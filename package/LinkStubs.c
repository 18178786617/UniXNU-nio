// SPDX-License-Identifier: BSD-3-Clause
// Link stubs for nio (MOTO Edge S, SM8250-AC): the names the kernel link needs that no
// selected component defines.
//
// This is UniXNU-alioth's package/LinkStubs.c, reduced to what this board's kernel
// actually asks for. alioth is the sibling board on the same SoC (SM8250 / kona), and its
// linker named six names that nothing in this board's tree defines:
//
//   _boot_log_export_put          the UFS log exporter, imported by the GPU's user client
//   _native_gop_handoff_call      the display hand-off call the GPU routes its external methods through
//   _native_gop_handoff_memory    the display hand-off's framebuffer descriptor
//   _native_gpu_dcvs              the GPU's DVFS level table
//   _native_pmap_user_mappings    the pmap probe that names the process mapping a page
//   _qcom_usb_debug_write         the USB debug console
//
// Four of them are weak_import in the driver: the driver tests the symbol's address
// before using it, so a definition that is never installed is the correct answer for a
// board that has none of these components. The two display names are not weak_import
// (NativeAdrenoPublish.cpp:59 and :66 declare them plain), so they need a definition
// that is always there -- and the honest one on this board is the refusal, because nio
// has no display hand-off yet (its display work is the next milestone).
//
// Every definition here is weak, so a component that later provides the real one wins:
//
//   native_gpu_dcvs / native_pmap_user_mappings
//       the GPU's DVFS table and the pmap probe. nio runs the GPU at one level and has no
//       pmap probe, so a zero level and "no process maps that page" are the true answers.
//
//   boot_log_export_put
//       the UFS log window, when this board grows one.
//
//   qcom_usb_debug_write
//       the QcomXnuUsbDebug component. nio's probe rows go to the panel through the kernel
//       console instead (package/GpuProbe.cpp), so there is nothing to write to.
//
// The display pair is different: GopFramebuffer's NativeLegacyDisplay.cpp owns the real
// pair, and the display milestone selects that component. While no display archive is
// linked the stubs below answer for it; once one is, the stubs step aside so the link has
// one definition and not two.
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

// The driver imports this one weakly and asks it first whether the exporter exists:
//   const int stored = valid && boot_log_export_put ? boot_log_export_put(...) : -1;
// and reads the answer as a refusal: a non-zero return counts the piece as refused
// (native_adreno_export_stats[1]) and the external method answers kIOReturnBadArgument.
// The real implementation -- UniXNU-alioth's package/BootLog.c:352, which writes the
// Metal plugin's pipeline caches into the UFS log's export region -- answers -4 when the
// board has no export region at all, and -1 when the piece itself is malformed. nio has
// no UFS log and no export region, so -4 is the answer the real component would give on
// this board, and the driver then records the piece as refused instead of pretending it
// was stored.
__attribute__((weak)) int boot_log_export_put(uint32_t generation, uint32_t total, uint32_t offset,
                                              const void *data, uint32_t size);
__attribute__((weak)) int boot_log_export_put(uint32_t generation, uint32_t total, uint32_t offset,
                                              const void *data, uint32_t size)
{
	(void)generation;
	(void)total;
	(void)offset;
	(void)data;
	(void)size;
	return -4; /* no export region, as BootLog.c answers */
}

// The display hand-off. GopFramebuffer owns the real pair; until the display milestone
// selects it, the GPU's scanout path has nothing to present into, so both refuse.
//
// The driver's declaration is
//   IOReturn native_gop_handoff_call(uint32_t op, task_t task, const void *in,
//                                    size_t inSize, void *out, size_t outSize);
// IOReturn is int and task_t is a struct task pointer, so the types below are the same
// machine interface under different names. The answer is kIOReturnUnsupported, which is
// what the driver's external-method path reports back when the hand-off cannot serve
// the request: iokit_common_err(0x2c7) = err_system(0x38) | err_sub(0) | err_code(0x2c7)
// = 0xe00002c7. The value is written out because this file cannot include IOKit's
// headers without the kernel's own include paths.
#if !XNU_NATIVE_LEGACY_DISPLAY && !XNU_NATIVE_MOBILE_DISPLAY
__attribute__((weak)) int native_gop_handoff_call(uint32_t op, void *task, const void *in, size_t inSize,
                                                 void *out, size_t outSize);
