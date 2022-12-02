#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <iostream>

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