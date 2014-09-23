CC=gcc
CFLAGS=-c -Wall -Werror -ansi -pedantic
LDFLAGS=-llua -framework SDL2 -framework SDL2_image
EXEC=pemu
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

pemu: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

pemu.o: utils.h surface.h gfx.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
