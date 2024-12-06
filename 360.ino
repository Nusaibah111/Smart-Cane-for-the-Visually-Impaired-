const int sndTrig = 9;
const int sndEcho = 10;
const int humsen = 8;
const int buzzer = 11;
const int motorA = 6;
const int motorB = 7;

int distance;
int duration_us;
int moisture;
bool motoron=true;

void setup() {
pinMode(sndTrig, OUTPUT);
pinMode(sndEcho, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(humsen,INPUT);
Serial.begin(9600);
}

void loop() {
  digitalWrite(sndTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sndTrig, LOW);
  duration_us = pulseIn(sndEcho, HIGH);
  distance = 0.017 * duration_us; //Converts distance to Centimeter
  
  moisture = digitalRead(humsen);

if ((distance>1 && distance <= 15) || moisture==0){
  motoron=false;
  if (motoron==false){
    Serial.println("motor on");
    digitalWrite(motorA,HIGH);
    digitalWrite(motorB,LOW);
    delay(500);
    digitalWrite(motorA,LOW);
    digitalWrite(motorB,LOW);
    motoron=true; 
    Serial.println("motor off");
  }

if ((distance>1 && distance <= 15) && moisture==0){
  tone(buzzer, 1500); //1500Hz Frequency
}


}
else{
  noTone(buzzer);
}

//Serial monitor code for debugging

//For distance
Serial.print("Distance: ");
Serial.println(distance);

//For moisture
Serial.print("Moisture: ");
Serial.println(moisture);
}