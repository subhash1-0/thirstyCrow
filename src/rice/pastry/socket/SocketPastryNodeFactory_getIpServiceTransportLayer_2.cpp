// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java
#include <rice/pastry/socket/SocketPastryNodeFactory_getIpServiceTransportLayer_2.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_getIpServiceTransportLayer_2_getNodeHandle_2_1.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>

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

rice::pastry::socket::SocketPastryNodeFactory_getIpServiceTransportLayer_2::SocketPastryNodeFactory_getIpServiceTransportLayer_2(SocketPastryNodeFactory *SocketPastryNodeFactory_this, ::org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer* ipTL, ::rice::pastry::PastryNode* pn)
    : super(*static_cast< ::default_init_tag* >(0))
    , SocketPastryNodeFactory_this(SocketPastryNodeFactory_this)
    , ipTL(ipTL)
    , pn(pn)
{
    clinit();
    ctor();
}

rice::p2p::commonapi::Cancellable* rice::pastry::socket::SocketPastryNodeFactory_getIpServiceTransportLayer_2::getNodeHandle(::java::lang::Object* o, ::rice::Continuation* c)
{
    auto addr = java_cast< ::java::net::InetSocketAddress* >(o);
    return npc(ipTL)->getId(addr, SocketPastryNodeFactory::NETWORK_INFO_NODE_HANDLE_INDEX, new SocketPastryNodeFactory_getIpServiceTransportLayer_2_getNodeHandle_2_1(this, pn, c), nullptr);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_getIpServiceTransportLayer_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_getIpServiceTransportLayer_2::getClass0()
{
    return class_();
}

