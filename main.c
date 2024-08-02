#include "MCAL/DIO/DIO_interface.h"
#include "HAL/LCD/LCD_HAL_interface.h"
#include "MCAL/SPI/SPI_interface.h"

int main(){
    uint8_t Rx_buffer;
    ErrorStatus_t status;

    SPI_vidInit();
    LCD_enuInit();

    LCD_u8SendString("Rx");
    LCD_u8SetPosXY(0, 2);

    status = SPI_enuSlaveReceive_Char(&Rx_buffer);

    if (status == ERROR_STATUS_OK) {
        LCD_enuSendData(Rx_buffer);
    } else {
        LCD_u8SendString("Error Receiving");
    }

    while (1) {
    }

    return 0;
}
