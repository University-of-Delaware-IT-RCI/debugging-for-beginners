#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static const uint32_t data[] = {0xFEEDFACE, 0xB000B000, 0xCAFECAFE};

int
main()
{
#if defined(__APPLE__) && defined(__aarch64__)
    printf("The aarch64 ABI requires the stack to always be 16-byte aligned.\n"
           "This code instead allocates 4 bytes from the stack.\n"
           "What will be the result?\n\n");
           
    // Misalign the stack pointer by moving it by 4 bytes (not 16-byte aligned)
    // and then attempt to write a value.
    __asm__ __volatile__(
        "mov x0, sp\n"
        "sub x0, x0, #4\n"
        "mov sp, x0\n"
    );
#else
    const void      *opaque_ptr = (const void*)data;
    const uint32_t  *data_ptr = (uint32_t*)(opaque_ptr + 1);
    uint32_t        value;
    
    printf("This program attempts to access an arbitrary unaligned address (%p) in\n"
           "virtual memory as though it is an array of 4-byte words.\n"
           "What will be the result?\n\n", data_ptr);
           
#   if defined(__GNUC__)
#       if defined(__x86_64__)
    // Enable alignment checking on x86_64 architectures
    __asm__ __volatile__("pushfq\n"
                         "orl $0x40000, (%rsp)\n"
                         "popfq");
#           define HAVE_FORCED_ALIGNMENT
#       elif defined(__i386__)
    // Enable alignment checking on x86 architectures
    __asm__ __volatile__("pushf\n"
                         "orl $0x40000, (%esp)\n"
                         "popf");
#           define HAVE_FORCED_ALIGNMENT
#       endif
#   endif
#   ifndef HAVE_FORCED_ALIGNMENT
#       error "This architecture does not (easily) support forced alignment."
#   endif

    /* Cause the alignment error: */
    value = *data_ptr;
    
    printf("Word at %p = 0x%08X\n", data_ptr, value);
#endif

    return 0;
}
