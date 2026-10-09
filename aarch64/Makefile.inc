
CC		= cc
CFLAGS		=
OPTCFLAGS	= -O3
DISASM		= otool -tjV

TARGETS	+=	baseaddr.x

CFLAGS +=	-I.

segfault.x: CFLAGS += -fsanitize=address -g

