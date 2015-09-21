// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/message/ChallengeMessage.java
#include <org/mpisws/p2p/transport/peerreview/message/ChallengeMessage.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/Evidence.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/EvidenceSerializer.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
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

org::mpisws::p2p::transport::peerreview::message::ChallengeMessage::ChallengeMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::message::ChallengeMessage::ChallengeMessage(::rice::p2p::commonapi::rawserialization::RawSerializable* originator, int64_t evidenceSeq, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* challenge) 
    : ChallengeMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(originator,evidenceSeq,challenge);
}

org::mpisws::p2p::transport::peerreview::message::ChallengeMessage::ChallengeMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, ::org::mpisws::p2p::transport::peerreview::infostore::EvidenceSerializer* evidenceSerializer)  /* throws(IOException) */
    : ChallengeMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,idSerializer,evidenceSerializer);
}

int16_t& org::mpisws::p2p::transport::peerreview::message::ChallengeMessage::TYPE()
{
    clinit();
    return TYPE_;
}
int16_t org::mpisws::p2p::transport::peerreview::message::ChallengeMessage::TYPE_;

void org::mpisws::p2p::transport::peerreview::message::ChallengeMessage::ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* originator, int64_t evidenceSeq, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* challenge)
{
    super::ctor();
    this->originator = originator;
    this->evidenceSeq = evidenceSeq;
    this->challenge = challenge;
}

int16_t org::mpisws::p2p::transport::peerreview::message::ChallengeMessage::getType()
{
    return TYPE();
}

int16_t org::mpisws::p2p::transport::peerreview::message::ChallengeMessage::getChallengeType()
{
    return npc(challenge)->getEvidenceType();
}

void org::mpisws::p2p::transport::peerreview::message::ChallengeMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, ::org::mpisws::p2p::transport::peerreview::infostore::EvidenceSerializer* evidenceSerializer) /* throws(IOException) */
{
    super::ctor();
    originator = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(idSerializer)->deserialize(buf));
    evidenceSeq = npc(buf)->readLong();
    auto chalType = npc(buf)->readByte();
    challenge = npc(evidenceSerializer)->deserialize(buf, chalType, false);
}

void org::mpisws::p2p::transport::peerreview::message::ChallengeMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(originator))->serialize(buf);
    npc(buf)->writeLong(evidenceSeq);
    npc(buf)->writeByte(static_cast< int8_t >(npc(challenge)->getEvidenceType()));
    npc(challenge)->serialize(buf);
}

org::mpisws::p2p::transport::peerreview::infostore::Evidence* org::mpisws::p2p::transport::peerreview::message::ChallengeMessage::getChallenge()
{
    return challenge;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::message::ChallengeMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.message.ChallengeMessage", 60);
    return c;
}

void org::mpisws::p2p::transport::peerreview::message::ChallengeMessage::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        TYPE_ = ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants::MSG_CHALLENGE;
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::message::ChallengeMessage::getClass0()
{
    return class_();
}

