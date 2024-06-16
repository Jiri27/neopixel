#include "neopixel.h"
#define L_PULSE 6 // 6*1/16MHz = 6*62.5 = 375ns (~400ns)
#define H_PULSE 12 // 12*1/16MHz = 12*62.5 = 750ns (~800ns)
void init_tim(void){
    GPIO_Init(GPIOC,GPIO_PIN_1,GPIO_MODE_OUT_PP_LOW_FAST); 
    TIM1_TimeBaseInit(0, TIM1_COUNTERMODE_UP, 15, 0); 
    // OC1 as output with Polarity High in PWM2 mode (OC1N not used)
    TIM1_OC1Init(TIM1_OCMODE_PWM2, TIM1_OUTPUTSTATE_ENABLE, TIM1_OUTPUTNSTATE_DISABLE,
                 1, TIM1_OCPOLARITY_HIGH, TIM1_OCNPOLARITY_HIGH, TIM1_OCIDLESTATE_SET,
                 TIM1_OCNIDLESTATE_RESET);
    TIM1_CtrlPWMOutputs(ENABLE); // časovač výstupu se nastaví jako globální
    TIM1_SelectOnePulseMode(TIM1_OPMODE_SINGLE); // zvolení jedno pulzu
}

uint32_t _merge(uint8_t r, uint8_t g, uint8_t b){
    return ((uint32_t)(g*GREEN_SCALE) << 16) | ((uint32_t)(r*RED_SCALE) << 8) | (uint32_t)(b*BLUE_SCALE);
}


void fill_with_color(uint8_t r, uint16_t g, uint8_t b, uint8_t n_leds){
    uint32_t data =  _merge(r,g,b);
    uint32_t mask;
    disableInterrupts(); // ~25us
    while(n_leds){   // na všechny led
        n_leds--;
        mask=0b100000000000000000000000; // for all bits in byte
        while(mask){
            while(TIM1->CR1 & TIM1_CR1_CEN); // wait if timer run (transmitting last bit)
            if(mask & data){ // send pulse with coresponding length ("L" od "H")
                TIM1->ARRL = H_PULSE; // set pulse width for "H" bit
            }else{
                TIM1->ARRL = L_PULSE; // set pulse width for "L" bit
            }
            TIM1->CR1 |= TIM1_CR1_CEN; // Start timer (start single pulse generation)
            mask = mask >> 1;
        }
    }

    enableInterrupts();
}


void fill_with_color_hex(uint32_t hex, uint8_t n_leds){
    uint32_t mask;
    disableInterrupts(); // can be omitted if interrupts do not take more then about ~25us
    while(n_leds){   // for all bytes from input array
        n_leds--;
        mask=0b100000000000000000000000; // for all bits in byte
        while(mask){
            while(TIM1->CR1 & TIM1_CR1_CEN); // wait if timer run (transmitting last bit)
            if(mask & hex){ // send pulse with coresponding length ("L" od "H")
                TIM1->ARRL = H_PULSE; // set pulse width for "H" bit
            }else{
                TIM1->ARRL = L_PULSE; // set pulse width for "L" bit
            }
            TIM1->CR1 |= TIM1_CR1_CEN; // Start timer (start single pulse generation)
            mask = mask >> 1;
        }
    }

    enableInterrupts();
}


void flush(uint32_t data[65]){

    uint8_t length = 64;
    uint32_t mask;
    disableInterrupts(); // can be omitted if interrupts do not take more then about ~25us
    while(length){   // for all bytes from input array
        length--;
        mask=0b100000000000000000000000; // for all bits in byte
        while(mask){
            while(TIM1->CR1 & TIM1_CR1_CEN); // wait if timer run (transmitting last bit)
            if(mask & data[length]){ // send pulse with coresponding length ("L" od "H")
                TIM1->ARRL = H_PULSE; // set pulse width for "H" bit
            }else{
                TIM1->ARRL = L_PULSE; // set pulse width for "L" bit
            }
            TIM1->CR1 |= TIM1_CR1_CEN; // Start timer (start single pulse generation)
            mask = mask >> 1;
        }
    }

    enableInterrupts();
}




void test(uint8_t* data, uint16_t length){
    uint8_t mask;
    disableInterrupts(); // can be omitted if interrupts do not take more then about ~25us
    while(length){   // for all bytes from input array
        length--;
        mask=0b10000000; // for all bits in byte
        while(mask){
            while(TIM1->CR1 & TIM1_CR1_CEN); // wait if timer run (transmitting last bit)
            if(mask & data[length]){ // send pulse with coresponding length ("L" od "H")
                TIM1->ARRL = H_PULSE; // set pulse width for "H" bit
            }else{
                TIM1->ARRL = L_PULSE; // set pulse width for "L" bit
            }
            TIM1->CR1 |= TIM1_CR1_CEN; // Start timer (start single pulse generation)
            mask = mask >> 1;
        }
    }

    enableInterrupts();
}