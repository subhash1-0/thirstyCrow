// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.java
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_AbstractPilot.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/LinkedList.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousContact.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.hpp>
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

org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_AbstractPilot::RendezvousTransportLayerImpl_AbstractPilot(RendezvousTransportLayerImpl *RendezvousTransportLayerImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousTransportLayerImpl_this(RendezvousTransportLayerImpl_this)
{
    clinit();
}

org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_AbstractPilot::RendezvousTransportLayerImpl_AbstractPilot(RendezvousTransportLayerImpl *RendezvousTransportLayerImpl_this)
    : RendezvousTransportLayerImpl_AbstractPilot(RendezvousTransportLayerImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_AbstractPilot::ctor()
{
    super::ctor();
    init();
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_AbstractPilot::init()
{
    queue = new ::java::util::LinkedList();
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_AbstractPilot::enqueue(::java::nio::ByteBuffer* bb)
{
    if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".enqueue("_j)
            ->append(static_cast< ::java::lang::Object* >(bb))
            ->append(u")"_j)->toString());

    npc(queue)->add(static_cast< ::java::lang::Object* >(bb));
    npc(socket)->register_(false, true, this);
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_AbstractPilot::write() /* throws(IOException) */
{
    if(npc(queue)->isEmpty())
        return;

    auto ret = npc(socket)->write(java_cast< ::java::nio::ByteBuffer* >(npc(queue)->getFirst()));
    if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" wrote "_j)
            ->append(ret)
            ->append(u" bytes of "_j)
            ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::nio::ByteBuffer* >(npc(queue)->getFirst())))->toString());

    if(ret < 0)
        cancel();

    if(npc(java_cast< ::java::nio::ByteBuffer* >(npc(queue)->getFirst()))->hasRemaining()) {
        npc(socket)->register_(false, true, this);
        return;
    } else {
        npc(queue)->removeFirst();
        write();
    }
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_AbstractPilot::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(canWrite) {
        write();
    }
    if(canRead) {
        read();
    }
}

java::lang::String* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_AbstractPilot::toString()
{
    return ::java::lang::StringBuilder().append(u""_j)->append(static_cast< ::java::lang::Object* >(java_cast< RendezvousContact* >(i)))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_AbstractPilot::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.rendezvous.RendezvousTransportLayerImpl.AbstractPilot", 78);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_AbstractPilot::getClass0()
{
    return class_();
}

