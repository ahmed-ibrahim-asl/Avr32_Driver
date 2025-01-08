/*
 * GLCDKS0108_private.h
 *
 *  Created on: Nov 7, 2024
 *      Author: ad
 */

#ifndef HAL_GLCDKS0108_GLCDKS0108_PRIVATE_H_
#define HAL_GLCDKS0108_GLCDKS0108_PRIVATE_H_

/************************ Include Section ************************/
#include "GLCKS0108_config.h"
/*****************************************************************/



/********************** Internal functions ***********************/
static void GLCDKS0108_SendCommand(uint8_t copy_u8Command);
static void GLCDKS0108_SendData(uint8_t copy_u8Data);
static void GLCDKS0108_SelectChip(uint8_t copy_u8Chip);
/*****************************************************************/



/* GLCD Command Macros */
#define GLCDKS0108_DISPLAY_OFF   0x3E  /* Turn display OFF */
#define GLCDKS0108_DISPLAY_ON    0x3F  /* Turn display ON */
#define GLCDKS0108_SET_Y_ADDRESS 0x40  /* Set Y address (column=0) */
#define GLCDKS0108_SET_X_ADDRESS 0xB8  /* Set X address (page=0) */
#define GLCDKS0108_SET_Z_ADDRESS 0xC0  /* Set Z address (start line=0) */



/* Font data */
extern const uint8_t GLCD_CharacterSet[][GLCD_FONT_WIDTH];

#endif /* HAL_GLCDKS0108_GLCDKS0108_PRIVATE_H_ */
