CPPFLAGS += -Wall -O2 -Ilibs
LDFLAGS  += -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua5.3

.PHONY: all

all:
	g++ $(CPPFLAGS) src/*.cpp  $(LDFLAGS) -o gameengine


clean:
	rm -f gameengine


run:
	./gameengine
