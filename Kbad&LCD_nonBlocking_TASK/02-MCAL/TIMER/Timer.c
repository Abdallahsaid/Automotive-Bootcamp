/**********************************/
/* Author   : Abdalla Abdelhafiz  */
/* Date     : 8/1/2022            */
/* Version  : V01                 */
/**********************************/
#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include "../registers.h"
#include "Timer.h"
#include "TimerConfig.h"

#define __INTR_ATTRS used, externally_visible

void static (*CallBack_Timer0CTC)(void) = NULL_PTR;
void static (*CallBack_Timer0OVF)(void) = NULL_PTR;

static u8_t gu8_intial_value = 0;

// global variable to count the number of overflows
volatile u16_t tot_overflow_T1 = 0;
static u16_t max_ovf_T1;
u8_t T1_done = FALSE;
u8_t T1_busy = FALSE;

void TIMER_vidTimer0Init(void)
{

    // setting waveform generation mode  ctc or normal
#if (TIMER_0_MODE == NORMAL)
    TCCR0 = 0;
    if (TIMER_0_OVF_INT == STD_ON)
    {
        TIMSK |= 1;
    }
    else
    {
        // do nothing
    }
#elif (TIMER_0_MODE == CTC)
    TCCR0 = 8;
    OCR0 = TIMER_0_COMPARE_VALUE; // setting the compare value
    if (TIMER_0_CTC_INT == STD_ON)
    {
        TIMSK |= 2;
    }
    else
    {
        // do nothing
    }
#endif
}

void TIMER_vidTimer0Start(u8_t intial_value)
{
    TIMER_vidTimer0SetInitValue(intial_value); // setting intial value
    TCCR0 |= TIMER_0_PRESCALER;                // setting the prescaler
}

void TIMER_vidTimer0Stop(void)
{
    TCCR0 &= ~(0b111); // clearing the prescaler bits
}

u8_t TIMER_u8Timer0_OVFflag(void)
{
    return GET_BIT(TIFR, 0);
}

u8_t TIMER_u8Timer0_CTCflag(void)
{
    return GET_BIT(TIFR, 1);
}

void TIMER_vidTimer0SetInitValue(u8_t intial_value)
{
    gu8_intial_value = intial_value;
    TCNT0 = gu8_intial_value;
}

ERROR_STATUS_t TIMER_init(TIMER_NUM_t timer)
{
    switch (timer)
    {
    case TIMER_0:
        /* code */
        return E_OK;
        break;
    case TIMER_1:
        TCCR1A = 0;
        // ctc mode
        TCCR1B = (1 << 3);
        // overflow value
        OCR1 = 1000;
        // enable compA interrupt
        SET_BIT(TIMSK, 4);
        return E_OK;
        break;
    case TIMER_2:
        /* code */
        return E_OK;

        break;

    default:
        return E_NOK;
        break;
    }
}

ERROR_STATUS_t TIMER_start(TIMER_NUM_t timer, u16_t ms)
{

    switch (timer)
    {
    case TIMER_0:
        /* code */
        return E_OK;
        break;
    case TIMER_1:
        if(T1_busy == TRUE){
            return E_NOK;
        }
        tot_overflow_T1 = 0;
        max_ovf_T1 = ms;
        T1_busy = TRUE;
        T1_done = FALSE;
        // set up timer with prescaler = 8
        SET_BIT(TCCR1B, 1);

        return E_OK;
        break;
    case TIMER_2:
        /* code */
        return E_OK;

        break;

    default:
        return E_NOK;
        break;
    }
}

ERROR_STATUS_t TIMER_stop(TIMER_NUM_t timer)
{
    switch (timer)
    {
    case TIMER_0:
        /* code */
        return E_OK;
        break;
    case TIMER_1:
        TCCR1B &= ~(0b111); // clock disable
        T1_busy = FALSE;
        return E_OK;
        break;
    case TIMER_2:
        /* code */
        return E_OK;

        break;

    default:
        return E_NOK;
        break;
    }
}

ERROR_STATUS_t TIMER_isExpired(TIMER_NUM_t timer, u8_t *expired)
{

    switch (timer)
    {
    case TIMER_0:
        /* code */
        return E_OK;
        break;
    case TIMER_1:
        *expired = T1_done;
        return E_OK;
        break;
    case TIMER_2:
        /* code */
        return E_OK;

        break;

    default:
        return E_NOK;
        break;
    }
}

void SetCallBack_Timer0CTC(void (*func)(void))
{
    CallBack_Timer0CTC = func;
}

void SetCallBack_Timer0OVF(void (*func)(void))
{
    CallBack_Timer0OVF = func;
}

void __vector_10(void) __attribute__((signal, __INTR_ATTRS));
void __vector_10(void)
{
    if (CallBack_Timer0CTC != NULL_PTR)
    {
        CallBack_Timer0CTC();
    }
}

void __vector_11(void) __attribute__((signal, __INTR_ATTRS));
void __vector_11(void)
{
    TCNT0 = gu8_intial_value;
    if (CallBack_Timer0OVF != NULL_PTR)
    {
        CallBack_Timer0OVF();
    }
}
// TIMER1 compA ISR
void __vector_7(void) __attribute__((signal, __INTR_ATTRS));
void __vector_7(void)
{
    tot_overflow_T1++;
    if (tot_overflow_T1 == max_ovf_T1)
    {
        T1_done = TRUE;
        T1_busy = FALSE;
        TIMER_stop(TIMER_1);
    }
    else
    {
        T1_done = FALSE;
    }
}
