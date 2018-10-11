#ifndef __CoapClient_HH_INCLUDED_
#define __CoapClient_HH_INCLUDED_
#include <coap/coap.h>
#include <iostream>
#include <string>

#include "CoapCommon.hh"

using namespace std;
typedef struct {
  string addr;
  string port;
  int methodType;
  string interface;
  string payload;
} ClientParams;

namespace pbrpc {
class CoapClient {
public:
  string payload;
  static void client_handler(struct coap_context_t *, coap_session_t *,
                             coap_pdu_t *, coap_pdu_t *, const coap_tid_t);
  static int executeClient(ClientParams);
};
} // namespace pbrpc
#endif