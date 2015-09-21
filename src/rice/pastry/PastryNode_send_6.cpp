// Generated from /pastry-2.1/src/rice/pastry/PastryNode.java
#include <rice/pastry/PastryNode_send_6.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/transport/PMessageNotification.hpp>
#include <rice/pastry/transport/PMessageReceiptImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::PastryNode_send_6::PastryNode_send_6(PastryNode *PastryNode_this, ::rice::pastry::transport::PMessageReceiptImpl* ret, ::rice::pastry::transport::PMessageNotification* deliverAckToMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastryNode_this(PastryNode_this)
    , ret(ret)
    , deliverAckToMe(deliverAckToMe)
{
    clinit();
    ctor();
}

void rice::pastry::PastryNode_send_6::ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg)
{
    if(npc(ret)->getInternal() == nullptr)
        npc(ret)->setInternal(msg);

    npc(deliverAckToMe)->sent(ret);
}

void rice::pastry::PastryNode_send_6::sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* reason)
{
    if(npc(ret)->getInternal() == nullptr)
        npc(ret)->setInternal(msg);

    npc(deliverAckToMe)->sendFailed(ret, reason);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::PastryNode_send_6::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::PastryNode_send_6::getClass0()
{
    return class_();
}

