/*
 * Header File
 */
#ifndef __FSERIAL_H__
#define __FSERIAL_H__

#include "Arduino.h"

class FSerial {
public:
  FSerial(int baud);
  bool Initialize();
  bool Send();

private:
  int baudrate;
  int datapoints;
  const String rdy = "RDY\n";
  const String ack = "ACK\n";
  const String nac = "NAC\n";
};

#endif