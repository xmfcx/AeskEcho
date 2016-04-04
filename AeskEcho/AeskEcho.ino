const int ID = 1;
String dataRead;
String dataToSend;
bool dataIsGood;

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	if (Serial.available() > 5)
	{
		dataRead = Serial.readString();
		if (dataRead[0] == 'P' && dataRead[1] == '0' && dataRead[2] == '#')
		{
			dataToSend = dataRead;
			dataIsGood = true;
		}
		if (dataIsGood)
		{
			dataToSend[1] = (char) ID;
			Serial.print(dataToSend);
			dataIsGood = false;
		}
	}
}
