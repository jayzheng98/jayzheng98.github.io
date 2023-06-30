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
<style>
  table {
    width: 100%;
    border-collapse: collapse;
  }
  th, td {
    text-align: center;
    padding: 8px;
  }
</style>
<a name="top"></a>

# Introduction
<hr>

**1.** In recent years, the signal system of High-speed Railway is facing unprecedented security threats. Since it lacks effective prediction or warning mechanisms for the Advanced Persistent Threats(APT), this project proposes study on cybersecurity threat analysis and defense technology of railway signal system

<div align="center"> <img alt="p2-16" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-16.png?raw=true" width="620px"></div><br>

**2.** This project mainly supported my **master's thesis**, titled <u>"Analysis and Detection of Cyber Threat Behavior in Train Control System Based on Knowledge Graph"</u>
 - *The specific structure of my work is shown below:*

<div align="center"> <img alt="p2-0" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-0.png?raw=true" width="500px"></div>
<br>

# Threat Analysis 
<hr>

## Introducton
**1.** How to testify there are security issues in the rail transit? Maybe we can conduct penetration tests in a simulation environment. But how to figure out the route and goal of cyberattacks within such a complex system? The answer is to firstly conduct a **theoretical threat analysis**

## Design
**1.** I've proposed a novel methodology for the coalescence analysis of safety and security in cyber-physical systems, namely <u>Process-Oriented and Coalescent Analysis (POCA)</u>. Different from the traditional **object-oriented** methods that directly start the analysis with system components or communication links, our method mainly focuses on the specific working process of the object, which is **process-oriented** analysis
 - *The overall framework of this methodology is shown below:*

<div align="center"> <img alt="p2-1" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/pub1-1.png?raw=true" width="620px"> </div><br>

**2.** POCA consists of 2 parts, which are oriented toward **functional safety** and **cyber security** respectively. POCA achieves a coalescence of these 2 attributes by drawing the 2 parts together
 - *The first part, as system service process analysis, abstracts service processes into analyzable objects by referring to the STPA method, which lays a foundation of "process-oriented"*
 - *Another part, as system cyber threat analysis, identifies potential cyber threats based on outputs of the first part according to common security analysis methods*

**3.** I've written an [academic paper](/publication/paper-number-1) about the work of this part for publication
 - *A comparison of POCA with some previous methods is shown below:*

<table style="table-layout: fixed">
  <thead>
   <tr>
    <th>Method</th>
    <th>Safety</th>
    <th>Security</th>
    <th>System Service</th>
    <th>Component Constraint</th>
    <th>Threat Scenario</th>
    <th>TTPs Analysis</th>
    <th>Remediation</th>
   </tr>
  </thead>
  <tbody>
   <tr>
    <td>Attack Trees</td>
    <td>-</td>
    <td>√</td>
    <td>-</td>
    <td>√</td>
    <td>√</td>
    <td>√</td>
    <td>-</td>
   </tr>
   <tr>
    <td>OCTAVE</td>
    <td>-</td>
    <td>√</td>
    <td>-</td>
    <td>-</td>
    <td>√</td>
    <td>-</td>
    <td>√</td>
   </tr>
   <tr>
    <td>STPA</td>
    <td>√</td>
    <td>-</td>
    <td>√</td>
    <td>-</td>
    <td>√</td>
    <td>-</td>
    <td>√</td>
   </tr>
   <tr>
    <td>TARA</td>
    <td>-</td>
    <td>√</td>
    <td>-</td>
    <td>√</td>
    <td>-</td>
    <td>√</td>
    <td>√</td>
   </tr>
   <tr>
    <td>Extended TVRA</td>
    <td>√</td>
    <td>√</td>
    <td>-</td>
    <td>√</td>
    <td>-</td>
    <td>√</td>
    <td>-</td>
   </tr>
   <tr>
    <td>Threat Profile</td>
    <td>-</td>
    <td>√</td>
    <td>-</td>
    <td>-</td>
    <td>√</td>
    <td>√</td>
    <td>-</td>
   </tr>
   <tr>
    <td>STPA-Sec</td>
    <td>-</td>
    <td>√</td>
    <td>√</td>
    <td>-</td>
    <td>√</td>
    <td>-</td>
    <td>√</td>
   </tr>
   <tr>
    <td>STPA-SafeSec</td>
    <td>√</td>
    <td>√</td>
    <td>√</td>
    <td>√</td>
    <td>√</td>
    <td>-</td>
    <td>√</td>
   </tr>
   <tr>
    <td>POCA</td>
    <td>√</td>
    <td>√</td>
    <td>√</td>
    <td>√</td>
    <td>√</td>
    <td>√</td>
    <td>-</td>
   </tr>
 </tbody>
