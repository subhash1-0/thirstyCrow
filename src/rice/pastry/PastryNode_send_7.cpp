// Generated from /pastry-2.1/src/rice/pastry/PastryNode.java
#include <rice/pastry/PastryNode_send_7.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/messaging/PRawMessage.hpp>
#include <rice/pastry/transport/PMessageReceiptImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::PastryNode_send_7::PastryNode_send_7(PastryNode *PastryNode_this, ::rice::pastry::transport::PMessageReceiptImpl* ret, NodeHandle* handle, ::rice::pastry::messaging::PRawMessage* rm, ::org::mpisws::p2p::transport::MessageCallback* callback, ::java::util::Map* options)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastryNode_this(PastryNode_this)
    , ret(ret)
    , handle(handle)
    , rm(rm)
    , callback(callback)
    , options(options)
{
    clinit();
    ctor();
}

void rice::pastry::PastryNode_send_7::run()
{
    npc(ret)->setInternal(npc(PastryNode_this->tl)->sendMessage(handle, rm, callback, options));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::PastryNode_send_7::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::PastryNode_send_7::getClass0()
{
    return class_();
}

