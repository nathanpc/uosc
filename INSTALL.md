# Installation

Sadly because of UOSCs dependencies on SDL2, yaml-cpp, and the Boost Filesystem libraries, you'll need to compile everything from source. That's not a difficult thing and chances are that you won't have any issues in  the proccess.


## SDL2

First let's install the SDL2 libraries, since probably your distro still haven't updated the packages from 1.2 to 2. First and foremost we should install the dependencies for those libraries. If you're on a Debian-based system, just execute this apt-get:

    sudo apt-get install libasound2-dev libcaca-dev libglu1-mesa-dev libpulse-dev libx11-dev libxext-dev multiarch-support libasound2 libcaca0 libpulse0 libx11-6 libxext6

If you're in another distro, just go to your distro's repo browser and install all the dependencies from the libsdl package.
