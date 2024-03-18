/*
 * spi_program.c
 *
 *  Created on: Mar 15, 2024
 *      Author: ad
 */


/********************************* Include  Section *********************************/
#include "../DIO/helper_embedded_libraries/micro_config.h"
#include "../DIO/DIO_interface.h"
#include "SPI_config.h"
#include "SPI_interface.h"
#include "SPI_priv.h"
/************************************************************************************/



void SPI_vidInit(void){

	//! Master/ Slave
	#if(SPI_MODE == SPI_MASTER_MODE)


		DIO_enuSetPinDirection(SPI_MOSI_PORT, SPI_MOSI_PIN, DIO_u8OUTPUT);
		DIO_enuSetPinDirection(SPI_MISO_PORT, SPI_MISO_PIN, DIO_u8INPUT);

		DIO_enuSetPinDirection(SPI_SCK_PORT, SPI_SCK_PIN, DIO_u8OUTPUT);
		DIO_enuSetPinDirection(SPI_SS_PORT, SPI_SS_PIN, DIO_u8OUTPUT);

		SET_BIT(SPCR_REG, SPCR_MSTR);

	#elif(SPI_MODE == SPI_SLAVE_MODE)

		DIO_enuSetPinDirection(SPI_MISO_PORT, SPI_MISO_PIN, DIO_u8OUTPUT);
		DIO_enuSetPinDirection(SPI_MOSI_PORT, SPI_MOSI_PIN, DIO_u8INPUT);

		DIO_enuSetPinDirection(SPI_SCK_PORT, SPI_SCK_PIN, DIO_u8INPUT);
		DIO_enuSetPinDirection(SPI_SS_PORT, SPI_SS_PIN, DIO_u8INPUT);

		CLR_BIT(SPCR_REG, SPCR_MSTR);
	#endif


	//! Data order
	#if(SPI_DORD == SPI_DORD_MSB)
		SET_BIT(SPCR_REG, SPCR_DORD);
	#elif(SPI_DORD == SPI_DORD_LSB)
		CLR_BIT(SPCR_REG, SPCR_DORD);
	#endif


	//! Clock Polarity
	#if(SPI_CPOL == SPI_LRising_TFalling)
		// SCK is high when idle
		CLR_BIT(SPCR_REG, SPCR_CPOL);

	#elif(SPI_CPOL == SPI_LRising_TFalling)
		// SCK is low when idle
		SET_BIT(SPCR_REG, SPCR_CPOL);
	#endif




	//! Set Clock Rate
	#if(SPI_PRES_SELECT == SPI_PRES_04)
		CLR_BIT(SPCR_REG, SPCR_SPR0 );
		CLR_BIT(SPCR_REG, SPCR_SPR1 );
		CLR_BIT(SPSR_REG, SPSR_SPI2x);

	#elif(SPI_PRES_SELECT == SPI_PRES_16)
		SET_BIT(SPCR_REG, SPCR_SPR0 );
		CLR_BIT(SPCR_REG, SPCR_SPR1 );
		CLR_BIT(SPSR_REG, SPSR_SPI2x);

	#elif(SPI_PRES_SELECT == SPI_PRES_64)
		CLR_BIT(SPCR_REG, SPCR_SPR0 );
		SET_BIT(SPCR_REG, SPCR_SPR1 );
		CLR_BIT(SPSR_REG, SPSR_SPI2x);

	#elif(SPI_PRES_SELECT == SPI_PRES_128)
		SET_BIT(SPCR_REG, SPCR_SPR0 );
		SET_BIT(SPCR_REG, SPCR_SPR1 );
		CLR_BIT(SPSR_REG, SPSR_SPI2x);

	#elif(SPI_PRES_SELECT == SPI_PRES_2_DoubleSpeed)
		CLR_BIT(SPCR_REG, SPCR_SPR0 );
		CLR_BIT(SPCR_REG, SPCR_SPR1 );
		SET_BIT(SPSR_REG, SPSR_SPI2x);

	#elif(SPI_PRES_SELECT == SPI_PRES_8_DoubleSpeed)
		SET_BIT(SPCR_REG, SPCR_SPR0 );
		CLR_BIT(SPCR_REG, SPCR_SPR1 );
		SET_BIT(SPSR_REG, SPSR_SPI2x);

	#elif(SPI_PRES_SELECT == SPI_PRES_32_DoubleSpeed)
		CLR_BIT(SPCR_REG, SPCR_SPR0 );
		SET_BIT(SPCR_REG, SPCR_SPR1 );
		SET_BIT(SPSR_REG, SPSR_SPI2x);

	#elif(SPI_PRES_SELECT == SPI_PRES_64_DoubleSpeed)
		SET_BIT(SPCR_REG, SPCR_SPR0 );
		SET_BIT(SPCR_REG, SPCR_SPR1 );
		SET_BIT(SPSR_REG, SPSR_SPI2x);

	#endif


	/*	Enable SPI	*/
	SET_BIT(SPCR_REG, SPCR_SPE);
}



ErrorStatus_t SPI_enuMasterTransmit_Char(uint8_t copy_u8Data){
	ErrorStatus_t Local_enu_ErrorState = ERROR_STATUS_FAILURE;


	SPDR_REG = copy_u8Data;

	/*! Wait for transmission complete */
	while(!GET_BIT(SPSR_REG, SPSR_SPIF));


	Local_enu_ErrorState = ERROR_STATUS_OK;
	return Local_enu_ErrorState;
}



ErrorStatus_t SPI_enuMasterTransmit_String(uint8_t* copy_pu8Data){
	ErrorStatus_t Local_enu_ErrorState = ERROR_STATUS_FAILURE;


	if(copy_pu8Data == NULL){
		return Local_enu_ErrorState;

	}else{

		do{
			SPI_enuMasterTransmit_Char(*copy_pu8Data);
			copy_pu8Data++;
		}while(*copy_pu8Data != '\0');
	}

	Local_enu_ErrorState = ERROR_STATUS_OK;
	return Local_enu_ErrorState;
}



ErrorStatus_t SPI_enuSlaveReceive_Char(uint8_t* copy_pu8Data){
	ErrorStatus_t Local_enu_ErrorState = ERROR_STATUS_FAILURE;


	/* Wait for successful reception of data from master */
	while(!GET_BIT(SPSR_REG, SPSR_SPIF));

	*copy_pu8Data = SPDR_REG;


	Local_enu_ErrorState = ERROR_STATUS_OK;
	return Local_enu_ErrorState;
}



ErrorStatus_t SPI_enuSlaveReceive_String(uint8_t* copy_pu8Data){

	ErrorStatus_t Local_enu_ErrorState = ERROR_STATUS_FAILURE;


	if(copy_pu8Data == NULL){
		return Local_enu_ErrorState;
	}else{

		// Intiate head of buffer similar to linked-list idea
		uint8_t *Local_u8Temp = copy_pu8Data;

		do{
			SPI_enuSlaveReceive_Char(Local_u8Temp);


		}while(*(Local_u8Temp++) != '\0');
	}


	Local_enu_ErrorState = ERROR_STATUS_OK;
	return Local_enu_ErrorState;
}


