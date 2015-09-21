// Generated from /pastry-2.1/src/rice/pastry/transport/AppSocketReceiverWrapper.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>

struct default_init_tag;

class rice::pastry::transport::AppSocketReceiverWrapper
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::P2PSocketReceiver
{

public:
    typedef ::java::lang::Object super;

private:
    ::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver {  };
    SocketAdapter* socket {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver, SocketAdapter* socket, ::rice::environment::Environment* env);

public:
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* s, ::java::lang::Exception* ioe) override;
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* s, bool canRead, bool canWrite) /* throws(IOException) */ override;

    // Generated
    AppSocketReceiverWrapper(::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver, SocketAdapter* socket, ::rice::environment::Environment* env);
protected:
    AppSocketReceiverWrapper(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
