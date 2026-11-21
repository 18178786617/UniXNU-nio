# Why the build failed

run: 610, commit eb80e5046b2dbd0f29c8591567eb71a6cc15e28b

## fingerprint.log

### the tail

```
S1=no, nio: STALL rounds==no, nio: HB =no, the matching path stalled=no, nio: U1=no
bsd/DEVELOPMENT/kern_exec.o: 356264 bytes, mtime 11-21 08:24:07, nio: bsd_init: =no, nio: MT thread=no, 
D1=no, 
S1=no, nio: STALL rounds==no, nio: HB =no, the matching path stalled=no, nio: U1=no
iokit/DEVELOPMENT/IOService.cpo: 962088 bytes, mtime 11-21 08:22:17, nio: bsd_init: =no, nio: MT thread=no, 
D1=no, 
S1=no, nio: STALL rounds==no, nio: HB =no, the matching path stalled=yes, nio: U1=no
object directory totals: 857 .o, 120 .cpo, 9 .filelist, 1 .a
filelist bsd/DEVELOPMENT/bsd.filelist: 456 entries; first: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/bsd/DEVELOPMENT/nfs_syscalls.o | /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/bsd/DEVELOPMENT/nfs_gss.o | /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/bsd/DEVELOPMENT/nfs_serv.o
filelist iokit/DEVELOPMENT/iokit.filelist: 94 entries; first: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/OSObject.iig.cpo | /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/OSAction.iig.cpo | /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOService.iig.cpo
filelist osfmk/DEVELOPMENT/osfmk.filelist: 311 entries; first: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/gssd_mach.o | /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/lockd_mach.o | /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/KUNCUserNotifications.o
startup.c source: mtime 11-21 08:21:44, HB=yes, old-format=no
IOService.cpp source: mtime 11-21 08:21:44, STALL=yes, U1=no
bsd_init.c source: mtime 11-21 08:21:44, BSDINIT=yes
startup.c sha256: 7f0001b1c67c265297b9988d0b3e4414
  source line 621: nio_dc_puts("\nnio: HB ");
    608| nio_heartbeat_thread(void *arg, wait_result_t wr)
    609| {
    610| 	unsigned n = 0;
    611| 	uint64_t nio_hb_last = 0;
    612| 	for (;;) {
    613| 		uint64_t nio_hb_abstime = 0, nio_hb_ns = 0;
    614| 
    615| 		delay(100);
    616| 		n++;
    617| 		clock_get_uptime(&nio_hb_abstime);
    618| 		absolutetime_to_nanoseconds(nio_hb_abstime, &nio_hb_ns);
    619| 		if ((nio_hb_ns - nio_hb_last) >= 1000000000ULL) {
    620| 			nio_hb_last = nio_hb_ns;
    621| 			nio_dc_puts("\nnio: HB ");
    622| 			nio_dc_putu(n);
    623| 			nio_dc_puts(" ");
    624| 			nio_dc_putu(nio_hb_ns / 1000u);
    625| 		}
startup.o nio literals: ['nio: CPU count published', 'nio: HB ', 'nio: MT done', 'nio: MT inline', 'nio: MT thread', 'nio: beacon thread started', 'nio: hb thread failed', 'nio: hb thread started']
startup.o nio symbols: ['00000000000178d4 b _kernel_startup_initialize_upto.nio_hb_started', '000000000000055c t _nio_beacon_thread', '00000000000178b4 S _nio_boot_waypoint', '000000000000211f D _nio_cand_class', '00000000000178bc S _nio_cand_count', '00000000000178c0 S _nio_cand_reason', '000000000000180c t _nio_dc_puts', '0000000000001850 t _nio_dc_putu']
startup.o stat: inode=3166154 links=1 size=120752
compile record: present
compile record entries: 1
startup.o compile: /Applications/Xcode_26.6.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang -xc /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.c -o startup.o -c -g -nostdinc -ferror-limit=10000 -fno-builtin -fno-common -ftrivial-auto-var-init=zero -fsigned-bitfields -fmerge-all-constants -fc++-static-destructors=none -fsanitize-minimal-runtime -fsanitize-ignorelist=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/san/kasan-blacklist-arm64 -fsanitize=signed-integer-overflow -D ARM64_BOARD_CONFIG_BCM2837 -arch arm64 -D arm64 -D ARM64 -D __ARM64__ -D LP64 -D PAGE_SIZE_FIXED -D VM_KERNEL_
```

## replay.log

### the tail

