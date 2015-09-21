// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/limitsockets/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_openSocket_1
    : public ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl
{

public:
    typedef ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl super;
    bool cancel() override;
    ::java::lang::String* toString() override;

    // Generated
    LimitSocketsTransportLayer_openSocket_1(LimitSocketsTransportLayer *LimitSocketsTransportLayer_this, ::java::lang::Object* i_, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options_, ::java::lang::Object* i, ::java::util::Map* options, ::rice::environment::logging::Logger* logger);
    static ::java::lang::Class *class_();
    LimitSocketsTransportLayer *LimitSocketsTransportLayer_this;
    ::java::lang::Object* i;
    ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe;
    ::java::util::Map* options;

private:
    virtual ::java::lang::Class* getClass0();
    friend class LimitSocketsTransportLayer;
    friend class LimitSocketsTransportLayer_openSocket_2;
    friend class LimitSocketsTransportLayer_LSSocket;
    friend class LimitSocketsTransportLayer_LSSocket_forceClose_1;
};
