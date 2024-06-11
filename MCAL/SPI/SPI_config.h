/*
 * spi_ config.h
 *
 *  Created on: Mar 15, 2024
 *      Author: ad
 */

#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_

#include "../DIO/DIO_priv.h"

/************	Configure SPI Pins 	*********/
#define SPI_MOSI_PORT			DIO_u8PortB
#define SPI_MOSI_PIN			DIO_u8PIN5


#define SPI_MISO_PORT			DIO_u8PortB
#define SPI_MISO_PIN			DIO_u8PIN6


#define SPI_SCK_PORT			DIO_u8PortB
#define SPI_SCK_PIN				DIO_u8PIN7


#define SPI_SS_PORT				DIO_u8PortB
#define SPI_SS_PIN				DIO_u8PIN4
/********************************************/


// Options: SPI_SLAVE_MODE or SPI_MASTER_MODE
#define SPI_MODE				SPI_SLAVE_MODE

// Options: SPI_DORD_MSB   or SPI_DORD_LSB
#define SPI_DORD				SPI_DORD_MSB


// CPOL - CLock Polarity
// Options: SPI_LRising_TFalling or SPI_LFalling_TRising
#define SPI_CPOL				SPI_LFalling_TRising

// CPHA - Clock Phase
// Options: SPI_LRead_TWrite	or SPI_LWrite_TRead
#define  SPI_CPHA				SPI_LWrite_TRead


// Options: SPI_PRES_04,	SPI_PRES_16
//			SPI_PRES_64,	SPI_PRES_128
//			SPI_PRES_2_DoubleSpeed
//			SPI_PRES_8_DoubleSpeed
//			SPI_PRES_32_DoubleSpeed
//			SPI_PRES_64_DoubleSpeed
#define SPI_PRES_SELECT			SPI_PRES_16




#endif /* MCAL_SPI_SPI_CONFIG_H_ */
