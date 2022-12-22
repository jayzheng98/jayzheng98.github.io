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
 - *[Tutorial3](https://github.com/jayzheng98/jayzheng98.github.io/blob/master/files/ArangoDB-GraphCourse_Beginners.pdf?raw=true): A basic but comprehensive graph course for freshers*

**2.** This note will mainly record my operations on ArangoDB while working on this [project](/projects/project2). To be more specific, **the next 4 chapters** will be a practical tutorial and show you the processes of importing the output of this [ paper](/publication/paper-number-1) into the "BRON" graph that was already constructed

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

**3.** You can see that ArangoDB uses an individual file to correlate two collections like "Mysql", such isolation allows us to easily and accurately modify the contents of the database 
 - *The* `_from` *and* `_to` *attributes of the "edge" file form the graph by referencing document* `_ids`
 - *The* `_id` *is automatically generated while importing by concatenating the "collection name" and* `_key` *with "/"*
<br>

# Create Collections
<hr>

**1.** Import the aforementioned `CSV` files one-by-one to the ArangoDB by running the following on your command-line:
 - *Document*

```shell
arangoimport --file PATH TO ".csv" ON YOUR MACHINE --collection NAME --create-collection true --type csv
```
 - *Edge*

```shell
arangoimport --file PATH TO ".csv" ON YOUR MACHINE --collection NAME --create-collection true --type csv --create-collection-type edge
```

**2.** Results (The import processes of "Control Action", "Weakness", "Safety Constraint", "Asset" and "Threat Scenario" are omitted here):
<div align="center"> <img alt="arango2" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/arango2.png?raw=true" width="760px"> </div><br>
<div align="center"> <img alt="arango3" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/arango3.png?raw=true" width="760px"> </div><br>

# Query & Traversal
<hr>

**1.** **Query** to find out how many "services" have "abbreviation":

```sql
FOR s IN service
  FILTER s.abbreviation
  RETURN s.name
```
<div align="center"> <img alt="arango4" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/arango4.png?raw=true" width="400px"> </div><br>

**2.** **Query** to see the relationship between "accident" and "hazard":

```sql
FOR r IN AccidentHazard
  RETURN r
```
<div align="center"> <img alt="arango5" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/arango5.png?raw=true" width="360px"> </div><br>

**3.** **Traverse** to check whether our collections are correlated together (start from "service/S8"):
 - `FOR` *vertex(, edge)(, path)*
 - `IN min..max` *defines the minimal and maximal depth for the traversal (min defaults to 1 and max defaults to min)*
 - `OUTBOUND/INBOUND/ANY` *defines the direction of your search*
 - *The subsequent format is 'StartVertex' edge_collection1, edge_collection2, ...*

```sql
-- Traversal follows outgoing edges, only returns "accidents" caused by "S8" (Result: left pic)
FOR v, e, p IN 1..3 OUTBOUND 'service/S8' HazardService, AccidentHazard
  RETURN p

-- Traversal follows edges pointing in any direction, will return more contents like "S4" (Result: right pic)
FOR v, e, p IN 1..5 ANY 'service/S8' HazardService, AccidentHazard
  RETURN p
```
<div align="center"> <img alt="arango6" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/arango6.png?raw=true" width="325px"> &ensp;&ensp; <img alt="arango7" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/arango7.png?raw=true" width="310px"></div><br>

# Create Graphs
<hr>

**1.** In ArngoDB we can directly construct a graph to **view** the whole structure of our knowleges. Notice that this is only a **viewing tool**, all the collections in a database are already a comprehensive graph
 - *The **abstract structure** of all POCA analysis results is shown below:*

<div align="center"> <img alt="arango8" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/arango8.png?raw=true" width="350px"> </div>
  
**2.** According to the abstract structure, we can use corresponding collections to construct the graph with ArangoDB, it is pretty simple:

<div align="center"> <img alt="arango9" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/arango8.png?raw=true" width="325px">  <img alt="arango10" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/arango10.png?raw=true" width="425px"></div>

**3.** The final graph of POCA analysis results in ArangoDB is shown below:

<div align="center"> <img alt="arango11" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/arango11.png?raw=true" width="725px"></div>

<div align="right"><a class="top-link hide" href="#top"><font size="6"><b>↑</b></font></a></div><br>
