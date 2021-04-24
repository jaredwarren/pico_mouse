
##
### guides
https://hutscape.com/tutorials/pico-neopixel - good one

https://www.raspberrypi.org/blog/neopixel-dithering-with-pico/ - code doesn't work, but otherwise good

https://www.hackster.io/naveenbskumar/raspberry-pi-pico-sound-activated-rgb-led-matrix-e11902 - Best, useable code

### docs
https://raspberrypi.github.io/pico-sdk-doxygen/group__hardware__pio.html


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
$ `make picolights`