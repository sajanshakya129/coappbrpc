#include <iostream>

#include "ClientRPC.hh"
#include "../server/server_cfg.h"

using namespace std;

namespace pbrpc {
ClientRPC *ClientRPC::instance = 0; // initializing instance

ClientRPC *ClientRPC::getInstance() { // getting new clientRPC instance
  if (instance == 0) {
    instance = new ClientRPC();
  }

  return instance;
}

ClientRPC::ClientRPC() {
  cout<<"initializing"<<endl;
}

ClientRPC::~ClientRPC() {
  cout<<"destructing"<<endl;
}

void ClientRPC::sendPayload(string data) {
  payload = this->payload = data;
}

void ClientRPC::runClient() {
  cout<<"from runclient"<<endl;
  cout<<this->address<<endl;
  cout<<this->port<<endl;
  CoapClient coapclient;
  ClientParams params;
  params.addr = this->address;
  params.port = this->port;
  params.methodType = COAP_REQUEST_POST;
  params.interface = "rpc";
  params.payload = this->payload;
  coapclient.executeClient(params);
}

void ClientRPC::receiveResponse(string resp) { this->response = resp; }

string ClientRPC::getResponse() { return this->response; }

void ClientRPC::createChannel(string ipAddr){
    string delimiter = ":";
    if(ipAddr.find(delimiter)!= std::string::npos){
      this->address=ipAddr.substr(0, ipAddr.find(delimiter));
      this->port= ipAddr.substr((ipAddr.find(delimiter)+1),ipAddr.find('\0'));
    }else{
      cout<<"ERROR in channel: Please enter ipaddress in formart ip_address:port_no"<<endl;
      exit(0);
    }
}

} // namespace pbrpc