```
  asm| Ltmp124:
  asm| ; %bb.3:                                ;   in Loop: Header=BB6_2 Depth=1
  asm| 	;DEBUG_VALUE: nio_hb_ns <- $x25
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:n <- $w21
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x24
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x25
  asm| 	.loc	4 621 4 is_stmt 1               ; .cache/xnu-work/osfmk/kern/startup.c:621:4
  asm| 	mov	x0, x19
  asm| 	bl	_nio_dc_puts
  asm| Ltmp125:
  asm| 	.loc	4 622 16                        ; .cache/xnu-work/osfmk/kern/startup.c:622:16
  asm| 	mov	w0, w21
  asm| 	.loc	4 622 4 is_stmt 0               ; .cache/xnu-work/osfmk/kern/startup.c:622:4
  asm| 	bl	_nio_dc_putu
  asm| Ltmp126:
  asm| 	.loc	4 623 4 is_stmt 1               ; .cache/xnu-work/osfmk/kern/startup.c:623:4
  asm| 	mov	x0, x20
  asm| 	bl	_nio_dc_puts
  asm| Ltmp127:
  asm| 	.loc	4 624 16                        ; .cache/xnu-work/osfmk/kern/startup.c:624:16
  asm| 	ldr	x8, [sp]
  asm| Ltmp128:
  asm| 	;DEBUG_VALUE: nio_hb_ns <- $x8
  asm| 	.loc	4 624 26 is_stmt 0              ; .cache/xnu-work/osfmk/kern/startup.c:624:26
  asm| 	lsr	x8, x8, #3
  asm| Ltmp129:
  asm| 	umulh	x8, x8, x23
  asm| 	lsr	x0, x8, #4
  asm| 	.loc	4 624 4                         ; .cache/xnu-work/osfmk/kern/startup.c:624:4
  asm| 	bl	_nio_dc_putu
  asm| Ltmp130:
  asm| 	.loc	4 0 4                           ; .cache/xnu-work/osfmk/kern/startup.c:0:4
  asm| 	mov	x24, x25
  asm| Ltmp131:
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x24
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x24
  asm| 	b	LBB6_1
  asm| Ltmp132:
  asm| 	.loh AdrpAdd	Lloh63, Lloh64
  asm| 	.loh AdrpAdd	Lloh61, Lloh62
```

## ci-steps.log

### the tail

```
  asm| Ltmp124:
  asm| ; %bb.3:                                ;   in Loop: Header=BB6_2 Depth=1
  asm| 	;DEBUG_VALUE: nio_hb_ns <- $x25
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:n <- $w21
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x24
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x25
  asm| 	.loc	4 621 4 is_stmt 1               ; .cache/xnu-work/osfmk/kern/startup.c:621:4
  asm| 	mov	x0, x19
  asm| 	bl	_nio_dc_puts
  asm| Ltmp125:
  asm| 	.loc	4 622 16                        ; .cache/xnu-work/osfmk/kern/startup.c:622:16
  asm| 	mov	w0, w21
  asm| 	.loc	4 622 4 is_stmt 0               ; .cache/xnu-work/osfmk/kern/startup.c:622:4
  asm| 	bl	_nio_dc_putu
  asm| Ltmp126:
  asm| 	.loc	4 623 4 is_stmt 1               ; .cache/xnu-work/osfmk/kern/startup.c:623:4
  asm| 	mov	x0, x20
  asm| 	bl	_nio_dc_puts
  asm| Ltmp127:
  asm| 	.loc	4 624 16                        ; .cache/xnu-work/osfmk/kern/startup.c:624:16
  asm| 	ldr	x8, [sp]
  asm| Ltmp128:
  asm| 	;DEBUG_VALUE: nio_hb_ns <- $x8
  asm| 	.loc	4 624 26 is_stmt 0              ; .cache/xnu-work/osfmk/kern/startup.c:624:26
  asm| 	lsr	x8, x8, #3
  asm| Ltmp129:
  asm| 	umulh	x8, x8, x23
  asm| 	lsr	x0, x8, #4
  asm| 	.loc	4 624 4                         ; .cache/xnu-work/osfmk/kern/startup.c:624:4
  asm| 	bl	_nio_dc_putu
  asm| Ltmp130:
  asm| 	.loc	4 0 4                           ; .cache/xnu-work/osfmk/kern/startup.c:0:4
  asm| 	mov	x24, x25
  asm| Ltmp131:
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x24
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x24
  asm| 	b	LBB6_1
  asm| Ltmp132:
  asm| 	.loh AdrpAdd	Lloh63, Lloh64
  asm| 	.loh AdrpAdd	Lloh61, Lloh62
```

## prelink.log

### the tail

```
emit-prelink-nio: Libm literal pool 0xfffffff005b8e054+0x4cc verified and known
Experimental candidate: 56958976 bytes; executable bytes unchanged; runtime unqualified
```

## xnu-trace.log

### the tail

