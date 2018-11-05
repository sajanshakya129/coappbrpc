/* RpcMethod.h -- Handles RPC service and registry of services
 *
 * Copyright (C) 2018 Sajan SHAKYA <sajanshakya129@gmail.com>
 *
 * This file is part of the CoAPPBRPC library libcoap. Please see
 * README for terms of use.
 */

/**
 * @file RpcMethod.h
 * @brief Handles RPC service and registry of services
 **/
#ifndef __RpcMethod_H_INCLUDED_
#define __RpcMethod_H_INCLUDED_

#include <google/protobuf/descriptor.h>
#include <google/protobuf/service.h>

namespace coappbrpc {

using ::google::protobuf::Message;
using ::google::protobuf::MethodDescriptor;
using ::google::protobuf::Service;

/*This class describes a RPC Method object.
 */
class RpcMethod {
public:
  const MethodDescriptor *descriptor; /**< method descriptor */
  const Message *request;             /**< parameters */
  const Message *response;            /**< result */

  RpcMethod(const MethodDescriptor *descriptor, const Message *request,
            const Message *response)
      : descriptor(descriptor), request(request), response(response) {}

  RpcMethod(void) : descriptor(NULL), request(NULL), response(NULL) {}
};

} // namespace coappbrpc

#endif //__RpcMethod_H_INCLUDED_
