/*
 * EEPROM_interface.h
 *
 *  Created on: May 28, 2024
 *      Author: ad
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_


/********************** Include  Section **********************/
#include "../../MCAL/DIO/helper_embedded_libraries/micro_config.h"
#include "../../MCAL/TWI/TWI_interface.h"
#include "EEPROM_config.h"
#include "EEPROM_priv.h"
/**************************************************************/


typedef struct{


	#if(EEPROM_TYPE == EEPROM_EIGHT_KBIT)
		uint8_t address;     // Address within the EEPROM
		uint8_t A1: 1;
		uint8_t A0: 1;
        uint8_t   : 6;       // 6-bit padding


		uint8_t data;        // Data to be written or read
	#endif

}EEPROM_Input_t;




ErrorStatus_t EEPROM_enuInit(void);

//ErrorStatus_t EEPROM_enuWriteData(uint16 copy_u16Address, uint8_t copy_u8Data);


ErrorStatus_t EEPROM_enuWriteData(EEPROM_Input_t* eepromInstance);


ErrorStatus_t EEPROM_enuReadData(EEPROM_Input_t* eepromInstance);




#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
