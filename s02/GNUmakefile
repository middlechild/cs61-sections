all: heap fibrec var

O ?= -O0

LIBS = -lm

include ../common/rules.mk

%.o: %.c $(BUILDSTAMP)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPCFLAGS) $(O) -o $@ -c $<

heap: heap.o
	$(CC) $(CFLAGS) $(O) -o $@ $^ $(LIBS)

fibloop: fibloop.o
	$(CC) $(CFLAGS) $(O) -o $@ $^ $(LIBS)

fibrec: fibrec.o
	$(CC) $(CFLAGS) $(O) -o $@ $^ $(LIBS)

var: var.o
	$(CC) $(CFLAGS) $(O) -o $@ $^ $(LIBS)

clean: clean-main
clean-main:
	$(call run,rm -f heap fibrec var *.o core *.core,CLEAN)
	$(call run,rm -rf out $(DEPSDIR) *.dSYM)

.PHONY: all clean clean-main
