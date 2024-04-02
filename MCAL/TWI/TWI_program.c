/*
 * TWI_program.c
 *
 *  Created on: Mar 30, 2024
 *      Author: ad
 */

/**************************** Include  Section ****************************/
#include "../DIO/helper_embedded_libraries/micro_config.h"
#include "../DIO/DIO_interface.h"
#include "../GIE/GIE_interface.h"

#include "TWI_interface.h"
#include "TWI_config.h"
#include "TWI_priv.h"


#include <util/delay.h>

/**************************************************************************/

void TWI_enuInit(void){


	#if(TWI_MODE_M_or_S == TWI_MASTER_MODE)
		// Set Value for Bit Rate            (should only be when we working with master)
		TWBR_REG = TWBR_VALUE;
	#endif


	// Enable TWI Interrupt
	GIE_enuEnable();
	SET_BIT(TWCR_REG, TWCR_TWIE);


	// Enable TWI Peripheral
	SET_BIT(TWCR_REG, TWCR_TWEN);


	#if(TWI_ACK_CONFIG == TWI_ACK_ENABLE)
		SET_BIT(TWCR_REG, TWCR_TWEA);

	#elif(TWI_ACK_CONFIG == TWI_ACK_DISABLE)
		CLR_BIT(TWCR_REG, TWCR_TWEA);

	#endif



	#if(TWI_GCE_CONFIG == TWI_GCE_ENABLE)
		SET_BIT(TWAR_REG, TWAR_TWGCE);

	#elif(TWI_GCE_CONFIG == TWI_GCE_DISABLE)
		CLR_BIT(TWAR_REG, TWAR_TWGCE);

	#endif


   // Set Address for MC
   TWAR_REG = (TWAR_REG&0x01)  | TWI_SET_ADDR;
}



TWIStatus_t TWI_enuStartCondition(void){
	TWIStatus_t	  Local_enu_ErrorState = TWI_STATUS_FAILURE;

	// Start condition
	SET_BIT(TWCR_REG, TWCR_TWSTA);


	// Clearing the TWINT flag is part of initiating an operation on the TWI.
	SET_BIT(TWCR_REG, TWCR_TWINT);


	// Wait for TWINT Flag set. This indicates that the START condition has been transmitted.
	while(!(GET_BIT(TWCR_REG, TWCR_TWINT)));


	/*
	 * S7 S6 S5 S4 S3 - PS1 PS2
	 * 1  1  1  1  {1 0 0   0}
	 *
	 * 0xF8
	 * */

	if( (TWSR_REG &0xF8) == 0x08){
		Local_enu_ErrorState = TWI_STATUS_OK;
	}


	return Local_enu_ErrorState;
}

TWIStatus_t TWI_enuRepeatStartCondition(void){
	TWIStatus_t	  Local_enu_ErrorState = TWI_STATUS_FAILURE;

	// Start condition
	SET_BIT(TWCR_REG, TWCR_TWSTA);


	// Clearing the TWINT flag is part of initiating an operation on the TWI.
	SET_BIT(TWCR_REG, TWCR_TWINT);


	// Wait for TWINT Flag set. This indicates that the START condition has been transmitted.
	while(!(GET_BIT(TWCR_REG, TWCR_TWINT)));


	/*
	 * S7 S6 S5 S4 S3 - PS1 PS2
	 * 1  1  1  1  {1 0 0   0}
	 *
	 * 0xF8
	 * */


	if( (TWSR_REG &0xF8) == TWI_RSTART_SUCCESS_CODE){
		Local_enu_ErrorState = TWI_STATUS_OK;

	}

	return Local_enu_ErrorState;
}


//! since there no status code why not doing macro like function
// IDEAS for feature development
TWIStatus_t TWI_enuStopCondition(void){
	TWIStatus_t	  Local_enu_ErrorState = TWI_STATUS_FAILURE;


	// Clearing the TWINT flag is part of initiating an operation on the TWI.
	SET_BIT(TWCR_REG, TWCR_TWINT);

	// Stop Condition
	SET_BIT(TWCR_REG, TWCR_TWSTO);



	Local_enu_ErrorState = TWI_STATUS_OK;
	return Local_enu_ErrorState;
}