</table>

## Experiment
**1.** I've applied POCA to the <u>Temporary Speed Restriction (TSR)</u> scenario of the train control system, and indeed identified several **threat scenarios** against the TSR service
 - *Since this paper has not been published, here I could only provide part of the analysis output*

<div align="center"><img alt="p2-111" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-111.png?raw=true" width="760px"></div>
<br>

# Threat Simulation
<hr>

## Introduction
**1.** This part not only **verifies the usability of POCA outputs**, but also **provides a dataset** for subsequent research. Due to the closed nature of the railway system, only internal attacks are likely to be implemented. Therefore, common datasets that include external attacks such as Web penetration are not suitable for our demand. Meanwhile, the datasets include attacks against railway systems are difficult to obtain. Thus, we have to generate our own dataset

## Design
### Simulation range
**1.** I've built a simulation range in my laboratory according to the Signal Safety Data Network(SSDN) of train control system ([networking processes](/notes/DC)):

<div align="center"><img alt="p2-3" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-1.png?raw=true" width="750px"></div>

<details><summary style="text-align: center; font-size: 14px;"><b>Click to view range component</b></summary>
  <ul>
    <li><strong>Network Equipment</strong>
      <ul>
        <li><em>The range uses switches to carry communication between the ground equipment, and uses router to connect ground equipment and Centralized Traffic Control (CTC)</em></li>
      </ul>
    </li>
    <li><strong>Data Generation Area(Environment data)</strong>
      <ul>
        <li><em>This area is composed of 5 servers, each running several virtual machines that simulate the ground equipment of the train control system. Since the network cards of the virtual machines are configured in "bridge mode", these servers also act as "switches"</em></li>
        <li><em>The LAN of switch1 is configured as "domain"</em></li>
      </ul>
    </li>
    <li><strong>Attacker</strong>
      <ul>
        <li><em>The attacker operates a Kali Linux host which has already connected to the ISDN server within the LAN of switch 3</em></li>
      </ul>
    </li>
    <li><strong>Data Collection and Analysis Terminal</strong>
      <ul>
        <li><em>This terminal is a host that installs the <a href="https://www.elastic.co/what-is/elasticsearch">Elasticsearch</a> engine, which is responsible for collecting and processing data from the data generation area</em></li>
        <li><em>The knowledge graph constructed later is also deployed on it</em></li>
      </ul>
    </li>
  </ul></details>

<details><summary style="text-align: center; font-size: 14px;"><b>Click to view range configuration</b></summary>
<ul>
  <li>
    <em>Each virtual machine is installed with software to simulate services of the train control system</em>
  </li>
  <li>
    <em><a href="https://learn.microsoft.com/en-us/sysinternals/downloads/sysmon">Sysmon</a> and <a href="https://nxlog.co/products/nxlog-enterprise-edition">NXlog</a> are installed to realize <strong>syslog generation</strong> and <strong>forwarding</strong> separately</em>
  </li>
</ul>
  
