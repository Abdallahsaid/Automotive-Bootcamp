/**********************************/
/* Author   : Abdalla Abdelhafiz  */
/* Date     : 27/1/2022           */
/* Version  : V01                 */
/**********************************/
#ifndef I2C_H_
#define I2C_H_

void I2C_init_master(void);   //intialize as master
void I2C_init_slave(void);    //intialize as slave
void I2C_start(void);         //send start bit ti take control of the bus
void I2C_repeated_start(void);//send repeated start 
void I2C_send_slave_address_with_write_req(u8_t slave_address);//sending the slave address with write req
void I2C_send_slave_address_with_read_req(u8_t slave_address); //sending the slave adresss with read req
void I2C_write_byte(u8_t byte);       //sending a data byte through the bus
u8_t I2C_read_byte_NACK(void);        //master reads a data byte and reply with not ack
u8_t I2C_read_byte_ACK(void);         //master reads a data byte and reply with ack
void I2C_stop(void);                  //sends stop bit
void I2C_slave_check_slave_address_received_with_write_req(void); //slave checking the recieved address with write req
void I2C_slave_check_slave_address_received_with_read_req(void);  //slave checking the recieved address with read req
u8_t I2C_slave_read_byte(void);       //slave reads byte and reply with ack
void I2C_slave_write_byte(u8_t byte);//slave send data byte through the bus


#endif
