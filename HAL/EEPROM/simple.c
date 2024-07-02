//#define F_CPU 8000000UL
//#include <avr/io.h>
//#include <util/delay.h>
//
//#define TW_START   0xA4
//#define TW_WRITE   0xC4
//#define TW_STOP    0x94
//#define TW_ACK     0xC4
//#define TW_NACK    0x84
//#define TW_READY   (TWCR & (1<<TWINT))
//#define EEPROM_ADDRESS_WRITE 0xA0
//#define EEPROM_ADDRESS_READ  0xA1
//
//
//void EEPROM_Write(uint8_t address, uint8_t data) {
//    // Send start condition
//    TWI_Start();
//    // Send EEPROM address with write operation
//    TWI_Write(EEPROM_ADDRESS_WRITE);
//    // Send memory address within EEPROM
//    TWI_Write(address);
//    // Write data to EEPROM
//    TWI_Write(data);
//    // Send stop condition
//    TWI_Stop();
//}
//
//uint8_t EEPROM_Read(uint8_t address) {
//    uint8_t data;
//    // Send start condition
//    TWI_Start();
//    // Send EEPROM address with write operation
//	// [[[[[0xA0]
//    TWI_Write(EEPROM_ADDRESS_WRITE);
//    // Send memory address within EEPROM
//    TWI_Write(address);
//    // Send repeated start condition
//    TWI_Start();
//    // Send EEPROM address with read operation
//    TWI_Write(EEPROM_ADDRESS_READ);
//    // Read data from EEPROM
//    data = TWI_Read_NACK();
//    // Send stop condition
//    TWI_Stop();
//    return data;
//}
//
////int main(void) {
////    // Set PORTA as output for displaying read data
//////    DDRA = 0xFF;
////    // Initialize TWI (I2C)
////    TWI_Init();
////    // Write 'A' to EEPROM at address 0x00
////    EEPROM_Write(0x00, 'A');
////    // Wait for the write operation to complete
////    _delay_ms(10);
////    // Read data from EEPROM at address 0x00
////    uint8_t data = EEPROM_Read(0x00);
////    // Display the read data on PORTA
////    DDRA = data;
////    while (1) {
////        // Infinite loop
////    }
////}
