// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/logentry/EvtAck.java
#include <org/mpisws/p2p/transport/peerreview/history/logentry/EvtAck.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>
#include <Array.hpp>

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

org::mpisws::p2p::transport::peerreview::history::logentry::EvtAck::EvtAck(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::history::logentry::EvtAck::EvtAck(::rice::p2p::commonapi::rawserialization::RawSerializable* remoteId, int64_t ackedSeq, int64_t hisSeq, ::int8_tArray* topMinusOne, ::int8_tArray* signature) 
    : EvtAck(*static_cast< ::default_init_tag* >(0))
{
    ctor(remoteId,ackedSeq,hisSeq,topMinusOne,signature);
}

org::mpisws::p2p::transport::peerreview::history::logentry::EvtAck::EvtAck(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, int32_t hashSize, int32_t signatureSize)  /* throws(IOException) */
    : EvtAck(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,idSerializer,hashSize,signatureSize);
}

void org::mpisws::p2p::transport::peerreview::history::logentry::EvtAck::ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* remoteId, int64_t ackedSeq, int64_t hisSeq, ::int8_tArray* topMinusOne, ::int8_tArray* signature)
{
    super::ctor();
    this->remoteId = remoteId;
    this->ackedSeq = ackedSeq;
    this->hisSeq = hisSeq;
    hTopMinusOne = topMinusOne;
    this->signature = signature;
}

void org::mpisws::p2p::transport::peerreview::history::logentry::EvtAck::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, int32_t hashSize, int32_t signatureSize) /* throws(IOException) */
{
    super::ctor();
    remoteId = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(idSerializer)->deserialize(buf));
    ackedSeq = npc(buf)->readLong();
    hisSeq = npc(buf)->readLong();
    hTopMinusOne = new ::int8_tArray(hashSize);
    npc(buf)->read(hTopMinusOne);
    signature = new ::int8_tArray(signatureSize);
    npc(buf)->read(signature);
}

int16_t org::mpisws::p2p::transport::peerreview::history::logentry::EvtAck::getType()
{
    return EVT_SENDSIGN;
}

void org::mpisws::p2p::transport::peerreview::history::logentry::EvtAck::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(remoteId))->serialize(buf);
    npc(buf)->writeLong(ackedSeq);
    npc(buf)->writeLong(hisSeq);
    npc(buf)->write(hTopMinusOne, 0, npc(hTopMinusOne)->length);
    npc(buf)->write(signature, 0, npc(signature)->length);
}

rice::p2p::commonapi::rawserialization::RawSerializable* org::mpisws::p2p::transport::peerreview::history::logentry::EvtAck::getRemoteId()
{
    return java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(remoteId);
}

int64_t org::mpisws::p2p::transport::peerreview::history::logentry::EvtAck::getAckedSeq()
{
    return ackedSeq;
}

int64_t org::mpisws::p2p::transport::peerreview::history::logentry::EvtAck::getHisSeq()
{
    return hisSeq;
}

int8_tArray* org::mpisws::p2p::transport::peerreview::history::logentry::EvtAck::getHTopMinusOne()
{
    return hTopMinusOne;
}

int8_tArray* org::mpisws::p2p::transport::peerreview::history::logentry::EvtAck::getSignature()
{
    return signature;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::logentry::EvtAck::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.history.logentry.EvtAck", 59);
    return c;
}

java::nio::ByteBuffer* org::mpisws::p2p::transport::peerreview::history::logentry::EvtAck::serialize()
{
    return super::serialize();
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::logentry::EvtAck::getClass0()
{
    return class_();
}

