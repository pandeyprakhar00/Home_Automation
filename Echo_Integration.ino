/*
 Version 0.4 - April 26 2019
*/ 

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WebSocketsClient.h> //  https://github.com/kakopappa/sinric/wiki/How-to-add-dependency-libraries
#include <ArduinoJson.h> // https://github.com/kakopappa/sinric/wiki/How-to-add-dependency-libraries (use the correct version)
#include <StreamString.h>

int relayOne = 5;
int relayTwo = 4;
int relayThree =14;
int relayFour = 12;
int relayFive = 13;
int relaySix = 3;
int relaySeven = 1;
int relayEight = 10;

ESP8266WiFiMulti WiFiMulti;
WebSocketsClient webSocket;
WiFiClient client;

#define MyApiKey "#####" // TODO: Change to your sinric API Key. Your API Key is displayed on sinric.com dashboard
#define MySSID "#####" // TODO: Change to your Wifi network SSID
#define MyWifiPassword "#####" // TODO: Change to your Wifi network password

#define HEARTBEAT_INTERVAL 300000 // 5 Minutes 

uint64_t heartbeatTimestamp = 0;
bool isConnected = false;


// deviceId is the ID assgined to your smart-home-device in sinric.com dashboard. Copy it from dashboard and paste it here

void turnOn(String deviceId) {
  if (deviceId == "#####") // Device ID of Light device
  {  
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(relayOne, LOW);
  } 
  else if (deviceId == "#####") // Device ID of Bulb device
  { 
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(relayTwo, LOW);
  }
    else if (deviceId == "#####") // Device ID of Fan device
  { 
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(relayThree, LOW);
  }
    else if (deviceId == "#####") // Device ID of Copper Light device
  { 
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(relayFour, LOW);
  }
    else if (deviceId == "#####") // Device ID of Window Light device
  { 
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(relayFive, LOW);
  }
    else if (deviceId == "#####") // Device ID of Central Light device
  { 
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(relaySix, LOW);
  }
    else if (deviceId == "#####") // Device ID of Focus Light device
  { 
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(relayEight, LOW);
  }
    else if (deviceId == "#####") // Device ID of Studio device
  { 
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(relayOne, HIGH);
    digitalWrite(relayTwo, LOW);
    digitalWrite(relayThree, HIGH);
    digitalWrite(relayFour, LOW);
    digitalWrite(relayFive, LOW);
    digitalWrite(relaySix, LOW);
    digitalWrite(relaySeven, LOW);
    digitalWrite(relayEight, LOW);
  }
   else if (deviceId == "#####") // Device ID of Everything device
  { 
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(relayOne, LOW);
    digitalWrite(relayTwo, LOW);
    digitalWrite(relayThree, LOW);
    digitalWrite(relayFour, LOW);
    digitalWrite(relayFive, LOW);
    digitalWrite(relaySix, LOW);
    digitalWrite(relaySeven, LOW);
    digitalWrite(relayEight, LOW);
  }
   else if (deviceId == "#####") // Device ID of Sleeping Mode device
  { 
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(relayOne, HIGH);
    digitalWrite(relayTwo, HIGH);
    digitalWrite(relayThree, LOW);
    digitalWrite(relayFour, LOW);
    digitalWrite(relayFive, HIGH);
    digitalWrite(relaySix, HIGH);
    digitalWrite(relaySeven, HIGH);
    digitalWrite(relayEight, HIGH);
  }
  else {
    Serial.print("Turn on for unknown device id: ");
    Serial.println(deviceId);    
  }     
}

