#include <LiquidCrystal.h>

#define trig 6
#define echo 5
#define buzz 4
#define led 2

LiquidCrystal lcd(7,8,9,10,11,12);

void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzz,OUTPUT);
  lcd.begin(16, 2);
  lcd.print("RANGE: ");
}

void loop() {
  lcd.setCursor(0,1);
  lcd.print("                "); 
  lcd.setCursor(0,1);

  long time = 0;
  long range = 0;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  time = pulseIn(echo, HIGH, 20000); 
  range = time / 58;

  if (time == 0) {
    lcd.print("Too close");
    digitalWrite(buzz,LOW);
    digitalWrite(led,LOW);

  } 
  else {
    lcd.print(range);
    lcd.print(" cm");
    Serial.println(range);
    delay(200);
      if(range <20)
    {
    digitalWrite(buzz,HIGH);
    digitalWrite(led,HIGH);
    }
    else
    {
    digitalWrite(buzz,LOW);
    digitalWrite(led,LOW);
    }
  }

  delay(200); 
}
