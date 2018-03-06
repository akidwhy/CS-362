// include the library code:

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
int i = 0;
int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the sensor divider
int passiveBuzzer = 15;
int buzzerReading;
int potentiometerReading;


void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  photocellReading = analogRead(photocellPin);
  potentiometerReading = analogRead(1);

//  while(i <= potentiometerReading){
//    potentiometerReading = analogRead(1);
//    Serial.print("Potentiometer reading = ");
//  Serial.println(potentiometerReading);
//    //i = potentiometerReading;
//    tone (8, potentiometerReading);
//    if( potentiometerReading == 1023){
//      break;
//    }
//  }
  //potentiometerReading = 0;
  while(i <= potentiometerReading){
    potentiometerReading = analogRead(1);
    tone (8, potentiometerReading);
  if (photocellReading < 400) {
      //tone(15, 200);  
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
  }
  else if (photocellReading < 500) {
      //tone(15, 400); 
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
  } 
  else if (photocellReading < 600) {
      //tone(15, 600); 
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
  }
  else if (photocellReading < 800) {
     // tone(15, 800); 
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
  } 
  else {
      //tone(15, 1000); 
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
  }
    break;
  }
  
  // delay at the end of the full loop:
  delay(100);

}


