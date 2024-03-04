/*
 * ADC_init.h
 *
 *  Created on: Feb 27, 2024
 *      Author: ad
 */

#ifndef MCAL_ADC_ADC_INITERFACE_H_
#define MCAL_ADC_ADC_INITERFACE_H_

/*************** Include Section Start ********************/
#include "../DIO/helper_embedded_libraries/micro_config.h"
#include "ADC_priv.h"
/**********************************************************/




//uint8_t resolutionBits, uint32_t maxVoltageMicrovolts

void ADC_enuInit(uint8_t Copy_u8ResolutionBits, uint32_t Copy_u32MaxVoltage_MicroVolts);




ErrorStatus_t ADC_enuStartConversion(ADC_Channel_types ADC_channel_N);
uint16 ADC_GetResult();




#define ADC_enuEnableInterrupt()	SET_BIT(ADCSRA_REG, ADCSRA_ADIE)



ErrorStatus_t ADC_enuSetCallBack(void(*Copy_pfunAppFun)(void), uint8_t Copy_u8IntNumber);




//!!!!!! For Fun (this for ADC_MODE_SINGLE_CONVERSION)
#if ADC_MODE_SELECTOR == ADC_MODE_SINGLE_CONVERSION


	uint16 ADC_analogRead(ADC_Channel_types ADC_channel_N);

//	uint16 ADC_analogRead(ADC_Channel_types ADC_channel_N);

#endif


#endif /* MCAL_ADC_ADC_INITERFACE_H_ */
