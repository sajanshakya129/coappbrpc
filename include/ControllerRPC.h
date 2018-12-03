/* ControllerRPC.h -- Controls RPC, resets, sets failed if RPC failes, handles
 * error messages
 *
 * Copyright (C) 2018 Sajan SHAKYA <sajanshakya129@gmail.com>
 *
 * This file is part of the CoAPPBRPC library. Please see
 * README for terms of use.
 */

/**
 * @file ControllerRPC.h
 * @brief Controls RPC, resets, sets failed if RPC failes, handles error
 *messages
 **/

#ifndef __ControllerRPC_H_INCLUDED_
#define __ControllerRPC_H_INCLUDED_

#include "MsgSchema.pb.h"
#include <google/protobuf/service.h>
#include <string>

namespace coappbrpc {

using ::coappbrpc::Error;
using ::google::protobuf::Closure;
using ::google::protobuf::RpcController;
using ::std::string;
/*! \class ControllerRPC
 * \brief
 *This class inherits properties from google protobuf RpcController, it has
 *methods for resetting, setting failed, get error object if there is any error
 *in the RPC.
 */
class ControllerRPC : public RpcController {
public:
  ControllerRPC(void) { Reset(); }
  virtual ~ControllerRPC() {}
  /*! \fn  void Reset()
    \brief Resets m_failed flag to false
  */
  void Reset() { m_failed = false; }

  /*! \fn  bool Failed()
    \brief getter function that returns m_failed flag
  */
  bool Failed() const { return m_failed; }

  /*! \fn  string ErrorText()
    \brief Getter function that returns message stored in m_message
  */
  string ErrorText() const { return m_message; }

  /*! \fn  void SetFailed(const string &reason)
    \brief Setter function which sets m_failed to true when RPC fails and set
    m_message to the reason of failure sent as parameter \param reason string
    value that has explanation for failure
  */
  void SetFailed(const string &reason) {
    m_failed = true;
    m_message = reason;
  }

  /*! \fn  void appendFailed(const string &reason)
   \brief Function that appends multiple reasons for failure
   \param reason string value that has explanation for failure
 */
  void appendFailed(const string &reason) { m_message += reason; }

  /*! \fn Error errorObj(void) const
    \brief gets the Error object
  */
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
  bool m_failed;    /*!< Boolean variable to set on and off if RPC fails */
  string m_message; /*!<String value to store error message if occurs  */
};

} // namespace coappbrpc

#endif //__ControllerRPC_H_INCLUDED_
