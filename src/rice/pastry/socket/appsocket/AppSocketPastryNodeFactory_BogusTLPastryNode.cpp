// Generated from /pastry-2.1/src/rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.java
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_BogusTLPastryNode.hpp>

#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_AppSocketFactoryLayer.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.hpp>

rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_BogusTLPastryNode::AppSocketPastryNodeFactory_BogusTLPastryNode(AppSocketPastryNodeFactory *AppSocketPastryNodeFactory_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , AppSocketPastryNodeFactory_this(AppSocketPastryNodeFactory_this)
{
    clinit();
}

rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_BogusTLPastryNode::AppSocketPastryNodeFactory_BogusTLPastryNode(AppSocketPastryNodeFactory *AppSocketPastryNodeFactory_this, ::rice::pastry::Id* id, ::rice::environment::Environment* e) 
    : AppSocketPastryNodeFactory_BogusTLPastryNode(AppSocketPastryNodeFactory_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(id,e);
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_BogusTLPastryNode::ctor(::rice::pastry::Id* id, ::rice::environment::Environment* e)
{
    super::ctor(id, e);
}

org::mpisws::p2p::transport::TransportLayer* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_BogusTLPastryNode::getWireTransportLayer(::org::mpisws::p2p::transport::wire::WireTransportLayerImpl* wtl)
{
    return new AppSocketPastryNodeFactory_AppSocketFactoryLayer(AppSocketPastryNodeFactory_this, wtl);
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_BogusTLPastryNode::setLocalHandle(::rice::pastry::NodeHandle* localhandle)
{
    this->localhandle = localhandle;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_BogusTLPastryNode::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.appsocket.AppSocketPastryNodeFactory.BogusTLPastryNode", 73);
    return c;
}

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_BogusTLPastryNode::getClass0()
{
    return class_();
}

