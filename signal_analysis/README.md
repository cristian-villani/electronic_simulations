# PWM Signal Analysis and Frequency Estimation Experiment

![Tinkercad Setup](images/pwm_analysis_setup.png)

## Overview

This project demonstrates **digital PWM signal sampling and frequency estimation using an Arduino Uno**.

- A PWM signal is generated and read from **digital pin 3**.
- The Arduino stores a fixed number of samples along with timestamps (`micros()`).
- The recorded signal is analyzed to estimate the **signal period and frequency**.
- All experiments were developed and tested in **Tinkercad**. A screenshot of the setup is included in the repository.

This experiment focuses on **timing behavior, sampling limitations, and digital signal analysis** in a simulated embedded environment.

---

## Setup Instructions

1. Open the project `.ino` file in Arduino IDE or Tinkercad.
2. Connect the PWM signal source to **digital pin 3**.
3. (Optional – experimental improvement) Connect the same signal to **digital pin 2** for interrupt-based measurement.
4. Open the Serial Monitor (9600 baud).
5. Run the simulation and observe printed signal samples and computed frequency values.

> Note: The project intentionally uses array-based sampling and `micros()` timing for educational purposes, even though more accurate methods exist.

[Open PWM Signal Analysis in Tinkercad](https://www.tinkercad.com/things/2K7PWbQ63Uu-signalanalysis)

---

## Results

### Raw Sample Collection

- The program collects `MAX_SIGNALS = 250` digital samples.
- Each sample stores:
  - The logic level (0 or 1)
  - The timestamp from `micros()`
- Data is printed to the Serial Monitor before analysis.

This allows inspection of:
- Sampling interval consistency
- Rising and falling edges
- Timing jitter introduced by software delays

### Frequency Estimation

After sampling, the program estimates:

- Time difference between detected peaks
- Signal period (in microseconds)
- Approximate frequency

Frequency is computed as:

```
frequency = 1000000.0 / period; // Hz
```


Since `micros()` returns time in microseconds, one second equals 1,000,000 µs.

---

## Observations

- Sampling is **not strictly uniform** due to:
  - `digitalRead()` execution time
  - `micros()` overhead
  - `delayMicroseconds()` imprecision
  - Serial printing latency
- Tinkercad simulation introduces additional timing jitter.
- Because the signal is digital (0/1), traditional “maximum detection” is conceptually equivalent to detecting **rising edges (0 → 1 transitions)**.
- The frequency estimation is approximate but sufficient for demonstration purposes.

This behavior makes the project a useful example of **software-based timing limitations** in microcontroller environments.

---

## Technical Notes

### Sampling Limitations

- `digitalRead()` is relatively slow compared to direct port access.
- `micros()` has limited resolution and overhead.
- The effective sampling interval is not constant.
- Serial output significantly affects timing when analysis is performed.

As a result, precise waveform reconstruction is not guaranteed.

---

### PWM vs. Edge Detection

Current implementation:
- Reads PWM signal from **pin 3**
- Stores digital samples in an array
- Post-processes data to estimate delay between peaks

Planned improvement:
- Use **pin 2** with `attachInterrupt()` and `RISING` mode
- Measure period directly between two rising edges
- Avoid array sampling and software delay

Interrupt-based measurement is significantly more reliable because it:
- Removes loop timing jitter
- Avoids manual sampling delays
- Measures true edge timing

---

### Alternative (Interrupt-Based) Concept

A more accurate frequency measurement approach:

```
period = current_rise_time - previous_rise_time;
frequency = 1000000.0 / period;
```

Using hardware interrupts allows precise edge timing without relying on sampling loops.

---

## Educational Purpose

This project demonstrates:

- Practical limitations of software timing
- Differences between sampling and edge detection
- Digital vs. analog signal interpretation
- Frequency estimation techniques
- The impact of simulation environments on embedded timing behavior

Even though more precise methods exist, the current implementation is intentionally preserved to document the learning process and experimentation.

