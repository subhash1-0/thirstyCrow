// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/evidence/ProofNonconformant.java
#include <org/mpisws/p2p/transport/peerreview/evidence/ProofNonconformant.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/LogSnippet.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/Authenticator.hpp>
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

org::mpisws::p2p::transport::peerreview::evidence::ProofNonconformant::ProofNonconformant(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::evidence::ProofNonconformant::ProofNonconformant(::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* to, ::rice::p2p::commonapi::rawserialization::RawSerializable* myHandle, ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* snippet) 
    : ProofNonconformant(*static_cast< ::default_init_tag* >(0))
{
    ctor(to,myHandle,snippet);
}

org::mpisws::p2p::transport::peerreview::evidence::ProofNonconformant::ProofNonconformant(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* serializer, int32_t hashSize, int32_t signatureSize)  /* throws(IOException) */
    : ProofNonconformant(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,serializer,hashSize,signatureSize);
}

void org::mpisws::p2p::transport::peerreview::evidence::ProofNonconformant::ctor(::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* to, ::rice::p2p::commonapi::rawserialization::RawSerializable* myHandle, ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* snippet)
{
    super::ctor();
    this->to = to;
    this->myHandle = myHandle;
    this->snippet = snippet;
}

int16_t org::mpisws::p2p::transport::peerreview::evidence::ProofNonconformant::getEvidenceType()
{
    return PROOF_NONCONFORMANT;
}

void org::mpisws::p2p::transport::peerreview::evidence::ProofNonconformant::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* serializer, int32_t hashSize, int32_t signatureSize) /* throws(IOException) */
{
    super::ctor();
    to = new ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator(buf, hashSize, signatureSize);
    myHandle = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(serializer)->deserialize(buf));
    snippet = new ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet(buf, hashSize);
}

void org::mpisws::p2p::transport::peerreview::evidence::ProofNonconformant::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(to)->serialize(buf);
    npc(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(myHandle))->serialize(buf);
    npc(snippet)->serialize(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::evidence::ProofNonconformant::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.evidence.ProofNonconformant", 63);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::evidence::ProofNonconformant::getClass0()
{
    return class_();
}

