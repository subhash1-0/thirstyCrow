// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/SRManagerTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/proximity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/TLTest.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::SRManagerTest
    : public TLTest
{

public:
    typedef TLTest super;

private:
    static ::int8_tArray* GOOD_HDR_;
    static ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* alice_addr_;
    static ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* bob_addr_;
    static ::org::mpisws::p2p::transport::proximity::ProximityProvider* bob_prox_;
    static ::org::mpisws::p2p::transport::TransportLayer* carol_;
    static ::org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayer* carol_tap_;
    static ::org::mpisws::p2p::transport::TransportLayer* dave_;
    static ::org::mpisws::p2p::transport::sourceroute::SourceRouteFactory* srFactory_;
    static ::rice::selector::Timer* timer_;

protected:
    void ctor();
    /*static ::org::mpisws::p2p::transport::TransportLayer* buildTL(::java::lang::String* name, ::java::net::InetAddress* addr, int32_t port, ::rice::environment::Environment* env); (private) */

public: /* package */
    static bool connectionAllowed(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* a, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* b, ::java::lang::String* context);

public:
    virtual ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* getBogusIdentifier(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local);
    static int32_t getDelay(::org::mpisws::p2p::transport::sourceroute::SourceRoute* a, ::org::mpisws::p2p::transport::sourceroute::SourceRoute* b);
    static void setUpBeforeClass();
    virtual void testLiveness();
    virtual void testProximity();

    // Generated
    SRManagerTest();
protected:
    SRManagerTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual ::java::lang::Object* getBogusIdentifier(::java::lang::Object* local) override;
    static ::int8_tArray*& GOOD_HDR();

public: /* package */
    static ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress*& alice_addr();
    static ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress*& bob_addr();
    static ::org::mpisws::p2p::transport::proximity::ProximityProvider*& bob_prox();
    static ::org::mpisws::p2p::transport::TransportLayer*& carol();
    static ::org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayer*& carol_tap();
    static ::org::mpisws::p2p::transport::TransportLayer*& dave();
    static ::org::mpisws::p2p::transport::sourceroute::SourceRouteFactory*& srFactory();
    static ::rice::selector::Timer*& timer();

private:
    virtual ::java::lang::Class* getClass0();
};
