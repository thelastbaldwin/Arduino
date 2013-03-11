void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int input = Serial.read(); //read serial
  switch(input){
    case 1: //If processing passes a '1' do case one
      if(input == 1){
        digitalWrite(13, HIGH);
        delay(1000);
      }
      break;
    case 2:
      if(input == 2){ //If processing passes a '2' do case two
        digitalWrite(13, LOW);
        delay(1000);
      }
      break;
  }
}
