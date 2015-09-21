// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl.java
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl_openSocket_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl_openSocket_1_receiveResult_1_1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl_openSocket_1_receiveResult_1_2.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_openSocket_1::SourceRouteTransportLayerImpl_openSocket_1(SourceRouteTransportLayerImpl *SourceRouteTransportLayerImpl_this, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* handle, SourceRoute* i, ::java::nio::ByteBuffer* b, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , SourceRouteTransportLayerImpl_this(SourceRouteTransportLayerImpl_this)
    , handle(handle)
    , i(i)
    , b(b)
    , deliverSocketToMe(deliverSocketToMe)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_openSocket_1::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* c, ::org::mpisws::p2p::transport::P2PSocket* result)
{
    if(npc(handle)->getSubCancellable() != nullptr && static_cast< ::rice::p2p::commonapi::Cancellable* >(c) != npc(handle)->getSubCancellable())
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"c != handle.getSubCancellable() (indicates a bug in the code) c:"_j)->append(static_cast< ::java::lang::Object* >(c))
            ->append(u" sub:"_j)
            ->append(static_cast< ::java::lang::Object* >(npc(handle)->getSubCancellable()))->toString());

    npc(handle)->setSubCancellable(new SourceRouteTransportLayerImpl_openSocket_1_receiveResult_1_1(this, result));
    if(npc(SourceRouteTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(SourceRouteTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"openSocket("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u"):receiveResult("_j)
            ->append(static_cast< ::java::lang::Object* >(result))
            ->append(u")"_j)->toString());

    npc(result)->register_(false, true, new SourceRouteTransportLayerImpl_openSocket_1_receiveResult_1_2(this, b, deliverSocketToMe, handle, i));
}

void org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_openSocket_1::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* c, ::java::lang::Exception* exception)
{
    npc(deliverSocketToMe)->receiveException(handle, exception);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_openSocket_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_openSocket_1::getClass0()
{
    return class_();
}

