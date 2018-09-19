#include <iostream>

#include "ClientRPC.hh"

using namespace std;

namespace pbrpc {
ClientRPC::ClientRPC() {
  std::cout << "from send client RPC Constructor" << endl;
}

ClientRPC::~ClientRPC() {
  std::cout << "from send client RPC Destructor" << endl;
}

ClientRPC::receivePayload(string data){
  payload=this->payload=data;
  createCoapParams(payload);
}

} // namespace pbrpc
