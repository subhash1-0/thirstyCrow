// Generated from /pastry-2.1/src/rice/p2p/util/MCAdapter.java
#include <rice/p2p/util/MCAdapter.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <rice/p2p/util/MRHAdapter.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::MCAdapter::MCAdapter(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::MCAdapter::MCAdapter(::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, MRHAdapter* handle) 
    : MCAdapter(*static_cast< ::default_init_tag* >(0))
{
    ctor(deliverAckToMe,handle);
}

void rice::p2p::util::MCAdapter::ctor(::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, MRHAdapter* handle)
{
    super::ctor();
    this->internal = deliverAckToMe;
    this->handle = handle;
}

void rice::p2p::util::MCAdapter::ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg)
{
    npc(internal)->ack(handle);
}

void rice::p2p::util::MCAdapter::sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* reason)
{
    npc(internal)->sendFailed(handle, reason);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::MCAdapter::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.MCAdapter", 23);
    return c;
}

java::lang::Class* rice::p2p::util::MCAdapter::getClass0()
{
    return class_();
}

