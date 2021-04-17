FROM gcc:10

RUN apt-get update && apt-get install -y \
  cmake \
  gcc-arm-none-eabi \
  libnewlib-arm-none-eabi \
  build-essential

RUN mkdir pico && \
 cd pico && \
 git clone -b master https://github.com/raspberrypi/pico-sdk.git && \
 cd pico-sdk && \
 git submodule update --init

ENV PICO_SDK_PATH=/pico/pico-sdk

CMD ["pwd"]