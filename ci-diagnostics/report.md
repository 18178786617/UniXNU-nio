# Why the build failed

run: 25, commit ca746683ba7ec6420cfcb9f8a71af3e6145d60d0

## archive-08-build-libpthread-kernel.log

### the errors

```
7:  /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:670:20: error: no member named 'proc_get_jit_entitled' in 'struct pthread_callbacks_s'
```

### around them

```
1-Cloning into '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work'...
2-the reference callback table is missing: reference/pthread-shims-10063.h
3-the reference callback table is not there; the compile will speak for itself
4-kern_support.c: the compile failed
5-command: xcrun --sdk iphoneos clang -target arm64-apple-ios17.0 -isysroot /Applications/Xcode_26.6.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS26.5.sdk -mkernel -ffreestanding -fno-builtin -fno-stack-check -std=gnu11 -fblocks -O2 -mno-implicit-float -DKERNEL=1 -DKERNEL_PRIVATE=1 -DXNU_KERNEL_PRIVATE=1 -DMACH_KERNEL_PRIVATE=1 -DMACH_ASSERT=1 -DDEBUG=1 -D__PTHREAD_EXPOSE_INTERNALS__=1 -DABSOLUTETIME_SCALAR_TYPE=1 -DNEEDS_SCHED_CALL_T=1 -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/private -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/include -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/System/Library/Frameworks/Kernel.framework/Versions/A/PrivateHeaders -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/System/Library/Frameworks/Kernel.framework/Versions/A/Headers -Wno-deprecated-declarations -c /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c -o /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/libpthread-kernel/kern_support.o
6-1 errors; the first ones:
7:  /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:670:20: error: no member named 'proc_get_jit_entitled' in 'struct pthread_callbacks_s'
8-s/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:785:30: warning: implicit conversion changes signedness: 'int' to 'vm_size_t' (aka 'unsigned long') [-Wsign-conversion]
9-  785 |         const vm_size_t guardsize = vm_map_page_size(map);
10-      |                         ~~~~~~~~~   ^~~~~~~~~~~~~~~~~~~~~
11-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:843:10: warning: implicit conversion changes signedness: 'int' to '__uint32_t' (aka 'unsigned int') [-Wsign-conversion]
12-  842 |                 arm_thread_state_t state = {
13-      |                                            ~
14-  843 |                         .pc = (int)wqstart_fnptr,
15-      |                               ^~~~~~~~~~~~~~~~~~
16-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:852:10: warning: implicit conversion changes signedness: 'int' to '__uint32_t' (aka 'unsigned int') [-Wsign-conversion]
17-  842 |                 arm_thread_state_t state = {
```

### the tail

```
      |                                            ~
  843 |                         .pc = (int)wqstart_fnptr,
  844 |                         .r[0] = (unsigned int)addrs->self,
  845 |                         .r[1] = (unsigned int)kport,
  846 |                         .r[2] = (unsigned int)addrs->stack_bottom,
  847 |                         .r[3] = (unsigned int)kevent_list,
  848 |                         // will be pushed onto the stack as arg4/5
  849 |                         .r[4] = (unsigned int)upcall_flags,
  850 |                         .r[5] = (unsigned int)kevent_count,
  851 | 
  852 |                         .sp = (int)(addrs->stack_top)
      |                               ^~~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:901:4: warning: implicit conversion changes signedness: 'int' to 'unsigned int' [-Wsign-conversion]
  898 |         ret = pthread_kern->kevent_workq_internal(p, eventlist, nevents,
      |               ~~~~~~~~~~~~
  899 |                         kevent_list, WQ_KEVENT_LIST_LEN,
  900 |                         data_buf, &data_available,
  901 |                         kevent_flags, kevent_count_out);
      |                         ^~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:979:36: warning: implicit conversion changes signedness: 'unsigned int' to 'int' [-Wsign-conversion]
  979 |                 workq_kevent(p, &th_addrs, 0, 0, flags, &kevent_list, &kevent_count);
      |                 ~~~~~~~~~~~~                     ^~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:983:17: warning: implicit conversion changes signedness: 'int' to 'uint32_t' (aka 'unsigned int') [-Wsign-conversion]
  982 |         workq_set_register_state(p, th, &th_addrs, kport,
      |         ~~~~~~~~~~~~~~~~~~~~~~~~
  983 |                         kevent_list, upcall_flags, kevent_count);
      |                                      ^~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:1007:54: warning: implicit conversion changes signedness: 'unsigned int' to 'int' [-Wsign-conversion]
 1007 |         error = workq_kevent(p, &th_addrs, events, nevents, flags,
      |                 ~~~~~~~~~~~~                                ^~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:1018:17: warning: implicit conversion changes signedness: 'int' to 'uint32_t' (aka 'unsigned int') [-Wsign-conversion]
 1017 |         workq_set_register_state(p, th, &th_addrs, kport,
      |         ~~~~~~~~~~~~~~~~~~~~~~~~
 1018 |                         kevent_list, upcall_flags, kevent_count);
      |                                      ^~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:1049:34: warning: implicit conversion changes signedness: 'int' to 'uint32_t' (aka 'unsigned int') [-Wsign-conversion]
 1049 |                 pthread_mutex_default_policy = policy_bootarg;
      |                                              ~ ^~~~~~~~~~~~~~
22 warnings and 1 error generated.

```

