/*
 * EXTI_priv.h
 *
 *  Created on: Jan 15, 2024
 *      Author: ad
 */

#ifndef MCAL_EXTI_EXTI_PRIV_H_
#define MCAL_EXTI_EXTI_PRIV_H_

/**
 * MCUCCR - MCU Control Register
 * 	contains control bits for interrupt sense control and ....
 *
 *
 * MCUCSR - MCU Control and Status Register
 * 	I guess, it's same as previous but for only INT2 except
 * 	otherone which was for INT0 and INT1
 *
 *
 * GICR   - General Interrupt Control:
 * 	This Controls turnning on or off INT0, INT1, INT2
 *
 * */


/********** Used Registers **********/
#define MCUCCR 	*((uint8_t*) (0x55))
#define MCUCSR 	*((uint8_t*) (0x54))
#define GICR	*((uint8_t*) (0x5B))
#define GIFR	*((uint8_t*) (0x5A))
/*********************************/


#define NUM_INT				3

#define INT0				0
#define INT1				1
#define INT2				2

/********** Sense Modes **********/
#define ANY_lOGICALCHANGE	0
#define LOW_LEVEL			1
#define FALLING_EDGE		2
#define RISING_EDGE			3
/*********************************/


#define DISABLED			0
#define ENABLED				1



/********* INT0/1/2 bits *********/
//Sense Mode Section
#define ISC00				0
#define ISC01				1
#define ISC10				2
#define ISC11				3

#define ISC2				6


//On-Off Control Section
#define INT0_switch			6
#define INT1_switch			7
#define INT2_switch			5

/*********************************/




//
//#define ISR(VECTOR_NUM)  void VECTOR_NUM(void) __attribute__((signal)); \
//                         void VECTOR_NUM(void)
//
//
//
//#define INT0_vector		__vector_1
//#define INT1_vector 	__vector_2
//#define INT2_vector 	__vector_2
//
//





#endif /* MCAL_EXTI_EXTI_PRIV_H_ */
