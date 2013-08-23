AS = arm-linux-gnueabihf-as.exe
LD = arm-linux-gnueabihf-ld.exe
CC = arm-linux-gnueabihf-gcc.exe -nostdlib -fno-builtin -nostartfiles -nodefaultlibs -mcpu arm1176jzf-s
OBJECTS = start.s.o kmain.c.o

all: $(OBJECTS)
	$(LD) -T kernel.ld $(OBJECTS) -o ../Release/kernel.img

%.s.o: %.asm
	$(AS) -o $@ $<

%.c.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f *.o ../Release/kernel.img