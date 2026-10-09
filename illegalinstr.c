#include <stdio.h>

void
mess_up_the_return_address(void)
{
#if defined(__GNUC__)
#   if defined(__x86_64__)
    // Subtract 1 from the 64-bit return address stored at 8(%rbp)
    __asm__ __volatile__(
        "movq 8(%%rbp), %%rax\n"    // Load return address into rax
        "subq $1, %%rax\n"          // Subtract 1 from the return address
        "movq %%rax, 8(%%rbp)"      // Store modified address back to the stack
        :                           // No outputs
        :                           // No inputs
        : "rax", "memory"           // Clobber list
    );
#       define HAVE_RETURN_MANIP
#   elif defined(__i386__)
    // Subtract 1 from the 32-bit return address stored at 4(%ebp)
    __asm__ __volatile__(
        "movl 4(%%ebp), %%eax\n"    // Load return address into eax
        "subl $1, %%eax\n"          // Subtract 1 from the return address
        "movl %%eax, 4(%%ebp)"      // Store modified address back to the stack
        :                           // No outputs
        :                           // No inputs
        : "eax", "memory"           // Clobber list
    );
#       define HAVE_FORCED_ALIGNMENT
#   endif
#endif
}

int
main()
{
    printf("This program calls a function that modifies the return address\n"
           "on the stack so that it will return one byte prior to the appropriate\n"
           "program counter.  What will be the result?\n\n");
           
    mess_up_the_return_address();

    return 0;
}
