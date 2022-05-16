static void temperatureTask(void *sTask){
    Serial.println("Initializing temperature");

    I2C i2c(0x48);
    Led led(7);
    while(true){
        temperature = i2c.getTemp();

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
    Led led(7);
    while(true){
        led.on();
        vTaskDelay(500/portTICK_PERIOD_MS);
        led.off();
        vTaskDelay(500/portTICK_PERIOD_MS);
    }
}