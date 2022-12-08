---
layout: single
title: "Design of LED traffic light brightness-adaptive system based on microcontroller"
collection: projects
permalink: /projects/project3
excerpt: "*Student Research Training Program(SRTP) of Southwest Jiaotong University [grant 180440]*"
date: 2018-04-20
toc: true
toc_label: "Contents"
---

<a name="top"></a>

# Introduction
<hr>

**1.** This is actually the enlightenment project of my life, which opened the door of my development career. It is the first time for me to apply the abstract knowledges I learned in class into practical engineering tasks. Although it is relatively elementary to look back on now, it is of great significance to me

**2.** The LED traffic lights currently used in various working conditions are mostly of constant luminance, while light sources with constant luminance are easy to be interfered by the environment. Therefore, this project aims to design the brightness-adaptive system of LED traffic lights. The main idea is to endow the automatic function of brightness adjustment to the LED signal lights through the microcontroller(MCU), so as to achieve the effect of energy conservation on the premise of ensuring traffic safety

<br>

# Environment and Tools
<hr>

|Category|Specification|Number|
|:---:|:---:|:---:|
|IDE|Keil uVision5||
|Circuit design|Altium Designer||
|microcontroller|STC15W408AS|x1|
|Electronic components|LED, DuPont line, capacitor...|xN|

<br>

# Design
<hr>

**1.** The hardware part consists of five parts: (corresponding to the numbers in schematic diagram below)
 - *Photosensitive circuit*
 - *Power supply circuit with buck converter*
 - *Microcontroller minimum system*
 - *LED traffic light driving circuit*
 - *Lamp beads check circuit*

**2.** As for the software part, it can be divided into 4 parts:
 - *Pulse-Width Modulation(PWM)*
 - *Analog to Digital(AD) sampling*
 - *traffic light driving*
 - *Fault detection*

**3.** This design takes <u>STC15</u> as the controller, and uses the photoresistor to collect the environment luminance for LED brightness adjustment, and uses the built-in AD function of MCU to calculate the value of LED lighting current as the judgment basis for whether lights fail

<br>

# Development
<hr>

**1. Schematic diagram**

<div align="center"> <img alt="p3-1" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj3-1.jpg?raw=true" width="700px"></div>

**2. PCB diagram**

<div align="center"> <img alt="p3-2" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj3-2.png?raw=true" width="460px"> </div> 

**3. Source Code (C)**

```c

```

**4. Figure**

<div align="center"> <img alt="p3-1" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj3-8.jpg?raw=true" width="580px"></div>
<br>

# Experiment
<hr>

<div align="right"><a class="top-link hide" href="#top"><font size="6"><b>↑</b></font></a></div><br>
