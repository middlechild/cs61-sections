# Default optimization level
O ?= 0

PROGRAMS = mymalloc_driver add
all: $(PROGRAMS)

include ../common/rules.mk

%.o: %.c $(BUILDSTAMP)
	$(CC) $(CFLAGS) $(DEPCFLAGS) -o $@ -c $<

add: add.o
	$(CC) $(CFLAGS) $(SAFE_CFLAGS) -o $@ $^

mymalloc_driver: mymalloc.o mymalloc_driver.o
	$(CC) $(CFLAGS) $(SAFE_CFLAGS) -o $@ $^

clean:
	rm -f $(PROGRAMS) *.o *.dSYM *.core
	rm -rf $(DEPSDIR)

.PHONY: all clean
