#include "../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include "../02-MCAL/TIMER/Timer.h"
#include "../03-HAL/01-LED/Led.h"
#include "../03-HAL/04-LCD/LCD.h"
#include "../03-HAL/03-KEYBAD/Keybad.h"
#include "../02-MCAL/registers.h"
#include "APP.h"

static void delay(u16_t max);
u8_t compare(u8_t a[], u8_t b[]);
u16_t convert_string_toNum(u8_t str[]);

void APP_vidInit(void)
{
  TIMER_init(TIMER_1);
  LED_vidInit(LED_0);
  Kbad_vidInit();
  SET_BIT(SREG, 7);
}

void APP_vidStart(void)
{
  u8_t key = 9;
  u8_t status;

  while (1)
  {
    LCD_vidInit();
    status = Kbad_u8GetPressed(&key);
    if ((status == E_OK) && (key < 9))
    {
      LCD_vidWriteNumber(key);
      LED_vidToggle(LED_0);
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
