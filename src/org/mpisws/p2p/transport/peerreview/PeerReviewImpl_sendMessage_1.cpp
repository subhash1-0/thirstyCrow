// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/PeerReviewImpl.java
#include <org/mpisws/p2p/transport/peerreview/PeerReviewImpl_sendMessage_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewImpl.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::peerreview::PeerReviewImpl_sendMessage_1::PeerReviewImpl_sendMessage_1(PeerReviewImpl *PeerReviewImpl_this, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl* ret)
    : super(*static_cast< ::default_init_tag* >(0))
    , PeerReviewImpl_this(PeerReviewImpl_this)
    , deliverAckToMe(deliverAckToMe)
    , ret(ret)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl_sendMessage_1::ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg)
{
    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->ack(ret);

}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl_sendMessage_1::sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* reason)
{
    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->sendFailed(ret, reason);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::PeerReviewImpl_sendMessage_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::PeerReviewImpl_sendMessage_1::getClass0()
{
    return class_();
}

