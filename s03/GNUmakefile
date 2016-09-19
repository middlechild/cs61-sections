# Default optimization level
O ?= -O0

PROGRAMS = add fib add-O0 add-O3
all: $(PROGRAMS)

include ../common/rules.mk

%.o: %.c $(BUILDSTAMP)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPCFLAGS) $(O) -o $@ -c $<

%-O0.o: %.c $(BUILDSTAMP)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPCFLAGS) -O0 -o $@ -c $<

%-O1.o: %.c $(BUILDSTAMP)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPCFLAGS) -O1 -o $@ -c $<

%-O2.o: %.c $(BUILDSTAMP)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPCFLAGS) -O2 -o $@ -c $<

%-O3.o: %.c $(BUILDSTAMP)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPCFLAGS) -O3 -o $@ -c $<

add: add.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

add-O0: add-O0.o
	$(CC) $(CFLAGS) -O0 -o $@ $^

add-O3: add-O3.o
	$(CC) $(CFLAGS) -O3 -o $@ $^

fib: fib.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

fib-O0: fib-O0.o
	$(CC) $(CFLAGS) -O0 -o $@ $^

fib-O3: fib-O3.o
	$(CC) $(CFLAGS) -O3 -o $@ $^

clean:
	rm -f *.o $(PROGRAMS) *.core
	rm -rf $(DEPSDIR) *.dSYM

.PHONY: all clean
