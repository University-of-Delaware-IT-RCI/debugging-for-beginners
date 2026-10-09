
CC		= gcc
CFLAGS		=
OPTCFLAGS	= -O3
DISASM		= objdump --disassemble=main --section=.text

segfault.x: CFLAGS += -fsanitize=address -g

fpe.x: LIBS += -lm

