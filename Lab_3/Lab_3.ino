// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int i;

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
  
  //bottomRow(15);
  for(i=15; i > -44; i--){
    if(i==-1){
      i = -9;
    }
    if(i == -17){
      i = -33;
    }
    lcd.setCursor(i,2);
    lcd.print("\"Live for yourself\" ");
    //for debugging
    Serial.print(i);  
    Serial.print("\n");
    delay(500);
    
    
  }
  // delay at the end of the full loop:
  delay(1000);

}


