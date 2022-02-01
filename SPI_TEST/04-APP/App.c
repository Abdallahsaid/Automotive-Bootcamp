#include "../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include "../02-MCAL/DIO/Dio.h" 
#include "../02-MCAL/SPI/SPI.h"
#include "APP.h"

static void delay(u16_t max);
u8_t compare(u8_t a[], u8_t b[]);
u16_t convert_string_toNum(u8_t str[]);

void APP_vidInit(void)
{

  SPI_vidInit();
  delay(40000); // master
 //DIO_vidSetPortDirection(DIO_PORTA,0xff); //slave
}

void APP_vidStart(void)
{
  SPI_u8Transcieve(0x55);  // master
  /*
  u8_t data=0;
  data = SPI_u8Transcieve(0);                // slave
  DIO_vidSetPortValue(DIO_PORTA,data);*/
  while (1)
  {
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
