notes.md


build: `docker build  -t pico .`
Run: `docker run --rm pico  `




building uf2


docker run -it --rm -v `pwd`:/blink -w /blink pico /bin/bash
$ mkdir build
$ cd build
$ cmake ..

$ make blink