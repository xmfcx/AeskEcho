#include <XBee.h>
XBee xbee = XBee();
String dataRead;
unsigned long lastMillis;
XBeeResponse response = XBeeResponse();
ZBExplicitRxResponse rx = ZBExplicitRxResponse();
void setup()
{
  Serial.begin(115200);
  xbee.setSerial(Serial);
  pinMode(12, OUTPUT);
}
void loop()
{
  xbee.readPacket(100);
  if (xbee.getResponse().isAvailable())
  {
    digitalWrite(12, HIGH);
    if (xbee.getResponse().getApiId() == ZB_EXPLICIT_RX_RESPONSE)
    {
      xbee.getResponse().getZBExplicitRxResponse(rx);
      uint8_t *received = rx.getData();
      for (int i = 0; i < rx.getDataLength(); i++)
      {
        dataRead += (char)received[i];
        if ((char)received[i] == '\n')
        {
          if(dataRead[1] == '3')
            dataRead[1] = '1';
          send_data(dataRead, 0);
          dataRead = "";
        }
      }
    }
  }

  if (millis() - lastMillis > 1000)
  {
    digitalWrite(12, LOW);
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
