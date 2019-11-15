//
// Created by developer on 19-10-25.
//

#include "RPCChannel.h"
#include <sys/socket.h>
#include <iostream>
using namespace std;
RPCChannel::RPCChannel(const string &ip, unsigned short port) : ip_(ip), port_(port)
{
    init();
}

void RPCChannel::init()
{
    socket_ = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_ < 0)
    {
        cout << "socket error" << endl;
        return;
    }
}
