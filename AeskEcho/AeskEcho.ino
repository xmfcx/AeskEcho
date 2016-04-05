String dataRead;
void setup()
{
	Serial.begin(9600);
}
void loop()
{
  while(Serial.available() > 0)
  {
    char received = Serial.read();
    dataRead += received;
    if(received=='\n')
    {
      dataRead[1] = '1';
      Serial.print(dataRead);
      dataRead = "";
    }
  }
}
