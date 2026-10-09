
CC		= cl65
CFLAGS		= --cpu 65c02 -t rp6502
OPTCFLAGS	= -r -O -Oi -Or -Os
DISASM		= da65 --cpu 65c02 -S 0x0200

all: simple.x simple-opt.x

