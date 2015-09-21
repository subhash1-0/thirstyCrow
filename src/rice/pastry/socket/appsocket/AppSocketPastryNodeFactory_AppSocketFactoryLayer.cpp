// Generated from /pastry-2.1/src/rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.java
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_AppSocketFactoryLayer.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/wire/WireTransportLayerImpl.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_AppSocketFactoryLayer_openSocket_1.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer::AppSocketPastryNodeFactory_AppSocketFactoryLayer(AppSocketPastryNodeFactory *AppSocketPastryNodeFactory_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , AppSocketPastryNodeFactory_this(AppSocketPastryNodeFactory_this)
{
    clinit();
}

rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer::AppSocketPastryNodeFactory_AppSocketFactoryLayer(AppSocketPastryNodeFactory *AppSocketPastryNodeFactory_this, ::org::mpisws::p2p::transport::wire::WireTransportLayerImpl* wtl) 
    : AppSocketPastryNodeFactory_AppSocketFactoryLayer(AppSocketPastryNodeFactory_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(wtl);
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer::ctor(::org::mpisws::p2p::transport::wire::WireTransportLayerImpl* wtl)
{
    super::ctor();
    this->wtl = wtl;
    npc(this->wtl)->setCallback(static_cast< ::org::mpisws::p2p::transport::TransportLayerCallback* >(this));
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer::acceptMessages(bool b)
{
    npc(wtl)->acceptMessages(b);
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer::acceptSockets(bool b)
{
    npc(wtl)->acceptSockets(b);
}

java::net::InetSocketAddress* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer::getLocalIdentifier()
{
    return npc(wtl)->getLocalIdentifier();
}

org::mpisws::p2p::transport::SocketRequestHandle* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer::openSocket(::java::net::InetSocketAddress* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    return npc(wtl)->openSocket(i, static_cast< ::org::mpisws::p2p::transport::SocketCallback* >(new AppSocketPastryNodeFactory_AppSocketFactoryLayer_openSocket_1(this, options, deliverSocketToMe)), options);
}

org::mpisws::p2p::transport::SocketRequestHandle* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{ 
    return openSocket(dynamic_cast< ::java::net::InetSocketAddress* >(i), dynamic_cast< ::org::mpisws::p2p::transport::SocketCallback* >(deliverSocketToMe), options);
}

org::mpisws::p2p::transport::MessageRequestHandle* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer::sendMessage(::java::net::InetSocketAddress* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    return npc(wtl)->sendMessage(i, m, deliverAckToMe, options);
}

org::mpisws::p2p::transport::MessageRequestHandle* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< ::java::net::InetSocketAddress* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    npc(callback)->incomingSocket(s);
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer::messageReceived(::java::net::InetSocketAddress* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */
{
    npc(callback)->messageReceived(i, m, options);
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< ::java::net::InetSocketAddress* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), options);
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer::destroy()
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.appsocket.AppSocketPastryNodeFactory.AppSocketFactoryLayer", 77);
    return c;
}

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer::getClass0()
{
    return class_();
}

