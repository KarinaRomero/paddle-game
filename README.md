# Paddle Game

## Game Description
This game is inspired in the pong game and the blocks puzzle games, the gameplay has two balls and paddles as the image, each ball can break blocks, the player on the right is a bot.

![alt text](https://github.com/KarinaRomero/paddle-game/blob/main/images/gameplay.png)

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

This project can be compiled whit cmake If it is not installed on your PC, follow the instructions in this **[link](https://vitux.com/how-to-install-cmake-on-ubuntu/)**.

Once cmake is installed, open the terminal in the root folder of the project and run the following commands in the next order:

```
mkdir build && cd build
cmake..
make
./PaddleGame
```

*Note: This project contains cmake files that search SDL2, SLD_image, SLD_ttf and SDL_mixer in your system.*

## Class diagram

## Rubric coverage



## Known issues and future improvements

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
