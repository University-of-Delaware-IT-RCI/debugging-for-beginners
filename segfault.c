#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__APPLE__)
#   include "baseaddr.h"

__attribute__((constructor))
void
apple_vm_info(void)
{
    show_vmaddr_base_offset();
}

#endif

int
main()
{
    uint8_t     *bytes = (uint8_t*)(0x3FFFFFFD80000042);
    
    printf("This program attempts to access an arbitrary address (%p) in\n"
           "virtual memory.  What will be the result?\n\n", bytes);
    printf("Byte at %p = 0x%hhX\n", bytes, *bytes);
    return 0;
}
