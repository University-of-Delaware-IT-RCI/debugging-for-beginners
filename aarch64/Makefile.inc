
CC		= cc
CFLAGS		+=
OPTCFLAGS	+= -O3
DISASM		= otool -tjV
SOEXT		= dylib
SANTZCFLAGS	+= -frtlib-add-rpath

