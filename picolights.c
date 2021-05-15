#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/gpio.h"
// #include "hardware/adc.h"
#include "ws2812.pio.h"
#include "math.h"

#define PIN_TX 0
#define N_PIXELS 16

#define PI 3.14159265

#define A 64.0
#define H 100.0
#define B 64.0
#define K 64.0
#define STEPS 128 * PI

static inline void put_pixel(uint32_t pixel_grb) {
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
    return
            ((uint32_t) (r) << 8) |
            ((uint32_t) (g) << 16) |
            (uint32_t) (b);
}

static double getY(int j) {
    // return A * sin(j / B);
    return A * sin((j-H) / B)+K;
}

int main() {
    stdio_init_all();
    // adc_init();

    // adc_gpio_init(26);
    // // Select ADC input 0 (GPIO26)
    // adc_select_input(0);

    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, PIN_TX, 800000, false); //rgb

    uint32_t pixels[N_PIXELS] = {0};
    sleep_ms(2000);

    while (1) {
        // long sound_intensity = 0;
        // for(int i=0; i<32; i++) {
        //     sound_intensity += adc_read();
        // }
        // sound_intensity >>= 5;


        // for(int i=0; i<N_PIXELS; i++) {
        //     // pixels[i] = rand();

        //     pixels[i] = urgb_u32(0xff, 0, 0)
        //     // pixels[i] = urgb_u32(0, 0, 0)
        //     // 0xff, 0, 0

        //     // pixels[3]
		// 	// valueb=(pixelsb[i] + errorsb[i]) >> shift;
		// 	// valuer=(pixelsr[i] + errorsr[i]) >> shift;
		// 	// valueg=(pixelsg[i] + errorsg[i]) >> shift;

		// 	// put_pixel(urgb_u32(valuer, valueg, valueb));
		// 	// errorsb[i] = (pixelsb[i] + errorsb[i]) - (valueb << shift); 
		// 	// errorsr[i] = (pixelsr[i] + errorsr[i]) - (valuer << shift); 
		// 	// errorsg[i] = (pixelsg[i] + errorsg[i]) - (valueg << shift); 

        //     put_pixel(pixels[i]);
        //     // sleep_ms(50);
		// }

        long steps = 128;


        double y = 0;


       

        // Red
        for (int j = 0; j < STEPS; j++)
        {
            y = getY(j);
            for(int i=0; i<N_PIXELS; i++) {
                pixels[i] = urgb_u32(y, 0, 0);
                put_pixel(pixels[i]);
            }
            sleep_ms(50);
        }
        sleep_ms(250);

        // Blue
        for (int j = 0; j < STEPS; j++)
        {
            y = getY(j);
            for (int i = 0; i < N_PIXELS; i++)
            {
                pixels[i] = urgb_u32(0, 0, y);
                put_pixel(pixels[i]);
            }
            sleep_ms(50);
        }
        sleep_ms(250);

        // gold 145 145 80
        for (int j = 0; j < STEPS; j++)
        {
            y = getY(j);
            for (int i = 0; i < N_PIXELS; i++)
            {
                pixels[i] = urgb_u32(((145/128)*y), ((145/128)*y), ((80/128)*y));
                put_pixel(pixels[i]);
            }
            sleep_ms(50);
        }
        sleep_ms(250);

        // diamond 78 178 178
        for (int j = 0; j < STEPS; j++)
        {
            y = getY(j);
            for (int i = 0; i < N_PIXELS; i++)
            {
                pixels[i] = urgb_u32(((78/128)*y), ((178/128)*y), ((178/128)*y));
                put_pixel(pixels[i]);
            }
            sleep_ms(50);
        }
        sleep_ms(250);

        // Green
        for (int j = 0; j < STEPS; j++)
        {
            y = getY(j);
            for (int i = 0; i < N_PIXELS; i++)
            {
                pixels[i] = urgb_u32(0, y, 0);
                put_pixel(pixels[i]);
            }
            sleep_ms(50);
        }
        sleep_ms(250);

        // // iron 107 88 74
        // for (int j = 0; j < B * PI; j++)
        // {
        //     y = A * sin(j / B);
        //     for (int i = 0; i < N_PIXELS; i++)
        //     {
        //         pixels[i] = urgb_u32(((107/128)*y), ((88/128)*y), ((74/128)*y));
        //         put_pixel(pixels[i]);
        //     }
        //     sleep_ms(50);
        // }
        // sleep_ms(250);

        // // fade out
        // for(int j=steps; j>0; j--) {
        //     for(int i=0; i<N_PIXELS; i++) {
        //         pixels[i] = urgb_u32(j, 0, 0);
        //         put_pixel(pixels[i]);
        //     }
        //     sleep_ms(50);
		// }
        // sleep_ms(250);

        // // blue
        // // fade in
        // for(int j=0; j<steps; j++) {
        //     for(int i=0; i<N_PIXELS; i++) {
        //         pixels[i] = urgb_u32(0, 0, j);
        //         put_pixel(pixels[i]);
        //     }
        //     sleep_ms(50);
		// }
        // sleep_ms(250);

        // // fade out
        // for(int j=steps; j>0; j--) {
        //     for(int i=0; i<N_PIXELS; i++) {
        //         pixels[i] = urgb_u32(0, 0, j);
        //         put_pixel(pixels[i]);
        //     }
        //     sleep_ms(50);
		// }
        // sleep_ms(250);

        
        // sleep_ms(250);
        // for(int i=0; i<N_PIXELS; i++) {
        //     pixels[i] = urgb_u32(0x80, 0, 0);
        //     put_pixel(pixels[i]);
		// }
        // sleep_ms(250);
        // for(int i=0; i<N_PIXELS; i++) {
        //     pixels[i] = urgb_u32(0x40, 0, 0);
        //     put_pixel(pixels[i]);
		// }
        // sleep_ms(250);
        // for(int i=0; i<N_PIXELS; i++) {
        //     pixels[i] = urgb_u32(0x20, 0, 0);
        //     put_pixel(pixels[i]);
		// }
        // sleep_ms(250);
        // for(int i=0; i<N_PIXELS; i++) {
        //     pixels[i] = urgb_u32(0, 0, 0);
        //     put_pixel(pixels[i]);
		// }
        // sleep_ms(1000);


        // for(int i=0; i<N_PIXELS; i++) {
        //     pixels[i] = urgb_u32(0, 0, 0xff);
        //     put_pixel(pixels[i]);
		// }
        // sleep_ms(250);
        // for(int i=0; i<N_PIXELS; i++) {
        //     pixels[i] = urgb_u32(0, 0, 0x80);
        //     put_pixel(pixels[i]);
		// }
        // sleep_ms(250);
        // for(int i=0; i<N_PIXELS; i++) {
        //     pixels[i] = urgb_u32(0, 0, 0x40);
        //     put_pixel(pixels[i]);
		// }
        // sleep_ms(250);
        // for(int i=0; i<N_PIXELS; i++) {
        //     pixels[i] = urgb_u32(0, 0, 0x20);
        //     put_pixel(pixels[i]);
		// }
        // sleep_ms(250);
        // for(int i=0; i<N_PIXELS; i++) {
        //     pixels[i] = urgb_u32(0, 0, 0);
        //     put_pixel(pixels[i]);
		// }
        // sleep_ms(1000);

        // pixels[3]  = pixels[2];
        // pixels[4]  = pixels[5];
        // pixels[11] = pixels[10];
        // pixels[15] = pixels[14];

        // pixels[2]  = pixels[1];
        // pixels[5]  = pixels[6];
        // pixels[10] = pixels[9];
        // pixels[14] = pixels[13];

        // pixels[1]  = pixels[0];
        // pixels[6]  = pixels[7];
        // pixels[9]  = pixels[8];
        // pixels[13] = pixels[12];

        // sound_intensity = 2200;

        // if (sound_intensity >= 2200) {
        //     pixels[0]  = rand();
        //     pixels[7]  = rand();
        //     pixels[8]  = rand();
        //     pixels[12] = rand();
        // } else if (sound_intensity >= 1700) {
        //     pixels[0]  = rand();
        //     pixels[7]  = rand();
        //     pixels[8]  = rand();
        //     pixels[12] = urgb_u32(0, 0, 0);
        // } else if (sound_intensity >= 1250) {
        //     pixels[0]  = rand();
        //     pixels[7]  = rand();
        //     pixels[8]  = urgb_u32(0, 0, 0);
        //     pixels[12] = urgb_u32(0, 0, 0);
        // } else if (sound_intensity >= 800) {
        //     pixels[0]  = rand();
        //     pixels[7]  = urgb_u32(0, 0, 0);
        //     pixels[8]  = urgb_u32(0, 0, 0);
        //     pixels[12] = urgb_u32(0, 0, 0);
        // } else {
        //     pixels[0]  = urgb_u32(0, 0, 0);
        //     pixels[7]  = urgb_u32(0, 0, 0);
        //     pixels[8]  = urgb_u32(0, 0, 0);
        //     pixels[12] = urgb_u32(0, 0, 0);
        // }

        // for (uint8_t i = 0; i < N_PIXELS; i++) {
        //     put_pixel(pixels[i]);
        // }

        // sleep_ms(200);
    }
}