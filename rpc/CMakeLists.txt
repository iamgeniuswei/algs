aux_source_directory(. DIR_RPC_SRCS)
add_library(rpc STATIC ${DIR_RPC_SRCS} RPCMethodServerImpl.cpp RPCMethodServerImpl.h RPCMethodServerStub.cpp RPCMethodServerStub.h RPCChannel.cpp RPCChannel.h RPCServerChannel.cpp RPCServerChannel.h RPCClientChannel.cpp RPCClientChannel.h)
set_target_properties(rpc PROPERTIES LINKER_LANGUAGE CXX)
