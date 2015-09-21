// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_openSocket_2.hpp>

#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_openSocket_2_receiveResult_2_1.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_openSocket_2_receiveResult_2_2.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_openSocket_2::PriorityTransportLayerImpl_openSocket_2(PriorityTransportLayerImpl *PriorityTransportLayerImpl_this, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* handle, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , PriorityTransportLayerImpl_this(PriorityTransportLayerImpl_this)
    , handle(handle)
    , deliverSocketToMe(deliverSocketToMe)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_openSocket_2::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    npc(handle)->setSubCancellable(new PriorityTransportLayerImpl_openSocket_2_receiveResult_2_1(this, sock));
    npc(sock)->register_(false, true, new PriorityTransportLayerImpl_openSocket_2_receiveResult_2_2(this, deliverSocketToMe, handle));
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_openSocket_2::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    if(npc(handle)->getSubCancellable() != nullptr && static_cast< ::rice::p2p::commonapi::Cancellable* >(s) != npc(handle)->getSubCancellable())
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"s != handle.getSubCancellable() must be a bug. s:"_j)->append(static_cast< ::java::lang::Object* >(s))
            ->append(u" sub:"_j)
            ->append(static_cast< ::java::lang::Object* >(npc(handle)->getSubCancellable()))->toString());

    if(deliverSocketToMe != nullptr)
        npc(deliverSocketToMe)->receiveException(handle, ex);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_openSocket_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_openSocket_2::getClass0()
{
    return class_();
}

