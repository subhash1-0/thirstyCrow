// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.java
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_IncomingPilot.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/rendezvous/ContactDeserializer.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousContact.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/util/InsufficientBytesException.hpp>
#include <org/mpisws/p2p/transport/util/SocketInputBuffer.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>

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

org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_IncomingPilot::RendezvousTransportLayerImpl_IncomingPilot(RendezvousTransportLayerImpl *RendezvousTransportLayerImpl_this, const ::default_init_tag&)
    : super(RendezvousTransportLayerImpl_this, *static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_IncomingPilot::RendezvousTransportLayerImpl_IncomingPilot(RendezvousTransportLayerImpl *RendezvousTransportLayerImpl_this, ::org::mpisws::p2p::transport::P2PSocket* socket)  /* throws(IOException) */
    : RendezvousTransportLayerImpl_IncomingPilot(RendezvousTransportLayerImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(socket);
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_IncomingPilot::ctor(::org::mpisws::p2p::transport::P2PSocket* socket) /* throws(IOException) */
{
    super::ctor();
    this->socket = socket;
    sib = new ::org::mpisws::p2p::transport::util::SocketInputBuffer(socket, int32_t(1024));
    receiveSelectResult(socket, true, true);
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_IncomingPilot::requestSocket(RendezvousContact* requestor, int32_t uid) /* throws(IOException) */
{
    if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Requesting socket from: "_j)->append(static_cast< ::java::lang::Object* >(java_cast< RendezvousContact* >(i)))
            ->append(u"requestor:"_j)
            ->append(static_cast< ::java::lang::Object* >(requestor))
            ->append(u" uid:"_j)
            ->append(uid)->toString());

    auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
    npc(sob)->writeByte(RendezvousTransportLayerImpl::PILOT_REQUEST);
    npc(RendezvousTransportLayerImpl_this->serializer)->serialize(requestor, sob);
    npc(sob)->writeInt(uid);
    enqueue(npc(sob)->getByteBuffer());
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_IncomingPilot::read() /* throws(IOException) */
{
    if(java_cast< RendezvousContact* >(i) == nullptr) {
        try {
            i = java_cast< RendezvousContact* >(npc(RendezvousTransportLayerImpl_this->serializer)->deserialize(sib));
            if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Received incoming Pilot from "_j)->append(static_cast< ::java::lang::Object* >(java_cast< RendezvousContact* >(i)))->toString());

        } catch (::org::mpisws::p2p::transport::util::InsufficientBytesException* ibe) {
            npc(socket)->register_(true, false, this);
            return;
        }
        npc(sib)->clear();
        npc(RendezvousTransportLayerImpl_this->incomingPilots)->put(java_cast< RendezvousContact* >(i), this);
        RendezvousTransportLayerImpl_this->notifyIncomingPilotAdded(java_cast< RendezvousContact* >(i));
    }
    try {
        auto msgType = npc(sib)->readByte();
        switch (msgType) {
        case RendezvousTransportLayerImpl::PILOT_PING:
            if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" received ping"_j)->toString());

            npc(sib)->clear();
            enqueue(::java::nio::ByteBuffer::wrap(RendezvousTransportLayerImpl::PILOT_PONG_BYTES()));
            read();
            break;
        }

    } catch (::org::mpisws::p2p::transport::util::InsufficientBytesException* ibe) {
        npc(socket)->register_(true, false, this);
        return;
    } catch (::java::io::IOException* ioe) {
        cancel();
    }
}

bool org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_IncomingPilot::cancel()
{
    return super::cancel();
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_IncomingPilot::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    if(java_cast< RendezvousContact* >(i) != nullptr) {
        if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Shutdown of incoming pilot "_j)->append(static_cast< ::java::lang::Object* >(socket))->toString());

        auto pilot = java_cast< RendezvousTransportLayerImpl_IncomingPilot* >(npc(RendezvousTransportLayerImpl_this->incomingPilots)->remove(java_cast< RendezvousContact* >(i)));
        if(pilot != nullptr)
            RendezvousTransportLayerImpl_this->notifyIncomingPilotRemoved(java_cast< RendezvousContact* >(i));

    }
    npc(socket)->close();
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_IncomingPilot::run()
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_IncomingPilot::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.rendezvous.RendezvousTransportLayerImpl.IncomingPilot", 78);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_IncomingPilot::getClass0()
{
    return class_();
}

