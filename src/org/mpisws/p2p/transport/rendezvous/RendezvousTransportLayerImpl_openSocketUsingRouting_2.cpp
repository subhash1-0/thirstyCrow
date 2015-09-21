// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.java
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_openSocketUsingRouting_2.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousContact.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.hpp>
#include <rice/environment/logging/Logger.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openSocketUsingRouting_2::RendezvousTransportLayerImpl_openSocketUsingRouting_2(RendezvousTransportLayerImpl *RendezvousTransportLayerImpl_this, RendezvousContact* contact, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options, ::org::mpisws::p2p::transport::SocketRequestHandle* handle)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousTransportLayerImpl_this(RendezvousTransportLayerImpl_this)
    , contact(contact)
    , deliverSocketToMe(deliverSocketToMe)
    , options(options)
    , handle(handle)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openSocketUsingRouting_2::receiveResult(::java::lang::Integer* result)
{
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openSocketUsingRouting_2::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::lang::Integer* >(result));
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openSocketUsingRouting_2::receiveException(::java::lang::Exception* exception)
{
    if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(RendezvousTransportLayerImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"openSocket("_j)->append(static_cast< ::java::lang::Object* >(contact))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverSocketToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u")"_j)->toString(), exception);

    npc(deliverSocketToMe)->receiveException(handle, exception);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openSocketUsingRouting_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openSocketUsingRouting_2::getClass0()
{
    return class_();
}

