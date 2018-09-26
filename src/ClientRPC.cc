#include <iostream>

#include "ClientRPC.hh"

using namespace std;

namespace pbrpc {
ClientRPC *ClientRPC::instance = 0; // initializing instance

ClientRPC *ClientRPC::getInstance() { // getting new clientRPC instance
  if (instance == 0) {
    instance = new ClientRPC();
  }

  return instance;
}

ClientRPC::ClientRPC() {}

ClientRPC::~ClientRPC() {}

void ClientRPC::sendPayload(string data) {
  payload = this->payload = data;
}

void ClientRPC::runClient() {
  CoapClient coapclient;
  ClientParams params;
  params.addr = "localhost";
  params.port = "5683";
  params.methodType = COAP_REQUEST_POST;
  params.interface = "rpc";
  params.payload = this->payload;
  coapclient.executeClient(params);
}

void ClientRPC::receiveResponse(string resp) { this->response = resp; }

string ClientRPC::getResponse() { return this->response; }

} // namespace pbrpc
