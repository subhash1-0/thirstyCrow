// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/evidence/ChallengeAudit.java
#include <org/mpisws/p2p/transport/peerreview/evidence/ChallengeAudit.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/Authenticator.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::peerreview::evidence::ChallengeAudit::ChallengeAudit(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::evidence::ChallengeAudit::ChallengeAudit(int8_t flags, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* from, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* to) 
    : ChallengeAudit(*static_cast< ::default_init_tag* >(0))
{
    ctor(flags,from,to);
}

org::mpisws::p2p::transport::peerreview::evidence::ChallengeAudit::ChallengeAudit(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t hashSize, int32_t signatureSize)  /* throws(IOException) */
    : ChallengeAudit(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,hashSize,signatureSize);
}

constexpr int16_t org::mpisws::p2p::transport::peerreview::evidence::ChallengeAudit::TYPE;

void org::mpisws::p2p::transport::peerreview::evidence::ChallengeAudit::ctor(int8_t flags, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* from, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* to)
{
    super::ctor();
    this->flags = flags;
    this->from = from;
    this->to = to;
}

int16_t org::mpisws::p2p::transport::peerreview::evidence::ChallengeAudit::getEvidenceType()
{
    return TYPE;
}

void org::mpisws::p2p::transport::peerreview::evidence::ChallengeAudit::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t hashSize, int32_t signatureSize) /* throws(IOException) */
{
    super::ctor();
    flags = npc(buf)->readByte();
    from = new ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator(buf, hashSize, signatureSize);
    to = new ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator(buf, hashSize, signatureSize);
}

void org::mpisws::p2p::transport::peerreview::evidence::ChallengeAudit::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(flags);
    npc(from)->serialize(buf);
    npc(to)->serialize(buf);
}

bool org::mpisws::p2p::transport::peerreview::evidence::ChallengeAudit::isIncludePrevCheckpoint()
{
    return (flags & FLAG_INCLUDE_CHECKPOINT) == FLAG_INCLUDE_CHECKPOINT;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::evidence::ChallengeAudit::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.evidence.ChallengeAudit", 59);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::evidence::ChallengeAudit::getClass0()
{
    return class_();
}

