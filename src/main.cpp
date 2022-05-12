#include <Header.h>

static void temperatureTask(void *sTask);
static void listenForClientsTask(void *sTask);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
      ;
  }

  xTaskCreate(temperatureTask, "Temperature Task", 420, NULL, 1, &temperatureTask_Handler);
  xTaskCreate(listenForClientsTask, "Listen For Clients Task", 420, NULL, 1, &listenForClientsTask_Handler);
}

void loop() {
  
}