// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/commitment/ReceiveInfo.java
#include <org/mpisws/p2p/transport/peerreview/commitment/ReceiveInfo.hpp>

#include <java/lang/Object.hpp>

org::mpisws::p2p::transport::peerreview::commitment::ReceiveInfo::ReceiveInfo(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::commitment::ReceiveInfo::ReceiveInfo(::java::lang::Object* sender, int64_t senderSeq, int64_t indexInLocalHistory) 
    : ReceiveInfo(*static_cast< ::default_init_tag* >(0))
{
    ctor(sender,senderSeq,indexInLocalHistory);
}

void org::mpisws::p2p::transport::peerreview::commitment::ReceiveInfo::ctor(::java::lang::Object* sender, int64_t senderSeq, int64_t indexInLocalHistory)
{
    super::ctor();
    this->sender = sender;
    this->senderSeq = senderSeq;
    this->indexInLocalHistory = indexInLocalHistory;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::commitment::ReceiveInfo::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.commitment.ReceiveInfo", 58);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::commitment::ReceiveInfo::getClass0()
{
    return class_();
}

