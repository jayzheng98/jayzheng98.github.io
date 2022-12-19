---
layout: single
collection: notes
permalink: /notes/arangodb
title: "ArangoDB"
author_profile: false
toc: true
toc_label: "Contents"
---

<a name="top"></a>

# Introduction
<hr>

**1.** There are already very detailed [official tutorials](https://www.arangodb.com/docs/stable/) about ArangoDB, so it will be meaningless for me to reproduce them here
 - *[Tutorial1](https://www.arangodb.com/community-server/sql-aql-comparison/): If you were familiar with SQL, you can get started with AQL quickly*
 - *[Tutorial2](https://www.arangodb.com/tutorials/tutorial-python/): Drive it with Python*

**2.** This note will mainly record my operations on ArangoDB while working on this [project](/projects/project2). To be more specific, it will show you the processes of importing the output of this [academic paper](/publication/paper-number-1) into the "BRON" graph that was already constructed

<div align="center"> <img alt="arango0" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/arango0.png?raw=true" width="760px"> </div><br>

**3.** After using ArangoDB for a period of time, I found it really convenient and I literally love this graph database 🥰

<br>

# Preparation
<hr>

**1.** To begin with, let's sort out all the analysis results of my paper. Since the collection(table) of Arango is in the format of `JSON`, we have to decide how many collections should be derived from these knowledges, and import them to `JSON` format files separately. According to my paper, the threat knowledges of railway signal system can be divided into:
 - *Accident, Hazard, Service, Control Action, Weakness, Safety Constraint, Asset and Threat Scenario*

**2.** Actually we don't need to transform all the knowledges into `JSON` format which is elusive directly, but could write them in the format of `CSV`
 - *For example, "accident.csv", "AccidentHazard.csv(relation)", "hazard.csv", "HazardService.csv(relation)" and "service.csv" is shown below:*

<div align="center"> <img alt="arango1" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/arango1.png?raw=true" width="750px"></div><br>

# Create Collections
<hr>

**1.** Import the aforementioned `CSV` files one by one to the ArangoDB by running the following on your command-line:
 - *Document*

```shell
arangoimport --file PATH TO ".csv" ON YOUR MACHINE --collection NAME --create-collection true --type csv
```
 - *Edge*

```shell
arangoimport --file PATH TO ".csv" ON YOUR MACHINE --collection NAME --create-collection true --type csv --create-collection-type edge
```

**2.** Results:
 - *The import processes of "Control Action", "Weakness", "Safety Constraint", "Asset" and "Threat Scenario" are omitted here*

<div align="center"> <img alt="arango2" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/arango2.png?raw=true" width="760px"> </div><br>
<div align="center"> <img alt="arango3" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/arango3.png?raw=true" width="760px"> </div><br>

<div align="right"><a class="top-link hide" href="#top"><font size="6"><b>↑</b></font></a></div><br>
