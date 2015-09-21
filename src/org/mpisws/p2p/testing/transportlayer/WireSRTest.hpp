// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/WireSRTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/TLTest.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::WireSRTest
    : public TLTest
{

public:
    typedef TLTest super;

private:
    static ::int8_tArray* GOOD_HDR_;
    static ::org::mpisws::p2p::transport::TransportLayer* carol_;
    static ::org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayer* carol_tap_;
    static ::org::mpisws::p2p::transport::sourceroute::SourceRouteFactory* srFactory_;

protected:
    void ctor();
    /*static ::org::mpisws::p2p::transport::TransportLayer* buildTL(::java::lang::String* name, ::java::net::InetAddress* addr, int32_t port, ::rice::environment::Environment* env); (private) */

public:
    virtual ::org::mpisws::p2p::transport::sourceroute::SourceRoute* getBogusIdentifier(::org::mpisws::p2p::transport::sourceroute::SourceRoute* local);
    ::org::mpisws::p2p::transport::sourceroute::SourceRoute* getIdentifier(::org::mpisws::p2p::transport::TransportLayer* a, ::org::mpisws::p2p::transport::TransportLayer* b) override;
    void openTCP() override;
    void sendUDP() override;
    static void setUpBeforeClass();

    // Generated
    WireSRTest();
protected:
    WireSRTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual ::java::lang::Object* getBogusIdentifier(::java::lang::Object* local) override;
    static ::int8_tArray*& GOOD_HDR();

public: /* package */
    static ::org::mpisws::p2p::transport::TransportLayer*& carol();
    static ::org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayer*& carol_tap();
    static ::org::mpisws::p2p::transport::sourceroute::SourceRouteFactory*& srFactory();

private:
    virtual ::java::lang::Class* getClass0();
};
