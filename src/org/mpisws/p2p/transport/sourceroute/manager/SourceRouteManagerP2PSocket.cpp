// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerP2PSocket.java
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerP2PSocket.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>

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

org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerP2PSocket::SourceRouteManagerP2PSocket(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerP2PSocket::SourceRouteManagerP2PSocket(::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::logging::Logger* logger, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, ::rice::environment::Environment* env) 
    : SourceRouteManagerP2PSocket(*static_cast< ::default_init_tag* >(0))
{
    ctor(socket,logger,errorHandler,env);
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerP2PSocket::ctor(::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::logging::Logger* logger, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, ::rice::environment::Environment* env)
{
    super::ctor(java_cast< ::java::lang::Object* >(npc(java_cast< ::org::mpisws::p2p::transport::sourceroute::SourceRoute* >(npc(socket)->getIdentifier()))->getLastHop()), socket, logger, errorHandler, npc(socket)->getOptions());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerP2PSocket::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.sourceroute.manager.SourceRouteManagerP2PSocket", 72);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerP2PSocket::getClass0()
{
    return class_();
}

