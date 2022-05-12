#include <Arduino.h>
#include <Wire.h>

//Button class
class I2C {
    private:
        uint8_t address;
        int16_t temperature;
    public:
        //Constructor
        I2C(uint8_t address) {
            this->address = address;
            init();
        }

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

        void updateTemp(){
            Wire.beginTransmission(address);
            Wire.write(0xAA);
            Wire.endTransmission(false);
            Wire.requestFrom(address, 2);
            uint8_t msb = Wire.read();
            uint8_t lsb = Wire.read();

            int16_t raw = (int8_t)msb << 1 | lsb >> 7;

            raw = raw * 10 / 2;

            this->temperature = raw / 10;
        }

        int16_t getTemp(){
            updateTemp();
            return this->temperature;
        }

        int16_t getFTemp(){
            updateTemp();
            return this->temperature * (9 / 5) + 32;
        }
};