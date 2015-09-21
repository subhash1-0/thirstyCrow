// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/commitment/CommitmentProtocolImpl.java
#include <org/mpisws/p2p/transport/peerreview/commitment/CommitmentProtocolImpl_CommitmentProtocolImpl_1.hpp>

#include <org/mpisws/p2p/transport/peerreview/commitment/CommitmentProtocolImpl.hpp>

org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl_CommitmentProtocolImpl_1::CommitmentProtocolImpl_CommitmentProtocolImpl_1(CommitmentProtocolImpl *CommitmentProtocolImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , CommitmentProtocolImpl_this(CommitmentProtocolImpl_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl_CommitmentProtocolImpl_1::run()
{
    CommitmentProtocolImpl_this->makeProgressAllPeers();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl_CommitmentProtocolImpl_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl_CommitmentProtocolImpl_1::getClass0()
{
    return class_();
}

