
CC		= gcc
CFLAGS		=
OPTCFLAGS	= -O3
DISASM		= objdump --disassemble=main --section=.text
LIBS		+= -lm

TARGETS		+= simple-i386.s

segfault.x: CFLAGS += -fsanitize=address -g

simple-i386.s: CFLAGS += -march=i386

