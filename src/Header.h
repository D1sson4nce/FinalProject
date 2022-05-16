#include <Arduino.h>
#include <Wire.h>
#include <Arduino_FreeRTOS.h>
#include <Ethernet2.h>

TaskHandle_t temperatureTask_Handler;
TaskHandle_t ledTask_Handler;

float temperature = 0;

#include <Button.h>
#include <Led.h>
#include <I2C.h>
#include <Web.h>
#include <Temperature.h>