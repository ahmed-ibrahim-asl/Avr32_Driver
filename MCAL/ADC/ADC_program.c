/*
 * ADC_program.c
 *
 *  Created on: Feb 27, 2024
 *      Author: ad
 */


/********************************* Include  Section *********************************/
#include "ADC_initerface.h"
#include "ADC_config.h"
/************************************************************************************/


void ADC_enuInit(void){


	/**
	 * Initialization steps:
	 * 1. Selecting voltage reference
	 * 2. Selecting ADC MODE!
	 * 3. Selecting Adjustment
	 * 4. clearing interrupt flag
	 * 5. enabling ADC
	 * */


	/*************************** Selecting  voltage reference ***************************/
		ADMUX_REG &= ADC_AUTO_TRIG_SRC_clr_msk;
		ADMUX_REG |= ADC_VOLTAGE_REF_SELECTOR_msk;
	/************************************************************************************/


	/******************************** Selecting ADC MODE ********************************/
		#if ADC_MODE_SELECTOR == ADC_MODE_AUTO_TRIGGER
			SET_BIT(ADCSRA_REG, ADCSRA_ADATE);

			SFIOR_REG &= ADC_AUTO_TRIG_SRC_clr_msk;
			SFIOR_REG |= ADC_AUTO_TRIG_SRCE_SELECTOR;


		#elif ADC_MODE_SELECTOR == ADC_MODE_SINGLE_CONVERSION
			CLR_BIT(ADCSRA_REG, ADCSRA_ADATE);
		#endif
	/************************************************************************************/


	/******************************* Selecting Adjustment *******************************/
		#if	ADC_ADJUSTMENT_SELECTOR == ADC_RIGHT_ADJUSTED
			CLR_BIT(ADMUX_REG, ADMUX_ADLAR);
		#endif

		#if	ADC_ADJUSTMENT_SELECTOR == ADC_LEFT_ADJUSTED
			SET_BIT(ADMUX_REG, ADMUX_ADLAR);
		#endif
	/************************************************************************************/



	/***************************** Clearing  Interrupt Flag *****************************/
		//! Notice: that ADIF to be cleared we write logical one (from data sheet)
		//So in initialization of ADC we write 1 to ADIF bit to make sure that the
		//flag is cleared in order to make sure that ADC ready for upcoming conversation
		// clearing interrupt flag
		SET_BIT(ADCSRA_REG, ADCSRA_ADIF);
	/************************************************************************************/


	/*********************************** Enabling ADC ***********************************/
		SET_BIT(ADCSRA_REG, ADCSRA_ADEN);
	/************************************************************************************/
}




ErrorStatus_t ADC_enuStartConversion(ADC_Channel_types ADC_channel_N){
	ErrorStatus_t Local_enuErrrorState = ERROR_STATUS_FAILURE;


	/******************************** Select ADC Channel ********************************/
	ADMUX_REG &= ADC_CHANNEL_SELECTOR_clr_msk;
	ADMUX_REG |= ADC_channel_N;
	/************************************************************************************/


	/******************************* ADC Start Conversion *******************************/
	SET_BIT(ADCSRA_REG, ADCSRA_ADSC);
	/************************************************************************************/

	return Local_enuErrrorState;
}



uint16 ADC_GetResult(){
//	uint16 * Copy_pu16ReadValue;

	while(GET_BIT(ADCSRA_REG, ADCSRA_ADSC));

	return ADCLH_REG;
}




