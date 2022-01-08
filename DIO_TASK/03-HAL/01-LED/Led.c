/**********************************/
/* Author   : Abdalla Abdelhafiz  */
/* Date     : 5/1/2022            */
/* Version  : V01                 */
/**********************************/
#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include "../../02-MCAL/DIO/Dio.h"
#include "Led.h"
#include "LedConfig.h"

void LED_vidInit(LED_Num_t led)
{
    switch (led)
    {
    case LED_0:
        DIO_vidSetPinDirection(LED_0_PORT, LED_0_PIN, OUTPUT);
        break;
    case LED_1:
        DIO_vidSetPinDirection(LED_1_PORT, LED_1_PIN, OUTPUT);
        break;
    case LED_2:
        DIO_vidSetPinDirection(LED_2_PORT, LED_2_PIN, OUTPUT);
        break;
    case LED_3:
        DIO_vidSetPinDirection(LED_3_PORT, LED_3_PIN, OUTPUT);
        break;

    default:
        break;
    }
}
void LED_vidOn(LED_Num_t led)
{
    switch (led)
    {
    case LED_0:
        DIO_vidSetPinValue(LED_0_PORT, LED_0_PIN, STD_HIGH);
        break;
    case LED_1:
        DIO_vidSetPinValue(LED_1_PORT, LED_1_PIN, STD_HIGH);
        break;
    case LED_2:
        DIO_vidSetPinValue(LED_2_PORT, LED_2_PIN, STD_HIGH);
        break;
    case LED_3:
        DIO_vidSetPinValue(LED_3_PORT, LED_3_PIN, STD_HIGH);
        break;
    default:
        break;
    }
}

void LED_vidOff(LED_Num_t led)
{
    switch (led)
    {
    case LED_0:
        DIO_vidSetPinValue(LED_0_PORT, LED_0_PIN, STD_LOW);
        break;
    case LED_1:
        DIO_vidSetPinValue(LED_1_PORT, LED_1_PIN, STD_LOW);
        break;
    case LED_2:
        DIO_vidSetPinValue(LED_2_PORT, LED_2_PIN, STD_LOW);
        break;
    case LED_3:
        DIO_vidSetPinValue(LED_3_PORT, LED_3_PIN, STD_LOW);
        break;

    default:
        break;
    }
}
void LED_vidToggle(LED_Num_t led)
{
    switch (led)
    {
    case LED_0:
        DIO_vidPinToggle(LED_0_PORT, LED_0_PIN);
        break;
    case LED_1:
        DIO_vidPinToggle(LED_1_PORT, LED_1_PIN);
        break;
    case LED_2:
        DIO_vidPinToggle(LED_2_PORT, LED_2_PIN);
        break;
    case LED_3:
        DIO_vidPinToggle(LED_3_PORT, LED_3_PIN);
        break;
    default:
        break;
    }
}