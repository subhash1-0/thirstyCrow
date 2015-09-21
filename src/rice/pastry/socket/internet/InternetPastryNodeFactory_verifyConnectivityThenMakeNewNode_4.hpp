// Generated from /pastry-2.1/src/rice/pastry/socket/internet/InternetPastryNodeFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/internet/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/networkinfo/ConnectivityResult.hpp>

struct default_init_tag;

class rice::pastry::socket::internet::InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_4
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::networkinfo::ConnectivityResult
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    bool udpSuccess_ {  };
    bool tcpSuccess_ {  };

public:
    void udpSuccess(::java::net::InetSocketAddress* from, ::java::util::Map* options) override;
    void tcpSuccess(::java::net::InetSocketAddress* from, ::java::util::Map* options) override;
    virtual void complete();
    void receiveException(::java::lang::Exception* e) override;

    // Generated
    InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_4(InternetPastryNodeFactory *InternetPastryNodeFactory_this, ::boolArray* timeout, ::rice::selector::TimerTask* timer, ::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::rice::Continuation* deliverResultToMe);
    static ::java::lang::Class *class_();

private:
    void init();
    InternetPastryNodeFactory *InternetPastryNodeFactory_this;
    ::boolArray* timeout;
    ::rice::selector::TimerTask* timer;
    ::rice::pastry::Id* nodeId;
    ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress;
    ::rice::Continuation* deliverResultToMe;
    virtual ::java::lang::Class* getClass0();
    friend class InternetPastryNodeFactory;
    friend class InternetPastryNodeFactory_findExternalNodes_1;
    friend class InternetPastryNodeFactory_findExternalAddressHelper_2;
    friend class InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3;
    friend class InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3_run_3_1;
};