## archive-07-build-mockfs-fixture.log

### the tail

```
3 XNU mockfs sources compiled (typed-allocation correction retained); ordinary ARM64 / iOS 17 audited
Offline minimal-root fixture only; not an APFS driver or iPadOS filesystem
```

## archive-06-build-software-aes-bindings.log

### the tail

```
PASS: native AES bound with the recorded original-kernelcache addresses
```

## component-SoftwareAES.log

### the tail

```
SoftwareAES: -Werror build and arm64-apple-ios17.0 object audit passed
```

## component-ArmCpu.log

### the tail

```
ArmCpu: -Werror build and arm64-apple-ios17.0 object audit passed
```

## component-ArmDTPlatform.log

### the tail

```
ArmDTPlatform: -Werror build and arm64-apple-ios17.0 object audit passed
```

## archive-02-build-corecrypto-14.log

### the tail

```
529 kernel C sources; 0 failures
Internal unregistered provider archive: libcorecrypto_kernel_noasm-namespaced.a
External names absent from kernel: []
Globals shared with kernel: 0; initialization and intact selftests are still required
```

## archive-01-build-corecrypto-14.log

### the tail

```
529 kernel C sources; 0 failures
Internal unregistered provider archive: libcorecrypto_kernel_noasm.a
External names absent from kernel: []
Globals shared with kernel: 26; initialization and intact selftests are still required
```

## storage-headers.log

### the tail

```
PASS: 19 public IOStorageFamily headers prepared at e45fbe30a7879e0b16e26dddb78538f1b00e0bff
```

## kernel-bootstrap.log

### the errors

```
48819: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
60276: "(kcdata_memcpy error: %d, length: %ld)\n",
60282: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
678004:  268 |                 printf("(%s) Failed to handle availability of LZ4. Error 0x%x\n", __func__, ret);
700671:  102 |                 printf("progress_notify_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
721032:    /*  272 |                 printf("zlib_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
730860:  388 | #define IODelete(.. 1049 |         o/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/clock.hs_log_error:(n.) 195:4e: warning: identifier '__Reply__clock_get_time_t' is reserved because it starts with '__' [-Wreserved-identifier]
734603:  143 |                 printf("%s failed to allocate memory. Error 0x%x\n", __func__, ret);
766474:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/port.h |         os_log_error:70:
1209890: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler mo 1519 |             .kt_sign:
1209959: 1398 |            _nosan_bcmp(const void *a __size        NET        d_by(szEM_LOG(L    OG_), const  v      ERR, "| error: duplication_p %d > %d",
1209985:    "| error: latency %d too big (> 1 s        62 | \
1210014:   1420 |                     "| error: jit  eter %dms tdoo big (latency %  \
1210036:    1420 |                     "| error: jitt94 | __nosan_strncpy(char *dst, const char *src, size_t sz)
1210061: 1438 |                     "| error: loss recovery %dms too big",
1210072: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
1210083: 1463 |                     "| error: output interval %dms too big",
1556668: 2626 |                 FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
1561621: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
1613694:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/thread.h |              :122    os_log_error:
1640185:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
1640595:sR  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
1664717:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
1664746:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
1758330:  275 |         SASEL_LOG("Returned with error: %d", err);
2378826: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
2378832: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
2862995:Undefined symbols for architecture arm64:
2863002:ld: symbol(s) not found for architecture arm64
2863003:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
2863004:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
2863005:make[2]: *** [build_all] Error 2
2863006:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
2863007:make: *** [build] Error 2
```