TWIStatus_t TWI_enuSetSlaveOperation(
		uint8_t copy_u8SlaveAddress, uint8_t copy_u8Operation){

	TWIStatus_t	  Local_enu_ErrorState = TWI_STATUS_FAILURE;


	TWDR_REG = (copy_u8SlaveAddress<<1) | (copy_u8Operation);

	// Since we should have already send START condition
	// we have to clear TWSTA
	CLR_BIT(TWCR_REG, TWCR_TWSTA);


	// Clearing the TWINT flag is part of initiating an operation on the TWI.
	SET_BIT(TWCR_REG, TWCR_TWINT);

	// Wait for TWINT Flag is set. Waiting for current operation to be done
	while(!(GET_BIT(TWCR_REG, TWCR_TWINT)));


    // Check for operation success based on requested operation
    if(copy_u8Operation == TWI_SLA_WR_ACK_TSUCCESS_CODE ){
        Local_enu_ErrorState = TWI_STATUS_OK;


    } else if(copy_u8Operation == TWI_SLA_RD_ACK_TSUCCESS_CODE ){
        Local_enu_ErrorState = TWI_STATUS_OK;

    }


	return Local_enu_ErrorState;
}


TWIStatus_t	TWI_enuWriteData(uint8_t copy_u8Data){
	TWIStatus_t	  Local_enu_ErrorState = TWI_STATUS_FAILURE;

	TWDR_REG = copy_u8Data;

	// Clearing the TWINT flag is part of initiating an operation on the TWI.
	SET_BIT(TWCR_REG, TWCR_TWINT);

	// Wait for TWINT Flag is set. Waiting for current operation to be done
	while(!(GET_BIT(TWCR_REG, TWCR_TWINT)));



	// 0x28 -(master) data byte has been transmitted ack has been received
	// 0xB8	- (slave) data byte has been transmitted ack has been received
	if( ((TWSR_REG & 0xF8) != TWI_M_TSUCCESS_CODE_withACK) || ((TWSR_REG & 0xF8) != TWI_S_TSUCCESS_CODE_withACK) ){
		return Local_enu_ErrorState;
	}


	if( (TWSR_REG & 0xF8) == TWI_M_TSUCCESS_CODE_withACK ){
		Local_enu_ErrorState = TWI_STATUS_OK;
	}

	else if((TWSR_REG & 0xF8) == TWI_S_TSUCCESS_CODE_withACK){
		Local_enu_ErrorState = TWI_STATUS_OK;
	}


	return Local_enu_ErrorState;
}



TWIStatus_t	TWI_enuReadData(uint8_t  *copy_pu8Data){
	TWIStatus_t	  Local_enu_ErrorState = TWI_STATUS_FAILURE;

	// Clearing the TWINT flag is part of initiating an operation on the TWI.
	SET_BIT(TWCR_REG, TWCR_TWINT);

	// Wait for TWINT Flag is set. Waiting for current operation to be done
	while(!(GET_BIT(TWCR_REG, TWCR_TWINT)));


	// 0x50 - (master) data byte has been received ack has been returned
	// 0x58 - (master) data byte has been received not ack has been returned


	// 0x80 - (slave)  data has been received ack has been returned
	// 0x88 - (slave)  data has been received not ack has been returned

	#if(TWI_ACK_CONFIG == TWI_ACK_ENABLE)

		// Master Receive
		if( ((TWSR_REG & 0xF8) == TWI_M_RSUCCESS_CODE_withAck) ){
			Local_enu_ErrorState = TWI_STATUS_OK;

		}

		// Slave Receive
		else if(((TWSR_REG & 0xF8) == TWI_S_RSUCCESS_CODE_withACK)){
			Local_enu_ErrorState = TWI_STATUS_OK;

		}

	#elif(TWI_ACK_CONFIG == TWI_ACK_DISABLE)
		// Master Receive
		if( ((TWSR_REG & 0xF8) == TWI_M_RSUCCESS_CODE_withAck) ){
			Local_enu_ErrorState = TWI_STATUS_OK;
		}

		// Slave Receive
		else if(((TWSR_REG & 0xF8) == TWI_S_RSUCCESS_CODE_withoutACK)){
			Local_enu_ErrorState = TWI_STATUS_OK;
		}
	#endif

	// Read data from TWDR Register
	*copy_pu8Data = TWDR_REG;

	return Local_enu_ErrorState;
}


ErrorStatus_t TWI_enuCheckMyAddress(void){
	TWIStatus_t	  Local_enu_ErrorState = TWI_STATUS_FAILURE;


	// Clearing the TWINT flag is part of initiating an operation on the TWI.
	SET_BIT(TWCR_REG, TWCR_TWINT);

	// Wait for TWINT Flag is set. Waiting for current operation to be done
	while(!(GET_BIT(TWCR_REG, TWCR_TWINT)));


	// 0x60 - SLA+W has been received, ACK has been returned
	// 0xA8 - SLA+R has been received, ACK has been returned

	if((TWSR_REG & 0xF8) == TWI_SLA_WR_ACK_RSUCCESS_CODE){
		Local_enu_ErrorState = TWI_STATUS_OK;
	}


	else if((TWSR_REG & 0xF8) == TWI_SLA_RD_ACK_RSUCCESS_CODE){
		Local_enu_ErrorState = TWI_STATUS_OK;
	}


	return Local_enu_ErrorState;
}
