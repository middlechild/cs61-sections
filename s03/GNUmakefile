# Default optimization level
O ?= -O0

PROGRAMS = fib \
	add-global add-global-O0 add-global-O3 \
	add-local add-local-O0 add-local-O3 \
	add-arguments add-arguments-O0 add-arguments-O3
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

%: %.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

%-O0: %-O0.o
	$(CC) $(CFLAGS) -O0 -o $@ $^

%-O3: %-O3.o
	$(CC) $(CFLAGS) -O3 -o $@ $^

clean:
	rm -f *.o $(PROGRAMS) *.core
	rm -rf $(DEPSDIR) *.dSYM

.PHONY: all clean
.PRECIOUS: %-O0.o %-O3.o
