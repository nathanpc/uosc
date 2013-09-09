# UOSC

The ultimate old school console.


## Requirements

Of course this project has some requirements...

  - [SDL 2.0](http://libsdl.org/)
  - [SDL2_Image 2.0](http://www.libsdl.org/tmp/SDL_image/)
  - [SDL2_TTF 2.0](http://www.libsdl.org/tmp/SDL_ttf/)
  - [yaml-cpp](https://code.google.com/p/yaml-cpp/)
  - [Boost Filesystem](http://www.boost.org/doc/libs/1_54_0/libs/filesystem/doc/index.htm)


## Installation

For detailed instructions on how to install UOSC please read the [INSTALL.md](https://github.com/nathanpc/uosc/blob/master/INSTALL.md) document.


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


## Screenshot

This is how awesome UOSC looks like:

![A very simple example](http://screencloud.net/img/screenshots/52d39c33126feec597d5c12c669567cc.png)