```
[08:05:37] script start (bootstrap=1 jobs=3)
  object MISSING
  source sha 7f0001b1c67c2652
[08:07:12] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha 7f0001b1c67c2652
[08:13:50] script start (bootstrap=0 jobs=3)
  object MISSING
  source sha 7f0001b1c67c2652
[08:13:50] before make (bootstrap=0 jobs=3)
  object MISSING
  source sha 7f0001b1c67c2652
[08:16:47] after make (bootstrap=0 jobs=3)
  object 120752 bytes sha c027c9a6fc995c3a
  source sha 7f0001b1c67c2652
[08:17:46] script start (bootstrap=0 jobs=3)
  object MISSING
  source sha 7f0001b1c67c2652
[08:17:47] before make (bootstrap=0 jobs=3)
  object MISSING
  source sha 7f0001b1c67c2652
[08:20:45] after make (bootstrap=0 jobs=3)
  object 120752 bytes sha c027c9a6fc995c3a
  source sha 7f0001b1c67c2652
[08:21:44] script start (bootstrap=0 jobs=3)
  object MISSING
  source sha 7f0001b1c67c2652
[08:21:45] before make (bootstrap=0 jobs=3)
  object MISSING
  source sha 7f0001b1c67c2652
[08:24:47] after make (bootstrap=0 jobs=3)
  object 120752 bytes sha c027c9a6fc995c3a
  source sha 7f0001b1c67c2652
```

## kernel.log

### the errors

```
31397:  113 | __NDR_convert__mig_reply_error_t(__unused m/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_process.c:728:2ig_reply_error: warning: identifier '__dtrace_a1' is reserved because it starts with '__' [-Wreserved-identifier]
40681:      |                                 ^failed with error: 0
55227:p  106 |                         struct  y error: %d, lproc *__p_forwength: %ld)\n"; /* Doubly-li,
55239:  109 |                                     "(os_r                struct timeveason_alloc_bual __p_starttiffer error: %dme;   /* proce, kcdata error: %d, lengtss start tih: %ld)\n",
91510:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.het_32(error:162:2: note: expanded from macro 'DTRACE_MACF2'
93790:me remove 3579 |         nfsm_chain_volatile<_T>:_get_fh_ptr(error:type;
99080:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.hd *, mpc, int, error:1163:15: warning: 'release' overrides a member function but is not marked 'override' [-Wsuggest-override]
375761:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:874reply_error:32: note: expanded from macro 'zfree'
532565:  158 |                 printf("buffer_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
549952:e availability of LZ4. /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:1435:4Error 0x%x\n", __: warning: identifier '__Reply__mach_port_peek_t' is reserved because it starts with '__' [-Wreserved-identifier]
572941:  102 |                 printf("progress_notify_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
596327:  272 |                 printf("zlib_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
848178:  659 |         } __R  602 |         int __equest__vm_coppagein_error: warning: identifier '__ovr' is reserved because it starts with '__' [-Wreserved-identifier]
1040095:("IOMemor 1049 |         oyDescs_logripto_error::wir(necthAddp_datressRa_traangesce_lo [0x%g_hanlx @ dle, 0x%lx"%s: ]\n[0x%llx, 0x%llx],\" forn[0x%llx, 0mat "\n", __FUx%llx],\n[0x%llx, 0x%llxNCTIO]\n",
1048911:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOService.hs_log_error:44:
1178259:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:330 1049 |         os_log_error:9: note: expanded from macro 'IOMallocType'(necp_d
1548418: 1386 |                 NETEM_LOG(LOG_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/zalloc.c:10852:1:ERR, "| error: warning: identifier '__startup_SYSCTL_entry_sysctl_register_test_startup_10852' is reserved because it starts with '__' [-Wreserved-identifier]
1548440:  1392 |                 ## _entrNETEM_LOG(LOG_ERRy_ ## na, "| error: corrume ## ption_p %d > %d",
1548498: 1420 |                     "| error: jitter %dms too big (late/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/zalloc.c:10878:3ncy %dms)",: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
1548522: error: jitter %dms too big (latency /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/zalloc.c:10878:3%dms)",
1548545:   67 |         __auto_t 1438 |                     "|ype __elem = *__e error: loss rptr;             ecovery %dms t                \oo big",
1548586:a 1463 |                     "| error: org, arg)
1787209: 2297 |   503 |         kheap_alo get theloc_tagex close error: %d", tern void __(kallocerzo_heap, sine_siteroze_rr), egister;
1792604:      | ^f returned an error:
1849434:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: inteatornal error: "
1862976:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
1862988:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
1953929:  275 |         SASEL_LOG("Returned with error: %d", err);
2024514:error:284:14
2157408:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/string.h:339reply_error:
2173252:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/pmap/pmap.h:224or error:
2252493:   56 |         o/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/kern_mman.c:1268:3s_log_error: warning: identifier '__dtrace_a0' is reserved because it starts with '__' [-Wreserved-identifier]
2462993: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
2462999: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
2729288:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:415_channel_error:6: warning: identifier '__ovr' is reserved because it starts with '__' [-Wreserved-identifier]
```

### around them

