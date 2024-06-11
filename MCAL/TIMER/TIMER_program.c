/*
 * TIMER_program.c
 *
 *  Created on: Apr 7, 2024
 *      Author: ad
 */




/******************************************* Include  Section *******************************************/
#include "../DIO/helper_embedded_libraries/micro_config.h"
#include "../DIO/DIO_interface.h"
#include "TIMER_config.h"
#include "TIMER_priv.h"
#include "TIMER_interface.h"
#include "../GIE/GIE_interface.h"
#include "../EXTI/EXTI_interface.h"
#include <avr/interrupt.h>
/********************************************************************************************************/





/******************************** Timer Tick Counters and ISR Handlers ********************************/

// Global tick count targets for each timer
static uint32_t TIMER0_TARGET_NTICKS;  // Target ticks for TIMER0
//static uint32_t TIMER1_TARGET_NTICKS;  // Target ticks for TIMER1
static uint32_t TIMER2_TARGET_NTICKS;  // Target ticks for TIMER2


// Define counters for each timer to track the number of overflows
static uint32_t TIMER0_CURRENT_NTICKS = 0;  // Current overflow count for TIMER0
//static uint32_t TIMER1_CURRENT_NTICKS = 0;  // Current overflow count for TIMER1
static uint32_t TIMER2_CURRENT_NTICKS = 0;  // Current overflow count for TIMER2
//

// Array of function pointers for Timer ISR callbacks
static void (*TIMERS_ISR_Functions[3])(void) = {NULL, NULL, NULL};
/*******************************************************************************************************/



/****************************************** TIMER0 FUNCTIONS ******************************************/
void TIMER0_voidInit(void){


	/*
	 * 1. Set Timter Mode (Normal - PWM phase correct - Fast PWM)
	 * 	  	For CTC MODE:
	 * 	  		- set compare output mode (toggle - clear - set)
	 *
	 * 2. set clock
	 *
	 * 3. Enable Interrupt (Compre Match Interrupt - OverFlow Interrupt)
	 *
	 * */

	/** Active global interrupt **/
	GIE_enuEnable();

	/**1. Set Timer Mode **/
	#if(TIMER0_MODE_SELECT == TIMER_MODE_NORMALovf)
		SET_BIT(TCCR0_REG, TCCR0_WGM01);
		SET_BIT(TCCR0_REG, TCCR0_WGM00);

	#elif(TIMER0_MODE_SELECT == TIMER_MODE_CTC)
		CLR_BIT(TCCR0_REG, TCCR0_WGM00);
		SET_BIT(TCCR0_REG, TCCR0_WGM01);

		/** Set compare output mode **/

		#if(TIMER0_OC0_OUTPUT_STATE == TIMER0_OC0_OUTPUT_ENABLE)
		DIO_enuSetPinDirection(TIMER_OC0_PORT, TIMER_OC0_PIN, DIO_u8OUTPUT);

			#if(TIMER_OC0_OUTPUT_MODE == TIMER_SET_OC0)
				SET_BIT(TCCR0_REG, TCCR0_COM00);
				SET_BIT(TCCR0_REG, TCCR0_COM01);

			#elif(TIMER_OC0_OUTPUT_MODE == TIMER_CLR_OC0)
				CLR_BIT(TCCR0_REG, TCCR0_COM00);
				SET_BIT(TCCR0_REG, TCCR0_COM01);

			#elif(TIMER_OC0_OUTPUT_MODE == TIMER_TOGGLE_OC0)
				SET_BIT(TCCR0_REG, TCCR0_COM00);
				CLR_BIT(TCCR0_REG, TCCR0_COM01);


			#elif(TIMER_OC0_OUTPUT_MODE == TIMER_NORMAL_OC2)
				CLR_BIT(TCCR0_REG, TCCR0_COM00);
				CLR_BIT(TCCR0_REG, TCCR0_COM01);
			#endif
		#endif


	#endif


	/**2. Set Prescaller clock **/
	#if(TIMER0_CLK_PRE_SELECT == TIMER_PRES_01)
		SET_BIT(TCCR0_REG, TCCR0_CS00);
		CLR_BIT(TCCR0_REG, TCCR0_CS01);
		CLR_BIT(TCCR0_REG, TCCR0_CS02);

	#elif(TIMER0_CLK_PRE_SELECT == TIMER_PRES_08)
		CLR_BIT(TCCR0_REG, TCCR0_CS00);
		SET_BIT(TCCR0_REG, TCCR0_CS01);
		CLR_BIT(TCCR0_REG, TCCR0_CS02);

	#elif(TIMER0_CLK_PRE_SELECT == TIMER_PRES_64)
		SET_BIT(TCCR0_REG, TCCR0_CS00);
		SET_BIT(TCCR0_REG, TCCR0_CS01);
		CLR_BIT(TCCR0_REG, TCCR0_CS02);

	#elif(TIMER0_CLK_PRE_SELECT == TIMER_PRES_256)
		CLR_BIT(TCCR0_REG, TCCR0_CS00);
		CLR_BIT(TCCR0_REG, TCCR0_CS01);
		SET_BIT(TCCR0_REG, TCCR0_CS02);

	#elif(TIMER0_CLK_PRE_SELECT == TIMER_PRES_1024)
		SET_BIT(TCCR0_REG, TCCR0_CS00);
		CLR_BIT(TCCR0_REG, TCCR0_CS01);
		SET_BIT(TCCR0_REG, TCCR0_CS02);
	#endif
}

