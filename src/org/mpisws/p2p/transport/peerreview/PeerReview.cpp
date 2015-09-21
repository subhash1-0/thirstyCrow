// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/PeerReview.java
#include <org/mpisws/p2p/transport/peerreview/PeerReview.hpp>

#include <java/lang/String.hpp>

java::lang::String*& org::mpisws::p2p::transport::peerreview::PeerReview::RELEVANT_LENGTH()
{
    clinit();
    return RELEVANT_LENGTH_;
}
java::lang::String* org::mpisws::p2p::transport::peerreview::PeerReview::RELEVANT_LENGTH_;

java::lang::String*& org::mpisws::p2p::transport::peerreview::PeerReview::DONT_COMMIT()
{
    clinit();
    return DONT_COMMIT_;
}
java::lang::String* org::mpisws::p2p::transport::peerreview::PeerReview::DONT_COMMIT_;

constexpr int8_t org::mpisws::p2p::transport::peerreview::PeerReview::PEER_REVIEW_PASSTHROUGH;

constexpr int8_t org::mpisws::p2p::transport::peerreview::PeerReview::PEER_REVIEW_COMMIT;

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::PeerReview::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.PeerReview", 46);
    return c;
}

