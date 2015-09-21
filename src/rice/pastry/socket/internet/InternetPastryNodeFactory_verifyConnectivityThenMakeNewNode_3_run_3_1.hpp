// Generated from /pastry-2.1/src/rice/pastry/socket/internet/InternetPastryNodeFactory.java

#pragma once

#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/internet/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class rice::pastry::socket::internet::InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3_run_3_1
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;
    void run() override;

    // Generated
    InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3_run_3_1(InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3 *InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3_this, ::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::rice::Continuation* deliverResultToMe);
    static ::java::lang::Class *class_();
    InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3 *InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3_this;
    ::rice::pastry::Id* nodeId;
    ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress;
    ::rice::Continuation* deliverResultToMe;

private:
    virtual ::java::lang::Class* getClass0();
    friend class InternetPastryNodeFactory;
    friend class InternetPastryNodeFactory_findExternalNodes_1;
    friend class InternetPastryNodeFactory_findExternalAddressHelper_2;
    friend class InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3;
    friend class InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_4;
};
