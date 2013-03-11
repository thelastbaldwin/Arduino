const int LENGTH= 4; //1024 only takes up 4 bytes, will be a total of 6 when sent with println
int sensorPin = A1;
int val = 0; //value read from sensor
char buffer[LENGTH];

void setup(){
  Serial.begin(9600);
  //pinMode(sensorPin, INPUT); //declare sensorPin as input
}

void loop(){
  val = 0;
  if(Serial.available() > 0){
    val = analogRead(sensorPin); //actual value
    sprintf(buffer, "%04d", val); //convert to string and pad with zeros
    Serial.println(buffer);
  }
  Serial.flush();
}


