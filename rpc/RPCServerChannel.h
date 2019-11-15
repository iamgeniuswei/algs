//
// Created by developer on 19-10-25.
//

#ifndef ALGS_RPCSERVERCHANNEL_H
#define ALGS_RPCSERVERCHANNEL_H

#include "RPCChannel.h"
#include <string>
using namespace std;
class RPCServerChannel : RPCChannel
{
public:
    RPCServerChannel(const string &ip, unsigned short port);
    void start();
private:
    bool bindToAddr();

};


#endif //ALGS_RPCSERVERCHANNEL_H
