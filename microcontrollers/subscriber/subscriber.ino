#include "EspMQTTClient.h"

/************************* WiFi Access Point *********************************/

#define WLAN_SSID       "PRISMA"
#define WLAN_PASS       "12082000"

/***************************** Broker MQTT ***********************************/

#define SERVER_IP       "192.168.1.122"
#define SERVER_PORT     1883
#define IDENTIFY_NAME   "Subscriber"

/*************************** Network Config **********************************/

EspMQTTClient client(
  WLAN_SSID,
  WLAN_PASS,
  SERVER_IP,
  IDENTIFY_NAME,
  SERVER_PORT
);

/*************************** Variables **********************************/

const int ledPin = 2;
int dutyCycle = 0;

/*************************** Code **********************************/

void setup()
{
  Serial.begin(115200);

  client.enableDebuggingMessages();     // Enable debugging messages sent to serial output
  client.enableHTTPWebUpdater();        // Enable the web updater. User and password default to values of MQTTUsername and MQTTPassword. These can be overridded with enableHTTPWebUpdater("user", "password").
  client.enableLastWillMessage("TestClient/lastwill", "I am going offline", true);      // You can activate the retain flag by setting the third parameter to true
}

void onConnectionEstablished()
{
  Serial.println("Connected...");
}

void loop()
{
  client.loop();

  client.subscribe("sensor", [](const String & payload) {
    dutyCycle = atoi(payload.c_str()) / 4;
    analogWrite(ledPin, dutyCycle);
  });

  delay(0.1 * 1000);
}
