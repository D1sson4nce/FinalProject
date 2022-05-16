/** \file Header.h
 * Header is for all the defines, includes and global variables
 */
#include <Header.h>

static void temperatureTask(void *sTask);
static void ledTask(void *sTask);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
      ;
  }

  xTaskCreate(temperatureTask, "Temperature Task", 256, NULL, 1, &temperatureTask_Handler);
  xTaskCreate(ledTask, "LED Task", 64, NULL, 1, &ledTask_Handler);

	initWeb();
}

void loop() {
	listenForClients();
}