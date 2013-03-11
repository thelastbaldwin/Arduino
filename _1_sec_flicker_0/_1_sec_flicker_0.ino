//hook up leds to pins 0,1, and 2 and this will cycle through them like
//traffic lights

const int redPin = 2;
const int yellowPin = 1;
const int greenPin = 0;

void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop(){
  digitalWrite(redPin, HIGH);
  delay(500);
  digitalWrite(redPin, LOW);
  
  digitalWrite(yellowPin, HIGH);
  delay(500);
  digitalWrite(yellowPin, LOW);
  
  digitalWrite(greenPin, HIGH);
  delay(500);
  digitalWrite(greenPin, LOW);
}
