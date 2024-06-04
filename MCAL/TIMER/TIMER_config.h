/*
 * TIMER_config.h
 *
 *  Created on: Apr 7, 2024
 *      Author: ad
 */

#ifndef MCAL_TIMER_TIMER_CONFIG_H_
#define MCAL_TIMER_TIMER_CONFIG_H_

#define F_CPU 8000000UL

/******************* Set  mode for TIMER Pins *******************/
#define TIMER_OC0_PORT			DIO_u8PortB
#define TIMER_OC0_PIN			DIO_u8PIN3


#define TIMER_OC1A_PORT			DIO_u8PortD
#define TIMER_OC1A_PIN			DIO_u8PIN5

#define TIMER_OC1B_PORT			DIO_u8PortD
#define TIMER_OC1B_PIN			DIO_u8PIN4

#define TIMER_OC2_PORT			DIO_u8PortD
#define TIMER_OC2_PIN			DIO_u8PIN7
/****************************************************************/

/************************ TIMER0  CONFIG ***********************/
// Options: TIMER_MODE_NORMALovf	or		TIMER_MODE_PWMphasecorrect
//			TIMER_MODE_FastPWM      or  	TIMER_MODE_CTC
#define TIMER0_MODE_SELECT				TIMER_MODE_CTC



// Options: TIMER0_OC0_OUTPUT_ENABLE or TIMER0_OC0_OUTPUT_DISABLE
#define TIMER0_OC0_OUTPUT_STATE			TIMER0_OC0_OUTPUT_ENABLE

#if(TIMER0_OC0_OUTPUT_STATE == TIMER0_OC0_OUTPUT_ENABLE)
	#if(TIMER0_MODE_SELECT == TIMER_MODE_CTC)
		// Options: TIMER_SET_OC0 or TIMER_CLR_OC0
		//			TIMER_TOGGLE_OC0
		#define TIMER_OC0_OUTPUT_MODE			TIMER_TOGGLE_OC0
	#endif
#endif

/*
 *PWM and other options
 *
 **/


// Options: TIMER_PRES_01  or TIMER_PRES_08
//			TIMER_PRES_64
// 			TIMER_PRES_256 or TIMER_PRES_1024
#define TIMER0_CLK_PRE_SELECT			TIMER_PRES_64
/***************************************************************/



/************************ TIMER1  CONFIG ***********************/
/***************************************************************/



/************************ TIMER2  CONFIG ***********************/
// Options: TIMER_MODE_NORMALovf	or		TIMER_MODE_PWMphasecorrect
//			TIMER_MODE_FastPWM      or  	TIMER_MODE_CTC
#define TIMER2_MODE_SELECT				TIMER_MODE_NORMALovf


// Options: TIMER2_OC2_OUTPUT_ENABLE or TIMER2_OC2_OUTPUT_DISABLE
#define TIMER2_OC2_OUTPUT_STATE			TIMER2_OC2_OUTPUT_ENABLE

#if(TIMER2_OC2_OUTPUT_STATE == TIMER2_OC2_OUTPUT_ENABLE)

	#if(TIMER2_MODE_SELECT == TIMER_MODE_CTC)
		// Options: TIMER_SET_OC2 or TIMER_CLR_OC2
		//			TIMER_TOGGLE_OC2 or TIMER_NORMAL_OC2
		#define TIMER_OC2_OUTPUT_MODE			TIMER_SET_OC2
	#endif

#endif
/*
 *PWM and other options
 *
 **/

// Options: TIMER_PRES_01  or TIMER_PRES_08
//			TIMER_PRES_64
// 			TIMER_PRES_256 or TIMER_PRES_1024
#define TIMER2_CLK_PRE_SELECT			TIMER_PRES_01
/***************************************************************/


#endif /* MCAL_TIMER_TIMER_CONFIG_H_ */
