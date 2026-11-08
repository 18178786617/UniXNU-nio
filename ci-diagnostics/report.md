# Why the build failed

run: 37, commit 372499e9c7e8431f0a1be9165381b3c66d4385f5

## archive-13-build-storage-family.log

### the tail

```
PASS iig generated IOUserBlockStorageDevice.h (19416 bytes) and its implementation (101746 bytes)
PASS IOAppleLabelScheme (2 warnings)
PASS IOApplePartitionScheme (0 warnings)
PASS IOBlockStorageDevice (0 warnings)
PASS IOBlockStorageDriver (12 warnings)
PASS IOFDiskPartitionScheme (0 warnings)
PASS IOFilterScheme (0 warnings)
PASS IOGUIDPartitionScheme (0 warnings)
PASS IOMedia (0 warnings)
PASS IOMediaBSDClient (96 warnings)
PASS IOPartitionScheme (0 warnings)
PASS IORequest (0 warnings)
PASS IORequestsPool (0 warnings)
PASS IOStorage (1 warnings)
PASS IOUserBlockStorageDevice.iig (0 warnings)
the archive does not define: IOBlockStorageDevice, IOMedia, IOBlockStorageDriver, IOGUIDPartitionScheme, IOApplePartitionScheme, IOFDiskPartitionScheme, IOMediaBSDClient
```

## archive-12-build-nio-ufs-archive.log

### the tail

```
nio-ufs: build/nio-ufs/libNioUfs.a -> build/sheng-ufs/libShengUfs.a (454264 bytes, sha256 216f2af7f2c44d6ce37175716af84d01819f06a715f3b153f562cd3e3ecf108a)
```

## component-NioUfs.log

### the tail

```
NioUfs: -Werror build and arm64-apple-ios17.0 object audit passed
```

## archive-10-build-link-stubs.log

### the tail

```
compiled LinkStubs.c (legacy display 0, mobile display 0, deployment 17.0)
  _boot_log_export_put         T
  _native_gop_handoff_call     T
  _native_gop_handoff_memory   T
  _native_gpu_dcvs             D
  _native_pmap_user_mappings   T
  _qcom_usb_debug_write        T
PASS: 6 link stubs archived in /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/link-stubs/libLinkStubs.a
```

## archive-09-build-adreno650.log

### the tail

```
note: -Wno-unnecessary-virtual-specifier is not known to this clang, not passing it
PASS: 31 NativeAdreno a650 objects archived
PASS: archive verified with 31 objects
```

## archive-08-build-libpthread-kernel.log

### the tail

```
Cloning into '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work'...
this XNU tree calls proc_get_pthread_jit_allowlist what the sources call proc_get_jit_entitled
Matching libpthread: 3 real C sources + bootstrap, ARM64/iOS 17 audit, no unavailable kernel names
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
65181:_mant, /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/arm/_types.h:76:33error: warning: identifier '__darwin_va_list' is reserved because it starts with '__' [-Wreserved-identifier]
249961: 1584 | #define devfs_default_error (void (*)(void))vn_default_error:
600947:_darwin_fs 2203 |         blkcnt_t                os;In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kdp/kdp_common.h_log_error:33:
619103: 1033 |             os_lIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOMemoryDescriptor.cpp:65og_error:
648362:0x%X  158 |                 prin) (tf(%d "bu/ 0ffex%Xr_s) itagnpue_it (nit%d ial/ 0izex%X fa) (ile%d d to allocate me/ 0mory. Error 0x%xx%X\n") (, r%d et)/ 0;
668789: 1056 |         }  __RectiError 0x%x\n", __func__, ret);
690427:102 |                 printf("progress_notify_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
712111: 1049 |         os_log_error:ed));
713057:ind Real Application %d Bou 1436 |         ZONE_ID_indInterface %d> (polit_LASialize T_RO_EXfailed to alcy id=%d sesT = Zlocatsion_ONE_ID_AMFI_e memory. Error 0x%x\norder=%d polOSENT", reicy_oITLEMENTS,
866464:sc_queue_append_update_prev(mpsc_queu64 |         e_chain_t prev, mpsc_queIn file included from u   /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Tests/TestIOMemoryDescriptor.cpp os_loge_chain__error:(OtS_38LOG elm)
1152038: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1152076:  696 |                          "| error:      loss recovery %dms int  too           bi   _       g"setjmp(
1356705:  602 |         int __pagein_error:14: warning: identifier '__percpu_section_start' is reserved because it starts with '__' [-Wreserved-identifier]
1458555:  190  696 |  o get the close error: %d", error);
1530497:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
1530659:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
1547316:  312 |                 #        ipseclog((LOG_DEBUG, "esp4_output: i  633 |                         MBUF_STRInternal error: "
1624108:  275 |         SASEL_LOG("Returned with error: %d", err);
1662206:   60 | typedef _Atomic(os%119s: proc:9_suser(_ref_count_t) os_ref_at) error: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
2292102: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
2292108: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
2319200:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/priority_queue.h:707_l/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/startup.h:729:12og_error:81: note: expanded from macro 'PRIORITY_QUEUE_MAKE_CB'
2693435:__pagein_error:22: warning: ;
2772467:Undefined symbols for architecture arm64:
2772476:ld: symbol(s) not found for architecture arm64
2772477:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
2772478:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
2772479:make[2]: *** [build_all] Error 2
2772480:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
2772481:make: *** [build] Error 2
```

