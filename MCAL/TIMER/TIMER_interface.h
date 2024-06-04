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

uint8_t TIMER0_voidScheduleTask( void (*TaskCallback)(void), float64 copy_f64RequiredTime_inSeconds);
/******************************************************************************************************/



/****************************************** TIMER1 INTERFACE ******************************************/
/******************************************************************************************************/



/****************************************** TIMER2 INTERFACE ******************************************/
void TIMER2_voidInit(void);
void TIMER2_voidStart(void);
void TIMER2_voidStop(void);

uint8_t TIMER2_voidScheduleTask( void (*TaskCallback)(void), float64 copy_f64RequiredTime_inSeconds);
/******************************************************************************************************/





//uint32_t TIMER_u32MeasureExecutionTime(uint8_t u8TimerID, void (*funcToMeasure)(void));



#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
