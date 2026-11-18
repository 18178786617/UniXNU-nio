// SPDX-License-Identifier: BSD-2-Clause-Patent
enum : uint32_t {
  // nio run-281 moved the UCD block into the request list page, right
  // after slot 0, on the theory that the controller's DMA is only proven
  // reachable on that page.  The theory was never tested against the root
  // path, and it disagrees with the recipe that was: adoptAndRead, the
  // only one ever validated on hardware, keeps its UCD on the page after
  // the list, at 4096.
  //
  // Run 479 stopped with the doorbell report written and the report after
  // it missing, which is the same place runs 65 and 66 stopped: the write
  // that starts the request list does not come back.  A controller that
  // cannot fetch the UCD would fail exactly there.
  //
  // So the UCD goes back to where the validated recipe has it.  It fits:
  // the block runs from 4096 to 5264, the data area starts at 8192, and
  // the whole window is still 16 KiB.
  kUcdOffset = 4096,
  kRspOffset = 512,
  kPrdtOffset = 1024,
  kDataOffset = 8192,
  kDataMax = 8192,
  kDmaBytes = kDataOffset + kDataMax,
};
