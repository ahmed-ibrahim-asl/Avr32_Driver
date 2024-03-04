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

void ADC_enuInit();




ErrorStatus_t ADC_enuStartConversion(ADC_Channel_types ADC_channel_N);
uint16 ADC_GetResult();




#define ADC_enuEnableInterrupt()	SET_BIT(ADCSRA_REG, ADCSRA_ADIE)



ErrorStatus_t ADC_enuSetCallBack(void(*Copy_pfunAppFun)(void), uint8_t Copy_u8IntNumber);






#endif /* MCAL_ADC_ADC_INITERFACE_H_ */
