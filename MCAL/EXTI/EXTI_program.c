/*
 * EXTI_program.c
 *
 *  Created on: Jan 15, 2024
 *      Author: ad
 *
 * 	Special thing in this driver is "Linking type" configuration
 * 	is implemented.
 */





/*************** Include Section Start ********************/
#include "../DIO/helper_embedded_libraries/micro_config.h"
#include "EXTI_interface.h"
#include "EXTI_priv.h"
#include "EXTI_config.h"
#include <avr/interrupt.h>
/**********************************************************/

//void (*Copy_pfunAppFun[NUM_INT])(void) = {NULL, NULL, NULL};

static void (*EXTI_pfunISRFun[NUM_INT])(void) = {NULL, NULL, NULL};



ErrorStatus_t EXTI_enuInit(EXTI* Copy_pu8GroupConfig){

	ErrorStatus_t Local_enuErrorStatus = ERROR_STATUS_FAILURE;


	if(Copy_pu8GroupConfig == NULL){

		return Local_enuErrorStatus;
	}


	else{
		/**************** INT0 Configuration ****************/
		if(Copy_pu8GroupConfig[INT0].Int_State == ENABLED){

			GICR |= (1<<INT0_switch);

			switch(Copy_pu8GroupConfig[INT0].Sence_Level){
				case ANY_lOGICALCHANGE:

					MCUCCR |=  (1 << ISC00);
					MCUCCR &= ~(1 << ISC01);

					break;

				case LOW_LEVEL:

					MCUCCR &= ~(1 << ISC00);
					MCUCCR &= ~(1 << ISC01);

					break;

				case FALLING_EDGE:

					MCUCCR &= ~(1 << ISC00);
					MCUCCR |=  (1 << ISC01);

					break;

				case RISING_EDGE:

					MCUCCR |=  (1 << ISC00);
					MCUCCR |=  (1 << ISC01);

					break;
			}


		}
		else if (Copy_pu8GroupConfig[INT0].Int_State == DISABLED){

			GICR &= ~(1<<INT0_switch);

		}
		/***************************************************/


		/**************** INT1 Configuration ****************/
		if(Copy_pu8GroupConfig[INT1].Int_State == ENABLED){

			GICR |= (1<<INT1_switch);


			switch(Copy_pu8GroupConfig[INT1].Sence_Level){
				case ANY_lOGICALCHANGE:

					MCUCCR |=   (1 << ISC10);
					MCUCCR &=  ~(1 << ISC11);

					break;

				case LOW_LEVEL:

					MCUCCR &=  ~(1 << ISC10);
					MCUCCR &=  ~(1 << ISC11);

					break;

				case FALLING_EDGE:

					MCUCCR &=  ~(1 << ISC10);
					MCUCCR |=   (1 << ISC11);

					break;

				case RISING_EDGE:

					MCUCCR |=  (1 << ISC10);
					MCUCCR |=  (1 << ISC11);

					break;
			}


		}
		else if (Copy_pu8GroupConfig[INT1].Int_State == DISABLED){

			GICR &= ~(1<<INT1_switch);

		}
		/***************************************************/


		/**************** INT2 Configuration ****************/
		if(Copy_pu8GroupConfig[INT2].Int_State == ENABLED){
			GICR |= (1<<INT2_switch);

			switch(Copy_pu8GroupConfig[INT2].Sence_Level){

				case FALLING_EDGE:
					MCUCSR &= ~(1 << ISC2);

					break;

				case RISING_EDGE:

					MCUCSR |= (1 << ISC2);

					break;
			}


		}
		else if (Copy_pu8GroupConfig[INT2].Int_State == DISABLED){

			GICR &= ~(1<<INT2_switch);

		}
		/***************************************************/





		Local_enuErrorStatus = ERROR_STATUS_OK;
	}

	return Local_enuErrorStatus;
}


ErrorStatus_t EXTI_enuEnableInterrupt(uint8_t Copy_u8IntNumber){

	ErrorStatus_t Local_enuErrorStatus = ERROR_STATUS_FAILURE;

	if( (Copy_u8IntNumber > INT2)){
		return Local_enuErrorStatus;
	}

	else{

		switch(Copy_u8IntNumber){
		case INT0:

			GICR |= (1<<INT0_switch);
			break;

		case INT1:

			GICR |= (1<<INT1_switch);
			break;

		case INT2:
			GICR |= (1<<INT2_switch);

		}

		Local_enuErrorStatus = ERROR_STATUS_OK;
	}

	return Local_enuErrorStatus;
}


