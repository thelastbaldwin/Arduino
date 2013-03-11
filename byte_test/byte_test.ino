char * testVal = "500";

void setup(){
  Serial.begin(9600);
}

void loop(){
  Serial.println(strlen(testVal));
}
