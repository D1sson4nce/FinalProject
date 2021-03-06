byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
}; /**< The specified mac address for the web server. */

IPAddress ip(192, 168, 1, 177); /**< The specified ip address for the web server. */

EthernetServer server(80); /**< Setting the server port */

/**
 * Initialize the web server with a mac and ip address.
 */
void initWeb() {
	Serial.println("Initializing web server");

	Ethernet.begin(mac, ip);
	server.begin();
}

/**
 * Listen once for a client. Called in a loop to listen continously.
 */
void listenForClients() {
    EthernetClient client = server.available();

    if (client) {
        Serial.println("new client");
        // an http request ends with a blank line
        boolean currentLineIsBlank = true;
        while (client.connected()) {
            if (client.available()) {
                char c = client.read();
                Serial.write(c);
                // if you've gotten to the end of the line (received a newline
                // character) and the line is blank, the http request has ended,
                // so you can send a reply
                if (c == '\n' && currentLineIsBlank) {
                    // send a standard http response header
                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-Type: text/html");
                    client.println("Connection: close");  // the connection will be closed after completion of the response
                    client.println("Refresh: 1");  // refresh the page automatically every 1 sec
                    client.println();
                    client.println("<!DOCTYPE HTML>");
                    client.println("<html>");
                    client.print(temperature);
                    client.println("\xB0");
                    client.println("</html>");
                    break;
                }
                if (c == '\n') {
                    // you're starting a new line
                    currentLineIsBlank = true;
                }
                else if (c != '\r') {
                    // you've gotten a character on the current line
                    currentLineIsBlank = false;
                }
            }
        }
        // give the web browser time to receive the data
        delay(1);
        // close the connection:
        client.stop();
        Serial.println("client disconnected");
    }
}