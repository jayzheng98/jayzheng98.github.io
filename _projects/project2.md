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
<style>body{text-align:justify}</style>
<a name="top"></a>

# Introduction
<hr>

**1.** In recent years, the signal system of High-speed Railway is facing unprecedented security threats, and it lacks effective prediction or warning mechanisms for the Advanced Persistent Threats(APT). Therefore, this project proposes study on cybersecurity threat analysis and prediction technology of railway signal system

**2.** This project mainly supported my **graduation thesis**, titled "Cyber Threat Behavior Analysis and Knowledge Graph Based Anomaly Detection in Train Control System". The specific structure of my work is:

<div align="center"> <img alt="p2-0" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-0.png?raw=true" width="300px"> </div>
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

**3.** Actually I've written an [academic paper](/publication/paper-number-1) about the work of this part for publication

## Experiment
**1.** I've applied POCA to the <u>Temporary Speed Restriction (TSR)</u> scenario of the train control system. The analysis results are set to be highly structured. As mentioned earlier, the core of this project is to use the knowledge graph for anomaly detection, so the output of POCA will be part of the final knowledge graph as well
 - *Because this paper has not been published for the time being, here I could only provide a prototype of the graph-structured analysis output (some contents have been changed later)*

<div align="center"> <img alt="p2-2" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-4.png?raw=true" width="740px"> </div>
<br>

# Threat Simulation
<hr>

## Introduction
**1.** This part not only verifies the usability of POCA analysis results, but also provides a dataset for subsequent research. Due to the closed nature of the railway system, only internal attacks are likely to be implemented. Therefore, common datasets that include external attacks such as Web penetration are not suitable for our demand. Meanwhile, the datasets include attacks against railway systems are difficult to obtain. Thus, we have to **generate our own dataset**

## Design
### Simulation range
**1.** I built a simulation range in my laboratory according to the Signal Safety Data Network(SSDN) of train control system ([networking processes](/notes/DC)). The topology diagram and physical diagram are as follows:

<div align="center"><img alt="p2-3" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-1.png?raw=true" width="750px"></div>

**2.** This range is composed of the network equipment and other 3 parts:
- **Network Equipment**
  - *The range uses switches to carry communication between the ground equipment, and uses router to connect ground equipment and Centralized Traffic Control (CTC). Specifically, the switch consists of a three-layer switch and 2 VLANs configured within it*

- **Data Generation Area(Environment data)**
  - *This area is composed of 5 servers, each running several virtual machines that simulate the ground equipment of the train control system. Since the network cards of the virtual machines are configured in 'bridge mode,' these servers also act as "switches"*
  - *The LAN of **Swithc1** is configured as "domain"*

- **Attacker**
  - *The attacker operates a Kali Linux host which has already connected to the ISDN server within the LAN of switch 3*

