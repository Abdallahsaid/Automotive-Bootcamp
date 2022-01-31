#include "../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include "../03-HAL/01-LED/Led.h"
#include "../02-MCAL/UART/UART.h"
#include "APP.h"

static void delay(u16_t max);
u8_t compare(u8_t a[], u8_t b[]);

void APP_vidInit(void)
{

  USART_Init(UART_bps_9600);
  LED_vidInit(LED_0);
  LED_vidInit(LED_1);
  LED_vidInit(LED_2);
  LED_vidInit(LED_3);
}

void APP_vidStart(void)
{
  u8_t u8arr_command[72];

  while (1)
  {
    UART_vidSendStr("Enter A Command: ");
    UART_vidGetStr(u8arr_command);
    UART_vidSendStr(u8arr_command);
    UART_vidSendStr("\r\n"); // new line
    if (compare(u8arr_command, "START") == STD_LOW)
    {
      UART_vidSendStr("Green LED is on ");
      UART_vidSendStr("\r\n"); // new line
      LED_vidOn(LED_0);
      LED_vidOff(LED_1);
      LED_vidOff(LED_2);
      LED_vidOff(LED_3);
    }
    else if (compare(u8arr_command, "WAIT") == STD_LOW)
    {
      UART_vidSendStr("Yellow LED is on ");
      UART_vidSendStr("\r\n"); // new line
      LED_vidOn(LED_1);
      LED_vidOff(LED_0);
      LED_vidOff(LED_2);
      LED_vidOff(LED_3);
    }
    else if (compare(u8arr_command, "STOP") == STD_LOW)
    {
      UART_vidSendStr("Red LED is on ");
      UART_vidSendStr("\r\n"); // new line
      LED_vidOn(LED_2);
      LED_vidOff(LED_0);
      LED_vidOff(LED_1);
      LED_vidOff(LED_3);
    }
    else if (compare(u8arr_command, "AT") == STD_LOW)
    {
      UART_vidSendStr("OK");
      UART_vidSendStr("\r\n"); // new line
    }
else
{
  // do nothing
}

  }
}

//*******  Private Functions ********
static void delay(u16_t max)
{
  u16_t counter = 0;
  while (counter < max) // loop to perform a delay
  {
    counter++;
  }
}

// Comparing both the strings.
u8_t compare(u8_t a[], u8_t b[])
{
  u8_t flag = 0, index = 0;                    // integer variables declaration
  while (a[index] != '\0' && b[index] != '\0') // while loop
  {
    if (a[index] != b[index])
    {
      flag = 1;
      break;
    }
    index++;
  }
  if (flag == 0)
    return STD_LOW;
  else
    return STD_HIGH;
}
