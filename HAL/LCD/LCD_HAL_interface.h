/*
 * LCD_HAL_interface.h
 *
 *  Created on: Jan 5, 2024
 *      Author: ad
 */

#ifndef HAL_LCD_HAL_INTERFACE_H_
#define HAL_LCD_HAL_INTERFACE_H_

///*************** Include Section Start ********************/
//#include "LCD_HAL_config.h"
///**********************************************************/

ErrorStatus_t LCD_enuInit(void);

ErrorStatus_t LCD_enuSendData(uint8_t Copy_u8Data);
ErrorStatus_t LCD_enuSendCommand(uint8_t Copy_u8Command);

ErrorStatus_t LCD_u8SendString(const char *Copy_pu8String);

ErrorStatus_t LCD_enuClearDisplay(void);


#define LCD_enuClearDisplay() LCD_enuSendCommand(1);


ErrorStatus_t LCD_enuIntegerToString(sint32_t Copy_u8data, uint8_t Copy_u8Base);




ErrorStatus_t LCD_u8SetPosXY(uint8_t copy_u8PosX, uint8_t copy_u8PosY);

//3. ErrorStatus_t LCD_enuDisplayAtXY(
//	 uint8_t Copy_u8Column,
//	 uint8_t Copy_u8Row,
//	 const uint8_t* Copy_u8String)

//4. Display weird characters

#endif /* HAL_LCD_HAL_INTERFACE_H_ */
