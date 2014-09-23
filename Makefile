CC=gcc
CFLAGS=-c -Wall -ansi -pedantic -I./include
ifeq ($(shell uname),Darwin)
	LDFLAGS=-L./lib/osx -lSDL2 -lSDL2_image -llua -lm -liconv -Wl,-framework,OpenGL -Wl,-framework,ForceFeedback -lobjc -Wl,-framework,Cocoa -Wl,-framework,Carbon -Wl,-framework,IOKit -Wl,-framework,CoreAudio -Wl,-framework,AudioToolbox -Wl,-framework,AudioUnit 
endif
ifeq ($(shell uname),Linux)
	LDFLAGS=-L./lib/linux -lSDL2main -lSDL2_image -llua5.2 -Wl,-rpath,./lib/linux -lSDL2 -lpthread -Wl,--no-undefined -lm -ldl -lts -lpthread -lrt
endif

EXEC=pemu
SRC_FOLDER=src
SRC= $(wildcard $(SRC_FOLDER)/*.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

pemu: $(OBJ)
	$(CC) $^ $(LDFLAGS) -o $@

pemu.o: utils.h surface.h gfx.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf $(SRC_FOLDER)/*.o

mrproper: clean
	rm -rf $(EXEC)
