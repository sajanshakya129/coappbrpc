#ifndef __ControllerRPC_H_INCLUDED_
#define __ControllerRPC_H_INCLUDED_
#include "MsgSchema.pb.h"
#include <google/protobuf/service.h>
#include <string>

namespace coappbrpc {

using ::google::protobuf::Closure;
using ::google::protobuf::RpcController;
using ::coappbrpc::Error;
using ::std::string;

class ControllerRPC : public RpcController {
public:
  ControllerRPC(void) { Reset(); }
  virtual ~ControllerRPC() {}
  void Reset() { m_failed = false; }
  bool Failed() const { return m_failed; }
  string ErrorText() const { return m_message; }

  void SetFailed(const string &reason) {
    m_failed = true;
    m_message = reason;
  }

  void appendFailed(const string &reason) { m_message += reason; }

  // get the Error object
  Error errorObj(void) const {
    Error error;
    error.set_message(ErrorText());
    return error;
  }

  void StartCancel() {}
  bool IsCanceled() const { return false; };
  void NotifyOnCancel(Closure *callback){};

private:
  bool m_failed;
  string m_message;
};

} // namespace coappbrpc

#endif //__ControllerRPC_H_INCLUDED_
