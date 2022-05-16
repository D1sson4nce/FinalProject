/**
* Temperature Task
* @param sTask is a passed variable with the task gets created
*/
static void temperatureTask(void *sTask){
    Serial.println("Initializing temperature");

    //initializes the I2C and the LED as objects
    I2C i2c(0x48);
    Led led(7);
    while(true){
        //gets the temperature from the I2C
        temperature = i2c.getTemp();

        //if the temperature is above 27 degrees, it'll start a blinking LED task, otherwise, it'll stop it
        static bool hasActiveLED = true;
        if(temperature > 27){
            if(!hasActiveLED){
                vTaskResume(ledTask_Handler);
            }
            hasActiveLED = true;
        }else{
            if(hasActiveLED){
                vTaskSuspend(ledTask_Handler);
                led.off();
            }
            hasActiveLED = false;
        }

        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

static void ledTask(void *sTask){
    //initializes the the LED as an object
    Led led(7);
    while(true){
        led.on();
        vTaskDelay(500/portTICK_PERIOD_MS);
        led.off();
        vTaskDelay(500/portTICK_PERIOD_MS);
    }
}