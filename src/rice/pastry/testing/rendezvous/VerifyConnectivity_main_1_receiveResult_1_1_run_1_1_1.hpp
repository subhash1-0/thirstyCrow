// Generated from /pastry-2.1/src/rice/pastry/testing/rendezvous/VerifyConnectivity.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/networkinfo/ConnectivityResult.hpp>

struct default_init_tag;

class rice::pastry::testing::rendezvous::VerifyConnectivity_main_1_receiveResult_1_1_run_1_1_1
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::networkinfo::ConnectivityResult
{

public:
    typedef ::java::lang::Object super;
    void udpSuccess(::java::net::InetSocketAddress* from, ::java::util::Map* options) override;
    void tcpSuccess(::java::net::InetSocketAddress* from, ::java::util::Map* options) override;
    void receiveException(::java::lang::Exception* exception) override;

    // Generated
    VerifyConnectivity_main_1_receiveResult_1_1_run_1_1_1(VerifyConnectivity_main_1_receiveResult_1_1 *VerifyConnectivity_main_1_receiveResult_1_1_this);
    static ::java::lang::Class *class_();
    VerifyConnectivity_main_1_receiveResult_1_1 *VerifyConnectivity_main_1_receiveResult_1_1_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class VerifyConnectivity;
    friend class VerifyConnectivity_main_1;
    friend class VerifyConnectivity_main_1_receiveResult_1_1;
};
