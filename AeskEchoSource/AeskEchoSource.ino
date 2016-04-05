#include <Arduino.h>
String dataToSend;
unsigned long lastMillis = 0;
int datanumber = 0;
void setup()
{
	Serial.begin(9600);
}
void loop()
{
	if (millis() - lastMillis > 2000)
	{
		dataToSend = "P1#" + String(datanumber) + "\n";
		Serial.print(dataToSend);
		datanumber++;
		lastMillis = millis();
	}
}
