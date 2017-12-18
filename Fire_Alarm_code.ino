int greenLed = 13;
int Smoke = A5;
int sensorThres = 200;
int buzzer = 11;
int i = 0;
int redLed1 = 8;
int redLed2 = 9;

void setup() {
  pinMode(greenLed, OUTPUT);
  pinMode(redLed1, OUTPUT);
  pinMode(redLed2, OUTPUT);
  pinMode(Smoke, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(Smoke);

  Serial.print("Pin A3: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    for (i = 200; i <=800; i++) // Wen a frequency sound
    {
      digitalWrite(redLed1, HIGH);
      digitalWrite(redLed2, LOW);
      tone(buzzer, i) ;// send voice
      delay (1) ;// Delay 1ms
    }
    delay(100);
    for (i = 800; i >=200; i--) // Wen a frequency sound
    {
      digitalWrite(redLed1, LOW);
      digitalWrite(redLed2, HIGH);
      tone(buzzer, i) ;// send voice
      delay (1) ;// Delay 1ms
    }
    noTone(buzzer);
  }
  else{
    digitalWrite(redLed1, LOW);
    digitalWrite(redLed2, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(greenLed, HIGH);
    delay(100);
    digitalWrite(greenLed, LOW);
    delay(500);
  }
  delay(100);
}
