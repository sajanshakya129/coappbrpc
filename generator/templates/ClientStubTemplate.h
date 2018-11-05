/*[[[cog
import cog,json
cog.outl("// This code is automatically generated.")

cog.outl("#ifndef __ClientStub_H_INCLUDED_")
cog.outl("#define __ClientStub_H_INCLUDED_")
with open('protofile.json') as fp:
	jsonData=json.load(fp)
cog.outl("#include \"%s\""% jsonData["headerfile"])
cog.outl("#include <coappbrpc/RpcClient.h>")
cog.outl("using ::coappbrpc::RpcClient;")
cog.outl("using ::coappbrpc::Request;")
cog.outl("using ::coappbrpc::Response;")

for item in jsonData["data"]:
	if item["type"] == "Message":
		cog.outl("using ::coappbrpc::api::%s;"%item["name"])
cog.outl("using namespace std;")
cog.outl("class ClientStub {")
cog.outl("public:")

for item in jsonData["data"]:
	if item["type"]=="Service":
		for method in item["methods"]:
			cog.outl("void {0}({1},{2} *);".format(method["method_name"], method["input"], method["output"]))
cog.outl("private:")
cog.outl("RpcClient *client = RpcClient::getInstance();")
cog.outl("template<typename R> string serializeMsg(R);")
cog.outl("};")
cog.outl("#endif")

]]]*/
//[[[end]]]