void turnOff(String deviceId) {
   if (deviceId == "#####") // Device ID of Light device
   {  
     Serial.print("Turn off Device ID: ");
     Serial.println(deviceId);
     digitalWrite(relayOne, HIGH);
   }
   else if (deviceId == "#####") // Device ID of Bulb device
   { 
     Serial.print("Turn off Device ID: ");
     Serial.println(deviceId);
     digitalWrite(relayTwo, HIGH);
  }
  else if (deviceId == "#####") // Device ID of Fan device
   { 
     Serial.print("Turn off Device ID: ");
     Serial.println(deviceId);
     digitalWrite(relayThree, HIGH);
  }
  else if (deviceId == "#####") // Device ID of Copper Light device
   { 
     Serial.print("Turn off Device ID: ");
     Serial.println(deviceId);
     digitalWrite(relayFour, HIGH);
  }
  else if (deviceId == "#####") // Device ID of Window Light device
   { 
     Serial.print("Turn off Device ID: ");
     Serial.println(deviceId);
     digitalWrite(relayFive, HIGH);
  }
  else if (deviceId == "#####") // Device ID of Central Light device
   { 
     Serial.print("Turn off Device ID: ");
     Serial.println(deviceId);
     digitalWrite(relaySix, HIGH);
  }
  else if (deviceId == "#####") // Device ID of Focus Light device
   { 
     Serial.print("Turn off Device ID: ");
     Serial.println(deviceId);
     digitalWrite(relayEight, HIGH);
  }
  else if (deviceId == "#####") // Device ID of Studio device
   { 
     Serial.print("Turn off Device ID: ");
     Serial.println(deviceId);
     digitalWrite(relayOne, LOW);
    digitalWrite(relayTwo, HIGH);
    digitalWrite(relayThree, LOW);
    digitalWrite(relayFour, HIGH);
    digitalWrite(relayFive, HIGH);
    digitalWrite(relaySix, HIGH);
    digitalWrite(relaySeven, HIGH);
    digitalWrite(relayEight, HIGH);
  }
  else if (deviceId == "#####") // Device ID of Everything device
   { 
     Serial.print("Turn off Device ID: ");
     Serial.println(deviceId);
     digitalWrite(relayOne, HIGH);
    digitalWrite(relayTwo, HIGH);
    digitalWrite(relayThree, HIGH);
    digitalWrite(relayFour, HIGH);
    digitalWrite(relayFive, HIGH);
    digitalWrite(relaySix, HIGH);
    digitalWrite(relaySeven, HIGH);
    digitalWrite(relayEight, HIGH);
  }
  else if (deviceId == "#####") // Device ID of Sleeping Mode device
   { 
     Serial.print("Turn off Device ID: ");
     Serial.println(deviceId);
     digitalWrite(relayOne, HIGH);
    digitalWrite(relayTwo, HIGH);
    digitalWrite(relayThree, LOW);
    digitalWrite(relayFour, HIGH);
    digitalWrite(relayFive, HIGH);
    digitalWrite(relaySix, HIGH);
    digitalWrite(relaySeven, HIGH);
    digitalWrite(relayEight, HIGH);
  }
  else {
     Serial.print("Turn off for unknown device id: ");
     Serial.println(deviceId);    
  }
}

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
  switch(type) {
    case WStype_DISCONNECTED:
      isConnected = false;    
      Serial.printf("[WSc] Webservice disconnected from sinric.com!\n");
      break;
    case WStype_CONNECTED: {
      isConnected = true;
      Serial.printf("[WSc] Service connected to sinric.com at url: %s\n", payload);
      Serial.printf("Waiting for commands from sinric.com ...\n");        
      }
      break;
    case WStype_TEXT: {
        Serial.printf("[WSc] get text: %s\n", payload);
        // Example payloads

        // For Switch or Light device types
        // {"deviceId": xxxx, "action": "setPowerState", value: "ON"} // https://developer.amazon.com/docs/device-apis/alexa-powercontroller.html

        // For Light device type
        // Look at the light example in github
          
        DynamicJsonBuffer jsonBuffer;
        JsonObject& json = jsonBuffer.parseObject((char*)payload); 
        String deviceId = json ["deviceId"];     
        String action = json ["action"];
        
        if(action == "setPowerState") { // Switch or Light
            String value = json ["value"];
            if(value == "ON") {
                turnOn(deviceId);
            } else {
                turnOff(deviceId);
            }
        }
        else if (action == "SetTargetTemperature") {
            String deviceId = json ["deviceId"];     
            String action = json ["action"];
            String value = json ["value"];
        }
        else if (action == "test") {
            Serial.println("[WSc] received test command from sinric.com");
        }
      }
      break;
    case WStype_BIN:
      Serial.printf("[WSc] get binary length: %u\n", length);
      break;
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(relayOne, OUTPUT);
  pinMode(relayTwo, OUTPUT);
  pinMode(relayThree, OUTPUT);
  pinMode(relayFour, OUTPUT);
  pinMode(relayFive, OUTPUT);
  pinMode(relaySix, OUTPUT);
  pinMode(relaySeven, OUTPUT);
  pinMode(relayEight, OUTPUT);

  digitalWrite(relayOne, HIGH);   /// To Set the Initial state of pins as High
    digitalWrite(relayTwo, HIGH);
    digitalWrite(relayThree, HIGH);
    digitalWrite(relayFour, HIGH);
    digitalWrite(relayFive, HIGH);
    digitalWrite(relaySix, HIGH);
    digitalWrite(relaySeven, HIGH);
    digitalWrite(relayEight, HIGH);
  
  WiFiMulti.addAP(MySSID, MyWifiPassword);
  Serial.println();
  Serial.print("Connecting to Wifi: ");
  Serial.println(MySSID);  

  // Waiting for Wifi connect
  while(WiFiMulti.run() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  if(WiFiMulti.run() == WL_CONNECTED) {
    Serial.println("");
    Serial.print("WiFi connected. ");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }

  // server address, port and URL
  webSocket.begin("iot.sinric.com", 80, "/");

  // event handler
  webSocket.onEvent(webSocketEvent);
  webSocket.setAuthorization("apikey", MyApiKey);
  
  // try again every 5000ms if connection has failed
  webSocket.setReconnectInterval(5000);   // If you see 'class WebSocketsClient' has no member named 'setReconnectInterval' error update arduinoWebSockets
}

void loop() {
  webSocket.loop();
  
  if(isConnected) {
      uint64_t now = millis();
      
      // Send heartbeat in order to avoid disconnections during ISP resetting IPs over night. Thanks @MacSass
      if((now - heartbeatTimestamp) > HEARTBEAT_INTERVAL) {
          heartbeatTimestamp = now;
          webSocket.sendTXT("H");          
      }
  }   
}

// If you want a push button: https://github.com/kakopappa/sinric/blob/master/arduino_examples/switch_with_push_button.ino 
