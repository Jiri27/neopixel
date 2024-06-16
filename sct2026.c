#include <sct2026.h>

void sct_init(){
    GPIO_Init(N_OE_PORT, N_OE_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(N_LATCH_PORT, N_LATCH_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(SDI_PORT, SDI_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(CLK_PORT, CLK_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);

    GPIO_WriteLow(SDI_PORT, SDI_PIN);
    GPIO_WriteLow(CLK_PORT, CLK_PIN);
    GPIO_WriteLow(N_LATCH_PORT, N_LATCH_PIN);
    GPIO_WriteLow(N_OE_PORT, N_OE_PIN);
}
void sct_sendBit(bool bit){
    if(bit) GPIO_WriteHigh(SDI_PORT, SDI_PIN);
    else GPIO_WriteLow(SDI_PORT, SDI_PIN);
    GPIO_WriteHigh(CLK_PORT, CLK_PIN);
    GPIO_WriteLow(CLK_PORT, CLK_PIN);
    GPIO_WriteLow(SDI_PORT, SDI_PIN);
}
void sct_sendWord(uint16_t word){
    for(int i = 0; i < 16; i++){
        uint16_t mask = 0b1 << i;
        uint16_t bit = (uint16_t)(word & mask) >> i;
        sct_sendBit(bit == 0b1);
    }
    GPIO_WriteHigh(N_LATCH_PORT, N_LATCH_PIN);
    GPIO_WriteLow(N_LATCH_PORT, N_LATCH_PIN);
    GPIO_WriteLow(N_OE_PORT, N_OE_PIN);
}
void sct_reset(){
    GPIO_WriteHigh(N_OE_PORT, N_OE_PIN);
}