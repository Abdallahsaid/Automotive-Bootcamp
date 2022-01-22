/**********************************/
/* Author   : Abdalla Abdelhafiz  */
/* Date     : 16/1/2022           */
/* Version  : V01                 */
/**********************************/
#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include "../../02-MCAL/DIO/Dio.h"
#include "KeybadConfig.h"
#include "Keybad.h"

// initalizing the the pins connected tos the keybad
void Kbad_vidInit(void)
{
	DIO_vidSetPinDirection(Kbad_Port, Kbad_C1, INPUT);
	DIO_vidSetPinDirection(Kbad_Port, Kbad_C2, INPUT);
	DIO_vidSetPinDirection(Kbad_Port, Kbad_C3, INPUT);

	DIO_vidSetPinValue(Kbad_Port, Kbad_C1, STD_HIGH);
	DIO_vidSetPinValue(Kbad_Port, Kbad_C2, STD_HIGH);
	DIO_vidSetPinValue(Kbad_Port, Kbad_C3, STD_HIGH);

	DIO_vidSetPinDirection(Kbad_Port, Kbad_R1, OUTPUT);
	DIO_vidSetPinDirection(Kbad_Port, Kbad_R2, OUTPUT);
	DIO_vidSetPinDirection(Kbad_Port, Kbad_R2, OUTPUT);
}

u8_t Kbad_u8GetPressed(void)
{
	u8_t button_num = 0;
	const u8_t RealCol[3] = {Kbad_C1, Kbad_C2, Kbad_C3};
	const u8_t RealRow[3] = {Kbad_R1, Kbad_R2, Kbad_R3};
	u8_t row = 0;
	u8_t col = 0;
	u16_t counter = 0;

	DIO_vidSetPinValue(Kbad_Port, Kbad_R1, STD_HIGH);
	DIO_vidSetPinValue(Kbad_Port, Kbad_R2, STD_HIGH);
	DIO_vidSetPinValue(Kbad_Port, Kbad_R3, STD_HIGH);

	for (button_num = 0; button_num < 9; button_num++)
	{
		counter = 0;
		row = button_num / 3;
		col = button_num % 3;
		DIO_vidSetPinValue(Kbad_Port, RealRow[row], STD_LOW);
		if (DIO_u8ReadPinValue(Kbad_Port, RealCol[col]) == STD_LOW)
		{
			while (counter < 45000) // loop to perform a delay
			{
				counter++;
			}
			if (DIO_u8ReadPinValue(Kbad_Port, RealCol[col]) == STD_LOW)
			{
				if      (row == 0 && col == 0)
				{
					return 0;
				}
				else if (row == 0 && col == 1)
				{
					return 1;
				}
				else if (row == 0 && col == 2)
				{
					return 2;
				}
				else if (row == 1 && col == 0)
				{
					return 3;
				}
				else if (row == 1 && col == 1)
				{
					return 4;
				}
				else if (row == 1 && col == 2)
				{
					return 5;
				}
				else if (row == 2 && col == 0)
				{
					return 6;
				}
				else if (row == 2 && col == 1)
				{
					return 7;
				}
				else if (row == 2 && col == 2)
				{
					return 8;
				}
				else 
				{
					/* code */
				}
				
				
			
			}
		}
		DIO_vidSetPinValue(Kbad_Port, RealRow[row], STD_HIGH);
	}
	return 9; // nothing is pressed
}
