/*
 * main.c
 *
 *  Created on: Dec 30, 2023
 *      Author: ad
 */

/******************** Include  Section Start ********************/
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TWI/TWI_interface.h"
#include "HAL/LCD/LCD_HAL_interface.h"
#include <util/delay.h>

/****************************************************************/





int main(){

	TWI_enuInit();


	#if(TWI_MODE_M_or_S == TWI_SLAVE_MODE)
		LCD_enuInit();
		uint8_t Local_u8Data = 0;
	#endif




	while(1){
		#if(TWI_MODE_M_or_S == TWI_MASTER_MODE)
			if( TWI_STATUS_OK == TWI_enuStartCondition()){

				if( TWI_STATUS_OK == TWI_enuSetSlaveOperation(5, TWI_WriteOperation)){

					if(TWI_STATUS_OK == TWI_enuWriteData('@')){
						TWI_enuStopCondition();

					}
				}
			}


		#elif(TWI_MODE_M_or_S == TWI_SLAVE_MODE)
			if( TWI_STATUS_OK == TWI_enuCheckMyAddress() ){

				if(TWI_STATUS_OK == TWI_enuReadData(&Local_u8Data)){
					LCD_enuSendData(Local_u8Data);
				}

			}
			_delay_ms(100);

		#endif
	}




	    return 0;
}



