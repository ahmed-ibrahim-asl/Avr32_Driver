/*
 * EXTI_config.c
 *
 *  Created on: Jan 15, 2024
 *      Author: ad
 */


/*************** Include Section Start ********************/
#include "EXTI_priv.h"
#include "EXTI_config.h"
/**********************************************************/


EXTI EXTI_GroupConfig[NUM_INT] = {
	{DISABLED, DISABLED},	//INT0
	{DISABLED, DISABLED},	//INT1
	{DISABLED, DISABLED}	//INT2
};
