#define red 33
#define green 32
#define buzzer 19
#define echo 18
#define trig 5


long duration;
float distance;

void setup() {
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(115200);
}

void loop() {

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (duration*.0343)/2;

  
  radar();

}

void radar() { 
  if(distance < 20.00){
      tone(buzzer, 600, 500);
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      Serial.print("TOO CLOSE DANGER!!");
      Serial.println(distance);
  } else{
    noTone(buzzer);
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);~
    Serial.print("Distance: ");
    Serial.println(distance);
    delay(100);
  }
}


