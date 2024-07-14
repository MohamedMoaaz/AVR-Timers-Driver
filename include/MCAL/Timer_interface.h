/**
 * @file    Timer_Interface.h
 * @author  Mohamed Moaaz
 * @brief   Timer interfacing file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

#ifndef __TIMER_INTERFACE_H__
#define __TIMER_INTERFACE_H__

//==============================================================================
// Macros & Defines
//==============================================================================
/*peripherals interrupts IDs*/
#define TIMER2_OUTPUT_COMPARE_MATCH_INTERRUPT_ID       7    
#define TIMER2_OVERFLOW_INTERRUPT_ID                   6
#define TIMER1_INPUT_CAPTURE_INTERRUPT_ID              5
#define TIMER1_OUTPUT_COMPARE_A_MATCH_INTERRUPT_ID     4
#define TIMER1_OUTPUT_COMPARE_B_MATCH_INTERRUPT_ID     3
#define TIMER1_OVERFLOW_INTERRUPT_ID                   2
#define TIMER0_OUTPUT_COMPARE_MATCH_INTERRUPT_ID       1
#define TIMER0_OVERFLOW_INTERRUPT_ID                   0

/*Timer1 Input capture edge trigger*/
#define ICU_RISING_EDGE                                1
#define ICU_FALLING_EDGE                               0

/*Timer0 fuction repetition modes*/
#define TIMER0_OVERFLOW_ONCE                           1
#define TIMER0_OVERFLOW_REPEAT                         0

//==============================================================================
// Typedefs
//==============================================================================


//==============================================================================
// Exported Values
//==============================================================================


//==============================================================================
// Global Functions Prototypes
//==============================================================================

void Timer0_voidInit(void);
E_Status Timer0_u8NormalModeSetTime(uint16_t copy_u16MilliSeconds, void (*Copy_pvCallBackFunc)(void), uint8_t copy_u8Repetition);
void Timer0_voidCTCModeSetTime(uint16_t copy_u16MilliSeconds, uint8_t copy_u8CompareMatchValue);
E_Status Timer0_u8StartFastPWM(uint8_t copy_u8DutyCycle);

void Timer1_Init(void);
/**
 * @brief this function is mainly used to control servo motor 
 * and it is only work properly on selecting prescaler 8 and fast pwm non inverting mode
 * @param copy_u16OnTime 
 * @param copy_u16PeriodTimeInMicroSec 
 */
void Timer1_voidStartCustomFastPWM(uint16_t copy_u16OnTime, uint16_t copy_u16PeriodTimeInMicroSec);

void Timer1_voidStart(void);
void Timer1_voidSetTimerValue(uint16_t copy_u16Value);
uint16_t Timer1_u16ReadTimerValue(void);
void Timer1_voidICUInit(void);
uint16_t Timer1_u16ReadInputCapture(void);
E_Status Timer1_u8ICUSettTriggerEdge(uint8_t copy_u8TriggerEdge);
E_Status Timer_u8InterruptEnable(uint8_t copy_u8PeripheralInterruptID);
E_Status Timer_u8InterruptDisable(uint8_t copy_u8PeripheralInterruptID);
E_Status Timer_u8SetCallBack(void (*Copy_pvCallBackFunc)(void), uint8_t copy_u8PeripheralInterruptID);
#endif /* __TIMER_INTERFACE_H__ */