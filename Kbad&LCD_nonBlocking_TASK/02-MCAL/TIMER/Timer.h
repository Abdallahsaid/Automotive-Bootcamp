#ifndef TIMER_H_
#define TIMER_H_


typedef enum
{
    E_NOK,
    E_OK
}ERROR_STATUS_t;

typedef enum
{
    TIMER_0,
    TIMER_1,
    TIMER_2
}TIMER_NUM_t;


void TIMER_vidTimer0Init  (void); // initalize timer 0 configration
void TIMER_vidTimer0Start(u8_t intial_value);  // starts the timer with the intial required value
void TIMER_vidTimer0Stop  (void);              // stops the timer
u8_t TIMER_u8Timer0_OVFflag(void);             // function to get the ovf flag
u8_t TIMER_u8Timer0_CTCflag(void);             // function to get CTC flag
void TIMER_vidTimer0SetInitValue(u8_t intial_value);   // function that sets the intial value 

void SetCallBack_Timer0CTC(void(*func)(void));     // setting the callback function for CTC interrupt
void SetCallBack_Timer0OVF(void(*func)(void));     // setting the callback function for OVF interrupt

ERROR_STATUS_t TIMER_init(TIMER_NUM_t timer);
ERROR_STATUS_t TIMER_start(TIMER_NUM_t timer, u16_t ms);
ERROR_STATUS_t TIMER_stop(TIMER_NUM_t timer);
ERROR_STATUS_t TIMER_isExpired(TIMER_NUM_t timer, u8_t *expired);




#endif
