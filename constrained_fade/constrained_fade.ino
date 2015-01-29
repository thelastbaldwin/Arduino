int led = 9;           // the pin that the LED is attached to
int brightness = 0; // how bright the LED is
double t = 0.0;
double speed = 0.1;

// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
} 

// the loop routine runs over and over again forever:
void loop()  { 
  t += speed;
  // set the brightness of pin 9:
  float sinVal = sin(t);
  brightness = int(128.0 + sin(t) * 64.0);
  analogWrite(led, brightness);    
  delay(30);                            
}

