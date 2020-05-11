# Asteriods Game in C++

## Dependencies
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Tips on installing SDL2 & SDL2 Image
#### Mac 
- `brew install sdl2`
- `brew install sdl2_image`

#### Linux
- `sudo apt-get install libsdl2-dev`
- `sudo apt-get install libsdl2-image-dev`

## Basic Build Instructions

1. Clone this repo. `git clone https://github.com/jayahariv/asteroids.git`
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make -j`
4. Run it: `./AsteroidsGame`

## How to play the game
- top / down arrow keys to move forward and backward
- left and right to rotate the ship
- press `a` to fire


### Future
- stars in the sky
- break astroid to smaller pieces
- sounds