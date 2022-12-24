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
<div align="center"> <img alt="p1-3" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj1-3.png?raw=true" width="750px"> </div> <br>

**3.** The problems and difficulties are:
 - *In LTE protocol, data will be encrypted or decrypted once enter the PDCP layer, but the pseudo base station does not have the key*
 - *Some channel parameters change in real time, which makes it difficult for the pseudo base station to maintain a stable connection*


## Malicious Relay Establishment

**1.** A normal LTE uplink communication process is shown below: (The function of each layer please refer to [here](https://www.tutorialspoint.com/lte/lte_protocol_stack_layers.htm))
<div align="center"> <img alt="p1-4" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj1-4.png?raw=true" width="320px"> </div> <br>

**2.** To cope with the first problem mentioned above, we could only relay data under the PDCP layer by <u>Socket</u>: 
 - *As the PDCP layer of our pseudo station doesn't have the right key to decrypt data, we cannot let the data continually going upper but relay the ciphertext directly*

<div align="center"> <img alt="p1-5" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj1-5.png?raw=true" width="740px"> </div>

**3.** To realize the relay, or in other words, to establish the LTE connection, we have to go through the following steps: 
 - *In fact, there is a process called PLMN selection (including cell search) before them. But this part has no relation with our research, so we skip it here*

<div align="center"> <img alt="p1-7" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj1-7.png?raw=true" width="700px"> </div>

## User data Tampering

<div align="right"><a class="top-link hide" href="#top"><font size="6"><b>↑</b></font></a></div><br>
