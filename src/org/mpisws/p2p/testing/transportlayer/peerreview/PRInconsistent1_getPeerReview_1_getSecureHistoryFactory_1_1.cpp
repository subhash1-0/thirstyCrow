// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1.hpp>

#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1_getPeerReview_1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1_ForkingSecureHistory.hpp>

org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1::PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1(PRInconsistent1_getPeerReview_1 *PRInconsistent1_getPeerReview_1_this, ::rice::environment::Environment* env_, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hashProv, ::rice::environment::Environment* env)
    : super(*static_cast< ::default_init_tag* >(0))
    , PRInconsistent1_getPeerReview_1_this(PRInconsistent1_getPeerReview_1_this)
    , env(env_)
{
    clinit();
    ctor(hashProv, env);
}

org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl* org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1::makeSecureHistory(::rice::p2p::util::RandomAccessFileIOBuffer* indexFile, ::rice::p2p::util::RandomAccessFileIOBuffer* dataFile, bool readOnly, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hashProv, ::org::mpisws::p2p::transport::peerreview::history::IndexEntryFactory* indexFactory, ::rice::environment::logging::Logger* logger) /* throws(IOException) */
{
    PRInconsistent1_ForkingSecureHistory* const foo = new PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1(this, env, indexFile, dataFile, readOnly, hashProv, indexFactory, logger);
    return foo;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1::getClass0()
{
    return class_();
}

