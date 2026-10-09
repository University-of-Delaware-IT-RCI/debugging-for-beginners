
VPATH = ..

-include Makefile.inc

default: simple.s simple-opt.s segfault.x buserror.x illegalinstr.x fpe.x

clean::
	$(RM) *.s *.x

%.s: %.x
	$(DISASM) $< > $@

%.x: %.c
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(LIBS) $<

%-opt.x: %.c
	$(CC) -o $@ $(CFLAGS) $(OPTCFLAGS) $<


