static void temperatureTask(void *sTask){
    Wire.begin();
    Wire.beginTransmission(I2C_ADDRESS);
    Wire.write(0xAC);
    Wire.write(0x0C);
    Wire.write(0x51);
    Wire.beginTransmission(I2C_ADDRESS);
    Wire.write(0x51);
    Wire.endTransmission();

    while(true){
        
    }
}