/**********************************/
/* Author   : Abdalla Abdelhafiz  */
/* Date     : 16/1/2022           */
/* Version  : V01                 */
/**********************************/
#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include "../../02-MCAL/DIO/Dio.h"
#include "../../02-MCAL/TIMER/Timer.h"
#include "KeybadConfig.h"
#include "Keybad.h"

#define STATE_A 0
#define STATE_B 1

ERROR_STATUS_t keybad_u8GetButton(u8_t button, u8_t *key_isPressed);
static u8_t keybad_arr_state[9] = {STATE_A,
								   STATE_A,
								   STATE_A,
								   STATE_A,
								   STATE_A,
								   STATE_A,
								   STATE_A,
								   STATE_A,
								   STATE_A};

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

ERROR_STATUS_t Kbad_u8GetPressed(u8_t *pressed_key)
{
	ERROR_STATUS_t ret_value = E_NOK;
	u8_t button_num = 0;
	u8_t key_status = 0;

	for (button_num = 0; button_num < 9; button_num++)
	{
		ret_value = keybad_u8GetButton(button_num, &key_status);
		if (ret_value == E_OK)
		{
			if (key_status == TRUE)
			{
				*pressed_key = button_num;
				return E_OK;
			}
		}
		else
		{
			return E_NOK;
		}
	}
	*pressed_key = 9; // nothing is pressed
	return E_OK;
}

/************** PRIVATE FUNCTIONS *****************/

ERROR_STATUS_t keybad_u8GetButton(u8_t button, u8_t *key_isPressed)
{
	u8_t status = 0;
	u8_t expired = 0;
	u8_t value = 1;
	const u8_t RealCol[3] = {Kbad_C1, Kbad_C2, Kbad_C3};
	const u8_t RealRow[3] = {Kbad_R1, Kbad_R2, Kbad_R3};
	u8_t row = button / 3;
	u8_t col = button % 3;
	DIO_vidSetPinValue(Kbad_Port, Kbad_C1, STD_HIGH);
	DIO_vidSetPinValue(Kbad_Port, Kbad_C2, STD_HIGH);
	DIO_vidSetPinValue(Kbad_Port, Kbad_C3, STD_HIGH);

	DIO_vidSetPinValue(Kbad_Port, RealCol[col], STD_LOW);
	if (keybad_arr_state[button] == STATE_A)
	{
		value = DIO_u8ReadPinValue(Kbad_Port, RealRow[row]);
		if (value == 0)
		{
			if(TIMER_start(TIMER_1, 90) == E_NOK){
               return E_NOK ;
			}
			keybad_arr_state[button] = STATE_B;
			*key_isPressed = FALSE;
			return E_OK;
		}
		else
		{
			*key_isPressed = FALSE;
			return E_OK;
		}
	}
	else if (keybad_arr_state[button] == STATE_B)
	{
		TIMER_isExpired(TIMER_1, &expired);
		if (expired == TRUE)
		{
			value = DIO_u8ReadPinValue(Kbad_Port, RealRow[row]);
			if (value == 0)
			{
				keybad_arr_state[button] = STATE_A;
				*key_isPressed = TRUE;
				return E_OK;
			}
			else
			{
				keybad_arr_state[button] = STATE_A;
				*key_isPressed = FALSE;
				return E_OK;
			}
		}
		else
		{
			*key_isPressed = FALSE;
			return E_OK;
		}
	}
	else
	{
		return E_NOK;
	}
}
