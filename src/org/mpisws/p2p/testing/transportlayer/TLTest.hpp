// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/TLTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::TLTest
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    static constexpr int32_t START_PORT { int32_t(5009) };

private:
    static ::org::mpisws::p2p::transport::TransportLayer* alice_;
    static ::org::mpisws::p2p::transport::TransportLayer* bob_;
    static ::rice::environment::Environment* env_;
    static ::rice::environment::logging::Logger* logger_;
    static ::java::util::Map* options_;
    static ::int8_tArray* sentBytes_;

protected:
    void ctor();

public:
    virtual ::java::lang::Object* getBogusIdentifier(::java::lang::Object* local) = 0;
    virtual ::java::lang::Object* getIdentifier(::org::mpisws::p2p::transport::TransportLayer* a, ::org::mpisws::p2p::transport::TransportLayer* b);
    virtual void messageTooBigUDP();
    virtual void noCallbackTest();
    virtual void openTCP();
    virtual void sendUDP();
    static void setUpBeforeClass();
    static void tearDownAfterClass();
    virtual void testSocketThreadSafety();

    // Generated
    TLTest();
protected:
    TLTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* package */
    static ::org::mpisws::p2p::transport::TransportLayer*& alice();
    static ::org::mpisws::p2p::transport::TransportLayer*& bob();
    static ::rice::environment::Environment*& env();
    static ::rice::environment::logging::Logger*& logger();
    static ::java::util::Map*& options();
    static ::int8_tArray*& sentBytes();

private:
    virtual ::java::lang::Class* getClass0();
};
