/**********************************/
/* Author   : Abdalla Abdelhafiz  */
/* Date     : 27/1/2022           */
/* Version  : V01                 */
/**********************************/
#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../02-MCAL/I2C/I2C.h"
#include "eeprom.h"

#define EEPROM_ADDRESS 0b01010000

void EEPROM_init(void)
{
	I2C_init_master();
}
//WRITE 1 BYTE
void EEPROM_write_byte(u16_t address, u8_t data)
{
	I2C_start();										   // START BIT
	I2C_send_slave_address_with_write_req(EEPROM_ADDRESS); // SENDING ADDRESS WITH WRITE REQ
	I2C_write_byte((address >> 8));						   // SENDING MSBs OF THE ADDRESS
	I2C_write_byte((u8_t)address);						   // SENDING LSBs OF THE ADDRESS
	I2C_write_byte(data);								   // SENDING DATA
	I2C_stop();											   // STOP BIT
}
//READ 1 BYTE
u8_t EEPROM_read_byte(u16_t address)
{
	u8_t data;
	I2C_start();										   // START BIT
	I2C_send_slave_address_with_write_req(EEPROM_ADDRESS); // SENDING ADDRESS WITH WRITE REQ
	I2C_write_byte((address >> 8));						   // SENDING MSBs OF THE ADDRESS
	I2C_write_byte((u8_t)address);						   // SENDING LSBs OF THE ADDRESS
	I2C_repeated_start();								   // REPEATED START BIT
	I2C_send_slave_address_with_read_req(EEPROM_ADDRESS);  // SENDING ADDRESS WITH READ REQ
	data = I2C_read_byte_NACK();						   // READING DATA AND REPLYING WITH NACK
	I2C_stop();											   // STOP BIT
	return data;
}
//PAGE WRITE
void EEPROM_write_bytes(u16_t address, const u8_t *data, u8_t byte_count)
{
	u8_t index = 0;
	I2C_start();										   // START BIT
	I2C_send_slave_address_with_write_req(EEPROM_ADDRESS); // SENDING ADDRESS WITH WRITE REQ
	I2C_write_byte((address >> 8));						   // SENDING MSBs OF THE ADDRESS
	I2C_write_byte((u8_t)address);						   // SENDING LSBs OF THE ADDRESS
	for (index = 0; index < byte_count; index++)
	{
		I2C_write_byte(data[index]); // SENDING DATA
	}
	I2C_stop(); // STOP BIT
}

//SEQENTIAL READ
void EEPROM_read_bytes(u16_t address, u8_t *return_var, u8_t byte_count)
{
	u8_t index = 0;
	I2C_start();										   // START BIT
	I2C_send_slave_address_with_write_req(EEPROM_ADDRESS); // SENDING ADDRESS WITH WRITE REQ
	I2C_write_byte((address >> 8));						   // SENDING MSBs OF THE ADDRESS
	I2C_write_byte((u8_t)address);						   // SENDING LSBs OF THE ADDRESS
	I2C_repeated_start();								   // REPEATED START BIT
	I2C_send_slave_address_with_read_req(EEPROM_ADDRESS);  // SENDING ADDRESS WITH READ REQ
	for (index = 0; index < (byte_count - 1); index++)
	{
		return_var[index] = I2C_read_byte_ACK(); // READING DATA AND REPLYING WITH ACK
	}
	return_var[index] = I2C_read_byte_NACK();               // READING DATA AND REPLYING WITH NACK
	I2C_stop();								                // STOP BIT
}
