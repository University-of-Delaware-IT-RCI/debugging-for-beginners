
CC		= cc
CFLAGS		=
OPTCFLAGS	= -O3
DISASM		= otool -tV

TARGETS	+=	baseaddr.x

CFLAGS +=	-I.

segfault.x: CFLAGS += -fsanitize=address -g

