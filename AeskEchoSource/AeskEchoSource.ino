#include "Time\Time.h"
String dataToSend;
unsigned long lastMillis;
int datanumber;
String curTime;

void setup()
{
	setTime(0, 0, 0, 1, 1, 2016);
	datanumber = 0;
	lastMillis = millis();
	Serial.begin(9600);
}

void loop()
{
	if (millis() - lastMillis > 1000)
	{
		time_t t = now();
		curTime = hour(t) + ":";
		curTime += ":" + minute(t);
		curTime += +":" + second(t);
		curTime += +"#";

		dataToSend = "P0#" + curTime + datanumber;
		Serial.print(dataToSend);
		datanumber++;
		lastMillis = millis();
	}
}
