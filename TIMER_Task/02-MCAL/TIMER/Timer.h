#ifndef TIMER_H_
#define TIMER_H_




void TIMER_vidTimer0Init  (void); // initalize timer 0 configration
void TIMER_vidTimer0Start(u8_t intial_value);  // starts the timer with the intial required value
void TIMER_vidTimer0Stop  (void);              // stops the timer
u8_t TIMER_u8Timer0_OVFflag(void);             // function to get the ovf flag
u8_t TIMER_u8Timer0_CTCflag(void);             // function to get CTC flag
void TIMER_vidTimer0SetInitValue(u8_t intial_value);   // function that sets the intial value 

void SetCallBack_Timer0CTC(void(*func)(void));     // setting the callback function for CTC interrupt
void SetCallBack_Timer0OVF(void(*func)(void));     // setting the callback function for OVF interrupt

#endif
