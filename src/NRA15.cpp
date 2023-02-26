/*

@author: Ruhaizan Fazreen Ashraff
@email: ruhaizanfazreen@gmail.com


  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
*/
#include "NRA15.h"
extern unsigned long PORT_SENSOR_TIMEOUT_MS;

uint8_t NRA15::IncomingNewMessage()//Incoming data from Sensor
{
  if (hwStream->available()>= 3)
  {
    if(hwStream->read() == HEADER){//Compare fisrt header with 0x48
      DataL = hwStream->read();//Read low byte
      DataH = hwStream->read();//Read high byte
      Distance_Uart_s25=((DataH&0x7F)*128 + (DataL&0x7F))*2.5;//Calculate parameter
      _last_distance_received_fd = millis();//Take Current milis
      Is_Data_NR15_Event = true;//Set Is_Data_NR15_Event to true
    }
  }
    else if ((_last_distance_received_fd == 0) || (millis() - _last_distance_received_fd > PORT_SENSOR_TIMEOUT_MS)) 
    {
  
      Is_Data_NR15_Event = false;  //Set Is_Data_NR15_Event to false
    }
  return 0;
}

void NRA15::begin(uint32_t baudRate)
{
  if (hwStream)
  {
    hwStream->begin(baudRate); //Set baudRate
  }
}