```
31391-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/system.h:              41:
31392-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_interface.h:32:
31393-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/clock.h:13:
31394-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mig_errors.h:    \
31395-      |                                    ^
31396-113:1: warning: identifier '__NDR_convert__mig_reply_error_t' is reserved because it starts with '__' [-Wreserved-identifier]
31397:  113 | __NDR_convert__mig_reply_error_t(__unused m/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_process.c:728:2ig_reply_error: warning: identifier '__dtrace_a1' is reserved because it starts with '__' [-Wreserved-identifier]
31398-_t /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:267:14: note: expanded from macro 'MAC_CHECK'
31399-  267 | *x)
31400-      | ^
31401-                    DTRACE_MACF2(mac__rslt__ ## check, void *, mpc, int, __step_err); \
31402-      | In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:29:
31403-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:49:
31404-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/system.h:41:
31405-In file included from                     ^
31406-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:162/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_interface.h:32:
31407-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/clock.h:136:4: warning: identifier '__Request__clock_get_time_t' is reserved because it starts with '__' [-Wreserved-identifier]
--
40675-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/arm64/sdt_arm.c:26:
40676-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/cpu_data.h:37:
40677-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_types.h:109:
40678-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_region.h:365:26: warning: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1370:76identifier '__pad' is reserved because it starts with '__' [-Wreserved-identifier]
40679-: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
40680-  365 |         int        1370 |                 IOLog(           "IOPolledFi   __pad; /* plePollersSetupad to 64-bit b for corefile oundary */
40681:      |                                 ^failed with error: 0
40682-x%x\n", err);
40683-      |                                                                                   ~~     ^~~
40684-      |                                                                                   %x
40685-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:77:
40686-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/mount_internal.h:84:
40687-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/socket.h:646:8: warning: identifier '__sockaddr_header' is reserved because it starts with '__' [-Wreserved-identifier]
40688-  646 | struct __sockaddr_header {
40689-      |        ^
40690-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/socket.h:681:26: warning: identifier '__ss_pad1' is reserved because it starts with '__' [-Wreserved-identifier]
40691-  681 |         char                    __ss_pad1In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/arm64/sdt_arm.c:26:
--
55221-      |                 ~~               ^~~~~~~~~~~
55222-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/nfs/nfs_syscalls.c:78:
55223-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/vnode_internal.h:warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
55224-82 1413 |                                            :
55225-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/systm.h:110:
55226-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/proc.h:106:18 "(kcdata_memc: warning: identifier '__p_forw' is reserved because it starts with '__' [-Wreserved-identifier]
55227:p  106 |                         struct  y error: %d, lproc *__p_forwength: %ld)\n"; /* Doubly-li,
55228-      |                                                                                ~~~
55229-      |                                                                                %zu
55230- 1414 |                         nked run/sleep qu                    path,eue. */
55231-      |                                       ^
55232- /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/proc.h:107:18: warning: mc_error, fataidentifier '__p_back' is reserved because it starts with '__' [-Wreserved-identifier]
55233-l_failure_desc_le  107 |                         strucn);
55234-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
55235-t  proc *__p_back;
55236-      |                                       ^
55237-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
55238- 1418 | /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/proc.h:109:18: warning: identifier '__p_starttime' is reserved because it starts with '__' [-Wreserved-identifier]
55239:  109 |                                     "(os_r                struct timeveason_alloc_bual __p_starttiffer error: %dme;   /* proce, kcdata error: %d, lengtss start tih: %ld)\n",
55240-      |                                                                                                   ~~~
55241-      me */
55242-      |                                ^
55243-|                                                                                                   %zu
55244- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
55245-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
55246-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
55247- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
55248-      |                             ^
55249-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
--
91504-      |                                    ^
91505-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_skywalk.c:51:2: warning: identifier '__dtrace_a1' is reserved because it starts with '__' [-Wreserved-identifier]
91506-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:267:14: note: expanded from macro 'MAC_CHECK'
91507-  267 |                     DTRACE_MACF2(mac__rslt__ ## check, void/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/nfs/nfs_serv.c:1338:2: warning: identifier '__tmp32' is reserved because it starts with '__' [-Wreserved-identifier]
91508- *, mp 1338 |         nfsmc, int, __step_err);_chain_g \
91509-      |                     ^
91510:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.het_32(error:162:2: note: expanded from macro 'DTRACE_MACF2'
91511-  162 |         DTRACE_PROBE2(_, nmreq, le_sdt_, name, arg1, an);
91512-      |         ^
91513-rg2/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/nfs/nfsm_subs.h:442:19: note: expanded from macro 'nfsm_chain_get_32'
91514-  442 |           );
91515-      |         ^
91516-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:128:29:       uint3note: expanded from macro 'DTRACE_PROBE2'
91517-  128 |            2_t __tmp32     register uintpt, *__tmpptrr_t __dtrace_a1 asm(; \
91518-      |                          ^
91519-"x/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/nfs/nfs_serv.c:1338:2: warning: identifier '__tmpptr' is reserved because it starts with '__' [-Wreserved-identifier]
91520-1")/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/nfs/nfsm_subs.h:442:29: note: expanded from macro 'nfsm_chain_get_32'
--
93784- struct union iovecs))remove_vola));
93785-      |                                                                      ^
93786-tile<volatile _T> {typedef _T type;};
93787-      |                 ^
93788-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/cpp_util.h:56:17: warning: identifier '_T' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]
93789-   56 | template <class _T> using remove_volatile_t = typena/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/nfs/nfs_serv.c:3579:2: warning: identifier '__tmp32' is reserved because it starts with '__' [-Wreserved-identifier]
93790:me remove 3579 |         nfsm_chain_volatile<_T>:_get_fh_ptr(error:type;
93791-      |                 ^
93792-, nmreq, nd->/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/cpp_util.h:62:16: warning: nd_vers,identifier '_T' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]
93793- nfh.n   62 | templatefh_fhp, nfh.nf<class _T> h_len);
93794-      |         ^
93795-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/nfs/nfsm_subs.h:518:18: note: expanded from macro 'nfsm_chain_get_fh_ptr'
93796-  518 |           struct remo              ve_extent { tynfsm_chain_getpedef _T ty_32((E), (NMC)pe; };
93797-      |                ^
93798-, (FHSIZE/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/cpp_util.h:63:16: warning: identifier '_T' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]
93799-));   63 | template \
93800-      |                         ^
--
99074-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h;
99075-      |                      ^
99076-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:637:15: note: overridden virtual function is here
99077-:265:14: note: expanded from macro 'MAC_CHECK'
99078-    265 |                     DTRA637 |         virtual voiCE_MACF3(mac__cald retain() conl__ ## check, voist = 0;
99079-      |                      ^
99080:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.hd *, mpc, int, error:1163:15: warning: 'release' overrides a member function but is not marked 'override' [-Wsuggest-override]
99081- 1163 |         virtual v, int, MAC_ITERATE_Coid release() conHECK); \
99082-      |                     ^
99083-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165:2: note: expanded from macro 'DTRACE_MACF3'
99084-  165 |         DTRACE_PRst;
99085-      |                      ^
99086-OBE3(__sdt_, n/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:655:15: note: overridden virtual function is here
99087-  655 |         virtual ame, arg1, argvoid release() const2, arg3);
99088-      |         ^
99089- = /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:141:29: note: expanded from macro 'DTRACE_PROBE3'
99090-0;
--
```

