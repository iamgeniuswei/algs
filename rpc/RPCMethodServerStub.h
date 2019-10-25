//
// Created by developer on 19-10-25.
//

#ifndef ALGS_RPCMETHODSERVERSTUB_H
#define ALGS_RPCMETHODSERVERSTUB_H

#include "RPCMethodServer.h"
class RPCChannel;
class RPCMethodServerStub : RPCMethodServer
{
public:
    RPCMethodServerStub(const RPCChannel *channel);

private:
    const RPCChannel *channel_ = nullptr;
};


#endif //ALGS_RPCMETHODSERVERSTUB_H
