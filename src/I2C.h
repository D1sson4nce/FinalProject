#include <Arduino.h>
#include <Wire.h>

//Button class
class I2C {
    private:
        uint8_t address;
        float temperature;
    public:
        /**
        * Constructor 
        * @param address the address the IC2 needs to transmit to
        */
        I2C(uint8_t address) {
            this->address = address;
            init();
        }

        /**
        * Initializes the I2C class
        */
        void init() {
            Wire.begin();
            Wire.beginTransmission(address);
            Wire.write(0xAC);
            Wire.write(0x0C);
            Wire.write(0x51);
            Wire.beginTransmission(address);
            Wire.write(0x51);
            Wire.endTransmission();
            updateTemp();
        }

        /**
        * Reads the temperature and calculates the value
        */
        void updateTemp(){
            Wire.beginTransmission(address);
            Wire.write(0xAA);
            Wire.endTransmission(false);
            Wire.requestFrom(address, 2);
            uint8_t msb = Wire.read();
            uint8_t lsb = Wire.read();

            float raw = (int8_t)msb << 1 | lsb >> 7;

            raw = raw * 10 / 2;

            this->temperature = raw / 10;
        }

        float getTemp(){
            updateTemp();
            return this->temperature;
        }
};