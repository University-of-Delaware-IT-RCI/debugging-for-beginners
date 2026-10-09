
CC		= gcc
CFLAGS		=
OPTCFLAGS	= -O3
DISASM		= objdump --disassemble=main --section=.text
LIBS		+= -lm

segfault.x: CFLAGS += -fsanitize=address -g

