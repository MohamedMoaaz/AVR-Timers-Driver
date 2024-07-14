/**
 * @file    main.c
 * @author  Mohamed Moaaz
 * @brief   Main executable file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

//==============================================================================
// Includes
//==============================================================================

#include "STD_TYPES.h"
#include "MCAL/DIO_interface.h"
#include "MCAL/PORT_interface.h"
#include "MCAL/GIE_interface.h"
#include "MCAL/Timer_interface.h"

//==============================================================================
// Extern Variables
//==============================================================================

//==============================================================================
// Private Macros & Defines
//==============================================================================

//==============================================================================
// Private Typedefs
//==============================================================================

//==============================================================================
// Static Variables
//==============================================================================

//==============================================================================
// Global Variables
//==============================================================================

//==============================================================================
// Static Functions Prototypes
//==============================================================================

//==============================================================================
// Static Functions
//==============================================================================

//==============================================================================
// Global Functions
//==============================================================================
uint16_t PeriodTicks = 0;
uint16_t OnTicks = 0;
/**
 * @brief   Main function.
 * @return  Status code.
 */
int main(void)
{

    for (;;)
    {
    }
    return 0;
}

void ICU_HW(void)
{
    static uint16_t Reading1, Reading2, Reading3;
    static uint8_t Local_u8Counter = 0;
    Local_u8Counter++;

    if (Local_u8Counter == 1)
    {
        Reading1 = ICU_u16ReadInputCapture();
    }
    else if (Local_u8Counter == 2)
    {
        Reading2 = ICU_u16ReadInputCapture();
        PeriodTicks = Reading2 - Reading1;
        ICU_u8SetTriggerEdge(ICU_FALLING_EDGE);
    }
    else if (Local_u8Counter == 3)
    {
        Reading3 = ICU_u16ReadInputCapture();
        OnTicks = Reading3 - Reading2;
        ICU_voidDisableInterrupt();
    }
}