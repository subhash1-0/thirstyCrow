// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousApp.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousApp_sendMessage_5.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousApp.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::nat::rendezvous::RendezvousApp_sendMessage_5::RendezvousApp_sendMessage_5(RendezvousApp *RendezvousApp_this, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl* ret)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousApp_this(RendezvousApp_this)
    , deliverAckToMe(deliverAckToMe)
    , ret(ret)
{
    clinit();
    ctor();
}

void rice::pastry::socket::nat::rendezvous::RendezvousApp_sendMessage_5::sent(::rice::pastry::transport::PMessageReceipt* msg)
{
    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->ack(ret);

}

void rice::pastry::socket::nat::rendezvous::RendezvousApp_sendMessage_5::sendFailed(::rice::pastry::transport::PMessageReceipt* msg, ::java::lang::Exception* reason)
{
    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->sendFailed(ret, reason);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousApp_sendMessage_5::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousApp_sendMessage_5::getClass0()
{
    return class_();
}

