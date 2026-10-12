
CC		= gcc
CFLAGS		=
OPTCFLAGS	= -O3
DISASM		= objdump --disassemble=main --section=.text
LIBS		+= -lm

TARGETS		+= simple-i386.s simple-i386-opt.s

segfault.x: CFLAGS += -fsanitize=address -g

simple-i386.s: simple.c
	$(CC) -o $@ -S $(CFLAGS) -march=i386 -m32 $<

simple-i386-opt.s: simple.c
	$(CC) -o $@ -S $(CFLAGS) $(OPTCFLAGS) -march=i386 -m32 $<

