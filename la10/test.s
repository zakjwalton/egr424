	.syntax unified
	.cpu cortex-m3
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 2
	.eabi_attribute 18, 4
	.thumb
	.file	"test.c"
	.text
	.align	2
	.global	timerISR
	.thumb
	.thumb_func
	.type	timerISR, %function
timerISR:
	@ Stack Align: May be called with mis-aligned SP.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	movw	r0, #:lower16:.LANCHOR0
	movt	r0, #:upper16:.LANCHOR0
	ldr	r3, [r0, #0]
	mov	ip, sp
	bic	r2, ip, #7
	adds	r1, r3, #1
	mov	sp, r2
	movw	r2, #:lower16:TickMatch
	str	r1, [r0, #0]
	movt	r2, #:upper16:TickMatch
	ldr	r1, [r0, #0]
	ldr	r3, [r2, #0]
	push	{ip}
	cmp	r1, r3
	bne	.L3
	movw	r1, #:lower16:.LANCHOR1
	movt	r1, #:upper16:.LANCHOR1
	movs	r0, #1
	str	r0, [r1, #0]
.L3:
	pop	{r0}
	mov	sp, r0
	bx	lr
	.size	timerISR, .-timerISR
	.align	2
	.global	printDeltaTime
	.thumb
	.thumb_func
	.type	printDeltaTime, %function
printDeltaTime:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, lr}
	movw	r0, #:lower16:.LC0
	movw	r4, #:lower16:.LANCHOR0
	movt	r4, #:upper16:.LANCHOR0
	movt	r0, #:upper16:.LC0
	bl	outstr
	ldr	r0, [r4, #0]
	ldr	r1, [r4, #4]
	subs	r0, r0, r1
	bl	disp10
	ldr	r3, [r4, #0]
	str	r3, [r4, #4]
	pop	{r4, pc}
	.size	printDeltaTime, .-printDeltaTime
	.global	MatchFlag
	.comm	TickMatch,4,4
	.section	.rodata.str1.4,"aMS",%progbits,1
	.align	2
.LC0:
	.ascii	"Delta Ticks: \000"
	.section	.myvars,"aw",%progbits
	.align	2
	.set	.LANCHOR1,. + 0
	.type	MatchFlag, %object
	.size	MatchFlag, 4
MatchFlag:
	.space	4
	.bss
	.align	2
	.set	.LANCHOR0,. + 0
	.type	Tick1ms, %object
	.size	Tick1ms, 4
Tick1ms:
	.space	4
	.type	lastTime.1280, %object
	.size	lastTime.1280, 4
lastTime.1280:
	.space	4
	.ident	"GCC: (Sourcery G++ Lite 2010q1-188) 4.4.1"
