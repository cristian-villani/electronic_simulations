# Ultrasonic Distance Measurement with Arduino

## Overview

This experiment demonstrates **distance measurement using an ultrasonic sensor** (e.g. HC-SR04) connected to an Arduino.  
The Arduino generates a short trigger pulse, measures the echo return time, and converts it into a physical distance.

The project focuses on **timing-based measurement**, digital I/O handling, and basic signal interpretation rather than sensor libraries or abstractions.

All experiments were developed and tested using **Tinkercad** simulation.

---

## Objective

- Measure distance using ultrasonic time-of-flight
- Convert timing information into a physical quantity (distance)
- React to sensor input using simple logic (LED threshold)
- Demonstrate precise timing and digital signal handling in embedded software

---

## Experimental Setup

- **Trigger pin (`PIN_SIG`)**: generates a short HIGH pulse
- **Echo pin (`PIN_ECHO`)**: receives the reflected pulse
- **LED output (`PIN_LED`)**: indicates distance below a threshold
- **Serial Monitor**: displays measured distance in centimeters

Distance is calculated from the echo pulse duration using the approximate speed of sound.

---

## Measurement Principle

1. Arduino sends a short trigger pulse to the ultrasonic sensor.
2. The sensor emits an ultrasonic burst.
3. The echo pin goes HIGH for the duration of the sound’s round trip.
4. Arduino measures this duration using `pulseIn()`.
5. Distance is computed as:

```
distance (cm) ≈ duration (µs) / 58
```


This converts time-of-flight into distance.

---

## Results

- Distance values are printed to the Serial Monitor in real time.
- An LED turns ON when the measured distance is below a defined threshold (e.g. 70 cm).
- In Tinkercad simulation, distance changes can be observed by moving the virtual object.

This demonstrates a complete **sense → compute → act** loop.

---

## Technical Notes

### Timing and Precision
- `pulseIn()` measures pulse width in microseconds, suitable for ultrasonic timing.
- Very long or missing echoes are handled via timeout.

### ADC and Floating Point
- No ADC is required for this experiment.
- Floating-point formatting via `sprintf()` is avoided due to limited AVR support.
- Distance values are printed using `Serial.print(value, decimals)`.

### Limitations
- Speed of sound is assumed constant (temperature not compensated).
- Measurement resolution is limited by timing precision.
- Tinkercad simulation approximates real-world behavior.

---

## Tinkercad Simulation

The circuit can be viewed and simulated online:

[Open Ultrasonic Distance Simulation in Tinkercad](https://www.tinkercad.com/things/gQj8CsAMDUa-ultrasound-sensor-led)

This allows experimentation without physical hardware.

---

## Didactic and Learning Purpose

This experiment illustrates:

- Digital pulse generation and timing measurement
- Conversion of raw timing data into physical meaning
- Interaction between software logic and sensor hardware
- Typical limitations encountered in embedded systems

It is intentionally simple and transparent, prioritizing **understanding over abstraction**.

---

## Possible Extensions

- Averaging multiple measurements for noise reduction
- Temperature compensation for speed of sound
- Display distance on an LCD or seven-segment display
- Replace `pulseIn()` with interrupt-based timing

