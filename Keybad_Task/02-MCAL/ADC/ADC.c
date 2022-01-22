/**********************************/
/* Author   : Abdalla Abdelhafiz  */
/* Date     : 18/1/2022           */
/* Version  : V01                 */
/**********************************/
#include"../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include"../../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include"../registers.h"

void ADC_Init(void){
	ADMUX =0b11000000;
	ADCSRA=0b10000111;
	SET_BIT(ADCSRA,6);

}
//max=1023
u8_t ADC_GetResult(u16_t* result){
	u8_t status=0;
	if(GET_BIT(ADCSRA,4)==1){
		*result = ADCR&(0b0000001111111111);
		SET_BIT(ADCSRA,4);
		SET_BIT(ADCSRA,6);
		status=1;
	}
	else
		status=0;
	return status;
}

