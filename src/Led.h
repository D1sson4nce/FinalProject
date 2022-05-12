#include <Arduino.h>

//LED class
class Led {
    private:
        byte pin;
    public:
        //Constructor
        Led(byte pin) {
            this->pin = pin;
            init();
        }

        void init() {
            pinMode(pin, OUTPUT);
            off();
        }

        void on() {
            digitalWrite(pin, HIGH);
        }
        
        void off() {
            digitalWrite(pin, LOW);
        }
};