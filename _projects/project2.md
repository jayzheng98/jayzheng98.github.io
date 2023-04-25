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
<style>body{text-align: justify}</style>
<a name="top"></a>

# Introduction
<hr>

**1.** In recent years, the signal system of High-speed Railway is facing unprecedented security threats, and it lacks effective prediction or warning mechanisms for the Advanced Persistent Threats(APT). Therefore, this project proposes study on cybersecurity threat analysis and prediction technology of railway signal system

**2.** Most contents (exclude "prediction") of this project is also my **graduation project**. It consists of 4 parts, and their relationships are shown below:

<div align="center"> <img alt="p2-0" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-0.svg?raw=true" width="340px"> </div>
<br>

# Threat Analysis 
<hr>

## Introducton
**1.** How to testify there are security issues in the rail transit? Maybe we can conduct penetration tests in a simulation environment. But how to figure out the route and goal of cyberattacks within such a complex system? The answer is to firstly conduct a **theoretical threat analysis**

## Design
**1.** I've proposed a novel methodology for the coalescence analysis of safety and security in cyber-physical systems, namely the <u>Process-Oriented and Coalescent Analysis (POCA)</u>. Different from the traditional **object-oriented** methods that directly start the analysis with system components or communication links, our method mainly focuses on the specific working process of the object, which is **process-oriented** analysis
 - *The overall framework of this methodology is shown below:*

<div align="center"> <img alt="p2-1" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/pub1-1.png?raw=true" width="620px"> </div><br>

**2.** The POCA consists of two major parts. They are oriented toward functional safety and cyber security respectively, and POCA achieves a coalescence of these two attributes by drawing the two parts together
 - *The first part, as system service process analysis, abstracts service processes into analyzable objects by referring to the STPA method, which lays a foundation of "process-oriented"*
 - *Another part, as system cyber threat analysis, identifies potential cyber threats based on outputs of the first part according to common security analysis methods*

**3.** Actually I've written an [academic paper](/publication/paper-number-1) about the work of this part for publication.

## Experiment
**1.** I've applied POCA to the <u>Temporary Speed Restriction (TSR)</u> scenario of the railway signal system. The analysis results are set to be highly structured. As mentioned earlier, the core of this project is to use the knowledge graph for anomaly detection, so the output of POCA will be part of the final knowledge graph as well
 - *Because this paper has not been published for the time being, here I could only provide a prototype of the graph-structured analysis output (some contents have been changed later)*

<div align="center"> <img alt="p2-2" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-4.png?raw=true" width="740px"> </div>
<br>

# Threat Simulation
<hr>

## Introduction
**1.** This part not only verifies the usability of POCA analysis results, but also provides a **dataset** for subsequent research. Due to the closed nature of the railway system, only internal attacks are likely to be implemented. Therefore, common datasets that include external attacks such as Web penetration are not suitable for our demand. Meanwhile, the datasets include attacks against railway signal system are difficult to obtain. Thus, we have to generate our own dataset

## Design
### Simulation range
**1.** I built a simulation range in my laboratory according to the network structure of the railway signal system ([networking processes](/notes/DC)). The topology diagram and physical diagram are as follows:

<div align="center"><img alt="p2-3" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-1.png?raw=true" width="750px"></div><br>

**2.** This range is composed of the network equipment and other 3 parts:
- **Network Equipment**
  - *The range uses switches to carry communication between the ground equipment of the train control system, and uses routers to connect ground equipment and Centralized Traffic Control (CTC) equipment. Specifically, the switch consists of a three-layer switch and 2 VLANs configured within it*

- **Data Generation Area(Environment data)**
  - *This area is composed of several virtual machines running on 5 servers separately. The virtual machines simulate the ground equipment of the train control system. Since the network cards of virtual machines are configured in "bridge mode", those servers actually act as "switches". In addition, the LAN of CTC is configured as a "domain"*

- **Attacker**
  - *The attacker operates a Kali Linux host which has already connected to the ISDN server within the LAN of switch 3*

