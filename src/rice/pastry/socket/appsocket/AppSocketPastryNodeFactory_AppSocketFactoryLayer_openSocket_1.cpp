// Generated from /pastry-2.1/src/rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.java
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_AppSocketFactoryLayer_openSocket_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/wire/SocketManager.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_AppSocketFactoryLayer.hpp>
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

rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer_openSocket_1::AppSocketPastryNodeFactory_AppSocketFactoryLayer_openSocket_1(AppSocketPastryNodeFactory_AppSocketFactoryLayer *AppSocketPastryNodeFactory_AppSocketFactoryLayer_this, ::java::util::Map* options, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , AppSocketPastryNodeFactory_AppSocketFactoryLayer_this(AppSocketPastryNodeFactory_AppSocketFactoryLayer_this)
    , options(options)
    , deliverSocketToMe(deliverSocketToMe)
{
    clinit();
    ctor();
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer_openSocket_1::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    auto sa = java_cast< ::org::mpisws::p2p::transport::wire::SocketManager* >(sock);
    if(npc(options)->containsKey(AppSocketPastryNodeFactory::STORE_SOCKET())) {
        npc(AppSocketPastryNodeFactory_AppSocketFactoryLayer_this->AppSocketPastryNodeFactory_this->socketTable)->put(java_cast< ::java::lang::Integer* >(java_cast< ::java::lang::Object* >(npc(options)->get(AppSocketPastryNodeFactory::STORE_SOCKET()))), sa);
    }
    npc(deliverSocketToMe)->receiveResult(cancellable, sock);
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer_openSocket_1::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    npc(deliverSocketToMe)->receiveException(s, ex);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer_openSocket_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer_openSocket_1::getClass0()
{
    return class_();
}

