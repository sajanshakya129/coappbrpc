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

void ClientRPC::setTransportPayload(string reqPayload) { m_payload = this->m_payload = reqPayload; }

void ClientRPC::runClient() {
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

void ClientRPC::setServerAddr(string ipAddr) {
  //TODO: handle ipv6
  string delimiter = ":";
  if (ipAddr.find(delimiter) != std::string::npos) {
    this->m_address = ipAddr.substr(0, ipAddr.find(delimiter));
    this->m_port = ipAddr.substr((ipAddr.find(delimiter) + 1), ipAddr.find('\0'));
  } else {
    std::cerr << "ERROR in channel: Please enter IP address in formart "
            "ip_address:port_no"
         << std::endl;
    exit(0);
  }
}

Response ClientRPC::execFunc(string vers, string serviceName, string method,
                             string msg) {
  ClientRPC *client = ClientRPC::getInstance();
  Request req;
  req.set_version(vers);
  req.set_service(serviceName);
  req.set_method(method);
  req.set_params(msg);
  req.set_id((rand() % 9999 + 1));
  std::string reqPayload;
  req.SerializeToString(&reqPayload);
  client->setTransportPayload(reqPayload);
  client->runClient();

  Response resp;
  resp.ParseFromString(client->getResponse());
  return resp;
}



} // namespace coappbrpc
