	.syntax unified
	.cpu cortex-m3
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 4
	.eabi_attribute 18, 4
	.thumb
	.file	"function.c"
	.text
	.align	1
	.global	selsort
	.thumb
	.thumb_func
	.type	selsort, %function
selsort:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, r5, r6, r7, r8, lr}
	movs	r2, #0
	adds	r4, r0, #4
	b	.L2
.L7:
	adds	r5, r2, #1
	mov	r6, r4
	mov	r3, r2
	mov	ip, r5
	b	.L3
.L5:
	ldr	r8, [r6], #4
	ldr	r7, [r0, r3, lsl #2]
	cmp	r8, r7
	it	lt
	movlt	r3, ip
	add	ip, ip, #1
.L3:
	cmp	ip, r1
	blt	.L5
	cmp	r3, r2
	beq	.L6
	ldr	r2, [r0, r3, lsl #2]
	ldr	r6, [r4, #-4]
	str	r6, [r0, r3, lsl #2]
	str	r2, [r4, #-4]
.L6:
	adds	r4, r4, #4
	mov	r2, r5
.L2:
	subs	r3, r1, #1
	cmp	r2, r3
	blt	.L7
	pop	{r4, r5, r6, r7, r8, pc}
	.size	selsort, .-selsort
	.ident	"GCC: (Sourcery G++ Lite 2010q1-188) 4.4.1"
