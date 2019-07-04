/*----------------------------------------------------------------------------------------
 Ce programme permet de piloter différents servomoteurs à l'aide du moniteur série.
 Tapez YxZZZZ dans le terminal
 Y entre 0 et 5 pour Mini Maestro 6 voies (selon Maestro)
 ZZZZ entre 4000 et 8000 (selon servomoteur)
 Ex: Tapez 0x6000 dans le moniteur série
  Materiel:
  - 1x servomoteur ou plus
  - 1x Mini Maestro
  - 1x Arduino
  
 Auteur: Xavier Wiedmer
http://www.aranacorp.com
----------------------------------------------------------------------------------------*/

#include "SoftwareSerial.h"
SoftwareSerial maestro(2,3);
SoftwareSerial hc06(0,1); //rx tx

unsigned char  message;
String msg, m1, m2;
int sep, servoId=-1, servoPos=-1;

void setup() {
  Serial.begin(9600);
  hc06.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  maestro.begin(9600);
  Serial.println(F("Waiting for command (YxZZZZ): "));
}

void loop() {
  if(hc06.available()){
    message = hc06.read();
    Serial.write(message);
  }



readSerialPort();
convertMsgToCmd();
   //Apply command to servo
   if (servoId>=0 && servoPos>=0 && servoId<18 && servoPos>=500 && servoPos<=10000) {
    
      setTarget(servoId, servoPos);
      Serial.print(F("Command "));
      Serial.print(servoPos);
      Serial.print( F(" sent "));
      Serial.print(F("to servo "));
      Serial.println(servoId);
  
  servoId=-1;
  servoPos=-1;
  Serial.println(F("Waiting for command ... "));
}
}
void setTarget(unsigned char servo, unsigned int target){
 /* envoie la séquence de commande au contrôleur série Maestro pour actionner le servomoteur*/
 const int deviceId = 0x0C; //controller ID 12
 const int startByte = 0xAA; // Protocol selection
 const int targetCmd = 0x04; // Command ID
 
 maestro.write(startByte); //start byte
 maestro.write(deviceId); //device id
 maestro.write(targetCmd); //command number
 maestro.write(servo); //servo number
 maestro.write(target & 0x7F); // Send first 4bits
 maestro.write((target >> 7) & 0x7F); // Send last 4bits
 delay(3);
}
void readSerialPort(){
 /*Permet de lire une commande provenant du terminal Arduino*/
while (Serial.available()) {
  delay(10);  
  if (Serial.available() >0) {
    char c = Serial.read();  //gets one byte from serial buffer
    msg += c;
  }
}
}
void convertMsgToCmd(){
 /*convertit le message provenant du terminal en commande à envoyer au contrôleur série*/
  if (msg.length() >0) {
    Serial.println(msg);
    sep = msg.indexOf('x');
    // expect a string like 0x0021 containing the two servo positions      
    m1 = msg.substring(0, sep); //get servo id
    m2 = msg.substring(sep+1, msg.length()); //get servo pos
    
    servoId=-1;
    servoPos=-1; 
   
    char carray1[6]; //magic needed to convert string to a number
    m1.toCharArray(carray1, sizeof(carray1));
    servoId = atoi(carray1);
    
    char carray2[6];
    m2.toCharArray(carray2, sizeof(carray2));
    servoPos = atoi(carray2);
     
    msg="";
}
}
