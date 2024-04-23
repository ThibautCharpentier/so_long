# so_long

so_long is an individual 42 school graphic design project where we have to create a small 2D game. We control a hero who must collect any valuables before leaving the place.

## Status

* Success
* Grade: 125/100

## Rules

The map will be constructed with three components walls, collectibles and free spaces. At every move, the current number of movements must be displayed in the shell. We have to use a 2D view (top-down or profile). The game doesn't need to be real-time.

The program displays the image in a window and respects the following rules:
* The management of the window must remain smooth.
* The **W**, **A**, **S**, **D** (qwerty) or **Z**, **Q**, **S**, **D** (azerty) keys will be used to move the main character.
* Pressing **ESC** must close the window and quit program cleanly.
* Clicking on the red cross on the window's frame must close the window and quit the program cleanly.

The program must take as a first argument a map description file with the **.ber** extension:
* The map must be composed of only five possible characters: **0** for an empty space, **1** for a wall, **C** for a collectible, **E** for map exit and **P** for the player's starting position.
* The map must surrounded by walls and must have at least one exit, one collectible and one starting position.
* We don't need to check if there's a valid path in the map.
* The map must be rectangular.

### Bonus

* Enemy patrols that cause the player to lose in case of contact.
* There's some sprite animation.
* Movement count is directly displayed on the screen instead of shell output.

## Project content

This project contains a **libft** folder which is a library that we had to create as the first 42 school project. This folder also includes files corresponding to the following 42 school project: **ft_printf** and **get_next_line**.

The **libmlx** is the MiniLibX library. It is a tiny graphics library which allows us to do the most basic things for rendering something in screen. The **libmlx_mac** is the version for Mac OS.

There is also a **map** folder which contains **.ber** files we can use as a first argument for running the program.

## Usage

Before running the project, you have to set up your MinilibX. Here you will find everything you need to make the library work according to your OS: <https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#installation>.

If you use **libmlx**, make sure that the MinilibX works by running a test. Use ```make libmlx``` command to compile the library then run the test with:
```
./libmlx/test/run_tests.sh
```

If the test works, now pay attention to the following lines in the Makefile file:
```
INCLUDES_HOME = -Ilibft/ -I/usr/include -Imlx_linux
LIBS_HOME = -Llibft -lft -Lmlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz

INCLUDES_42 = -Ilibft/ -I/usr/X11/include -Imlx_linux
LIBS_42 = -Llibft -lft -Lmlx_linux -lmlx -L/usr/X11/lib -lXext -lX11 -lm -lz
```
You must choose the right configuration according to the structure of your system (perhaps the two possible configurations above will not correspond). I recommend you to follow the link I wrote above.
If you use **libmlx**, the right ```-I/usr/*/include``` and ```-L/usr/*/lib``` should match with the first line ```INC=/usr/*/include``` of the ```libmlx/Makefile.gen``` file.
Otherwise, if you use **libmlx_mac**, you have to change the LIBMLX parameter with this line ```LIBMLX = libmlx_mac```.

If everything looks correct, use ```make``` command to compile the project then run the program with:
```
./so_long map/map.ber
```

To run the bonus part, use ```make bonus``` command and run the bonus program with:
```
./so_long_bonus map/map_bonus.ber
```
In the ```map/map_bonus.ber``` file, enemy patrols are represented by the **H** and **V** characters depending on whether they move horizontally or vertically.

If you have a QWERTY keyboard you can change keys in ```srcs/so_long.h``` and in ```srcs_bonus/so_long_bonus.h```.
***
Made by Thibaut Charpentier: <thibaut.charpentier42@gmail.com>
