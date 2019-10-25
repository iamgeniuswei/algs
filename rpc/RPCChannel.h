//
// Created by developer on 19-10-25.
//

#ifndef ALGS_RPCCHANNEL_H
#define ALGS_RPCCHANNEL_H

#include <string>
using namespace std;

class RPCChannel
{
public:
    RPCChannel(const string &ip, unsigned short port);

protected:
    void init();
protected:
    string ip_;
    unsigned short port_ = 0;
    int socket_ = 0;
};


#endif //ALGS_RPCCHANNEL_H
