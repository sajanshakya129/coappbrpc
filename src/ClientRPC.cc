#include "ClientRPC.h"

namespace coappbrpc {
ClientRPC *ClientRPC::m_instance = 0; // initializing instance

ClientRPC *ClientRPC::getInstance() { // getting new clientRPC instance
  if (m_instance == 0) {
    m_instance = new ClientRPC();
  }

  return m_instance;
}

ClientRPC::ClientRPC() {}

ClientRPC::~ClientRPC() {}

void ClientRPC::runClient() {
  //creates structure to run coap
  CoapClient coapclient;
  ClientParams params;
  params.addr = this->m_address;
  params.port = this->m_port;
  params.methodType = COAP_REQUEST_POST;
  params.interface = COAP_INTERFACE_NAME;
  params.payload = this->m_payload;
  coapclient.executeClient(params);
}

void ClientRPC::setResponse(string resp) { this->m_response = resp; }

string ClientRPC::getResponse() { return this->m_response; }

void ClientRPC::setServerAddr(string ipAddr,string port) {
    this->m_address = ipAddr;
    this->m_port = port;
}

Response ClientRPC::execFunc(string vers, string serviceName, string method,
                             string msg) {
  //sets request that is to be sent
  ClientRPC *client = ClientRPC::getInstance();
  Request req;
  req.set_version(vers);
  req.set_service(serviceName);
  req.set_method(method);
  req.set_params(msg);
  req.set_id((rand() % 9999 + 1));
  req.SerializeToString(&this->m_payload);
  client->runClient();

  Response resp;
  resp.ParseFromString(client->getResponse());
  return resp;
}



} // namespace coappbrpc
