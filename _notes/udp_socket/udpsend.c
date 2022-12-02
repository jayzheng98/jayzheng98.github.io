#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>     // Socket header file on Linux
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <iostream>

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