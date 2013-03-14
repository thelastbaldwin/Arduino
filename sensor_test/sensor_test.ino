int sensorPin = A1;
int val = 0;

void setup(){
  Serial.begin(9600);
  pinMode(sensorPin, INPUT); //declare sensorPin as input
}

void loop(){
    val = analogRead(sensorPin); //actual value
    Serial.println(val);
}


