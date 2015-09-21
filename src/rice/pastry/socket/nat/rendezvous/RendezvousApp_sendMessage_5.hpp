// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousApp.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/transport/PMessageNotification.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousApp_sendMessage_5
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::transport::PMessageNotification
{

public:
    typedef ::java::lang::Object super;
    void sent(::rice::pastry::transport::PMessageReceipt* msg) override;
    void sendFailed(::rice::pastry::transport::PMessageReceipt* msg, ::java::lang::Exception* reason) override;

    // Generated
    RendezvousApp_sendMessage_5(RendezvousApp *RendezvousApp_this, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl* ret);
    static ::java::lang::Class *class_();
    RendezvousApp *RendezvousApp_this;
    ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe;
    ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl* ret;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RendezvousApp;
    friend class RendezvousApp_RendezvousApp_1;
    friend class RendezvousApp_openChannel_2;
    friend class RendezvousApp_openChannel_3;
    friend class RendezvousApp_openChannel_4;
    friend class RendezvousApp_sendMessage_6;
    friend class RendezvousApp_sendMessage_7;
};