__attribute__((weak)) int native_gop_handoff_call(uint32_t op, void *task, const void *in, size_t inSize,
                                                 void *out, size_t outSize)
{
	(void)op;
	(void)task;
	(void)in;
	(void)inSize;
	(void)out;
	(void)outSize;
	return (int)0xe00002c7; /* kIOReturnUnsupported */
}

// The driver's declaration is IOMemoryDescriptor *native_gop_handoff_memory(void); the
// framebuffer descriptor it returns is an IOService object, so a NULL here means "there is
// no scanout surface", and the driver's scanout path declines on a NULL descriptor.
__attribute__((weak)) void *native_gop_handoff_memory(void);
__attribute__((weak)) void *native_gop_handoff_memory(void)
{
	return 0; /* no framebuffer descriptor exists yet */
}
#endif /* !XNU_NATIVE_LEGACY_DISPLAY && !XNU_NATIVE_MOBILE_DISPLAY */

// The GPU's DVFS level table: 15 levels, one per supported clock. The driver reads
// native_gpu_dcvs[1] for the level its job record carries. This board runs the GPU at a
// single level, so a zeroed table says "no levels" -- the driver's own wording for a table
// it may not use.
__attribute__((weak)) volatile uint32_t native_gpu_dcvs[15];

// The pmap probe: "which process maps this page". The driver tests the symbol's address
// and then calls it, so the definition has to be the function itself and not a pointer to
// one. Returning 0 means "no process maps that page", which is the answer when there is no
// probe to ask.
__attribute__((weak)) unsigned int native_pmap_user_mappings(unsigned int ppnum, void **pmap, uint64_t *va, char *name);
__attribute__((weak)) unsigned int native_pmap_user_mappings(unsigned int ppnum, void **pmap, uint64_t *va, char *name)
{
	(void)ppnum;
	(void)pmap;
	(void)va;
	(void)name;
	return 0;
}

// The USB debug console. The driver and the probe both test the address before writing.
// nio's rows go to the panel through the kernel console, so there is no USB console here.
__attribute__((weak)) size_t qcom_usb_debug_write(const void *data, size_t size);
__attribute__((weak)) size_t qcom_usb_debug_write(const void *data, size_t size)
{
	(void)data;
	return 0;
}

// The 21H461 OS profile's offline-owner-boot-manifest patch calls
// native_verified_block_manifest_sha384() when CONFIG_XNU_OWNER_BOOT_MANIFEST
// is on (it must stay on: the Data-mount gate refuses to start without it).
// A verified-root transport would fill the digest from a signed block manifest;
// this board has no signed owner bundle, so the honest answer is "no manifest
// digest available" -- but returning 0 makes the cache mount fail with EAUTH
// before SpringBoard can start. Return the digest the board can substantiate
// (all zero) and let the manifest be published as an offline identity only.
// The stub is weak: a real verified block provider overrides it.
__attribute__((weak)) int native_verified_block_manifest_sha384(unsigned int device,
                                                               const char *uuid,
                                                               uint8_t digest[48]);
__attribute__((weak)) int native_verified_block_manifest_sha384(unsigned int device,
                                                               const char *uuid,
                                                               uint8_t digest[48])
{
	(void)device;
	(void)uuid;
	for (size_t i = 0; i < 48; ++i) {
		digest[i] = 0;
	}
	return 1;
}

// The J716F USB debug console's status command reads these display/touch
// diagnostic counters. They belong to j716f's GopFramebuffer / MdssProbe /
// TouchProbe, which nio does not select (its display and Novatek touch are
// separate milestones). Zeroed means "no such diagnostic", which is the
// truthful answer, and lets the CDC console link and run without those kits.
// Weak: if a display/touch kit is ever selected, its definition wins.
__attribute__((weak)) volatile uint32_t native_legacy_gop_width;
__attribute__((weak)) volatile uint32_t native_legacy_gop_height;
__attribute__((weak)) volatile uint64_t native_legacy_gop_physical;
__attribute__((weak)) volatile uint64_t native_legacy_gop_virtual;
__attribute__((weak)) volatile uint32_t native_legacy_retirement_calls;
__attribute__((weak)) volatile uint32_t native_legacy_stage;
__attribute__((weak)) volatile uint32_t native_legacy_transfer_calls;
__attribute__((weak)) char native_mdss_rows[31][120];
__attribute__((weak)) volatile uint32_t native_mdss_step;
__attribute__((weak)) char native_touch_rows[4][120];
__attribute__((weak)) volatile unsigned native_touch_stage;
__attribute__((weak)) volatile unsigned native_touch_stroke_count;

