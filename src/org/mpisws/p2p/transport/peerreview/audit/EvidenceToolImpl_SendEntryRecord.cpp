// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/audit/EvidenceToolImpl.java
#include <org/mpisws/p2p/transport/peerreview/audit/EvidenceToolImpl_SendEntryRecord.hpp>

#include <java/nio/ByteBuffer.hpp>

org::mpisws::p2p::transport::peerreview::audit::EvidenceToolImpl_SendEntryRecord::EvidenceToolImpl_SendEntryRecord(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::audit::EvidenceToolImpl_SendEntryRecord::EvidenceToolImpl_SendEntryRecord(int64_t seq, ::java::nio::ByteBuffer* hashedPlusPayload) 
    : EvidenceToolImpl_SendEntryRecord(*static_cast< ::default_init_tag* >(0))
{
    ctor(seq,hashedPlusPayload);
}

void org::mpisws::p2p::transport::peerreview::audit::EvidenceToolImpl_SendEntryRecord::ctor(int64_t seq, ::java::nio::ByteBuffer* hashedPlusPayload)
{
    super::ctor();
    this->seq = seq;
    this->hashedPlusPayload = hashedPlusPayload;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::audit::EvidenceToolImpl_SendEntryRecord::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.audit.EvidenceToolImpl.SendEntryRecord", 74);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::audit::EvidenceToolImpl_SendEntryRecord::getClass0()
{
    return class_();
}

