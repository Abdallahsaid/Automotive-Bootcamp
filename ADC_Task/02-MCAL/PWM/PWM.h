#ifndef PWM_H_
#define PWM_H_


void PWM_vidInit(void);   // call this function to intialize the driver before starting the pwm
void PWM_vidstart(void);  // this function must be set as a the callback for timer interupt to start generating pwm on the configured pins
void PWM_SetDutyCycle(u8_t dutyc);   // setting the duty cycle you can call it anytime after starting the pwm generation to modify the dutycycle

#endif