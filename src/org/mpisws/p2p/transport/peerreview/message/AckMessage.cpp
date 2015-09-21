// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/message/AckMessage.java
#include <org/mpisws/p2p/transport/peerreview/message/AckMessage.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
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

org::mpisws::p2p::transport::peerreview::message::AckMessage::AckMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::message::AckMessage::AckMessage(::rice::p2p::commonapi::rawserialization::RawSerializable* nodeId, int64_t sendEntrySeq, int64_t recvEntrySeq, ::int8_tArray* hashTopMinusOne, ::int8_tArray* signature) 
    : AckMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(nodeId,sendEntrySeq,recvEntrySeq,hashTopMinusOne,signature);
}

void org::mpisws::p2p::transport::peerreview::message::AckMessage::ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* nodeId, int64_t sendEntrySeq, int64_t recvEntrySeq, ::int8_tArray* hashTopMinusOne, ::int8_tArray* signature)
{
    super::ctor();
    this->nodeId = nodeId;
    this->sendEntrySeq = sendEntrySeq;
    this->recvEntrySeq = recvEntrySeq;
    this->hashTopMinusOne = hashTopMinusOne;
    this->signature = signature;
}

int16_t org::mpisws::p2p::transport::peerreview::message::AckMessage::getType()
{
    return MSG_ACK;
}

int16_t org::mpisws::p2p::transport::peerreview::message::AckMessage::getEvidenceType()
{
    return RESP_SEND;
}

void org::mpisws::p2p::transport::peerreview::message::AckMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(nodeId))->serialize(buf);
    npc(buf)->writeLong(sendEntrySeq);
    npc(buf)->writeLong(recvEntrySeq);
    npc(buf)->write(hashTopMinusOne, 0, npc(hashTopMinusOne)->length);
    npc(buf)->write(signature, 0, npc(signature)->length);
}

/* <Identifier extends RawSerializable> */org::mpisws::p2p::transport::peerreview::message::AckMessage* org::mpisws::p2p::transport::peerreview::message::AckMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* sib, ::org::mpisws::p2p::transport::util::Serializer* serializer, int32_t hashSizeInBytes, int32_t signatureSizeInBytes) /* throws(IOException) */
{
    clinit();
    auto remoteId = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(serializer)->deserialize(sib));
    auto ackedSeq = npc(sib)->readLong();
    auto hisSeq = npc(sib)->readLong();
    auto hTopMinusOne = new ::int8_tArray(hashSizeInBytes);
    npc(sib)->read(hTopMinusOne);
    auto signature = new ::int8_tArray(signatureSizeInBytes);
    npc(sib)->read(signature);
    return new AckMessage(remoteId, ackedSeq, hisSeq, hTopMinusOne, signature);
}

rice::p2p::commonapi::rawserialization::RawSerializable* org::mpisws::p2p::transport::peerreview::message::AckMessage::getNodeId()
{
    return java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(nodeId);
}

int64_t org::mpisws::p2p::transport::peerreview::message::AckMessage::getSendEntrySeq()
{
    return sendEntrySeq;
}

int64_t org::mpisws::p2p::transport::peerreview::message::AckMessage::getRecvEntrySeq()
{
    return recvEntrySeq;
}

int8_tArray* org::mpisws::p2p::transport::peerreview::message::AckMessage::getHashTopMinusOne()
{
    return hashTopMinusOne;
}

int8_tArray* org::mpisws::p2p::transport::peerreview::message::AckMessage::getSignature()
{
    return signature;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::message::AckMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.message.AckMessage", 54);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::message::AckMessage::getClass0()
{
    return class_();
}

