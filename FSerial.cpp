/*
 * Code File
 */
#include "Arduino.h"
#include "Custom_PID.h"

FSerial::FSerial(int baud, int dp) {
    baudrate = baud;
    datapoints = dp;
   }

bool FSerial::Initialize() {
    Serial.begin(baudrate);
    return True;
}

bool FSerial::Send(String data_to_send[]) {
    while (Serial.available() > 0) {
        String incoming_slip = "";
        String data = "";

        for (int i=0, i<datapoints, i++) {
            data = data + "TCP" + String(i+1) + ":" + data_to_send[i];
        }

        incoming_slip = Serial.readStringUntil("\n");

        if (incoming_slip == ack) {
          Serial.println(data);
          Serial.flush();
          break;
        }

        else if (incoming_slip == nac) {
          Serial.println(data);
          Serial.flush();
        }
  }
  return true;
}