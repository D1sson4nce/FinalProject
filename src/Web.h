#include <Arduino.h>
#include <Ethernet2.h>

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 177);
EthernetServer server(80);

static void listenForClientsTask(void *pvParams) {
    Serial.println("Initializing web server");

    Ethernet.begin(mac, ip);
    server.begin();

    while (true)
    {
        EthernetClient client = server.available();
        if (client)
        {
            Serial.println("Client found");
            boolean currentLineIsBlank = true;
            while (client.connected()) {
                if (client.available()) {
                    char c = client.read();
                    Serial.write(c);
                    // newline character and currentLineIsBlank, http request has ended,
                    // so you can send a reply
                    if (c == '\n' && currentLineIsBlank) {
                        // send a standard http response header
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: text/html");
                        client.println("Connection: close");  // the connection will be closed after completion of the response
                        client.println("Refresh: 5");  // refresh the page automatically every 5 sec
                        client.println();
                        client.println("<!DOCTYPE HTML>");
                        client.println("<html>");
                        // output values
                        client.print("Temperature: ");
                        client.print(temperature);
                        client.print(" \xB0");
                        client.println("<br />");
                        client.println("</html>");
                        break;
                    }
                    if (c == '\n') {
                        // starting a new line
                        currentLineIsBlank = true;
                    }
                    else if (c != '\r') {
                        // you've gotten a character on the current line
                        currentLineIsBlank = false;
                    }
                }
            }
        }
        vTaskDelay(1/portTICK_PERIOD_MS);
    }
}