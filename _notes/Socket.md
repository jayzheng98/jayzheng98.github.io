---
layout: archive
collection: notes
permalink: /notes/socket
title: "Socket"
author_profile: false
redirect_from: 
  - /socket/
---

<a name="top"></a>

<!-- GFM-TOC -->
* Categories 
    * [Introduction](#introduction)
    * [Linux](#linux)
       * [UDP Client](#udp-client)
       * [UDP Server](#udp-server)
       * [TCP Client](#tcp-client)
       * [TCP Server](#tcp-server)
       * [Test](#test)
    * [Windows](#windows)

<!-- GFM-TOC -->

<br>

# Introduction
<hr>

**1.** Actually the complex rationale behind Socket is not recorded in this article. The aim of this page is to help people get started quickly. They can modify the templates according to their needs

**2.** Besides the common data types such as "number" and "string", Socket can also transfer "structure" and "class" which is shown in [UDP Client](#udp-client)

**3.** All codes are written in *C++*

<br>

# Linux
<hr>

## UDP Client
```c++
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>          // Socket header file on Linux
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

struct UsrData {                // Test structure
    int usr_id;
    char usr_nickname[8];
};

class circle {                  // Test class
public:
    int m_r;
    double calculate() {
        return 2 * 3.14 * m_r;
    }
};

int main() {
    // Create a Socket (address type, socket type, protocol type)
    unsigned int sendSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); 

    // Bind your own address
    struct sockaddr_in sockAddr;
    socklen_t len = sizeof(sockAddr);
    memset(&sockAddr, 0, sizeof(sockAddr));
    sockAddr.sin_family = AF_INET;                            // Use IPv4 address
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");        // Specific IP address
    sockAddr.sin_port = htons(8888);                          // Port
    // "htonl()" converts the unsigned integer from host byte order to network byte order

    circle c1;
    c1.m_r = 10;
    UsrData sendUser;
    sendUser.usr_id = 1251;
    strcpy(sendUser.usr_nickname, "Zhongyi");

    // Send class and structure
    int n1 = sendto(sendSock, (class circle *) &c1, sizeof(c1), 0, (struct sockaddr *) &sockAddr, len);
    int n2 = sendto(sendSock, (struct UsrData *) &sendUser, sizeof(sendUser), 0, (struct sockaddr *) &sockAddr, len);
    // "sendto()" and "recvfrom()" return the number of bytes that have been transferred
    printf("Sent: %d\n", n1);
    printf("Sent: %d\n", n2);
    
    unsigned char reply[32];
    recvfrom(sendSock, reply, sizeof(reply), 0, (struct sockaddr *) &sockAddr, &len);
    printf("Reply: %s\n", reply);

    close(sendSock);
    return 0;
}
```
## UDP Server

```c++
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

struct UsrData{
    int usr_id;
    char usr_nickname[8];
};

class  circle{
public:
    int  m_r;
    double calculate(){
        return 2*3.14*m_r;
    }
};

int main() {
    int recevSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    struct sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sockAddr.sin_port = htons(8888);
    bind(recevSock, (struct sockaddr *) &sockAddr, sizeof(sockAddr));  // Notice this step is uneeded in "client"

    // Receiver doesn't need to know the sender's address, but needs an empty struct to receive address info
    struct sockaddr_in sendAddr;
    socklen_t len = sizeof(sendAddr);

    circle c2;
    struct UsrData recvUser;
    unsigned char reply[32] = {"Successfully received!"};

    while(1){
        int n1 = recvfrom(recevSock, (class circle *) &c2, sizeof(c2), 0, (struct sockaddr *) &sendAddr, &len);
        int n2 = recvfrom(recevSock, (struct UsrData *) &recvUser, sizeof(recvUser), 0, (struct sockaddr *) &sendAddr, &len);
        printf("Received: %d\n", n1);
        printf("Received: %d\n", n2);
        printf("SourceIP: %s, Port=%d\n", inet_ntoa(sendAddr.sin_addr), ntohs(sendAddr.sin_port));

        printf("Structure  ID=%d, Name: %s\n", recvUser.usr_id, recvUser.usr_nickname);
        printf("Class  %f\n", c2.calculate());                      // Check whether data has been transferred successfully

        sendto(recevSock, reply, sizeof(reply), 0, (struct sockaddr *) &sendAddr, sizeof(sendAddr));
    }
    close(recevSock);
    return 0;
}
```
## TCP Client
```c++
```
## TCP Server
```c++
```
## Test
**1.** You can copy and modify the snippets above according to your practical engineering application, and remember to run them in the Linux environment. Here I've tested the "UDP Socket" with IDE "Clion" in Ubuntu 18.04:<br>
 - *Client*
<div align="center"> <img alt="isolevel" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/socket2.png?raw=true" width="600px"> </div><br>

 - *Server*
<div align="center"> <img alt="isolevel" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/socket1.png?raw=true" width="600px"> </div><br>

<br>

# Windows
<hr>

Since I haven't encountered the scenario of socket communication on Windows in all my projects before, I cannot make a record here for the time being 😉

<div align="right"><a class="top-link hide" href="#top"><font size="6"><b>↑</b></font></a></div>
