/**********************************/
/* Author   : Abdalla Abdelhafiz  */
/* Date     : 26/1/2022           */
/* Version  : V01                 */
/**********************************/
#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include "../registers.h"
#include "../DIO/Dio.h"
#include "SPI.h"
#include "SPIconfig.h"
#include "SPI_private.h"

static void delay(u16_t max);
void SPI_vidInit(void)
{
#if (SPI_MODE == SPI_MASTER)
    DIO_vidSetPinDirection(DIO_PORTB, DIO_PIN5, OUTPUT); // MOSI
    DIO_vidSetPinDirection(DIO_PORTB, DIO_PIN6, INPUT);  // MISO
    DIO_vidSetPinDirection(DIO_PORTB, DIO_PIN4, OUTPUT); // SS
    DIO_vidSetPinDirection(DIO_PORTB, DIO_PIN7, OUTPUT); // SCK
    DIO_vidSetPinValue(DIO_PORTB, DIO_PIN4,STD_LOW);//SS
    // SETTING THE MASTER BIT
    SET_BIT(SPCR, MSTR);
    // freq Fosc/4
    CLR_BIT(SPCR, SPR1);
    CLR_BIT(SPCR, SPR1);

#elif (SPI_MODE == SPI_SLAVE)
    DIO_vidSetPinDirection(DIO_PORTB, DIO_PIN5, INPUT);  // MOSI
    DIO_vidSetPinDirection(DIO_PORTB, DIO_PIN6, OUTPUT); // MISO
    DIO_vidSetPinDirection(DIO_PORTB, DIO_PIN4, INPUT); // SS
    DIO_vidSetPinDirection(DIO_PORTB, DIO_PIN7, INPUT);  // SCK

    // CLEARING THE MASTER BIT
    CLR_BIT(SPCR, MSTR);
#endif
    // CHOOSING DATA ORDER
#if (SPI_DATA_ORDER == LSB)
    CLR_BIT(SPCR, DORD);
#elif (SPI_DATA_ORDER == MSB)
    SET_BIT(SPCR, DORD);
#endif
    // LEADING EDGE FALLING
    SET_BIT(SPCR, CPOL);
    // Clock Phase SETUP
    SET_BIT(SPCR, CPHA);
    //disable speed doubler
    CLR_BIT(SPSR,SPI2X);
    // SPI ENABLE
    SET_BIT(SPCR, SPE);
}

u8_t SPI_u8Transcieve(u8_t u8_data)
{   
    #if (SPI_MODE == SPI_MASTER)
    
    //LOADING THE DATA INTO SPI DATA REG
    SPDR = u8_data;
    //waiting till transaction is done
    while ((GET_BIT(SPSR, SPIF)) == STD_LOW)
    {
    }
    return SPDR;
    #elif (SPI_MODE == SPI_SLAVE)
    u8_t u8_recieved;
    //waiting till transaction is done
    while ((GET_BIT(SPSR, SPIF)) == STD_LOW)
    {
    }
    //storing the recieved value
    u8_recieved = SPDR;
    //LOADING THE DATA INTO SPI DATA REG
    SPDR = u8_data;
    return u8_recieved;
    #endif
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
