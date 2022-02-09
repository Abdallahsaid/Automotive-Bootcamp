/**********************************/
/* Author   : Abdalla Abdelhafiz  */
/* Date     : 16/1/2022           */
/* Version  : V01                 */
/**********************************/
#ifndef KEYBAD_H_
#define KEYBAD_H_

void Kbad_vidInit(void);
ERROR_STATUS_t Kbad_u8GetPressed(u8_t *pressed_key);

#endif /* KEYBAD_H_ */
