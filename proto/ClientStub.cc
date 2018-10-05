// This code is automatically generated.
#include "ClientStub.hh"
void ClientStub::Ping(PingRequest request,PingResponse response*)
{ Response resp;
resp=client->execFunc("1.1","PingService","Ping",Serialize(request));
response->ParseFromString(resp.result());
}
void ClientStub::Add(PingRequest request,PingResponse response*)
{ Response resp;
resp=client->execFunc("1.1","PingService","Add",Serialize(request));
response->ParseFromString(resp.result());
}
string ClientStub:Serialize(PingRequest request){
std::string msg;
request.SerializeToString(&msg);
return msg;
}
string ClientStub:Serialize(PingResponse request){
std::string msg;
request.SerializeToString(&msg);
return msg;
}



void ClientStub::Ping(PingRequest request, PingResponse *response){
	Response resp;
	resp=client->execFunc("1.1","PingService","Ping",Serialize(request));
	response->ParseFromString(resp.result());
}

string ClientStub::Serialize(PingRequest request){
	std::string msg;
	request.SerializeToString(&msg);
	return msg;
}

