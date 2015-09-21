// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java
#include <rice/pastry/socket/SocketPastryNodeFactory_getIdentityImpl_4.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/socket/TransportLayerNodeHandle.hpp>

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

rice::pastry::socket::SocketPastryNodeFactory_getIdentityImpl_4::SocketPastryNodeFactory_getIdentityImpl_4(SocketPastryNodeFactory *SocketPastryNodeFactory_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , SocketPastryNodeFactory_this(SocketPastryNodeFactory_this)
{
    clinit();
    ctor();
}

bool rice::pastry::socket::SocketPastryNodeFactory_getIdentityImpl_4::isSane(TransportLayerNodeHandle* upper, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* middle)
{
    return npc(java_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(npc(upper)->getAddress()))->equals(static_cast< ::java::lang::Object* >(middle));
}

bool rice::pastry::socket::SocketPastryNodeFactory_getIdentityImpl_4::isSane(::java::lang::Object* upper, ::java::lang::Object* middle)
{ 
    return isSane(dynamic_cast< TransportLayerNodeHandle* >(upper), dynamic_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(middle));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_getIdentityImpl_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_getIdentityImpl_4::getClass0()
{
    return class_();
}

