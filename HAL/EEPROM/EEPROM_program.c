/*
 * EEPROM_program.c
 *
 *  Created on: May 28, 2024
 *      Author: ad
 */


/********************** Include  Section **********************/
#include "../../MCAL/DIO/helper_embedded_libraries/micro_config.h"


#include "EEPROM_interface.h"
/**************************************************************/



ErrorStatus_t EEPROM_enuInit(void){
	ErrorStatus_t Local_enuErrorState = TWI_enuInit();

	return Local_enuErrorState;
}


ErrorStatus_t EEPROM_enuWriteData(EEPROM_Input_t* eepromInstance) {
    ErrorStatus_t Local_enuErrorState = ERROR_STATUS_FAILURE;


	#if(EEPROM_TYPE == EEPROM_NM24C04 || EEPROM_TYPE == EEPROM_NM24C04F )

    	uint8_t	Local_u8Address = (0xA0) | (eepromInstance->A2 << 3) | (eepromInstance->A1 << 2) | (eepromInstance->A0);

	#elif(EEPROM_TYPE == EEPROM_NM24C05 || EEPROM_TYPE == EEPROM_NM24C05F )

    	uint8_t	Local_u8Address = (0xA0) | (eepromInstance->A2 << 3) | (eepromInstance->A1 << 2) | (eepromInstance->A0);

	#elif(EEPROM_TYPE == EEPROM_NM24C08 || EEPROM_TYPE == EEPROM_NM24C08F )

		uint8_t	Local_u8Address = (0xA0) | (eepromInstance->A2 << 2) | (eepromInstance->A1 << 1) | (eepromInstance->A0);

	#elif(EEPROM_TYPE == EEPROM_NM24C09 || EEPROM_TYPE == EEPROM_NM24C09F )

		uint8_t Local_u8Address = (0xA0) | (EEPROM_A2_STATE << 2);

	#else
		#error "Unsupported EEPROM type!"
	#endif


    // Send start condition
    if( TWI_enuStartCondition() == TWI_STATUS_OK){

		// Send EEPROM address with write operation
		TWI_enuWriteData(Local_u8Address | TWI_WriteOperation);

		// Send memory address within EEPROM
		TWI_enuWriteData(eepromInstance->address);

		// Write data to EEPROM
		TWI_enuWriteData(eepromInstance->data);

		// Send stop condition
		TWI_enuStopCondition();

    }

    Local_enuErrorState = ERROR_STATUS_OK;
    return Local_enuErrorState;
}


ErrorStatus_t EEPROM_enuReadData(EEPROM_Input_t* eepromInstance) {
    ErrorStatus_t Local_enuErrorState = ERROR_STATUS_FAILURE;

    eepromInstance->data = 0;

	#if(EEPROM_TYPE == EEPROM_NM24C04 || EEPROM_TYPE == EEPROM_NM24C04F )

		uint8_t	Local_u8Address = (0xA0) | (eepromInstance->A2 << 3) | (eepromInstance->A1 << 2) | (eepromInstance->A0);

	#elif(EEPROM_TYPE == EEPROM_NM24C05 || EEPROM_TYPE == EEPROM_NM24C05F )

		uint8_t	Local_u8Address = (0xA0) | (eepromInstance->A2 << 3) | (eepromInstance->A1 << 2) | (eepromInstance->A0);

	#elif(EEPROM_TYPE == EEPROM_NM24C08 || EEPROM_TYPE == EEPROM_NM24C08F )

		uint8_t	Local_u8Address = (0xA0) | (eepromInstance->A2 << 2) | (eepromInstance->A1 << 1) | (eepromInstance->A0);

	#elif(EEPROM_TYPE == EEPROM_NM24C09 || EEPROM_TYPE == EEPROM_NM24C09F )

		uint8_t Local_u8Address = (0xA0) | (EEPROM_A2_STATE << 2);

	#else
		#error "Unsupported EEPROM type!"
	#endif


	#if( EEPROM_TYPE == EEPROM_NM24C09 || EEPROM_TYPE == EEPROM_NM24C09F )
		uint8_t Local_u8Address = (0xA0) | (EEPROM_A2_STATE << 2);
	#endif

	// Send start condition
    if( TWI_enuStartCondition() == TWI_STATUS_OK){

		// Send EEPROM address with write operation
		TWI_enuWriteData(Local_u8Address);

		// Send memory address within EEPROM
		TWI_enuWriteData(eepromInstance->address);

		// Send repeated start condition
		TWI_enuStartCondition();

		// Send EEPROM address with read operation
		TWI_enuWriteData(Local_u8Address | TWI_ReadOperation);

		// Read data from EEPROM
		TWI_enuReadData(&(eepromInstance->data));

		// Send stop condition
		TWI_enuStopCondition();

    }

    Local_enuErrorState = ERROR_STATUS_OK;
    return Local_enuErrorState;
}
