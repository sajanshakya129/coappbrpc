// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: rpc_ping.proto

#ifndef PROTOBUF_INCLUDED_rpc_5fping_2eproto
#define PROTOBUF_INCLUDED_rpc_5fping_2eproto

#include <limits>
#include <string>

#include <google/protobuf/stubs/common.h>
#if GOOGLE_PROTOBUF_VERSION < 3006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/service.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_rpc_5fping_2eproto

// Internal implementation detail -- do not use these members.
struct TableStruct_rpc_5fping_2eproto {
  static const ::google::protobuf::internal::ParseTableField entries[]
    GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[]
    GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::ParseTable schema[2]
    GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors_rpc_5fping_2eproto();
namespace pbrpc {
namespace api {
class PingRequest;
class PingRequestDefaultTypeInternal;
extern PingRequestDefaultTypeInternal _PingRequest_default_instance_;
class PingResponse;
class PingResponseDefaultTypeInternal;
extern PingResponseDefaultTypeInternal _PingResponse_default_instance_;
}  // namespace api
}  // namespace pbrpc
namespace google {
namespace protobuf {
template<> ::pbrpc::api::PingRequest* Arena::CreateMaybeMessage<::pbrpc::api::PingRequest>(Arena*);
template<> ::pbrpc::api::PingResponse* Arena::CreateMaybeMessage<::pbrpc::api::PingResponse>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace pbrpc {
namespace api {

// ===================================================================

class PingRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:pbrpc.api.PingRequest) */ {
 public:
  PingRequest();
  virtual ~PingRequest();

  PingRequest(const PingRequest& from);

  inline PingRequest& operator=(const PingRequest& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  PingRequest(PingRequest&& from) noexcept
    : PingRequest() {
    *this = ::std::move(from);
  }

  inline PingRequest& operator=(PingRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor() {
    return default_instance().GetDescriptor();
  }
  static const PingRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const PingRequest* internal_default_instance() {
    return reinterpret_cast<const PingRequest*>(
               &_PingRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(PingRequest* other);
  friend void swap(PingRequest& a, PingRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline PingRequest* New() const final {
    return CreateMaybeMessage<PingRequest>(NULL);
  }

  PingRequest* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<PingRequest>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const PingRequest& from);
  void MergeFrom(const PingRequest& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  static const char* _InternalParse(const char* begin, const char* end, void* object, ::google::protobuf::internal::ParseContext* ctx);
  ::google::protobuf::internal::ParseFunc _ParseFunc() const final { return _InternalParse; }
  #else
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PingRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string msg = 1;
  void clear_msg();
  static const int kMsgFieldNumber = 1;
  const ::std::string& msg() const;
  void set_msg(const ::std::string& value);
  #if LANG_CXX11
  void set_msg(::std::string&& value);
  #endif
  void set_msg(const char* value);
  void set_msg(const char* value, size_t size);
  ::std::string* mutable_msg();
  ::std::string* release_msg();
  void set_allocated_msg(::std::string* msg);

  // string abc = 2;
  void clear_abc();
  static const int kAbcFieldNumber = 2;
  const ::std::string& abc() const;
  void set_abc(const ::std::string& value);
  #if LANG_CXX11
  void set_abc(::std::string&& value);
  #endif
  void set_abc(const char* value);
  void set_abc(const char* value, size_t size);
  ::std::string* mutable_abc();
  ::std::string* release_abc();
  void set_allocated_abc(::std::string* abc);

  // string def = 3;
  void clear_def();
  static const int kDefFieldNumber = 3;
  const ::std::string& def() const;
  void set_def(const ::std::string& value);
  #if LANG_CXX11
  void set_def(::std::string&& value);
  #endif
  void set_def(const char* value);
  void set_def(const char* value, size_t size);
  ::std::string* mutable_def();
  ::std::string* release_def();
  void set_allocated_def(::std::string* def);

  // @@protoc_insertion_point(class_scope:pbrpc.api.PingRequest)
 private:
  class HasBitSetters;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr msg_;
  ::google::protobuf::internal::ArenaStringPtr abc_;
  ::google::protobuf::internal::ArenaStringPtr def_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_rpc_5fping_2eproto;
};
// -------------------------------------------------------------------

class PingResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:pbrpc.api.PingResponse) */ {
 public:
  PingResponse();
  virtual ~PingResponse();

  PingResponse(const PingResponse& from);

  inline PingResponse& operator=(const PingResponse& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  PingResponse(PingResponse&& from) noexcept
    : PingResponse() {
    *this = ::std::move(from);
  }

  inline PingResponse& operator=(PingResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor() {
    return default_instance().GetDescriptor();
  }
  static const PingResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const PingResponse* internal_default_instance() {
    return reinterpret_cast<const PingResponse*>(
               &_PingResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(PingResponse* other);
  friend void swap(PingResponse& a, PingResponse& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline PingResponse* New() const final {
    return CreateMaybeMessage<PingResponse>(NULL);
  }

  PingResponse* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<PingResponse>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const PingResponse& from);
  void MergeFrom(const PingResponse& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  static const char* _InternalParse(const char* begin, const char* end, void* object, ::google::protobuf::internal::ParseContext* ctx);
  ::google::protobuf::internal::ParseFunc _ParseFunc() const final { return _InternalParse; }
  #else
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PingResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string result = 1;
  void clear_result();
  static const int kResultFieldNumber = 1;
  const ::std::string& result() const;
  void set_result(const ::std::string& value);
  #if LANG_CXX11
  void set_result(::std::string&& value);
  #endif
  void set_result(const char* value);
  void set_result(const char* value, size_t size);
  ::std::string* mutable_result();
  ::std::string* release_result();
  void set_allocated_result(::std::string* result);

  // @@protoc_insertion_point(class_scope:pbrpc.api.PingResponse)
 private:
  class HasBitSetters;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr result_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_rpc_5fping_2eproto;
};
// ===================================================================

class PingService_Stub;

class PingService : public ::google::protobuf::Service {
 protected:
  // This class should be treated as an abstract interface.
  inline PingService() {};
 public:
  virtual ~PingService();

  typedef PingService_Stub Stub;

  static const ::google::protobuf::ServiceDescriptor* descriptor();

  virtual void Ping(::google::protobuf::RpcController* controller,
                       const ::pbrpc::api::PingRequest* request,
                       ::pbrpc::api::PingResponse* response,
                       ::google::protobuf::Closure* done);
  virtual void Add(::google::protobuf::RpcController* controller,
                       const ::pbrpc::api::PingRequest* request,
                       ::pbrpc::api::PingResponse* response,
                       ::google::protobuf::Closure* done);

  // implements Service ----------------------------------------------

  const ::google::protobuf::ServiceDescriptor* GetDescriptor();
  void CallMethod(const ::google::protobuf::MethodDescriptor* method,
                  ::google::protobuf::RpcController* controller,
                  const ::google::protobuf::Message* request,
                  ::google::protobuf::Message* response,
                  ::google::protobuf::Closure* done);
  const ::google::protobuf::Message& GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const;
  const ::google::protobuf::Message& GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(PingService);
};

class PingService_Stub : public PingService {
 public:
  PingService_Stub(::google::protobuf::RpcChannel* channel);
  PingService_Stub(::google::protobuf::RpcChannel* channel,
                   ::google::protobuf::Service::ChannelOwnership ownership);
  ~PingService_Stub();

  inline ::google::protobuf::RpcChannel* channel() { return channel_; }

  // implements PingService ------------------------------------------

  void Ping(::google::protobuf::RpcController* controller,
                       const ::pbrpc::api::PingRequest* request,
                       ::pbrpc::api::PingResponse* response,
                       ::google::protobuf::Closure* done);
  void Add(::google::protobuf::RpcController* controller,
                       const ::pbrpc::api::PingRequest* request,
                       ::pbrpc::api::PingResponse* response,
                       ::google::protobuf::Closure* done);
 private:
  ::google::protobuf::RpcChannel* channel_;
  bool owns_channel_;
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(PingService_Stub);
};


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PingRequest

// string msg = 1;
inline void PingRequest::clear_msg() {
  msg_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PingRequest::msg() const {
  // @@protoc_insertion_point(field_get:pbrpc.api.PingRequest.msg)
  return msg_.GetNoArena();
}
inline void PingRequest::set_msg(const ::std::string& value) {
  
  msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:pbrpc.api.PingRequest.msg)
}
#if LANG_CXX11
inline void PingRequest::set_msg(::std::string&& value) {
  
  msg_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:pbrpc.api.PingRequest.msg)
}
#endif
inline void PingRequest::set_msg(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:pbrpc.api.PingRequest.msg)
}
inline void PingRequest::set_msg(const char* value, size_t size) {
  
  msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:pbrpc.api.PingRequest.msg)
}
inline ::std::string* PingRequest::mutable_msg() {
  
  // @@protoc_insertion_point(field_mutable:pbrpc.api.PingRequest.msg)
  return msg_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PingRequest::release_msg() {
  // @@protoc_insertion_point(field_release:pbrpc.api.PingRequest.msg)
  
  return msg_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PingRequest::set_allocated_msg(::std::string* msg) {
  if (msg != NULL) {
    
  } else {
    
  }
  msg_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), msg);
  // @@protoc_insertion_point(field_set_allocated:pbrpc.api.PingRequest.msg)
}

// string abc = 2;
inline void PingRequest::clear_abc() {
  abc_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PingRequest::abc() const {
  // @@protoc_insertion_point(field_get:pbrpc.api.PingRequest.abc)
  return abc_.GetNoArena();
}
inline void PingRequest::set_abc(const ::std::string& value) {
  
  abc_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:pbrpc.api.PingRequest.abc)
}
#if LANG_CXX11
inline void PingRequest::set_abc(::std::string&& value) {
  
  abc_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:pbrpc.api.PingRequest.abc)
}
#endif
inline void PingRequest::set_abc(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  abc_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:pbrpc.api.PingRequest.abc)
}
inline void PingRequest::set_abc(const char* value, size_t size) {
  
  abc_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:pbrpc.api.PingRequest.abc)
}
inline ::std::string* PingRequest::mutable_abc() {
  
  // @@protoc_insertion_point(field_mutable:pbrpc.api.PingRequest.abc)
  return abc_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PingRequest::release_abc() {
  // @@protoc_insertion_point(field_release:pbrpc.api.PingRequest.abc)
  
  return abc_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PingRequest::set_allocated_abc(::std::string* abc) {
  if (abc != NULL) {
    
  } else {
    
  }
  abc_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), abc);
  // @@protoc_insertion_point(field_set_allocated:pbrpc.api.PingRequest.abc)
}

// string def = 3;
inline void PingRequest::clear_def() {
  def_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PingRequest::def() const {
  // @@protoc_insertion_point(field_get:pbrpc.api.PingRequest.def)
  return def_.GetNoArena();
}
inline void PingRequest::set_def(const ::std::string& value) {
  
  def_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:pbrpc.api.PingRequest.def)
}
#if LANG_CXX11
inline void PingRequest::set_def(::std::string&& value) {
  
  def_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:pbrpc.api.PingRequest.def)
}
#endif
inline void PingRequest::set_def(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  def_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:pbrpc.api.PingRequest.def)
}
inline void PingRequest::set_def(const char* value, size_t size) {
  
  def_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:pbrpc.api.PingRequest.def)
}
inline ::std::string* PingRequest::mutable_def() {
  
  // @@protoc_insertion_point(field_mutable:pbrpc.api.PingRequest.def)
  return def_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PingRequest::release_def() {
  // @@protoc_insertion_point(field_release:pbrpc.api.PingRequest.def)
  
  return def_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PingRequest::set_allocated_def(::std::string* def) {
  if (def != NULL) {
    
  } else {
    
  }
  def_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), def);
  // @@protoc_insertion_point(field_set_allocated:pbrpc.api.PingRequest.def)
}

// -------------------------------------------------------------------

// PingResponse

// string result = 1;
inline void PingResponse::clear_result() {
  result_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PingResponse::result() const {
  // @@protoc_insertion_point(field_get:pbrpc.api.PingResponse.result)
  return result_.GetNoArena();
}
inline void PingResponse::set_result(const ::std::string& value) {
  
  result_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:pbrpc.api.PingResponse.result)
}
#if LANG_CXX11
inline void PingResponse::set_result(::std::string&& value) {
  
  result_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:pbrpc.api.PingResponse.result)
}
#endif
inline void PingResponse::set_result(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  result_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:pbrpc.api.PingResponse.result)
}
inline void PingResponse::set_result(const char* value, size_t size) {
  
  result_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:pbrpc.api.PingResponse.result)
}
inline ::std::string* PingResponse::mutable_result() {
  
  // @@protoc_insertion_point(field_mutable:pbrpc.api.PingResponse.result)
  return result_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PingResponse::release_result() {
  // @@protoc_insertion_point(field_release:pbrpc.api.PingResponse.result)
  
  return result_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PingResponse::set_allocated_result(::std::string* result) {
  if (result != NULL) {
    
  } else {
    
  }
  result_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), result);
  // @@protoc_insertion_point(field_set_allocated:pbrpc.api.PingResponse.result)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace api
}  // namespace pbrpc

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // PROTOBUF_INCLUDED_rpc_5fping_2eproto
