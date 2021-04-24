/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"
#include "pico/multicore.h"

#define STRING_LEN 6

int bit_depth=12;
const int PIN_TX = 0;

uint32_t pixelsb[STRING_LEN];
uint32_t errorsb[STRING_LEN];

uint32_t pixelsr[STRING_LEN];
uint32_t errorsr[STRING_LEN];

uint32_t pixelsg[STRING_LEN];
uint32_t errorsg[STRING_LEN];

static inline void put_pixel(uint32_t pixel_grb) {
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
    return
            ((uint32_t) (r) << 8) |
            ((uint32_t) (g) << 16) |
            (uint32_t) (b);
}

void ws2812b_core() {
#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(150);
        gpio_put(LED_PIN, 0);
        sleep_ms(150);
        gpio_put(LED_PIN, 1);
        sleep_ms(350);
        gpio_put(LED_PIN, 0);
        sleep_ms(350);

        gpio_put(LED_PIN, 1);
        sleep_ms(1350);
        gpio_put(LED_PIN, 0);
        sleep_ms(1350);
    }
#endif


	// int valuer, valueg, valueb;
	// int shift = bit_depth-8;
	
    // while (1){
		
	// 	for(int i=0; i<STRING_LEN; i++) {
	// 		valueb=(pixelsb[i] + errorsb[i]) >> shift;
	// 		valuer=(pixelsr[i] + errorsr[i]) >> shift;
	// 		valueg=(pixelsg[i] + errorsg[i]) >> shift;

	// 		put_pixel(urgb_u32(valuer, valueg, valueb));
	// 		errorsb[i] = (pixelsb[i] + errorsb[i]) - (valueb << shift); 
	// 		errorsr[i] = (pixelsr[i] + errorsr[i]) - (valuer << shift); 
	// 		errorsg[i] = (pixelsg[i] + errorsg[i]) - (valueg << shift); 
	// 	}
	// 	sleep_us(400);
	// }
}	
		


int main() {
	
	setup_default_uart();
	
	PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, PIN_TX, 800000, false);
	
	for(int i=0; i< STRING_LEN; ++i) {
		pixelsr[i]=0;
		pixelsg[i]=0;
		pixelsb[i]=0;
	}
 
	multicore_launch_core1(ws2812b_core);

    int valuer, valueg, valueb;
	int shift = bit_depth-8;
	
    while (1){
		
		for(int i=0; i<STRING_LEN; i++) {
			valueb=(pixelsb[i] + errorsb[i]) >> shift;
			valuer=(pixelsr[i] + errorsr[i]) >> shift;
			valueg=(pixelsg[i] + errorsg[i]) >> shift;

			put_pixel(urgb_u32(valuer, valueg, valueb));
			errorsb[i] = (pixelsb[i] + errorsb[i]) - (valueb << shift); 
			errorsr[i] = (pixelsr[i] + errorsr[i]) - (valuer << shift); 
			errorsg[i] = (pixelsg[i] + errorsg[i]) - (valueg << shift); 
		}
		sleep_us(400);
	}
   
    // while (1) {

        
        // for(int i=0; i< STRING_LEN; ++i) {
        //     pixelsr[i]=128;
        //     pixelsg[i]=0;
        //     pixelsb[i]=0;
        //     sleep_ms(50);
        // }
        // sleep_ms(500);

        // for(int i=0; i< STRING_LEN; ++i) {
        //     pixelsr[i]=0;
        //     pixelsg[i]=0;
        //     pixelsb[i]=0;
        // }
        // sleep_ms(100);

        // for(int i=0; i< STRING_LEN; ++i) {
        //     pixelsr[i]=0;
        //     pixelsg[i]=255;
        //     pixelsb[i]=0;
        //     sleep_ms(50);
        // }
        // sleep_ms(500);

        // for (int i = 0; i < 30; ++i) {
		// 	for (int j=0;j<30;++j){
		// 		pixelsb[0] = j;
		// 		if(j%8 == 0) { pixelsb[1] = j; }
		// 		pixelsr[2] = j;
		// 		if(j%8 == 0) { pixelsr[3] = j; }
		// 		pixelsg[4] = j;
		// 		if(j%8 == 0) { pixelsg[5] = j; }
		// 		pixelsg[6] = j;
		// 		pixelsr[6] = j;
		// 		pixelsb[6] = j;
		// 		if(j%8 == 0) { 
		// 			pixelsg[7] = j;
		// 			pixelsr[7] = j;
		// 			pixelsb[7] = j; 
		// 		}					
		// 		sleep_ms(50);
		// 	}
		// 	for (int j=30;j>0;--j){
		// 		pixelsb[0] = j;
		// 		if(j%8 == 0) { pixelsb[1] = j; }
		// 		pixelsr[2] = j;
		// 		if(j%8 == 0) { pixelsr[3] = j; }
		// 		pixelsg[4] = j;
		// 		if(j%8 == 0) { pixelsg[5] = j; }
		// 		pixelsg[6] = j;
		// 		pixelsr[6] = j;
		// 		pixelsb[6] = j;
		// 		if(j%8 == 0) { 
		// 			pixelsg[7] = j;
		// 			pixelsr[7] = j;
		// 			pixelsb[7] = j; 
		// 		}					
		// 		sleep_ms(50);
		// 	}
        // }
    // }
}