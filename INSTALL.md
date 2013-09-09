# Installation

Sadly because of UOSCs dependencies on SDL2, yaml-cpp, and the Boost Filesystem libraries, you'll need to compile everything from source. That's not a difficult thing and chances are that you won't have any issues in  the proccess.


## SDL2

Let's begin by installing the SDL2 libraries. Probably your distro still haven't updated the packages on the repos from 1.2 to 2.0, so we'll have to compile those from source. I'll be providing direct download links to the versions that are used to develop UOSC to ensure maximum compatibility.

### Dependencies

First and foremost we should install the dependencies for those libraries. If you're on a Debian-based system, just execute this apt-get:

    sudo apt-get install libasound2-dev libcaca-dev libglu1-mesa-dev libpulse-dev libx11-dev libxext-dev multiarch-support libasound2 libcaca0 libpulse0 libx11-6 libxext6 libjpeg8 libpng12-0 libtiff5 libwebp4 libfreetype6

If you're in another distro, just go to your distro's repo browser and install all the dependencies from the libsdl package.

### SDL2

Let's begin with the core library, download [SDL2-2.0.0.tar.gz](http://www.libsdl.org/release/SDL2-2.0.0.tar.gz) and unpack the archive, then execute the usual commands:

    ./configure
	make
	sudo make install
	make ldconfig

### SDL2_image

UOSC uses the official SDL_image library to display images on the screen. Download [SDL2_image-2.0.0.tar.gz](http://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.0.tar.gz), unpack the archive, and execure the usual commands:

    ./configure
	make
	sudo make install
	make ldconfig

### SDL2_ttf

We need to display text on th screen. Again, download [SDL2_ttf-2.0.12.tar.gz](http://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.12.tar.gz), unpack the archive and execute the usual commands:

    ./configure
	make
	sudo make install
	make ldconfig


## yaml-cpp

UOSC's configuration files are written in [YAML](http://www.yaml.org/) and the best library available for C++ is yaml-cpp.

### Dependencies

yaml-cpp uses [CMake](http://www.cmake.org/), so we have to install it. In a Debian-based distro:

    sudo apt-get install cmake

Now download [yaml-cpp 0.5.1.tar.gz](http://yaml-cpp.googlecode.com/files/yaml-cpp-0.5.1.tar.gz), unpack the archive and execute the following commands:

    mkdir build
	cd build
	cmake -DBUILD_SHARED_LIBS=ON ..
	make
	sudo make install
