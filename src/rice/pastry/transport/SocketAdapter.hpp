// Generated from /pastry-2.1/src/rice/pastry/transport/SocketAdapter.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/appsocket/AppSocket.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace nio
    {
typedef ::SubArray< ::java::nio::Buffer, ::java::lang::ObjectArray > BufferArray;
typedef ::SubArray< ::java::nio::ByteBuffer, BufferArray, ::java::lang::ComparableArray > ByteBufferArray;
    } // nio
} // java

struct default_init_tag;

class rice::pastry::transport::SocketAdapter
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::appsocket::AppSocket
    , public virtual ::org::mpisws::p2p::transport::P2PSocketReceiver
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::org::mpisws::p2p::transport::P2PSocket* internal {  };
    ::rice::environment::logging::Logger* logger {  };
    ::rice::environment::Environment* environment {  };
protected:
    void ctor(::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::Environment* env);

public:
    void close() override;
    int64_t read(::java::nio::ByteBufferArray* dsts, int32_t offset, int32_t length) /* throws(IOException) */ override;

public: /* package */
    ::rice::p2p::commonapi::appsocket::AppSocketReceiver* reader {  };
    ::rice::p2p::commonapi::appsocket::AppSocketReceiver* writer {  };

public:
    void register_(bool wantToRead, bool wantToWrite, int32_t timeout, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver) override;
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* s, ::java::lang::Exception* e) override;
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* s, bool canRead, bool canWrite) /* throws(IOException) */ override;
    void shutdownOutput() override;
    int64_t write(::java::nio::ByteBufferArray* srcs, int32_t offset, int32_t length) /* throws(IOException) */ override;
    int64_t read(::java::nio::ByteBuffer* dst) /* throws(IOException) */ override;
    int64_t write(::java::nio::ByteBuffer* src) /* throws(IOException) */ override;
    ::java::lang::String* toString() override;

    // Generated
    SocketAdapter(::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::Environment* env);
protected:
    SocketAdapter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
