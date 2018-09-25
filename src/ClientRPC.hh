#ifndef __ClientRPC_HH_INCLUDED_
#define __ClientRPC_HH_INCLUDED_

#include <pbrpc/pbrpc.pb.h>
#include "coap_client.hh"
#include <string>
using namespace std;

namespace pbrpc {
class ClientRPC {
public:
  string payload;
  string response;
  ClientRPC();
  virtual ~ClientRPC();
  void sendPayload(string);
  void runClient();
  void receiveResponse(unsigned char *, size_t );
  string getResponse();

};

} // namespace pbrpc

#endif //__ClientRPC_HH_INCLUDED_
