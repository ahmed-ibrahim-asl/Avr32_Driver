/*
 * SPI_priv.h
 *
 *  Created on: Mar 15, 2024
 *      Author: ad
 */

#ifndef MCAL_SPI_SPI_PRIV_H_
#define MCAL_SPI_SPI_PRIV_H_

/************************ SPI Registers ************************/
#define SPCR_REG	*((volatile uint8_t*) (0x2D))
#define SPSR_REG	*((volatile uint8_t*) (0x2E))
#define SPDR_REG	*((volatile uint8_t*) (0x2F))
/***************************************************************/


//! SPCR
#define SPCR_SPIE							7
#define SPCR_SPE							6
#define SPCR_DORD							5
#define SPCR_MSTR							4
#define SPCR_CPOL							3
#define SPCR_CPHA							2
#define SPCR_SPR1							1
#define SPCR_SPR0							0

//! SPSR
#define SPSR_SPI2x							0
#define SPSR_SPIF							7



#define SPI_SLAVE_MODE						0
#define SPI_MASTER_MODE						1

#define SPI_DORD_MSB						2
#define SPI_DORD_LSB						3

#define SPI_LRising_TFalling				4
#define SPI_LFalling_TRising				5

#define SPI_LRead_TWrite					6
#define SPI_LWrite_TRead					7


#define SPI_PRES_04							8
#define SPI_PRES_16							9
#define SPI_PRES_64							10
#define SPI_PRES_128						11
#define SPI_PRES_2_DoubleSpeed				12
#define SPI_PRES_8_DoubleSpeed				13
#define SPI_PRES_32_DoubleSpeed				14
#define SPI_PRES_64_DoubleSpeed				15




#endif /* MCAL_SPI_SPI_PRIV_H_ */
