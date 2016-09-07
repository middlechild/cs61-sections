# build all programs with names like `membug[0-9]`
MEMBUG = $(patsubst %.c,%,$(sort $(wildcard membug[0-9].c)))

all: $(MEMBUG) heap

# Default optimization level
O ?= -O0

LIBS = -lm

include ../common/rules.mk

%.o: %.c $(BUILDSTAMP)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPCFLAGS) $(O) -o $@ -c $<

heap: heap.o
	$(CC) $(CFLAGS) $(O) -o $@ $^ $(LIBS)

membug%: membug%.o
	$(CC) $(CFLAGS) $(O) -o $@ $^ $(LIBS)

clean: clean-main
clean-main:
	$(call run,rm -f heap $(MEMBUG) heap *.o core *.core,CLEAN)
	$(call run,rm -rf out $(DEPSDIR) *.dSYM)

.PHONY: all clean clean-main
