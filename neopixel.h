#include "stm8s.h"
#define L_PULSE 6 // 6*1/16MHz = 6*62.5 = 375ns (~400ns)
#define H_PULSE 12 // 12*1/16MHz = 12*62.5 = 750ns (~800ns)

#define RED_SCALE 0.6
#define GREEN_SCALE 0.8
#define BLUE_SCALE 1

void init_tim(void);

uint32_t _merge(uint8_t r, uint8_t g, uint8_t b);

void fill_with_color(uint8_t r, uint16_t g, uint8_t b, uint8_t n_leds);

void fill_with_color_hex(uint32_t hex, uint8_t n_leds);

void flush(uint32_t data[65]);