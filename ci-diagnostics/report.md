# Why the build failed

run: 24, commit ab0b8945fa750ccac1eb2f843e3043b801b22900

## archive-08-build-libpthread-kernel.log

### the errors

```
5:  /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:670:20: error: no member named 'proc_get_jit_entitled' in 'struct pthread_callbacks_s'
```

### around them

```
1-Cloning into '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work'...
2-kern_support.c: the compile failed
3-command: xcrun --sdk iphoneos clang -target arm64-apple-ios17.0 -isysroot /Applications/Xcode_26.6.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS26.5.sdk -mkernel -ffreestanding -fno-builtin -fno-stack-check -std=gnu11 -fblocks -O2 -mno-implicit-float -DKERNEL=1 -DKERNEL_PRIVATE=1 -DXNU_KERNEL_PRIVATE=1 -DMACH_KERNEL_PRIVATE=1 -DMACH_ASSERT=1 -DDEBUG=1 -D__PTHREAD_EXPOSE_INTERNALS__=1 -DABSOLUTETIME_SCALAR_TYPE=1 -DNEEDS_SCHED_CALL_T=1 -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/private -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/include -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/System/Library/Frameworks/Kernel.framework/Versions/A/PrivateHeaders -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/System/Library/Frameworks/Kernel.framework/Versions/A/Headers -Wno-deprecated-declarations -c /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c -o /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/libpthread-kernel/kern_support.o
4-1 errors; the first ones:
5:  /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:670:20: error: no member named 'proc_get_jit_entitled' in 'struct pthread_callbacks_s'
6-s/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:785:30: warning: implicit conversion changes signedness: 'int' to 'vm_size_t' (aka 'unsigned long') [-Wsign-conversion]
7-  785 |         const vm_size_t guardsize = vm_map_page_size(map);
8-      |                         ~~~~~~~~~   ^~~~~~~~~~~~~~~~~~~~~
9-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:843:10: warning: implicit conversion changes signedness: 'int' to '__uint32_t' (aka 'unsigned int') [-Wsign-conversion]
10-  842 |                 arm_thread_state_t state = {
11-      |                                            ~
12-  843 |                         .pc = (int)wqstart_fnptr,
13-      |                               ^~~~~~~~~~~~~~~~~~
14-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:852:10: warning: implicit conversion changes signedness: 'int' to '__uint32_t' (aka 'unsigned int') [-Wsign-conversion]
15-  842 |                 arm_thread_state_t state = {
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
48656:llersSetup for corefile failed with error: 0x%x\n", err);
62663: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
62669: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
66165:def _Atomic(int/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_host.hint, error:783, int, M:4: warning: identifier '__Request__mach_zone_info_for_largest_zone_t' is reserved because it starts with '__' [-Wreserved-identifier]
99264:   48 | CF3(mac_typedef _call__ __builti## checkn_va_lis, void *t __gnuc, mpc, int, error:_, int, MAC_ITERATE_CHECK); \
313378:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if_bridge.c:223trace_error:18: note: expanded from macro 'BRIDGE_LOG'
638112:  113 | __NDR_convert__mig_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c:555:1reply_error: warning: cast from 'void (*)(struct sysctl_oid *)' to 'typeof (sysctl_register_oid_early(&sysctl__net_necp_drop_unentitled_level)) (*)(const void *)' (aka 'void (*)(const void *)') converts to incompatible function type [-Wcast-function-type-strict]
659025:  158 |                 printf("buffer_s 1029tage_initialize fa |         } __Reply_iled t_thread_ao allocate bort_t memory. Error 0x%x\n_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c:5712:13: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
679600:ching <%s> <value (%d / 0x%X) (%d / 0ix%Xled to handle availability of LZ4. Error 0x%x\n", __func__, ret);
703223:ate memory. Error 0x%x\n", ret);0x%X)>", \
713165:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOMapper.hquest__ 1049 |         os_task_selog_error:47:
725585: failed to  8764 |                                         NECP_DATA_allocate memorTRACE_LOG_SOCKETy. Error 0x%x\_RESULT(debug,n", ret);
734316:le        221 |         } __d to allocate memory. Error 0x%|                                                                                                                             %u
857595:  432 |         } __Request__host_reboot_t __at |             otribute__(s_log_error: note: expanded from macro '\
1198635: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
1198646: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
1198693: 2303 |         STARTUP_ARG(ZALLOC, STARTUP_RANK_LAST, __zone_site_register, &site)(LOG_ERR, "| error: duplication_p %d > %d",
1198766: 1413 |                     "| error: latency %d too big (> 1 sec)",
1198777: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1198788: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1198799: 1438 |                     "| error: loss recovery %dms too big",
1198810: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %dwarning: identifier '__elem' is reserved because it starts with '__' [-Wreserved-identifier]
1198831: 1463 |                     "| error: output interval %dms too big",
1456112:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/turnstile.h2202 |                     "%s: error:53:
1546022: get the close error: %d", error);
1549869:ctlin   64_et3 | snq2_truet ucue  t mb  _OSU  ufna _ rli_vetgnalured32ned an U1[4error: 6 ];%d{
1635415:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
1635427:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
1727253:  275 |         S"size misASEL_LOG("Returned with error: %d", err);
1763876:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/cdefs.h:1089:45d req, error: note: expanded from macro '__container_of'
1763943:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/mach_types.h:87nd6log0(error:41: note: :
1775223:  549 |         nd6lostartup_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/netinet6/nd6.hg(error:861:22: lck_grp_spec_bankwarning: identifier '__res11' is reserved because it starts with '__' [-Wreserved-identifier]
1811754:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/classq/classq.hIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_voucher.h:40:229:13error: warning: identifier '_getq_all' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
1872350:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/machine/pmap.heval __pl:34p_y_error:
1910202:        int   729 |             rank, __:__STp2809Aagein_error:5: warning: identifier '__pthread_sigmask' is reserved because it starts with '__' [-Wreserved-identifier]
2377721:"(kcdata_memcpy error:      |           ^
2377729: 3383 |                 y_    "(os_re_machason_alloc_buffer _vmerror: %d, k_dcdata error: %eferd, length: %ld)\n"re,
2398349:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_info.h:66nt or error:
2408825:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h:59g_error:5: note: expanded from macro '__SAFE_CAST_PTR'
2862994:Undefined symbols for architecture arm64:
```

