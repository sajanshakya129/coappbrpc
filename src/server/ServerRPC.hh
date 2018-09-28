#ifndef __ServerRPC_HH_INCLUDED_
#define __ServerRPC_HH_INCLUDED_

#include <coap/coap.h>
#include "../common/CoapCommon.hh"
#include <string>
using namespace std;
namespace pbrpc {
class ServerRPC {
public:
    ServerRPC();
    virtual ~ServerRPC();
    void     init(void);
    int      start(void);
    bool     stop(int);

    coap_context_t *ctx = nullptr;

    int  port    = 5683;
    string  serverAddr = "localhost";
    bool running = false;
};

}

#endif //__ServerRPC_HH_INCLUDED_
