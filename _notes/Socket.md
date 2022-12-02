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
    * [Windows](#windows)

<!-- GFM-TOC -->

<br>

# Introduction
<hr>

Actually

<br>

# Linux
<hr>

## UDP Client
```c++
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>     // Socket header file on Linux
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <iostream>
using namespace std;

struct UsrData{             // Test structure
    int usr_id[8];
    char usr_nickname[8];
};

class  circle{              // Test class
public:
    int  m_r;
    double calculate() {
        return 2*3.14*m_r;
    }
};

int main(){
    // Create a Socket
    unsigned int sendSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);  // Address type, socket type, protocol type

    // Bind your own address
    struct sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr)); 
    /*
    struct sockaddr_in {
       sa_family_t    sin_family;       // address family: AF_INET
       in_port_t      sin_port;         // port in network byte order
       struct in_addr sin_addr;         // internet address
    };
    */
    sockAddr.sin_family = AF_INET;                 
    sockAddr.sin_port = htons(1235);    // "htonl()" converts the unsigned integer from host byte order to network byte order
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    circle  c1;
    c1.m_r = 10;
    UsrData sendUser;
    sendUser.usr_id[0] = 1251;
    strcpy(sendUser.usr_nickname, "sadad");
    
    int sendNum  = sendto(sendSock, (class  circle *)&c1, sizeof(c1), 0, (struct sockaddr *)&sockAddr, sizeof(sockAddr));
    printf("Send: %d\n", sendNum);

    unsigned char buff[32] = {0};
    recvfrom(sendSock, buff, sizeof(buff), 0, (struct sockaddr *)&sockAddr, sizeof(sockAddr));
    printf("Reply: %s\n", buff);
        
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
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <iostream>
using namespace std;

struct UsrData{
    int usr_id[8];
    char usr_nickname[8];
};

class  circle{
public:
    int  m_r;
    double calculate(){
        return 2*3.14*m_r;
    }
};

int main(){
    unsigned int recSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    struct sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));
    sockAddr.sin_family = AF_INET;                                  // Use IPv4 address
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1 ");             // Specific IP address
    sockAddr.sin_port = htons(1235);                                // Port
    bind(recSock, (struct sockaddr *)&sockAddr, sizeof(sockAddr));  // Notice this step is uneeded in "client"

    circle  c2;
    struct UsrData recvUser;
    unsigned char buff[32] = {"Successfully received!"};
    struct sockaddr_in sendAddr;                                    // Receiver doesn't need to know the sender's address, but needs an empty struct to receive address info
    
    while(1){
        int n1 = recvfrom(recevSock, (class  circle *)&c2, sizeof(c2), 0, (struct sockaddr *)&sendAddr, sizeof(sendAddr));
        printf("Receive: %d\n", n1);

        //printf("num[16]=%d     num[16] = %s", recvUser.usr_id[0], recvUser.usr_nickname);

        printf("ip=%s  port=%d\n", inet_ntoa(sendAddr.sin_addr), ntohs(sendAddr.sin_port));
        printf("%d\n", c2.m_r);                                     // Check whether the class has been transferred successfully 
        sendto(recSock, buff, sizeof(buff), 0, (struct sockaddr *)&sendAddr, sizeof(sendAddr));
    }
    close(recevSock);
    return 0;
}
```

<br>

# Windows
<hr>

Since I haven't encountered the scenario of socket communication on Windows in all my projects before, I cannot make a record here for the time being 😉

<div align="right"><a class="top-link hide" href="#top"><font size="6"><b>↑</b></font></a></div>
