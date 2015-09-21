// Generated from /pastry-2.1/src/rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/appsocket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>

struct default_init_tag;

class rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getLivenessProvider_2_1
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::liveness::LivenessProvider
{

public:
    typedef ::java::lang::Object super;
    void addLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name) override;
    virtual bool checkLiveness(::org::mpisws::p2p::transport::sourceroute::SourceRoute* i, ::java::util::Map* options);
    virtual void clearState(::org::mpisws::p2p::transport::sourceroute::SourceRoute* i);
    virtual int32_t getLiveness(::org::mpisws::p2p::transport::sourceroute::SourceRoute* i, ::java::util::Map* options);
    bool removeLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name) override;

    // Generated
    AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getLivenessProvider_2_1(AppSocketPastryNodeFactory_getLivenessTransportLayer_2 *AppSocketPastryNodeFactory_getLivenessTransportLayer_2_this);
    static ::java::lang::Class *class_();
    virtual bool checkLiveness(::java::lang::Object* i, ::java::util::Map* options) override;
    virtual void clearState(::java::lang::Object* i) override;
    virtual int32_t getLiveness(::java::lang::Object* i, ::java::util::Map* options) override;
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
    friend class AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getOverrideLiveness_2_2;
    friend class AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getPinger_2_3;
};
