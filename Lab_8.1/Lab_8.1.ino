// include the library code:
#include <LiquidCrystal.h>
  const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int counter = 0;
int seconds = 0;
int x = 0;
int y = 0;
unsigned long int timer;
unsigned long int timer2;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(3, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3), helper2, RISING);
  attachInterrupt(digitalPinToInterrupt(2), helper1, RISING);
}

void loop() {
  if (!y) {
    timer2 = millis() - timer;

    if (timer2 / 1000 != seconds) {
      seconds = timer2 / 1000;
      lcd.clear();
      lcd.print("We have been");
      lcd.setCursor(0, 2);
      lcd.print("waiting for: ");
      lcd.print(seconds);
    }
  }
  delay(100);
}

void helper1() {
  if (y == 1 && counter != 0) {
    timer = millis();
    x = 0;
  }
  y = 0;
}

void helper2() {
  counter++;
  lcd.clear();
  lcd.print("Interrupt");
  x = 1;
  y = 1;
}
