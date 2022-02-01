#include "../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include "../03-HAL/EEPROM/EEPROM.h"
#include "../02-MCAL/UART/UART.h"
#include "APP.h"

static void delay(u16_t max);
u8_t compare(u8_t a[], u8_t b[]);
u16_t convert_string_toNum(u8_t str[]);

void APP_vidInit(void)
{

  USART_Init(UART_bps_9600);
  EEPROM_init();
}

void APP_vidStart(void)
{
  u8_t u8arr_str[72];
  u16_t u16_eeprom_adress;
  u8_t u8_data;
  while (1)
  {
    // GETTING THE COMMAND
    UART_vidSendStr("Enter A Command: ");
    UART_vidGetStr(u8arr_str);
    UART_vidSendStr(u8arr_str);
    UART_vidSendStr("\r\n"); // new line
    // COMMAND CHECKING
    if (compare(u8arr_str, "WRITE") == STD_LOW) // IF COMAND IS "WRITE" ENTERED
    {
      UART_vidSendStr("ENTER EEPROM ADDRESS: "); // GET EEPROM ADDRESS
      UART_vidGetStr(u8arr_str);
      UART_vidSendStr(u8arr_str);
      UART_vidSendStr("\r\n");                             // new line
      u16_eeprom_adress = convert_string_toNum(u8arr_str); // CONVERT STRING TO NUMERICAL VALUE
      UART_vidSendStr("OK");
      UART_vidSendStr("\r\n"); // new line

      UART_vidSendStr("ENTER DATA: ");
      u8_data = UART_u8RecieveChar();  // GETTING A DATA BYTE
      UART_vidSendChar(u8_data);
      UART_vidSendStr("\r\n"); // new line
      UART_vidSendStr("OK");
      UART_vidSendStr("\r\n"); // new line
      EEPROM_write_byte(u16_eeprom_adress, u8_data); // SAVING THE DATA TO THE EEPROM ADDRESS
      delay(15000);
    }
    else if (compare(u8arr_str, "READ") == STD_LOW) // IF COMMAND IS "READ" ENTERED
    {
      UART_vidSendStr("ENTER EEPROM ADDRESS: "); // GET EEPROM ADDRESS
      UART_vidGetStr(u8arr_str);
      UART_vidSendStr(u8arr_str);
      UART_vidSendStr("\r\n");                             // new line
      u16_eeprom_adress = convert_string_toNum(u8arr_str); // CONVERT STRING TO NUMERICAL VALUE

      UART_vidSendStr("OK");
      UART_vidSendStr("\r\n"); // new line

      UART_vidSendStr("DATA LOADDED IS: ");
      u8_data = EEPROM_read_byte(u16_eeprom_adress); //LOADING THE DATA TO THE EEPROM ADDRESS
      UART_vidSendChar(u8_data);
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
