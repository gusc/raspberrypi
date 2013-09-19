AS = arm-linux-gnueabihf-as.exe
LD = arm-linux-gnueabihf-ld.exe
CC = arm-linux-gnueabihf-gcc.exe
OD = arm-linux-gnueabihf-objcopy.exe

ARMFLAGS = -mcpu=arm1176jzf-s -mfpu=vfp -mhard-float
LDFLAGS = -nostdlib
CCFLAGS = --std=c99 -O0 -ffreestanding -fno-builtin -nostdlib -nostartfiles -nodefaultlibs $(ARMFLAGS)

OBJECTS = start.s.o gcc.c.o lib.c.o pages.c.o heap.c.o dma.c.o fb.c.o kmain.c.o
TARGET = kernel.img

all: $(TARGET)
	$(OD) kernel.o -O binary ../Release/$(TARGET) 

$(TARGET): $(OBJECTS)
	$(LD) $(LDFLAGS) -T kernel.ld $(OBJECTS) -o kernel.o

%.s.o: %.asm
	$(AS) -o $@ $<

%.c.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f *.o ../Release/kernel.img