//Global variables
const int ledPinR1 = 13;
const int ledPinG1 = 12;
const int ledPinR2 = 10;
const int ledPinY2 = 9;
const int ledPinG2 = 8;
const int buttonPin = 2; 

int buttonState = 0;
int prevButtonState = HIGH;

void setup(){
  //Setting all pins to input/output
  pinMode(ledPinR1, OUTPUT);
  pinMode(ledPinG1, OUTPUT);
  pinMode(ledPinR2, OUTPUT);
  pinMode(ledPinY2, OUTPUT);
  pinMode(ledPinG2, OUTPUT);
  pinMode(buttonPin, INPUT);
}
 
void loop(){
  //Setting initials: green light for cars, read for walkers
    digitalWrite(ledPinG2, HIGH);
    digitalWrite(ledPinR1, HIGH);
    digitalWrite(ledPinG1, LOW);
    digitalWrite(ledPinR2, LOW);
    digitalWrite(ledPinY2, LOW);
  
  //Checking if button is pushed
  buttonState = digitalRead(buttonPin);
//Check if button is pressed == LOW
  if ((buttonState == LOW) && (prevButtonState == HIGH)) {
    delay(1000);
    digitalWrite(ledPinR2, LOW);        //STATE 4
    digitalWrite(ledPinY2, HIGH);       //yellow light for cars
    delay(1000);
    digitalWrite(ledPinG2, LOW);        //STATE 1
    digitalWrite(ledPinR2, HIGH);       //red light for cars
    delay(2000);
    digitalWrite(ledPinR1, LOW);        
    digitalWrite(ledPinG1, HIGH);       //green light for walkers
    delay(5000);
    digitalWrite(ledPinG1, LOW);
    digitalWrite(ledPinR1, HIGH);       //red light for walkers
    delay(2000);
    digitalWrite(ledPinR2, HIGH);       //STATE 2
    digitalWrite(ledPinY2, HIGH);       //yellow and red for cars
    delay(1000);
    digitalWrite(ledPinR2, LOW);        //STATE 3
    digitalWrite(ledPinY2, LOW);
    digitalWrite(ledPinG2, HIGH);       //green light for cars 
  }
  else {
    digitalWrite(ledPinG1, LOW); // turns green LED off
  }
  prevButtonState = buttonState; //sets previous button state
  
}
