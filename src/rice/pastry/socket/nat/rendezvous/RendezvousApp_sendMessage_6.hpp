// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousApp.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousApp_sendMessage_6
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::MessageRequestHandle
{

public:
    typedef ::java::lang::Object super;
    bool cancel() override;
    ::java::nio::ByteBuffer* getMessage() override;
    RendezvousSocketNodeHandle* getIdentifier() override;
    ::java::util::Map* getOptions() override;

    // Generated
    RendezvousApp_sendMessage_6(RendezvousApp *RendezvousApp_this, RendezvousSocketNodeHandle* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options, ::rice::pastry::routing::RouteMessage* rm);
    static ::java::lang::Class *class_();
    RendezvousApp *RendezvousApp_this;
    RendezvousSocketNodeHandle* i;
    ::java::nio::ByteBuffer* m;
    ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe;
    ::java::util::Map* options;
    ::rice::pastry::routing::RouteMessage* rm;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RendezvousApp;
    friend class RendezvousApp_RendezvousApp_1;
    friend class RendezvousApp_openChannel_2;
    friend class RendezvousApp_openChannel_3;
    friend class RendezvousApp_openChannel_4;
    friend class RendezvousApp_sendMessage_5;
    friend class RendezvousApp_sendMessage_7;
};
