/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int input;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);   
  Serial.begin(9600);  
}

// the loop routine runs over and over again forever:
void loop() {
  input = Serial.read();
  Serial.println(input);
  
  if(input == 1){
    for(int i=0; i < 10; i++){
      digitalWrite(led, HIGH); 
      delay(100);              
      digitalWrite(led, LOW); 
      delay(100);  
    }
  }
}
