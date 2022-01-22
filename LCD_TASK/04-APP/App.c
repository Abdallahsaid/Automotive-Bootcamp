#include "../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include "../03-HAL/01-LED/Led.h"
#include "../03-HAL/03-KEYBAD/Keybad.h"
#include "../03-HAL/04-LCD/LCD.h"
#include "../03-HAL/05-TEMP_SENSOR/TempSens.h"
#include "APP.h"

void APP_vidInit(void)
{
    LCD_vidInit();
    Kbad_vidInit();
}

void APP_vidStart(void)
{
   LCD_vidWriteString("Hello World!");
   LCD_vidSetPosition(1,5);
   LCD_vidWriteNumber(65000);
   while (1)
   {
       /* code */
   }
   
}
