
VPATH = ..

TARGETS		= simple.s simple-opt.s simple.x simple-opt.x simple-fsan.x \
		  segfault.x buserror.x illegalinstr.x fpe.x \
		  not-so-simple-1.x not-so-simple-1-fsan.x not-so-simple-1-opt.x \
		  not-so-simple-2.x not-so-simple-2-fsan.x not-so-simple-2-opt.x \
		  not-so-simple-3.x not-so-simple-3-opt.x \
		  not-so-simple-4.x not-so-simple-4-opt.x \
		  mypyfunc.$(SOEXT)

CFLAGS		= -I.

SANTZCFLAGS	= -fsanitize=address -g

.PHONY: default all clean

default:: all

-include Makefile.inc

all: $(TARGETS)

clean::
	$(RM) *.s *.x *.$(SOEXT)

%.s: %.x
	$(DISASM) $< > $@

%.x: %.c
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(LIBS) $<

%-opt.x: %.c
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(LIBS) $(OPTCFLAGS) $<

%-fsan.x: %.c
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(LIBS) $(SANTZCFLAGS) $<

%.$(SOEXT): %.c
	$(CC) -fPIC -shared -o $@ $(CFLAGS) $(OPTCFLAGS) $(LDFLAGS) $(LIBS) $<

not-so-simple-%-opt.x: CFLAGS += -g

