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

**1.** First let me explain that why there are "\*" symbols in the title. Since the vulnerability proposed by a researcher in our lab currently exists in many subway lines in China, once it is disclosed before CNNVD officially publishes the announcement (after the vulnerability is announced, the subway communication systems in most cities will be upgraded and fixed), it has the potential to be used by criminals to cause severe social harm. Therefore, **part of this project is confidential**, and I don't even know the specific name of this vulnerability

**2.** Then you may ask that **am I secret-related personnel?** No, I am not. In effect, the project is divided into 2 parts and are implemented by 2 group of people separately. The goal of the first part(theoretic) is to figure out the specific rationale behind this vulnerability and how it can be exploited by attacks, obviously people who are responsible for this part are secret-related. They have already finished their work and have drawn us a conclusion that it can be exploited by the <u>man-in-the-middle(MITM)</u> attack

**3.** According to the theoretic instruction, another group of people (me and two younger students) are summoned to complete the recurrence and verification of the MITM attack in the wireless communication system of subway, which becomes the second part(practical) of the project. **To be more specific**, we have to build an LTE (the version used in subway) experimental platform to actually conduct the MITM to prove that this attack indeed can be implemented in the system

<br>

# Environment and Tools
<hr>

This is a description of your talk, which is a markdown files that can be all markdown-ified like any other post. Yay markdown!
