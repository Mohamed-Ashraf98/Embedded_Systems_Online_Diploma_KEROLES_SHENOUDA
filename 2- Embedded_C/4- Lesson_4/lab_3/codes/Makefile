#@copyright : Mohamed Ashraf El-Sayed

CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -mthumb -g -gdwarf-2
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ= $(As:.s=.o)
Project_name=lab_3


all: $(Project_name).bin
	@echo "-------------------------------- Done --------------------------------"

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld -Map=Map_file.map $(LIBS) $(OBJ) $(AsOBJ) -o $@
	cp $(Project_name).elf $(Project_name).axf

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.map *.elf *.bin

clean:
	rm *.map *.elf *.bin