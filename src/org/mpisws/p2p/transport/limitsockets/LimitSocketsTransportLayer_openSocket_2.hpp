// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/limitsockets/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_openSocket_2
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::SocketCallback
{

public:
    typedef ::java::lang::Object super;
    void receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock) override;
    void receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex) override;
    ::java::lang::String* toString() override;

    // Generated
    LimitSocketsTransportLayer_openSocket_2(LimitSocketsTransportLayer *LimitSocketsTransportLayer_this, ::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret, ::java::util::Map* options);
    static ::java::lang::Class *class_();
    LimitSocketsTransportLayer *LimitSocketsTransportLayer_this;
    ::java::lang::Object* i;
    ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe;
    ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret;
    ::java::util::Map* options;

private:
    virtual ::java::lang::Class* getClass0();
    friend class LimitSocketsTransportLayer;
    friend class LimitSocketsTransportLayer_openSocket_1;
    friend class LimitSocketsTransportLayer_LSSocket;
    friend class LimitSocketsTransportLayer_LSSocket_forceClose_1;
};
