// Generated from /pastry-2.1/src/rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.java

#pragma once

#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/wire/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/appsocket/fwd-pastry-2.1.hpp>
#include <rice/pastry/PastryNode.hpp>

struct default_init_tag;

class rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_BogusTLPastryNode
    : public ::rice::pastry::PastryNode
{

public:
    typedef ::rice::pastry::PastryNode super;
protected:
    void ctor(::rice::pastry::Id* id, ::rice::environment::Environment* e);

public:
    virtual ::org::mpisws::p2p::transport::TransportLayer* getWireTransportLayer(::org::mpisws::p2p::transport::wire::WireTransportLayerImpl* wtl);
    virtual void setLocalHandle(::rice::pastry::NodeHandle* localhandle);

    // Generated
    AppSocketPastryNodeFactory_BogusTLPastryNode(AppSocketPastryNodeFactory *AppSocketPastryNodeFactory_this, ::rice::pastry::Id* id, ::rice::environment::Environment* e);
protected:
    AppSocketPastryNodeFactory_BogusTLPastryNode(AppSocketPastryNodeFactory *AppSocketPastryNodeFactory_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    AppSocketPastryNodeFactory *AppSocketPastryNodeFactory_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class AppSocketPastryNodeFactory;
    friend class AppSocketPastryNodeFactory_AppSocketFactoryLayer;
    friend class AppSocketPastryNodeFactory_AppSocketFactoryLayer_openSocket_1;
    friend class AppSocketPastryNodeFactory_getSocketFactory_1;
    friend class AppSocketPastryNodeFactory_getSocketFactory_1_getAppSocket_1_1;
    friend class AppSocketPastryNodeFactory_getSocketFactory_1_getSocketChannel_1_2;
    friend class AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3;
    friend class AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_1;
    friend class AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_2;
    friend class AppSocketPastryNodeFactory_getLivenessTransportLayer_2;
    friend class AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getLivenessProvider_2_1;
    friend class AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getOverrideLiveness_2_2;
    friend class AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getPinger_2_3;
};
