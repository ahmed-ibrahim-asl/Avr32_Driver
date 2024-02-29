/*
 * ADC_priv.h
 *
 *  Created on: Feb 27, 2024
 *      Author: ad
 */

#ifndef MCAL_ADC_ADC_PRIV_H_
#define MCAL_ADC_ADC_PRIV_H_


/********************************** General Macros **********************************/
#define ADMUX_REG	*((volatile uint8_t*) (0x27))
#define ADCSRA_REG	*((volatile uint8_t*) (0x26))
#define ADCH_REG	*((volatile uint8_t*) (0x25))
#define ADCL_REG	*((volatile uint8_t*) (0x24))
#define SFIOR_REG	*((volatile uint8_t*) (0x50))


//! [we can #define configure]
//! To read Lower and Higher (For Right Adjustment only)

/* ADC Adjustment Selection */
#define ADC_RIGHT_ADJUSTED						0
#define ADC_LEFT_ADJUSTED						1


/* ADC Mode Select */
#define ADC_MODE_AUTO_TRIGGER 					1
#define ADC_MODE_SINGLE_CONVERSION				0




#if ADC_ADJUSTMENT_SELECTOR == ADC_RIGHT_ADJUSTED
	#define ADCLH_REG	*((volatile uint16*) (0x24))
#endif
/************************************************************************************/



/********************************* ADMUX bits Names *********************************/
#define ADMUX_REFS1								7
#define ADMUX_REFS0								6
#define ADMUX_ADLAR								5
#define ADMUX_MUX4								4
#define ADMUX_MUX3								3
#define ADMUX_MUX2								2
#define ADMUX_MUX1								1
#define ADMUX_MUX0								0
/************************************************************************************/


/******************************** ADCSRA  bits Names ********************************/
#define ADCSRA_ADEN								7
#define ADCSRA_ADSC								6
#define ADCSRA_ADATE							5
#define ADCSRA_ADIF								4
#define ADCSRA_ADIE								3
#define ADCSRA_ADPS2							2
#define ADCSRA_ADPS1							1
#define ADCSRA_ADPS0							0
/************************************************************************************/



/*************************** Voltage  Reference Selection ***************************/
//! we going with this method in case in some how you want
//! to go crazy and change the configuration while running application
#define ADC_VOLTAGE_REF_clr_msk				    0b00111111
#define ADC_VOLTAGE_REF_AVCC					0b01000000
#define ADC_VOLTAGE_REF_AREF					0b10000000
#define ADC_VOLTAGE_REF_2_56v					0b11000000
/************************************************************************************/



// Presclaer select
#define ADC_PRESCALER_clr_msk					0b11111000
#define ADC_PRESCALER_2_msk						0b00000000
#define ADC_PRESCALER_4_msk						0b00000010
#define ADC_PRESCALER_8_msk 					0b00000011

#define ADC_PRESCALER_16_msk 					0b00000100
#define ADC_PRESCALER_32_msk 					0b00000101
#define ADC_PRESCALER_64_msk 					0b00000110
#define ADC_PRESCALER_128_msk 					0b00000111
/****************************************************************/
// ADC auto trigger select

#define ADC_AUTO_TRIG_SRC_clr_msk				0b00011111
#define ADC_AUTO_TRIG_SRC_FREE_RUNNING_msk		0b00000000
#define ADC_AUTO_TRIG_SRC_ANALOG_COMP_msk		0b00100000

#define ADC_AUTO_TRIG_SRC_EXTI0_msk				0b01000000
#define ADC_AUTO_TRIG_SRC_TIMER0_COMP_msk		0b01100000
#define ADC_AUTO_TRIG_SRC_TIMER0_OVF_msk		0b10000000

#define ADC_AUTO_TRIG_SRC_TIMER1_COMP_msk		0b10100000
#define ADC_AUTO_TRIG_SRC_TIMER1_OVF_msk		0b11000000
#define ADC_AUTO_TRIG_SRC_TIMER1_CAPT_msk		0b11100000


typedef enum{
	ADC_Channel_0,			// 0b000	00000
	ADC_Channel_1,			// 0b000	00001
	ADC_Channel_2,			// 0b000	00010
	ADC_Channel_3,			// 0b000 	00011
	ADC_Channel_4,			// 0b000	00100
	ADC_Channel_5,			// 0b000	00101
	ADC_Channel_6,			// 0b000	00110
	ADC_Channel_7			// 0b000	00111

}ADC_Channel_types;


#define ADC_CHANNEL_SELECTOR_clr_msk			0b11100000


#endif /* MCAL_ADC_ADC_PRIV_H_ */
