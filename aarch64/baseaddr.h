
#ifndef __BASEADDR_H__
#define __BASEADDR_H__

#include <mach-o/dyld.h>

static inline
void
show_vmaddr_base_offset(void)
{
    intptr_t    slide = _dyld_get_image_vmaddr_slide(0);

    printf("[APPLE-VM-INFO] base address offset = 0x%016lx\n", slide);
}

#endif /* __BASEADDR_H__ */