void TIMER0_voidStart(void){
		#if(TIMER0_MODE_SELECT == TIMER_MODE_NORMALovf)
			SET_BIT(TIMSK_REG, TIMSK_TOIE0);

		#elif(TIMER0_MODE_SELECT == TIMER_MODE_CTC)
			SET_BIT(TIMSK_REG, TIMSK_OCIE0);

		#endif
}

void TIMER0_voidStop(void){
		#if(TIMER0_MODE_SELECT == TIMER_MODE_NORMALovf)
			CLR_BIT(TIMSK_REG, TIMSK_TOIE0);

		#elif(TIMER0_MODE_SELECT == TIMER_MODE_CTC)
			CLR_BIT(TIMSK_REG, TIMSK_OCIE0);

		#endif
}

uint8_t TIMER0_voidScheduleTask( void (*TaskCallback)(void), float64 copy_f64RequiredTime_inSeconds){

	uint32_t Local_u32PrescalerValue = 0;

	switch(TCCR0 & 0x07){
		case 0x01: Local_u32PrescalerValue = 1; break;
		case 0x02: Local_u32PrescalerValue = 8; break;
		case 0x03: Local_u32PrescalerValue = 64; break;
		case 0x04: Local_u32PrescalerValue = 256; break;
		case 0x05: Local_u32PrescalerValue = 1024; break;
	}

	float64 Local_f64Totalticks = (copy_f64RequiredTime_inSeconds * F_CPU)/Local_u32PrescalerValue;

	#if(TIMER0_MODE_SELECT == TIMER_MODE_NORMALovf)




		/**
		 *  fmod - function similar to modulus operator but designed to work
		 *  with floating point numbers, not just integers. it computes the
		 *  remainder of the diviion of one floating-point number by another.
		 * */

		if( (fmod(Local_f64Totalticks, 1.00) == 0.0)  &&  fmod(Local_f64Totalticks, 256.0) == 0.0){
			TIMER0_TARGET_NTICKS = (uint32_t)(Local_f64Totalticks/256);
		}else{
			// It's floating Number, setting preload value

			TCNT0_REG = 256 - (uint32_t)(fmod(Local_f64Totalticks, 256.0));

			TIMER0_TARGET_NTICKS = (uint32_t)ceil(Local_f64Totalticks/256);
		}




	#elif(TIMER0_MODE_SELECT == TIMER_MODE_CTC)


		if(Local_f64Totalticks > 255){
			OCR0_REG = 255;
	        TIMER0_TARGET_NTICKS = ceil((double)Local_f64Totalticks / 255.0); // How many times timer should reach 255

		}else{
			OCR0_REG = Local_f64Totalticks-1;
			TIMER0_TARGET_NTICKS  = 1;
		}

	#endif


		TIMERS_ISR_Functions[0] = TaskCallback;
		TIMER0_voidStart();
	return 0;
}
/******************************************************************************************************/






