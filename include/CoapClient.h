#ifndef __CoapClient_H_INCLUDED_
#define __CoapClient_H_INCLUDED_
#include <coap2/coap.h>
#include <string>

#include "CoapCommon.h"

using namespace std;
typedef struct {
  string addr;
  string port;
  int methodType;
  string interface;
  string payload;
} ClientParams;

namespace coappbrpc {
/*! \class CoapClient
* \brief
*This class contains two methods to clientHandler and executeClient
*client Handler is a callback function which returns response back to RPC client
*excuteClient handles coap client request. It creates a coap context, uses UDP as transport controller,
*registers, adds options  and creates PDU and sends to server.
*/
class CoapClient {
public:
  string payload;
  static void clientHandler(struct coap_context_t *, coap_session_t *,
                             coap_pdu_t *, coap_pdu_t *, const coap_tid_t);
  static int executeClient(ClientParams);
};
} // namespace coappbrpc
#endif