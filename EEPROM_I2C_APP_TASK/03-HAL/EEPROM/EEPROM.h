/**********************************/
/* Author   : Abdalla Abdelhafiz  */
/* Date     : 27/1/2022           */
/* Version  : V01                 */
/**********************************/
#ifndef EEPROM_H_
#define EEPROM_H_


void EEPROM_init(void);
void EEPROM_write_byte (u16_t address, u8_t data);
u8_t EEPROM_read_byte  (u16_t address);
void EEPROM_write_bytes(u16_t address, const u8_t *data, u8_t byte_count);
void EEPROM_read_bytes (u16_t address, u8_t *return_var, u8_t byte_count);
#endif /* EEPROM_H_ */