### around them

```
65175-t _/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:265:14:_at note: expanded from macro 'MAC_CHECK'
65176-  265 |           tribute__((unused));
65177-      |           ^
65178-    /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:  e_t;     DTRACE_MACF3(999:4: mac__warning: identifier '__Request__mach_port_space_info_t' is reserved because it starts with '__' [-Wreserved-identifier]
65179-  call_999 |         } _ ## __Reqcheckuest_,        /* sizeovoidf() * *, m/
65180-      |                                 ^pc, i
65181:_mant, /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/arm/_types.h:76:33error: warning: identifier '__darwin_va_list' is reserved because it starts with '__' [-Wreserved-identifier]
65182-, int,   76 | ty MAC_pedefITERA __buTE_CHECK); \
65183-      |                     ^
65184-ch_iltin_va_port_list       __darwin_spaceva_list;  _info     _t __/* vaattri_list */
65185-      |                                 ^
65186-but/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165:2/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/arm/_types.h:82: note: expanded from macro 'DTRACE_MACF3'
65187-  :33: warning: identifier '__darwin_wchar_t' is reserved because it starts with '__' [-Wreserved-identifier]
65188-165 |         DTRe__ACE((u_PROBE3(__sdt_, name, a   82 | rgnus1, ed)arg);
65189-2, arg3ty      |           ^pedef __WCHAR_T
65190-YPE__    )/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:1011:4;
65191-      |         ^
--
249955-      |                                                        ^~~~~~~~~~~~~~~~~~~~~~~
249956-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/miscfs/devfs/devfs_vnops.c:1683:57: warning: cast from 'int (*)(void)' to 'void (*)(void)' converts to incompatible function type [-Wcast-function-type-strict]
249957- 1683 |         { .opve_op = &vnop_default_desc, .opve_impl = (VOPFUNC)devfs            MIG mach_host_server.c
249958-_default_error },
249959-      |                                                                ^~~~~~~~~~~~~~~~~~~
249960-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/miscfs/devfs/devfs_vnops.c:1584:29: note: expanded from macro 'devfs_default_error'
249961: 1584 | #define devfs_default_error (void (*)(void))vn_default_error:
249962-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSContainers.h:46:
249963-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSValueObject.h:36:
249964-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:980:2: warning: identifier '__elem' is reserved because it starts with '__' [-Wreserved-identifier]
249965-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:946:2: note: expanded from macro 'IOOverrideTypedOperators'
249966-  946 |         __IOOverrideTypedOperators(type)
249967-      |         ^
249968-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:869:10: note: expanded from macro '__IOOverrideTypedOperators'
249969-  869 |                 IOFreeType(mem, type);                            \
249970-      |                 ^
249971-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:340:6: note: expanded from macro 'IOFreeType'
--
600941-_lo      |                         ^ngj
600942-mp(
600943-      /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/_types.h:59:25: warning: |            ^
600944-identifier '__darwin_fsblkcnt_t' is reserved because it starts with '__' [-Wreserved-identifier]
600945-   59 | typedef /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if_ipsec.c:unsigned iIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kdp/kdp_common.c:30:
600946-nt    _2203:4: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
600947:_darwin_fs 2203 |         blkcnt_t                os;In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kdp/kdp_common.h_log_error:33:
600948-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/task.h:94(OS_LOG_DEFAULT,:
600949-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kern_types.h:    /* Used by 259:16: warning: identifier '_wait_queue_link' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
600950-  259 "ips | tysec_flowswitch_tatpedef attvstrucfs ant _wad fach - flowsit_statvfs */
600951-witqueuech is NULL\n");
600952-      |                         ^
600953-      /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396_link:5: note: expanded from macro 'os_log_error'
600954-  396 |     _Sta *wait_queue_link_t;tic_a
600955-      |                ^
600956-|                         ^
600957-sser/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/_types.h:60:25t(: warning: identifier '__darwin_fsfilcnt_t' is reserved because it starts with '__' [-Wreserved-identifier]
--
619097-  177 | int     _consume_printf_args(int, ...);
619098-      |         ^
619099-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c:1323:3: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
619100- 1323 |                 NECPLOG(LOG_ERR, "necp_session_add_domain_filter filter copyin error (%d)", error);
619101-      |                 ^
619102-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1033:6: note: expanded from macro 'NECPLOG'
619103: 1033 |             os_lIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOMemoryDescriptor.cpp:65og_error:
619104-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/uio.h:101:
619105-(necp_lo/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/kernel_types.h:92:8: warning: identifier '__ifnet' is reserved because it starts with '__' [-Wreserved-identifier]
619106-g_handle, "%s: " format "\n", __FUNCTION__, __VA_ARGS__); \
619107-      |             ^
619108-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/misc_protos.h   :202:1:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5 warning: : note: expanded from macro 'os_log_error'identifier '_doprnt' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
619109-
619110-  202 | _do  396 |     prnt(
619111-      | ^
619112-92 | st/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/misc_protos.h:209:ruct __if1: warning: identifier '_doprnt_log' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
619113-  209 | _doprnt_log(
--
712105-      |           ^
712106-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/thread_act.h:1143:4: warning: identifier '__Reply__thread_swap_exception_ports_t' is reserved because it starts with '__' [-Wreserved-identifier]
712107- 1143 |         } __Reply__thread_swap_exception_ports_t __attribute__((unus76 | typedef __uint32_t      __darwin_uid_t;         /* [???] user IDs */
712108-      |                         ^
712109-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/_types.h:77:25                                                                                                                                                                                 ^~
712110-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:50: note: expanded from macro 'NECPDATATRACELOG'
712111: 1049 |         os_log_error:ed));
712112-      |           ^
712113- warning: identifier '__darwin_useconds_t' is reserved because it starts with '__' [-Wreserved-identifier]
712114-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/thread_act.h(necp_data_trace_log_handle, "%s: " format "\n", __F   77 | typedef __uint32_t      __darwin_useconds_t;    /* [???] microseconds */
712115-      |                         ^
712116-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/_types.h:79:25: warning: identifier '__darwin_uuid_t' is reserved because it starts with '__' [-Wreserved-identifier]
712117-   79 | typedef unsigne:1155Ud char   __darwin_uuid_t[16];
712118-      |                         ^
712119-NCTION__, __/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/_types.h:80:17: warning: identifier '__darwin_uuid_string_t' is reserved because it starts with '__' [-Wreserved-identifier]
712120-   80 | typedef char    __darwin_uuid_string_t[37];
712121-      |                 ^
--
866458-ntrol unit %d", wrapper-  159 | __startup_ZALLOC_entry___zone_site_>/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/mpsc_queue.h:265:1: warning: identifier '__mpsc_queue_append_update_prev' is reserved because it starts with '__' [-Wreserved-identifier]
866459-control_unit);
866460-      |                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
866461-  265 | __/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:64:69: note: expanded from macro 'NETAGENTLOG'
866462-registemr_2p70   
866463-      | ^
866464:sc_queue_append_update_prev(mpsc_queu64 |         e_chain_t prev, mpsc_queIn file included from u   /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Tests/TestIOMemoryDescriptor.cpp os_loge_chain__error:(OtS_38LOG elm)
866465-      | ^
866466-:
866467-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/mpsc_queue.h:267:2: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
866468-  267 |         /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOKitKernelInternal.h:_37DEFAULT, "%sos_atomic_store(&pre: " v->mp:
866469-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/vm/vm_pageout.h:qc_ne79xt, eformat "\n", __FUNCTION__, __VA_ARGS__); \
866470-      |             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~
866471-lm, relaxed);
866472-:
866473-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/bits.h:270:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:399:76: 21: warning: cast from 'void (*)(vm_allocation_site_t *)' (aka 'void (*)(vm_allocation_site *)') to 'void (*)(const void *)' converts to incompatible function type [-Wcast-function-type-strict]
866474-note: expanded from macro 'os_log_error'
--
1152032-671:81      |                                                    ~~~~: note: 
1152033-   58 |   118 | __c          opy   out   _ch   k(c   ons   t v   oid__F *kUNCaddTIOr, N__use, #r_a#__ddrVA__t ARGuadS__dr,);  si\
1152034-      ze_|                                             ^~~~~~~~~~~
1152035-t len, size_t chk_size)
1152036-      | ^
1152037-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:29: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
1152038: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1152039-      |                                                            ~~
1152040-      |                                                            %u
1152041- 1421 |                     p->ifnetem_jitter_msIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/lock_group.c:62:
1152042-In file included from expanded from macro '\
1152043-PRIORITY_QUEUE_MAKE_BASE'
```

### the tail

```
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
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov  8 05:38:49 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
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
  "_native_verified_block_root_authorized", referenced from:
      _bsd_init in bsd_init.o
ld: symbol(s) not found for architecture arm64
clang++: error: linker command failed with exit code 1 (use -v to see invocation)
make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
make[2]: *** [build_all] Error 2
make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
make: *** [build] Error 2
build-xnu-4k-baseline.sh: line 829: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## status.txt

```
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
driver   NioUfs                   device
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
