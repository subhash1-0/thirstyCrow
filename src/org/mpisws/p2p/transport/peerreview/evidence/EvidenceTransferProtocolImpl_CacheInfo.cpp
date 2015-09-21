// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocolImpl.java
#include <org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocolImpl_CacheInfo.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/util/Collection.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReview.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocolImpl.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl_CacheInfo::EvidenceTransferProtocolImpl_CacheInfo(EvidenceTransferProtocolImpl *EvidenceTransferProtocolImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , EvidenceTransferProtocolImpl_this(EvidenceTransferProtocolImpl_this)
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl_CacheInfo::EvidenceTransferProtocolImpl_CacheInfo(EvidenceTransferProtocolImpl *EvidenceTransferProtocolImpl_this, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject) 
    : EvidenceTransferProtocolImpl_CacheInfo(EvidenceTransferProtocolImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(subject);
}

void org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl_CacheInfo::ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* subject)
{
    super::ctor();
    this->subject = subject;
    validUntil = 0;
    witnessesRequested = true;
}

void org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl_CacheInfo::updateWitnesses(::java::util::Collection* witnesses)
{
    witnessesRequested = false;
    this->witness = witnesses;
    validUntil = npc(EvidenceTransferProtocolImpl_this->peerreview)->getTime() + EvidenceTransferProtocolImpl::WITNESS_SET_VALID_MICROS;
}

bool org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl_CacheInfo::isValid()
{
    return validUntil > npc(EvidenceTransferProtocolImpl_this->peerreview)->getTime();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl_CacheInfo::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.evidence.EvidenceTransferProtocolImpl.CacheInfo", 83);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl_CacheInfo::getClass0()
{
    return class_();
}

