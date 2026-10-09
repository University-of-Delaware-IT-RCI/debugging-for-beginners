#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int
main()
{
    uint8_t     *bytes = (uint8_t*)(0x3FFFFFFD80000042);
    
    printf("This program attempts to access an arbitrary address (%p) in\n"
           "virtual memory.  What will be the result?\n\n", bytes);
    printf("Byte at %p = 0x%hhX\n", bytes, *bytes);
    return 0;
}
