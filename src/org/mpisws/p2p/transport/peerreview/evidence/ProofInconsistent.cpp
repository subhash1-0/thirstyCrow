// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/evidence/ProofInconsistent.java
#include <org/mpisws/p2p/transport/peerreview/evidence/ProofInconsistent.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/LogSnippet.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/Authenticator.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorSerializer.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::peerreview::evidence::ProofInconsistent::ProofInconsistent(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::evidence::ProofInconsistent::ProofInconsistent(::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth1, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth2) 
    : ProofInconsistent(*static_cast< ::default_init_tag* >(0))
{
    ctor(auth1,auth2);
}

org::mpisws::p2p::transport::peerreview::evidence::ProofInconsistent::ProofInconsistent(::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth1, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth2, ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* snippet) 
    : ProofInconsistent(*static_cast< ::default_init_tag* >(0))
{
    ctor(auth1,auth2,snippet);
}

org::mpisws::p2p::transport::peerreview::evidence::ProofInconsistent::ProofInconsistent(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializer* serializer, int32_t hashSize)  /* throws(IOException) */
    : ProofInconsistent(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,serializer,hashSize);
}

constexpr int8_t org::mpisws::p2p::transport::peerreview::evidence::ProofInconsistent::NO_SNIPPET;

constexpr int8_t org::mpisws::p2p::transport::peerreview::evidence::ProofInconsistent::LOG_SNIPPET;

void org::mpisws::p2p::transport::peerreview::evidence::ProofInconsistent::ctor(::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth1, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth2)
{
    super::ctor();
    this->auth1 = auth1;
    this->auth2 = auth2;
}

void org::mpisws::p2p::transport::peerreview::evidence::ProofInconsistent::ctor(::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth1, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth2, ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* snippet)
{
    super::ctor();
    this->auth1 = auth1;
    this->auth2 = auth2;
    this->snippet = snippet;
}

int16_t org::mpisws::p2p::transport::peerreview::evidence::ProofInconsistent::getEvidenceType()
{
    return PROOF_INCONSISTENT;
}

void org::mpisws::p2p::transport::peerreview::evidence::ProofInconsistent::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializer* serializer, int32_t hashSize) /* throws(IOException) */
{
    super::ctor();
    auth1 = npc(serializer)->deserialize(buf);
    auto type = npc(buf)->readByte();
    auth2 = npc(serializer)->deserialize(buf);
    switch (type) {
    case NO_SNIPPET:
        break;
    case LOG_SNIPPET:
        snippet = new ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet(buf, hashSize);
        break;
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"unknown type:"_j)->append(type)->toString());
    }

}

void org::mpisws::p2p::transport::peerreview::evidence::ProofInconsistent::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(auth1)->serialize(buf);
    if(snippet == nullptr) {
        npc(buf)->writeByte(NO_SNIPPET);
    } else {
        npc(buf)->writeByte(LOG_SNIPPET);
    }
    npc(auth2)->serialize(buf);
    if(snippet != nullptr) {
        npc(snippet)->serialize(buf);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::evidence::ProofInconsistent::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.evidence.ProofInconsistent", 62);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::evidence::ProofInconsistent::getClass0()
{
    return class_();
}

