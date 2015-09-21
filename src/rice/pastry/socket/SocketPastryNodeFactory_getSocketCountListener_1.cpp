// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java
#include <rice/pastry/socket/SocketPastryNodeFactory_getSocketCountListener_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::SocketPastryNodeFactory_getSocketCountListener_1::SocketPastryNodeFactory_getSocketCountListener_1(SocketPastryNodeFactory *SocketPastryNodeFactory_this, ::rice::pastry::PastryNode* pn)
    : super(*static_cast< ::default_init_tag* >(0))
    , SocketPastryNodeFactory_this(SocketPastryNodeFactory_this)
    , pn(pn)
{
    clinit();
    ctor();
}

void rice::pastry::socket::SocketPastryNodeFactory_getSocketCountListener_1::socketOpened(::java::net::InetSocketAddress* i, ::java::util::Map* options, bool outgoing)
{
    npc(pn)->broadcastChannelOpened(i, 0);
}

void rice::pastry::socket::SocketPastryNodeFactory_getSocketCountListener_1::socketOpened(::java::lang::Object* i, ::java::util::Map* options, bool outgoing)
{ 
    socketOpened(dynamic_cast< ::java::net::InetSocketAddress* >(i), options, outgoing);
}

void rice::pastry::socket::SocketPastryNodeFactory_getSocketCountListener_1::socketClosed(::java::net::InetSocketAddress* i, ::java::util::Map* options)
{
    npc(pn)->broadcastChannelClosed(i);
}

void rice::pastry::socket::SocketPastryNodeFactory_getSocketCountListener_1::socketClosed(::java::lang::Object* i, ::java::util::Map* options)
{ 
    socketClosed(dynamic_cast< ::java::net::InetSocketAddress* >(i), options);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_getSocketCountListener_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_getSocketCountListener_1::getClass0()
{
    return class_();
}

