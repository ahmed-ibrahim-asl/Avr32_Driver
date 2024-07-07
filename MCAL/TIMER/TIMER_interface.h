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
void TIMER1_voidSetPWM(uint8_t copy_u8DutyCycle);




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

/******************************************************************************************************/


//uint32_t TIMER_u32MeasureExecutionTime(uint8_t u8TimerID, void (*funcToMeasure)(void));



#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
