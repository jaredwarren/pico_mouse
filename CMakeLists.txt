cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(mouse)

pico_sdk_init()

add_executable(mouse
    mouse.c
    usb_descriptors.c
)

# pico_generate_pio_header(mouse ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio)

# target_include_directories(mouse PRIVATE ${CMAKE_CURRENT_LIST_DIR})

target_sources(mouse PRIVATE mouse.c)

#target_link_libraries(mouse PRIVATE pico_stdlib tinyusb_device tinyusb_board)
target_include_directories(mouse PRIVATE ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(mouse PRIVATE pico_stdlib tinyusb_device tinyusb_board)


pico_add_extra_outputs(mouse)