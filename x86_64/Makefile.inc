
CC		= gcc
CFLAGS		=
OPTCFLAGS	= -O3
DISASM		= objdump --disassemble=main --section=.text
LIBS		+= -lm

TARGETS		+= simple-i386.s simple-i386-opt.s

segfault.x: CFLAGS += -fsanitize=address -g

simple-i386.s: CFLAGS += -march=i386 -m32

simple-i386-opt.s: CFLAGS += -march=i386 -m32

simple-i386.s: simple.c

simple-i386-opt.s: simple.c