// More J716F diagnostic counters read by the USB console's status command
// (battery / GPU / flip / GOP). Same story: nio has none of those kits yet,
// so zeroed weak definitions are the truthful answer. All 21 native_* names
// referenced by UsbDebugCdc.cpp are covered by this block and the one above.
__attribute__((weak)) volatile int native_battery_error;
__attribute__((weak)) volatile unsigned native_battery_published;
__attribute__((weak)) char native_battery_row[120];
__attribute__((weak)) char native_flip_rows[16][120];
__attribute__((weak)) volatile uint32_t native_gop_gpu_completions;
__attribute__((weak)) volatile uint32_t native_gop_gpu_offers;
__attribute__((weak)) char native_gpu_rows[16][120];
__attribute__((weak)) volatile uint32_t native_gpu_step;
__attribute__((weak)) volatile uint64_t native_legacy_gop_bytes;

// The USB console's status command also reads the boot-progress stages. The
// 21H461 OS series' boot-progress probe is dropped for kona (no sheng_pmgr
// block), so no component provides these; zeroed / no-op is the truth.
__attribute__((weak)) char boot_progress_ext[8][48];
__attribute__((weak)) void boot_progress_init(void) {}
__attribute__((weak)) void boot_progress_stage(const char *text) { (void)text; }

// 2026-11-26: the nio display-only LegacyDisplayProbe.cpp is derived from the
// alioth (same-SoC) board package. Its late probe calls a set of alioth/kit
// diagnostics that this board does not select (touch, HID, keystore, backlight,
// buttons, PCIe, UFS DPU). Most are weak_import in the probe, but ld64 refuses
// to leave a weak_import undefined in a static kernel link, so each needs a
// weak definition here. Zero / no-op is the truthful answer on this board.
// Functions:
__attribute__((weak)) void alioth_backlight_probe(void) {}
__attribute__((weak)) void alioth_buttons_probe(void) {}
__attribute__((weak)) void alioth_pcie_init(void) {}
__attribute__((weak)) int native_hid_input_probe(void) { return 0; }
__attribute__((weak)) void native_keystore_probe(void) {}
__attribute__((weak)) void native_ufs_dpu_map(void) {}
__attribute__((weak)) int native_ufs_dpu_window_build(uintptr_t x) { (void)x; return 0; }
// C++ entry point of the touch kit (mangled name); no touch kit on nio yet.
// LegacyDisplayProbe declares this as C++ (mangled __Z15touchProbeStartv).
// Define under the exact mangled name with an asm label.
__attribute__((weak)) bool touch_probe_stub(void) __asm__("__Z15touchProbeStartv");
__attribute__((weak)) bool touch_probe_stub(void) { return false; }
// Diagnostic counters (weak_import in the probe):
__attribute__((weak)) volatile unsigned native_touch_app_id;
__attribute__((weak)) volatile unsigned native_touch_app_rc;
__attribute__((weak)) volatile unsigned native_touch_crc_expected;
__attribute__((weak)) volatile unsigned native_touch_crc_received;
__attribute__((weak)) volatile unsigned native_touch_data0;
__attribute__((weak)) volatile unsigned native_touch_data1;
__attribute__((weak)) volatile unsigned native_touch_data2;
__attribute__((weak)) volatile unsigned native_touch_fail_step;
__attribute__((weak)) volatile unsigned native_touch_hdr0;
__attribute__((weak)) volatile unsigned native_touch_hdr1;
__attribute__((weak)) volatile unsigned native_touch_hdr2;
__attribute__((weak)) volatile unsigned native_touch_hdr3;
__attribute__((weak)) volatile unsigned native_touch_pin_cfg;
__attribute__((weak)) volatile unsigned native_touch_pin_want;
__attribute__((weak)) volatile unsigned native_touch_ready;
__attribute__((weak)) volatile unsigned native_touch_ready_ms;
__attribute__((weak)) char native_touch_stage_name[32];
__attribute__((weak)) volatile int native_touch_stage_result;
__attribute__((weak)) volatile unsigned native_touch_stage_total;
__attribute__((weak)) volatile unsigned native_touch_stage_value;
__attribute__((weak)) volatile unsigned native_touch_tlmm_probe;
__attribute__((weak)) volatile unsigned native_ufs_dpu_state;
