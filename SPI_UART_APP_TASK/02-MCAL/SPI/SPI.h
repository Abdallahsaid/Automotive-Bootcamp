/**********************************/
/* Author   : Abdalla Abdelhafiz  */
/* Date     : 26/1/2022           */
/* Version  : V01                 */
/**********************************/
#ifndef SPI_H_
#define SPI_H_

void SPI_vidInit(void);
u8_t SPI_u8Transcieve(u8_t u8_data);
void SPI_vidSendStr(const u8_t u8arr_str[]);
void SPI_vidGetStr(u8_t u8arr_str[]);


#endif