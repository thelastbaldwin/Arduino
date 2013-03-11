//hook up leds to pins 0,1, and 2 and this will cycle through them like
//traffic lights

const int redPin = 7;
const int yellowPin = 4;
const int greenPin = 2;
int input;

void setup(){
  // initialize serial communication with computer:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop(){
  input = Serial.read(); //read serial
  Serial.println(input);
  switch(input){
    case redPin:
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, LOW);
      digitalWrite(redPin, HIGH);
      break;
    case yellowPin:
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, HIGH);
      break;
    case greenPin:
      digitalWrite(redPin, LOW); 
      digitalWrite(yellowPin, LOW);
      digitalWrite(greenPin, HIGH);
      break;
  } 
  
}
