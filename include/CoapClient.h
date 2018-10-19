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
class CoapClient {
public:
  string payload;
  static void clientHandler(struct coap_context_t *, coap_session_t *,
                             coap_pdu_t *, coap_pdu_t *, const coap_tid_t);
  static int executeClient(ClientParams);
};
} // namespace coappbrpc
#endif