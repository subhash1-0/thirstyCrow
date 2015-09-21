// Generated from /pastry-2.1/src/rice/pastry/testing/rendezvous/VerifyConnectivity.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::pastry::testing::rendezvous::VerifyConnectivity_main_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    virtual void receiveResult(::java::net::InetAddress* result);
    virtual void receiveException(::java::io::IOException* exception);

    // Generated
    VerifyConnectivity_main_1(int32_t externalPort, ::rice::pastry::socket::SocketPastryNodeFactory* factory, ::rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifier* verifier, ::java::net::InetSocketAddress* bootaddress, ::rice::environment::Environment* env);
    static ::java::lang::Class *class_();
    virtual void receiveException(::java::lang::Exception* exception) override;
    virtual void receiveResult(::java::lang::Object* result) override;
    int32_t externalPort;
    ::rice::pastry::socket::SocketPastryNodeFactory* factory;
    ::rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifier* verifier;
    ::java::net::InetSocketAddress* bootaddress;
    ::rice::environment::Environment* env;

private:
    virtual ::java::lang::Class* getClass0();
    friend class VerifyConnectivity;
    friend class VerifyConnectivity_main_1_receiveResult_1_1;
    friend class VerifyConnectivity_main_1_receiveResult_1_1_run_1_1_1;
};
