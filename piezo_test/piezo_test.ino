const int LENGTH= 4; //1024 only takes up 4 bytes, will be a total of 6 when sent with println
const int THRESH = 3;
int sensorPin = A2;
int val = 0; //value read from sensor
char buffer[LENGTH];
 
void setup(){
  Serial.begin(9600);
  pinMode(sensorPin, INPUT); //declare the ledPin as an OUTPUT
}
 
void loop(){
     
  val = 0;
  if(Serial.available() > 0){
    val = analogRead(sensorPin)/THRESH; //actual value
    sprintf(buffer, "%04d", val); //convert to string and pad with zeros
    Serial.println(buffer);
  }
  Serial.flush();

}
