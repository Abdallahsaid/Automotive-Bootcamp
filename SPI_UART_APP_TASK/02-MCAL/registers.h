/*
 * registers.h
 *
 *  Created on: Aug 17, 2019
 *      Author: OWNER
 */
#ifndef REGISTERS_H_
#define REGISTERS_H_
/*
typedef union{
	struct{
		u8_t bit0:1;
		u8_t bit1:1;
		u8_t bit2:1;
		u8_t bit3:1;
		u8_t bit4:1;
		u8_t bit5:1;
		u8_t bit6:1;
		u8_t bit7:1;
	};
	u8_t byte;
}MyReg;
*/
//#define PORTB (*((volatile MyReg*)0x38))

#define PORTA    *((volatile u8_t*)0x3B)
#define DDRA     *((volatile u8_t*)0x3A)
#define PINA     *((volatile u8_t*)0x39)

#define PORTB    *((volatile u8_t*)0x38)
#define DDRB     *((volatile u8_t*)0x37)
#define PINB     *((volatile u8_t*)0x36)

#define PORTC    *((volatile u8_t*)0x35)
#define DDRC     *((volatile u8_t*)0x34)
#define PINC     *((volatile u8_t*)0x33)

#define PORTD    *((volatile u8_t*)0x32)
#define DDRD     *((volatile u8_t*)0x31)
#define PIND     *((volatile u8_t*)0x30)
  
#define SREG     *((volatile u8_t*)0x5f)
#define GICR     *((volatile u8_t*)0x5B)
#define MCUCR    *((volatile u8_t*)0x55)
#define TIMSK    *((volatile u8_t*)0x59)
#define TCCR0    *((volatile u8_t*)0x53)
#define TCNT0    *((volatile u8_t*)0x52)
#define OCR0     *((volatile u8_t*)0x5C)


#define TCCR1A   *((volatile u8_t*)0x4F)
#define TCCR1B   *((volatile u8_t*)0x4E)
#define ICR1     *((volatile u16_t*)0x46)
#define OCR1     *((volatile u16_t*)0x4A)
#define TIFR     *((volatile u8_t*)0x58)

#define ADMUX    *((volatile u8_t*)0x27)
#define ADCSRA   *((volatile u8_t*)0x26)
#define ADCR     *((volatile u16_t*)0x24)
 
#define UDR      *((volatile u8_t*)0x2C)
#define UCSRA    *((volatile u8_t*)0x2B)
#define UCSRB    *((volatile u8_t*)0x2A)
#define UCSRC    *((volatile u8_t*)0x40)
#define UBRRL    *((volatile u8_t*)0x29)
#define UBRRH    *((volatile u8_t*)0x40)

#define WDTCR    *((volatile u8_t*)0x41)
#define MCUCSR   *((volatile u8_t*)0x54)

#define SPDR     *((volatile u8_t*)0x2F)
#define SPSR     *((volatile u8_t*)0x2E)
#define SPCR     *((volatile u8_t*)0x2D)


#endif /* REGISTERS_H_ */
