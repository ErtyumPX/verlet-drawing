# Verlet Drawing

Drawing images using physics simulation.

The project is directly inspired by the video of [Pezzza's Work](https://www.youtube.com/@PezzzasWork),  [Writing a Physics Engine from scratch](https://www.youtube.com/watch?v=lS_qeBy3aQI). Thanks a lot him.

Although the code here is not from the public source code, apart from using quite similar technologies like SFML.

## License

This project is licensed under the [GNU GPL-3.0](https://github.com/ErtyumPX/verlet-drawing/blob/main/LICENSE) license.

Feel free to use the source code. Referring to the repository would be very much appreciated.

## Setup

Project is currently compiled with `GNU G++ 13.2.1`.

The only third-party dependency is `SFML2`. Used version of SFML in project is `2.6.1`.

SFML was selected because of it's ease of use for text rendering with sizes being all agjusted in pixels.

For compiling and linking rules `GNU Make 4.4.1` was used. After downloading dependencies, make sure to change the include paths inside the Makefile.

```
# change the paths for '-I'
CC := g++
CFLAGS := -Wall -std=c++11 -I/usr/include/SDL2           # here
LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system
...
```

After fulfilling dependencies, download or clone the project and use Makefile to easily compile:

```
> make run
```

Since SFML is a cross-platform media library, output should work on Windows, MacOS and Linux.

## General Structure

### Directory Structure and Files

Will be updated soon.

### How It Goes

Will be updated soon.
