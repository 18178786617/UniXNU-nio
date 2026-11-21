# Why the build failed

run: 609, commit f8cb134c4d744ac0ea0656ccc63025d31e498ebf

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

## archive-01-build-corecrypto-14.log

### the tail

```
529 kernel C sources; 0 failures
No XNU symbol names: run a kernel pass first (it writes link.filelist)
```

## storage-headers.log

### the tail

```
PASS: 19 public IOStorageFamily headers prepared at e45fbe30a7879e0b16e26dddb78538f1b00e0bff
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
[07:38:40] script start (bootstrap=1 jobs=3)
  object MISSING
  source sha 7f0001b1c67c2652
[07:40:40] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha 7f0001b1c67c2652
[07:51:01] script start (bootstrap=0 jobs=3)
  object MISSING
  source sha 7f0001b1c67c2652
[07:51:02] before make (bootstrap=0 jobs=3)
  object MISSING
  source sha 7f0001b1c67c2652
[07:55:08] after make (bootstrap=0 jobs=3)
  object 120752 bytes sha c027c9a6fc995c3a
  source sha 7f0001b1c67c2652
```

## kernel.log

### the errors

```
39958: 1370 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
54033: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
54039: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
55746:call__ ## check, void *, m/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/_types.h:74 sh:25pc, int, error: warning: ort)    identifier '__darwin_sigset_t' is reserved because it starts with '__' [-Wreserved-identifier]
533179:  158 |                 printf("buffer_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
553391:lability of LZ4. Error 0x%x\n", __func__, ret);
574435:led to allocate memory. Error 0x%x\n", ret);
597496:  272 |                 printf("zlib_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
609446:  143 |                 printf("%s failed to allocate memory. Error 0x%x\n", __func__, ret);
637595:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/sysctl.h:416:2 error: note: expanded from macro 'SYSCTL_OID'
1001964:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/machine/atomic.hider, error:32:
1106655:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:1277:9 1049 |         os_log_error: note: expanded from macro 'kalloc_type_2'
1544096: 1413 |                     "| error: latency %d too big (> 1 sec)",
1544114:_ # 1420 |                     "|# var = error:  { &var, grpjitter %dms too , attrbig ( }; \
1544135: 1420 |                     "| error: jitter %dms too big ((LOCKS, latency %dms)",
1614125:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:1205reply_error:29: warning: identifier '__kalloc_array_decode' is reserved because it starts with '__' [-Wreserved-identifier]
1840729:&nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
1880652:internaion_  lt468 error: "
1880946:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
1895725:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
1895737:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
2462805: 3383 |                     "(os_reasoe KALLOCn_all_DISPoc_buffer error: %ATCH1(base, N, ...) __COd, kcdata error: %NCAT(bd, length: %ld)ase, N)(__V\n",
2462814:_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:1282:2error: note: expanded from macro 'kfree_type_2'
```

### around them

