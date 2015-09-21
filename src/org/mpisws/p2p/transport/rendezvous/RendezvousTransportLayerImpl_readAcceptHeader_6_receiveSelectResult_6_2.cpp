// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.java
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_2.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_readAcceptHeader_6.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/util/OptionsFactory.hpp>
#include <org/mpisws/p2p/transport/util/SocketWrapperSocket.hpp>
#include <rice/p2p/util/tuples/Tuple.hpp>

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

org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_2::RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_2(RendezvousTransportLayerImpl_readAcceptHeader_6 *RendezvousTransportLayerImpl_readAcceptHeader_6_this, ::rice::p2p::util::tuples::Tuple* deliverSocketToMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousTransportLayerImpl_readAcceptHeader_6_this(RendezvousTransportLayerImpl_readAcceptHeader_6_this)
    , deliverSocketToMe(deliverSocketToMe)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_2::receiveException(::java::lang::Exception* exception)
{
    npc(java_cast< ::org::mpisws::p2p::transport::SocketCallback* >(npc(deliverSocketToMe)->a()))->receiveException(java_cast< ::org::mpisws::p2p::transport::SocketRequestHandle* >(npc(deliverSocketToMe)->b()), exception);
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_2::receiveResult(::org::mpisws::p2p::transport::P2PSocket* result)
{
    npc(java_cast< ::org::mpisws::p2p::transport::SocketCallback* >(npc(deliverSocketToMe)->a()))->receiveResult(java_cast< ::org::mpisws::p2p::transport::SocketRequestHandle* >(npc(deliverSocketToMe)->b()), new ::org::mpisws::p2p::transport::util::SocketWrapperSocket(java_cast< ::java::lang::Object* >(npc(result)->getIdentifier()), result, RendezvousTransportLayerImpl_readAcceptHeader_6_this->RendezvousTransportLayerImpl_this->logger, RendezvousTransportLayerImpl_readAcceptHeader_6_this->RendezvousTransportLayerImpl_this->errorHandler, ::org::mpisws::p2p::transport::util::OptionsFactory::merge(npc(java_cast< ::org::mpisws::p2p::transport::SocketRequestHandle* >(npc(deliverSocketToMe)->b()))->getOptions(), npc(result)->getOptions())));
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_2::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::org::mpisws::p2p::transport::P2PSocket* >(result));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_2::getClass0()
{
    return class_();
}

