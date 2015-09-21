// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.java
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_sendMessage_8.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_sendMessage_8::RendezvousTransportLayerImpl_sendMessage_8(RendezvousTransportLayerImpl *RendezvousTransportLayerImpl_this, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl* ret)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousTransportLayerImpl_this(RendezvousTransportLayerImpl_this)
    , deliverAckToMe(deliverAckToMe)
    , ret(ret)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_sendMessage_8::ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg)
{
    npc(deliverAckToMe)->ack(ret);
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_sendMessage_8::sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* reason)
{
    npc(deliverAckToMe)->sendFailed(ret, reason);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_sendMessage_8::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_sendMessage_8::getClass0()
{
    return class_();
}

