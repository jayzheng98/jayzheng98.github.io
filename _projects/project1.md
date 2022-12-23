---
layout: single
title: "Verification and recurrence of ***** vulnerability in the wireless communication system of China Urban Rail Transit"
collection: projects
permalink: /projects/project1
excerpt: "*This vulnerability has been submitted to [China National Vulnerability Database of Information Security](https://www.cnnvd.org.cn/home/childHome), numbered: CNNVD-202204-3571*"
date: 2022-04-15
---

# Introduction
<hr>

**1.** First let me explain why there are "\*" in the title. Since this vulnerability currently exists in many subway lines of China, once it is disclosed before CNNVD officially publishes the announcement (after the vulnerability is announced, the subway communication systems will be upgraded and fixed), it has the potential to be used by criminals to further cause severe social harm. Therefore, **part of this project is confidential**, and I don't even know the specific name of this vulnerability

**2.** Then you may ask that **am I secret-related personnel?** No, I am not. In effect, the project is divided into 2 parts and are studied by 2 group of people separately. The goal of the first part(theoretic) is to figure out the specific rationale behind this vulnerability and how it can be exploited by attacks, obviously people working on this part are secret-related. They have already finished their work and drew us a conclusion that it can be exploited by the **man-in-the-middle(MITM)** attack

**3.** According to the theoretic instruction, another group of people (me and 2 younger students) are summoned to achieve the recurrence and verification of the MITM attack in the subway wireless communication system, which becomes the second part(practical) of the project. **To be more specific**, we have to build an LTE (the version used in subway) experimental platform to actually conduct the MITM to prove that this attack indeed can be implemented in the system
 - *Notice that we only implement basic MITM attack without further exploiting this vulnerability (Otherwise we would become secret-related as well* 🤐 *)*

<br>

# Notice
<hr>

Since this project is about to be finished, **quite a lot** of the trial and error processes I recorded earlier in this article have been deleted, leaving only the last feasible solution
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