```
39952- 1360 |                         IOLog("Failed to open corefile of size %llu MB (returned error 0x%x)\n",
39953-      |                                                                                          ~~
39954-      |                                                                                          %x
39955- 1361 |                             (corefile_fallback_size_bytes / (1024ULL * 1024ULL)), err);
39956-      |                                                                                   ^~~
39957-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1370:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
39958: 1370 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
39959-      |                                                                                   ~~     ^~~
39960-      |                                                                                   %x
39961-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1453:2: warning: 'switch' missing 'default' label [-Wswitch-default]
39962- 1453 |         switch (op) {
39963-      |         ^
39964-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1536:20: warning: missing field 'total' initializer [-Wmissing-designated-field-initializers]
39965- 1536 |         c_string = (char*)kalloc_data(string_length, (zalloc_flags_t)(Z_ZERO | Z_WAITOK | Z_NOFAIL));
39966-      |                           ^
39967-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:512:2: note: expanded from macro 'kalloc_data'
39968-  512 |         kheap_alloc(KHEAP_DATA_BUFFERS, size, flags)
--
54027- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
54028-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
54029-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
54030-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
54031-      |                 ~~               ^~~~~~~~~~~
54032-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
54033: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
54034-      |                                                                                ~~~
54035-      |                                                                                %zu
54036- 1414 |                                             path, mc_error, fatal_failure_desc_len);
54037-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
54038-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
54039: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
54040-      |                                                                                                   ~~~
54041-      |                                                                                                   %zu
54042- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
54043-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
54044-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
54045- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
54046-      |                             ^
54047-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
54048- 1426 |                 zfree(ZV_NAMEI, vn_path);
54049-      |                 ^
--
55740-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:265ef_t:14 _; : Atomic(  note: expanded from macro 'MAC_CHECK'short)       /
55741-            *   265 a[? |         tomic_short;
55742-             ??] pro|         ^  ce
55743-   /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdatomic.h:102:9: sswarning: DTRACE'_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
55744-   102 | typedef __MACF3(and grAtmaouomic(unsigp IDs c__ned*/
55745-      |                         ^
55746:call__ ## check, void *, m/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/_types.h:74 sh:25pc, int, error: warning: ort)    identifier '__darwin_sigset_t' is reserved because it starts with '__' [-Wreserved-identifier]
55747-, int, MAC_ITERATE at_CHomiEC   74 | typc_ushort;
55748-      |         ^
55749-edef __uint32_t      __darwin_sigset_t;      /* [???] signal set */
55750-      |                         ^
55751-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdatomic.h:103:9: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
55752-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/_types.h:75:25K); \
55753-      |                     ^
55754-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165:2  103:: note: expanded from macro 'DTRACE_MACF3'
55755-  165 |  warning:  | t        Didentifier '__darwin_suseconds_t' is reserved because it starts with '__' [-Wreserved-identifier]
55756-ypeTRACE_P   75deRO | tf BEy_Ato3pemi(__sdt_dec(, name, arf ing1__t), in  arg2, arg  t33)  2_;
--
637589-CTLF/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.h:97:33: warning: identifier '__darwin_ssize_t' is reserved because it starts with '__' [-Wreserved-identifier]
637590-LAG_RW | CTLFLAG_LOCKED,   97 | typedef long                    _
637591-      | ^
637592-_darw/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/sysctl.h:486:2: note: expanded from macro 'SYSCTL_UINT'
637593-in_s  486 |         SYSCTL_OID(parent, nbr, size_t;       /*name, CTLTYP byte count orE_INT|access, \
637594-      |         ^
637595:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/sysctl.h:416:2 error: note: expanded from macro 'SYSCTL_OID'
637596- */
637597-      |                                 ^
637598-  416 |         __STARTUP_ARG(sysctl_##parent,/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.h:98: _##name,           33: warning: identifier '__darwin_time_t' is reserved because it starts with '__' [-Wreserved-identifier]
637599-          98 | typedef long                \
637600-      |         ^
637601-  /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/startup.h:736:2: note: expanded from macro '__STARTUP_ARG'
637602-                  736 |         __STARTUP1(name, line __darwin_time_t; , subsystem, rank, fun       /* time()c, arg, arg)
637603-      |         ^
637604- */
637605-      |                                 ^
--
1001958-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if_ipsec.c:2099:3: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
1001959- 2099 |                 os_log_error(OS_LOG_DEFAULT, "%s can't getIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/ipc_misc.c:30:
1001960-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_port.h:86:
1001961-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/turnstile.h: %s prov53:
1001962-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/waitq.h:49:
1001963-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/mpsc_queue.h:34:
1001964:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/machine/atomic.hider, error:32:
1001965-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic_private.h:199:
1001966-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic_private_impl.h:45 %d\n",
1001967-      |                 ^
1001968-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5: note: expanded from macro 'os_log_error'
1001969-  396 |     _S:1: warning: identifier '_os_atomic_mo_has_acquire' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
1001970-tat   45 | _os_atomic_assert(_ic_mo_has_a_builtincquire(OS_A_constant_pTOMIC_STD m(format), "emory_order ord)
1001971-      | ^
1001972-format string must be constant");             \
1001973-      |     ^
1001974-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic_private_impl.h:59:1: warning: identifier '_os_atomic_mo_has_release' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
--
1106649-      |                                        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1106650-note: (skipping 1 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)
1106651-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:50: note: <scratch space>:137:1: note: expanded from here
1106652-  137 | kalloc_type_2
1106653-      | ^expanded from macro 'NECPDATATRACELOG'
1106654-
1106655:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:1277:9 1049 |         os_log_error: note: expanded from macro 'kalloc_type_2'
1106656-(necp_data_trace_ 1277 |         static _KALLOClog_handle, "%s: " fo_TYPE_DEFINE(kt_viewrmat "\n", __FUNCTIO_var, type, KT_SN__, __VA_ARGS__HARED_ACCT);      ); \
1106657-      |                                                         ^~~~~~
1106658- /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:397:83: note: expanded from macro 'os_log_error'
1106659-  397 |     __attr  \
1106660-      |                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1106661-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:1518:17ibute__((section(": note: expanded from macro '_KALLOC_TYPE_DEFINE'
1106662-_In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/lock_ptr.c:41:
1106663-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/machine/machine_cpu.h:34:
1106664-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/machine_cpu.h: _TEXT,__o35:
1106665-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/cpu_data_internal.h:46:
--
1544090-      |                                                    ~~~~
1544091-ATIC_A  118 |          SSERT     _OVER     LOADE     D_MAC    _RO(___FUNCVA_ARGTION__, ##_S__, __VA_ARGS__)static_asse; \
1544092-      rt_2_|                                             ^~~~~~~~~~~
1544093-args, _static_assert_1_arg)(__VA_ARGS__)
1544094-      |                                                                                         ^
1544095-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1414:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
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
PASS: DEVELOPMENT_ARM64_BCM2837 holds 857 .o, 120 .cpo, 0 archives, 9 file lists, core absent
PASS: DEVELOPMENT_ARM64_BCM2837 holds 0 .o, 0 .cpo, 0 archives, 0 file lists, core absent
PASS: removed the core image, the file lists and 987 build products
PASS: 117 patched sources carry a fresh mtime
  bsd/kern/bsd_init.c: mtime 07:51:01, carries 'nio: bsd_init:'
  iokit/Kernel/IOService.cpp: mtime 07:51:01, carries 'nio: S1'
  bsd/kern/kern_exec.c: mtime 07:51:01, carries 'nio: exec: load_init_program enter'
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
nio-ufs: build/nio-ufs/libNioUfs.a -> build/sheng-ufs/libShengUfs.a (578096 bytes, sha256 6ed3751d428db16fb77ace1b71ef6ab51f38b38bd714ec7034a92b05582b0623)
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
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sat Nov 21 07:49:50 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
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
