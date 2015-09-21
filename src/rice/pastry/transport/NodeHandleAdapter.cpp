// Generated from /pastry-2.1/src/rice/pastry/transport/NodeHandleAdapter.java
#include <rice/pastry/transport/NodeHandleAdapter.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessListener.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityListener.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityProvider.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>
#include <rice/pastry/NodeHandle.hpp>

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

rice::pastry::transport::NodeHandleAdapter::NodeHandleAdapter(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::transport::NodeHandleAdapter::NodeHandleAdapter(::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider, ::org::mpisws::p2p::transport::proximity::ProximityProvider* proxProvider) 
    : NodeHandleAdapter(*static_cast< ::default_init_tag* >(0))
{
    ctor(tl,livenessProvider,proxProvider);
}

void rice::pastry::transport::NodeHandleAdapter::ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider, ::org::mpisws::p2p::transport::proximity::ProximityProvider* proxProvider)
{
    super::ctor();
    this->tl = tl;
    this->livenessProvider = livenessProvider;
    this->proxProvider = proxProvider;
}

void rice::pastry::transport::NodeHandleAdapter::acceptMessages(bool b)
{
    npc(tl)->acceptMessages(b);
}

void rice::pastry::transport::NodeHandleAdapter::acceptSockets(bool b)
{
    npc(tl)->acceptSockets(b);
}

rice::pastry::NodeHandle* rice::pastry::transport::NodeHandleAdapter::getLocalIdentifier()
{
    return java_cast< ::rice::pastry::NodeHandle* >(java_cast< ::java::lang::Object* >(npc(tl)->getLocalIdentifier()));
}

org::mpisws::p2p::transport::SocketRequestHandle* rice::pastry::transport::NodeHandleAdapter::openSocket(::rice::pastry::NodeHandle* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    return npc(tl)->openSocket(i, deliverSocketToMe, options);
}

org::mpisws::p2p::transport::SocketRequestHandle* rice::pastry::transport::NodeHandleAdapter::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{ 
    return openSocket(dynamic_cast< ::rice::pastry::NodeHandle* >(i), dynamic_cast< ::org::mpisws::p2p::transport::SocketCallback* >(deliverSocketToMe), options);
}

org::mpisws::p2p::transport::MessageRequestHandle* rice::pastry::transport::NodeHandleAdapter::sendMessage(::rice::pastry::NodeHandle* i, ::rice::p2p::commonapi::rawserialization::RawMessage* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    return npc(tl)->sendMessage(i, m, deliverAckToMe, options);
}

org::mpisws::p2p::transport::MessageRequestHandle* rice::pastry::transport::NodeHandleAdapter::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< ::rice::pastry::NodeHandle* >(i), dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(m), dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

void rice::pastry::transport::NodeHandleAdapter::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    npc(tl)->setCallback(callback);
}

void rice::pastry::transport::NodeHandleAdapter::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    npc(tl)->setErrorHandler(handler);
}

void rice::pastry::transport::NodeHandleAdapter::destroy()
{
    npc(tl)->destroy();
}

void rice::pastry::transport::NodeHandleAdapter::addLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name)
{
    npc(livenessProvider)->addLivenessListener(name);
}

bool rice::pastry::transport::NodeHandleAdapter::checkLiveness(::rice::pastry::NodeHandle* i, ::java::util::Map* options)
{
    return npc(livenessProvider)->checkLiveness(i, options);
}

bool rice::pastry::transport::NodeHandleAdapter::checkLiveness(::java::lang::Object* i, ::java::util::Map* options)
{ 
    return checkLiveness(dynamic_cast< ::rice::pastry::NodeHandle* >(i), options);
}

int32_t rice::pastry::transport::NodeHandleAdapter::getLiveness(::rice::pastry::NodeHandle* i, ::java::util::Map* options)
{
    return npc(livenessProvider)->getLiveness(i, options);
}

int32_t rice::pastry::transport::NodeHandleAdapter::getLiveness(::java::lang::Object* i, ::java::util::Map* options)
{ 
    return getLiveness(dynamic_cast< ::rice::pastry::NodeHandle* >(i), options);
}

bool rice::pastry::transport::NodeHandleAdapter::removeLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name)
{
    return npc(livenessProvider)->removeLivenessListener(name);
}

void rice::pastry::transport::NodeHandleAdapter::addProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* listener)
{
    npc(proxProvider)->addProximityListener(listener);
}

int32_t rice::pastry::transport::NodeHandleAdapter::proximity(::rice::pastry::NodeHandle* i, ::java::util::Map* options)
{
    return npc(proxProvider)->proximity(i, options);
}

int32_t rice::pastry::transport::NodeHandleAdapter::proximity(::java::lang::Object* i, ::java::util::Map* options)
{ 
    return proximity(dynamic_cast< ::rice::pastry::NodeHandle* >(i), options);
}

bool rice::pastry::transport::NodeHandleAdapter::removeProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* listener)
{
    return npc(proxProvider)->removeProximityListener(listener);
}

org::mpisws::p2p::transport::TransportLayer* rice::pastry::transport::NodeHandleAdapter::getTL()
{
    return tl;
}

void rice::pastry::transport::NodeHandleAdapter::clearState(::rice::pastry::NodeHandle* i)
{
    npc(livenessProvider)->clearState(i);
}

void rice::pastry::transport::NodeHandleAdapter::clearState(::java::lang::Object* i)
{ 
    clearState(dynamic_cast< ::rice::pastry::NodeHandle* >(i));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::transport::NodeHandleAdapter::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.transport.NodeHandleAdapter", 39);
    return c;
}

java::lang::Class* rice::pastry::transport::NodeHandleAdapter::getClass0()
{
    return class_();
}

