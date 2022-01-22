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

u8_t keybad_u8GetButton(u8_t button);

// initalizing the the pins connected tos the keybad
void Kbad_vidInit(void)
{
	DIO_vidSetPinDirection(Kbad_Port, Kbad_R1, INPUT);
	DIO_vidSetPinDirection(Kbad_Port, Kbad_R2, INPUT);
	DIO_vidSetPinDirection(Kbad_Port, Kbad_R3, INPUT);

	DIO_vidSetPinValue(Kbad_Port, Kbad_R1, STD_HIGH);
	DIO_vidSetPinValue(Kbad_Port, Kbad_R2, STD_HIGH);
	DIO_vidSetPinValue(Kbad_Port, Kbad_R3, STD_HIGH);

	DIO_vidSetPinDirection(Kbad_Port, Kbad_C1, OUTPUT);
	DIO_vidSetPinDirection(Kbad_Port, Kbad_C2, OUTPUT);
	DIO_vidSetPinDirection(Kbad_Port, Kbad_C3, OUTPUT);
}

u8_t Kbad_u8GetPressed(void)
{
	u8_t button_num = 0;

	for ( button_num = 0; button_num < 9; button_num++)
	{
		if(keybad_u8GetButton(button_num) == 1){
			return button_num;
		}

	}
	
	return 9; // nothing is pressed
}


/************** PRIVATE FUNCTIONS *****************/

u8_t keybad_u8GetButton(u8_t button)
{
	u8_t status = 0;
	u16_t counter = 0;
	u8_t value = 1;
	const u8_t RealCol[3] = {Kbad_C1, Kbad_C2, Kbad_C3};
	const u8_t RealRow[3] = {Kbad_R1, Kbad_R2, Kbad_R3};
	u8_t row = button / 3;
	u8_t col = button % 3;
	DIO_vidSetPinValue(Kbad_Port, Kbad_C1, STD_HIGH);
	DIO_vidSetPinValue(Kbad_Port, Kbad_C2, STD_HIGH);
	DIO_vidSetPinValue(Kbad_Port, Kbad_C3, STD_HIGH);

	DIO_vidSetPinValue(Kbad_Port, RealCol[col], STD_LOW);
	value = DIO_u8ReadPinValue(Kbad_Port, RealRow[row]);
	if (value == 0)
	{
		while (counter < 45000)  //loop to perform a delay
		            {
		                counter++;
		            }
		value = DIO_u8ReadPinValue(Kbad_Port, RealRow[row]);
		if (value == 0)
		{
			status = 1;
		}
	}
	return status;
}
