
VPATH = ..

TARGETS	=	simple.s simple-opt.s simple.x simple-opt.x simple-fsan.x \
		segfault.x buserror.x illegalinstr.x fpe.x \
		not-so-simple.x not-so-simple-fsan.x

-include Makefile.inc

default: $(TARGETS)

clean::
	$(RM) *.s *.x

%.s: %.x
	$(DISASM) $< > $@

%.x: %.c
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(LIBS) $<

%-opt.x: %.c
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(LIBS) $(OPTCFLAGS) $<

%-fsan.x: %.c
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(LIBS) -fsanitize=address -g $<

