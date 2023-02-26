#ifndef NRA15_H
#define NRA15_H
#include <Arduino.h> //Declared weak in Arduino.h to allow user redefinitions.


class NRA15  {
  // Class Member Variables
  // Constructor - creates a NRA15
  private:
    HardwareSerial* hwStream; //Pointer class HardwareSerial hwStream

    const uint8_t HEADER=0x48; //HEADER 0X48
    uint16_t DataL, DataH; //Variable Data Low and Data High 
  public:
    NRA15( HardwareSerial& device)
    {hwStream = &device;} //Pass reference to Serial object into a class
    void begin(uint32_t baudRate); //Void Function Parameter begin declaration
    uint8_t IncomingNewMessage(); //Void Function Parameter IncomingNewMessage declaration
    uint16_t Distance_Uart_s25; //Variable Distance_Uart_s25 declaration
    uint32_t _last_distance_received_fd; //Variable _last_distance_received_fd declaration
    bool Is_Data_NR15_Event = false;  //bool Is_Data_NR15_Event declaration
};

#endif