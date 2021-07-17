const int buzzerPin = 12;
#include <SoftwareSerial.h>
const int flamePin = 11;
int Flame = HIGH;
int redled = 5;
int greenled = 6;
int sms_count=0;
SoftwareSerial mySerial(9, 10);
void setup() 
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);

  pinMode(flamePin, INPUT);
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop() 
{
  Flame = digitalRead(flamePin);
  if (Flame== LOW)
  {
    
      mySerial.println("ATD9370359002;"); // ATDxxxxxxxxxx; semicolon should be at the last ;AT command that follows UART protocol;
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(redled, HIGH);
      digitalWrite(greenled,LOW);
       //Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     //delay(1000);  // Delay of 1 second
     //Serial.println("AT+CMGS=\"+916388331935\"\r"); // Replace x with mobile number
     //Serial.println("FIRE IN THE HOUSE");// The SMS text you want to send
     //Serial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
     //delay(100);
     while(sms_count<3) 
     {  
       SendTextMessage(); 
     }
        
  }
  else
  {

    digitalWrite(buzzerPin, LOW);
    digitalWrite(greenled, HIGH);
    digitalWrite(redled, LOW);
  }
}
void SendTextMessage()
{
  mySerial.println("AT+CMGF=1");    //To send SMS in Text Mode
  delay(2000);
  mySerial.println("AT+CMGS=\"+919370359002\"\r"); 
  delay(2000);
  mySerial.println("Fire in the HOUSE!");
  delay(200);
  mySerial.println((char)26);//the stopping character
  delay(5000);
   mySerial.println("AT+CMGS=\"+919370359002\"\r"); 
  delay(2000);
  mySerial.println("Fire in the HOUSE!");
  delay(200);
  mySerial.println((char)26);//the message stopping character
  delay(5000);
  sms_count++;
}