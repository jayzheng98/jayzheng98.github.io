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

**2.** Most contents (exclude prediction) of this project is also my **graduation project**. At present, I am still studying how to correlate abnormal data (attacks) mixed in system logs through the knowledge graph
 - *It can be divided into 3 parts, and their relationships are shown below:*

<div align="center"> <img alt="p2-0" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-0.png?raw=true" width="300px"> </div>
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

**2.** Because this paper has not been published for the time being, here I could only provide a prototype of the graphical analysis output (some contents have been changed later)

<div align="center"> <img alt="p2-2" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-4.png?raw=true" width="680px"> </div>
<br>

# Simulation Attack 
<hr>

## Introduction
The main purpose of this part is to create our **own dataset**. Due to the closed nature of the railway system network, only internal attacks are likely to be implemented, while external attacks such as Web attacks cannot be implemented. Therefore, common datasets that include both inner and outer attacks cannot be directly used for the subsequent analysis, and the datasets include attacks against railway signal system are very rare and difficult to obtain

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
|Security Platform|Metasploit<br>MITRE Caldera|x1<br>x1|

## Design
### Simulation range
**1.** I built a simulation shooting range in my laboratory according to the network structure of the railway signal system, I've recorded my networking process [here](/notes/DC). The topology diagram and physical diagram are as follows:
 - *Due to limited conditions, I can only simulate its network structure at present, which means there is no highly simulated service scenario operated within the range*

<div align="center"> <img alt="p2-3" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-1.png?raw=true" width="750px"> </div> <br>
<div align="center"> <img alt="p2-4" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-2.jpg?raw=true" width="700px"> </div> <br>
<div align="center"> <img alt="p2-5" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-3.jpg?raw=true" width="700px"> </div> <br>

