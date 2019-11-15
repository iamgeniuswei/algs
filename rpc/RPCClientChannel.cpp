//
// Created by developer on 19-11-14.
//

#include "RPCClientChannel.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <assert.h>
#include <iostream>
using namespace std;
void RPCClientChannel::callMethod()
{
    char sendBuf[1024];
    memset(sendBuf, 0, 1024);
    strcpy(sendBuf, "method request from client");
    int len = send(socket_, sendBuf, strlen(sendBuf), 0);
    char recvBuf[1024];
    memset(recvBuf, 0, 1024);
    len = recv(socket_, recvBuf, 1024, 0);
    cout << "client has received response: " << recvBuf << endl;
}

RPCClientChannel::RPCClientChannel(const string &ip, unsigned short port) : RPCChannel(ip, port)
{
    sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    struct in_addr s;
    inet_pton(AF_INET, ip.data(), (void*)&s);
    serverAddr.sin_addr.s_addr = s.s_addr;
    serverAddr.sin_port = htons(port);
    int err = connect(socket_, (sockaddr*)&serverAddr, sizeof(sockaddr));
    assert(err != -1);
}
