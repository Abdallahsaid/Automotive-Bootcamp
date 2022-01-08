/**********************************/
/* Author   : Abdalla Abdelhafiz  */
/* Date     : 5/1/2022            */
/* Version  : V01                 */
/**********************************/
#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include "../../02-MCAL/DIO/Dio.h"
#include "Button.h"
#include "ButtonConfig.h"

void BTN_vidInit(BTN_Num_t btn)
{
    switch (btn)
    {
    case BTN_0:
        DIO_vidSetPinDirection(BTN_0_PORT, BTN_0_PIN, INPUT);
        if (BTN_0_RESISTOR == BTN_PULL_UP_INTERNAL)
        {
            DIO_vidSetPinValue(BTN_0_PORT, BTN_0_PIN, STD_HIGH);
        }
        else
        {
            // do nothing
        }
        break;
    case BTN_1:
        DIO_vidSetPinDirection(BTN_1_PORT, BTN_1_PIN, INPUT);
        if (BTN_1_RESISTOR == BTN_PULL_UP_INTERNAL)
        {
            DIO_vidSetPinValue(BTN_1_PORT, BTN_1_PIN, STD_HIGH);
        }
        else
        {
            // do nothing
        }
        break;
    default:
        break;
    }
}

u8_t BTN_u8IsPressed(BTN_Num_t btn)
{   u16_t counter= 0;
    u8_t prev_status = 0;
    u8_t status = 1;

    switch (btn)
    {
    case BTN_0:
        while (1)
        {
            prev_status = DIO_u8ReadPinValue(BTN_0_PORT, BTN_0_PIN);
            while (counter < 40000)  //loop to perform a delay
            {
                counter++;    
            }
            status = DIO_u8ReadPinValue(BTN_0_PORT, BTN_0_PIN);
            
            if (status == prev_status)
            {
                break;
            }
        }
        
        if (BTN_0_RESISTOR == BTN_PULL_DOWN_EXT)
        {
            return status;
        }
        else if ((BTN_0_RESISTOR == BTN_PULL_UP_EXT) || (BTN_0_RESISTOR == BTN_PULL_UP_INTERNAL))
        {

            return (!status);
        }

        else
        {
            // do nothing
        }
        break;
    case BTN_1:
        while (1)
        {
            prev_status = DIO_u8ReadPinValue(BTN_1_PORT, BTN_1_PIN);
            while (counter < 40000)  //loop to perform a delay
            {
                counter++;    
            }
            status = DIO_u8ReadPinValue(BTN_1_PORT, BTN_1_PIN);
            
            if (status == prev_status)
            {
                break;
            }
        }
        if (BTN_1_RESISTOR == BTN_PULL_DOWN_EXT)
        {
            return status;
        }
        else if ((BTN_1_RESISTOR == BTN_PULL_UP_EXT) || (BTN_1_RESISTOR == BTN_PULL_UP_INTERNAL))
        {

            return (!status);
        }

        else
        {
            // do nothing
        }
        break;
    default:
        break;
    }
    return status;
}