### around them

```
48813- 1354 |                         IOLog("Failed to open corefile of size %llu MB (returned error 0x%x)\n",
48814-      |                                                                                          ~~
48815-      |                                                                                          %x
48816- 1355 |                             (corefile_fallback_size_bytes / (1024ULL * 1024ULL)), err);
48817-      |                                                                                   ^~~
48818-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1364:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
48819: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
48820-      |                                                                                   ~~     ^~~
48821-      |                                                                                   %x
48822-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1447:2: warning: 'switch' missing 'default' label [-Wswitch-default]
48823- 1447 |         switch (op) {
48824-      |         ^
48825-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1530:20: warning: missing field 'total' initializer [-Wmissing-designated-field-initializers]
48826- 1530 |         c_string = (char*)kalloc_data(string_length, (zalloc_flags_t)(Z_ZERO | Z_WAITOK | Z_NOFAIL));
48827-      |                           ^
48828-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:512:2: note: expanded from macro 'kalloc_data'
48829-  512 |         kheap_alloc(KHEAP_DATA_BUFFERS, size, flags)
--
60270-      |                     ^
60271-      |                 ~~               ^~~~~~~~~~~
60272-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/percpu.h:291:14: warning: identifier '__percpu_section_end' is reserved because it starts with '__' [-Wreserved-identifier]
60273-  291 |         extern char __percpu_section_end[0] __SECTION_END_SYM("__DATA", "__percpu");/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
60274-
60275- 1413 |                                                  |                     ^
60276: "(kcdata_memcpy error: %d, length: %ld)\n",
60277-      |                                                                                ~~~
60278-      |                                                                                %zu
60279- 1414 |                                             path, mc_error, fatal_failure_desc_len);
60280-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
60281-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
60282: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
60283-      |                                                                                                   ~~~
60284-      |                                                                                                   %zu
60285- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
60286-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
60287-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
60288- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
60289-      |                             ^
60290-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
60291- 1426 |                 zfree(ZV_NAMEI, vn_path);
60292-      |                 ^
--
730854-m /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.htor{ *, _:1049:77: note: expanded from macro 'NECPDATATRACELOG'
730855-
730856-      |       ^
730857-descriptorsCount);
730858-      |                         ^
730859-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:388:32: note: expanded from macro 'IODelete'
730860:  388 | #define IODelete(.. 1049 |         o/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/clock.hs_log_error:(n.) 195:4e: warning: identifier '__Reply__clock_get_time_t' is reserved because it starts with '__' [-Wreserved-identifier]
730861-         __IOKIT_  195 | D        } __Reply__clocck_get_tISPATCH(IODeime_t __attlete, ##__VA_p_dARGS__)
730862-      |                                ^
730863-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:740:2: note: expanded from macro '__IOKIT_DISPATCH'
730864-  rib740ute__ata_trace_log_hand((unused));l
730865-      |           ^
730866- |         __IOKIT_DISPATCH1(base,e,  __IOKIT_COUNT_ARGS(__VA_ARGS__), ##__VA_AR/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/clock.h:209GS__)
730867-      |         ^
730868-"%s:: " form4at ":\n", __FUNCTION__, __VA_ARGS__ warning: identifier '__Reply__clock_get_attributes_t' is reserved because it starts with '__' [-Wreserved-identifier]
730869-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:738:41: note: expanded from macro '__IOKIT_DISPATCH1'
730870-  209 |         )  738} __Reply; \
--
766468-      | da                                                                                                              ^~
766469-rwin_piIn file included from d_t;         /* [???] proces/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_hash.c1049:50: note: expanded from macro 'NECPDATATRACELOG's and group IDs */
766470-      |                         ^:68
766471-
766472-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/_types.h:74:25:
766473- 1049In file included from : warning: identifier '__darwin_sigset_t' is reserved because it starts with '__' [-Wreserved-identifier]
766474:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/port.h |         os_log_error:70:
766475-In file included from (necp_data_tr/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_space.h:90:
766476-ace_log   In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/task.h:_74 | tyhandpedele, f __uint32_t122"%s: " format:
766477-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/cpu_data.h:42:
766478-In file included from   "\n", _    _FUN __darwin_sigCTIOset_N__,t;     /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/machine/cpu_data.h:34:
766479-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/cpu_data.h:43:
766480-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/thread.h:84:
766481- __VIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/thread_kernel_state.h:31A_AR:
766482-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/vm/vm_kern.h:841GS__:29: warning: bitwise operation between different enumeration types ('kmr_flags_t' and 'kmem_flags_t') [-Wenum-enum-conversion]
766483-); \
766484-      |                                                         ^~~~~~
--
1209884-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/host_info.h:66:
1209885-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/message.h:813:
1209886-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/debug.h:32:
1209887-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kcdata.h:246:
1209888-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/string.h:42/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1387:7: warning: format specifies type 'int' but the argument has underlying type 'unsigned int' [-Wformat]
1209889- note: expanded from macro '_KALLOC_TYPE_DEFINE'
1209890: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler mo 1519 |             .kt_sign:
1209891-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/libsa/types.h:67:16: warning: identifier '_quad_' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
1209892-del %d",
1209893-      |                                                                      ~~   67 | typedef struct
1209894-      |                                                                      %u
1209895- _quad_ {
1209896-      |                ^
1209897-ature = KALLOC_TYPE_EMIT_SIG(type),                 \
1209898-      |             ~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~
1209899-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:1497:2: note: expanded from macro 'KALLOC_TYPE_EMIT_SIG'
1209900- 1497 |         (KALLOC_TYPE_CHECK(KT 1387 |                     p->ifnete_SUMMARY_MASK_DATA, sig_type, #m_model)In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/lock_ticket.c:31:
--
1209953-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/iokit/IOKit/IOLib.h:336:9: note: expanded from macro 'IOFreeType'
1209954-  336 |         static _KALLOC_TYPE_DEFINE(kt_view_var, type,       \
1209955-      |                ^
1209956-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:1520:2: note: expanded from macro '_KALLOC_TYPE_DEFINE'
1209957- 1520 |         } };      /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1399:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/san/san/memintrinsics.h:52:1: warning: identifier '__nosan_bcmp' is reserved because it starts with '__' [-Wreserved-identifier]
1209958-    52 | _    7       : warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
1209959: 1398 |            _nosan_bcmp(const void *a __size        NET        d_by(szEM_LOG(L    OG_), const  v      ERR, "| error: duplication_p %d > %d",
1209960-      |                                                            ~~
1209961-      o     |                                                            %u
1209962-id * 1399 |                     p->ifnetem   b ___            \
1209963-      |         ^duplicatio
1209964-n_p, NETEM_PSCALE);
1209965-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~
1209966-sized_by(sz), siz/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: In file included from OSUnserialize.y:62:
1209967-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libkern/libkern/c++/OSContainers.h:46:
1209968-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libkern/libkern/c++/OSValueObject.h:487:2e_t snote: expanded from macro 'NETEM_LOG'
1209969-z:  117 |                  )
--
1209979-      | d                                            ^~~~~~~~~~~
1209980-_by(sz), size_t sz)
1209981-      | ^
1209982- note: expanded from macro 'os_ptr_load_and_erase'
1209983-   66 |         __auto_type *__single __eptr = &(elem);    /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1414:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
1209984-    1413 |                        /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/san/san/memintrinsics.h:62:1: warning: identifier '__nosan_memcmp' is reserved because it starts with '__' [-Wreserved-identifier]
```

