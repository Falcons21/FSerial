/*
  FSerial Communication Protocol library developed for Team Assailing Falcons
  Download the library here- https://github.com/Falcons21/FSerial

  This is an example sketch to show the working of the library.
  Random Data Points are taken in this example and are incrememnted in each iteration.

  To Use the library create a list with required data points and use .Send method to send the data
*/
#include <FSerial.h>

float count = 0.0;

FSerial fserial(2000000, 10);

void setup() {
  fserial.Initialize();
}

void loop() {

  String tcp1 = String(100 + count);
  String tcp2 = String(30 + count);
  String tcp3 = String(90 + count);
  String tcp4 = String(21.8 + count);
  String tcp5 = String(22.3298 + count);
  String tcp6 = String(78.3993 + count);
  String tcp7 = "AUTO";
  String tcp8 = "NONE";
  String tcp9 = "NONE";
  String tcp10 = "NONE";

  String data_list[10] = {tcp1, tcp2, tcp3, tcp4, tcp5, tcp6, tcp7, tcp8, tcp9, tcp10};
  fserial.Send(data_list);

  count = count + 1.0;

}