<table>
  <thead>
    <tr>
      <th>Device</th>
      <th>Operating System</th>
      <th>IP</th>
      <th>Security Tool</th>
      <th>Main Software</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>RBC active</td>
      <td>Windows 10</td>
      <td>192.168.4.203</td>
      <td>360 Security<br>Windows Defender</td>
      <td>RBC Simulation Software<br>Sysmon+NXlog</td>
    </tr>
    <tr>
      <td>RBC standby</td>
      <td>Windows 10</td>
      <td>192.168.3.105</td>
      <td>Same with active</td>
      <td>Same with active</td>
    </tr>
    <tr>
      <td>ISDN Server active</td>
      <td>Ubuntu 18.04</td>
      <td>192.168.4.206</td>
      <td>ClamAV</td>
      <td>ISDN Simulation Software<br>SysmonForLinux+NXlog</td>
    </tr>
    <tr>
      <td>ISDN Server standby</td>
      <td>Ubuntu 18.04</td>
      <td>192.168.3.106</td>
      <td>Same with active</td>
      <td>Same with active</td>
    </tr>
    <tr>
      <td>TSRS active</td>
      <td>Windows 10</td>
      <td>192.168.4.200</td>
      <td>360 Security<br>Windows Defender</td>
      <td>TSRS Simulation Software<br>Sysmon+NXlog<br>EasyFileSharing</td>
    </tr>
    <tr>
      <td>TSRS standby</td>
      <td>Windows 10</td>
      <td>192.168.3.103</td>
      <td>Same with active</td>
      <td>Same with active</td>
    </tr>
    <tr>
      <td>TSR Interface Server</td>
      <td>Windows Server 2008</td>
      <td>172.110.2.11</td>
      <td>360 Security<br>Windows Defender</td>
      <td>Sysmon+NXlog</td>
    </tr>
    <tr>
      <td>CTC active</td>
      <td>Windows 10</td>
      <td>172.110.2.12</td>
      <td>360 Security<br>Windows Defender</td>
      <td>CTC Simulation Software<br>Sysmon+NXlog</td>
    </tr>
    <tr>
      <td>CTC standby</td>
      <td>Windows 10</td>
      <td>172.110.2.13</td>
      <td>Same with active</td>
      <td>CTC Simulation Software<br>Sysmon+NXlog<br>EasyFileSharing</td>
    </tr>
    <tr>
      <td>Kali Linux</td>
      <td>Kali Linux 2020</td>
      <td>192.168.4.211</td>
      <td>-</td>
      <td>Metasploit<br>MITRE CALDERA</td>
    </tr>
    <tr>
      <td>ELK mainframe</td>
      <td>Windows 10</td>
      <td>10.10.10.230</td>
      <td>360 Security<br>Windows Defender</td>
      <td>Elasticsearch</td>
    </tr>
  </tbody>
</table>
</details>

