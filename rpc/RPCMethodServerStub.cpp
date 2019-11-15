//
// Created by developer on 19-10-25.
//

#include "RPCMethodServerStub.h"
#include "RPCChannel.h"
RPCMethodServerStub::RPCMethodServerStub(RPCClientChannel *channel)
:channel_(channel)
{}

void RPCMethodServerStub::Echo()
{
    if(channel_)
    {
        channel_->callMethod();
    }
}
