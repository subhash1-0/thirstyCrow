// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/SRManagerTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::SRManagerTest_TestLivenessTransportLayerImpl
    : public ::org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl
{

public:
    typedef ::org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl super;

protected:
    void ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler);

public:
    virtual void pong(::org::mpisws::p2p::transport::sourceroute::SourceRoute* i, int64_t senderTime, ::java::util::Map* options);

    // Generated
    SRManagerTest_TestLivenessTransportLayerImpl(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler);
protected:
    SRManagerTest_TestLivenessTransportLayerImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void pong(::java::lang::Object* i, int64_t senderTime, ::java::util::Map* options) override;

private:
    virtual ::java::lang::Class* getClass0();
};
