//
// Created by developer on 19-11-14.
//

#ifndef ALGS_RPCCLIENTCHANNEL_H
#define ALGS_RPCCLIENTCHANNEL_H

#include "RPCChannel.h"

class RPCClientChannel : public RPCChannel
{
public:
    RPCClientChannel(const string &ip, unsigned short port);

public:
    void callMethod();
};


#endif //ALGS_RPCCLIENTCHANNEL_H
