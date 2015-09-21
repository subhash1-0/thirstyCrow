// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/message/AccusationMessage.java
#include <org/mpisws/p2p/transport/peerreview/message/AccusationMessage.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/EvidenceRecord.hpp>
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

org::mpisws::p2p::transport::peerreview::message::AccusationMessage::AccusationMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::message::AccusationMessage::AccusationMessage(::rice::p2p::commonapi::rawserialization::RawSerializable* originator, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject, int64_t evidenceSeq, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence) 
    : AccusationMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(originator,subject,evidenceSeq,evidence);
}

org::mpisws::p2p::transport::peerreview::message::AccusationMessage::AccusationMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, ::org::mpisws::p2p::transport::peerreview::infostore::EvidenceSerializer* evSerializer)  /* throws(IOException) */
    : AccusationMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,idSerializer,evSerializer);
}

org::mpisws::p2p::transport::peerreview::message::AccusationMessage::AccusationMessage(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::infostore::EvidenceRecord* evidenceRecord, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence) 
    : AccusationMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(subject,evidenceRecord,evidence);
}

void org::mpisws::p2p::transport::peerreview::message::AccusationMessage::ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* originator, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject, int64_t evidenceSeq, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence)
{
    super::ctor(originator, subject, evidenceSeq, evidence);
}

void org::mpisws::p2p::transport::peerreview::message::AccusationMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, ::org::mpisws::p2p::transport::peerreview::infostore::EvidenceSerializer* evSerializer) /* throws(IOException) */
{
    super::ctor(buf, idSerializer, evSerializer);
}

void org::mpisws::p2p::transport::peerreview::message::AccusationMessage::ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::infostore::EvidenceRecord* evidenceRecord, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence)
{
    ctor(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(evidenceRecord)->getOriginator()), subject, npc(evidenceRecord)->getTimeStamp(), evidence);
}

int16_t org::mpisws::p2p::transport::peerreview::message::AccusationMessage::getType()
{
    return MSG_ACCUSATION;
}

bool org::mpisws::p2p::transport::peerreview::message::AccusationMessage::isResponse()
{
    return false;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::message::AccusationMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.message.AccusationMessage", 61);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::message::AccusationMessage::getClass0()
{
    return class_();
}

