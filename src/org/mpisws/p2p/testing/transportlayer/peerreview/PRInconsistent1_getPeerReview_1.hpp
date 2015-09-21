// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1.java

#pragma once

#include <org/mpisws/p2p/testing/transportlayer/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewImpl.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_getPeerReview_1
    : public ::org::mpisws::p2p::transport::peerreview::PeerReviewImpl
{

public:
    typedef ::org::mpisws::p2p::transport::peerreview::PeerReviewImpl super;

public: /* protected */
    ::org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactory* getSecureHistoryFactory(::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::rice::environment::Environment* env) override;

    // Generated

public:
    PRInconsistent1_getPeerReview_1(PRInconsistent1 *PRInconsistent1_this, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::util::Serializer* handleSerializer, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, ::org::mpisws::p2p::transport::peerreview::IdentifierExtractor* identifierExtractor, ::org::mpisws::p2p::transport::peerreview::infostore::IdStrTranslator* stringTranslator);
    static ::java::lang::Class *class_();
    PRInconsistent1 *PRInconsistent1_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PRInconsistent1;
    friend class PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1;
    friend class PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1;
    friend class PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1_appendEntry_1_1_1_1;
    friend class PRInconsistent1_ForkingSecureHistory;
    friend class PRInconsistent1_getBogusApp_2;
};
