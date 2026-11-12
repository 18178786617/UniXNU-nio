// SPDX-License-Identifier: BSD-2-Clause-Patent
// Root queue takeover; shared with the host fault-injection harness.
static bool hostWaitRegister (unsigned offset, uint32_t mask, uint32_t value)
{
  uint64_t deadline;
  clock_interval_to_deadline (100, kMillisecondScale, &deadline);
  do {
    if ((read32 (gHost.hc, offset) & mask) == value) return true;
    IODelay (10);
  } while (mach_absolute_time () < deadline);
  return false;
}

static bool hostStopQueue (const char **why)
{
  // Confirm the firmware has no active transfer/task before changing its
  // request list or the storage stream's SMMU routing.
  // HCS.DP (device present) is bit 0 and HCS.UCRDY (UIC command ready) is
  // bit 3; the other bits in between report device and link errors, so
  // waiting for all of them would mean waiting for a failure.
  if (!(read32 (gHost.hc, 0x34) & 1) ||
      (read32 (gHost.hc, 0x30) & (0x1 | 0x8)) != (0x1 | 0x8)) {
    recordTransport (kIOReturnNotReady, 15);
    *why = "controller not ready for takeover";
    return false;
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
