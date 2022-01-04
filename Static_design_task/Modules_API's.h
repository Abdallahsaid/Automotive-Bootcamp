/************************
  MODULE : Application
************************/
u8_t APP_intialization(void);
u8_t APP_start(void);


/********************
  MODULE : BUTTONS   
********************/
u8_t BTN_intialize(BTN_t button);
u8_t BTN_isPressed(BTN_t button);
u8_t BTN_button1_action(void);
u8_t BTN_button2_action(void);
u8_t BTN_button3_action(void);
u8_t BTN_button4_action(void);
/********************
  MODULE : MOTORS   
********************/
u8_t MTR_intialize(MTR_t motor);
u8_t MTR_ON(MTR_t motor ,MTRSpeed_t speed , MTRDirection_t );
/********************
  MODULE : DIO   
********************/
void DIO_vid_set_port_direction(DIOPort_t Port,DIODir_T direction);
void DIO_vidSetPortValue(DIOPort_t Port,u8 value);
u8 DIO_u8ReadPortValue(DIOPort_t Port);

void DIO_vidSetPinDirection(DIOPort_t Port ,DIOPin_t pin ,DIODir_T direction);
void DIO_vidSetPinValue(DIOPort_t Port ,DIOPin_t pin ,DIOValue_t value);
DIOValue_t DIO_u8ReadPinValue(DIOPort_t Port ,DIOPin_t pin);

/********************
  MODULE : TIMER   
********************/
u8_t TIMER_init(TIMER_t timer_num);
u8_t TIMER_start(TIMER_t timer_num , u8_t time_ms);
u8_t TIMER_stop(TIMER_t timer_num);
u8_t TIMER_status(TIMER_t timer_num);

/********************
  MODULE : PWM   
********************/

u8_t PWM_init(PWM_t channel);
u8_t PWM_on(PWM_t channel , u8_t duty_cycle, u8_t freq);
u8_t PWM_off(PWM_t channel)