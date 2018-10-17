#ifndef __ControllerRPC_HH_INCLUDED_
#define __ControllerRPC_HH_INCLUDED_

#include <google/protobuf/service.h>
#include <string>

namespace pbrpc {

using ::google::protobuf::Closure;
using ::google::protobuf::RpcController;
using ::pbrpc::Error;
using ::std::string;

class ControllerRPC : public RpcController {
public:
  ControllerRPC(void) { Reset(); }
  virtual ~ControllerRPC() {}
  void Reset() { _failed = false; }
  bool Failed() const { return _failed; }
  string ErrorText() const { return _message; }

  void SetFailed(const string &reason) {
    _failed = true;
    _message = reason;
  }

  void AppendFailed(const string &reason) { _message += reason; }

  // get the Error object
  Error ErrorObj(void) const {
    Error error;
    error.set_message(ErrorText());
    return error;
  }

  void StartCancel() {}
  bool IsCanceled() const { return false; };
  void NotifyOnCancel(Closure *callback){};

private:
  bool _failed;
  string _message;
};

} // namespace pbrpc

#endif //__ControllerRPC_HH_INCLUDED_
