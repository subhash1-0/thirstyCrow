// Generated from /pastry-2.1/src/rice/pastry/PastryNode.java
#include <rice/pastry/PastryNode_connect_3.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/nio/IntBuffer.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode_connect_3_run_3_1.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/client/PastryAppl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::PastryNode_connect_3::PastryNode_connect_3(PastryNode *PastryNode_this, ::rice::pastry::client::PastryAppl* appl, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* handle, NodeHandle* i, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* deliverSocketToMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastryNode_this(PastryNode_this)
    , appl(appl)
    , handle(handle)
    , i(i)
    , deliverSocketToMe(deliverSocketToMe)
{
    clinit();
    ctor();
}

void rice::pastry::PastryNode_connect_3::run()
{
    auto const b = ::java::nio::ByteBuffer::allocate(4);
    npc(npc(b)->asIntBuffer())->put(npc(appl)->getAddress());
    npc(b)->clear();
    npc(handle)->setSubCancellable(npc(PastryNode_this->tl)->openSocket(i, new PastryNode_connect_3_run_3_1(this, handle, i, b, deliverSocketToMe, appl), nullptr));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::PastryNode_connect_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::PastryNode_connect_3::getClass0()
{
    return class_();
}

