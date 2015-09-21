// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/PeerReviewImpl.java
#include <org/mpisws/p2p/transport/peerreview/PeerReviewImpl_init_4.hpp>

#include <java/lang/String.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewImpl.hpp>

org::mpisws::p2p::transport::peerreview::PeerReviewImpl_init_4::PeerReviewImpl_init_4(PeerReviewImpl *PeerReviewImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , PeerReviewImpl_this(PeerReviewImpl_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl_init_4::run()
{
    PeerReviewImpl_this->doMaintenance();
}

java::lang::String* org::mpisws::p2p::transport::peerreview::PeerReviewImpl_init_4::toString()
{
    return u"DoMaintenanceTask"_j;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::PeerReviewImpl_init_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::PeerReviewImpl_init_4::getClass0()
{
    return class_();
}

