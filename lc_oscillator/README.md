# LC Oscillator & Resonance

## Overview

This experiment demonstrates **LC tank circuit oscillations** using an Arduino-controlled switch.
The Arduino periodically charges the capacitor in an LC circuit and then allows it to discharge freely through the inductor. The resulting oscillations can be visualized with an oscilloscope in **Tinkercad simulation**.

The project focuses on **resonance, timing, and analog signal analysis**, illustrating the interaction between digital control signals and analog circuits.

All experiments were developed and tested using **Tinkercad** simulation.

---

## Objective

* Explore LC tank circuit behavior and resonance
* Visualize charge/discharge oscillations on an oscilloscope
* Measure peak voltages and understand the effect of component values
* Investigate the impact of excitation timing on resonance
* Demonstrate basic analog signal acquisition using Arduino ADC

---

## Experimental Setup

* **Charge resistor (`R_charge`)**: limits current to the capacitor during charging
* **Capacitor (`C`)**: stores energy and participates in oscillations
* **Inductor (`L`)**: stores magnetic energy and participates in oscillations
* **NPN transistor switch**: controlled by Arduino digital pin to start/stop charging
* **Arduino analog input (`A1`)**: measures voltage across LC tank
* **Oscilloscope (simulation)**: visualizes oscillations without disturbing the circuit

---

## Measurement Principle

1. Arduino sets the switch HIGH, charging the capacitor through `R_charge`.
2. Switch goes LOW, allowing the LC circuit to oscillate freely.
3. The Arduino analog input reads the voltage across the LC tank.
4. Peak voltage can be extracted by sampling multiple points during oscillation.
5. By varying the LOW period of the excitation, resonance conditions can be approached.

**Expected resonance period (with L = 10 mH, C = 10 μF):**

T0 = 2 × π × √(L × C) ≈ 1.986 ms

* This corresponds to a resonance frequency of roughly **503 Hz**.

---

## Results

* The oscilloscope shows **sinusoidal oscillations** after each charge pulse.
* Maximum peak occurs when the excitation timing matches the LC natural period.
* The signal decays over time due to resistance and simulation damping.
* In Tinkercad simulation, component values (L, C, R) can be changed to observe the effect on frequency and damping.

---

## Technical Notes

### Timing and Precision

* Arduino uses `delayMicroseconds()` to control excitation timing with sub-millisecond resolution.
* Sampling rate of the ADC is limited (~10 kHz default), so only peak estimation is practical.
* Simultaneous measurement and oscilloscope visualization may require careful timing.

### ADC and Sampling

* Arduino reads analog voltage to determine peak; fast oscillations may not be captured perfectly.
* Trade-off exists between measurement speed and waveform accuracy.

### Limitations

* Simulation does not account for all parasitic effects (e.g., stray resistance or inductance).
* Arduino ADC may undersample fast LC oscillations, producing reduced peak values.
* Pulse width and timing must be chosen carefully to approach resonance; too short or too long pulses reduce oscillation amplitude.
* The Tinkercad oscilloscope may show slightly idealized waveforms compared to real hardware.

---

## Tinkercad Simulation

The circuit can be viewed and simulated online:

[Open LC Oscillator Simulation in Tinkercad](https://www.tinkercad.com/things/hoRI0pb9cX4-lcchargedischargecircuit)

This allows experimentation without physical hardware.

---

## Didactic and Learning Purpose

This experiment illustrates:

* LC tank resonance and oscillation dynamics
* Interaction between digital switching and analog circuits
* Practical measurement limitations using microcontrollers
* The effect of component values and timing on resonance
* Visualizing and analyzing oscillatory signals in a simulation environment

It is intentionally simple and transparent, prioritizing **understanding over abstraction**.

---

## Possible Extensions

* Sweep excitation pulse timing to automatically find peak resonance
* Store peak voltages for different L/C combinations and generate a table of results
* Implement moving average to reduce measurement noise
* Add serial output of waveform data for plotting in Excel or Python
* Replace Arduino sampling with external faster ADC for more accurate waveform capture

