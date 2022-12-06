---
layout: single
collection: notes
permalink: /notes/DC
title: "Device Configuration"
author_profile: false
toc: true
toc_label: "Contents"
---

<a name="top"></a>

<br>

# Introduction
<hr>

As mentioned in the [project](), I've set up a simulation shooting range in my laboratory according to the network topology of high-speed railway signal system, and the topology diagram is shown below. This article roughly records my networking process

<div align="center"> <img alt="dc1" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/proj2-1.png?raw=true" width="720px"> </div>
<br>

# Layer 3 Switch
<hr>

## Cisco 
**1. Device overview**
 - *The layer 3 switch in the pic is [Catalyst 3560G series](https://www.cisco.com/c/en/us/support/switches/catalyst-3560-series-switches/series.html)*

<div align="center"> <img alt="dc2" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/dc1.jpg?raw=true" width="550px"> </div><br>

**2. Connect for configuration**
 - *Usually there is a <u>console interface</u> behind the switch*

<div align="center"> <img alt="dc3" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/dc2.jpg?raw=true" width="350px"> </div>

 - *Connect it with PC by the console cable*

<div align="center"> <img alt="dc4" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/dc3.jpg?raw=true" width="300px"> </div><br>

**3. Set up for configuration**
 - *Download the [Hyper Terminal](https://www.hilgraeve.com/hyperterminal-trial/) which provides us with the terminal to configure devices*
 - *Set up a new connection, and select the <u>cluster communication port(COM)</u> which was former connected with console cable*

<div align="center"> <img alt="dc5" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/dc4.png?raw=true" width="300px">    <img alt="dc6" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/dc5.png?raw=true" width="400px"> </div>

 - *When you see the* `Switch>` *, it means that you have successfully connected to your device*

<div align="center"> <img alt="dc7" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/dc6.png?raw=true" width="400px"> </div><br>

**4. Configure**
 - *Here are some useful commands to configure Cisco switches*
 
```
enable 
conf ter

// Create vlan "xx" and configure IP (address, mask)
vlanxx
int vlan xx
ip add 192.168.4.1 255.255.255.0

// Include ports in vlan xx
int g0/7
switchport mode access
switchport access vlan xx

// Enable routing between vlans
ip routing
 
// Configure static route (destination address, mask, destination gateway)
ip route 172.110.2.0 255.255.255.0 192.168.2.2
 
// Save and exit
exit
write
 
// Show configurations
show vlan
show int vlanxx
show ip route
```

 - *The final configuration of my range is shown below, it is exactly the same with the topology. Then I only need to configure the network of every computer and server and connect their network cards to the switch interfaces accordingly*
 
<div align="center"> <img alt="dc8" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/dc7.png?raw=true" width="450px">   <img alt="dc9" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/dc8.png?raw=true" width="450px"> </div> 

## H3C
**1. Device overview**
 - *The H3C layer 3 switch in my lab is [S3600 series](https://www.h3c.com/en/Support/Resource_Center/HK/Switches/H3C_S3600/H3C_S3600_Series_Switches/default.htm)*

<div align="center"> <img alt="dc11" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/dc10.jpg?raw=true" width="600px"> </div><br>

**2. Configure**
 - *Actually I didn't add this switch in my network in the end, so here I just simply record some commands of its configuration*

```
sys

// Create vlan "xx" and configure IP (address, mask)
vlan xx
int vlan-interfacexx
ip add 192.168.5.254 255.255.255.0

// Include ports in vlan xx
vlan xx
port g1/0/1
port g1/0/2 to g1/0/10

// H3C switches enable routing between vlans by default

// Configure static route (destination address, mask, destination gateway)
ip route-static 192.168.5.0 24 192.168.5.1

// Save and exit
q
save

// Show configurations
display ip routing-table
display vlan
display int vlan xx
```

<div align="center"> <img alt="dc10" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/dc9.jpg?raw=true" width="550px"> </div>
<br>

# Router
<hr>

## UTT 
**1. Device overview**
 - *The router in the pic is [HiPER 840G](https://www.utt.com.cn/productdetail.php?modelid=178)*

<div align="center"> <img alt="dc12" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/dc11.jpg?raw=true" width="550px"> </div><br>

**2. Connect for configuration**
 - *Use a PC to connect to its <u>LAN</u> interface, then input the IP address of this LAN to login the configuration website (The default IP of my device is 192.168.1.1)*


<div align="right"><a class="top-link hide" href="#top"><font size="6"><b>↑</b></font></a></div><br>
