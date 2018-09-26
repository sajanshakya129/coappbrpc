#ifndef __ClientRPC_HH_INCLUDED_
#define __ClientRPC_HH_INCLUDED_

#include "coap_client.hh"
#include <pbrpc/pbrpc.pb.h>
#include <string>
using namespace std;

namespace pbrpc {
class ClientRPC {
private:
  static ClientRPC* instance;
  string payload;
  string response;
  ClientRPC();
public:
  static ClientRPC* getInstance();
  virtual ~ClientRPC();
  void sendPayload(string);
  void runClient();
  void receiveResponse(string);
  string getResponse();
};
} // namespace pbrpc

#endif //__ClientRPC_HH_INCLUDED_
