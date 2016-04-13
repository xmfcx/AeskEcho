#include <XBee.h>
String dataToSend;
XBee xbee = XBee();
unsigned long lastMillis = 0;
int datanumber = 0;

void setup()
{
  Serial.begin(115200);
  xbee.setSerial(Serial);
}
void loop()
{
  if (millis() - lastMillis > 1000)
  {
    dataToSend = "P3#" + String(datanumber) + "\r\n";
    send_data(dataToSend, 0);
    send_data(dataToSend, 1);
    send_data(dataToSend, 2);
    datanumber++;
    lastMillis = millis();
  }
}
void send_data(String data, int target)
{
  uint8_t payload[data.length()];
  for (int i = 0; i < data.length(); i++)
  {
    payload[i] = data[i];
  }
  XBeeAddress64 addr64;
  switch (target)
  {
    case 0:
      addr64 = XBeeAddress64(0x0013A200, 0x40A27F25);
      break;
    case 1:
      addr64 = XBeeAddress64(0x0013A200, 0x40A27F09);
      break;
    case 2:
      addr64 = XBeeAddress64(0x0013A200, 0x40A27F2A);
      break;
    case 3:
      addr64 = XBeeAddress64(0x0013A200, 0x40A2E5A9);
      break;
  }
  ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));
  xbee.send(zbTx);
}