### the tail

```
      |                      ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:442:6: warning: identifier '__ovr' is reserved because it starts with '__' [-Wreserved-identifier]
  442 |         if (round_page_overflow(x, &x)) {
      |             ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:126:15: note: expanded from macro 'round_page_overflow'
  126 |                 bool __ovr = os_add_overflow(in, (__typeof__(*out))PAGE_MASK, out); \
      |                      ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:607:14: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
  607 |         vm_offset_t ptr = params.vmpp_base +
      |                     ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libsa/lastkerneldataconst.c:49:65: warning: identifier '_lastkerneldataconst' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
   49 | const vm_offset_t    __attribute__((section("__DATA,__data")))  _lastkerneldataconst         = (vm_offset_t)&data_const_padding[0];
      |                                                                 ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libsa/lastkerneldataconst.c:50:65: warning: identifier '_lastkerneldataconst_padsize' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
   50 | const vm_size_t      __attribute__((section("__DATA,__data")))  _lastkerneldataconst_padsize = sizeof(data_const_padding);
      |                                                                 ^
83 warnings generated.
             CC version.o
clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/version.c:39:12: warning: identifier '__kernelVersionString' is reserved because it starts with '__' [-Wreserved-identifier]
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Thu Nov  5 10:54:01 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
      |            ^
1 warning generated.
             LD mach.development.bcm2837.unstripped
ld: warning: -new_linker is obsolete
ld: warning: search path '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/usr/local/lib/kernel/platform' not found
Undefined symbols for architecture arm64:
  "_mockfs_mountroot", referenced from:
      _vfstbllist in vfs_conf.o
  "_mockfs_vfsops", referenced from:
      _vfstbllist in vfs_conf.o
  "_mockfs_vnodeop_opv_desc", referenced from:
      _vfs_opv_descs in vfs_conf.o
ld: symbol(s) not found for architecture arm64
clang++: error: linker command failed with exit code 1 (use -v to see invocation)
make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
make[2]: *** [build_all] Error 2
make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
make: *** [build] Error 2
build-xnu-4k-baseline.sh: line 829: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## build-libpthread-kernel_compile-errors.log

### the errors

```
4:  /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:670:20: error: no member named 'proc_get_jit_entitled' in 'struct pthread_callbacks_s'
```

### around them

```
1-kern_support.c: the compile failed
2-command: xcrun --sdk iphoneos clang -target arm64-apple-ios17.0 -isysroot /Applications/Xcode_26.6.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS26.5.sdk -mkernel -ffreestanding -fno-builtin -fno-stack-check -std=gnu11 -fblocks -O2 -mno-implicit-float -DKERNEL=1 -DKERNEL_PRIVATE=1 -DXNU_KERNEL_PRIVATE=1 -DMACH_KERNEL_PRIVATE=1 -DMACH_ASSERT=1 -DDEBUG=1 -D__PTHREAD_EXPOSE_INTERNALS__=1 -DABSOLUTETIME_SCALAR_TYPE=1 -DNEEDS_SCHED_CALL_T=1 -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/private -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/include -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/System/Library/Frameworks/Kernel.framework/Versions/A/PrivateHeaders -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/System/Library/Frameworks/Kernel.framework/Versions/A/Headers -Wno-deprecated-declarations -c /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c -o /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/libpthread-kernel/kern_support.o
3-1 errors; the first ones:
4:  /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:670:20: error: no member named 'proc_get_jit_entitled' in 'struct pthread_callbacks_s'
```

## build-libpthread-kernel_kern_support.log

### the errors

```
32:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:670:20: error: no member named 'proc_get_jit_entitled' in 'struct pthread_callbacks_s'
```

### around them

```
24-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:589:34: warning: implicit conversion changes signedness: 'int' to 'uint32_t' (aka 'unsigned int') [-Wsign-conversion]
25-  589 |                         data.tsd_offset <= (uint32_t)(pthsize - tsd_slot_sz)) {
26-      |                                                       ^~~~~~~ ~
27-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:653:11: warning: implicit conversion loses integer precision: 'integer_t' (aka 'int') to 'thread_qos_t' (aka 'unsigned char') [-Wimplicit-int-conversion]
28-  652 |                                 data.main_qos = _pthread_priority_make_from_thread_qos(
29-      |                                                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
30-  653 |                                                 qos.qos_tier, 0, 0);
31-      |                                                 ~~~~^~~~~~~~
32:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:670:20: error: no member named 'proc_get_jit_entitled' in 'struct pthread_callbacks_s'
33-  670 |         if (pthread_kern->proc_get_jit_entitled(p)) {
34-      |             ~~~~~~~~~~~~  ^
35-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:693:29: warning: implicit conversion changes signedness: 'int' to 'mach_vm_size_t' (aka 'unsigned long long') [-Wsign-conversion]
36-  693 |         mach_vm_size_t guardsize = vm_map_page_size(wq_map);
37-      |                        ~~~~~~~~~   ^~~~~~~~~~~~~~~~~~~~~~~~
38-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:695:38: warning: implicit conversion changes signedness: 'int' to 'vm_map_offset_t' (aka 'unsigned long long') [-Wsign-conversion]
39-  694 |         mach_vm_size_t pthread_size = vm_map_round_page_mask(
40-      |                                       ~~~~~~~~~~~~~~~~~~~~~~
41-  695 |                         pthread_kern->proc_get_pthsize(p) + PTHREAD_T_OFFSET,
42-      |                         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~
43-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:754:36: warning: implicit conversion changes signedness: 'int' to 'vm_size_t' (aka 'unsigned long') [-Wsign-conversion]
44-  754 |         const vm_size_t       guardsize = vm_map_page_size(vmap);
```

## status.txt

```
patch    35 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-component-load-probes.patch
patch    36 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-legacy-start.patch
patch    37 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/gpu-probe-start.patch
patch    38 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-native-gpu-broker.patch
patch    39 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-owner-boot-manifest.patch
patch    40 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-owner-cache-carrier.patch
patch    41 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-owner-root-binding-audit.patch
patch    42 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-owner-root-crypto-probe.patch
patch    43 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-owner-systemos-mount.patch
patch    44 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-owner-z-air-init.patch
patch    45 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-pgz-alignment-probe.patch
patch    46 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/public-entitlements-header.patch
patch    47 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/source-corecrypto14-bootstrap.patch
patch    48 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/source-machine-layer.patch
patch    49 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/source-pthread-bootstrap.patch
patch    50 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/zzw-native-adreno-sandbox-grant.patch
patch    51 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/zzwb-native-sandbox-grant-set-properties.patch
patch    52 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/zzx-pmap-sync-64bit-pa.patch
patch    53 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/zzy-native-gpu-addon-mount.patch
patch    54 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/zzy-staged-system-apps.patch
patch    55 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/zzyb-native-cryptex-os-view.patch
patch    56 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/zzyc-owner-skip-launch-constraints.patch
patch    57 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/native-smp-secondary.patch
patch    58 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/native-smp-type-clusters.patch
patch    59 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/sheng-platform-power.patch
patch    60 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/zzz-boot-progress.patch
patch    61 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/xnu-8796.101.5-security-init.patch
patch    62 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/xnu-8796.101.5-sparse-index.patch
patch    63 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/linux-clang-auto-var-init.patch
patch    64 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/linux-clang-uio-stackbuf-align.patch
patch    65 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/linux-clang-kalloc-pointee-type.patch
patch    66 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/linux-clang-iorpc-kernel-content.patch
patch    67 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/xnu-8796-arm64-kpc-backend.patch
driver   ArmCpu                   base
driver   ArmDTPlatform            base
driver   SoftwareAES              base
kit      AdrenoFirmware           base
kit      AdrenoPM4                base
kit      ArmSmmu4K                base
kit      XnuPrelink               base
package  device                   device
package  main                     base
patch    darwinboot               device
patch    libpthread               base
patch    mesa                     base
patch    xnu                      device
patch    xnu-12377                base
patch    xnu-8796                 device
patch    xnu-prelink              device
refer    AvailabilityVersions     git pinned 933f9360f1b7
refer    IOStorageFamily          git pinned e45fbe30a787
refer    corecrypto-2023          git pinned 11fba65b12d8
refer    edk2                     git pinned cfb93724a06f
refer    libdispatch              git pinned 30fe6a7d9453
refer    libplatform              git pinned a00a4cc36da2
refer    libpthread               git pinned c0e60fb5ecfc
refer    xnu                      git pinned aca3beaa3dfb
refer    xnu-driverkit            git pinned 2c2f96dc2b9a
refer    xnu-trustcache           git pinned aca3beaa3dfb
soc      sm8250                   git pinned a6e7e36caab5
```

## patch scope

```
out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work: every added line is inside a function
```
