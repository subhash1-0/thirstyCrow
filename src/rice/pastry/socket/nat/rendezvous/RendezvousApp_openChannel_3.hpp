// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousApp.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousApp_openChannel_3
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Cancellable
{

public:
    typedef ::java::lang::Object super;
    bool cancel() override;

    // Generated
    RendezvousApp_openChannel_3(RendezvousApp *RendezvousApp_this, RendezvousSocketNodeHandle* target, RendezvousSocketNodeHandle* rendezvous, RendezvousSocketNodeHandle* source, int32_t uid, ::rice::Continuation* deliverAckToMe, ::java::util::Map* options, ::rice::pastry::routing::RouteMessage* rm);
    static ::java::lang::Class *class_();
    RendezvousApp *RendezvousApp_this;
    RendezvousSocketNodeHandle* target;
    RendezvousSocketNodeHandle* rendezvous;
    RendezvousSocketNodeHandle* source;
    int32_t uid;
    ::rice::Continuation* deliverAckToMe;
    ::java::util::Map* options;
    ::rice::pastry::routing::RouteMessage* rm;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RendezvousApp;
    friend class RendezvousApp_RendezvousApp_1;
    friend class RendezvousApp_openChannel_2;
    friend class RendezvousApp_openChannel_4;
    friend class RendezvousApp_sendMessage_5;
    friend class RendezvousApp_sendMessage_6;
    friend class RendezvousApp_sendMessage_7;
};
