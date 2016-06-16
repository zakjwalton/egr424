  20              	selsort:
  23 0000 2DE9F041 		push	{r4, r5, r6, r7, r8, lr}
  24 0004 0022     		movs	r2, #0
  25 0006 041D     		adds	r4, r0, #4
  26 0008 1BE0     		b	.L2
  27              	.L7:
  28 000a 551C     		adds	r5, r2, #1
  29 000c 2646     		mov	r6, r4
  30 000e 1346     		mov	r3, r2 // Store start in r3
  31 0010 AC46     		mov	ip, r5
  32 0012 08E0     		b	.L3
  33              	.L5:
  34 0014 56F8048B 		ldr	r8, [r6], #4 //This is Data[i], post index by 4
  35 0018 50F82370 		ldr	r7, [r0, r3, lsl #2] //This is Data[minix]
  36 001c B845     		cmp	r8, r7 
  37 001e B8BF     		it	lt
  38 0020 6346     		movlt	r3, ip //Does this if Data[i] < Data[minix]
  39 0022 0CF1010C 		add	ip, ip, #1 //i++
  40              	.L3:
  41 0026 8C45     		cmp	ip, r1 //Determine if i is still < N
  42 0028 F4DB     		blt	.L5
  43 002a 9342     		cmp	r3, r2
  44 002c 07D0     		beq	.L6
  45 002e 50F82320 		ldr	r2, [r0, r3, lsl #2]
  46 0032 54F8046C 		ldr	r6, [r4, #-4]
  47 0036 40F82360 		str	r6, [r0, r3, lsl #2]
  48 003a 44F8042C 		str	r2, [r4, #-4]
  49              	.L6:
  50 003e 0434     		adds	r4, r4, #4 //Start is increment, so I will start at 1+ before
  51 0040 2A46     		mov	r2, r5
  52              	.L2:
  53 0042 4B1E     		subs	r3, r1, #1
  54 0044 9A42     		cmp	r2, r3
  55 0046 E0DB     		blt	.L7
  56 0048 BDE8F081 		pop	{r4, r5, r6, r7, r8, pc}
