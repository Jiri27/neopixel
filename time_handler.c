#include <time_handler.h>

void init_time(){
    init_milis();
}
void unsafe_delay(uint32_t mls){ //Unsafe
    uint32_t timer_start = milis();
    while(milis() - timer_start <= mls);
}
void locked_timer_task(void(*pointer)(void), uint32_t delay, uint16_t limit){
    uint32_t time = 0;
    uint16_t c = 0;
    while (limit == 0 || c < limit) { //Loop
        if (milis() - time >= delay) {
            pointer();
            time = milis(); //Reset timer
            if(limit != 0) c++; //limit counter
        }
    }
}
void locked_timer_task_extended(void(*pointer_pre)(void), void(*pointer_timed)(void), void(*pointer_after)(void), uint32_t delay, uint16_t limit){
    uint32_t time = 0;
    uint16_t c = 0;
    while (limit == 0 || c < limit) { //Loop
        if(pointer_pre) pointer_pre();
        if (milis() - time >= delay) {
            pointer_timed();
            time = milis(); //Reset timer
            if(limit != 0) c++; //limit counter
        }
        if(pointer_after) pointer_after();
    }
}
void attach_timer(uint8_t id, uint8_t prescaler, uint32_t period){
    if(id == TIMER2){
        TIM2_TimeBaseInit(prescaler, period);
        TIM2_Cmd(ENABLE);
        TIM2_ITConfig(TIM2_IT_UPDATE, ENABLE);
    }else if(id == TIMER3){
        TIM3_TimeBaseInit(prescaler, period);
        TIM3_Cmd(ENABLE);
        TIM3_ITConfig(TIM3_IT_UPDATE, ENABLE);
    }
}
void attach_pwm(uint8_t id, uint8_t prescaler, uint32_t period, uint16_t duty, bool tim2_in_use){
    if(id == OC21){
        if(tim2_in_use) TIM2_TimeBaseInit(prescaler, period);
        TIM2_OC1Init(
            TIM2_OCMODE_PWM1,
            TIM2_OUTPUTSTATE_ENABLE,
            3000,
            TIM2_OCPOLARITY_HIGH
        );
        TIM2_OC1PreloadConfig(ENABLE);
        if(tim2_in_use) TIM2_Cmd(ENABLE);
    }else if(id == OC22){
        if(tim2_in_use) TIM2_TimeBaseInit(prescaler, period);
        TIM2_OC2Init(
            TIM2_OCMODE_PWM1,
            TIM2_OUTPUTSTATE_ENABLE,
            duty,
            TIM2_OCPOLARITY_HIGH
        );
        TIM2_OC2PreloadConfig(ENABLE);
        if(tim2_in_use) TIM2_Cmd(ENABLE);
    }else if(id == OC23){
        if(tim2_in_use) TIM2_TimeBaseInit(prescaler, period);
        TIM2_OC3Init(
            TIM2_OCMODE_PWM1,
            TIM2_OUTPUTSTATE_ENABLE,
            duty,
            TIM2_OCPOLARITY_HIGH
        );
        TIM2_OC3PreloadConfig(ENABLE);
        if(tim2_in_use) TIM2_Cmd(ENABLE);
    }
}
void update_pwm_duty(uint8_t id, uint16_t duty){
    if(id == OC21){
        TIM2_SetCompare1(duty);
    }else if(id == OC22){
        TIM2_SetCompare2(duty);
    }else if(id == OC23){
        TIM2_SetCompare3(duty);
    }
}