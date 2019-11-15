//
// Created by developer on 19-10-25.
//

#include "RPCServerChannel.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <sys/socket.h>
using namespace std;
RPCServerChannel::RPCServerChannel(const string &ip, unsigned short port)
:RPCChannel(ip, port)
{}

void RPCServerChannel::start()
{
    if(!bindToAddr())
        return;
    int ret = listen(socket_, 3);
    assert(ret != -1);
    cout << "RPC Server listening...." << endl;
    while (true)
    {
        sockaddr_in client;
        socklen_t client_addr_len = sizeof (client);
        int connfd = accept(socket_, (sockaddr*)&client, &client_addr_len);
        char recvBuf[1024];
        memset(recvBuf, 0, 1024);
        int len = recv(connfd, recvBuf, 1024, 0);
        cout << "Server has received method request: " << recvBuf << endl;
        char sendBuf[1024];
        memset(sendBuf, 0, 1024);
        strcpy(sendBuf, "result ok!");
        send(connfd, sendBuf, strlen(sendBuf), 0);
    }
}

bool RPCServerChannel::bindToAddr()
{
    if(socket_ < 0)
        return false;
    sockaddr_in sin;
    bzero(&sin, sizeof (sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port_);
    if(ip_.empty())
        sin.sin_addr.s_addr = 0;
    else
    {
        struct in_addr s;
        inet_pton(AF_INET, ip_.data(), (void*)&s);
        sin.sin_addr.s_addr = s.s_addr;
    }
    int ret = bind(socket_, (sockaddr*)&sin, sizeof (sin));
    assert(ret != -1);
    return true;
}
