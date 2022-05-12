#include <Header.h>

static void temperatureTask(void *sTask);

void setup() {
  Serial.begin(9600);

  xTaskCreate(temperatureTask, "Temperature Task", 128, NULL, 1, &temperatureTask_Handler);
}

void loop() {
  
}