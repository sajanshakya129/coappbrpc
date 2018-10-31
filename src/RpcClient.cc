#include "RpcClient.h"

namespace coappbrpc {
RpcClient *RpcClient::m_instance = 0; // initializing instance

RpcClient *RpcClient::getInstance() { // getting new clientRPC instance
  if (m_instance == 0) {
    m_instance = new RpcClient();
  }

  return m_instance;
}

RpcClient::RpcClient() {}

RpcClient::~RpcClient() {}

void RpcClient::runClient() {
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

void RpcClient::setResponse(string resp) { this->m_response = resp; }

string RpcClient::getResponse() { return this->m_response; }

void RpcClient::setServerAddr(string ipAddr,string port) {
    this->m_address = ipAddr;
    this->m_port = port;
}

Response RpcClient::execFunc(string vers, string serviceName, string method,
                             string msg) {
  //sets request that is to be sent
  RpcClient *client = RpcClient::getInstance();
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
