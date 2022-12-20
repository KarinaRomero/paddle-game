# Paddle Game

## Game Description
This game is inspired in the pong game and the blocks puzzle games, the gameplay has two balls and paddles as the image, each ball can break blocks, the player on the right is a bot.

![gameplay](https://github.com/KarinaRomero/paddle-game/blob/main/images/gameplay.png)

## Rules
- The opponent's ball will never touch your own wall since the range is limited to 3/4 of the screen, but the balls can collide with each other.
- Each player collect points when the ball break a block.
- Each player loses 150 points if the ball touches their own wall.
- Each block has the next points and rates to be spawned values:

| Block Name      | Points | Rate     |
| :---        |    :----:   |          ---: |
| ![#122CB8](https://placehold.co/15x15/122CB8/122CB8.png) `#122CB8` **Duncan**      | 600       | 9%   |
| ![#855885](https://placehold.co/15x15/855885/855885.png) `#855885` **Vlad**      | 550       | 10%   |
| ![#2FAFEB](https://placehold.co/15x15/2FAFEB/2FAFEB.png) `#2FAFEB` **Davon**      | 250       | 15%   |
| ![#ED9F6B](https://placehold.co/15x15/ED9F6B/ED9F6B.png) `#ED9F6B` **Frank**      | 150       | 22%   |
| ![#B83C12](https://placehold.co/15x15/B83C12/B83C12.png) `#B83C12` **Zane**      | 100       | 44%   |


## Libraries
This game is made whit **[Simple Direct Media Layer](https://wiki.libsdl.org/SDL2/FrontPage)** for the System operative **Ubuntu**, open the terminal and install the next packages:

```
sudo apt-get update
sudo apt-get install libsdl2-dev
sudo apt install libsdl2-image-dev
sudo apt-get install libsdl2-ttf-dev
sudo apt-get install libsdl2-mixer-dev
```

## How to compile?

First of all you need the compiler gcc/g++ >= 7.4.0 in this **[link](https://www.guru99.com/c-gcc-install.html)** there are the general instructions, but if you are using ubuntu, run the next command in the command line:

```
sudo apt install build-essential
```

This project can be compiled whit cmake If it is not installed on your PC, follow the instructions in this **[link](https://vitux.com/how-to-install-cmake-on-ubuntu/)**, or if you are using ubuntu, you can simply install by command line using:

```
sudo apt-get install cmake
```

Once cmake is installed, open the terminal in the root folder of the project and run the following commands in the next order:

```
mkdir build && cd build
cmake ..
make
./PaddleGame
```

*Note: This project contains cmake files that search SDL2, SLD_image, SLD_ttf and SDL_mixer in your system.*

## Known issues and future improvements

- Some textures have a black border.
- Sometimes the ball collides many times with other objects.
- The texture component load one texture for each object, this can be improve to load one texture for any number of objects.
- The Window class holds the logic for the input, this can be separated.

## Class diagram

![Class Diagram](https://github.com/KarinaRomero/paddle-game/blob/main/images/ClassDiagram.png)

## Rubric coverage


### README (All Rubric Points REQUIRED)

| README      | Location or example for the point |
| :---        |    :----:   |
| The README is included with the project and has instructions for building/running the project.      | [How to compile?](#how-to-compile)       
| If any additional libraries are needed to run the project, these are indicated with cross-platform installation instructions.     | [Libraries](#libraries)       
| You can submit your writeup as markdown or pdf.     | [Paddle Game](#paddle-game)       
| The README describes the project you have built      | [Game Description](#game-description)       
| The README also indicates the file and class structure, along with the expected behavior or output of the program.     | [Class diagram](#class-diagram)       
| The README indicates which rubric points are addressed. The README also indicates where in the code (i.e. files and line numbers) that the rubric points are addressed.     | [Rubric coverage](#rubric-coverage)       

### Compiling and Testing (All Rubric Points REQUIRED)

| Compiling and Testing      | Location or example for the point |
| :---        |    :----:   |
| The project code must compile and run without errors.      | The project is compiled via cmake and contains cmake files to look up the libraries and directories    

### Loops, Functions, I/O (Optional points coverage)

| Loops, Functions, I/O      | Location or example for the point |
| :---        |    :----:   |
| The project code is clearly organized into functions.      |  Is present in the code but this class can be an example `window.cpp`
| The project reads data from an external file or writes data to a file as part of the necessary operation of the program.      |  The best score is saved in a txt file `Utilities::ReadBestScore()` & `Utilities::SaveBestScore(int score)` -> `utilities.h:32`
| The project accepts input from a user as part of the necessary operation of the program..      |  In the class `Window::Input()` to move the paddle

### Object Oriented Programming (Optional points coverage)

| OOP      | Location or example for the point |
| :---        |    :----:   |
| The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.      |  [Class diagram](#class-diagram) 
| All class data members are explicitly specified as public, protected, or private.      |  This class can be an example `game_object.h` 
| All class members that are set to argument values are initialized through member initialization lists.      |  The GameObject constructor `GameObject::GameObject(std::string path, Utilities::Vector2D position) : _position(position), _initialPosition(position), _path(path` -> `game_object.cpp:10`
| One function is overloaded with different signatures for the same function name.      |  The function `Draw()` in the `GameObject` class -> `game_object.h:39`
| One function is declared with a template that allows it to accept a generic parameter.      |  The function `Utilities::RandomNumberByRates()` in the `Utilities` namespace -> `utilities.h:32`

### Memory Management (Optional points coverage)

| Memory Management      | Location or example for the point |
| :---        |    :----:   |
| At least one class that uses unmanaged dynamically allocated memory, along with any class that otherwise needs to modify state upon the termination of an object, uses a destructor.      |  [Class diagram](#class-diagram) 
| The project follows the Resource Acquisition Is Initialization pattern where appropriate, by allocating objects at compile-time, initializing objects when they are declared, and utilizing scope to ensure their automatic destruction..      |  This class can be an example `window.cpp`
| The project uses at least one smart pointer: unique_ptr, shared_ptr, or weak_ptr. The project does not use raw pointers.      |  This class can be an example `main.cpp`


## Assets

- [Acme Font](https://fonts.google.com/specimen/Acme?query=Acme)
- [Sprites](https://norma-2d.itch.io/celestial-objects-pixel-art-pack)
- [Music](https://tallbeard.itch.io/music-loop-bundle)
- [VFX](https://ellr.itch.io/universal-ui-soundpack)
- [Background](https://bacteri.itch.io/background-space)

## Bibliography

- [Udacity resources](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213)
- [Udacity repositories](https://github.com/orgs/udacity/repositories)
- [SDL](https://wiki.libsdl.org/SDL2/FrontPage)
- [Cmake](https://vitux.com/how-to-install-cmake-on-ubuntu/)
- [Cmake c++ tutorials](https://cmake.org/cmake/help/latest/guide/tutorial/Adding%20Generator%20Expressions.html#exercise-1-setting-the-c-standard-with-interface-libraries)
- [Ball movement within an area](https://codereview.stackexchange.com/questions/277369/ball-movement-within-an-area)
- [Timing: Frame Rate, Physics, Animation](https://thenumb.at/cpp-course/sdl2/08/08.html)
- [Lazy Foo' Productions](https://lazyfoo.net/tutorials/SDL/index.php#Sound%20Effects%20and%20Music)
- [Cmake files to find SDL2 and SDL_image](https://github.com/trenki2/SDL2Test)
- [Cmake files to find SDL_mixer and SDL_ttf](https://github.com/aminosbh/sdl2-ttf-sample/tree/master/cmake/sdl2)
- [SDL Game Development by Shaun Mitchell](https://www.packtpub.com/product/sdl-game-development/9781849696821?_ga=2.185403753.1362938751.1671468971-1042951398.1670260284)
- [Colors in markdown git](https://stackoverflow.com/questions/11509830/how-to-add-color-to-githubs-readme-md-file)
- [Markdown](https://www.markdownguide.org/basic-syntax/#code-blocks)
