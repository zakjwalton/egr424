#include <stdlib.h>

#define TEST_STRING "12345"
#define NUMBER_BASE 10

int gResult;

void main(void)
{
    gResult = strtol(TEST_STRING, 0, NUMBER_BASE);
}
