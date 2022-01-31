#include "../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include "../03-HAL/01-LED/Led.h"
#include "../02-MCAL/UART/UART.h"
#include "APP.h"

static void delay(u16_t max);

void APP_vidInit(void)
{
    
    USART_Init(UART_bps_9600);

}

void APP_vidStart(void)
{
    u8_t Str[72];
    UART_vidSendStr("Enter A String: ");

    while (1)
    {
      UART_vidGetStr(Str);
      UART_vidSendStr("\r\n");
      UART_vidSendStr("The String Recieved is : ");
      UART_vidSendStr(Str);
      UART_vidSendStr("\r\n");
      UART_vidSendStr("Enter A String:\r\n");
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
