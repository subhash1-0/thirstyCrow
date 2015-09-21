// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.java
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_OutgoingPilot.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/rendezvous/ContactDeserializer.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousContact.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/util/InsufficientBytesException.hpp>
#include <org/mpisws/p2p/transport/util/SocketInputBuffer.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/TimerTask.hpp>

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

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_OutgoingPilot::RendezvousTransportLayerImpl_OutgoingPilot(RendezvousTransportLayerImpl *RendezvousTransportLayerImpl_this, const ::default_init_tag&)
    : super(RendezvousTransportLayerImpl_this, *static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_OutgoingPilot::RendezvousTransportLayerImpl_OutgoingPilot(RendezvousTransportLayerImpl *RendezvousTransportLayerImpl_this, RendezvousContact* i, ::java::util::Map* options) 
    : RendezvousTransportLayerImpl_OutgoingPilot(RendezvousTransportLayerImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(i,options);
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_OutgoingPilot::ctor(RendezvousContact* i, ::java::util::Map* options)
{
    super::ctor();
    this->i = i;
    this->options = options;
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_OutgoingPilot::init_()
{
    npc(RendezvousTransportLayerImpl_this->selectorManager)->schedule(static_cast< ::rice::selector::TimerTask* >(this), static_cast< int64_t >(RendezvousTransportLayerImpl::PILOT_PING_PERIOD), static_cast< int64_t >(RendezvousTransportLayerImpl::PILOT_PING_PERIOD));
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_OutgoingPilot::receiveException(::java::lang::Exception* ex)
{
    cancel();
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_OutgoingPilot::setCancellable(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable)
{
    this->cancellable = cancellable;
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_OutgoingPilot::setSocket(::org::mpisws::p2p::transport::P2PSocket* socket)
{
    if(cancelled) {
        npc(socket)->close();
        return;
    }
    this->cancellable = nullptr;
    this->socket = socket;
    if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" success opening outgoing pilot"_j)->toString());

    try {
        enqueue(::java::nio::ByteBuffer::wrap(RendezvousTransportLayerImpl::PILOT_SOCKET_BYTES()));
        enqueue(npc(RendezvousTransportLayerImpl_this->serializer)->serialize(java_cast< RendezvousContact* >(RendezvousTransportLayerImpl_this->localNodeHandle)));
        sib = new ::org::mpisws::p2p::transport::util::SocketInputBuffer(socket, int32_t(1024));
        receiveSelectResult(socket, true, true);
    } catch (::java::io::IOException* ioe) {
        cancel();
    }
}

java::lang::String* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_OutgoingPilot::toString()
{
    return ::java::lang::StringBuilder().append(u"OutgoingPilot{"_j)->append(static_cast< ::java::lang::Object* >(java_cast< RendezvousContact* >(i)))
        ->append(u"}("_j)
        ->append(static_cast< ::java::lang::Object* >(socket))
        ->append(u")"_j)->toString();
}

bool org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_OutgoingPilot::ping()
{
    if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".ping "_j)
            ->append(static_cast< ::java::lang::Object* >(socket))->toString());

    if(socket == nullptr)
        return false;

    enqueue(::java::nio::ByteBuffer::wrap(RendezvousTransportLayerImpl::PILOT_PING_BYTES()));
    return true;
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_OutgoingPilot::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    cancel();
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_OutgoingPilot::read() /* throws(IOException) */
{
    try {
        auto msgType = npc(sib)->readByte();
        {
            RendezvousContact* requestor;
            int32_t uid;
            switch (msgType) {
            case RendezvousTransportLayerImpl::PILOT_PONG:
                if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
                    npc(RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" received pong"_j)->toString());

                npc(sib)->clear();
                read();
                break;
            case RendezvousTransportLayerImpl::PILOT_REQUEST:
                requestor = java_cast< RendezvousContact* >(npc(RendezvousTransportLayerImpl_this->serializer)->deserialize(sib));
                uid = npc(sib)->readInt();
                if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
                    npc(RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Received socket request: requestor:"_j)->append(static_cast< ::java::lang::Object* >(requestor))
                        ->append(u" middleman:"_j)
                        ->append(static_cast< ::java::lang::Object* >(java_cast< RendezvousContact* >(i)))
                        ->append(u" uid:"_j)
                        ->append(uid)->toString());

                RendezvousTransportLayerImpl_this->openAcceptSocket(requestor, java_cast< RendezvousContact* >(i), uid);
                npc(sib)->clear();
                read();
                break;
            }
        }

    } catch (::org::mpisws::p2p::transport::util::InsufficientBytesException* ibe) {
        npc(socket)->register_(true, false, this);
        return;
    } catch (::java::io::IOException* ioe) {
        cancel();
    }
}

org::mpisws::p2p::transport::rendezvous::RendezvousContact* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_OutgoingPilot::getIdentifier()
{
    return java_cast< RendezvousContact* >(i);
}

java::util::Map* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_OutgoingPilot::getOptions()
{
    return options;
}

bool org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_OutgoingPilot::cancel()
{
    super::cancel();
    if(socket == nullptr) {
        if(cancellable != nullptr) {
            npc(cancellable)->cancel();
            cancellable = nullptr;
        }
    } else {
        npc(socket)->close();
    }
    RendezvousTransportLayerImpl_OutgoingPilot* pilot = nullptr;
    {
        synchronized synchronized_0(RendezvousTransportLayerImpl_this->outgoingPilots);
        {
            pilot = java_cast< RendezvousTransportLayerImpl_OutgoingPilot* >(npc(RendezvousTransportLayerImpl_this->outgoingPilots)->remove(java_cast< RendezvousContact* >(i)));
        }
    }
    if(pilot != nullptr)
        RendezvousTransportLayerImpl_this->notifyOutgoingPilotRemoved(java_cast< RendezvousContact* >(i));

    return true;
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_OutgoingPilot::run()
{
    ping();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_OutgoingPilot::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.rendezvous.RendezvousTransportLayerImpl.OutgoingPilot", 78);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_OutgoingPilot::getClass0()
{
    return class_();
}

