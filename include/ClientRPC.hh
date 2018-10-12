#ifndef __ClientRPC_HH_INCLUDED_
#define __ClientRPC_HH_INCLUDED_

#include "CoapClient.hh"
#include <iostream>
#include "pbrpc.pb.h"
#include <string>
using namespace std;

#define COAP_INTERFACE_NAME "rpc"

namespace pbrpc {
class ClientRPC {
private:
  static ClientRPC *instance;
  string address;
  string port;
  string payload;
  string response;
  ClientRPC();

public:
  static ClientRPC *getInstance();
  virtual ~ClientRPC();
  void sendPayload(string);
  void runClient();
  void setResponse(string);
  string getResponse();
  void SetServerAddr(string);
  Response execFunc(string, string, string, string);
};
} // namespace pbrpc

#endif //__ClientRPC_HH_INCLUDED_
