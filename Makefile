
VPATH = ..

TARGETS	=	simple.s simple-opt.s simple.x simple-opt.x \
		segfault.x buserror.x illegalinstr.x fpe.x

-include Makefile.inc

default: $(TARGETS)

clean::
	$(RM) *.s *.x

%.s: %.x
	$(DISASM) $< > $@

%.x: %.c
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(LIBS) $<

%-opt.x: %.c
	$(CC) -o $@ $(CFLAGS) $(OPTCFLAGS) $<