/****************************************** TIMER2 FUNCTIONS ******************************************/
void TIMER2_voidInit(void){
	/**
	 * TODO:
	 *  1. Specify opearting mode (Normal - PWM - CTC - Fast PWM)
	 *
	 *  	Incase of choosing CTC Mode
	 *  	. CTC output mode (Toggle - Clear - Set )
	 *
	 *
	 *		Incase of choosing Fast PWM Mode
	 *		. modes(normal - reversed clear on compare match - set)
	 *
	 *
	 *		Incase of choosing Phase Correct PWM Mode
	 *		. modes(Normal - Reversed - clear on compare - set on compare)
	 *
	 *
	 *	2. Set Prescaler Value
	 *
	 *
	 *	3. ⚠{Asynchrounous is not addressed yet}
	 *
	 *	4. Turn Global Interrupt ON
	 *
	 * */


	/**************************** Set  mode for TIMER2 ****************************/
	#if(TIMER2_MODE_SELECT == TIMER_MODE_NORMALovf)
		CLR_BIT(TCCR2_REG, TCCR2_WGM20);
		CLR_BIT(TCCR2_REG, TCCR2_WGM21);

	#elif(TIMER2_MODE_SELECT == TIMER_MODE_CTC)

		CLR_BIT(TCCR2_REG, TCCR2_WGM20);
		SET_BIT(TCCR2_REG, TCCR2_WGM21);


		#if(TIMER2_OC2_OUTPUT_STATE == TIMER2_OC2_OUTPUT_ENABLE)
		DIO_enuSetPinDirection(TIMER_OC2_PORT, TIMER_OC2_PIN, DIO_u8OUTPUT);

			#if(TIMER_OC2_OUTPUT_MODE == TIMER_TOGGLE_OC2)
				SET_BIT(TCCR2_REG, TCCR2_COM20);
				CLR_BIT(TCCR2_REG, TCCR2_COM21);

			#elif(TIMER_OC2_OUTPUT_MODE == TIMER_SET_OC2)
				SET_BIT(TCCR2_REG, TCCR2_COM20);
				SET_BIT(TCCR2_REG, TCCR2_COM21);

			#elif(TIMER_OC2_OUTPUT_MODE == TIMER_CLR_OC2)
				CLR_BIT(TCCR2_REG, TCCR2_COM20);
				SET_BIT(TCCR2_REG, TCCR2_COM21);

			#elif(TIMER_OC2_OUTPUT_MODE == TIMER_NORMAL_OC2)
				CLR_BIT(TCCR2_REG, TCCR2_COM20);
				CLR_BIT(TCCR2_REG, TCCR2_COM21);

			#endif

		#endif


	#endif
	/******************************************************************************/

	/***************************** TIMER2  PRE SELECT *****************************/
	#if(TIMER2_CLK_PRE_SELECT == TIMER_PRES_01)
		SET_BIT(TCCR2_REG, TCCR2_CS20);
		CLR_BIT(TCCR2_REG, TCCR2_CS21);
		CLR_BIT(TCCR2_REG, TCCR2_CS22);

	#elif(TIMER2_CLK_PRE_SELECT == TIMER_PRES_08)
		CLR_BIT(TCCR2_REG, TCCR2_CS20);
		SET_BIT(TCCR2_REG, TCCR2_CS21);
		CLR_BIT(TCCR2_REG, TCCR2_CS22);

	#elif(TIMER2_CLK_PRE_SELECT == TIMER_PRES_32)
		SET_BIT(TCCR2_REG, TCCR2_CS20);
		SET_BIT(TCCR2_REG, TCCR2_CS21);
		CLR_BIT(TCCR2_REG, TCCR2_CS22);

	#elif(TIMER2_CLK_PRE_SELECT == TIMER_PRES_64)
		CLR_BIT(TCCR2_REG, TCCR2_CS20);
		CLR_BIT(TCCR2_REG, TCCR2_CS21);
		SET_BIT(TCCR2_REG, TCCR2_CS22);

	#elif(TIMER2_CLK_PRE_SELECT == TIMER_PRES_128)
		SET_BIT(TCCR2_REG, TCCR2_CS20);
		CLR_BIT(TCCR2_REG, TCCR2_CS21);
		SET_BIT(TCCR2_REG, TCCR2_CS22);

	#elif(TIMER2_CLK_PRE_SELECT == TIMER_PRES_256)
		CLR_BIT(TCCR2_REG, TCCR2_CS20);
		SET_BIT(TCCR2_REG, TCCR2_CS21);
		SET_BIT(TCCR2_REG, TCCR2_CS22);

	#elif(TIMER2_CLK_PRE_SELECT == TIMER_PRES_1024)
		SET_BIT(TCCR2_REG, TCCR2_CS20);
		SET_BIT(TCCR2_REG, TCCR2_CS21);
		SET_BIT(TCCR2_REG, TCCR2_CS22);
	#endif
	/******************************************************************************/


	// Turn Global Interrupt ON
	GIE_enuEnable();

}

