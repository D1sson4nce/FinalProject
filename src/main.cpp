#include <Header.h>

static void temperatureTask(void *sTask);
static void initServerTask(void *sTask);
static void listenForClientsTask(void *sTask);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
      ;
  }

//   xTaskCreate(temperatureTask, "Temperature Task", 128, NULL, 1, &temperatureTask_Handler);
//   xTaskCreate(initServerTask, "Web Server Task", 128, NULL, 1, &initServerTask_Handler);
    // initServerTask(NULL);
    xTaskCreate(listenForClientsTask, "Listen For Clients Task", 420, NULL, 1, &listenForClientsTask_Handler);
}

void loop() {
  
}