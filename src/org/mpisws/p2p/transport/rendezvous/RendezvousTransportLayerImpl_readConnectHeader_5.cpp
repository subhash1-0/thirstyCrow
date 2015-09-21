// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.java
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_readConnectHeader_5.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/rendezvous/ContactDeserializer.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousContact.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousStrategy.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_IncomingPilot.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/util/InsufficientBytesException.hpp>
#include <org/mpisws/p2p/transport/util/SocketInputBuffer.hpp>
#include <rice/environment/logging/Logger.hpp>

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

org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readConnectHeader_5::RendezvousTransportLayerImpl_readConnectHeader_5(RendezvousTransportLayerImpl *RendezvousTransportLayerImpl_this, ::org::mpisws::p2p::transport::util::SocketInputBuffer* sib)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousTransportLayerImpl_this(RendezvousTransportLayerImpl_this)
    , sib(sib)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readConnectHeader_5::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    try {
        auto target = java_cast< RendezvousContact* >(npc(RendezvousTransportLayerImpl_this->serializer)->deserialize(sib));
        auto opener = java_cast< RendezvousContact* >(npc(RendezvousTransportLayerImpl_this->serializer)->deserialize(sib));
        auto uid = npc(sib)->readInt();
        if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
            npc(RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"readConnectHeader("_j)->append(static_cast< ::java::lang::Object* >(socket))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(target))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(opener))
                ->append(u","_j)
                ->append(uid)
                ->append(u")"_j)->toString());

        RendezvousTransportLayerImpl_this->putConnectSocket(opener, target, uid, socket);
        if(npc(RendezvousTransportLayerImpl_this->incomingPilots)->containsKey(target)) {
            if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"I'm the rendezevous for "_j)->append(static_cast< ::java::lang::Object* >(opener))
                    ->append(u" to "_j)
                    ->append(static_cast< ::java::lang::Object* >(target))
                    ->append(u" and I have a pilot."_j)->toString());

            auto pilot = java_cast< RendezvousTransportLayerImpl_IncomingPilot* >(npc(RendezvousTransportLayerImpl_this->incomingPilots)->get(target));
            npc(pilot)->requestSocket(opener, uid);
        } else {
            if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"I'm the rendezevous for "_j)->append(static_cast< ::java::lang::Object* >(opener))
                    ->append(u" to "_j)
                    ->append(static_cast< ::java::lang::Object* >(target))
                    ->append(u" and I don't have a pilot."_j)->toString());

            npc(RendezvousTransportLayerImpl_this->rendezvousStrategy)->openChannel(target, java_cast< RendezvousContact* >(RendezvousTransportLayerImpl_this->localNodeHandle), opener, uid, nullptr, npc(socket)->getOptions());
        }
    } catch (::org::mpisws::p2p::transport::util::InsufficientBytesException* ibe) {
        npc(socket)->register_(true, false, this);
    }
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readConnectHeader_5::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(RendezvousTransportLayerImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"error in readConnectHeader("_j)->append(static_cast< ::java::lang::Object* >(socket))
            ->append(u") closing."_j)->toString(), ioe);

    npc(socket)->close();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readConnectHeader_5::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readConnectHeader_5::getClass0()
{
    return class_();
}

