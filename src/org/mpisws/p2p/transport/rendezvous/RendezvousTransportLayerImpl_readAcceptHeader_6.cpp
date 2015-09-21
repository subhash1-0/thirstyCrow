// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.java
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_readAcceptHeader_6.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>
#include <org/mpisws/p2p/transport/rendezvous/ContactDeserializer.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousContact.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_2.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_3.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_4.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_5.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_ByteWriter.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/util/InsufficientBytesException.hpp>
#include <org/mpisws/p2p/transport/util/SocketInputBuffer.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/util/tuples/MutableTuple.hpp>
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

org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6::RendezvousTransportLayerImpl_readAcceptHeader_6(RendezvousTransportLayerImpl *RendezvousTransportLayerImpl_this, ::org::mpisws::p2p::transport::util::SocketInputBuffer* sib)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousTransportLayerImpl_this(RendezvousTransportLayerImpl_this)
    , sib(sib)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* acceptorSocket, bool canRead, bool canWrite) /* throws(IOException) */
{
    try {
        auto const target = java_cast< RendezvousContact* >(npc(RendezvousTransportLayerImpl_this->serializer)->deserialize(sib));
        auto const opener = java_cast< RendezvousContact* >(npc(RendezvousTransportLayerImpl_this->serializer)->deserialize(sib));
        auto const uid = npc(sib)->readInt();
        if(npc(opener)->equals(java_cast< RendezvousContact* >(RendezvousTransportLayerImpl_this->localNodeHandle))) {
            auto const deliverSocketToMe = RendezvousTransportLayerImpl_this->removeExpectedIncomingSocket(target, uid);
            if(deliverSocketToMe == nullptr) {
                if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Got accept socket to me, that I'm not expecting: t:"_j)->append(static_cast< ::java::lang::Object* >(target))
                        ->append(u" o:"_j)
                        ->append(static_cast< ::java::lang::Object* >(opener))
                        ->append(u" uid:"_j)
                        ->append(uid)
                        ->append(u" "_j)
                        ->append(static_cast< ::java::lang::Object* >(acceptorSocket))->toString());

                (new RendezvousTransportLayerImpl_ByteWriter(RendezvousTransportLayerImpl_this, RendezvousTransportLayerImpl::CONNECTION_RESPONSE_FAILURE, static_cast< ::rice::Continuation* >(new RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_1(this))))->receiveSelectResult(acceptorSocket, false, true);
                return;
            }
            (new RendezvousTransportLayerImpl_ByteWriter(RendezvousTransportLayerImpl_this, RendezvousTransportLayerImpl::CONNECTION_RESPONSE_SUCCESS, static_cast< ::rice::Continuation* >(new RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_2(this, deliverSocketToMe))))->receiveSelectResult(acceptorSocket, false, true);
            return;
        }
        if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
            npc(RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"readAcceptHeader("_j)->append(static_cast< ::java::lang::Object* >(acceptorSocket))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(target))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(opener))
                ->append(u","_j)
                ->append(uid)
                ->append(u")"_j)->toString());

        auto const connectorSocket = RendezvousTransportLayerImpl_this->removeConnectSocket(opener, target, uid);
        if(connectorSocket == nullptr) {
            if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"writing failed bytes in readAcceptHeader("_j)->append(static_cast< ::java::lang::Object* >(acceptorSocket))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(target))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(opener))
                    ->append(u","_j)
                    ->append(uid)
                    ->append(u")"_j)->toString());

            ::org::mpisws::p2p::transport::P2PSocketReceiver* acceptorFailed = new RendezvousTransportLayerImpl_ByteWriter(RendezvousTransportLayerImpl_this, RendezvousTransportLayerImpl::CONNECTION_RESPONSE_FAILURE, static_cast< ::rice::Continuation* >(new RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_3(this, acceptorSocket, target, opener, uid)));
            npc(acceptorFailed)->receiveSelectResult(acceptorSocket, false, true);
        } else {
            auto const forwardSockets = new ::rice::p2p::util::tuples::MutableTuple();
            if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
                npc(RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"writing success bytes in readAcceptHeader("_j)->append(static_cast< ::java::lang::Object* >(acceptorSocket))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(target))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(opener))
                    ->append(u","_j)
                    ->append(uid)
                    ->append(u")"_j)->toString());

            ::org::mpisws::p2p::transport::P2PSocketReceiver* connectorSuccess = new RendezvousTransportLayerImpl_ByteWriter(RendezvousTransportLayerImpl_this, RendezvousTransportLayerImpl::CONNECTION_RESPONSE_SUCCESS, static_cast< ::rice::Continuation* >(new RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_4(this, acceptorSocket, target, opener, uid, forwardSockets)));
            npc(connectorSuccess)->receiveSelectResult(connectorSocket, false, true);
            ::org::mpisws::p2p::transport::P2PSocketReceiver* acceptorSuccess = new RendezvousTransportLayerImpl_ByteWriter(RendezvousTransportLayerImpl_this, RendezvousTransportLayerImpl::CONNECTION_RESPONSE_SUCCESS, static_cast< ::rice::Continuation* >(new RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_5(this, acceptorSocket, target, opener, uid, forwardSockets, connectorSocket)));
            npc(acceptorSuccess)->receiveSelectResult(acceptorSocket, false, true);
        }
    } catch (::org::mpisws::p2p::transport::util::InsufficientBytesException* ibe) {
        npc(acceptorSocket)->register_(true, false, this);
    }
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(RendezvousTransportLayerImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"error in readConnectHeader("_j)->append(static_cast< ::java::lang::Object* >(socket))
            ->append(u") closing."_j)->toString(), ioe);

    npc(socket)->close();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6::getClass0()
{
    return class_();
}

