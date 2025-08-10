#include <IRremote.hpp>


#define red 11
#define green 10
#define yellow 9
#define pilot 12

IRrecv pilocik(pilot);

uint32_t kod=0;

int wypelnienie =0;
int zmiana=50;

void setup()
{
  Serial.begin(9600);
  pilocik.enableIRIn();
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(yellow,OUTPUT);
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
  digitalWrite(yellow,LOW);
} 
void loop()
{
  if(pilocik.decode())
  {

    kod=pilocik.decodedIRData.decodedRawData;
    Serial.println(kod,HEX);

    switch(kod)
    {
      case 0xBA45FF00: //0 - wszystkie diody wyłączone 
        digitalWrite(red,LOW);
        digitalWrite(green,LOW);
        digitalWrite(yellow,LOW);
        delay(500);
      break;
      case 0xF30CFF00: //1 - zolta on reszta off
          digitalWrite(yellow,HIGH);
          digitalWrite(green,LOW);
          digitalWrite(red,LOW);
          delay(500);
      break;
      case 0xE718FF00: //2 - zielona on reszta off
        digitalWrite(green,HIGH);
        digitalWrite(red,LOW);
        digitalWrite(yellow,LOW);
        delay(500);
      break;
      case 0xA15EFF00: // 3 - czerwona on reszta off
        digitalWrite(red,HIGH);
        digitalWrite(green,LOW);
        digitalWrite(yellow,LOW);
        delay(500);
      break;
      case 0xF708FF00:
        digitalWrite(red,HIGH);
        digitalWrite(green,HIGH);
        digitalWrite(yellow,HIGH);
        delay(500);
      break;
      case 0xE31CFF00:

      for(int j=0;j<10;j++)
      {
        for(int i=9;i<12;i++)
        {
          digitalWrite(i,HIGH);
          delay(500);
          digitalWrite(i,LOW);
        };
      };
      break; 
      case 0xA55AFF00:
      for(int j=0;j<10;j++)
      {
        for(int i=11;i>8;i--)
        {
          digitalWrite(i,HIGH);
          delay(500);
          digitalWrite(i,LOW);
        };
      };
      break;
     
    }
    pilocik.resume();
  }
}