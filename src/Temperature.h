static void temperatureTask(void *sTask){
    I2C i2c(0x48);
    Button btn(0);
    bool letGo = true;
    bool isUsingCelcius = true;
    while(true){
        if(letGo && btn.isPressed()){
            letGo = false;
            if(isUsingCelcius){
                isUsingCelcius = false;
                Serial.println(temperature);
            }else{
                isUsingCelcius = true;
                Serial.println(temperature);
            }
        }else if(!btn.isPressed()){
            letGo = true;
        }
        if(isUsingCelcius){
            temperature = i2c.getTemp();
        }else{
            temperature = i2c.getFTemp();
        }
    }
}

static void ledTask(void *sTask){
    Led led(1);
    while(true){
        led.on();
        vTaskDelay(500/portTICK_PERIOD_MS);
        led.off();
        vTaskDelay(500/portTICK_PERIOD_MS);
    }
}