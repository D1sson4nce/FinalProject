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
            }else{
                isUsingCelcius = true;
            }
        }else if(!btn.isPressed()){
            letGo = true;
        }
        if(isUsingCelcius){
            temperature = i2c.getTemp();
        }else{
            temperature = i2c.getFTemp();
        }
        Serial.println(temperature);
    }
}