### around them

```
48650-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/tty.h:75:
48651-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/select.h:113:
48652-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/event.h:730:1: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
48653-  730 | _Static_assert(!VM/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1364:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
48654-_ 1364 |                 IOLPACKING_IS_og("IOPoBASE_RELATIVE(KNOlledFTE_KQ_PAilePoCKED),
48655-      | ^
48656:llersSetup for corefile failed with error: 0x%x\n", err);
48657-      |                                                                                   ~~     ^~~
48658-      |                                                                                   %x
48659-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/event.h:741:6: warning: bit-field 'kn_qos_index' of type 'uintptr_t' (aka 'unsigned long') has a different storage size than the preceding bit-field (8 vs 2 bytes) and will not be packed under the Microsoft ABI [-Wms-bitfield-padding]
48660-  741 |             kn_qos_index:4,                         /* in-use qos index */
48661-      |             ^
48662-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/event.h:739:27: note: preceding bit-field 'kn_status' declared here with type 'kn_status_t'
48663-  739 |         kn_status_t              kn_status : 12;
48664-      |                                  ^
48665-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/event.h:1017:8: warning: identifier '_kevent_register' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
48666- 1017 | struct _kevent_register;
--
62657- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
62658-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
62659-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
62660-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
62661-      |                 ~~               ^~~~~~~~~~~
62662-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
62663: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
62664-      |                                                                                ~~~
62665-      |                                                                                %zu
62666- 1414 |                                             path, mc_error, fatal_failure_desc_len);
62667-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
62668-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
62669: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
62670-      |                                                                                                   ~~~
62671-      |                                                                                                   %zu
62672- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
62673-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
62674-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
62675- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
62676-      |                             ^
62677-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
62678- 1426 |                 zfree(ZV_NAMEI, vn_path);
62679-      |                 ^
--
66159-y  773p265 | :e4: warning: identifier '__Request__mach_zone_info_for_zone_t' is reserved because it starts with '__' [-Wreserved-identifier]
66160-         de  773 f  |           _A}   to__  miRe    DTRc(quACuiesE_nt_fast8_t)     t_M ACF3(ma_mach_zone_infc_ ao__ctfomic_uialonr_zone_l_tt_fast8__  t__attri##;
66161-bu c      | te__        ^
66162-heck, vo(/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdatomic.h(uid:122nu *:sed9:)), mp;
66163- warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
66164-  122 | tyc      | pe,           ^
66165:def _Atomic(int/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_host.hint, error:783, int, M:4: warning: identifier '__Request__mach_zone_info_for_largest_zone_t' is reserved because it starts with '__' [-Wreserved-identifier]
66166-_fast16_t)     AC_ITERATE_CHECK); \
66167-      |                     ^
66168-  783 |   atomic_i/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165:2        } __:nt_fast16_t;
66169-      |         ^
66170-Request__mach_zone_i note: expanded from macro 'DTRACE_MACF3'
66171-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdatomic.h:123:9  nfo:165 |         DTRACE_P_ warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
66172-for_largest_zoneROBE_t _3(___attsdt_ribu,  123 | typedef te__((un_Atousedmic());
66173-uint      |           ^
66174-_fast16_t)      atomic_uint/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_host.h:793:4: warning: identifier '__Request__mach_zone_get_zlog_zones_t' is reserved because it starts with '__' [-Wreserved-identifier]
66175- _fast16n  _a793 |         }mt;
--
99258-  265 |                     DTRACE_MIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/vfs/vfs_conf.c:70:
99259-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/param.h:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/system.hA116:
99260-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/ucred.h:82:
99261-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/queue.h:63:
99262-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:36:
99263-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdarg.h:48:27: warning: identifier '__gnuc_va_list' is reserved because it starts with '__' [-Wreserved-identifier]
99264:   48 | CF3(mac_typedef _call__ __builti## checkn_va_lis, void *t __gnuc, mpc, int, error:_, int, MAC_ITERATE_CHECK); \
99265-      |                     ^
99266-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165:2: note: expanded from macro 'DTRACE_MACF3'
99267-  165 |         DTRACE_PROBE3(__sdt_, name, arg1, arg2, arg3);
99268-      |         ^
99269-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:va_list;
99270-      |                           ^14062
99271-:29: note: expanded from macro 'DTRACE_PROBE3'
99272-  140 |                 register uintptr_t __dtrace_a1 asm("x1") = (uintptr_t) arg1;                    \
99273-      |                                    ^
99274-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_system.c:136:2: warning: identifier '__dtrace_a2' is reserved because it starts with '__' [-Wreserved-identifier]
--
313372-  201 |     _firehose_tracepoint_type_trace_debug               /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if_bridge.c:4396:4: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
313373-    = 0x02,
313374- 4396 |                       |     ^
313375-        BRI/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/firehose/firehose_types_private.h:202:DGE_LOG(5: warning: identifier '_firehose_tracepoint_type_trace_error' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
313376-  LOG_DEBU202 |     _fG, BR_DBirehose_GF_CHECKtracepoiSUM,
313377-      |                         ^nt_type_
313378:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if_bridge.c:223trace_error:18: note: expanded from macro 'BRIDGE_LOG'
313379-          223 |                             = 0x1       o0,
313380-      |     ^
313381-s_log(OS_L/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/firehose/firehose_types_private.h:203:5: OG_DEwarning: identifier '_firehose_tracepoint_type_trace_fault' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
313382-  203 |  FAULT, "   _fire%s: " __hose_trastrincepoint_g, \
313383-      |                         ^type_tra
313384-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:292:5:ce_fault note: expanded from macro 'os_log'
313385-  292 |     _Static_a     ssert(__bui     ltin_con     stant_p(    =forma 0x11t), "format,
313386-      |     ^ string 
313387-must be constant");      /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/firehose/firehose_types_private.h:198:     1: warning: identifier '_firehose_tracepoint_type_trace_t' is reserved because it starts with '_' at global scope [-Wreserved-identifier]  \
313388-      |     ^
--
638106-   99 | __startup_SYSIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/system.h:41:
638107-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_interface.h:32:
638108-In file included from CTL/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/clock.h:13:
638109-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mig_errors.h_entry_sysctl__net_necp__drop_unentitled_level
638110-      | ^
638111-:113:1: warning: identifier '__NDR_convert__mig_reply_error_t' is reserved because it starts with '__' [-Wreserved-identifier]
638112:  113 | __NDR_convert__mig_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c:555:1reply_error: warning: cast from 'void (*)(struct sysctl_oid *)' to 'typeof (sysctl_register_oid_early(&sysctl__net_necp_drop_unentitled_level)) (*)(const void *)' (aka 'void (*)(const void *)') converts to incompatible function type [-Wcast-function-type-strict]
638113-_t(__unused mig_reply  555 | SYSCTL_PROC(_net__error_t *xnecp, NECPCTL_DRO)
638114-      | ^
638115-P_UNENTITLED_LEVEL, drop_unentitled_level, CTLTYPE_INT | CTLFLAG_LOCKED | CTLFLAG_RW, &necp_In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IODMACommand.cpp:38:
638116-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.hdrop_unen:49:
638117-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/system.h:41:
638118-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_interface.h:titled_level, 0, &sysctl_handle_necp_unentitled_level, "IU", "");
638119-      | ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
638120-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/sysctl.h:529:2: note: expanded from macro 'SYSCTL_PROC'
638121-  529 |         SYSCTL_OID(parent, nbr, name, access, \
638122-      |         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
--
713159-      |           ^
713160- \
713161-      |                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
713162-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1300:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:77: note: 4: warning: identifier '__Request__task_set_emulation_vector_t' is reserved because it starts with '__' [-Wreserved-identifier]
713163- 1300 |         }expanded from macro 'NECPDATATRACELOG'
713164- __ReIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOMemoryDescriptor.cpp:40:
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
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Thu Nov  5 10:36:01 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
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
