#ifndef __MethodRPC_HH_INCLUDED_
#define __MethodRPC_HH_INCLUDED_

#include <google/protobuf/descriptor.h>
#include <google/protobuf/service.h>

namespace pbrpc {

using ::google::protobuf::Message;
using ::google::protobuf::MethodDescriptor;
using ::google::protobuf::Service;

/*This class describes a RPC Method object.
 */
class MethodRPC {
public:
  const MethodDescriptor *descriptor; /**< method descriptor */
  const Message *request;             /**< parameters */
  const Message *response;            /**< result */

  MethodRPC(const MethodDescriptor *descriptor, const Message *request,
            const Message *response)
      : descriptor(descriptor), request(request), response(response) {}

  MethodRPC(void) : descriptor(NULL), request(NULL), response(NULL) {}
};

} // namespace pbrpc

#endif //__MethodRPC_HH_INCLUDED_
