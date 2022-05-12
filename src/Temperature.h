static void temperatureTask(void *sTask){
    I2C i2c(0x48);
    while(true){
        int16_t temp = i2c.getFTemp();
        Serial.println(temp);
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}