// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/ssl/SSLTransportLayerImpl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/ssl/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl_openSocket_1_receiveResult_1_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    void receiveException(::java::lang::Exception* exception) override;
    virtual void receiveResult(SSLSocketManager* result);

    // Generated
    SSLTransportLayerImpl_openSocket_1_receiveResult_1_1(SSLTransportLayerImpl_openSocket_1 *SSLTransportLayerImpl_openSocket_1_this, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret);
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;
    SSLTransportLayerImpl_openSocket_1 *SSLTransportLayerImpl_openSocket_1_this;
    ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe;
    ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SSLTransportLayerImpl;
    friend class SSLTransportLayerImpl_openSocket_1;
    friend class SSLTransportLayerImpl_incomingSocket_2;
};
