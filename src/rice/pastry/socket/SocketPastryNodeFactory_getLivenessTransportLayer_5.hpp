// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java

#pragma once

#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_TransLiveness.hpp>

struct default_init_tag;

class rice::pastry::socket::SocketPastryNodeFactory_getLivenessTransportLayer_5
    : public virtual ::java::lang::Object
    , public virtual SocketPastryNodeFactory_TransLiveness
{

public:
    typedef ::java::lang::Object super;
    ::org::mpisws::p2p::transport::TransportLayer* getTransportLayer() override;
    ::org::mpisws::p2p::transport::liveness::LivenessProvider* getLivenessProvider() override;
    ::org::mpisws::p2p::transport::liveness::OverrideLiveness* getOverrideLiveness() override;
    ::org::mpisws::p2p::transport::liveness::Pinger* getPinger() override;

    // Generated
    SocketPastryNodeFactory_getLivenessTransportLayer_5(SocketPastryNodeFactory *SocketPastryNodeFactory_this, ::org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl* ltl);
    static ::java::lang::Class *class_();
    SocketPastryNodeFactory *SocketPastryNodeFactory_this;
    ::org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl* ltl;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SocketPastryNodeFactory;
    friend class SocketPastryNodeFactory_TransLiveness;
    friend class SocketPastryNodeFactory_TransLivenessProximity;
    friend class SocketPastryNodeFactory_getSocketCountListener_1;
    friend class SocketPastryNodeFactory_getIpServiceTransportLayer_2;
    friend class SocketPastryNodeFactory_getIpServiceTransportLayer_2_getNodeHandle_2_1;
    friend class SocketPastryNodeFactory_getIdentityImpl_3;
    friend class SocketPastryNodeFactory_getIdentityImpl_4;
    friend class SocketPastryNodeFactory_getSourceRouteManagerLayer_6;
    friend class SocketPastryNodeFactory_getUpperIdentityLayer_7;
    friend class SocketPastryNodeFactory_getCommonAPITransportLayer_8;
    friend class SocketPastryNodeFactory_getCommonAPITransportLayer_9;
    friend class SocketPastryNodeFactory_getOptionsAdder_10;
    friend class SocketPastryNodeFactory_TLBootstrapper;
    friend class SocketPastryNodeFactory_TLBootstrapper_boot_1;
    friend class SocketPastryNodeFactory_TLBootstrapper_boot_1_receiveResult_1_1;
    friend class SocketPastryNodeFactory_TLBootstrapper_boot_2;
    friend class SocketPastryNodeFactory_TLBootstrapper_boot_3;
    friend class SocketPastryNodeFactory_TLBootstrapper_boot_4;
    friend class SocketPastryNodeFactory_newNode_11;
    friend class SocketPastryNodeFactory_newNode_11_run_11_1;
};
