#include <controls.h>

int isUp(struct Controls* pointer){
    int state = !GPIO_ReadInputPin(INPUT_PORT,UP_BTN);
    return state;
}
int isDown(struct Controls* pointer){
    int state = !GPIO_ReadInputPin(INPUT_PORT,DOWN_BTN);
    return state;
}
int isSelect(struct Controls* pointer){
    int state = !GPIO_ReadInputPin(INPUT_PORT,SELECT_BTN);
    return state;
}
int getUp(struct Controls* pointer){
    int result = 0;
    int state = GPIO_ReadInputPin(INPUT_PORT,UP_BTN);
    if(state == 0){
        result = pointer->old_up != state;
    }
    pointer->old_up = state;
    return result;
}
int getDown(struct Controls* pointer){
    int result = 0;
    int state = GPIO_ReadInputPin(INPUT_PORT,DOWN_BTN);
    if(state == 0){
        result = pointer->old_down != state;
    }
    pointer->old_down = state;
    return result;
}
int getSelect(struct Controls* pointer){
    int result = 0;
    int state = GPIO_ReadInputPin(INPUT_PORT,SELECT_BTN);
    if(state == 0){
        result = pointer->old_select != state;
    }
    pointer->old_select = state;
    return result;
}
int init_controls(struct Controls* pointer){
    pointer->old_up = 0;
    pointer->old_down = 0;
    pointer->old_select = 0;

    GPIO_Init(INPUT_PORT, UP_BTN, GPIO_MODE_IN_PU_NO_IT);
    GPIO_Init(INPUT_PORT, DOWN_BTN, GPIO_MODE_IN_PU_NO_IT);
    GPIO_Init(INPUT_PORT, SELECT_BTN, GPIO_MODE_IN_PU_NO_IT);
    return 0;
}