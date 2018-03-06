// constants won't change. They're used here to set pin numbers:
const int buttonUp = 12;     // the number of the pushbutton pin
const int buttonDown = 4;

// variables will change:
int buttonStateUp = 0;         // variable for reading the pushbutton status
int buttonStateDown = 0;
int counter = 0;
int val;                        // variable for reading the pin status
int val2;                       // variable for reading the delayed/debounced status
int buttonState;
int lightMode = 0;


void setup() {
  Serial.begin(9600);   
  pinMode(buttonUp, INPUT);
  pinMode(buttonDown, INPUT);
  pinMode(11, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  buttonState = digitalRead(buttonUp);
}

void loop() {
  val = digitalRead(buttonUp);      // read input value and store it in val
  Serial.print("Button 1: ");
  Serial.println(digitalRead(buttonUp));
  Serial.print("\n");
  delay(10);                         // 10 milliseconds is a good amount of time
  val2 = digitalRead(buttonUp);     // read the input again to check for bounces
  Serial.print("Button 2: ");
  Serial.println(digitalRead(buttonUp));
  Serial.print("\n");
  if (val == val2) {                 // make sure we got 2 consistant readings!
    if (val != buttonState) {          // the button state has changed!
      if (val == LOW) {                // check if the button is pressed
        if (lightMode == 0) {          // is the light off?
          lightMode = 1;               // turn light on!
          digitalWrite(11, HIGH);
          digitalWrite(8, HIGH);
          digitalWrite(7, HIGH);
        } 
          else {
          lightMode = 0;               // turn light off!
          digitalWrite(11, LOW);
          digitalWrite(8, LOW);
          digitalWrite(7, LOW);
        }
      }
    }
    buttonState = val;                 // save the new state in our variable
    counter++;
  }

}
