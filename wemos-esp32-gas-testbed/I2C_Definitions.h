////////////////////////////////////////////////////////////////////////////
// I2C Interfaces
///////

#define SLAVE_ADDRESS  0x04

// pseudo registers
#define REGISTER_SET  16
uint8_t registers[REGISTER_SET];

// i2c messages
int messageSize = 10;
uint8_t i2cCommand   = 0xFF;
uint8_t i2cData      = 0xFF;
bool dataRecieved = false;