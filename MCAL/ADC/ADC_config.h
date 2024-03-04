/*
 * ADC_config.h
 *
 *  Created on: Feb 27, 2024
 *      Author: ad
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_


/**
 * -Configure the voltage reference:	(macroName: ADC_VOLTAGE_REF_SELECTOR_msk)
 *
 * 1. ADC_VOLTAGE_REF_AVCC
 * 2. ADC_VOLTAGE_REF_AREF
 * 3. ADC_VOLTAGE_REF_2_56v
 *
 * #############################################################################
 * -Configuration the ADC Mode:			(macroName: ADC_MODE_SELECTOR)
 *
 * 1. ADC_MODE_AUTO_TRIGGER
 * 2. ADC_MODE_SINGLE_CONVERSION
 *
 * #############################################################################
 * -Configuration the ADC adjustment	(macroName: ADC_ADJUSTMENT_SELECTOR)
 * 1. ADC_RIGHT_ADJUSTED
 * 2. ADC_LEFT_ADJUSTED
 *
 * #############################################################################
 * -Configure the ADC prescaler			(macroName: ADC_PRESCALER_SELECTOR_msk)
 *
 * 1. ADC_PRESCALER_2_msk
 * 2. ADC_PRESCALER_4_msk
 * 3. ADC_PRESCALER_8_msk
 * 4. ADC_PRESCALER_16_msk
 * 5. ADC_PRESCALER_32_msk
 * 6. ADC_PRESCALER_64_msk
 * 7. ADC_PRESCALER_128_msk
 *
 * #############################################################################
 * -Auto Trigger Source Selector:
 *1. ADC_AUTO_TRIG_SRC_FREE_RUNNING_msk
 *2. ADC_AUTO_TRIG_SRC_ANALOG_COMP_msk
 *3. ADC_AUTO_TRIG_SRC_EXTI0_msk
 *4. ADC_AUTO_TRIG_SRC_TIMER0_COMP_msk
 *5. ADC_AUTO_TRIG_SRC_TIMER0_OVF_msk
 *6. ADC_AUTO_TRIG_SRC_TIMER1_COMP_msk
 *7. ADC_AUTO_TRIG_SRC_TIMER1_OVF_msk
 *8. ADC_AUTO_TRIG_SRC_TIMER1_CAPT_msk
 *
 * */

#define ADC_VOLTAGE_REF_SELECTOR_msk	ADC_VOLTAGE_REF_AVCC

#define ADC_MODE_SELECTOR				ADC_MODE_SINGLE_CONVERSION

#define ADC_PRESCALER_SELECTOR_msk		ADC_PRESCALER_128_msk

#define ADC_AUTO_TRIG_SRCE_SELECTOR		ADC_AUTO_TRIG_SRC_FREE_RUNNING_msk


#define ADC_ADJUSTMENT_SELECTOR			ADC_RIGHT_ADJUSTED




#endif /* MCAL_ADC_ADC_CONFIG_H_ */
