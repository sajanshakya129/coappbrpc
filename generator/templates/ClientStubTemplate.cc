/* ClientStubTemplate.h -- Template used to create client
 *
 * Copyright (C) 2018 Sajan SHAKYA <sajanshakya129@gmail.com>
 *
 * This file is part of the CoAPPBRPC library libcoap. Please see
 * README for terms of use.
 */
/**
 * @file ClientStubTemplate.h
 * @brief Template used to create client stub automatically
 * when command "coappbrpc <filename.proto>" is executed in terminal
 */

/*[[[cog
import cog,json
cog.outl("// This code is automatically generated.")

cog.outl("#include \"ClientStub.h\"")
with open('protofile.json') as fp:
        jsonData=json.load(fp)

for item in jsonData["data"]:
        if item["type"]=="Service":
                for method in item["methods"]:
                        cog.outl("void ClientStub::{0}({1} request,{2}
*response)".format(method["method_name"], method["input"], method["output"]))
                        cog.outl("{ Response resp;")
                        cog.outl("resp=client->execFunc(\"1.1\",\"{0}\",\"{1}\",serializeMsg(request));".format(item["name"],method["method_name"]))
                        cog.outl("response->ParseFromString(resp.result());")
                        cog.outl("}")

]]]*/
//[[[end]]]

template <typename R> string ClientStub::serializeMsg(R request) {
  std::string msg;
  request.SerializeToString(&msg);
  return msg;
}