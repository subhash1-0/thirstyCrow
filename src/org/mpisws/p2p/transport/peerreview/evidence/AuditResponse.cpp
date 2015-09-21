// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/evidence/AuditResponse.java
#include <org/mpisws/p2p/transport/peerreview/evidence/AuditResponse.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/LogSnippet.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::peerreview::evidence::AuditResponse::AuditResponse(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::evidence::AuditResponse::AuditResponse(::rice::p2p::commonapi::rawserialization::RawSerializable* logOwner, ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* logSnippet) 
    : AuditResponse(*static_cast< ::default_init_tag* >(0))
{
    ctor(logOwner,logSnippet);
}

org::mpisws::p2p::transport::peerreview::evidence::AuditResponse::AuditResponse(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* serializer, int32_t hashSize)  /* throws(IOException) */
    : AuditResponse(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,serializer,hashSize);
}

void org::mpisws::p2p::transport::peerreview::evidence::AuditResponse::ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* logOwner, ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* logSnippet)
{
    super::ctor();
    this->logOwner = logOwner;
    this->logSnippet = logSnippet;
}

int16_t org::mpisws::p2p::transport::peerreview::evidence::AuditResponse::getEvidenceType()
{
    return RESP_AUDIT;
}

void org::mpisws::p2p::transport::peerreview::evidence::AuditResponse::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* serializer, int32_t hashSize) /* throws(IOException) */
{
    super::ctor();
    logOwner = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(serializer)->deserialize(buf));
    logSnippet = new ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet(buf, hashSize);
}

void org::mpisws::p2p::transport::peerreview::evidence::AuditResponse::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(logOwner))->serialize(buf);
    npc(logSnippet)->serialize(buf);
}

org::mpisws::p2p::transport::peerreview::audit::LogSnippet* org::mpisws::p2p::transport::peerreview::evidence::AuditResponse::getLogSnippet()
{
    return logSnippet;
}

rice::p2p::commonapi::rawserialization::RawSerializable* org::mpisws::p2p::transport::peerreview::evidence::AuditResponse::getLogOwner()
{
    return java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(logOwner);
}

int64_t org::mpisws::p2p::transport::peerreview::evidence::AuditResponse::getFirstSeq()
{
    return npc(logSnippet)->getFirstSeq();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::evidence::AuditResponse::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.evidence.AuditResponse", 58);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::evidence::AuditResponse::getClass0()
{
    return class_();
}