void TIMER2_voidStart(void){
	#if(TIMER2_MODE_SELECT == TIMER_MODE_NORMALovf)
		SET_BIT(TIMSK_REG, TIMSK_TOIE2);

	#elif(TIMER2_MODE_SELECT == TIMER_MODE_CTC)
		SET_BIT(TIMSK_REG, TIMSK_OCIE2);

	#endif
}

void TIMER2_voidStop(void){
	#if(TIMER2_MODE_SELECT == TIMER_MODE_NORMALovf)
		CLR_BIT(TIMSK_REG, TIMSK_TOIE2);

	#elif(TIMER2_MODE_SELECT == TIMER_MODE_CTC)
		CLR_BIT(TIMSK_REG, TIMSK_OCIE2);

	#endif
}

uint8_t TIMER2_voidScheduleTask( void (*TaskCallback)(void), float64 copy_f64RequiredTime_inSeconds){

	uint32_t Local_u32PrescalerValue = 0;

	switch(TCCR2 & 0x07){
		case 0x01: Local_u32PrescalerValue = 1; break;
		case 0x02: Local_u32PrescalerValue = 8; break;
		case 0x03: Local_u32PrescalerValue = 64; break;
		case 0x04: Local_u32PrescalerValue = 256; break;
		case 0x05: Local_u32PrescalerValue = 1024; break;
	}

	float64 Local_f64Totalticks = (copy_f64RequiredTime_inSeconds * F_CPU)/Local_u32PrescalerValue;

	#if(TIMER2_MODE_SELECT == TIMER_MODE_NORMALovf)




		/**
		 *  fmod - function similar to modulus operator but designed to work
		 *  with floating point numbers, not just integers. it computes the
		 *  remainder of the diviion of one floating-point number by another.
		 * */

		if( (fmod(Local_f64Totalticks, 1.00) == 0.0)  &&  fmod(Local_f64Totalticks, 256.0) == 0.0){
			TIMER2_TARGET_NTICKS = (uint32_t)(Local_f64Totalticks/256);
		}else{
			// It's floating Number, setting preload value

			TCNT2_REG = 256 - (uint32_t)(fmod(Local_f64Totalticks, 256.0));

			TIMER2_TARGET_NTICKS = (uint32_t)ceil(Local_f64Totalticks/256);
		}




	#elif(TIMER2_MODE_SELECT == TIMER_MODE_CTC)


		if(Local_f64Totalticks > 255){
			OCR2_REG = 255;
	        TIMER2_TARGET_NTICKS = ceil((double)Local_f64Totalticks / 255.0); // How many times timer should reach 255

		}else{
			OCR2_REG = Local_f64Totalticks-1;
			TIMER2_TARGET_NTICKS  = 1;
		}

	#endif


		TIMERS_ISR_Functions[2] = TaskCallback;
		TIMER2_voidStart();
	return 0;

}
/*******************************************************************************************************/

ISR(TIMER0_OVF_vect){

	TIMER0_CURRENT_NTICKS++;

	if(TIMER0_CURRENT_NTICKS >= TIMER0_TARGET_NTICKS){
		TIMER0_CURRENT_NTICKS = 0;
		TIMERS_ISR_Functions[0]();
	}


	//here we can specify whether we want to stop timer0 or keep repeat or anything
}

ISR(TIMER0_COMP_vect){

	TIMER0_CURRENT_NTICKS++;

	if(TIMER0_CURRENT_NTICKS >= TIMER0_TARGET_NTICKS){
		TIMER0_CURRENT_NTICKS = 0;
		TIMERS_ISR_Functions[0]();
	}


	//here we can specify whether we want to stop timer0 or keep repeat or anything
}

ISR(TIMER2_OVF_vect){

	TIMER2_CURRENT_NTICKS++;

	if(TIMER2_CURRENT_NTICKS >= TIMER2_TARGET_NTICKS){
		TIMER2_CURRENT_NTICKS = 0;
		TIMERS_ISR_Functions[2]();
	}


	//here we can specify whether we want to stop timer 2 or keep repeat or anything
}

ISR(TIMER2_COMP_vect){

	TIMER2_CURRENT_NTICKS++;

	if(TIMER2_CURRENT_NTICKS >= TIMER2_TARGET_NTICKS){
		TIMER2_CURRENT_NTICKS = 0;
		TIMERS_ISR_Functions[2]();
	}


	//here we can specify whether we want to stop timer 2 or keep repeat or anything

}