// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocolImpl.java
#include <org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocolImpl_MessageInfo.hpp>

#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocolImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/PeerReviewMessage.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl_MessageInfo::EvidenceTransferProtocolImpl_MessageInfo(EvidenceTransferProtocolImpl *EvidenceTransferProtocolImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , EvidenceTransferProtocolImpl_this(EvidenceTransferProtocolImpl_this)
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl_MessageInfo::EvidenceTransferProtocolImpl_MessageInfo(EvidenceTransferProtocolImpl *EvidenceTransferProtocolImpl_this, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) 
    : EvidenceTransferProtocolImpl_MessageInfo(EvidenceTransferProtocolImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(subject,message,deliverAckToMe,options);
}

void org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl_MessageInfo::ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    super::ctor();
    this->subject = subject;
    this->message = message;
    this->deliverAckToMe = deliverAckToMe;
    this->options = options;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl_MessageInfo::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.evidence.EvidenceTransferProtocolImpl.MessageInfo", 85);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl_MessageInfo::getClass0()
{
    return class_();
}

