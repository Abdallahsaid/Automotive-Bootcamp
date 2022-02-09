/**********************************/
/* Author   : Abdalla Abdelhafiz  */
/* Date     : 5/1/2022            */
/* Version  : V01                 */
/**********************************/
#include"../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include"../../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include"../registers.h"
#include"Dio.h"

void DIO_vidSetPortDirection (DIO_Port_t port,u8_t value){
    switch (port){
	case DIO_PORTA: DDRA=value;
	break;
	case DIO_PORTB: DDRB=value;
	break;
	case DIO_PORTC: DDRC=value;
	break;
	case DIO_PORTD: DDRD=value;
	break;
	}
}
void DIO_vidSetPortValue     (DIO_Port_t port,u8_t value){
    switch (port){
	case DIO_PORTA: PORTA=value;
	break;
	case DIO_PORTB: PORTB=value;
	break;
	case DIO_PORTC: PORTC=value;
	break;
	case DIO_PORTD: PORTD=value;
	break;
	}
}
u8_t DIO_u8ReadPortValue     (DIO_Port_t port){
    volatile u8_t value;
	switch (port){
	case DIO_PORTA: value=PINA;
	break;
	case DIO_PORTB: value=PINB;
	break;
	case DIO_PORTC: value=PINC;
	break;
	case DIO_PORTD: value=PIND;
	break;

	}
return value;
}

void DIO_vidSetPinDirection (DIO_Port_t port, DIO_Pin_t pin, DIO_PinDirection_t value){
    switch (port)
    {
    case DIO_PORTA:
        if (value == OUTPUT)
            SET_BIT(DDRA, pin);
        else if (value == INPUT)
            CLR_BIT(DDRA, pin);
        break;
    case DIO_PORTB:
        if (value == OUTPUT)
            SET_BIT(DDRB, pin);
        else if (value == INPUT)
            CLR_BIT(DDRB, pin);
        break;
    case DIO_PORTC:
        if (value == OUTPUT)
            SET_BIT(DDRC, pin);
        else if (value == INPUT)
            CLR_BIT(DDRC, pin);
        break;
    case DIO_PORTD:
        if (value == OUTPUT)
            SET_BIT(DDRD, pin);
        else if (value == INPUT)
            CLR_BIT(DDRD, pin);
        break;
    }
}
void DIO_vidSetPinValue     (DIO_Port_t port,DIO_Pin_t pin,u8_t value){
    switch(port){
		case DIO_PORTA:
        if (value == STD_HIGH)
            SET_BIT(PORTA, pin);
        else if (value == STD_LOW)
        	CLR_BIT(PORTA, pin);
        break;
    case DIO_PORTB:
        if (value == STD_HIGH)
            SET_BIT(PORTB, pin);
        else if (value == STD_LOW)
            CLR_BIT(PORTB, pin);
        break;
    case DIO_PORTC:
        if (value == STD_HIGH)
            SET_BIT(PORTC, pin);
        else if (value == STD_LOW)
            CLR_BIT(PORTC, pin);
        break;
    case DIO_PORTD:
        if (value == STD_HIGH)
            SET_BIT(PORTD, pin);
        else if (value == STD_LOW)
            CLR_BIT(PORTD, pin);
        break;

		}
}
u8_t DIO_u8ReadPinValue     (DIO_Port_t port,DIO_Pin_t pin){
    volatile u8_t value;
	switch(port){
	case DIO_PORTA: value= GET_BIT(PINA,pin);
	break;
	case DIO_PORTB: value= GET_BIT(PINB,pin);
		break;
	case DIO_PORTC: value= GET_BIT(PINC,pin);
		break;
	case DIO_PORTD: value= GET_BIT(PIND,pin);
		break;
	}
	return value;
}

void DIO_vidPinToggle(DIO_Port_t port,DIO_Pin_t pin){
    switch(port){
	case DIO_PORTA:  TOG_BIT(PORTA,pin);
	break;
	case DIO_PORTB:  TOG_BIT(PORTB,pin);
		break;
	case DIO_PORTC:  TOG_BIT(PORTC,pin);
		break;
	case DIO_PORTD:  TOG_BIT(PORTD,pin);
		break;
	}

}