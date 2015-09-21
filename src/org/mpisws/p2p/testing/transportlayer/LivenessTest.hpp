// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/LivenessTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/proximity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/SRTest.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::LivenessTest
    : public SRTest
{

public:
    typedef SRTest super;

private:
    static ::org::mpisws::p2p::transport::proximity::ProximityProvider* bob_prox_;
    static ::org::mpisws::p2p::transport::TransportLayer* dave_;
    static ::org::mpisws::p2p::transport::sourceroute::SourceRouteFactory* srFactory_;
    static ::rice::selector::Timer* timer_;

protected:
    void ctor();
    /*static ::org::mpisws::p2p::transport::TransportLayer* buildTL(::java::lang::String* name, ::java::net::InetAddress* addr, int32_t port, ::rice::environment::Environment* env); (private) */

public:
    static int32_t getDelay(::org::mpisws::p2p::transport::sourceroute::SourceRoute* a, ::org::mpisws::p2p::transport::sourceroute::SourceRoute* b);
    ::org::mpisws::p2p::transport::sourceroute::SourceRoute* getIdentifier(::org::mpisws::p2p::transport::TransportLayer* a, ::org::mpisws::p2p::transport::TransportLayer* b) override;
    static void setUpBeforeClass();
    virtual void testLiveness();
    virtual void testProximity();

    // Generated
    LivenessTest();
protected:
    LivenessTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* package */
    static ::org::mpisws::p2p::transport::proximity::ProximityProvider*& bob_prox();
    static ::org::mpisws::p2p::transport::TransportLayer*& dave();
    static ::org::mpisws::p2p::transport::sourceroute::SourceRouteFactory*& srFactory();
    static ::rice::selector::Timer*& timer();

private:
    virtual ::java::lang::Class* getClass0();
};
