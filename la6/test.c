extern unsigned addem(void) __attribute__((naked));
unsigned addem(void) {
      asm volatile(
           "MOV R6, #1\n"
           "STR R6, [SP, #0x8]\n"
           "MOVW LR, #0x193\n"
           "BX LR"
      );
}
