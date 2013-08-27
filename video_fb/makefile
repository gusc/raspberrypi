AS = arm-linux-gnueabihf-as.exe
LD = arm-linux-gnueabihf-ld.exe
CC = arm-linux-gnueabihf-gcc.exe -nostdlib -fno-builtin -nostartfiles -nodefaultlibs -mcpu=arm1176jzf-s
OD = arm-linux-gnueabihf-objcopy.exe
OBJECTS = start.s.o kmain.c.o
TARGET = kernel.img

all: $(TARGET)
	$(OD) kernel.o -O binary ../Release/$(TARGET) 

$(TARGET): $(OBJECTS)
	$(LD) -T kernel.ld $(OBJECTS) -o kernel.o

%.s.o: %.asm
	$(AS) -o $@ $<

%.c.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f *.o ../Release/kernel.img