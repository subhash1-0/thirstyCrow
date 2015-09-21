// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/evidence/EvidenceSerializerImpl.java
#include <org/mpisws/p2p/transport/peerreview/evidence/EvidenceSerializerImpl.hpp>

#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorSerializer.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorSerializerImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/AuditResponse.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/ChallengeAudit.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/ProofInconsistent.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/ProofNonconformant.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/AckMessage.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/UserDataMessage.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>

org::mpisws::p2p::transport::peerreview::evidence::EvidenceSerializerImpl::EvidenceSerializerImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::evidence::EvidenceSerializerImpl::EvidenceSerializerImpl(::org::mpisws::p2p::transport::util::Serializer* handleSerializer, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, int32_t hashSize, int32_t signatureSize) 
    : EvidenceSerializerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(handleSerializer,idSerializer,hashSize,signatureSize);
}

void org::mpisws::p2p::transport::peerreview::evidence::EvidenceSerializerImpl::ctor(::org::mpisws::p2p::transport::util::Serializer* handleSerializer, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, int32_t hashSize, int32_t signatureSize)
{
    super::ctor();
    this->handleSerializer = handleSerializer;
    this->idSerializer = idSerializer;
    this->hashSize = hashSize;
    this->signatureSize = signatureSize;
    this->authSerializer = new ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializerImpl(hashSize, signatureSize);
}

org::mpisws::p2p::transport::peerreview::infostore::Evidence* org::mpisws::p2p::transport::peerreview::evidence::EvidenceSerializerImpl::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int8_t type, bool response) /* throws(IOException) */
{
    switch (type) {
    case CHAL_AUDIT:
        if(response) {
            return new AuditResponse(buf, handleSerializer, hashSize);
        } else {
            return new ChallengeAudit(buf, hashSize, signatureSize);
        }
    case CHAL_SEND:
    case static_cast< int8_t >(MSG_USERDATA):
        if(response) {
            return ::org::mpisws::p2p::transport::peerreview::message::AckMessage::build(buf, idSerializer, hashSize, signatureSize);
        } else {
            return ::org::mpisws::p2p::transport::peerreview::message::UserDataMessage::build(buf, handleSerializer, hashSize, signatureSize);
        }
    case PROOF_INCONSISTENT:
        return new ProofInconsistent(buf, static_cast< ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializer* >(authSerializer), hashSize);
    case PROOF_NONCONFORMANT:
        return new ProofNonconformant(buf, handleSerializer, hashSize, signatureSize);
    }

    throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Unknown type:"_j)->append(type)->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::evidence::EvidenceSerializerImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.evidence.EvidenceSerializerImpl", 67);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::evidence::EvidenceSerializerImpl::getClass0()
{
    return class_();
}

