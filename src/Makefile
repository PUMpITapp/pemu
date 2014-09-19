CC=gcc
CFLAGS=-c -Wall
LDFLAGS=-llua -framework SDL2
EXEC=pemu
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

pemu: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

pemu.o: surface.h gfx.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
