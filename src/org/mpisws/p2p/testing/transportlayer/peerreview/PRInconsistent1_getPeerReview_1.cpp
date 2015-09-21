// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1_getPeerReview_1.hpp>

#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/IdentityTransport.hpp>

org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_getPeerReview_1::PRInconsistent1_getPeerReview_1(PRInconsistent1 *PRInconsistent1_this, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::util::Serializer* handleSerializer, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, ::org::mpisws::p2p::transport::peerreview::IdentifierExtractor* identifierExtractor, ::org::mpisws::p2p::transport::peerreview::infostore::IdStrTranslator* stringTranslator)
    : super(*static_cast< ::default_init_tag* >(0))
    , PRInconsistent1_this(PRInconsistent1_this)
{
    clinit();
    ctor(transport, env, handleSerializer, idSerializer, identifierExtractor, stringTranslator);
}

org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactory* org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_getPeerReview_1::getSecureHistoryFactory(::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::rice::environment::Environment* env)
{
    return new PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1(this, env, transport, env);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_getPeerReview_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_getPeerReview_1::getClass0()
{
    return class_();
}

