TRGT  = arm-none-eabi-
GDB   = $(TRGT)gdb
HSDIR = build_haskell

include setup.mk

all: $(HSDIR)/hs_main.c
	make -f forc.mk
	cortexflash -X -w bin/output.bin -v /dev/tty.usbmodem1420

$(HSDIR)/hs_main.c: hs_src/Main.hs
	mkdir -p $(HSDIR)
	ajhc -fffi --tdir=$(HSDIR) -C --include=hs_src --include=$(VEXELL)/src -o $@ $<

clean:
	rm -rf build_haskell
	make -f forc.mk clean

gdbwrite: all
	@echo '################################################'
	@echo '##### Use me after running "sudo st-util". #####'
	@echo '################################################'
	$(GDB) -x gdbwrite.boot build/ch.elf

gdbattach: all
	@echo '################################################'
	@echo '##### Use me after running "sudo st-util". #####'
	@echo '################################################'
	$(GDB) -x gdbattach.boot build/ch.elf
