# AeskEcho
Telemetry Mesh Network Project with 3 Arduino Nanos and 4 XBee Pro 868 to extend range.

##Dependencies
- https://github.com/andrewrapp/xbee-arduino

##Scheme
![alt tag](http://i.imgur.com/Vuui5Ce.png)
###Workflow
* Device 3 is the main broadcaster. 3 sends data to 0, 1 and 2.
  * Message Format: "P3#dataNumber\r\n" 3 here is ID.
* Device 0 is the final destination. 1 and 3 sends data to it.
  * In my case, 0 was directly connected to laptop.
* Device 1 receives data from 2 and 3 and sends to 0.
  * If received from 3, renames the ID to 1.
* Device 2 receives from 3 and sends it to 1.
  * Renames ID to 2.

##XBee Configurations
Use XCTU to configure XBees. I had 4 Xbee Pro 868 devices.
1. Factory reset all.
2. ID = some number you like. Must be same on all.
3. NO = 2.
4. AP = 2.
5. AO = 1.
6. NI = Name you like, I named them like ROUTER3, ROUTER2.
7. Note somewhere the SH and SL numbers, they are necessary to decide where you are sending stuff.
8. BD = 115200.
#About
This was a prepared for Shell Eco-marathon Europe 2016 by AESK (Alternative Energy Systems Club) http://www.ytuaesk.com/