### the tail

```
ld: warning: -new_linker is obsolete
ld: warning: search path '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/usr/local/lib/kernel/platform' not found
ld: warning: -segment_order should list all segments, __PRELINK_TEXT is missing
ld: warning: -segment_order should list all segments, __PRELINK_INFO is missing
ld: warning: -segment_order should list all segments, __PLK_TEXT_EXEC is missing
ld: warning: -segment_order should list all segments, __PRELINK_DATA is missing
ld: warning: -segment_order should list all segments, __PLK_DATA_CONST is missing
ld: warning: -segment_order should list all segments, __PLK_LLVM_COV is missing
ld: warning: -segment_order should list all segments, __PLK_LINKEDIT is missing
ld: warning: -segment_order should list all segments, __LINKINFO is missing
ld: warning: -segment_order of __LINKEDIT is ignored, the segment must be ordered last
       DSYMUTIL mach.development.bcm2837.dSYM
        LIBTOOL mach.development.bcm2837.a
libtool: warning: 'sched_clutch.o' has no symbols
libtool: warning: 'ptrauth_data_tests.o' has no symbols
libtool: warning: 'pmap_cs.o' has no symbols
libtool: warning: 'pmap_iommu.o' has no symbols
libtool: warning: 'iofilter_asm.o' has no symbols
libtool: warning: 'iofilter.o' has no symbols
libtool: warning: 'gxf_exceptions.o' has no symbols
libtool: warning: 'pinst.o' has no symbols
libtool: warning: 'platform_tests_asm.o' has no symbols
libtool: warning: 'net_stubs.o' has no symbols
libtool: warning: 'classq_util.o' has no symbols
libtool: warning: 'key_debug.o' has no symbols
libtool: warning: 'ppl.o' has no symbols
libtool: warning: 'sysv_shm.o' has no symbols
libtool: warning: 'sysv_sem.o' has no symbols
libtool: warning: 'sysv_msg.o' has no symbols
libtool: warning: 'ptrauth_data_tests_sysctl.o' has no symbols
libtool: warning: 'readonly_proc_tests_sysctl.o' has no symbols
libtool: warning: 'skywalk_stubs.o' has no symbols
libtool: warning: 'cpu_copy_in_cksum_gen.o' has no symbols
libtool: warning: 'ctrr_test_sysctl.o' has no symbols
libtool: warning: 'IOCommandQueue.cpo' has no symbols
libtool: warning: 'TestIODeviceMemoryRosetta.cpo' has no symbols
libtool: warning: 'AppleARMSMP.cpo' has no symbols
warning: ignoring unknown option: --minimize
          STRIP mach.development.bcm2837
built kernel at /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837
```

