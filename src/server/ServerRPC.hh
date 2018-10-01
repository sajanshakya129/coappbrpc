#ifndef __ServerRPC_HH_INCLUDED_
#define __ServerRPC_HH_INCLUDED_

#include <coap/coap.h>
#include <google/protobuf/service.h>
#include <pbrpc/pbrpc.pb.h>

#include "../common/CoapCommon.hh"
#include <string>

using ::google::protobuf::Service;
using ::google::protobuf::ServiceDescriptor;

using namespace std;
namespace pbrpc {
class ServerRPC {
public:
    ServerRPC();
    virtual ~ServerRPC();
    void     init(void);
    int      start(string);
    bool     stop(int);
    void registerService(Service *service);

    coap_context_t *ctx = nullptr;

    int  port;
    string  serverAddr;
    bool running = false;
};

}

#endif //__ServerRPC_HH_INCLUDED_
