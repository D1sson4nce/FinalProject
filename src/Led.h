#include <Arduino.h>

//LED class
class Led {
    private:
        byte pin;
    public:
        /**
        * Constructor 
        * @param pin is the pin number the LED gets its power from
        */
        Led(byte pin) {
            this->pin = pin;
            init();
        }

        /**
        * Initializes the I2C class
        * Sets the pin mode to output
        */
        void init() {
            pinMode(pin, OUTPUT);
            off();
        }

        /**
        * turns on the LED
        */
        void on() {
            digitalWrite(pin, HIGH);
        }
        
        /**
        * turns off the LED
        */
        void off() {
            digitalWrite(pin, LOW);
        }
};