## archive-14-build-verified-root.log

### the tail

```
PASS: real VerifiedRoot crypto + empty policy table -> libVerifiedRoot.a
      root verification is disabled: no signed policy bundle exists for this board
PASS: DEVELOPMENT_ARM64_BCM2837 holds 857 .o, 120 .cpo, 1 archives, 9 file lists, core 18861504 bytes
PASS: DEVELOPMENT_ARM64_BCM2837 holds 0 .o, 0 .cpo, 0 archives, 0 file lists, core 18861504 bytes
PASS: removed the core image, the file lists and 991 build products
PASS: 117 patched sources carry a fresh mtime
  bsd/kern/bsd_init.c: mtime 08:21:44, carries 'nio: bsd_init:'
  iokit/Kernel/IOService.cpp: mtime 08:21:44, carries 'nio: S1'
  bsd/kern/kern_exec.c: mtime 08:21:44, carries 'nio: exec: load_init_program enter'
```

## archive-13-build-storage-bindings.log

### the tail

```
PASS: libStorageBindings.a -> 18 absolute bindings over 14 kext-owned slots (com.apple.iokit.IOStorageFamily)
    __ZN20IOBlockStorageDevice10gMetaClassE -> 0xfffffff006a051d0
    __ZN20IOBlockStorageDevice11requestIdleEv -> 0xfffffff0045e2050
    __ZN20IOBlockStorageDevice13doSetPriorityEP26IOBlockStorageDeviceExtentjh -> 0xfffffff0045e2068
    __ZN20IOBlockStorageDevice13doSynchronizeEyyj -> 0xfffffff0045e2080
    __ZN20IOBlockStorageDevice13setPropertiesEP8OSObject -> 0xfffffff0045e1f38
    __ZN20IOBlockStorageDevice18doSynchronizeCacheEv -> 0xfffffff0045e2074
    __ZN20IOBlockStorageDevice18getWriteCacheStateEPb -> 0xfffffff0045e2038
    __ZN20IOBlockStorageDevice18setWriteCacheStateEb -> 0xfffffff0045e2044
    __ZN20IOBlockStorageDevice20doGetProvisionStatusEyyPjP35IOBlockStorageProvisionDeviceExtenty -> 0xfffffff0045e208c
    __ZN20IOBlockStorageDevice4initEP12OSDictionary -> 0xfffffff0045e1e30
    __ZN20IOBlockStorageDevice7doUnmapEP26IOBlockStorageDeviceExtentjj -> 0xfffffff0045e205c
    __ZN20IOBlockStorageDevice9metaClassE -> 0xfffffff005c73f40
    __ZN20IOBlockStorageDeviceC1EPK11OSMetaClass -> 0xfffffff0045e1d98
    __ZN20IOBlockStorageDeviceC2EPK11OSMetaClass -> 0xfffffff0045e1d98
    __ZN20IOBlockStorageDeviceD2Ev -> 0xfffffff0045e1db8
    __ZNK20IOBlockStorageDevice11getPropertyEPK8OSSymbol -> 0xfffffff0045e1e88
    __ZNK20IOBlockStorageDevice12getMetaClassEv -> 0xfffffff0045e1dc4
    __ZTV20IOBlockStorageDevice -> 0xfffffff005c73f50

original-bindings.o:
fffffff006a051d0 A __ZN20IOBlockStorageDevice10gMetaClassE
fffffff0045e2050 A __ZN20IOBlockStorageDevice11requestIdleEv
fffffff0045e2068 A __ZN20IOBlockStorageDevice13doSetPriorityEP26IOBlockStorageDeviceExtentjh
fffffff0045e2080 A __ZN20IOBlockStorageDevice13doSynchronizeEyyj
fffffff0045e1f38 A __ZN20IOBlockStorageDevice13setPropertiesEP8OSObject
fffffff0045e2074 A __ZN20IOBlockStorageDevice18doSynchronizeCacheEv
fffffff0045e2038 A __ZN20IOBlockStorageDevice18getWriteCacheStateEPb
fffffff0045e2044 A __ZN20IOBlockStorageDevice18setWriteCacheStateEb
fffffff0045e208c A __ZN20IOBlockStorageDevice20doGetProvisionStatusEyyPjP35IOBlockStorageProvisionDeviceExtenty
fffffff0045e1e30 A __ZN20IOBlockStorageDevice4initEP12OSDictionary
fffffff0045e205c A __ZN20IOBlockStorageDevice7doUnmapEP26IOBlockStorageDeviceExtentjj
fffffff005c73f40 A __ZN20IOBlockStorageDevice9metaClassE
fffffff0045e1d98 A __ZN20IOBlockStorageDeviceC1EPK11OSMetaClass
fffffff0045e1d98 A __ZN20IOBlockStorageDeviceC2EPK11OSMetaClass
fffffff0045e1db8 A __ZN20IOBlockStorageDeviceD2Ev
fffffff0045e1e88 A __ZNK20IOBlockStorageDevice11getPropertyEPK8OSSymbol
fffffff0045e1dc4 A __ZNK20IOBlockStorageDevice12getMetaClassEv
fffffff005c73f50 A __ZTV20IOBlockStorageDevice

```

