// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int i;
int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the sensor divider

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("Abdullah Kidwai");
  
  delay(1000);
}

void loop() {
  photocellReading = analogRead(photocellPin);
  Serial.print("Analog reading = ");
  Serial.println(photocellReading);     // the raw analog reading
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Abdullah Kidwai");
  if (photocellReading < 400) {
    lcd.setCursor(0, 1);
    lcd.print("Dark");
  } else if (photocellReading < 500) {
    lcd.setCursor(0, 1);
    lcd.print("Partially dark");
  } else if (photocellReading < 600) {
    lcd.setCursor(0, 1);
    lcd.print("Medium");
  } else if (photocellReading < 800) {
    lcd.setCursor(0, 1);
    lcd.print("Partially Lit");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Fully lit");
  }
    
    
  
  // delay at the end of the full loop:
  delay(100);

}


