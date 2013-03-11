const int ARSIZE = 8; //led pin array size
int ledPins[ARSIZE] = {2, 3, 4, 5, 6, 7, 8, 9};
int ledState[ARSIZE]; 
int index;

void setup(){
  for(int i = 0; i < ARSIZE; i++){
    pinMode(ledPins[i], OUTPUT);    
  }
  Serial.begin(9600);
}

void loop(){
  //turn off all leds
  for(int i = 0; i < ARSIZE; i++){
     digitalWrite(ledPins[i], LOW);
  }
  
  index = (millis()/100)%ARSIZE;
  digitalWrite(ledPins[index], HIGH); 
}