### Simulation attack
**1.** I designed a complete attack strategy against the system based on the aforementioned POCA output "threat scenario2". It covers all 12 tactics and includes 18 techniques of [MITRE ATT&CK](https://attack.mitre.org/)

<div align="center"> <img alt="p2-5" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-5.png?raw=true" width="790px"> </div> <br>

**2.** I separately implemented the pre and post penetration by Kali in the range, and all syslogs (total 3 days) are saved as the raw dataset

<details><summary style="text-align: center; font-size: 14px;"><b>Click to view dataset example</b></summary>
<div align="center"> <img alt="p2-24" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-24.png?raw=true" width="790px"> </div>
</details>

## Development
### Log labelling
**1.** The highly-textual information contained in logs will greatly increase the workload and difficulty of analysis, so it's necessary to **preprocess** the dataset: try to add a "label" to each log to generalize its behavior

**2.** A [configuration file](https://github.com/olafhartong/sysmon-modular) of Sysmon have actually helped us take the first step. It can map logs to the **ATT&CK techniques** in the `RuleName`, which could properly represent their security behavior

<div align="center"> <img alt="p2-7" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-7.png?raw=true" width="700px"> </div><br>

**3.** However, the above work is kind of rudimentary, since about **93%** logs will be labeled. In other words, its strong generalization results in low identification of real attack behaviors
 - *For example, all operations achieved by Powershell will be labeled as "T1059.001 Powershell", while they can actually be divided more specifically*

**4.** Therefore, we've written another set of **detection rules** ([repository](https://github.com/jayzheng98/Mapping-Sysmonlogs-to-ATTACK)) specialized for the commandline (powershell/cmd/terminal) inputs. It integrates 770 attack abilities of [MITRE CALDERA platform](https://caldera.mitre.org/), covering 11 tactics and about 240 techniques (60%) of ATT&CK matrix
 - *By running the* `test_in_my_case.py` *in the repository, it will overwrite the* `RuleName` *of some logs with more precise "ATT&CK technique_ids", and then export the processed dataset from ELK as* `syslog.csv` *at once*

<br>

# Graph construction
<hr>

## Introduction
**1.** The expanding scale of cyberspace leads to a sharp increase in the amount of security-related data, which are diverse, fragmented, and heterogeneous. **The main challenge** in current security analysis is not data shortage, but how to effectively combine information from multiple sources

**2.** Previous chapters have generated various data, such as threat modeling, system architecture, and system logs. To effectively utilize these outputs, we need to address the **multi-source heterogeneous** issue. Knowledge graph(KG), with its excellent data integration, correlation, and visualization capability, becomes the preferred technology

**3.** Knowledge graph is a large-scale semantic model composed of vertices and edges. It can intuitively model various security scenarios. This section intends to merge all the aforementioned outputs with existing achievements to construct a **cybersecurity KG of train control system**

## Design
### Ontology structure
**1.** A review article "[Recent Progress of Using Knowledge Graph for Cybersecurity](https://www.mdpi.com/2079-9292/11/15/2287)" provides us with a general architecture of CSKG, which consists of 4 dimensions:

<div align="center"> <img alt="p2-8" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-8.png?raw=true" width="540px"> </div><br>

**2.** On the basis of this architecture, we've designed the following ontology structure of our CSKG of train control system. The next 4 sections will separately discuss each dimension

<div align="center"> <img alt="p2-12" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-12.png?raw=true" width="780px"> </div>

<details><summary style="text-align: center; font-size: 14px;"><b>Click to view meaning of edges between dimensions</b></summary>
 <table>
  <thead>
  <tr>
    <th>Dimension</th>
    <th>Relationship</th>
    <th>Description</th>
  </tr>
  </thead>
  <tbody>
  <tr>
    <td>CTI-Knowledge data</td>
    <td>CTI-TTP</td>
    <td>General security CTI is described by "technique" and "tactic" in knowledge data</td>
  </tr>
  <tr>
    <td>Behavior data-Knowledge data</td>
    <td>Syslog-TTP</td>
    <td>"Technique" in knowledge data is used as the label to generalize the behavior of "syslog" in behavior data</td>
  </tr>
  <tr>
    <td>Environment data-Behavior data</td>
    <td>Asset-Process</td>
    <td>"Process" in behavior data can be correlated with "asset" in environment data based on IP address</td>
  </tr>
  <tr>
    <td>Environment data-CTI</td>
    <td>Asset-CA</td>
    <td>"Control action" in specific railway CTI is carried out by "asset" in environment data</td>
  </tr>
  <tr>
    <td>Environment data-CTI</td>
    <td>Asset-Weakness</td>
    <td>"Weakness" in specific railway CTI exists in "asset" in environment data</td>
  </tr>
  </tbody>
 </table>
</details>
<details><summary style="text-align: center; font-size: 14px;"><b>Click to view meaning of edges within dimensions</b></summary>
  <table>
  <thead>
  <tr>
    <th>Dimension</th>
    <th>Relationship</th>
    <th>Description</th>
  </tr>
  </thead>
  <tbody>
  <tr>
    <td rowspan="8">Knowledge data</td>
    <td>Tactic-Technique</td>
    <td>Tactic includes multiple techniques</td>
  </tr>
  <tr>
    <td>Technique-Capec</td>
    <td>ATT&CK techniques and CAPEC attack patterns have overlaps</td>
  </tr>
  <tr>
    <td>Technique-Technique</td>
    <td>Parent-child relationship exists among techniques</td>
  </tr>
  <tr>
    <td>Capec-Capce</td>
    <td>Parent-child relationship exists among attack patterns</td>
  </tr>
  <tr>
    <td>Technique-Technique_mitigation</td>
    <td>Mitigations can reduce the impact of techniques</td>
  </tr>
  <tr>
    <td>Technique-Technique_detection</td>
    <td>Detection methods can identify traces of techniques</td>
  </tr>
  <tr>
    <td>Capec-Cwe</td>
    <td>Attack patterns exploit weaknesses in components</td>
  </tr>
  <tr>
    <td>Cwe-Cve</td>
    <td>Weaknesses in components include multiple vulnerabilities</td>
  </tr>
  <tr>
    <td rowspan="8">CTI</td>
    <td>CTI-CTI</td>
    <td>Sequential relationship exists among attack behaviors</td>
  </tr>
  <tr>
    <td>Accident-Hazard</td>
    <td>System hazards can cause accidents</td>
  </tr>
  <tr>
    <td>Hazard-Service</td>
    <td>Abnormalities in service can cause system hazards</td>
  </tr>
  <tr>
    <td>Service-CA</td>
    <td>Services include multiple control actions</td>
  </tr>
  <tr>
    <td>CA-Weakness</td>
    <td>Control actions may lead to unsafe control actions</td>
  </tr>
  <tr>
    <td>Weakness-Weakness</td>
    <td>Parent-child relationship exists among unsafe control actions</td>
  </tr>
  <tr>
    <td>TS-Weakness</td>
    <td>Threat scenarios include multiple unsafe control actions</td>
  </tr>
  <tr>
    <td>TS-TS</td>
    <td>Parent-child relationship exists among threat scenarios</td>
  </tr>
  <tr>
    <td>Environment Data</td>
    <td>Asset-Asset</td>
    <td>Connection relationship exists among assets</td>
  </tr>
  <tr>
    <td rowspan="4">Behavior Data</td>
    <td>Syslog-Syslog</td>
    <td>Chronologic relationship exists among syslogs</td>
  </tr>
  <tr>
    <td>Process-Syslog</td>
    <td>Processes include multiple logs</td>
  </tr>
  <tr>
    <td>Process-Process</td>
    <td>Access relationship exists among processes</td>
  </tr>
  <tr>
    <td>Parentp-Childp</td>
    <td>Parent-child relationships exists among processes</td>
  </tr>
  </tbody>
</table>
</details><br>

### ① Knowledge data
**1.** Knowledge data from common cybersecurity knowledge bases, such as [ATT&CK](https://attack.mitre.org/), [CAPEC](https://capec.mitre.org/), [CWE](https://cwe.mitre.org/) , [CVE](https://nvd.nist.gov), [MITRE Engage](https://engage.mitre.org/) and [D3FEND](https://d3fend.mitre.org/), are already linked together by researchers from MIT as an [open source](https://github.com/ALFA-group/BRON) graph "[BRON](https://arxiv.org/pdf/2010.00533.pdf)". So I directly imported BRON as the <u>knowledge data</u>
 - *The ontology structure of BRON's main part is shown below:*

<div align="center"> <img alt="p2-9" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-9.png?raw=true" width="460px"> </div> 

### ② General security CTI
**1.** This dimension is represented as the "cyber threat intelligence(CTI)" ontology. At present, most common CTI exist in **unstructured** or **semi-structured** forms. In order to construct the KG of this dimension, we need to extract those CTI into **structured data**

**2.** MITRE developed an [open source](https://github.com/center-for-threat-informed-defense/tram/) platform "[TRAM](https://medium.com/mitre-engenuity/tram-advancing-research-into-automated-ttp-identification-in-threat-reports-2d868fecc791)", which can associate the input attack procedure (left) with ATT&CK techniques and tactics (right) to help generate CTI in a structured form as "TTPs"

<div align="center"> <img alt="p2-10" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-10.png?raw=true" width="640px"> </div><br>

**3.** Through the TRAM platform and manual verification, we've generated the <u>general security CTI</u> of some common attacks, which could be easily imported into graph
 - *The figure below shows an example of the extracted "file stealing" attack*

<div align="center"> <img alt="p2-23" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-23.png?raw=true" width="740px"> </div>

### ② Specific railway CTI
**1.** This CTI refers to the threat modeling results of target system. In this project, it is generated by [POCA](#threat-analysis). The ontology structure of POCA outputs is shown below:
 - *Results such as "control action", "hazard" and "threat scenario" can be presented as ontologies*
 - *Results like "risk score" and "description" can be used as attributes of ontologies*

<div align="center"> <img alt="arango8" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/arango8.png?raw=true" width="290px"> </div>

**2.** The following is a conceptual display of entities and relationships in the <u>specific railway CTI</u>:
 - *A small part of the content in the figure is different from the actual one*

<div align="center"> <img alt="p2-2" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-4.png?raw=true" width="780px"> </div>

### ③ Environment data
**1.** This dimension is represented as the “asset” ontology. It is generally based on the topology of target system and includes attributes such as OS and IP of the equipment. It not only models the physical composition of target system, but also acts as a bridge between <u>behavior data</u> and <u>CTI</u>
 - *The environment data of this project has been provided [here](#simulation-range)*

### ④ Behavior data
**1.** The <u>behavior data</u> of this project is the syslog generated by Sysmon, and "behavior" is represented by the [ATT&CK technique label](#log-labelling)

**2.** Details of this part are summarized in this [repository](https://github.com/jayzheng98/Syslog-Graph). In short, logs whose `EventID` = `1 (ProcessCreate)` or `10 (ProcessAccess)` contain info that separately represent 2 kinds of process relations: "parentp-childp" and "process-process". We can utilize them as well as the inherent "time" as the 3 major relations to form a **syslog ontology structure**:

<div align="center"> <img alt="p2-11" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-11.png?raw=true" width="230px"> </div>

## Development
**1.** As for the development, knowledge graph can be constructed through **graph database**. This project chooses the [ArangoDB](https://www.arangodb.com/), and its basic construction processes are recorded [here](/notes/arangodb)

**2.** Here, I take the <u>specific railway CTI</u> and <u>environment data</u> 2 dimensions as examples to display the actually constructed graph:

<div align="center"> <img alt="p2-13" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-13.png?raw=true" width="770px"> </div><br>

**3.** Basic indicators of the constructed KG:
<details><summary style="text-align: center; font-size: 14px;"><b>Click to view indicators</b></summary>
<table>
  <thead>
    <tr>
      <th>Indicator</th>
      <th>Definition</th>
      <th>Value</th>
      <th>Explanation</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Nodes</td>
      <td>Number of nodes</td>
      <td>$500966$</td>
      <td>-</td>
    </tr>
    <tr>
      <td>Edges</td>
      <td>Number of edges</td>
      <td>$1685976$</td>
      <td>The graph is a directed graph</td>
    </tr>
    <tr>
      <td>Isolated Nodes</td>
      <td>Number of nodes with no edges</td>
      <td>$22368$</td>
      <td>As some nodes in BRON are isolated, this graph is a disconnected graph</td>
    </tr>
    <tr>
      <td>Network Density</td>
      <td>Ratio of actual edges to possible edges</td>
      <td>$6.72\times10^{-6}$</td>
      <td>The density is close to 0, indicating that the graph is sparse</td>
    </tr>
    <tr>
      <td>Average Degree</td>
      <td>The sum of degrees of all nodes divided by the number of nodes</td>
      <td>$6.73$</td>
      <td>On average, each node has connected with 6.73 edges</td>
    </tr>
    <tr>
      <td>Maximum Depth</td>
      <td>The longest path from the root node to a leaf node</td>
      <td>$10$</td>
      <td>The graph has the maximum depth when its root is the "accident" layer and its leaf is the "CVE" layer</td>
    </tr>
    <tr>
      <td>Network Diameter</td>
      <td>The longest shortest path between any two nodes</td>
      <td>$14$</td>
      <td>Such path is found between an "accident" node and a "CVE" node</td>
    </tr>
  </tbody>
</table>
</details>
<br>

# Anomaly Detection
<hr>

## Introduction
**1.** Modern cyberattacks are often carried out in a concealed and highly variable style, which lack obvious features or patterns. Thus, traditional methods are difficult to effectively identify them. Therefore, **behavior-based** anomaly detection has become an important idea, which identifies potential threats by modeling system behaviors and detecting abnormal ones on this basis

## Design
### Detection framework
**1.** From a macro perspective, the project studies 2 types of behavior: <u>abstract threat behavior</u> derived through theoretical analysis (**CTI** in KG), and <u>specific system behavior</u> collected through practical experiments (**behavior data** in KG). The overall threat detection idea is "based on **CTI** dimension, supplemented by other dimensions, detect anomalies in **behavior data** dimension"

<div align="center"> <img alt="p2-14" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-14.png?raw=true" width="660px"> </div><br>

**2.** Based on this idea, I've designed a **behavior-based anomaly detection framework** shown above, which defines 3 kinds of behaviors according to the threat level from low to high:
 - <b>System device behavior</b> 
   - *It is the complete set of <u>behavior data</u>, including 2 subsets of mid & high-level behavior*
   - *Due to the high proportion of labelled syslogs, it is hard to identify the abnormal data hidden in massive normal data at this level*
 - <b>Security threat behavior</b>
   - *It is detected when some <u>system device behaviors</u> satisfy a specific attack pattern recorded in <u>general security CTI</u>*
   - *The idea is: search for combination of syslogs in which their "ATT&CK technique labels" match the "techniques" used by the attack pattern*
 - <b>Service abnormal behavior</b> 
   - *It is detected when some <u>security threat behaviors</u> further conform to a specific threat scenario described in <u>specific railway CTI</u>*
   - *The idea is: among detected attack patterns, search for those that involve operations of certain "service command file" exploited by the threat scenario*

### Detection modes
**1.** As for the application, this framework can perform 2 detection modes: 
 - ***Bottom-up** means the detection is from the low-level all the way up to the high-level, and directly achieves the anomaly detection*
 - *However, considering the complexity of cyber attacks and the incompleteness of CTI in the KG, high-level abnormal behavior usually cannot be directly mapped through the bottom-up detection. Therefore, the more flexible **bi-directional** detection should be widely applied*

<div align="center"> <img alt="p2-15" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-15.png?raw=true" width="780px"> </div>

**2.** The program flowchart of following experiment based on the detection framework is:

<div align="center"> <img alt="p2-16" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-6.png?raw=true" width="660px"> </div><br>

## Experiment
**1.** Graph traversal is the technical carrier of this detection experiment. Since our KG has a relatively large depth, the Breadth-First Search (BFS) is more applicable and efficient
 - *ArangoDB's query language [AQL](https://www.arangodb.com/docs/stable/aql/index.html) has integrated multiple basic algorithms including BFS, so we could develop detection functions based on it*

### Security threat behavior detection (low → middle)
**1.** The general idea for detection at this level is:
 - *Traverse within "CTI" to obtain all attack patterns' entities (CTI)*
 - *Traverse to "asset" through "syslog" to find related logs for each pattern (behavior data)*
 - *Output the traversal path as the detection result*
 
```sql
FOR vertices,edges,paths IN ANY 'CTI/steal1'
                CTICTI,
                CTITTP,
                OUTBOUND TechniqueTechnique_mitigation,
                INBOUND SyslogTTP,
                INBOUND ProcessSyslog,
                INBOUND ParentpChildp,
                INBOUND AssetProcess
    OPTIONS {bfs:ture}
RETURN paths
```

**2.** After executing codes similar to above, 2 kinds of attack patterns were successfully detected:
 - *Lateral movement*
 
<div align="center"> <img alt="p2-17" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-17.png?raw=true" width="740px"> </div><br>
 - *File stealing*

<div align="center"> <img alt="p2-18" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-18.png?raw=true" width="760px"> </div><br>

### Service abnormal behavior detection (middle → high)
**1.** The basis for mapping from mid-level to high-level is the **service command files**. The general idea for detection at this level is:
- *Based on the traversal result of <b>security threat behavior detection</b>, set filter conditions for the specific command file to continue traversing upwards*

**2.** For the detected "lateral movement", it does not involve any command file; For the "file stealing", the commandline input of "syslog/23647" (corresponding to the 3rd step of this attack pattern) indicates that it used the `Copy-Item` to copy (steal) the "TSR_Cancel.CONF" command file to a folder called "staged":

<div align="center"> <img alt="p2-19" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-19.png?raw=true" width="480px"> </div><br>

**3.** Based on this clue, the "file stealing" attack may be further mapped to the high-level service abnormal behavior

```sql
FOR vertices,edges,paths IN 1..8 ANY 'CTI/steal3'
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
RETURN paths
```

**4.** After executing the above code, only the first step of threat scenario2 (node "TS2") was matched, suggesting that **bottom-up** detection is insufficient for our dataset. Therefore, **bi-directional** detection is required to further trace subsequent steps of threat scenario2

<div align="center"> <img alt="p2-20" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-20.png?raw=true" width="570px"> </div><br>

### Service abnormal behavior detection (high → low)
**1.** The general idea for detection at this level is:
 - *Traverse within "threat_scenario" to obtain remaining threat scenarios' entities (CTI)*
 - *Traverse downward to "syslog" to find related logs for each scenario (behavior data)*
 - *Output the traversal path as the detection result*

**2.** At first, node "TS2.1" was read, which involves **tampering** with the **TSR cancel** command file. However, since this file was tampered locally by the attacker, no relevant logs can be detected

**3.** Then, continue traversing to the "TS2.1.1" node, which involves **leakage** of the **TSR execution reminder** command file. The corresponding AQL code is:

```sql
FOR vertices,edges,paths IN 1..7 ANY 'threat_scenario/TS2'
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
RETURN paths
```

**4.** Through the above code, abnormal behavior of operating such command file was detected:
 - *Firstly,* `RuleName` *field of "syslog/24049" indicates the involvement of **script and payload**, suggesting that it is highly likely a trace of attacker monitoring the **TSR execution reminder***
 - *Furthermore, the* `TargetFilename` *field records the monitored file and its location as "C:\Users\Administrator\AppData\Roaming\Microsoft\Windows\Recent", which is typically used to store shortcuts of recently used files*
 - *Therefore, it can be inferred that the script used by attacker doesn't directly monitor the original command file, but a shortcut in another directory*

<div align="center"> <img alt="p2-21" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-21.png?raw=true" width="580px"> </div><br>
**5.** Continue traversing to the "TS2.1.1.1" node, which involves the **counterfeit** of **TSR execution** command file. The corresponding AQL code is:

```sql
FOR vertices,edges,paths IN 1..8 ANY 'threat_scenario/TS2'
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
RETURN paths
```

**6.** Through the above code, abnormal behavior of operating such command file was detected:
 - *Firstly, "syslog/4634" corresponds to **event 11**, which is generated when a new file is created or the original **file is overwritten**. It is consistent with the fact that the attacker replaced the "TSR execute" with the stolen "TSR cancel" command file*
 - *Secondly, the process path recorded in* `Image` *field includes **cmd.exe**, indicating that the attacker replaced file through remote commandline*
 - *Then, same abnormal behavior was detected on CTC active (asset8) and standby (asset9), indicating that the attacker had replaced files on both devices*
 - *Finally,* `TargetFilename` *field clearly reveals that the attacker's target is **TSR_execution.CONF***

<div align="center"> <img alt="p2-22" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-22.png?raw=true" width="750px"> </div><br>

## Assessment
### Detection result
**1.** We collected the detection results of our KG model and performed detection on the same dataset using a log analysis platform based on the ELK engine as a reference

**2.** As shown below, the log analysis platform detected **40%** of all the attack processes, while the KG identified **60%**, with a higher availability in detecting post-penetration attack

<table>
 <thead>
  <tr>
    <th>Stage</th>
    <th>Process</th>
    <th>Description</th>
    <th>Detected by KG?</th>
    <th>Detected by ELK?</th>
  </tr>
 </thead>
 <tbody>
  <tr>
    <td rowspan="5">Pre-penetration</td>
    <td>1</td>
    <td>Exploit vulnerabilities to establish connection with CTC from specific port</td>
    <td>×</td>
    <td>√</td>
  </tr>
  <tr>
    <td>2</td>
    <td>Elevate permissions on CTC through MSF commands such as process migration</td>
    <td>×</td>
    <td>×</td>
  </tr>
  <tr>
    <td>3</td>
    <td>Establish the proxy link between Caldera and CTC through the Meterpreter shell</td>
    <td>√</td>
    <td>√</td>
  </tr>
  <tr>
    <td>4</td>
    <td>Use the Mimikatz to steal the name and password of CTC domain administrator</td>
    <td>×</td>
    <td>×</td>
  </tr>
  <tr>
    <td>5</td>
    <td>Use stolen credentials to realize the lateral movement between the CTC active and standby</td>
    <td>√</td>
    <td>√</td>
  </tr>
  <tr>
    <td rowspan="5">Post-penetration</td>
    <td>1</td>
    <td>Search in all agent hosts for reserved historic "TSR cancel" files</td>
    <td>√</td>
    <td>×</td>
  </tr>
  <tr>
    <td>2</td>
    <td>Copy searched files to the Kali and delete the attack trace</td>
    <td>√</td>
    <td>√</td>
  </tr>
  <tr>
    <td>3</td>
    <td>Tamper the content of the "TSR cancel" configuration file locally for forgery</td>
    <td>×</td>
    <td>×</td>
  </tr>
  <tr>
    <td>4</td>
    <td>Remotely upload a PS script to CTC standby to monitor the change of its "execution reminder" file</td>
    <td>√</td>
    <td>×</td>
  </tr>
  <tr>
    <td>5</td>
    <td>Once the targeted file changed, replace the "TSR execution" file with the counterfeit one</td>
    <td>√</td>
    <td>×</td>
  </tr>
 </tbody>
</table>

**3.** To further demonstrate the advantage of behavior-based detection, we take the detection of "Post-penetration process 5" as an example to analyze the difference between the 2 approaches:
 - *Actually, the log analysis platform contains detection rules for the "malicious file replacement", but primarily based on the "source IP", "file name", and "replaced content". However, in our designed attack, the attacker's IP was pre-set as legitimate, and the target file was only replaced by another service command file, without any malicious code. This case indicates that the platform's **feature-based** detection can be easily bypassed*
 - *On the contrary, the detection of our KG model is **behavior-based**. Regardless of changes in features such as "IP", "file name", or "file content", as long as the adversary still exhibits the behavior as "replacing command file", it will be recognized as an anomaly in system service*

<br>

# Conclusion
<hr>

**1.** This thesis focuses on **threat modeling** and **anomaly detection** research for train control system. The main contributions are:
 - *A novel threat modeling approach is proposed, which integrates security analysis with the process of system service to achieve the coalescence of functional safety and cyber security of cyber-physical systems*
 -	*A cybersecurity knowledge graph of railway train control system is constructed, which provides researchers with a global analysis perspective by using multidimensional data to model the behavior of railway systems*
 -	*A abnormal behavior detection framework is proposed based on the constructed knowledge graph, which can effectively detect major attack behaviors hidden in system logs and provide intelligible visual outputs*

**2.** Although certain results have been achieved, there are still limitations and researchable issues:
 - *The POCA provides a relatively simple description of the attack patterns involved in threat scenarios, which directly leads to the inability to effectively associate 2 types of CTI when constructing the knowledge graph*
 - *Manual analysis is used to assist the graph model in the bi-directional detection. With the development of AI technology, the attack and defense scenarios will gradually become intelligent. Our graph model should also integrate a variety of model-based intelligent technologies to achieve fully automated analysis and detection*

<div align="right"><a class="top-link hide" href="#top"><font size="6"><b>↑</b></font></a></div><br>
