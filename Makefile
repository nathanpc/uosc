CXX = clang++
CXXSTD = c++11
CXXFLAGS = -Wall -std=$(CXXSTD) $(shell sdl2-config --cflags) $(shell pkg-config SDL2_image SDL2_ttf yaml-cpp --cflags)
LDFLAGS = $(shell sdl2-config --libs) $(shell pkg-config SDL2_image SDL2_ttf yaml-cpp --libs) -lboost_filesystem -lboost_system
OBJ = src/main.o src/config.o src/graphics.o src/texture_manager.o src/text.o src/game_console.o src/games.o src/input_handler.o src/window_properties.o
PREFIX = /opt/uosc
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
	sudo mkdir ${PREFIX)
	sudo install ./$(NAME) $(PREFIX)
	sudo install ./assets/ $(PREFIX)
	sudo install ./config.yml $(PREFIX)

uninstall:
	sudo rm $(PREFIX)/$(NAME)
