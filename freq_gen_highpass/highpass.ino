// C++ code
//

int GEN_SIG = 3;
long int pot_signal;
float frequency;
// int pwm_value;
// float t = 0;
// float dt = 0.001;

void setup()
{
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(GEN_SIG, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // pot_signal = analogRead(A2)/100+1;
  pot_signal = map(analogRead(A2), 0, 1023, 1000, 10000); 
  frequency = (int)(1000000.0/(2*pot_signal));
  Serial.println("===========");
  Serial.println("Frequency in Hz:");
  Serial.println(frequency);
  Serial.println("Delay in ms:");
  Serial.println(2*pot_signal);
  Serial.println("============");
  
  // To generate sinus function
  // pwm_value = 127.5 + 127.5 * sin(2 * PI * frequency * t);
  // analogWrite(GEN_SIG, pwm_value);
  // t += dt;
  // delayMicroseconds((int)(dt * 1e6));
  
  // To generate 100 square waves, instead:
   for(int i = 0; i<100; i++){
     digitalWrite(GEN_SIG, HIGH);
     delayMicroseconds(pot_signal);
     digitalWrite(GEN_SIG, LOW);
     delayMicroseconds(pot_signal);
    }
  
  }