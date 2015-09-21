// Generated from /pastry-2.1/src/rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.java
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getSocketFactory_1_getSocketChannel_1_2.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/nio/channels/SocketChannel.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/wire/SocketManager.hpp>
#include <rice/Continuation.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getSocketFactory_1.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.hpp>

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

rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getSocketChannel_1_2::AppSocketPastryNodeFactory_getSocketFactory_1_getSocketChannel_1_2(AppSocketPastryNodeFactory_getSocketFactory_1 *AppSocketPastryNodeFactory_getSocketFactory_1_this, ::rice::Continuation* c, int32_t myUid)
    : super(*static_cast< ::default_init_tag* >(0))
    , AppSocketPastryNodeFactory_getSocketFactory_1_this(AppSocketPastryNodeFactory_getSocketFactory_1_this)
    , c(c)
    , myUid(myUid)
{
    clinit();
    ctor();
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getSocketChannel_1_2::receiveException(::java::lang::Exception* exception)
{
    npc(c)->receiveException(exception);
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getSocketChannel_1_2::receiveResult(::org::mpisws::p2p::transport::P2PSocket* result)
{
    auto sm = java_cast< ::org::mpisws::p2p::transport::wire::SocketManager* >(npc(AppSocketPastryNodeFactory_getSocketFactory_1_this->AppSocketPastryNodeFactory_this->socketTable)->remove(::java::lang::Integer::valueOf(myUid)));
    auto ret = npc(sm)->getSocketChannel();
    npc(c)->receiveResult(ret);
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getSocketChannel_1_2::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::org::mpisws::p2p::transport::P2PSocket* >(result));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getSocketChannel_1_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getSocketChannel_1_2::getClass0()
{
    return class_();
}

