#include "../../LIB/Std_Types.h"
#include "CPU.h"

static uint8 guint8_CritCount = 0;


/* Enable IRQ Interrupts ... This Macro enables IRQ interrupts by clearing the I-bit in the PRIMASK. */
#define CPU_EnableGlobalInterrupt()  __asm("CPSIE I")

/* Disable IRQ Interrupts ... This Macro disables IRQ interrupts by setting the I-bit in the PRIMASK. */
#define CPU_DisableGlobalInterrupt() __asm("CPSID I")


void CPU_StartCriticalSection(void)
{
    guint8_CritCount++;
    CPU_DisableGlobalInterrupt();
}
void CPU_StopCriticalSection(void)
{
    if (guint8_CritCount == 0)
    {
        CPU_EnableGlobalInterrupt();
    }
    else
    {
        guint8_CritCount--;
        if (guint8_CritCount == 0)
        {
            CPU_EnableGlobalInterrupt();
        }
        else
        {
            /* do nothing */
        }
    }
}