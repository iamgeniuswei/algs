//
// Created by developer on 19-10-25.
//

#include "RPCServerChannel.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
RPCServerChannel::RPCServerChannel(const string &ip, unsigned short port)
:RPCChannel(ip, port)
{}

void RPCServerChannel::start()
{

}

bool RPCServerChannel::bind()
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
    return false;
}
