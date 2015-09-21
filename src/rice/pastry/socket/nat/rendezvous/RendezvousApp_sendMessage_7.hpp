// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousApp.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/routing/RouteMessageNotification.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousApp_sendMessage_7
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::routing::RouteMessageNotification
{

public:
    typedef ::java::lang::Object super;
    void sendSuccess(::rice::pastry::routing::RouteMessage* message, ::rice::pastry::NodeHandle* nextHop) override;
    void sendFailed(::rice::pastry::routing::RouteMessage* message, ::java::lang::Exception* e) override;

    // Generated
    RendezvousApp_sendMessage_7(RendezvousApp *RendezvousApp_this, RendezvousSocketNodeHandle* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options, ::org::mpisws::p2p::transport::MessageRequestHandle* ret);
    static ::java::lang::Class *class_();
    RendezvousApp *RendezvousApp_this;
    RendezvousSocketNodeHandle* i;
    ::java::nio::ByteBuffer* m;
    ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe;
    ::java::util::Map* options;
    ::org::mpisws::p2p::transport::MessageRequestHandle* ret;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RendezvousApp;
    friend class RendezvousApp_RendezvousApp_1;
    friend class RendezvousApp_openChannel_2;
    friend class RendezvousApp_openChannel_3;
    friend class RendezvousApp_openChannel_4;
    friend class RendezvousApp_sendMessage_5;
    friend class RendezvousApp_sendMessage_6;
};
