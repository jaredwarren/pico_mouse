
##
### guides
https://github.com/raspberrypi/pico-examples/tree/master/usb/device/dev_hid_composite

### docs
https://raspberrypi.github.io/pico-sdk-doxygen/group__hardware__pio.html


## Docker
build: `docker build  -t pico .`
Run: `docker run --rm pico  `




## building uf2

`docker run -it --rm -v `pwd`:/mouse -w /mouse pico /bin/bash`

first
$ `mkdir build`
$ `cd build`
$ `cmake ..`
$ `make mouse`

re-build
`docker run -it --rm -v `pwd`:/mouse -w /mouse pico /bin/bash`

$ `cd build`
$ `make mouse`




# mouse
docker run -it --rm -v `pwd`:/mouse -w /mouse pico /bin/bash
$ `cd build`
$ `make mouse`



# calc sin
https://www.desmos.com/calculator/w9jrdpvsmk