const int buttonUp = 12;     // the number of the pushbutton pin
const int buttonDown = 4;

// variables will change:
int buttonStateUp = 0;         // variable for reading the pushbutton status
int buttonStateDown = 0;
int counter = 0;
int prevStateUp = 0;
int prevStateDown = 0;

void setup() {
  pinMode(11, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //reset();
  buttonStateUp = digitalRead(buttonUp);
  if(prevStateUp != buttonStateUp){
    if(buttonStateUp == HIGH){
    counter++;
    Serial.print(counter);
    Serial.print("\n");
  }
  }
  buttonStateDown = digitalRead(buttonDown);
  if(prevStateDown != buttonStateDown){
    if(buttonStateDown == HIGH){
    counter--;
    Serial.print(counter);
    Serial.print("\n");
  }
  }
  

  for(int i = 0; i < counter + 1; ++i) 
  {
    signal( 7, ((i >> 2) % 2) == 1);
    signal( 8, ((i >> 1) % 2) == 1); // Got the idea from 
    signal( 11, ((i >> 0) % 2) == 1); // http://forums.adafruit.com/viewtopic.php?f=20&t=12289
  }
  if(counter > 7){
    counter = 7;
  }
  if(counter < 0){
    counter = 0;
  }
  prevStateUp = buttonStateUp;
  prevStateDown = buttonStateDown;
  delay(100);
}

void signal(int led, bool on) {
  if(on) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
}
