// SPDX-License-Identifier: BSD-2-Clause-Patent
enum : uint32_t {
  // nio run-281: the controller's DMA is only proven reachable on the list
  // page itself (the 4 KiB the firmware used for its 32 UTRD slots). The
  // UCD block moves into that page, right after slot 0 (128..1168 of the
  // first 4 KiB; slots 1..31 are never rung). Page 1+ stays reserved for
  // data, which only commands with data touch.
  kUcdOffset = 128,
  kRspOffset = 512,
  kPrdtOffset = 1024,
  kDataOffset = 8192,
  kDataMax = 8192,
  kDmaBytes = kDataOffset + kDataMax,
};
