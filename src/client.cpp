#include "ClientRPC.hh"
#include <iostream>

#include <curl/curl.h>
#include <stdio.h>
#include <string>
#include "../proto/rpc_ping.pb.h"
#include <pbrpc/pbrpc.pb.h>

using ::pbrpc::api::PingRequest;
using ::pbrpc::api::PingResponse;
using ::pbrpc::api::PingService;
using ::pbrpc::Request;
using ::pbrpc::Response;
using ::pbrpc::ClientRPC;
using namespace std;

class PingClient{
public:
	string ping (const string& msg){
		cout<<"inside ping"<<endl;
		PingRequest request;
		request.set_message(msg);

		PingResponse response;
		//clientcontext
		//Status status=PingService.Ping(request, &response);
		// if (status.ok()) {
	 //      return response.result();
	 //    } else {
	 //      cout << status.error_code() << ": " << status.error_message()
	 //                << std::endl;
	 //      return "RPC failed";
	 //    }
	}
};

// int main(void) {
//   GOOGLE_PROTOBUF_VERIFY_VERSION;
//   cout << "executing client" << endl;
//   // PingRequest request;
//   // PingResponse response;
//   // request.set_message("hello whats up");

//   Request req;//Creating a pbrpc request that needs to be Serialized and transported to Server
//   req.set_pbrpc("1.1");
//   req.set_service("PingService");
//   req.set_method("ping");
//   req.set_id(123);

//   std::string data;
//   req.SerializeToString(&data);//Serializing

//   std::cout<<"data="<<data<<std::endl;

//   CURL *curl;
//   CURLcode res;

//   curl_global_init(CURL_GLOBAL_ALL);

//   curl = curl_easy_init();
//   if (curl) {

//     struct curl_slist *header = NULL;
//     header = curl_slist_append(header, "Content-Type: application/x-protobuf");
//     curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
//     curl_easy_setopt(curl, CURLOPT_URL, "localhost:9999/rpc");
//     curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
//     res = curl_easy_perform(curl);

//     if (res != CURLE_OK)
//       fprintf(stderr, "curl_easy_perform() failed: %s\n",
//               curl_easy_strerror(res));

//     curl_easy_cleanup(curl);
//   }
//   curl_global_cleanup();
//   return 0;
// }

int main(void) {
ClientRPC client;
Request req;
  req.set_pbrpc("1.1");
  req.set_service("PingService");
  req.set_method("ping");
  req.set_id(123);
  std::string data;
  req.SerializeToString(&data);

  client.sendPayload(data);
  client.runClient();
}
