void func(void) __attribute__((naked)) ;
void func(void)
{
    asm volatile ("add.w R3, R10, R9, ASR #5");
}