## archive-12-build-nio-ufs-archive.log

### the tail

```
nio-ufs: build/nio-ufs/libNioUfs.a -> build/sheng-ufs/libShengUfs.a (578096 bytes, sha256 ffe6f6b440387189ac7ade655c3877ef13b1d88a2736d31bae86bf7dec2cfb48)
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
PASS: 31 NativeAdreno a650 objects archived
PASS: archive verified with 31 objects
```

## archive-08-build-libpthread-kernel.log

### the tail

```
every callback the sources call has the name this XNU tree uses
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
28517: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
28523: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
499832: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
499843: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
499854: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
499865: 1413 |                     "| error: latency %d too big (> 1 sec)",
499876: 1420 |                     "| error: jitter %dms too big (latency %dms)",
499887: 1420 |                     "| error: jitter %dms too big (latency %dms)",
499898: 1438 |                     "| error: loss recovery %dms too big",
499909: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
499920: 1463 |                     "| error: output interval %dms too big",
611014: 2626 |                 FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
612746: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
639513:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
639621:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
646617:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
646629:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
684414:  275 |         SASEL_LOG("Returned with error: %d", err);
1059114: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
1059120: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
1848880: 1370 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
1928144:  158 |                 printf("buffer_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
1935467:  268 |                 printf("(%s) Failed to handle availability of LZ4. Error 0x%x\n", __func__, ret);
1944465:  102 |                 printf("progress_notify_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
1953497:  272 |                 printf("zlib_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
1958061:  143 |                 printf("%s failed to allocate memory. Error 0x%x\n", __func__, ret);
2863260:Undefined symbols for architecture arm64:
2863269:ld: symbol(s) not found for architecture arm64
2863270:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
2863271:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
2863272:make[2]: *** [build_all] Error 2
2863273:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
2863274:make: *** [build] Error 2
```

### around them

```
28511- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
28512-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
28513-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
28514-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
28515-      |                 ~~               ^~~~~~~~~~~
28516-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
28517: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
28518-      |                                                                                ~~~
28519-      |                                                                                %zu
28520- 1414 |                                             path, mc_error, fatal_failure_desc_len);
28521-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
28522-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
28523: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
28524-      |                                                                                                   ~~~
28525-      |                                                                                                   %zu
28526- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
28527-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
28528-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
28529- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
28530-      |                             ^
28531-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
28532- 1426 |                 zfree(ZV_NAMEI, vn_path);
28533-      |                 ^
--
499826- 1284 |         kfree_type_impl(kt_view_var, os_ptr_load_and_erase(elem));             \
499827-      |                                      ^
499828-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:67:14: note: expanded from macro 'os_ptr_load_and_erase'
499829-   67 |         __auto_type __elem = *__eptr;                             \
499830-      |                     ^
499831-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1387:7: warning: format specifies type 'int' but the argument has underlying type 'unsigned int' [-Wformat]
499832: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
499833-      |                                                                      ~~
499834-      |                                                                      %u
499835- 1387 |                     p->ifnetem_model);
499836-      |                     ^~~~~~~~~~~~~~~~
499837-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499838-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499839-      |                                                    ~~~~
499840-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499841-      |                                             ^~~~~~~~~~~
499842-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1393:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499843: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
499844-      |                                                           ~~
499845-      |                                                           %u
499846- 1393 |                     p->ifnetem_corruption_p, NETEM_PSCALE);
499847-      |                     ^~~~~~~~~~~~~~~~~~~~~~~
499848-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499849-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499850-      |                                                    ~~~~
499851-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499852-      |                                             ^~~~~~~~~~~
499853-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1399:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499854: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
499855-      |                                                            ~~
499856-      |                                                            %u
499857- 1399 |                     p->ifnetem_duplication_p, NETEM_PSCALE);
499858-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~
499859-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499860-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499861-      |                                                    ~~~~
499862-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499863-      |                                             ^~~~~~~~~~~
499864-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1414:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499865: 1413 |                     "| error: latency %d too big (> 1 sec)",
499866-      |                                       ~~
499867-      |                                       %u
499868- 1414 |                     p->ifnetem_latency_ms);
499869-      |                     ^~~~~~~~~~~~~~~~~~~~~
499870-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499871-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499872-      |                                                    ~~~~
499873-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499874-      |                                             ^~~~~~~~~~~
499875-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499876: 1420 |                     "| error: jitter %dms too big (latency %dms)",
499877-      |                                      ~~
499878-      |                                      %u
499879- 1421 |                     p->ifnetem_jitter_ms, p->ifnetem_latency_ms);
499880-      |                     ^~~~~~~~~~~~~~~~~~~~
499881-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499882-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499883-      |                                                    ~~~~
499884-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499885-      |                                             ^~~~~~~~~~~
499886-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:29: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499887: 1420 |                     "| error: jitter %dms too big (latency %dms)",
499888-      |                                                            ~~
499889-      |                                                            %u
499890- 1421 |                     p->ifnetem_jitter_ms, p->ifnetem_latency_ms);
499891-      |                                           ^~~~~~~~~~~~~~~~~~~~~
499892-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499893-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499894-      |                                                    ~~~~
499895-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499896-      |                                             ^~~~~~~~~~~
499897-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1439:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499898: 1438 |                     "| error: loss recovery %dms too big",
499899-      |                                             ~~
499900-      |                                             %u
499901- 1439 |                     p->ifnetem_loss_recovery_ms);
499902-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~
499903-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499904-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499905-      |                                                    ~~~~
499906-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499907-      |                                             ^~~~~~~~~~~
499908-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1457:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499909: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
499910-      |                                                         ~~
499911-      |                                                         %u
499912- 1457 |                     p->ifnetem_reordering_p, NETEM_PSCALE);
499913-      |                     ^~~~~~~~~~~~~~~~~~~~~~~
499914-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499915-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499916-      |                                                    ~~~~
499917-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499918-      |                                             ^~~~~~~~~~~
499919-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1464:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499920: 1463 |                     "| error: output interval %dms too big",
499921-      |                                               ~~
```

