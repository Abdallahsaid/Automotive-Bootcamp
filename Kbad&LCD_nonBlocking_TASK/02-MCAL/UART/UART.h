/**********************************/
/* Author   : Abdalla Abdelhafiz  */
/* Date     : 24/1/2022            */
/* Version  : V01                 */
/**********************************/
#ifndef UART_H_
#define UART_H_

//8MHZ Baud Rate options
//possible baud rates choose one of them as input to the intialize function
#define UART_bps_2400   207
#define UART_bps_4800   103
#define UART_bps_9600   51
#define UART_bps_14400  34
#define UART_bps_19200  25
#define UART_bps_38400  12
#define UART_bps_250K   1
#define UART_bps_500K   0


void USART_Init(u16_t baud);
void UART_vidSendChar(u8_t u8_data);
u8_t UART_u8RecieveChar(void);
void USART_Flush(void);
void UART_vidSendStr(const u8_t *Str);
void UART_vidGetStr(u8_t *string);



#endif