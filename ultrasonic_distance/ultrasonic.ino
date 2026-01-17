// C++ code
//

int PIN_LED = 13;
int PIN_SIG = 7;
int PIN_ECHO = 8;

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_SIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
}

void loop()
{
  delay(1);
  digitalWrite(PIN_SIG, LOW);
  delayMicroseconds(20);
  digitalWrite(PIN_SIG, HIGH);
  delayMicroseconds(30);
  digitalWrite(PIN_SIG, LOW);
  unsigned long duration = pulseIn(PIN_ECHO, HIGH, 30000);
  // Serial.println(duration);
  double distance = duration/58.0;
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  if(distance < 70){
    digitalWrite(PIN_LED, HIGH);
  }
  delay(10);
  digitalWrite(PIN_LED, LOW);
  // delay(100);
}