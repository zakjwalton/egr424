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
	.file	"lab2.c"
	.global	__aeabi_ldivmod
	.text
	.align	2
	.global	func
	.thumb
	.thumb_func
	.type	func, %function
func:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r3, r4, r5, lr}
	movw	r4, #:lower16:gLast
	movt	r4, #:upper16:gLast
	mov	r2, r0
	mov	r3, r1
	str	r0, [r4, #0]
	adr	r5, .L5
	ldrd	r4, [r5]
	cmp	r4, r2
	sbcs	ip, r5, r3
	bge	.L2
	mov	r2, #1000
	movs	r3, #0
	bl	__aeabi_ldivmod
	mov	r2, r0
	mov	r3, r1
.L2:
	mov	r1, r3
	mov	r0, r2
	pop	{r3, r4, r5, pc}
.L6:
	.align	3
.L5:
	.word	12345677
	.word	0
	.size	func, .-func
	.comm	gLast,4,4
	.ident	"GCC: (Sourcery G++ Lite 2010q1-188) 4.4.1"
