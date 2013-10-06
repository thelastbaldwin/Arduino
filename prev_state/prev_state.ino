//this sketch allows a run of the mill button to have an action when after
//it's finished being depressed

int red = 2;
int orange = 3;
int button = 1;
int prevState = HIGH; //button not pressed

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(red, OUTPUT); 
  pinMode(orange, OUTPUT);  
  pinMode(button, INPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  //when the button is depressed, turn on the light
  if(digitalRead(button) == LOW){
       digitalWrite(red, HIGH);
      digitalWrite(orange, LOW);
      prevState = LOW;
  }
  if(digitalRead(button) == HIGH && prevState == LOW){
    digitalWrite(orange, HIGH);
    digitalWrite(red, LOW);
    prevState = HIGH;
    delay(200);
  }
  else{
    digitalWrite(orange, LOW);
    digitalWrite(red, LOW);
  }
}
