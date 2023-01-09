---
layout: single
title: "Verification and recurrence of ***** vulnerability in the wireless communication system of China Urban Rail Transit"
collection: projects
permalink: /projects/project1
excerpt: "*This vulnerability has been submitted to [China National Vulnerability Database of Information Security](https://www.cnnvd.org.cn/home/childHome), numbered: CNNVD-202204-3571*"
date: 2022-04-15
toc: true
toc_label: "Contents"
---

<a name="top"></a>

# Introduction
<hr>

**1.** First let me explain why there are "\*" in the title. Since this vulnerability currently exists in many subway lines of China, once it is disclosed before CNNVD officially publishes the announcement (after the vulnerability is announced, the subway communication systems will be upgraded and fixed), it has the potential to be used by criminals to further cause severe social harm. Therefore, **part of this project is confidential**, and I don't even know the specific name of this vulnerability

**2.** Then you may ask that **am I secret-related personnel?** No, I am not. In effect, the project is divided into 2 parts and are studied by 2 group of people separately. The goal of the first part(theoretic) is to figure out the specific rationale behind this vulnerability and how it can be exploited by attacks, obviously people working on this part are secret-related. They have already finished their work and drew us a conclusion that it can be exploited by the **man-in-the-middle(MITM)** attack

**3.** According to the theoretic instruction, another group of people (me and 2 younger students) are summoned to achieve the recurrence and verification of the MITM attack in the subway wireless communication system, which becomes the second part(practical) of the project. **To be more specific**, we have to build an LTE (the version used in subway) experimental platform to actually conduct the MITM to prove that this attack indeed can be implemented in the system
 - *Notice that we only implement basic MITM attack without further exploiting this vulnerability (Otherwise we would become secret-related as well* 🤐 *)*

<br>

# Notice
<hr>

Since this project is about to be finished, **quite a lot** of the trial and error processes I recorded earlier in this article have been deleted, leaving only the **last feasible solution**
 - *For example, as for the LTE networking devices. At first, we even used a [real 4G base station](https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj1-0.jpg?raw=true). Later, we chose an elementary (cheap) kind of Software Defined Radio(SDR) equipment called "[LimeSDR](https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/limesdr.jpg?raw=true)". Finally, we adopted the more professional USRP equipment*

<br>

# Environment and Tools
<hr>

|Category|Specification|Number|
|:---:|:---:|:---:|
|IDE|Clion2022||
|LTE Stack|srsRAN 21.04||
|SDR|Ettus USRP b200mini|x4|
|PC|Desktop<br>Laptop|x1<br>x2|
|OS|Ubuntu18.04|x3|
|Antenna||xN|
|Metallic Enclosure|Iron box<br>Aluminum box|x2<br>x2|

<br>

# Design
<hr>

## Overview

**1.** Thanks to researchers from German for publishing the paper "[Breaking LTE on layer two](https://ieeexplore.ieee.org/document/8835335)" which provides us with lots of instructions on MITM or named in the paper as "aLTEr" attack against LTE. However, these instructions only stay at the **theoretical level**, which means that we still need to do a lot of groping work for the actual implementation of this attack

**2.** A normal LTE communication is like:
<div align="center"> <img alt="p1-2" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj1-2.png?raw=true" width="360px"> </div> <br>

What we have to do is to insert the pseudo base station into the normal communication link and tamper with a piece of data:
<div align="center"> <img alt="p1-3" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj1-3.png?raw=true" width="760px"> </div> <br>

**3.** The problems and difficulties are:
 - *In LTE protocol, data will be encrypted or decrypted once enter the PDCP layer, but the pseudo base station does not have the valid key to do that*
 - *Some channel parameters change in real time, which makes it difficult for the pseudo base station to maintain a stable connection*


## Malicious Relay Establishment

