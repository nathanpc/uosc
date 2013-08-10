CXX = clang++
CXXFLAGS = -Wall $(shell sdl2-config --cflags) $(shell pkg-config SDL2_image --cflags)
LDFLAGS = $(shell sdl2-config --libs) $(shell pkg-config SDL2_image --libs)
OBJ = src/main.o src/graphics.o src/texture_manager.o
PREFIX = /usr/bin
NAME = uosc

all: build

build: $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $(NAME) $(LIBS)

debug: CXXFLAGS += -g3 -DDEBUG
debug: build

%.o: %.c
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $<

clean:
	rm -rf src/*.o
	rm -rf $(NAME)

install: build
	sudo chmod a+x ./$(NAME)
	sudo install ./$(NAME) $(PREFIX)

uninstall:
	sudo rm -f $(PREFIX)/$(NAME)
