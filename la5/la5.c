#include <stdarg.h>

extern void func (int i);

void test (int N, ...)
{
    va_list List; // Declare a pointer to whatever parameters were passed to us,
    // after the “fixed” parameters
    va_start(List, N); // Initialize this pointer to the first parameter passed
    // after the known “fixed” parameter N
    while(N--)
    {
        func(va_arg(List, int)); // va_arg increments to the next parameter in
        // List and interprets it to be of type “int”
    }
    va_end(List); // This usually does nothing, but it’s a complement to
    // va_start()
}

void testtest(void)
{
    test(5,1,2,3);
}
