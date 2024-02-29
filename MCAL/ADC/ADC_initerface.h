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






void ADC_enuInit(void);

ErrorStatus_t ADC_enuStartConversion(ADC_Channel_types ADC_channel_N);

uint16 ADC_GetResult();


//ErrorStatus_t ADC_GetResult(uint16_t* ADCResult);





#endif /* MCAL_ADC_ADC_INITERFACE_H_ */
