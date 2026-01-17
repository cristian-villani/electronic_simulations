# Electronic Simulations – Arduino Learning Projects

## Overview

This repository contains a collection of **small, learning-oriented Arduino experiments** focused on **embedded programming**, **digital timing**, and **interaction with analog and sensor-based hardware**.

All projects were developed using **Arduino** and simulated in **Tinkercad**, allowing rapid prototyping, visualization of signals, and validation of circuit behavior before moving to physical hardware. The use of simulation tools is intentional and supports both **learning** and **didactic clarity**.

The projects are intentionally simple and focused, each addressing a small but meaningful concept. The goal is not complexity, but **correct reasoning about hardware–software interaction** and clear documentation of results and limitations.

---

## Purpose and Didactic Intent

This repository has a dual purpose:

- **Learning purpose**: to practice embedded programming concepts such as timing, digital I/O, ADC usage, and sensor interfacing.
- **Didactic purpose**: to provide clear, reproducible examples that explain *what happens and why*, reflecting my background as a physics teacher.

Each project includes explanations, screenshots, and comments aimed at making the behavior understandable even to readers with limited electronics background.

---

## Experiments

### Experiment A: Square Wave Generator & RC High-Pass Filter  
📁 `freq_gen_highpass/`

- Generates a programmable square wave on a digital Arduino pin.
- Frequency controlled via a potentiometer.
- Uses microsecond timing for precise signal generation.
- Burst mode used for stable oscilloscope visualization.
- The square wave drives a simple RC high-pass filter.
- Output observed using an oscilloscope (Tinkercad simulation).
- Demonstrates:
  - Frequency-dependent filter behavior
  - Positive and negative voltage spikes due to capacitor charging/discharging
  - Interaction between digital signals and analog components
- Highlights limitations of Arduino ADC when attempting to measure fast analog transients.

---

### Experiment B: Ultrasonic Sensor Distance Measurement  
📁 `ultrasonic_distance/`

- Measures distance using an ultrasonic sensor (e.g. HC-SR04).
- Arduino triggers the sensor and measures echo pulse duration using `pulseIn`.
- Distance calculated from time-of-flight and printed to the Serial Monitor.
- LED indicates when an object is closer than a defined threshold.
- Demonstrates:
  - Digital output (trigger pulse)
  - Digital input timing (echo pulse)
  - Conversion of timing data into physical quantities (distance)
  - Simple decision logic based on sensor input
- Can be simulated in Tinkercad to visualize behavior without hardware.

---

## Repository Structure


```
electronic_simulations/
│
├── README.md # This file: repository overview
│
├── freq_gen_highpass/ # Square wave + RC high-pass filter experiment
│ ├── README.md
│ ├── highpass.ino
│ ├── scope_low_freq.png
│ └── scope_high_freq.png
│
└── ultrasonic_distance/ # Ultrasonic distance measurement experiment
├── README.md
├── ultrasonic.ino
└── circuit.png
```

---

## Simulation and Measurement

- Tinkercad is used for:
  - Circuit design
  - Signal visualization with a virtual oscilloscope
  - Reproducible experiments without hardware constraints
- Screenshots are included to document observed behavior.
- Fast analog signals are intentionally observed via oscilloscope rather than ADC sampling, to avoid misleading results.

---

## Limitations

- Projects prioritize **clarity and learning value** over optimization.
- Arduino ADC sampling rate limits the ability to measure fast analog transients accurately.
- Signal generation is limited to basic waveforms.
- Simulations approximate real-world behavior and should be validated on physical hardware if precision is required.

---

## Audience

This repository is intended for:

- Learners exploring Arduino and embedded programming
- Students interested in signal processing basics
- Recruiters or engineers evaluating embedded software skills
- Educators looking for simple, reproducible teaching examples

---

## Future Extensions

- Additional filter types (low-pass, band-pass)
- Envelope detection and energy estimation
- Physical hardware validation
- More sensor-based experiments

---

This repository documents **learning through experimentation**, with emphasis on understanding, reproducibility, and clear explanation.

