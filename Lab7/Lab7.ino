//Names: Syed S Rahman, Abdullah Kidwai
//netIDs: srahma35, akidwa2

int input = 0;
int counter = 0;
int prevState = 0;
int buttonState = 0;

void setup() 
{
  // put your setup code here, to run once
  pinMode(12, INPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(12);  //reading the value from button
  
  while(Serial.available() > 0)
  {
    input = Serial.read();
    
    if(input == 0)
    {
      digitalWrite(11, LOW);
    }
    else if (input == 1)
    {
      digitalWrite(11, HIGH);
    }
  }
  
  if(buttonState != prevState)
  {
    if(buttonState == HIGH)
    {
      counter++;
      Serial.write(counter%2);
    }
  }

  prevState = buttonState;
  
}
