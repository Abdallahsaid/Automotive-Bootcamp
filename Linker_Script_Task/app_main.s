	.cpu cortex-m4
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"app_main.c"
	.text
	.global	u8InitGLobalVar
	.data
	.type	u8InitGLobalVar, %object
	.size	u8InitGLobalVar, 1
u8InitGLobalVar:
	.byte	2
	.bss
	.align	2
u32NonInitStaticGlobalVar:
	.space	4
	.size	u32NonInitStaticGlobalVar, 4
	.global	u16ConstGlobalVar
	.section	.rodata
	.align	1
	.type	u16ConstGlobalVar, %object
	.size	u16ConstGlobalVar, 2
u16ConstGlobalVar:
	.short	3
	.global	arr
	.section	.sprints,"aw"
	.align	2
	.type	arr, %object
	.size	arr, 5
arr:
	.ascii	"\000\001\002\003\004"
	.text
	.align	1
	.global	main
	.arch armv7e-m
	.syntax unified
	.thumb
	.thumb_func
	.fpu softvfp
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #8
	add	r7, sp, #0
	movs	r3, #4
	strh	r3, [r7, #6]	@ movhi
	movs	r3, #3
	cmp	r3, #3
	bne	.L2
	ldr	r3, .L4
	movs	r2, #6
	str	r2, [r3]
	adds	r3, r7, #6
	mov	r0, r3
	bl	vidFunc
	ldr	r3, .L4+4
	ldrb	r3, [r3]	@ zero_extendqisi2
	adds	r3, r3, #1
	uxtb	r2, r3
	ldr	r3, .L4+4
	strb	r2, [r3]
	b	.L3
.L2:
	ldr	r3, .L4
	movs	r2, #7
	str	r2, [r3]
	ldr	r3, .L4+4
	ldrb	r3, [r3, #1]	@ zero_extendqisi2
	adds	r3, r3, #1
	uxtb	r2, r3
	ldr	r3, .L4+4
	strb	r2, [r3, #1]
.L3:
	b	.L3
.L5:
	.align	2
.L4:
	.word	u32NonInitStaticGlobalVar
	.word	arr
	.size	main, .-main
	.data
	.type	u8InitStaticLocVar.4150, %object
	.size	u8InitStaticLocVar.4150, 1
u8InitStaticLocVar.4150:
	.byte	5
	.ident	"GCC: (GNU Arm Embedded Toolchain 9-2020-q2-update) 9.3.1 20200408 (release)"
