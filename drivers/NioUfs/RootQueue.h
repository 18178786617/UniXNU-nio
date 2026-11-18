// SPDX-License-Identifier: BSD-2-Clause-Patent
// Root queue takeover; shared with the host fault-injection harness.

/* nio: the waits in this driver do not use the kernel's delay, and do not
 * use its clock.
 *
 * IODelay() ends in machine_delay_until(), which spins on
 * mach_absolute_time() and waits for an event with WFE.  This board's
 * timebase is advanced by the timer interrupt, and the matching path runs
 * with the interrupt off, so that wait does not end.  Run 469 stopped at a
 * IODelay; run 476 stopped at another one, in the transfer poll's own
 * pause -- the same fault in a second place.
 *
 * So the wait is a read of the controller's own status register.  The read
 * is slow enough to be a pause, it needs no clock and no interrupt, and
 * read32() is one of the primitives the host harness replaces, so the
 * harness keeps working unchanged.
 */
static inline void ufsWaitTicks (unsigned reads)
{
  volatile uint32_t sink = 0;
  for (unsigned index = 0; index < reads; ++index) sink += read32 (gHost.hc, 0x30);
  (void) sink;
}

static bool hostWaitRegister (unsigned offset, uint32_t mask, uint32_t value)
{
  /* nio: counted, not timed, for the reason ufsWaitTicks() gives.  A
   * hundred thousand reads is about a hundred milliseconds of wall time,
   * which is what the timed version waited for. */
  for (unsigned spins = 0; spins < 100000; ++spins) {
    if ((read32 (gHost.hc, offset) & mask) == value) return true;
    ufsWaitTicks (10);
  }
  return false;
}

static bool hostStopQueue (const char **why)
{
  // Confirm the firmware has no active transfer/task before changing its
  // request list or the storage stream's SMMU routing.
  // HCS.DP (device present) is bit 0 and HCS.UCRDY (UIC command ready) is
  // bit 3; the other bits in between report device and link errors, so
  // waiting for all of them would mean waiting for a failure.
  //
  // nio run-486: the host controller enable bit is set if it is not
  // already set.  The reference implementation on this controller
  // refuses to go on unless it is set, and a UEFI driver disables the
  // controller on its way out, so the bit is probably clear by the time
  // this runs.  A controller that is not enabled does not fetch the
  // request descriptor when the doorbell is rung.
  if ((read32 (gHost.hc, 0x30) & (0x1 | 0x8)) != (0x1 | 0x8)) {
    recordTransport (kIOReturnNotReady, 15);
    *why = "controller not ready for takeover";
    return false;
  }
  if (!(read32 (gHost.hc, 0x34) & 1)) {
    hostWrite (0x34, 1);
    if (!(read32 (gHost.hc, 0x34) & 1)) {
      recordTransport (kIOReturnNotReady, 15);
      *why = "controller enable refused";
      return false;
    }
  }
  if (read32 (gHost.hc, 0x58) || read32 (gHost.hc, 0x78)) {
    recordTransport (kIOReturnBusy, 15);
    *why = "firmware request outstanding";
    return false;
  }
  if (read32 (gHost.hc, 0x20) & kUfsFatalStatus) {
    recordTransport (kIOReturnIOError, 15);
    *why = "firmware controller error";
    return false;
  }
  hostWrite (0x24, 0);
  hostWrite (0x60, 0);
  if (!hostWaitRegister (0x60, 1, 0)) {
    recordTransport (kIOReturnTimeout, 15);
    *why = "request list stop";
    return false;
  }
  return true;
}

static bool hostStartQueue (const char **why)
{
  hostWrite (0x50, static_cast<uint32_t> (gHost.phys));
  hostWrite (0x54, static_cast<uint32_t> (gHost.phys >> 32));
  if (read32 (gHost.hc, 0x50) != static_cast<uint32_t> (gHost.phys) ||
      read32 (gHost.hc, 0x54) != static_cast<uint32_t> (gHost.phys >> 32)) {
    /* nio R297: say exactly what the controller kept, instead of only the
     * reason string; a mismatched base is a mapping problem, not a link one.
     *
     * nio R300: this is a panic and not a printf.  The driver's own printf
     * never reaches the console on this board -- only the kernel's prints do
     * -- so a print here says nothing to the person reading the screen.  The
     * panic is the one channel that is known to be visible, so the numbers
     * that tell a mapping problem from a link problem go there. */
    gRootDiagnostic.hcs = read32 (gHost.hc, 0x30);
    gRootDiagnostic.hce = read32 (gHost.hc, 0x34);
    gRootDiagnostic.doorbell = read32 (gHost.hc, 0x60);
    gRootDiagnostic.isBefore = read32 (gHost.hc, 0x20);
    panic ("NATIVE_UFS queue: request list address\n"
           "wrote %08x/%08x read %08x/%08x phys %llx\n"
           "hcs=%08x is=%08x hce=%08x hclkrl=%08x",
           static_cast<uint32_t> (gHost.phys),
           static_cast<uint32_t> (gHost.phys >> 32),
           read32 (gHost.hc, 0x50), read32 (gHost.hc, 0x54),
           static_cast<unsigned long long> (gHost.phys),
           gRootDiagnostic.hcs, gRootDiagnostic.isBefore,
           gRootDiagnostic.hce, gRootDiagnostic.doorbell);
    recordTransport (kIOReturnIOError, 15);
    *why = "request list address";
    return false;
  }
  gRootDiagnostic.isBefore = read32 (gHost.hc, 0x20);
  hostWrite (0x20, gRootDiagnostic.isBefore);
  hostWrite (0x60, 1);
  // The request list is running once HCLKRUN is set and the controller
  // reports the device present and the UIC command path ready.
  if (!hostWaitRegister (0x60, 1, 1) || !hostWaitRegister (0x30, 0x1 | 0x8, 0x1 | 0x8)) {
    /* nio R297: HCS.DP (bit 0) is what says whether the controller sees a
     * device at all; HCS.UCRDY is bit 3.  Print both with the error and doorbell
     * registers so the next run separates power/clock/reset from link faults.
     *
     * nio R300: a panic and not a printf, for the reason above. */
    gRootDiagnostic.hcs = read32 (gHost.hc, 0x30);
    gRootDiagnostic.hce = read32 (gHost.hc, 0x34);
    gRootDiagnostic.doorbell = read32 (gHost.hc, 0x60);
    panic ("NATIVE_UFS queue: request list did not start\n"
           "hclkrl=%08x hcs=%08x is=%08x hce=%08x\n"
           "utrlba=%08x utrlbase=%08x phys %llx",
           gRootDiagnostic.doorbell, gRootDiagnostic.hcs,
           read32 (gHost.hc, 0x20), gRootDiagnostic.hce,
           read32 (gHost.hc, 0x50), read32 (gHost.hc, 0x54),
           static_cast<unsigned long long> (gHost.phys));
    recordTransport (kIOReturnTimeout, 15);
    *why = "request list ready";
    return false;
  }
  return true;
}
