#include <Arduino.h>
#include <Wire.h>
#include <Arduino_FreeRTOS.h>
#include <Ethernet2.h>

#define I2C_ADDRESS 0x48

TaskHandle_t temperatureTask_Handler;

#include <Button.h>
#include <Led.h>
#include <I2C.h>
#include <Web.h>
#include <Temperature.h>