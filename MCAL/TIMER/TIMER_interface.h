/*
 * TIMER_interface.h
 *
 *  Created on: Apr 7, 2024
 *      Author: ad
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

/****************************************** TIMER0 INTERFACE ******************************************/
void TIMER0_voidInit(void);
void TIMER0_voidStart(void);
void TIMER0_voidStop(void);
void TIMER0_voidSetPWM(uint8_t copy_u8DutyCycle);


uint8_t TIMER0_voidScheduleTask( void (*TaskCallback)(void), float64 copy_f64RequiredTime_inSeconds);
/******************************************************************************************************/



/****************************************** TIMER1 INTERFACE ******************************************/
void TIMER1_voidInit(void);
void TIMER1_voidStart(void);
void TIMER1_voidStop(void);

// Function for setting PWM in non-16bit modes
void TIMER1_voidSetPWM(uint8_t duty_cycle_percent);

// Function for setting PWM in 16bit modes with frequency control
void TIMER1_voidSetPWM_16bit(uint8_t duty_cycle_percent, uint32_t frequency);




uint8_t TIMER1_voidScheduleTask( void (*TaskCallback)(void), float64 copy_f64RequiredTime_inSeconds);
/******************************************************************************************************/



/****************************************** TIMER2 INTERFACE ******************************************/
void TIMER2_voidInit(void);
void TIMER2_voidStart(void);
void TIMER2_voidStop(void);
void TIMER2_voidSetPWM(uint8_t copy_u8DutyCycle);


uint8_t TIMER2_voidScheduleTask( void (*TaskCallback)(void), float64 copy_f64RequiredTime_inSeconds);
/******************************************************************************************************/



/****************************************** WATCH DOG TIMER INTERFACE ******************************************/
//void TIMER_voidWDTSleep(void);
//void TIMER_voidWDTEnable (void);
//void TIMER_voidWDTDisable(void);
/******************************************************************************************************/


//uint32_t TIMER_u32MeasureExecutionTime(uint8_t u8TimerID, void (*funcToMeasure)(void));



#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
