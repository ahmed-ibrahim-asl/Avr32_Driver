/*
 * spi_interface.h
 *
 *  Created on: Mar 15, 2024
 *      Author: ad
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_


/********************* Functions  Prototype *********************/
void SPI_vidInit(void);


ErrorStatus_t SPI_enuMasterTransmit_Char(uint8_t copy_u8Data);

ErrorStatus_t SPI_enuMasterTransmit_String(uint8_t* copy_pu8Data);


ErrorStatus_t SPI_enuSlaveReceive_Char(uint8_t* copy_pu8Data);
ErrorStatus_t SPI_enuSlaveReceive_String(uint8_t* copy_pu8Data);
/****************************************************************/

static inline uint8_t flipBits(uint8_t byte);

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
