// Generated from /pastry-2.1/src/rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/appsocket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/liveness/OverrideLiveness.hpp>

struct default_init_tag;

class rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getOverrideLiveness_2_2
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::liveness::OverrideLiveness
{

public:
    typedef ::java::lang::Object super;
    virtual void setLiveness(::org::mpisws::p2p::transport::sourceroute::SourceRoute* i, int32_t liveness, ::java::util::Map* options);

    // Generated
    AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getOverrideLiveness_2_2(AppSocketPastryNodeFactory_getLivenessTransportLayer_2 *AppSocketPastryNodeFactory_getLivenessTransportLayer_2_this);
    static ::java::lang::Class *class_();
    virtual void setLiveness(::java::lang::Object* i, int32_t liveness, ::java::util::Map* options) override;
    AppSocketPastryNodeFactory_getLivenessTransportLayer_2 *AppSocketPastryNodeFactory_getLivenessTransportLayer_2_this;

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
    friend class AppSocketPastryNodeFactory_getLivenessTransportLayer_2;
    friend class AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getLivenessProvider_2_1;
    friend class AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getPinger_2_3;
};
