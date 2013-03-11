const int ARSIZE = 4; //size of all the arrays. 
int ledPins[ARSIZE] = {13, 2, 4, 7};  //pins, duh 
long interval[ARSIZE]; //interval for each LED
long previousMillis[ARSIZE]; // will store last time LED was updated
int ledState[ARSIZE];
unsigned long currentMillis; 

void setup() {
  //set all pins in array as outputs, initialize values
  for(int i = 0; i < ARSIZE; i++){
    pinMode(ledPins[i], OUTPUT); //<-- this was breaking it
    interval[i] = 0;
    previousMillis[i] = 0;
    ledState[i] = LOW;
  }  
  Serial.begin(9600); //gives us access to serial monitor for debugging purposes
  currentMillis = 0;
}

void loop()
{
  //go through each pin in our array
  for(int i = 0; i <  ARSIZE; i++){
    currentMillis = millis();
    
    if((currentMillis - previousMillis[i]) > interval[i]){   
      
      previousMillis[i] = currentMillis;   
      
         // if the LED is off turn it on and vice-versa:
        if (ledState[i] == LOW){
           ledState[i] = HIGH;
           interval[i] = 1000 * random(1, 5); // the time to be on
        }
        else
        {
            ledState[i] = LOW;
            interval[i] = 1000 * random(3, 5); // the time to be off
        }
        Serial.print("PIN Number: ");
        Serial.print(ledPins[i]);
        Serial.print("\n");
        Serial.print("Pin State: ");
        Serial.print(ledState[i]);
        Serial.print("\n");          
    }
    digitalWrite(ledPins[i], ledState[i]);
  }
}
