/**********************************/
/* Author   : Abdalla Abdelhafiz  */
/* Date     : 19/1/2022           */
/* Version  : V01                 */
/**********************************/
#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include "../../02-MCAL/ADC/ADC.h"


void TEMP_vidInit(void){
    ADC_Init();
}
u8_t TEMP_u8GetTemp(u8_t* temperature){
    
    u16_t return_result;
    if (ADC_GetResult(&return_result))
    {
        *temperature =(u8_t) ((return_result)/4);
        return 1;
    }
    else{
        //do nothing
    }
    return 0; 
}