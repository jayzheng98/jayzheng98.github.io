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
 - *[Tutorial1](https://www.arangodb.com/community-server/sql-aql-comparison/): If you were familiar with SQL, you can get started quickly with AQL*
 - *[Tutorial2](https://www.arangodb.com/tutorials/tutorial-python/): Drive it with Python*

**2.** This note will mainly record my operations on ArangoDB while working on [this project](/projects/project2). To be more specific, it will show you the processes of importing the output of this [academic paper](/publication/paper-number-1) into the "BRON" graph that was already constructed

<div align="center"> <img alt="p2-10" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-10.png?raw=true" width="780px"> </div> 

**3.** After using ArangoDB for a period of time, I found it really convenient and I literally love this graph database 🥰
<br>

# Preparation
<hr>

**1.** To begin with, let's sort out all the analysis results of my paper. Since the collection(table) of Arango is in the format of JSON, we have to decide how many collections should be derived from these knowledges, and write them into JSON format files separately. According to my paper, the threat knowledges of railway signal system can be divided into the following categories:
 - *Accident, Hazard, Service(include control action & weakness), Safety Constraint, Asset and Threat Scenario*


<div align="right"><a class="top-link hide" href="#top"><font size="6"><b>↑</b></font></a></div><br>
