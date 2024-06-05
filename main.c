/*
 * main.c
 *
 *  Created on: Dec 30, 2023
 *      Author: ad
 */

/******************** Include  Section Start ********************/
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/EEPROM/EEPROM_interface.h"
#include <util/delay.h>
/****************************************************************/

int main(){
	EEPROM_enuInit();


	EEPROM_Input_t EEPROM_1;
    EEPROM_1.A0 = 0;          // Set appropriate value
    EEPROM_1.A1 = 0;          // Set appropriate value
    EEPROM_1.address = 0x00;  // Set initial address
    EEPROM_1.data = 'A';     // Set initial data

	EEPROM_enuWriteData(&EEPROM_1);
	_delay_ms(20);


	EEPROM_enuReadData(&EEPROM_1);

	//! For speed and making the lab easier
	DDRA = EEPROM_1.data;





	while(1){


	}


	    return 0;
}


