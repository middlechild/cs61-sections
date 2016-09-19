# Default optimization level
O ?= -O0

PROGRAMS = fib add
all: $(PROGRAMS)

include ../common/rules.mk

%.o: %.c $(BUILDSTAMP)
	$(CC) $(CFLAGS) $(O) $(DEPCFLAGS) -o $@ -c $<

add: add.o
	$(CC) $(CFLAGS) $(O) $(SAFE_CFLAGS) -o $@ $^

fib: fib.o fib.o
	$(CC) $(CFLAGS) $(O) $(SAFE_CFLAGS) -o $@ $^

clean:
	rm -f $(PROGRAMS) *.o *.dSYM *.core
	rm -rf $(DEPSDIR)

.PHONY: all clean
