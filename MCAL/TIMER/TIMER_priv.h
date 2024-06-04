/*
 * TIMER_priv.h
 *
 *  Created on: Apr 7, 2024
 *      Author: ad
 */

#ifndef MCAL_TIMER_TIMER_PRIV_H_
#define MCAL_TIMER_TIMER_PRIV_H_


/************************ TIMER Registers ************************/
#define TIFR_REG    *((volatile uint8_t*) (0x58))
#define TIMSK_REG   *((volatile uint8_t*) (0x59))


#define TCNT0_REG   *((volatile uint8_t*) (0x52))
#define TCCR0_REG   *((volatile uint8_t*) (0x53))


#define OCR0_REG	*((volatile uint8_t*) (0x5C))


#define TCNT2_REG	*((volatile uint8_t*) (0x44))
#define TCCR2_REG	*((volatile uint8_t*) (0x45))
#define OCR2_REG	*((volatile uint8_t*) (0x43))


/*****************************************************************/



/************************ TCCR0 BITS ************************/
#define TCCR0_CS00							0
#define TCCR0_CS01							1
#define TCCR0_CS02							2
#define TCCR0_WGM01							3
#define TCCR0_COM00							4
#define TCCR0_COM01							5
#define TCCR0_WGM00							6
#define TCCR0_FOC0							7
/************************************************************/


/************************ TCCR2 BITS ************************/
#define TCCR2_CS20							0
#define TCCR2_CS21							1
#define TCCR2_CS22							2
#define TCCR2_WGM21							3
#define TCCR2_COM20							4
#define TCCR2_COM21							5
#define TCCR2_WGM20							6
#define TCCR2_FOC2							7
/************************************************************/



/************************ TIMSK BITS ************************/
#define TIMSK_TOIE0							0
#define TIMSK_OCIE0							1
#define TIMSK_TOIE1							2
#define TIMSK_OCIE1B						3
#define TIMSK_OCIE1A						4
#define TIMSK_TICIE1						5
#define TIMSK_TOIE2							6
#define TIMSK_OCIE2							7
/************************************************************/





#define TIMER_MODE_NORMALovf				0
#define TIMER_MODE_PWMphasecorrect			1
#define TIMER_MODE_CTC						2
#define TIMER_MODE_FastPWM					3


#define TIMER_TOGGLE_OC0					4
#define TIMER_CLR_OC0						5
#define TIMER_SET_OC0						6
#define TIMER_NORMAL_OC0					7


#define TIMER_CLR_OC2						5
#define TIMER_SET_OC2						6
#define TIMER_NORMAL_OC2					7

#define TIMER_PRES_01						7
#define TIMER_PRES_08						8
#define TIMER_PRES_32						9
#define TIMER_PRES_64						10
#define TIMER_PRES_128						11
#define TIMER_PRES_256						12
#define TIMER_PRES_1024						13



#define TIMER0_OC0_OUTPUT_ENABLE           1
#define TIMER0_OC0_OUTPUT_DISABLE          2



#define TIMER2_OC2_OUTPUT_ENABLE           1
#define TIMER2_OC2_OUTPUT_DISABLE          2



#endif /* MCAL_TIMER_TIMER_PRIV_H_ */
