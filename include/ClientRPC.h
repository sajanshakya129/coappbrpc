#ifndef __ClientRPC_H_INCLUDED_
#define __ClientRPC_H_INCLUDED_

#include "CoapClient.h"
#include "MsgSchema.pb.h"
#include <iostream>
#include <string>
using namespace std;

namespace coappbrpc {
class ClientRPC {
private:
  static ClientRPC *m_instance;
  string m_address;
  string m_port;
  string m_payload;
  string m_response;
  ClientRPC();

public:
  static ClientRPC *getInstance();
  virtual ~ClientRPC();
  void setTransportPayload(string);
  void runClient();
  void setResponse(string);
  string getResponse();
  void setServerAddr(string,string);
  Response execFunc(string, string, string, string);
};
} // namespace coappbrpc

#endif //__ClientRPC_H_INCLUDED_
