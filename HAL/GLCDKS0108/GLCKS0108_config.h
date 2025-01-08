/*
 * GLCKS0108_config.h
 *
 *  Created on: Nov 7, 2024
 *      Author: ad
 */

#ifndef HAL_GLCDKS0108_GLCKS0108_CONFIG_H_
#define HAL_GLCDKS0108_GLCKS0108_CONFIG_H_


/* Include necessary headers */
#include "../../MCAL/DIO/DIO_interface.h"
#include <util/delay.h>

/* Define your CPU frequency if not defined elsewhere */
#ifndef F_CPU
#define F_CPU 16000000UL
#endif



/* Define data and control ports */
#define GLCDKS0108_DATA_PORT      PORTA
#define GLCDKS0108_DATA_DDR       DDRA


//////////////////////////////////////////////////////////
/* Define control pins based on your connections */
#define GLCDKS0108_RS_PORT			DIO_u8PortB
#define GLCDKS0108_RS_PIN         	DIO_u8PIN2   /* DI - Data/Instruction (Register Select) */

#define GLCDKS0108_RW_PORT			DIO_u8PortB
#define GLCDKS0108_RW_PIN         	DIO_u8PIN1   /* R/W - Read/Write */

#define GLCDKS0108_EN_PORT			DIO_u8PortB
#define GLCDKS0108_EN_PIN         	DIO_u8PIN0   /* E - Enable */

#define GLCDKS0108_CS1_PORT			DIO_u8PortB
#define GLCDKS0108_CS1_PIN     		DIO_u8PIN4   /* CS1 - Chip Select 1 */

#define GLCDKS0108_CS2_PORT			DIO_u8PortB
#define GLCDKS0108_CS2_PIN    	    DIO_u8PIN5   /* CS2 - Chip Select 2 */

#define GLCDKS0108_RST_PORT		DIO_u8PortB
#define GLCDKS0108_RST_PIN        DIO_u8PIN6      /* RST - Reset */

/* Define display size */
#define GLCDKS0108_WIDTH          128  /* Options: 128, 192 */
#define GLCDKS0108_HEIGHT         64

/* Number of chips (1 chip per 64 pixels width) */
#if GLCDKS0108_WIDTH == 128
	#define GLCD_NUM_CHIPS      2

#elif GLCDKS0108_WIDTH == 192
	#define GLCD_NUM_CHIPS      3

#else
	#error "Unsupported GLCD width!"
#endif

/* Font width in pixels */
#define GLCD_FONT_WIDTH     5

#endif /* HAL_GLCDKS0108_GLCKS0108_CONFIG_H_ */
