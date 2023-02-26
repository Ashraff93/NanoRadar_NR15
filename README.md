
# NanoRadar_NR15
Basic calling for NanoRadar_NR15

These drivers use Uart to communicate, 4 pins are required to interface.
...
  Nr15.IncomingNewMessage(); //Call IncomingNewMessage From Front Sensor
  Serial.println(Nr15.Distance_Uart_s25); //put soe delay
...