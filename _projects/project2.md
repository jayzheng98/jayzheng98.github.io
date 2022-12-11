---
layout: single
title: "Cybersecurity threat analysis and prediction of High-speed Railway Signal System based on knowledge graph"
collection: projects
permalink: /projects/project2
excerpt: "*Applied Basic Research Project of Science & Technology Department of Sichuan Province [grant 21YYJC3147]*"
date: 2021-04-05
toc: true
toc_label: "Contents"
---

<a name="top"></a>

# Introduction
<hr>

**1.** Most parts of this project is also my graduation design. At present, I am still studying how to correlate abnormal data (attacks) mixed in system log data through knowledge graph

**2.** In recent years, the signal system of High-speed Railway is facing unprecedented security threats, and we lack effective prediction or warning mechanisms for the Advanced Persistent Threats(APT). Therefore, this project proposes study on cybersecurity threat analysis and prediction technology of high-speed railway signal system
 - *It can be divided into 3 parts, and their relationships are shown below:*

<div align="center"> <img alt="p2-0" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-0.png?raw=true" width="260px"> </div>
<br>

# Threat Analysis 
<hr>

## Introducton
**1.** I have to emphasize that this project does not simply transplant some novel AI methods into an unexploited field of research, but tries to transform plausible advanced technique to addrress issues already exist in the rail transit

**2.** How to testify that there are indeed security issues in the system? You may say we can conduct penetration tests in a simulation environment, but how can you figure out the route and the goal of attacks within such a complex system? The answer is to firstly conduct a **theoretical threat analysis**

## Design
**1.** I've proposed a novel methodology for the coalescence analysis of safety and security in cyber-physical systems, namely the Process-Oriented and Coalescent Analysis (POCA). Different from the traditional **object-oriented** methods that directly start the analysis with system components or communication links, our method mainly focuses on the specific working process of the object, which is **process-oriented** analysis
 - *The overall framework of this methodology is shown below:*

<div align="center"> <img alt="p2-1" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/pub1-1.png?raw=true" width="580px"> </div><br>

**2.** The POCA consists of two major parts. They are oriented toward functional safety and cyber security respectively, and POCA achieves a coalescence of these two attributes by drawing the two parts together
 - *The first part, as system service process analysis, abstracts service processes into analyzable objects by referring to the STPA method, which lays a foundation of "process-oriented"*
 - *Another part, as system cyber threat analysis, identifies potential cyber threats based on outputs of the first part according to common security analysis methods*

**3.** Actually I've written an academic paper about the work of this part for publication. For more information, please refer to [here](/publication/paper-number-1)

## Experiment
**1.** The results of this theoretical analysis are set to be highly structured. As mentioned earlier, the core of this project is to use the knowledge graph for anomaly detection, so its output will be part of the input to the final graph as well

**2.** Because this paper has not been published for the time being and the project is currently working on the construction of the final graph, here I could only provide a prototype of the graphical analysis output

<div align="center"> <img alt="p2-2" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-4.png?raw=true" width="680px"> </div>
<br>

# Simulation Attack 
<hr>

## Environment and Tools

|Category|Specification|Number|
|:---:|:---:|:---:|
|IDE|PyCharm2019||
|Database|Elasticsearch7.8.0||
|Data Sensor|Sysmon<br>SysmonForLinux<br>Nxlog-EE|x6<br>x2<br>x8|
|PC|Lenovo ThinkCentre|x1|
|Server|Lenovo ThinkServer RD640|x5|
|OS|Windows10<br>Ubuntu18.04<br>Kali Linux2020<br>WinServer2008|x7<br>x2<br>x1<br>x1|
|Network Device|Cisco Catalyst 3560G<br>UTT HiPER 840G<br>Cable|x1<br>x1<br>xN|
|Security Tool|Metasploit<br>MITRE Caldera|x1<br>x1|

<br>

# Anomaly Detection
<hr>

## Environment and Tools

|Category|Specification|Number|
|:---:|:---:|:---:|
|IDE|PyCharm2019||
|Database|Arangodb3.9.2||
|PC|ThinkPad S5|x1|
|OS|Windows10|x1|

<br>

**Updating...** <br>

<div align="right"><a class="top-link hide" href="#top"><font size="6"><b>↑</b></font></a></div><br>
