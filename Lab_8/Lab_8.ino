// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
unsigned long time;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  delay(1000);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  Serial.print("Time: ");
  time = millis();
  lcd.setCursor(0,0);
  lcd.print("We have been");
  lcd.setCursor(0,1);
  lcd.print("waitng for:");
  lcd.print(time);

  
  

  Serial.println(time);    //prints time since program started
  delay(1000);
  lcd.clear();

}