ErrorStatus_t EXTI_enuDisableInterrupt(uint8_t Copy_u8IntNumber){

	ErrorStatus_t Local_enuErrorStatus = ERROR_STATUS_FAILURE;

	if(Copy_u8IntNumber > INT2){
		return Local_enuErrorStatus;
	}

	else{

		switch(Copy_u8IntNumber){
		case INT0:

			GICR &= ~(1<<INT0_switch);
			break;

		case INT1:

			GICR &= ~(1<<INT1_switch);
			break;

		case INT2:

			GICR &= ~(1<<INT2_switch);
		}

		Local_enuErrorStatus = ERROR_STATUS_OK;
	}

	return Local_enuErrorStatus;
}


ErrorStatus_t EXTI_enuSetSenseLevel(uint8_t Copy_u8IntNumber,  uint8_t Copy_u8SenseLevel){

	ErrorStatus_t Local_enuErrorStatus = ERROR_STATUS_FAILURE;


	if( (Copy_u8IntNumber > INT2) || Copy_u8SenseLevel > RISING_EDGE){

		return Local_enuErrorStatus;
	}

	else{

		switch(Copy_u8IntNumber){
		case INT0:

			/**************** INT0 Sense_LEVEL ****************/
			switch(Copy_u8SenseLevel){
				case ANY_lOGICALCHANGE:

					MCUCCR |=  (1 << ISC00);
					MCUCCR &= ~(1 << ISC01);

					break;

				case LOW_LEVEL:

					MCUCCR &= ~(1 << ISC00);
					MCUCCR &= ~(1 << ISC01);

					break;

				case FALLING_EDGE:

					MCUCCR &= ~(1 << ISC00);
					MCUCCR |=  (1 << ISC01);

					break;

				case RISING_EDGE:

					MCUCCR |=  (1 << ISC00);
					MCUCCR |=  (1 << ISC01);

					break;
			}

			break;
			/**************************************************/

		case INT1:

			/**************** INT1 Sense_LEVEL ****************/
			switch(Copy_u8SenseLevel){
			case ANY_lOGICALCHANGE:

				MCUCCR |=   (1 << ISC10);
				MCUCCR &=  ~(1 << ISC11);

				break;

			case LOW_LEVEL:

				MCUCCR &=  ~(1 << ISC10);
				MCUCCR &=  ~(1 << ISC11);

				break;

			case FALLING_EDGE:

				MCUCCR &=  ~(1 << ISC10);
				MCUCCR |=   (1 << ISC11);

				break;

			case RISING_EDGE:

				MCUCCR |=  (1 << ISC10);
				MCUCCR |=  (1 << ISC11);

				break;
			}

			break;
			/**************************************************/



		case INT2:

			/**************** INT2 Sense_LEVEL ****************/
			switch(Copy_u8SenseLevel){

				case FALLING_EDGE:
					MCUCSR &= ~(1 << ISC2);

					break;

				case RISING_EDGE:

					MCUCSR |= (1 << ISC2);

					break;
			}

			/**************************************************/
		}


		Local_enuErrorStatus = ERROR_STATUS_OK;
	}


	return Local_enuErrorStatus;
}


ErrorStatus_t EXTI_enuCallBack( void (*Copy_pfunAppFun)(void), uint8_t Copy_u8IntNumber){

	ErrorStatus_t Local_enuErrorStatus = ERROR_STATUS_FAILURE;


	if( (Copy_pfunAppFun == NULL ) ){


		Local_enuErrorStatus = ERROR_STATUS_NULL_POINTER;
		return Local_enuErrorStatus;
	}

	else if(Copy_u8IntNumber > INT2){

		Local_enuErrorStatus = ERROR_OUT_OF_RANGE;
		return Local_enuErrorStatus;
	}

	else{
		EXTI_pfunISRFun[Copy_u8IntNumber] = Copy_pfunAppFun;
	}


	Local_enuErrorStatus = ERROR_STATUS_OK;
	return Local_enuErrorStatus;
}


ISR(INT0_vect){

		if(EXTI_pfunISRFun[INT0] != NULL){
			EXTI_pfunISRFun[INT0]();
		}
}

ISR(INT1_vect){

		if(EXTI_pfunISRFun[INT1] != NULL){
			EXTI_pfunISRFun[INT1]();
		}
}


ISR(INT2_vect){

		if(EXTI_pfunISRFun[INT2] != NULL){
			EXTI_pfunISRFun[INT2]();
		}
}
