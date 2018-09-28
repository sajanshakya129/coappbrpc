#ifndef __ClientRPC_HH_INCLUDED_
#define __ClientRPC_HH_INCLUDED_

#include "CoapClient.hh"
#include <pbrpc/pbrpc.pb.h>
#include <string>
using namespace std;

namespace pbrpc {
class ClientRPC {
private:
  static ClientRPC* instance;
  string address;
  string port;
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
  void createChannel(string);
};
} // namespace pbrpc

#endif //__ClientRPC_HH_INCLUDED_
