/*
 * GLCDKS0108_Interface.h
 *
 *  Created on: Nov 7, 2024
 *      Author: ad
 */

#ifndef HAL_GLCDKS0108_GLCDKS0108_INTERFACE_H_
#define HAL_GLCDKS0108_GLCDKS0108_INTERFACE_H_

/************************ Include Section ************************/
#include "../../MCAL/DIO/DIO_interface.h"
#include <avr/pgmspace.h>
/*****************************************************************/

void GLCDKS0108_Init(void);

/* Clear the entire display */
void GLCDKS0108_ClearAll(void);

/* Display a single character at specified page and column */
void GLCDKS0108_DisplayChar(uint8_t copy_u8Page, uint8_t copy_u8Column, uint8_t copy_u8Character);

/* Display a string starting from specified page and column */
void GLCDKS0108_DisplayString(uint8_t copy_u8Page, uint8_t copy_u8Column, const uint8_t * copy_pu8str);

#endif /* HAL_GLCDKS0108_GLCDKS0108_INTERFACE_H_ */
