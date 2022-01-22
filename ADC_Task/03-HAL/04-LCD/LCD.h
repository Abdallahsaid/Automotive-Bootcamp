/**********************************/
/* Author   : Abdalla Abdelhafiz  */
/* Date     : 18/1/2022           */
/* Version  : V01                 */
/**********************************/
#ifndef LCD_H_
#define LCD_H_

#define LCD_MODULE_ID    (120U)   /* LCD Module Id                     */

/*
 * Macros for LCD DRIVER Status
 */
#define LCD_INITIALIZED                (1U)
#define LCD_NOT_INITIALIZED            (0U)

/******************************************************************************/
/*                          API Service Id Macros                             */
/******************************************************************************/

#define LCD_INIT_SID                    (u8_t)0x00
#define LCD_WRITE_COMMAND_SID           (u8_t)0x01
#define LCD_WRITE_DATA_SID              (u8_t)0x02
#define LCD_WRITE_STRING_SID        	(u8_t)0x03
#define LCD_WRITE_NUMBER_SID            (u8_t)0x04
#define LCD_SET_POSTION_SID             (u8_t)0x05
#define LCD_CLEAR_SID                   (u8_t)0x06


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
void LCD_vidInit(void);
void LCD_vidWriteCommand(u8_t command);
void LCD_vidWriteData(u8_t data);
void LCD_vidWriteString(u8_t*string);
void LCD_vidWriteNumber(u32_t num);
void LCD_vidSetPosition(u8_t row,u8_t col);
void LCD_vidClear(void);

#endif /* LCD_H_ */
