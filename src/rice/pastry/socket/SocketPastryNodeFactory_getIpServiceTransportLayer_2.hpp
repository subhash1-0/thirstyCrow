// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/networkinfo/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/NodeHandleFetcher.hpp>

struct default_init_tag;

class rice::pastry::socket::SocketPastryNodeFactory_getIpServiceTransportLayer_2
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::NodeHandleFetcher
{

public:
    typedef ::java::lang::Object super;
    ::rice::p2p::commonapi::Cancellable* getNodeHandle(::java::lang::Object* o, ::rice::Continuation* c) override;

    // Generated
    SocketPastryNodeFactory_getIpServiceTransportLayer_2(SocketPastryNodeFactory *SocketPastryNodeFactory_this, ::org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer* ipTL, ::rice::pastry::PastryNode* pn);
    static ::java::lang::Class *class_();
    SocketPastryNodeFactory *SocketPastryNodeFactory_this;
    ::org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer* ipTL;
    ::rice::pastry::PastryNode* pn;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SocketPastryNodeFactory;
    friend class SocketPastryNodeFactory_TransLiveness;
    friend class SocketPastryNodeFactory_TransLivenessProximity;
    friend class SocketPastryNodeFactory_getSocketCountListener_1;
    friend class SocketPastryNodeFactory_getIpServiceTransportLayer_2_getNodeHandle_2_1;
    friend class SocketPastryNodeFactory_getIdentityImpl_3;
    friend class SocketPastryNodeFactory_getIdentityImpl_4;
    friend class SocketPastryNodeFactory_getLivenessTransportLayer_5;
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
