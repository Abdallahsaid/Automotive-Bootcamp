/**********************************/
/* Author   : Abdalla Abdelhafiz  */
/* Date     : 5/1/2022            */
/* Version  : V01                 */
/**********************************/
#ifndef LED_H_
#define LED_H_

/* Description: Enum to hold configured leds */
typedef enum
{
    LED_0,
    LED_1,
    LED_2,
    LED_3

} LED_Num_t;

void LED_vidInit(LED_Num_t led);
void LED_vidOn(LED_Num_t led);
void LED_vidOff(LED_Num_t led);
void LED_vidToggle(LED_Num_t led);

#endif