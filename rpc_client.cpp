//
// Created by developer on 19-11-15.
//
#include "rpc/RPCClientChannel.h"
#include "rpc/RPCMethodServerStub.h"
int main()
{
    RPCClientChannel *chl = new RPCClientChannel("192.168.10.198", 12345);
    RPCMethodServerStub *stub = new RPCMethodServerStub(chl);
    stub->Echo();
    return 0;
}