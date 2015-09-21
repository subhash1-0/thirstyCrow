// Generated from /pastry-2.1/src/rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.java
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getSocketFactory_1_getAppSocket_1_1.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <rice/Continuation.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getSocketFactory_1.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.hpp>
#include <rice/pastry/transport/SocketAdapter.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getAppSocket_1_1::AppSocketPastryNodeFactory_getSocketFactory_1_getAppSocket_1_1(AppSocketPastryNodeFactory_getSocketFactory_1 *AppSocketPastryNodeFactory_getSocketFactory_1_this, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , AppSocketPastryNodeFactory_getSocketFactory_1_this(AppSocketPastryNodeFactory_getSocketFactory_1_this)
    , c(c)
{
    clinit();
    ctor();
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getAppSocket_1_1::receiveException(::java::lang::Exception* exception)
{
    npc(c)->receiveException(exception);
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getAppSocket_1_1::receiveResult(::org::mpisws::p2p::transport::P2PSocket* result)
{
    npc(c)->receiveResult(new ::rice::pastry::transport::SocketAdapter(result, AppSocketPastryNodeFactory_getSocketFactory_1_this->AppSocketPastryNodeFactory_this->environment));
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getAppSocket_1_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::org::mpisws::p2p::transport::P2PSocket* >(result));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getAppSocket_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getAppSocket_1_1::getClass0()
{
    return class_();
}

