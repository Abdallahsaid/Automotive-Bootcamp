/**********************************/
/* Author   : Abdalla Abdelhafiz  */
/* Date     : 24/1/2022           */
/* Version  : V01                 */
/**********************************/
#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include "../registers.h"
#include "UART.h"

#define RXC 7
#define UDRE 5

void USART_Init(u16_t baud)
{
    /* Set baud rate */
    UBRRH = (u8_t)(baud >> 8);
    UBRRL = (u8_t)baud;
    /* Enable receiver and transmitter */
    UCSRB = 0b00011000;

    // rising clock & 8-bit data & disabled parity & async op mode & 1-StopBit
    UCSRC = 0b10000110;
}

void UART_vidSendChar(u8_t u8_data)
{
    /* Wait for empty transmit buffer */
    while ((GET_BIT(UCSRA, UDRE)) == 0)
    {
    }
    /* Put data into buffer, sends the data */
    UDR = u8_data;
}
u8_t UART_u8RecieveChar(void)
{
    /* Wait for data to be received */
    while ((GET_BIT(UCSRA, RXC)) == 0)
    {
    }
    /* Get and return received data from buffer */
    return UDR;
}

void USART_Flush(void)
{
    u8_t u8_dummy = 0;
    /* flush data reg untill the flag is cleared */
    while (GET_BIT(UCSRA, RXC))
    {
        // read data reg
        u8_dummy = UDR;
    }
}

void UART_vidSendStr(const u8_t *Str)
{
    u8_t index = 0;
    while (Str[index])
    {
        /* Wait for empty transmit buffer */
        while ((GET_BIT(UCSRA, UDRE)) == 0);
        /* Put data into buffer, sends the data */
        UDR = Str[index];

        index++;
    }
}

void UART_vidGetStr(u8_t *string) // Receive a character until carriage return or newline
{
    u8_t index = 0, end = 0;
    do
    {
        /* Wait for data to be received */
        while ((GET_BIT(UCSRA, RXC)) == 0);
        /* Get and load received data from buffer into the string variable */
        string[index] = UDR;
        end = string[index];
        index++;
    } while ((end != '\n') && (end != '\r'));

    string[index] = '\0';
}