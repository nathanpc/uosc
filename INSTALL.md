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

### SDL2_image

UOSC uses the official SDL_image library to display images on the screen. Download [SDL2_image-2.0.0.tar.gz](http://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.0.tar.gz), unpack the archive, and execure the usual commands:

    ./configure
	make
	sudo make install

### SDL2_ttf

We need to display text on th screen. Again, download [SDL2_ttf-2.0.12.tar.gz](http://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.12.tar.gz), unpack the archive and execute the usual commands:

    ./configure
	make
	sudo make install
	make ldconfig


## Boost Libraries

Your distro probably have this library collection in the repos jugding by how popular it is, so let's install it:

    sudo apt-get install libboost1.50-all-dev


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


## UOSC

Finally let's install UOSC, it's the easiest one:

    make
	sudo make install

If you're on a Raspberry Pi or a machine that doesn't have clang++ execute the `make` command like this:

    make CXX=g++ CXXSTD=c++0x


## Configuring

UOSC's configuration file is written in YAML, which means it's extremely human-friendly, but I decided to help you a bit to understand how to populate the file with your desired emulators. Let's start with an example and the go through it line-by-line:

```yml
---

emulators:
  - id: gba
    name: GameBoy Advance
    icon:
      x: 7
      y: 4
    exec: "vba {rom}"
    roms: "/home/nathanpc/ROMs/GameBoy/"
    ignore_ext: ".sav"
  - id: genesis
    name: Sega Genesis
    icon:
      x: 8
      y: 25
    exec: "dgen {rom}"
    roms: "/home/nathanpc/ROMs/Genesis/"

...
```

First we have a list of the emulators that UOSC should know about. Each emulator contains the following required attributes:

  - `id`: A unique identifier, which will be used internally to identify each emulator
  - `name`: A descriptive name
  - `icon`: This where we'll put the information about the console icon
    - `x`: The row of the icon in the `assets/console.png` file
    - `y`: The collumn of the icon in the `assets/console.png` file
  - `exec`: The command that should be executed to launch the emulator. `{rom}` will indicate where UOSC should insert the ROM file in the command
  - `roms`: Where UOSC should look to index the roms
  - `ignore_ext`: This specifies which extensions UOSC should ignore (save files for example) when indexing the ROMs folder


## The End

Yup, that's all folks. Now you have UOSC installed and configured in your system.
