//
// Created by developer on 19-10-25.
//

#ifndef ALGS_RPCMETHODSERVERSTUB_H
#define ALGS_RPCMETHODSERVERSTUB_H

#include "RPCMethodServer.h"
#include "RPCClientChannel.h"
class RPCMethodServerStub : public RPCMethodServer
{
public:
    RPCMethodServerStub(RPCClientChannel *channel);

public:
    void Echo() override;

private:
    RPCClientChannel *channel_ = nullptr;
};


#endif //ALGS_RPCMETHODSERVERSTUB_H
