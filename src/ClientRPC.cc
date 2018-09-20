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

void ClientRPC::sendPayload(string data){
  cout<<"from clientRPC sendPayload"<<endl;
  payload=this->payload=data;
}

void ClientRPC::runClient(){
	cout<<"from clientRPC runclient"<<endl;
	CoapClient coapclient;
	ClientParams params;
	  params.addr="localhost";
	  params.port="5683";
	  params.methodType=COAP_REQUEST_POST;
	  params.interface="rpc";
	  params.payload=this->payload;
	  coapclient.runClient(params);
};


} // namespace pbrpc
