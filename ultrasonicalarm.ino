#define trigPin 2
#define echoPin 3
#define ledPin 7
#define buzzerPin 8

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  long duration, distance_cm;
  
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  
  duration = pulseIn(echoPin, HIGH);
  
  
  distance_cm = duration / 58;
  

  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  
  if (distance_cm < 100) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);  
  } else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);  
  }
  
  delay(200);  
}



