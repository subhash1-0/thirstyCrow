// Generated from /pastry-2.1/src/rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.java
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_1::AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_1(AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3 *AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_this, ::org::mpisws::p2p::transport::P2PSocket* sock)
    : super(*static_cast< ::default_init_tag* >(0))
    , AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_this(AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_this)
    , sock(sock)
{
    clinit();
    ctor();
}

bool rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_1::cancel()
{
    npc(sock)->close();
    return true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_1::getClass0()
{
    return class_();
}

