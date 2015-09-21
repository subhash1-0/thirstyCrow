// Generated from /pastry-2.1/src/rice/pastry/testing/rendezvous/VerifyConnectivity.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class rice::pastry::testing::rendezvous::VerifyConnectivity_main_1_receiveResult_1_1
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;

    // Generated
    VerifyConnectivity_main_1_receiveResult_1_1(VerifyConnectivity_main_1 *VerifyConnectivity_main_1_this, ::java::net::InetAddress* result, int32_t externalPort, ::rice::pastry::socket::SocketPastryNodeFactory* factory, ::rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifier* verifier, ::java::net::InetSocketAddress* bootaddress);
    static ::java::lang::Class *class_();
    VerifyConnectivity_main_1 *VerifyConnectivity_main_1_this;
    ::java::net::InetAddress* result;
    int32_t externalPort;
    ::rice::pastry::socket::SocketPastryNodeFactory* factory;
    ::rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifier* verifier;
    ::java::net::InetSocketAddress* bootaddress;

private:
    virtual ::java::lang::Class* getClass0();
    friend class VerifyConnectivity;
    friend class VerifyConnectivity_main_1;
    friend class VerifyConnectivity_main_1_receiveResult_1_1_run_1_1_1;
};
