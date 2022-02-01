#include "../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include "../02-MCAL/UART/UART.h"
#include "../02-MCAL/SPI/SPI.h"
#include "APP.h"

#define MESSAGE_MAX_LENGTH 255

static void delay(u16_t max);
u8_t compare(u8_t a[], u8_t b[]);
u16_t convert_string_toNum(u8_t str[]);

void APP_vidInit(void)
{
  USART_Init(UART_bps_9600);
  SPI_vidInit();
   delay(40000); // master
}

void APP_vidStart(void)
{
  u8_t u8arr_message[MESSAGE_MAX_LENGTH];

  while (1)
  {

    UART_vidGetStr(u8arr_message);
    UART_vidSendStr(u8arr_message);          //master
    UART_vidSendStr("\r\n");
    SPI_vidSendStr(u8arr_message);
/*
    SPI_vidGetStr(u8arr_message);
    UART_vidSendStr(u8arr_message);        //slave
    UART_vidSendStr("\r\n");*/
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

u16_t convert_string_toNum(u8_t str[])
{
  u16_t result = 0;
  u8_t index = 0;
  u8_t size = 0;
  u8_t digit = 0;
  while (str[size] != '\0' && str[size] != '\n' && str[size] != '\r')
  {
    size++;
  }
  for (index = 0; index < size; index++)
  {
    result *= 10;
    digit = str[index] - '0';
    result = result + digit;
  }

  return result;
}
