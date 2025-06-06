/**
 * @file    EXTI_program.c
 * @author  Mohamed Moaaz
 * @brief   External interrupt program file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

//==============================================================================
// Includes
//==============================================================================

#include "STD_TYPES.h"
#include "MCAL/GIE_interface.h"
#include "MCAL/GIE_register.h"

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
// Exported Values
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

void GIE_voidEnable(void)
{
    SET_BIT(SREG, SREG_I);
}

void GIE_voidDisable(void)
{
    CLEAR_BIT(SREG, SREG_I);
}