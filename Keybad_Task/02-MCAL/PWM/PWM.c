#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include "../TIMER/Timer.h"
#include "../DIO/Dio.h"
#include "PWM.h"
#include "PWMconfig.h"


static u8_t PWM_timer_count = 0;
static u8_t PWM_dutyCycle=0;

void PWM_vidInit(void){
    TIMER_vidTimer0Init();
    DIO_vidSetPinDirection(PWM_PORT1 , PWM_PIN1 , OUTPUT );
    DIO_vidSetPinDirection(PWM_PORT2 , PWM_PIN2 , OUTPUT );
   // DIO_vidSetPinDirection(PWM_PORT3 , PWM_PIN3 , OUTPUT );
    TIMER_vidTimer0Start(PWM_INTIAL_VALUE);
}

// the callback function when the timer overflow 
void PWM_vidstart(void)
{
    TIMER_vidTimer0SetInitValue(PWM_INTIAL_VALUE);
    PWM_timer_count++;
    if (PWM_timer_count == PWM_dutyCycle)
    {
        DIO_vidSetPinValue(PWM_PORT1 , PWM_PIN1 , STD_LOW);
        DIO_vidSetPinValue(PWM_PORT2 , PWM_PIN2 , STD_LOW);
       // DIO_vidSetPinValue(PWM_PORT3 , PWM_PIN3 , STD_LOW);
        
    }
    else if(PWM_timer_count >= 100)
    {
        PWM_timer_count = 0;
        DIO_vidSetPinValue(PWM_PORT1 , PWM_PIN1 , STD_HIGH);
        DIO_vidSetPinValue(PWM_PORT2 , PWM_PIN2 , STD_HIGH);
       // DIO_vidSetPinValue(PWM_PORT3 , PWM_PIN3 , STD_HIGH);
        
    }
    else
    {
        // do nothing
    }
}

//function to change dutycycle
void PWM_SetDutyCycle(u8_t dutyc){
    PWM_dutyCycle = dutyc;
}