**1.** A normal LTE uplink communication process is shown below: (The function of each layer please refer to [here](https://www.tutorialspoint.com/lte/lte_protocol_stack_layers.htm))
<div align="center"> <img alt="p1-4" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj1-4.png?raw=true" width="320px"> </div> <br>

**2.** To cope with the first problem mentioned above, we could only relay data under the PDCP layer (at the RLC layer) by <u>socket</u>: 
 - *As the PDCP layer of our pseudo station doesn't have the right key to decrypt data, we cannot let the data continually going upper but relay the ciphertext directly*

<div align="center"> <img alt="p1-5" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj1-5.png?raw=true" width="740px"> </div>

**3.** To realize the relay, or in other words, to establish the LTE connection, we have to go through the following steps: 
 - *In fact, there is a process called PLMN selection (including cell search) before them. But this part has no relation with our research, so we skip it here*

<div align="center"> <img alt="p1-7" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj1-7.png?raw=true" width="720px"> </div><br>

**4.** There are 3 transmission modes of RLC layer: **Transparent Mode (TM), Acknowledged Mode (AM) and Unacknowledged Mode (UM)**. The "TM" and "AM" mode are used to transmit data for the connection establishment; "UM" mode is later used to transmit the user data, so it doesn't appear in the pic above
 - ***step 1-6: RRC connection (1-2 in TM mode)***
   - *Generally, these steps are used to establish the **initial connection** between normal devices and our pseudo devices, we don't need to modify them*
   - *Many tests have proved that RRC connection can be completed directly by pseudo equipment without forwarding the reply of normal equipment. So, to realize the relay connection, **we only need to relay all data in subsequent steps***
 - ***step 7-16: RRC connection reconfiguration & Attach (All in AM mode)***
   - *7: Attach request and PDN connectivity request (PDN connectivity request aims to establish the "default bearer" between UE and P-GW)*
   - *8-9: Authentication (Confirm the identity between UE and MME and establish the EPS security context)*
   - *10-13: Security mode (This process will enable the EPS security context to activate the communication between UE and MME through the confirmed code)*
   - *14-16: When 14 arrives, UE and MME will establish the EMM-CONNECTED status, then MME will send UE an "activate default/dedicated bearer context request", and UE will reply a corresponding "accept" to establish the "EPS bearer"*
   - ***To be honest, we don't need to know every step very well while relaying them, just locate "AM" mode in the source code and forward all the data come through***

## User Data Tampering

**1.** The rationale behind user data tampering is already illustrated in detail in the [Breaking LTE on layer two](https://ieeexplore.ieee.org/document/8835335). In short, **although there is <u>confidentiality protection</u>(encryption) in LTE, we could still tamper with data in cyphertext form since LTE in specific version lacks the <u>integrity protection</u>**

<div align="center"> <img alt="p1-8" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj1-8.png?raw=true" width="760px"> </div><br>

# Development
<hr>

## Experimental Platform

**1.** The conceptual structure of the platform is shown below:

<div align="center"> <img alt="p1-9" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj1-9.png?raw=true" width="540px"> </div><br>

**2.** The physical establishment of the platform is shown below:
 - *In the middle are actually 2 displayer screens we've connected to the single **desktop***
 - *The 2 "silver" boxes under the laptops are the **shield boxes** which seal **2 SDR device** in separately*

<div align="center"> <img alt="p1-6" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj1-6.png?raw=true" width="760px"> </div><br>

### Hardware
**1. SDR-USRP B200mini:** We could deploy LTE stack on such device to simulate the UE and eNodeB+EPC separately. (base station and core network should be deployed on a single SDR) It can be easily connected to a computer by its self-contained USB cable

<div align="center"> <img alt="p1-1" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj1-1.jpg?raw=true" width="400px"> </div><br>

**2. Shield box:** During our early experiments, we found that the connection between 2 SDR device would be frequently disturbed by the wireless signal of the national communication carriers. Thus, we decide to build 2 shield boxes to isolate our device from the public network (in our case, we can operate under ideal conditions)

<div align="center"> <img alt="p1-10" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj1-10.jpg?raw=true" width="600px"> </div>
<div align="center"> <img alt="p1-11" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj1-11.jpg?raw=true" width="600px"> </div><br>

### Software


## LTE Source Code Modification


<div align="right"><a class="top-link hide" href="#top"><font size="6"><b>↑</b></font></a></div><br>
