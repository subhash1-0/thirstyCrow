// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl.java
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl_AddressManager_PendingMessage.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/LinkedList.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl_AddressManager.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>

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

org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingMessage::SourceRouteManagerImpl_AddressManager_PendingMessage(SourceRouteManagerImpl_AddressManager *SourceRouteManagerImpl_AddressManager_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , SourceRouteManagerImpl_AddressManager_this(SourceRouteManagerImpl_AddressManager_this)
{
    clinit();
}

org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingMessage::SourceRouteManagerImpl_AddressManager_PendingMessage(SourceRouteManagerImpl_AddressManager *SourceRouteManagerImpl_AddressManager_this, ::java::nio::ByteBuffer* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) 
    : SourceRouteManagerImpl_AddressManager_PendingMessage(SourceRouteManagerImpl_AddressManager_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(message,deliverAckToMe,options);
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingMessage::ctor(::java::nio::ByteBuffer* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    super::ctor();
    this->message = message;
    this->deliverAckToMe = deliverAckToMe;
    this->options = options;
}

bool org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingMessage::cancel()
{
    if(cancellable == nullptr) {
        return npc(SourceRouteManagerImpl_AddressManager_this->pendingMessages)->remove(static_cast< ::java::lang::Object* >(this));
    }
    return npc(cancellable)->cancel();
}

java::util::Map* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingMessage::getOptions()
{
    return options;
}

java::lang::Object* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingMessage::getIdentifier()
{
    return java_cast< ::java::lang::Object* >(SourceRouteManagerImpl_AddressManager_this->address);
}

java::nio::ByteBuffer* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingMessage::getMessage()
{
    return message;
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingMessage::ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg)
{
    npc(deliverAckToMe)->ack(this);
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingMessage::sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* reason)
{
    npc(deliverAckToMe)->sendFailed(this, reason);
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingMessage::fail(::java::lang::Exception* reason)
{
    cancel();
    sendFailed(static_cast< ::org::mpisws::p2p::transport::MessageRequestHandle* >(nullptr), reason);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.sourceroute.manager.SourceRouteManagerImpl.AddressManager.PendingMessage", 97);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingMessage::getClass0()
{
    return class_();
}

