//this code does not allow the the date of 29 for the month of febuary
#include <Time.h>
#include <TimeLib.h>
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int hr;
int minu;
int sec;
int days;
int mnth;
int yr;
int user = 0;
bool boo = false;

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  delay(1000);
}
//5:45:15 21/7/2000
//23:59:57 31/12/1999
//23:59:57 28/2/2001
void loop() {
// send data only when you receive data:
// int ser= Serial.available();
// Serial.println("OKY");
// Serial.println(ser);
                    
 while (Serial.available() > 2) {
     hr = Serial.parseInt();
     minu = Serial.parseInt();
     sec = Serial.parseInt();
     mnth = Serial.parseInt();
     days = Serial.parseInt();
     yr = Serial.parseInt();

     if(hr < 0 || hr > 23){
      lcd.clear();
      Serial.print("Incorrect Hour");
      lcd.print("Invalid hour.");
      break;
     }
     if(minu < 0 || minu > 59){
      lcd.clear();
      Serial.print("Incorrect Min");
      lcd.print("Invalid minute.");
      break;
     }
     if(sec < 0 || sec > 59){
      lcd.clear();
      Serial.print("Incorrect Sec");
      lcd.print("Invalid seconds.");
      break;
     }

     if(mnth >= 1 && mnth <=12){
      if(mnth == 1 || mnth == 3 || mnth== 5 || mnth == 7 || mnth == 8 || mnth == 10 || mnth == 12){
        if (days >= 1 && days <= 31){
          if(yr < 1000 || yr > 9999){
            lcd.clear();
            Serial.print("Incorrect Year");
            lcd.print("Invalid year");
            break;
          }
        }
        else{
          lcd.clear();
          Serial.print("Incorrect day");
          lcd.print("Invalid day");
          break;
        }
      }
      else if(mnth == 4 || mnth == 6 || mnth == 9 || mnth == 11){
        if (days >= 1 && days<= 30){
          if(yr < 1000 || yr > 9999){
            lcd.clear();
            Serial.print("Incorrect Year");
            lcd.print("Invalid year");
            break;
          }
        }
        else{
          lcd.clear();
          Serial.print("Incorrect Day");
          lcd.print("Invalid day");
          break;
        }        
      }

      //check feb
      else if(mnth == 2){
        if (days >= 1 && days <= 28){
          if(yr < 1000 || yr > 9999){
            lcd.clear();
            Serial.print("Incorrect Year");
            lcd.print("Invalid year");
            break;
          }
        }
        else{
          lcd.clear();
          Serial.print("Incorrect Day");
          lcd.print("Invalid day");
          break;
        }        
      }
    }
    else{
      lcd.clear();
      Serial.print("Incorrect Month");
      lcd.print("Wrong month");
      break;
    }

     
        
    // say what you got:
    Serial.print("Hour: ");
    Serial.println(hr);
    Serial.print("Minute: ");
    Serial.println(minu);
    Serial.print("Second: ");
    Serial.println(sec);
    Serial.print("Month: ");
    Serial.println(mnth);
    Serial.print("Day: ");
    Serial.println(days);    
    Serial.print("Year: ");
    Serial.println(yr);

    setTime(hr,minu,sec,days,mnth,yr);
    boo = true;
                    
  }
        if(boo == true){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print(hour());
          lcd.print(":");
          lcd.print(minute());
          lcd.print(":");
          lcd.print(second());
          lcd.setCursor(0, 1);
          lcd.print(month());
          lcd.print("/");
          lcd.print(day());
          lcd.print("/");
          lcd.print(year());
          delay(500);
        }  
            
}

