#include<iostream>
#include "ClientStub.hh"

void ClientStub::Ping(PingRequest request, PingResponse *response){
	Response resp;
	std::string msg("Testing User Msg");
	request.SerializeToString(&msg);
	resp=client->execFunc("1.1","PingService","Ping",Serialize(request));
	//cout<<"inside client stub: ping"<<endl;
	response->ParseFromString(resp.result());
}

string ClientStub::Serialize(PingRequest request){
	std::string msg;
	request.set_message(request.message());
	request.SerializeToString(&msg);
	return msg;
}
