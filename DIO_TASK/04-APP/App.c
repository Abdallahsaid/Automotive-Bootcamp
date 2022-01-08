#include "../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include "../03-HAL/01-LED/Led.h"
#include "../03-HAL/02-BUTTON/Button.h"
#include "APP.h"

void APP_vidInit(void){
    LED_vidInit(LED_0);
    BTN_vidInit(BTN_1);

    
    
}

void APP_vidStart(void){
    u8_t button_prev_state=0;
	while(1){

if (BTN_u8IsPressed(BTN_1) == TRUE)
    {   if(button_prev_state == 0){
	    button_prev_state=1;
        LED_vidToggle(LED_0);
    }
    }
    else{
    	button_prev_state= 0;
    }

	}

}
