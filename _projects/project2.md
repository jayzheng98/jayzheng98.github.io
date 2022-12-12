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

**1.** In recent years, the signal system of High-speed Railway is facing unprecedented security threats, and we lack effective prediction or warning mechanisms for the Advanced Persistent Threats(APT). Therefore, this project proposes study on cybersecurity threat analysis and prediction technology of cyber-physical systems

**2.** Most contents of this project is also my **graduation project**. At present, I am still studying how to correlate abnormal data (attacks) mixed in system logs through the knowledge graph
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

<div align="center"> <img alt="p2-1" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/pub1-1.png?raw=true" width="620px"> </div><br>

**2.** The POCA consists of two major parts. They are oriented toward functional safety and cyber security respectively, and POCA achieves a coalescence of these two attributes by drawing the two parts together
 - *The first part, as system service process analysis, abstracts service processes into analyzable objects by referring to the STPA method, which lays a foundation of "process-oriented"*
 - *Another part, as system cyber threat analysis, identifies potential cyber threats based on outputs of the first part according to common security analysis methods*

**3.** Actually I've written an [academic paper](/publication/paper-number-1) about the work of this part for publication.

## Experiment
**1.** The results of this theoretical analysis are set to be highly structured. As mentioned earlier, the core of this project is to use the knowledge graph for anomaly detection, so its output will be part of the input to the final graph as well

**2.** Because this paper has not been published for the time being and the project is currently working on the construction of the final graph, here I could only provide a prototype of the graphical analysis output

<div align="center"> <img alt="p2-2" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-4.png?raw=true" width="680px"> </div>
<br>

# Simulation Attack 
<hr>

## Introduction
**1.** The main purpose of this part is to create our **own dataset**. Due to the closed nature of the railway system network, only internal attacks are likely to be implemented, while external attacks such as Web attacks cannot be implemented. Therefore, common datasets that include both inner and outer attacks cannot be directly used for the subsequent analysis, and the datasets include attacks against railway signal system are very rare and difficult to obtain

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

## Design
### Simulation range
**1.** I built a simulation shooting range in my laboratory according to the network structure of the railway signal system, I've recorded my networking process [here](/notes/DC). The topology diagram and physical diagram are as follows:

<div align="center"> <img alt="p2-3" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-1.png?raw=true" width="750px"> </div> <br>
<div align="center"> <img alt="p2-4" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-2.jpg?raw=true" width="700px"> </div> <br>
<div align="center"> <img alt="p2-5" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-3.jpg?raw=true" width="700px"> </div> <br>

**2.** Each device(virtual machine) is equipped with "sensor" to generate environment data. In this project I choose [Sysmon](https://learn.microsoft.com/en-us/sysinternals/downloads/sysmon) as the data(log) sensor and use [Nxlog](https://nxlog.co/products/nxlog-enterprise-edition) to transmit data to [ELK](https://www.elastic.co/what-is/elasticsearch) mainframe(3rd pic above)
 - Actually the deployment of the 3 tools mentioned above deserves 3 individual blogs to illustrate. However, for now I don't have enough time to do so, I will roughly summarize the configuration of them here:
   - Sysmom(windows): please refer to this [repository](https://github.com/olafhartong/sysmon-modular/blob/master/sysmonconfig.xml)
   - Sysmon(linux): please refer to this [repository](https://github.com/microsoft/MSTIC-Sysmon/blob/main/linux/configs/main.xml)
   - Nxlog: The configuration files I wrote for windows and linux have been submitted to my [repository](https://github.com/jayzheng98/jayzheng98.github.io/tree/master/files)
   - ELK: Generally only the "logstash" needs to be customized, the configuration I wrote has also been submitted to my [repository](https://github.com/jayzheng98/jayzheng98.github.io/blob/master/files/logstash.conf)

### Dataset
**1.** We learned the well-known open source APT reports, kill chain model and other materials, then designed a complete set of signal system cyberattack strategies based on the threat analysis results(threat scenarios)
 - *The attack set covers all 12 tactics and includes 22 techniques of [MITRE ATT&CK](https://attack.mitre.org/):*
 - *The "PS(powershell) script" mentioned in the pic has been submitted to my [repository](https://github.com/jayzheng98/jayzheng98.github.io/blob/master/files/file_monitor.ps1)*

<div align="center"> <img alt="p2-5" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-5.jpg?raw=true" width="640px"> </div> <br>
<div align="center"> <img alt="p2-6" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-6.jpg?raw=true" width="640px"> </div>

**2.** Suppose the adversary has already invaded in the signal system as the "Kali Linux" shown in the topology. Then we separately implemented the pre and post penetration processes with Kali in 2 days in the shooting range. All the environment data before and after the implementation (**total 3 days**) have been exported and saved as the **raw dataset**
 - *We've collected about 400k sysmon logs in total, and roughly estimate that there are about 15k abnormal data generated by the designed attacks*

<br>

## Experiment

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
