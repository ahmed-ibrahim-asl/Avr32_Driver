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
//	ErrorStatus_t Local_enuErrorState = TWI_enuInit();

	TWI_enuInit();
	return 1;
}



ErrorStatus_t EEPROM_enuWriteData(EEPROM_Input_t* eepromInstance){
	ErrorStatus_t Local_enuErrorState = ERROR_STATUS_FAILURE;

	///////////////////////////////////////////////////////////////////////////////////////////////
	uint8_t Local_u8Address = (0xA0) | (EEPROM_A2_STATE<<2) | (eepromInstance->A1 << 1) | (eepromInstance->A0)| 0x00;
	uint8_t Local_u8ByteAddress = eepromInstance->address;
	///////////////////////////////////////////////////////////////////////////////////////////////

	if(TWI_enuStartCondition() == TWI_STATUS_OK){
		TWI_enuSetSlaveOperation(Local_u8Address, TWI_WriteOperation);
		TWI_enuWriteData(Local_u8ByteAddress);


		TWI_enuRepeatStartCondition();

		TWI_enuWriteData(eepromInstance->data);
		TWI_enuStopCondition();


	}


	Local_enuErrorState = ERROR_STATUS_OK;
	return Local_enuErrorState;
}



ErrorStatus_t EEPROM_enuReadData(EEPROM_Input_t* eepromInstance){
	ErrorStatus_t Local_enuErrorState = ERROR_STATUS_FAILURE;


	//To Ensure any residual data from a previous write operation will be cleared
	eepromInstance->data = 0;

	///////////////////////////////////////////////////////////////////////////////////////////////
	uint8_t Local_u8Address = (0xA0) | (EEPROM_A2_STATE<<2) | ((eepromInstance->A1) << 1) | (eepromInstance->A0)| 0x01;
	uint8_t Local_u8ByteAddress = eepromInstance->address;
	///////////////////////////////////////////////////////////////////////////////////////////////


	if(TWI_enuStartCondition() == TWI_STATUS_OK){

		TWI_enuSetSlaveOperation(Local_u8Address, TWI_WriteOperation);

		TWI_enuWriteData(Local_u8ByteAddress);

		if(TWI_enuRepeatStartCondition() == TWI_STATUS_OK){
			TWI_enuSetSlaveOperation(Local_u8Address, TWI_ReadOperation);
			TWI_enuReadData(&(eepromInstance->data));
			TWI_enuStopCondition();
		}
	}


	Local_enuErrorState = ERROR_STATUS_OK;
	return Local_enuErrorState;
}
