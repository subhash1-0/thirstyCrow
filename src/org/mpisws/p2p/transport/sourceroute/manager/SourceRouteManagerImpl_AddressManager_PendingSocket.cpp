// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl.java
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl_AddressManager_PendingSocket.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/LinkedList.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl_AddressManager.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerP2PSocket.hpp>
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

org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingSocket::SourceRouteManagerImpl_AddressManager_PendingSocket(SourceRouteManagerImpl_AddressManager *SourceRouteManagerImpl_AddressManager_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , SourceRouteManagerImpl_AddressManager_this(SourceRouteManagerImpl_AddressManager_this)
{
    clinit();
}

org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingSocket::SourceRouteManagerImpl_AddressManager_PendingSocket(SourceRouteManagerImpl_AddressManager *SourceRouteManagerImpl_AddressManager_this, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) 
    : SourceRouteManagerImpl_AddressManager_PendingSocket(SourceRouteManagerImpl_AddressManager_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(deliverSocketToMe,options);
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingSocket::ctor(::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    super::ctor();
    this->deliverSocketToMe = deliverSocketToMe;
    this->options = options;
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingSocket::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    npc(deliverSocketToMe)->receiveResult(this, new SourceRouteManagerP2PSocket(sock, SourceRouteManagerImpl_AddressManager_this->SourceRouteManagerImpl_this->logger, SourceRouteManagerImpl_AddressManager_this->SourceRouteManagerImpl_this->errorHandler, SourceRouteManagerImpl_AddressManager_this->SourceRouteManagerImpl_this->environment));
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingSocket::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    npc(deliverSocketToMe)->receiveException(this, ex);
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingSocket::fail(::java::lang::Exception* ex)
{
    cancel();
    receiveException(static_cast< ::org::mpisws::p2p::transport::SocketRequestHandle* >(nullptr), ex);
}

bool org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingSocket::cancel()
{
    if(cancellable == nullptr) {
        return npc(SourceRouteManagerImpl_AddressManager_this->pendingSockets)->remove(static_cast< ::java::lang::Object* >(this));
    }
    return npc(cancellable)->cancel();
}

java::lang::Object* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingSocket::getIdentifier()
{
    return java_cast< ::java::lang::Object* >(SourceRouteManagerImpl_AddressManager_this->address);
}

java::util::Map* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingSocket::getOptions()
{
    return options;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingSocket::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.sourceroute.manager.SourceRouteManagerImpl.AddressManager.PendingSocket", 96);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingSocket::getClass0()
{
    return class_();
}

