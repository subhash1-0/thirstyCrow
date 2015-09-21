// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/EpochTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/TLTest.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::EpochTest
    : public TLTest
{

public:
    typedef TLTest super;

private:
    static ::int8_tArray* GOOD_HDR_;

protected:
    void ctor();

public:
    virtual void bogus();
    /*static ::org::mpisws::p2p::transport::TransportLayer* buildTL(::java::lang::String* name, ::java::net::InetAddress* addr, int32_t port, ::rice::environment::Environment* env); (private) */
    virtual ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* getBogusIdentifier(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local);
    static void setUpBeforeClass();
    virtual void testFalseAddress();
    virtual void testFalseAddressBypass();

    // Generated
    EpochTest();
protected:
    EpochTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual ::java::lang::Object* getBogusIdentifier(::java::lang::Object* local) override;
    static ::int8_tArray*& GOOD_HDR();

private:
    virtual ::java::lang::Class* getClass0();
};
