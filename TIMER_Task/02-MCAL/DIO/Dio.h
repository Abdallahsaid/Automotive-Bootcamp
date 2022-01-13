/**********************************/
/* Author   : Abdalla Abdelhafiz  */
/* Date     : 5/1/2022            */
/* Version  : V01                 */
/**********************************/
#ifndef DIO_H_
#define DIO_H_


/* Description: Enum to hold the port possible values */
typedef enum
{
   DIO_PORTA,
   DIO_PORTB,
   DIO_PORTC,
   DIO_PORTD
   
}DIO_Port_t;

/* Description: Enum to hold the PIN possible values */
typedef enum
{
    DIO_PIN0,
    DIO_PIN1,
    DIO_PIN2,
    DIO_PIN3,
    DIO_PIN4,
    DIO_PIN5,
    DIO_PIN6,
    DIO_PIN7
}DIO_Pin_t;

/* Description: Enum to hold PIN direction */
typedef enum
{
    INPUT,OUTPUT
}DIO_PinDirection_t;


void DIO_vidSetPortDirection (DIO_Port_t port,u8_t value);
void DIO_vidSetPortValue     (DIO_Port_t port,u8_t value);
u8_t DIO_u8ReadPortValue     (DIO_Port_t port);

void DIO_vidSetPinDirection (DIO_Port_t port,DIO_Pin_t pin,DIO_PinDirection_t value);
void DIO_vidSetPinValue     (DIO_Port_t port,DIO_Pin_t pin,u8_t value);
u8_t DIO_u8ReadPinValue     (DIO_Port_t port,DIO_Pin_t pin);

void DIO_vidPinToggle(DIO_Port_t port,DIO_Pin_t pin);

#endif /* DIO_H_ */