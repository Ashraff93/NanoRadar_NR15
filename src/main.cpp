#include <Arduino.h> //Declared weak in Arduino.h to allow user redefinitions.
#include "NRA15.h" //#include "NRA15.h" 
#define NR15 Serial1 //#define TELEMSERIAL Serial1 RX:TX(0,1)
unsigned long PORT_SENSOR_TIMEOUT_MS = 2000; //Time millisecond before turn off sensor


NRA15 Nr15(NR15); //Define UART3SERIAL to class NRA15 with LedSS3
uint8_t id25 = 25; /*<  Onboard ID of the sensor*/
uint8_t orientation25 = 25; //Direction the sensor faces Sector 25 (Downward)
void setup() {
  delay(5000); //Delay 5 second before procced to the next line
  Serial.begin(115200); // opens serial port, sets data rate to 115200 bps
  Nr15.begin(115200); // set the data rate for the UartSerial1 port
}

void loop() {
  Nr15.IncomingNewMessage(); //Call IncomingNewMessage From Front Sensor
  Serial.println(Nr15.Distance_Uart_s25); //put soe delay
}