- **Data Collection and Analysis Terminal**
  - *This terminal is a host that installs the [Elasticsearch](https://www.elastic.co/what-is/elasticsearch) engine, which is responsible for collecting and processing data from the data generation area*
  - *The knowledge graph constructed later is also deployed on it*

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
| Kali Linux | Kali Linux 2020 | 192.168.4.211 |- | Metasploit<br>MITRE Caldera |
| ELK mainframe | Windows 10 | 10.10.10.230 | 360 Security<br>Windows Defender | Elasticsearch |

### Simulation attack
**1.** I designed a complete attack strategy against the system based on POCA analysis output "threat scenario2". It covers all 12 tactics and includes 18 techniques of [MITRE ATT&CK](https://attack.mitre.org/) base

<div align="center"> <img alt="p2-5" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-5.jpg?raw=true" width="660px"> </div> <br>

**2.** I separately implemented the pre and post penetration by Kali in the range, and all logs (total 3 days) are saved as the **raw dataset**
 
## Development
### Log labelling
**1.** The highly-textual information contained in logs will greatly increase the workload and difficulty of analysis, so it's necessary to **preprocess** the dataset: try to add a "label" to each log

**2.** A [configuration file](https://github.com/olafhartong/sysmon-modular) of Sysmon have actually helped us take the first step, it can map logs to the **ATT&CK techniques** in the `RuleName` field, which plays the role as "label"

<div align="center"> <img alt="p2-7" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-7.png?raw=true" width="720px"> </div><br>

**3.** However, the above work is kind of rudimentary, since about **93%** logs will be labeled. In other words, its strong generalization results in low identification of real attack behaviors
 - *For example, all operations achieved by Powershell will be labeled as "T1059.001 Powershell", while they can actually be divided more specifically*

**4.** Therefore, we've written another set of **detection rules** ([repository](https://github.com/jayzheng98/Mapping-Sysmonlogs-to-ATTACK)) specialized for the commandline (powershell/cmd/terminal) inputs. It integrates 770 attack abilities of [MITRE Caldera platform](https://caldera.mitre.org/), covering 11 tactics and about 240 techniques (60%) of ATT&CK
 - *This rule set conforms to the query statement [DSL](https://www.elastic.co/guide/en/elasticsearch/reference/current/query-dsl.html) of ELK engine, so we can utilize ELK to drive detections within tremendous data quickly*
 - *By running the* `test_in_my_case.py` *in the repository, it will overwrite the* `RuleName` *of some logs with more precise "technique_ids", and then export the processed dataset from ELK as* `syslog.csv` *at once*

<br>

# Graph construction
<hr>

## Introduction
<!--**1.** Each attack event can be expressed as a specific **behavior** on a specific **entity** (system, file, process...) at a specific **time**. These events do not exist independently but have causal relationships and chronological orders. However, current security tools are almost **point-to-point**. Although they can accurately detect vulnerabilities, viruses and abnormal behaviors, they can neither trace the attack route nor predict the subsequent plausible anomalies-->

**1.** The expanding scale of cyberspace leads to a sharp increase in the amount of security-related data, which are diverse, fragmented, and heterogeneous. The main challenge in current security analysis is not the shortage of data, but how to combine information from various sources

**2.** Knowledge graph is a large-scale semantic model composed of vertices and edges. It can intuitively model various cybersecurity scenarios. This section intends to merge all the outputs of aforementioned work with existing achievements to construct a **KG of railway signal system**

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
**1.** There are 2 kinds of CTI sources in my KG: General security CTI and Specific railway CTI

**2. General security CTI** is completed with the help of existing achievement. MITRE developed an [open source](https://github.com/center-for-threat-informed-defense/tram/) platform "[TRAM](https://medium.com/mitre-engenuity/tram-advancing-research-into-automated-ttp-identification-in-threat-reports-2d868fecc791)". As shown below, TRAM can associate the input attack procedure (left) with the ATT&CK techniques and tactics (right) to help generate CTI in the form of "TTPs"

<div align="center"> <img alt="p2-10" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-10.png?raw=true" width="660px"> </div><br>

**3.** Through the TRAM platform and manual verification, we've generated the **general security CTI** of some common attacks, which could be easily transformed into graph structure
 - *The table below shows an example of the reformatted "file stealing" attack*

||Tactic|Technique| Procedure |
| :----: | :----------: | :-------------: | :-------------: |
|1	|Collection	|T1074.001: Local Data Staging	|Create a folder on the target device for file collection|
|2	| Collection |T1005: Data from Local System	|Search target files by keywords (filename, suffixes)|
|3	| Collection |T1074.001: Local Data Staging	|Copy the searched files to the pre-built folder|
|4	| Collection|T1560.001: Archive via Utility|Pack and compress the collected target files|
|5	|Exfiltration|T1041: Exfiltration Over C2 Channel|	Establish a command and control (C2) channel using the HTTP protocol to return packaged files|

<br>

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
**1.** As for the development, knowledge graph can be constructed through graph database. This project chooses the [ArangoDB](https://www.arangodb.com/), and its basic info and usage are recorded [here](/notes/arangodb)

**2.** Since it is impossible to clearly visualize a graph model with large amount of data, here I only take the <u>specific railway CTI</u> and <u>environment data</u> 2 dimensions as examples to display the nodes and edges in the constructed graph database:

<div align="center"> <img alt="p2-13" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-13.png?raw=true" width="720px"> </div><br>

**3.** Basic indicators of the constructed KG:

| Indicator | Definition | Value | Explanation |
| :---: | :---: | :---: | :---: |
| Nodes | Number of nodes | $500966$ |  |
| Edges | Number of edges |$1685976$| The graph is a directed graph |
| Isolated Nodes | Number of nodes with no edges | $22368$ | As some nodes in BRON are isolated, this graph is a disconnected graph |
| Network Density | Ratio of actual edges to possible edges | $6.72\times10^{-6}$ | The density is close to 0, indicating that the graph is sparse |
| Average Degree | The sum of degrees of all nodes divided by the number of nodes | $6.73$ | On average, each node has connected with 6.73 edges |
| Maximum Depth | The longest path from the root node to a leaf node | $10$ | The graph has the maximum depth when its root is the "accident" layer and its leaf is the "CVE" layer |
| Network Diameter | The longest shortest path between any two nodes | $14$ | Such path is found between an "accident" node and a "CVE" node |

<br>

# Anomaly Detection
<hr>

## Introduction
**1.** Modern cyberattacks are often carried out in a concealed and highly variable style, which lack obvious features or patterns. Thus, traditional methods are difficult to effectively identify them. Therefore, behavior-based anomaly detection has become an important idea, which identifies potential threats by modeling system behaviors and detecting abnormal ones on this basis

## Design
### Detection framework
**1.** From a macro perspective, the behavior studied in this project can be divided into 2 categories: <u>abstract abnormal behavior</u> recorded as theoretical CTI, and <u>specific system behavior</u> collected through practical experiments. Once a bridge is built to cross the gap between theoretical results and actual data, effective anomaly detection can be achieved

<div align="center"> <img alt="p2-14" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-14.png?raw=true" width="540px"> </div><br>

**2.** Based on this idea, I've designed a **behavior-based anomaly detection framework**, which defines 3 kinds of behaviors according to the threat level from low to high:
 - *<b>System device behavior</b> refers to syslogs labelled by ATT&CK technique. Due to the high proportion of labelled logs, it is hard to directly identify the small amount of abnormal data hidden in massive normal data at this level*
 - *<b>Security threat behavior</b> is detected when some <u>system device behavior</u> satisfy the attack behaviors recorded in <u>general security CTI</u>, indicating a high probability of behavior data that left by the hacker during attacks*
 - *<b>Service abnormal behavior</b> is detected when a certain amount of <u>security threat behavior</u> further conforms to threat scenarios described in <u>specific railway CTI</u>, indicating that certain system service may have experienced anomalies due to security threats*

### Detection modes
**1.** As for the application, this framework can perform 2 detection modes: 
 - ***Bottom-up** means the detection is from the low-level all the way up to the high-level, and directly achieves the anomaly detection*
 - *However, considering the complexity of attacks and the incompleteness of CTI in the KG, high-level abnormal behavior usually cannot be directly mapped through the bottom-up detection. Therefore, the more flexible **bi-directional** detection should be widely applied*

<div align="center"> <img alt="p2-15" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-15.png?raw=true" width="765px"> </div>

**2.** The program flowchart of experiment based on the detection framework is:

<div align="center"> <img alt="p2-16" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-6.png?raw=true" width="600px"> </div><br>

## Experiment
**1.** Graph traversal is the technical carrier of this detection experiment. Since our KG has a relatively large depth, the Breadth-First Search (BFS) is more applicable and efficient
 - *ArangoDB's query language [AQL](https://www.arangodb.com/docs/stable/aql/index.html) has integrated multiple basic algorithms including BFS, so we could develop detection functions based on it*

### Security threat behavior detection (low → middle)
**1.** Since the association between <u>behavior data</u>, <u>knowledge data</u>, and <u>CTI</u> has already been established in the KG, we only need to search for the syslog node combinations that match the TTPs of <u>general security CTI</u> according to their ATT&CK labels
 - *The AQL code for this detection is as follows:*
 
```sql
FOR v,e,p IN ANY 'CTI/steal1'
                CTICTI,
                CTITTP,
                OUTBOUND TechniqueTechnique_mitigation,
                INBOUND SyslogTTP,
                INBOUND ProcessSyslog,
                INBOUND ParentpChildp,
                INBOUND AssetProcess
    OPTIONS {bfs:ture}
RETURN p
```

**2.** After executing the above code, we've detected 2 kinds of attack patterns in the dataset:
 - *Lateral movement*
 
<div align="center"> <img alt="p2-17" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-17.png?raw=true" width="740px"> </div><br>
 - *File stealing*

<div align="center"> <img alt="p2-18" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-18.png?raw=true" width="760px"> </div><br>

### Service abnormal behavior detection (middle → high)
**1.** The basis for mapping from mid-level to high-level in this project is the **command files**

**2.** For the detected "lateral movement", it does not involve any service command file; For the "file stealing", the commandline input of "syslog/23647" (corresponding to the 3rd step of this attack pattern) indicates that it used the `Copy-Item` to copy (steal) the "TSR_Cancel.CONF" command file to a folder called "staged"

<div align="center"> <img alt="p2-19" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-19.png?raw=true" width="480px"> </div><br>

**3.** According to the <u>specific railway CTI</u>, the control action related to TSR cancel command is "CA0". Based on this clue, the detected attack may be further mapped to the high-level service abnormal behavior through the following AQL template:
 - *The general idea is: based on the traversal result of the middle-level detection, set filter conditions to continue traversing upwards*

```sql
FOR v,e,p IN 1..8 ANY 'CTI/steal3'
                     CTITTP,
                     INBOUND SyslogTTP,
                     INBOUND ProcessSyslog,
                     INBOUND ParentpChildp,
                     INBOUND AssetProcess,
                     INBOUND AssetCA,
                     INBOUND CAWeakness,
                     OUTBOUND TSweakness
     OPTIONS {bfs: true}
     FILTER p.vertices[*]._key ANY == "23647"
        AND p.vertices[*].command ANY == "TSR_Cancel"
        AND p.vertices[*].security_threat ANY == "Leakage"
RETURN p
```

**4.** After executing the above code, only the first step of threat scenario2 (node "TS2") was matched, suggesting that **bottom-up** detection alone is insufficient for identifying service abnormal behavior in our dataset. Therefore, **bi-directional** detection is required to further trace subsequent steps of threat scenario2

<div align="center"> <img alt="p2-20" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-20.png?raw=true" width="250px"> </div><br>

### Service abnormal behavior detection (high → low)
**1.** The workflow of bi-directional detection is:
 - *traverse within the "threat_scenario" layer (current location) to obtain remaining steps (CTI)*
 - *traverse downward to the "syslog" layer for each step to find related logs (behavior data)*
 - *output the traversal path as the detection result*

**2.** At first, node "TS2.1" was read, which involves **tampering** with the **TSR cancel** command file. However, since this file was tampered locally by the attacker, no relevant logs can be detected

**3.** Then, continue traversing to the "TS2.1.1" node, which involves **leakage** of the **TSR execution reminder** command file

```sql
FOR v,e,p IN 1..7 ANY 'threat_scenario/TS2'
                     TSTS,
                     INBOUND TSWeakness,
                     OUTBOUND CAWeakness,
                     OUTBOUND AssetCA,
                     OUTBOUND AssetProcess,
                     OUTBOUND ParentpChildp,
                     OUTBOUND ProcessSyslog
     OPTIONS {bfs: true}
     FILTER p.vertices[*]._id ANY == "asset/8"
        OR p.vertices[*]._id ANY == "asset/9"
     FILTER p.vertices[*].command ANY == "TSR_ExecutionReminder"
        AND p.vertices[*].security_threat ANY == "Leakage"
     FILTER p.vertices[*].TargetFilename
        AND p.vertices[*].TargetFilename LIKE "%TSR_ExecutionReminder%"
RETURN p
```

**4.** Through the above code, abnormal behavior of operating such command file was detected:

<div align="center"> <img alt="p2-21" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-21.png?raw=true" width="500px"> </div><br>
**5.** Continue traversing within the "threat scenario" layer to the "TS2.1.1.1" node, which involves the **counterfeit** of **TSR execution** command file

```sql
FOR v,e,p IN 1..8 ANY 'threat_scenario/TS2'
                     TSTS,
                     INBOUND TSWeakness,
                     OUTBOUND CAWeakness,
                     OUTBOUND AssetCA,
                     OUTBOUND AssetProcess,
                     OUTBOUND ParentpChildp,
                     OUTBOUND ProcessSyslog
     OPTIONS {bfs: true}
     FILTER p.vertices[*]._id ANY == "asset/8"
        OR p.vertices[*]._id ANY == "asset/9"
     FILTER p.vertices[*].command ANY == "TSR_Execution"
        AND p.vertices[*].security_threat ANY == "Counterfeit"
     FILTER p.vertices[*].TargetFilename
        AND p.vertices[*].TargetFilename LIKE "%TSR_Execution%"
RETURN p
```

**6.** Through the above code, abnormal behavior of operating such command file was detected:
 - *Firstly, this log corresponds to **event 11**, which is generated when a new file is created or the original **file is overwritten**. It is consistent with the fact that the attacker replaced the "TSR execute" with the stolen "TSR cancel" command file*
 - *Secondly, the process path recorded in* `Image` *field includes **cmd.exe**, indicating that the attacker replaced file through remote commandline*
 - *Then, same abnormal behavior was detected on CTC active (asset8) and standby (asset9), indicating that the attacker had replaced files on both devices*
 - *Finally,* `TargetFilename` *field clearly reveals that the attacker's target is **TSR_execution.CONF***

<div align="center"> <img alt="p2-22" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-22.png?raw=true" width="600px"> </div><br>
**7.** So far, main abnormal behaviors related to threat scenario2 in the dataset have been detected

<br>

# Conclusion
<hr>

**1.** This thesis focuses on **threat modeling** and **anomaly detection** research for train control system. The main contributions are:
 - *A novel threat modeling approach is proposed, which integrates security analysis with the process of system service to achieve the coalescence of functional safety and cyber security of cyber-physical systems*
 -	*A cybersecurity knowledge graph of railway train control system is constructed, which provides researchers with a global analysis perspective by using multidimensional data to model the behavior of railway systems*
 -	*A abnormal behavior detection framework is proposed based on the constructed knowledge graph, which can effectively detect major attack behaviors hidden in system logs and provide visual outputs*

**2.** Although certain results have been achieved, there are still limitations and researchable issues:
 - *The POCA provides a relatively simple description of the attack patterns involved in threat scenarios, which directly leads to the inability to effectively associate two types of CTI when constructing the knowledge graph*
 - *Manual analysis is still used to assist the graph model in making judgments in the bi-directional mode. With the development of AI technology, the attack and defense scenarios will gradually become intelligent. Our graph model should also integrate a variety of model-based intelligent technologies to achieve fully automated analysis and detection*

<div align="right"><a class="top-link hide" href="#top"><font size="6"><b>↑</b></font></a></div><br>
