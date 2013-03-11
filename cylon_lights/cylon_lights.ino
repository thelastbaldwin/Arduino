const int ARSIZE = 8;
int myPins[ARSIZE] = {2, 3, 4, 5, 6, 7, 8, 9};
int ledState[ARSIZE];

//analog sensor
int sensorPin = A0;
int speed = 0;

void setup(){
  for(int i = 0; i < ARSIZE; i++){    
    pinMode(myPins[i], OUTPUT);
    ledState[i] = LOW;
  }
}

void loop(){
  speed = analogRead(sensorPin);
  
  for(int i = 0; i < ARSIZE; i++){
    delay(speed);
    if(i > 0 && i < ARSIZE -1){
       digitalWrite(myPins[i-1], LOW);
      digitalWrite(myPins[i], HIGH);
      digitalWrite(myPins[i + 1], LOW);
    }else if(i == 0){
      digitalWrite(myPins[i + 1], LOW);
      digitalWrite(myPins[i], HIGH);
      digitalWrite(myPins[ARSIZE - 1], LOW);
    }
    else if(i == ARSIZE - 1){
      digitalWrite(myPins[i-1], LOW);
      digitalWrite(myPins[i], HIGH);
    }
  }
  
  for(int i = ARSIZE-1; i >= 0; i--){
    delay(speed);
    if(i > 0 && i < ARSIZE -1){
       digitalWrite(myPins[i-1], LOW);
      digitalWrite(myPins[i], HIGH);
      digitalWrite(myPins[i + 1], LOW);
    }else if(i == 0){
      digitalWrite(myPins[i + 1], LOW);
      digitalWrite(myPins[i], HIGH);
      digitalWrite(myPins[ARSIZE - 1], LOW);
    }
    else if(i == ARSIZE - 1){
      digitalWrite(myPins[i-1], LOW);
      digitalWrite(myPins[i], HIGH);
    }
  }
}
