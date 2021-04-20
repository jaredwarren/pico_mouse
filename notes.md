

## Docker
build: `docker build  -t pico .`
Run: `docker run --rm pico  `




## building uf2

`docker run -it --rm -v `pwd`:/blink -w /blink pico /bin/bash`

first
$ `mkdir build`
$ `cd build`
$ `cmake ..`
$ `make blink`

re-build
`docker run -it --rm -v `pwd`:/blink -w /blink pico /bin/bash`

$ `cd build`
$ `make blink`




# picolights
docker run -it --rm -v `pwd`:/blink -w /blink pico /bin/bash
$ `cd build`
$ `make picolights`?