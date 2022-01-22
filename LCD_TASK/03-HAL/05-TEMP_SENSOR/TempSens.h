/**********************************/
/* Author   : Abdalla Abdelhafiz  */
/* Date     : 19/1/2022           */
/* Version  : V01                 */
/**********************************/
#ifndef  TEMPSENS_H_
#define  TEMPSENS_H_

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
void TEMP_vidInit(void);
u8_t TEMP_u8GetTemp(u8_t* temperature);

#endif