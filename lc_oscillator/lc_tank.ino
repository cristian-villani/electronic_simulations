// C++ code
//
int mess_number = 100;
int samples[100];
bool SIMULATION_MODE = true;
bool TUNE_MODE = true;
int run_count = 0;
int simulation_count = 50;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  if(!TUNE_MODE){
    run_count = 0;
  }
  else{
    digitalWrite(13, HIGH);
    delayMicroseconds(50); 
    digitalWrite(13, LOW);
    delayMicroseconds(100);  // let the first transient settle
    for (int delay_us = 1800; delay_us <= 2100; delay_us += 20) {
      // print delay value once
      Serial.print("Excitation delay (us): ");
      Serial.println(delay_us);
      delay(5);

      // excite continuously for 3 seconds
      // unsigned long start = millis();
      // while (millis() - start < 1000) {
      for (int pulse = 0; pulse < 50; pulse++) {
        digitalWrite(13, HIGH);
        delayMicroseconds(50);
        digitalWrite(13, LOW);
        delayMicroseconds(delay_us);
      }
      Serial.print("Finished excitation for delay_us = ");
      Serial.println(delay_us);
      delay(5);
      // delay(1000);
    } // next delay_us
    // Stop here forever
    while (1);
  }
}

void loop()
{
  if(SIMULATION_MODE){   // Shows charge/discharge curves
    run_count += 1;
    if(run_count >= simulation_count) SIMULATION_MODE = false;
    digitalWrite(13,HIGH);
    delay(10); //Charge for 10 milliseconds
    digitalWrite(13, LOW);
    delay(10); // Wait for 10 milliseconds free oscillation time
  }
  else{   // Analyze the signal
    digitalWrite(13, HIGH);
    Serial.println("Charging... ");
    delay(10); // Charge for 10 milliseconds
    digitalWrite(13, LOW);
    // for(int i=0; i< mess_number; i++){
    //   samples[i] = analogRead(A1);
    //   delayMicroseconds(10);  // capture LC free oscillation
    // }
    int peak = 0;
    for(int i=0; i<mess_number; i++){
      int val = analogRead(A1);
      if(val > peak && val < 1000) peak = val;
      delayMicroseconds(1);
    }
    Serial.println(peak);  
  }
}