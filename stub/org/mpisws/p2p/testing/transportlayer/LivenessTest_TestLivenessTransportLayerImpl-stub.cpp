// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/LivenessTest.java
#include <org/mpisws/p2p/testing/transportlayer/LivenessTest_TestLivenessTransportLayerImpl.hpp>

#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>

extern void unimplemented_(const char16_t* name);
org::mpisws::p2p::testing::transportlayer::LivenessTest_TestLivenessTransportLayerImpl::LivenessTest_TestLivenessTransportLayerImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::LivenessTest_TestLivenessTransportLayerImpl::LivenessTest_TestLivenessTransportLayerImpl(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler)
    : LivenessTest_TestLivenessTransportLayerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(tl, env, errorHandler);
}


void ::org::mpisws::p2p::testing::transportlayer::LivenessTest_TestLivenessTransportLayerImpl::ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::mpisws::p2p::testing::transportlayer::LivenessTest_TestLivenessTransportLayerImpl::ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler)");
}

void org::mpisws::p2p::testing::transportlayer::LivenessTest_TestLivenessTransportLayerImpl::pong(::org::mpisws::p2p::transport::sourceroute::SourceRoute* i, int64_t senderTime, ::java::util::Map* options)
{ /* stub */
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::LivenessTest_TestLivenessTransportLayerImpl::pong(::org::mpisws::p2p::transport::sourceroute::SourceRoute* i, int64_t senderTime, ::java::util::Map* options)");
}

void org::mpisws::p2p::testing::transportlayer::LivenessTest_TestLivenessTransportLayerImpl::pong(::java::lang::Object* i, int64_t senderTime, ::java::util::Map* options)
{ 
    pong(dynamic_cast< ::org::mpisws::p2p::transport::sourceroute::SourceRoute* >(i), senderTime, options);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::LivenessTest_TestLivenessTransportLayerImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.LivenessTest.TestLivenessTransportLayerImpl", 81);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::LivenessTest_TestLivenessTransportLayerImpl::getClass0()
{
    return class_();
}

