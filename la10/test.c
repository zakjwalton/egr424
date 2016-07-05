volatile static unsigned Tick1ms = 0;
// Section: .bss
// Assembly code:
volatile unsigned TickMatch;
// Section: .bss
// Assembly code:
volatile unsigned MatchFlag __attribute__((section(".myvars"))) = 0; 
// Section: .bss
// Assembly code:
extern void disp10(unsigned val); // Print val in base 10
extern void outstr(const char *s); // Print string
void timerISR(void) __attribute__((interrupt("IRQ")));
void timerISR(void)
{
 if(++Tick1ms == TickMatch)
 {
 MatchFlag = 1;
 }
}
void printDeltaTime(void)
{
const char *s = "Delta Ticks: ";
// Section: .text
// Assembly code:
static unsigned lastTime;
// Section: .bss
// Assembly code:
outstr(s);
disp10(Tick1ms - lastTime);
lastTime = Tick1ms;
}
