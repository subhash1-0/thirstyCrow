// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.java
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_4.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousContact.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_readAcceptHeader_6.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/util/tuples/MutableTuple.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_4::RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_4(RendezvousTransportLayerImpl_readAcceptHeader_6 *RendezvousTransportLayerImpl_readAcceptHeader_6_this, ::org::mpisws::p2p::transport::P2PSocket* acceptorSocket, RendezvousContact* target, RendezvousContact* opener, int32_t uid, ::rice::p2p::util::tuples::MutableTuple* forwardSockets)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousTransportLayerImpl_readAcceptHeader_6_this(RendezvousTransportLayerImpl_readAcceptHeader_6_this)
    , acceptorSocket(acceptorSocket)
    , target(target)
    , opener(opener)
    , uid(uid)
    , forwardSockets(forwardSockets)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_4::receiveResult(::org::mpisws::p2p::transport::P2PSocket* result)
{
    if(npc(RendezvousTransportLayerImpl_readAcceptHeader_6_this->RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(RendezvousTransportLayerImpl_readAcceptHeader_6_this->RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Connector socket complete, setting up forwarding. readAcceptHeader("_j)->append(static_cast< ::java::lang::Object* >(acceptorSocket))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(target))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(opener))
            ->append(u","_j)
            ->append(uid)
            ->append(u")"_j)->toString());

    npc(forwardSockets)->setA(result);
    if(java_cast< ::org::mpisws::p2p::transport::P2PSocket* >(npc(forwardSockets)->b()) != nullptr)
        RendezvousTransportLayerImpl_readAcceptHeader_6_this->RendezvousTransportLayerImpl_this->createForwarder(java_cast< ::org::mpisws::p2p::transport::P2PSocket* >(npc(forwardSockets)->a()), java_cast< ::org::mpisws::p2p::transport::P2PSocket* >(npc(forwardSockets)->b()), opener, target, uid);

}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_4::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::org::mpisws::p2p::transport::P2PSocket* >(result));
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_4::receiveException(::java::lang::Exception* exception)
{
    if(npc(RendezvousTransportLayerImpl_readAcceptHeader_6_this->RendezvousTransportLayerImpl_this->logger)->level <= npc(RendezvousTransportLayerImpl_readAcceptHeader_6_this->RendezvousTransportLayerImpl_this->logger)->WARNING)
        npc(RendezvousTransportLayerImpl_readAcceptHeader_6_this->RendezvousTransportLayerImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Error writing failed bytes in readAcceptHeader("_j)->append(static_cast< ::java::lang::Object* >(acceptorSocket))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(target))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(opener))
            ->append(u","_j)
            ->append(uid)
            ->append(u")"_j)->toString(), exception);

    npc(acceptorSocket)->close();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_4::getClass0()
{
    return class_();
}

