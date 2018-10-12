/*[[[cog
import cog,json
cog.outl("// This code is automatically generated.")

cog.outl("#ifndef __ClientStub_HH_INCLUDED_")
cog.outl("#define __ClientStub_HH_INCLUDED_")
with open('protofile.json') as fp:
	jsonData=json.load(fp)
cog.outl("#include \"%s\""% jsonData["headerfile"])
cog.outl("#include \"ClientRPC.hh\"")
cog.outl("using ::pbrpc::ClientRPC;")
cog.outl("using ::pbrpc::Request;")
cog.outl("using ::pbrpc::Response;")

for item in jsonData["data"]:
	if item["type"] == "Message":
		cog.outl("using ::pbrpc::api::%s;"%item["name"])
cog.outl("using namespace std;")
cog.outl("class ClientStub {")
cog.outl("public:")

for item in jsonData["data"]:
	if item["type"]=="Service":
		for method in item["methods"]:
			cog.outl("void {0}({1},{2} *);".format(method["method_name"], method["input"], method["output"]))
cog.outl("private:")
cog.outl("ClientRPC *client = ClientRPC::getInstance();")
for item in jsonData["data"]:
	if item["type"]=="Message":
		cog.outl("string Serialize(%s);"%item["name"])
		
cog.outl("};")
cog.outl("#endif")

]]]*/
//[[[end]]]


