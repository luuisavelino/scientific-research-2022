#include "EspMQTTClient.h"

/************************* WiFi Access Point *********************************/

#define WLAN_SSID       "Wireless"
#define WLAN_PASS       "iot-research"

/***************************** Broker MQTT ***********************************/

#define SERVER_IP       "34.171.228.78"
#define SERVER_PORT     1883
#define IDENTIFY_NAME   "Publisher"

/*************************** Network Config **********************************/

EspMQTTClient client(
  WLAN_SSID,
  WLAN_PASS,
  SERVER_IP,
  IDENTIFY_NAME,
  SERVER_PORT
);

/*************************** Variables **********************************/

const int analogInPin = A0;  // ESP8266 Analog Pin ADC0 = A0
char sensorValue[20];  // value read from the pot

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
  itoa(analogRead(analogInPin), sensorValue, 10);
  client.publish("sensor/tensao", sensorValue, true);
  
  Serial.println(sensorValue);
  delay(0.250 * 1000);

  client.loop();
}
