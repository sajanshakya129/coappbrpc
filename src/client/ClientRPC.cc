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

void ClientRPC::sendPayload(string data) { payload = this->payload = data; }

void ClientRPC::runClient() {
  CoapClient coapclient;
  ClientParams params;
  params.addr = this->address;
  params.port = this->port;
  params.methodType = COAP_REQUEST_POST;
  params.interface = COAP_INTERFACE_NAME;
  params.payload = this->payload;
  coapclient.executeClient(params);
}

void ClientRPC::setResponse(string resp) { this->response = resp; }

string ClientRPC::getResponse() { return this->response; }

void ClientRPC::SetServerAddr(string ipAddr) {
  string delimiter = ":";
  if (ipAddr.find(delimiter) != std::string::npos) {
    this->address = ipAddr.substr(0, ipAddr.find(delimiter));
    this->port = ipAddr.substr((ipAddr.find(delimiter) + 1), ipAddr.find('\0'));
  } else {
    cout << "ERROR in channel: Please enter IP address in formart "
            "ip_address:port_no"
         << endl;
    exit(0);
  }
}

Response ClientRPC::execFunc(string vers, string serviceName, string method,
                             string msg) {
  ClientRPC *client = ClientRPC::getInstance();
  Request req;
  req.set_pbrpc(vers);
  req.set_service(serviceName);
  req.set_method(method);
  req.set_params(msg);
  req.set_id((rand() % 9999 + 1));
  std::string payload;
  req.SerializeToString(&payload);
  client->sendPayload(payload);
  client->runClient();

  Response resp;
  resp.ParseFromString(client->getResponse());
  return resp;
}

} // namespace pbrpc