- **Data Collection and Analysis Terminal**
  - *This terminal is a host that installs the [Elasticsearch](https://www.elastic.co/what-is/elasticsearch) data engine, which is responsible for collecting and processing data from the data generation area*

**3.** Detailed configuration of this range is shown in the table below:
 - *Each virtual machine is installed with software to simulate services of the train control system*
 - *[Sysmon](https://learn.microsoft.com/en-us/sysinternals/downloads/sysmon) and [NXlog](https://nxlog.co/products/nxlog-enterprise-edition) are also installed to realize syslog generation and forwarding separately*

| Device | Operating System | IP | Security Tool | Main Software |
| :----: | :-----------------: | :----------: | :-------------: | :-------------: |
| RBC active | Windows 10 | 192.168.4.203 | 360 Security<br>Windows Defender | RBC Simulation Software<br>Sysmon+NXlog |
| RBC standby | Windows 10 | 192.168.3.105 | Same with active | Same with active |
| ISDN Server active | Ubuntu 18.04 | 192.168.4.206 | ClamAV | ISDN Simulation Software<br>SysmonForLinux+NXlog |
| ISDN Server standby | Ubuntu 18.04 | 192.168.3.106 | Same with active | Same with active |
| TSRS active | Windows 10 | 192.168.4.200 | 360 Security<br>Windows Defender | TSRS Simulation Software<br>Sysmon+NXlog<br>EasyFileSharing |
| TSRS standby | Windows 10 | 192.168.3.103 | Same with active | Same with active |
| TSR Interface Server | Windows Server 2008 | 172.110.2.11 | 360 Security<br>Windows Defender | Sysmon+NXlog |
| CTC active | Windows 10 | 172.110.2.12 | 360 Security<br>Windows Defender | CTC Simulation Software<br>Sysmon+NXlog |
| CTC standby | Windows 10 | 172.110.2.13 | Same with active | CTC Simulation Software<br>Sysmon+NXlog<br>EasyFileSharing |
| Kali Linux | Kali Linux 2020 | 192.168.4.211 | | Metasploit<br>MITRE Caldera |
| ELK mainframe | Windows 10 | 10.10.10.230 | 360 Security<br>Windows Defender | Elasticsearch |

### Simulation attack
**1.** I designed a complete attack strategy against the signal system based on POCA analysis result "threat scenario 2". It covers all 12 tactics and includes 18 techniques of [MITRE ATT&CK](https://attack.mitre.org/)

<div align="center"> <img alt="p2-5" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-5.jpg?raw=true" width="660px"> </div> <br>

**2.** I separately implemented the pre and post penetration by Kali in the range, and all logs (total 3 days) are saved as the **raw dataset**
 
## Development
### Log labelling
**1.** The highly-textual information contained in logs will greatly increase the workload and difficulty of analysis, so it's necessary to **preprocess** the dataset: try to add a "label" to each log

**2.** A [configuration file](https://github.com/olafhartong/sysmon-modular) of Sysmon have actually helped us take the first step, it can map logs to the **ATT&CK techniques** in the `RuleName` field, which plays the role as "label"

<div align="center"> <img alt="p2-7" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-7.png?raw=true" width="720px"> </div><br>

**3.** However, the above work is kind of rudimentary, since about **93%** logs will be labeled. In other words, its strong generalization results in low identification of real attack behaviors
 - *For example, all operations achieved by Powershell will be labeled as "[T1059.001 Powershell](https://attack.mitre.org/techniques/T1059/001/)", while they can actually be divided more specifically*

**4.** Therefore, we've written another set of **detection rules** ([repository](https://github.com/jayzheng98/Mapping-Sysmonlogs-to-ATTACK)) specialized for the commandline (powershell/cmd/terminal) inputs. It integrates 770 attack abilities of [MITRE Caldera platform](https://caldera.mitre.org/), covering 11 tactics and about 240 techniques (60%) of ATT&CK
 - *This rule set conforms to the query statement [DSL](https://www.elastic.co/guide/en/elasticsearch/reference/current/query-dsl.html) of ELK engine, so we can utilize ELK to drive detections within tremendous data quickly*
 - *By running the* `test_in_my_case.py` *in the repository, it will overwrite the* `RuleName` *of some logs with more precise "technique_ids", and then export the processed dataset from ELK as* `syslog.csv` *at once*

<br>

# Graph construction
<hr>

## Introduction
<!--**1.** Each attack event can be expressed as a specific **behavior** on a specific **entity** (system, file, process...) at a specific **time**. These events do not exist independently but have causal relationships and chronological orders. However, current security tools are almost **point-to-point**. Although they can accurately detect vulnerabilities, viruses and abnormal behaviors, they can neither trace the attack route nor predict the subsequent plausible anomalies-->

**1.** The expanding scale of cyberspace leads to a sharp increase in the amount of security-related data, which are diverse, fragmented, and heterogeneous. The main challenge in current security analysis is not the shortage of data, but how to combine information from various sources into a single model

**2.** Knowledge graph is a large-scale semantic model composed of vertices and edges. It can intuitively model various cybersecurity scenarios. This section intends to merge all the outputs of aforementioned work and some existing achievements to construct a **KG of railway signal system**, which will further be the foundation of the anomaly detection experiment

## Design
### Overview
**1.** The review article "[Recent Progress of Using Knowledge Graph for Cybersecurity](https://www.mdpi.com/2079-9292/11/15/2287)" provides us with a general architecture with 4 dimensions of KG:
 - *On the basis of this template, we are going to transform the raw data of each dimension into **graph structure**, and eventually merge them together to construct the knowledge graph*

<div align="center"> <img alt="p2-8" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-8.png?raw=true" width="540px"> </div><br>

### Knowledge data
**1.** Knowledge data from [ATT&CK](https://attack.mitre.org/), [CAPEC](https://capec.mitre.org/), [CWE](https://cwe.mitre.org/) , [CVE](https://nvd.nist.gov), [MITRE Engage](https://engage.mitre.org/) and [D3FEND](https://d3fend.mitre.org/) are already linked together by researchers from MIT as an [open source](https://github.com/ALFA-group/BRON) graph "[BRON](https://arxiv.org/pdf/2010.00533.pdf)". The graph structure of BRON's main part is shown below:

<div align="center"> <img alt="p2-9" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-9.png?raw=true" width="440px"> </div> 
<br>

### Environment data
**1.** This dimension is generally based on the topology of the target system and includes attributes such as OS and IP of the equipment. It not only models the physical composition of the environment, but also acts as a bridge between <u>behavior data</u> and <u>cyber threat intelligence (CTI)</u>
 - *The environment data of this project has been provided in [Section 2](#simulation-range). It is represented as the "asset" entity in the following work*

### CTI
**1.** There are 2 kinds of CTI sources in my KG: <u>General security CTI</u> and <u>Specific railway CTI</u>

**2. General security CTI** is completed with the help of existing achievement. MITRE developed an [open source](https://github.com/center-for-threat-informed-defense/tram/) platform [TRAM](https://medium.com/mitre-engenuity/tram-advancing-research-into-automated-ttp-identification-in-threat-reports-2d868fecc791). As shown below, TRAM can associate the input attack procedure (left) with the ATT&CK techniques and tactics (right) to help generate CTI in the form of "TTPs"

<div align="center"> <img alt="p2-10" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-10.png?raw=true" width="660px"> </div><br>

**3.** Through the TRAM platform and manual verification, we've generated the **general security CTI** of some common attacks, which could be easily transformed into graph structure
 - *The table below shows an example of the reformatted "file stealing" attack*

<table>
<style>td{text-align:center;}</style>
	<tr>
            <th></th>
	    <th>Tactic</th>
	    <th>Technique</th>
	    <th>Procedure</th>
	</tr>
	<tr>
     <td>1</td>
	    <td rowspan="4">Collection</td>
	    <td>T1074.001: Local Data Staging</td>
	    <td>Create a folder on the target device for file collection</td>
	</tr>
	<tr>
     <td>2</td>
	    <td>T1005: Data from Local System</td>
	    <td>Search target files by keywords (filename, suffixes)</td>
	</tr>
	<tr>
     <td>3</td>
	    <td>T1074.001: Local Data Staging</td>
	    <td>Copy the searched files to the pre-built folder</td>
	</tr>
	<tr>
     <td>4</td>
	    <td>T1560.001: Archive via Utility</td>
	    <td>Pack and compress the collected target files</td>
	</tr>
	<tr>
     <td>5</td>
	    <td>Exfiltration</td>
	    <td>T1041: Exfiltration Over C2 Channel</td>
	    <td>Establish a command and control (C2) channel using the HTTP protocol to return packaged files</td>
	</tr>
</table><br>
<!--
||	Tactic|	Technique	| Procedure |
| :----: | :----------: | :-------------: | :-------------: |
|1	|Collection	|T1074.001: Local Data Staging	|Create a folder on the target device for file collection|
|2	| 	         |T1005: Data from Local System	|Search target files by keywords (filename, suffixes)|
|3	|           |T1074.001: Local Data Staging	|Copy the searched files to the pre-built folder|
|4	|           |T1560.001: Archive via Utility|Pack and compress the collected target files|
|5	|Exfiltration|T1041: Exfiltration Over C2 Channel|	Establish a command and control (C2) channel using the HTTP protocol to return packaged files|
-->

**4. Specific railway CTI** refers to the threat modeling outputs of the system. In this project, it is generated by [POCA](#threat-analysis). The graph structure of POCA analysis results is shown below:
 - *Results such as "control action", "weakness" and "threat scenario" can be presented as entities*
 - *Results like "risk score" and "description" can be used as attributes of entities*
 - *Entities are associated through external and internal relationships. For example, nodes in the "threat scenario" entity can form a threat tree through the internal relationship "TS-TS"*

<div align="center"> <img alt="arango8" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/arango8.png?raw=true" width="300px"> </div><br>

### Behavior data
**1.** Details of this part are summarized in this [repository](https://github.com/jayzheng98/Syslog-Graph). In short, logs whose `EventID` = `1 (ProcessCreate)` or `10 (ProcessAccess)` contain info that separately represent 2 kinds of process relations: "parentp-childp" and "process-process". We can utilize them as well as the inherent "time" as the 3 major relations to form a **syslog graph**:

<div align="center"> <img alt="p2-11" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-11.png?raw=true" width="240px"> </div><br>

### Final graph
**1.** The abstract structure of the final KG based on the aforementioned dimensions and relationships is shown below:
<div align="center"> <img alt="p2-12" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-12.png?raw=true" width="740px"> </div><br>

## Development
<!--**2.** The graph database that drives BRON is "[ArangoDB](https://www.arangodb.com/)", Part of their graph construction are recorded [here](/notes/arangodb)-->

<br>

# Anomaly Detection
<hr>



<br>

<div align="right"><a class="top-link hide" href="#top"><font size="6"><b>↑</b></font></a></div><br>
