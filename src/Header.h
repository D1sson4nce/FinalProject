#include <Arduino.h>
#include <Wire.h>
#include <Arduino_FreeRTOS.h>
#include <Ethernet2.h>

TaskHandle_t temperatureTask_Handler;

#include <Button.h>
#include <Led.h>
#include <Web.h>
#include <Temperature.h>