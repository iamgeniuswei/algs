//
// Created by developer on 19-10-17.
//
#include "rpc/RPCServerChannel.h"
#include <iostream>
using namespace std;
int main()
{
    cout << "RPC Server..." << endl;
    RPCServerChannel *chl = new RPCServerChannel("192.168.10.198", 12345);
    chl->start();
}