**2.** Each device(virtual machine) is equipped with "sensor" to generate environment data. In this project I choose [Sysmon](https://learn.microsoft.com/en-us/sysinternals/downloads/sysmon) as the data(log) sensor and use [Nxlog](https://nxlog.co/products/nxlog-enterprise-edition) to transmit data to [ELK](https://www.elastic.co/what-is/elasticsearch) search engine(3rd pic above)
 - Actually the deployment of the 3 tools mentioned above deserves an individual blog to illustrate. However, for now I don't have enough time to do so, I will roughly summarize the configuration of them here:
   - Sysmom(windows): please refer to this [repository](https://github.com/olafhartong/sysmon-modular/blob/master/sysmonconfig.xml)
   - Sysmon(linux): please refer to this [repository](https://github.com/microsoft/MSTIC-Sysmon/blob/main/linux/configs/main.xml)
   - Nxlog: The configuration files I wrote for windows and linux have been submitted to my [repository](https://github.com/jayzheng98/jayzheng98.github.io/tree/master/files)
   - ELK: Generally only the "logstash" needs to be customized, the configuration I wrote has also been submitted to my [repository](https://github.com/jayzheng98/jayzheng98.github.io/blob/master/files/logstash.conf)

### Dataset
**1.** We've designed a complete cyberattack path against the signal system based on one of the threat analysis results(threat scenarios)
 - *This attack set covers all 12 tactics and includes 22 techniques of [MITRE ATT&CK](https://attack.mitre.org/)*
 - *The "PS(powershell) script" mentioned in the pic has been submitted to my [repository](https://github.com/jayzheng98/jayzheng98.github.io/blob/master/files/file_monitor.ps1)*

<div align="center"> <img alt="p2-5" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-5.jpg?raw=true" width="600px"> </div> <br>
<div align="center"> <img alt="p2-6" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-6.jpg?raw=true" width="600px"> </div> <br>

## Development
**1.** Before inputting the raw dataset into the final knowledge graph, we have to do some **preprocessing**

**2.** The configuration files of Sysmon mentioned [earlier](#simulation-range) have actually helped us take the first step, that is, they can map the **Sysmonlogs** to the **techniques** of [MITRE ATT&CK](https://attack.mitre.org/) by adding the "RuleName" field
 - *With such "label", it will be easier for us to correlate logs with knowledge bases in the final graph*

<div align="center"> <img alt="p2-7" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-7.png?raw=true" width="650px"> </div> <br>

**3.** However, the mapping of config files is kind of rudimentary since about **93%** of logs will be labeled. In other words, its strong generalization results in low identification of real attack techniques
 - *For example, operations achieved by Powershell will all be labeled as "[T1059.001 Powershell](https://attack.mitre.org/techniques/T1059/001/)", while they can actually be divided more specifically*

**4.** Therefore, we've written a set of more precise **[detection rules](https://github.com/jayzheng98/Mapping-Sysmonlogs-to-ATTACK)** by referring to several opensource attack libraries and abstracting keywords from attack statements executed in the commandline
 - *This rule set conforms to the query statement [DSL](https://www.elastic.co/guide/en/elasticsearch/reference/current/query-dsl.html) of ELK engine, so we can utilize ELK to execute detections within tremendous data quickly*
 - *This rule set integrates 770 attack abilities, covering 11 tactics and about 240 techniques (60%) of ATT&CK.  It is still at an **elementary stage** and needs further development*

## Experiment
**1.** We separately implemented the pre and post penetration by Kali in the shooting range. All the behavior data (about 200k logs) before and after the implementation (total 3 days) have been saved as the **raw dataset**

**2.** By running the `test_in_my_case.py` in **[detection rules](https://github.com/jayzheng98/Mapping-Sysmonlogs-to-ATTACK)**, it may overwrite the original "RuleName" field of some logs with more precise technique ids and add a new field "RiskLevel" to all logs. Then it will export the processed dataset in `.csv` format (To facilitate the subsequent import into the graph database) 
 - *RiskLevel-0: Log that doesn't have a "RuleName"*
 - *RiskLevel-1: Log that has a RuleName which has not been overwritten*
 - *RiskLevel-2: Log that has a RuleName which has been overwritten*

<br>

# Anomaly Detection
<hr>

## Introduction
**1.** Each attack event can be expressed as a specific **behavior** on a specific **entity** (system, file, process...) at a specific **time**. These events do not exist independently but have causal relationships and chronological orders. However, current security tools are almost **point-to-point**. Although they can accurately detect vulnerabilities, viruses and abnormal behaviors, they can neither trace the attack route nor predict the subsequent plausible anomalies

**2.** We believe the Knowledge Graph (KG) will be an advanced **complement** to the traditional security tools since it can mine, analyze and construct the relationships among various entities to correlate attack events and restore the attack tree as complete as possible

**3.** We intend to merge all the outputs of previous work with a well-developed [cybersecurity KG](#knowledge-databron) to further construct the **KG of railway signal system**, and write a set of preliminary rules to drive the graph to automatically dig out attack chains hide in normal data

## Environment and Tools

|Category|Specification|Number|
|:---:|:---:|:---:|
|IDE|PyCharm2019||
|Database|Arangodb3.9.2||
|PC|ThinkPad S5|x1|
|OS|Windows10|x1|

## Design
**1.** A review article "[Recent Progress of Using Knowledge Graph for Cybersecurity](https://www.mdpi.com/2079-9292/11/15/2287)" provides us with a general experiment architecture of KG:

<div align="center"> <img alt="p2-8" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-8.png?raw=true" width="520px"> </div><br>

**2.** On the basis of this template, we have incorporated our own contents. The **conceptual structure** of the final KG of this project is as follows:
 - *Red arrows represent the element that binds two parts together*

<div align="center"> <img alt="p2-9" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-9.png?raw=true" width="780px"> </div> 
<br>

**3.** In the "development" section, we are going to separately transform the raw materials of the 4 parts into **graph structure** and eventually merge them together

## Development
### Knowledge data(BRON)
**1.** Knowledge data from [ATT&CK](https://attack.mitre.org/), [CAPEC](https://capec.mitre.org/), [CWE](https://cwe.mitre.org/) , [CVE](https://nvd.nist.gov), [MITRE Engage](https://engage.mitre.org/) and [D3FEND](https://d3fend.mitre.org/) are already linked together in a graph called "[BRON](https://github.com/ALFA-group/BRON)"
 - *For more details about BRON please refer to their [academic paper](https://arxiv.org/pdf/2010.00533.pdf)*

**2.** The database that drives BRON is "[ArangoDB](https://www.arangodb.com/)", our final graph will mainly depend on it as well

### CTI(POCA) & Environment data(Topology)
**1.** The "[POCA](#threat-analysis)" and "[Topology](#simulation-range)" in the pic above are already described in previous sections. Part of their graph construction processes are recorded [here](/notes/arangodb), and I won’t describe such work in detail later in this article
 - *All the source materials(.csv) as well as their relations of this 2 parts have been committed to this [repository](https://github.com/jayzheng98/Analysis-result-of-POCA)*

### Behavior data(Sysmonlogs)
**1.** To begin with, we should have an in-depth understanding of the Sysmon logs. This [webpage](https://rootdse.org/posts/understanding-sysmon-events/) provides us with detailed information of each "Event" as well as the fields in it

**2.** Suppose that you are already familiar with Sysmonlogs and have obtained the `syslog.csv` by running the aforementioned `test_in_my_case.py`, 

**Updating...** <br>

<div align="right"><a class="top-link hide" href="#top"><font size="6"><b>↑</b></font></a></div><br>
