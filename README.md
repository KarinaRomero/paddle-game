# Paddle Game

## Game Description
This game is inspired in the pong game and the blocks puzzle games, the gameplay has two balls and paddles as the image, each ball can break blocks, the player on the right is a bot.

## Rules
- The opponent's ball will never touch your own wall since the range is limited to 3/4 of the screen, but the balls can collide with each other.
- Each player collect points when the ball break a block.
- Each player loses 150 points if the ball touches their own wall.
- Each block has the next points and rates to be spawned values:

| Block Name      | Points | Rate     |
| :---        |    :----:   |          ---: |
| <span style="color:#122CB8">**Duncan**</span>      | 600       | 9%   |
| <span style="color:#855885">**Vlad**</span>      | 550       | 10%   |
| <span style="color:#2FAFEB">**Davon**</span>      | 250       | 15%   |
| <span style="color:#ED9F6B">**Frank**</span>      | 150       | 22%   |
| <span style="color:#B83C12">**Zane**</span>      | 100       | 44%   |

## Libraries
This game is made whit [Simple Direct Media Layer](https://wiki.libsdl.org/SDL2/FrontPage) for the System operative Ubuntu, open the terminal and install the next packages:

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

- [SDL](https://wiki.libsdl.org/SDL2/FrontPage)
- [Cmake](https://vitux.com/how-to-install-cmake-on-ubuntu/)
- [Cmake c++ tutorials](https://cmake.org/cmake/help/latest/guide/tutorial/Adding%20Generator%20Expressions.html#exercise-1-setting-the-c-standard-with-interface-libraries)
- [Ball movement within an area](https://codereview.stackexchange.com/questions/277369/ball-movement-within-an-area)
- [Timing: Frame Rate, Physics, Animation](https://thenumb.at/cpp-course/sdl2/08/08.html)
- [Lazy Foo' Productions](https://lazyfoo.net/tutorials/SDL/index.php#Sound%20Effects%20and%20Music)
- [Cmake files to find SDL2 and SDL_image](https://github.com/trenki2/SDL2Test)
- [Cmake files to find SDL_mixer and SDL_ttf](https://github.com/aminosbh/sdl2-ttf-sample/tree/master/cmake/sdl2)
- [SDL Game Development by Shaun Mitchell](https://www.packtpub.com/product/sdl-game-development/9781849696821?_ga=2.185403753.1362938751.1671468971-1042951398.1670260284)