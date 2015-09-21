// Generated from /pastry-2.1/src/rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.java

#pragma once

#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/appsocket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_TransLiveness.hpp>

struct default_init_tag;

class rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::socket::SocketPastryNodeFactory_TransLiveness
{

public:
    typedef ::java::lang::Object super;
    ::org::mpisws::p2p::transport::TransportLayer* getTransportLayer() override;
    ::org::mpisws::p2p::transport::liveness::LivenessProvider* getLivenessProvider() override;
    ::org::mpisws::p2p::transport::liveness::OverrideLiveness* getOverrideLiveness() override;
    ::org::mpisws::p2p::transport::liveness::Pinger* getPinger() override;

    // Generated
    AppSocketPastryNodeFactory_getLivenessTransportLayer_2(AppSocketPastryNodeFactory *AppSocketPastryNodeFactory_this, ::org::mpisws::p2p::transport::TransportLayer* tl);
    static ::java::lang::Class *class_();
    AppSocketPastryNodeFactory *AppSocketPastryNodeFactory_this;
    ::org::mpisws::p2p::transport::TransportLayer* tl;

private:
    virtual ::java::lang::Class* getClass0();
    friend class AppSocketPastryNodeFactory;
    friend class AppSocketPastryNodeFactory_AppSocketFactoryLayer;
    friend class AppSocketPastryNodeFactory_AppSocketFactoryLayer_openSocket_1;
    friend class AppSocketPastryNodeFactory_BogusTLPastryNode;
    friend class AppSocketPastryNodeFactory_getSocketFactory_1;
    friend class AppSocketPastryNodeFactory_getSocketFactory_1_getAppSocket_1_1;
    friend class AppSocketPastryNodeFactory_getSocketFactory_1_getSocketChannel_1_2;
    friend class AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3;
    friend class AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_1;
    friend class AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_2;
    friend class AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getLivenessProvider_2_1;
    friend class AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getOverrideLiveness_2_2;
    friend class AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getPinger_2_3;
};