### the tail

```
   50 | const vm_size_t      __attribute__((section("__DATA,__data")))  _lastkerneldataconst_padsize = sizeof(data_const_padding);
      |                                                                 ^
83 warnings generated.
             CC lastkernelconstructor.o
clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libsa/lastkernelconstructor.c:31:13: warning: declaration requires a global constructor [-Wglobal-constructors]
   31 | static void last_kernel_constructor(void) __attribute__ ((constructor));
      | ~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~
1 warning generated.
             CC nonlto.o
clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libsa/nonlto.c:33:33: warning: identifier '__not_used_at_all__' is reserved because it starts with '__' [-Wreserved-identifier]
   33 | int __attribute__((__unused__)) __not_used_at_all__;
      |                                 ^
1 warning generated.
             CC version.o
clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/version.c:39:12: warning: identifier '__kernelVersionString' is reserved because it starts with '__' [-Wreserved-identifier]
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sat Nov 21 08:13:08 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
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
build-xnu-4k-baseline.sh: line 881: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## status.txt

```
patch    189 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-root-name-declared-here.patch
patch    190 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-the-platform-on-class.patch
patch    191 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-waypoints-inside-the-matching.patch
patch    192 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-waypoints-inside-the-passive-match.patch
patch    193 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-the-nvram-matching.patch
patch    194 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-where-the-matching-happens.patch
patch    195 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-the-matching-goes-back-to-the-boot-thread.patch
patch    196 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-a-photograph-can-read-the-beacon.patch
patch    197 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-the-matching-has-four-rounds-in-all.patch
patch    198 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-the-storage-driver-is-offered-its-node.patch
patch    199 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-the-prelinked-storage-personality-asks-for-its-node.patch
patch    200 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-publish-iobsd-before-the-matching.patch
patch    201 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-the-armcpu-probe-and-publish-the-cpu-count.patch
patch    202 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-run-the-matching-off-the-boot-thread.patch
patch    203 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-declare-no-system-mapper.patch
patch    204 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-do-not-wait-for-dlil-threads.patch
patch    205 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-report-the-root-mount-on-the-panel.patch
patch    206 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-do-not-stall-on-iobsd-before-root.patch
patch    207 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-the-secure-root-check.patch
patch    208 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-the-last-bsd-init-steps.patch
patch    209 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-call-bsdinit-task-directly.patch
patch    210 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-the-init-clone-steps.patch
patch    211 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-the-cloneproc-calls.patch
patch    212 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-the-cloneproc-return-wait.patch
patch    213 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-the-fork-create-child-steps.patch
patch    214 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-the-fork-yield.patch
patch    215 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-switch-to-init-map-before-exec.patch
patch    216 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-fix-init-map-accessor.patch
patch    217 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-use-initproc-map-for-exec.patch
patch    218 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-defer-bsdinit-to-init-thread.patch
patch    219 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-the-bsdinit-task-steps.patch
driver   ArmCpu                   base
driver   ArmDTPlatform            base
driver   NioUfs                   device
driver   SoftwareAES              base
kit      AdrenoFirmware           base
kit      AdrenoPM4                base
kit      ArmSmmu4K                base
kit      VerifiedRoot             base
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
