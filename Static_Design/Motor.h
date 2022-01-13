#ifndef MOTOR_H_
#define MOTOR_H_

void MOTOR_vidInit(void);
void MOTOR_vidON(MOTOR_t motornum);
void MOTOR_vidOFF(MOTOR_t motornum);
void MOTOR_vidSetSpeed(MOTOR_t motornum , u8_t speed);


#endif