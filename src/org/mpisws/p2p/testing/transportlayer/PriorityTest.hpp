// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/PriorityTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/TLTest.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::PriorityTest
    : public TLTest
{

public:
    typedef TLTest super;

protected:
    void ctor();

public:
    virtual void bogus();
    /*static ::org::mpisws::p2p::transport::TransportLayer* buildTL(::java::lang::String* name, ::java::net::InetAddress* addr, int32_t port, ::rice::environment::Environment* env); (private) */
    virtual ::java::net::InetSocketAddress* getBogusIdentifier(::java::net::InetSocketAddress* local);
    virtual void queueOverflow();
    static void setUpBeforeClass();

    // Generated
    PriorityTest();
protected:
    PriorityTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual ::java::lang::Object* getBogusIdentifier(::java::lang::Object* local) override;

private:
    virtual ::java::lang::Class* getClass0();
};
