
// C++ code
//
const int MAX_SIGNALS = 250;
int SIGNAL_PIN = 3;
int signal_array[MAX_SIGNALS];
int array_index = 0;
int TIME_STEP = 1; // Set time step 10 Microseconds
unsigned long start_time = micros();
unsigned long time_array[MAX_SIGNALS];

void setup()
{
  Serial.begin(9600);
  pinMode(SIGNAL_PIN, INPUT);
}

void loop()
{
  if(array_index < MAX_SIGNALS){
  	signal_array[array_index] = digitalRead(SIGNAL_PIN);
  	// delayMicroseconds(TIME_STEP);
    time_array[array_index] = micros();
    array_index += 1;
    delayMicroseconds(5);
  }
  else{
    Serial.println("Analysing signal:");
    int max_sign = 9999;
    int n_max = 0;
    int old_max_index = MAX_SIGNALS + 1;
    bool g_max = false;
    for(int ai = 0; ai < MAX_SIGNALS; ai++){
      Serial.print(signal_array[ai]);
      Serial.print("  ");
      Serial.print(time_array[ai]);
      Serial.println(" ");
    }
    Serial.println(".");
    Serial.println("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
    for(int ai = 0; ai < MAX_SIGNALS; ai++){
      if(signal_array[ai] < max_sign){
        max_sign = signal_array[ai]; // Signal increasing, storing
        g_max = true;
        old_max_index = ai;
      }
      else{  // Signal decreasing, looking for the second maximum;
        n_max += 1;
        max_sign = 9999;
        if(g_max){
          Serial.println("=========================");
          Serial.print("Found maximum n. ");
          Serial.print(n_max);
          Serial.print(" for index = ");
          Serial.print(ai-1);
          Serial.print(": ");
          Serial.println(signal_array[ai-1]);
          Serial.print("Estimated delay: ");
          // int est_del = (ai-old_max_index) * TIME_STEP; 
          long int est_del = time_array[ai] - time_array[old_max_index];
          Serial.print(est_del);
          Serial.println(" Microseconds");
          Serial.print("Estimated frequency: ");
          Serial.println((long)(double(1.0/est_del)*500000));
          Serial.println("==========================");
          g_max = false;
        }
        old_max_index = ai;
        delay(10);
      }
    }
    array_index = 0;
    delay(1000);
  }
}