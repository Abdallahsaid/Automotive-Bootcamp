#include "../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include "../02-MCAL/I2C/I2C.h"
#include "../02-MCAL/DIO/Dio.h"
#include "APP.h"

static void delay(u16_t max);

void APP_vidInit(void)
{
   I2C_init_master();
  // I2C_init_slave
  // DIO_vidSetPortDirection(DIO_PORTA, 0xff);
    
}

void APP_vidStart(void)
{
	//u8_t recieved = 0;
 // I2C_slave_check_slave_address_received_with_write_req();
  //recieved = I2C_slave_read_byte();
 // DIO_vidSetPortValue(DIO_PORTA , recieved);
  I2C_start();
  I2C_send_slave_address_with_write_req(0x01);
  I2C_write_byte(0x55);
  I2C_stop();
   while(1){



   }
  
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
/*
 //master app
   while (1)
   {
     SPI_u8Transcieve('A'); //0b01000001
     delay(50000);
   }

	 /*
	//slave app
		 u8_t u8_recieved=0;

	  while (1)
	  {
		  u8_recieved = SPI_u8Transcieve(0);
		  DIO_vidSetPortValue(DIO_PORTA ,u8_recieved );
	  }

*/
