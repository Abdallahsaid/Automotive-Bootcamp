#include "../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include "../03-HAL/01-LED/Led.h"
#include "../02-MCAL/registers.h"
#include "../02-MCAL/TIMER/Timer.h"
#include "APP.h"

void ISR(void);
u16_t gu16_timer0_counter=0;



void APP_vidInit(void)
{   
    LED_vidInit(LED_0);
    TIMER_vidTimer0Init();
    SetCallBack_Timer0OVF(ISR);
    SET_BIT(SREG,7);
    TIMER_vidTimer0Start(131);
    
}

void APP_vidStart(void)
{
    while (1)
    {
        if (gu16_timer0_counter == 300)
        {
           LED_vidOff(LED_0);
        }
        else if(gu16_timer0_counter == 800)
        {
            LED_vidOn(LED_0);
            gu16_timer0_counter=0;
        }
        else
        {
            //do nothing
        }
        
        
        
    }
    
    
}

void ISR(void){
    gu16_timer0_counter++;
}

