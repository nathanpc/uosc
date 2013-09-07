CXX = clang++
CXXFLAGS = -Wall -std=c++11 $(shell sdl2-config --cflags) $(shell pkg-config SDL2_image SDL2_ttf yaml-cpp --cflags)
LDFLAGS = $(shell sdl2-config --libs) $(shell pkg-config SDL2_image SDL2_ttf yaml-cpp --libs) -lboost_filesystem -lboost_system
OBJ = src/main.o src/config.o src/graphics.o src/texture_manager.o src/text.o src/game_console.o src/games.o src/input_handler.o src/window_properties.o
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
