// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl.java
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl_AddressManager_openSocket_2.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl_AddressManager.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerP2PSocket.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_openSocket_2::SourceRouteManagerImpl_AddressManager_openSocket_2(SourceRouteManagerImpl_AddressManager *SourceRouteManagerImpl_AddressManager_this, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* handle)
    : super(*static_cast< ::default_init_tag* >(0))
    , SourceRouteManagerImpl_AddressManager_this(SourceRouteManagerImpl_AddressManager_this)
    , deliverSocketToMe(deliverSocketToMe)
    , handle(handle)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_openSocket_2::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    npc(deliverSocketToMe)->receiveResult(handle, new SourceRouteManagerP2PSocket(sock, SourceRouteManagerImpl_AddressManager_this->SourceRouteManagerImpl_this->logger, SourceRouteManagerImpl_AddressManager_this->SourceRouteManagerImpl_this->errorHandler, SourceRouteManagerImpl_AddressManager_this->SourceRouteManagerImpl_this->environment));
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_openSocket_2::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    npc(deliverSocketToMe)->receiveException(handle, ex);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_openSocket_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_openSocket_2::getClass0()
{
    return class_();
}

