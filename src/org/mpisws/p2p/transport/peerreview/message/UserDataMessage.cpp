// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/message/UserDataMessage.java
#include <org/mpisws/p2p/transport/peerreview/message/UserDataMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Throwable.hpp>
#include <java/nio/Buffer.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/HashProvider.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/EvtRecv.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>
#include <rice/p2p/util/MathUtils.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
#include <Array.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace nio
    {
typedef ::SubArray< ::java::nio::Buffer, ::java::lang::ObjectArray > BufferArray;
typedef ::SubArray< ::java::nio::ByteBuffer, BufferArray, ::java::lang::ComparableArray > ByteBufferArray;
    } // nio
} // java

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

org::mpisws::p2p::transport::peerreview::message::UserDataMessage::UserDataMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::message::UserDataMessage::UserDataMessage(int64_t topSeq, ::rice::p2p::commonapi::rawserialization::RawSerializable* senderHandle, ::int8_tArray* topMinusOne, ::int8_tArray* sig, ::java::nio::ByteBuffer* message, int32_t relevantlen) 
    : UserDataMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(topSeq,senderHandle,topMinusOne,sig,message,relevantlen);
}

constexpr int16_t org::mpisws::p2p::transport::peerreview::message::UserDataMessage::TYPE;

void org::mpisws::p2p::transport::peerreview::message::UserDataMessage::ctor(int64_t topSeq, ::rice::p2p::commonapi::rawserialization::RawSerializable* senderHandle, ::int8_tArray* topMinusOne, ::int8_tArray* sig, ::java::nio::ByteBuffer* message, int32_t relevantlen)
{
    super::ctor();
    this->topSeq = topSeq;
    this->senderHandle = senderHandle;
    hTopMinusOne = topMinusOne;
    this->signature = sig;
    this->relevantLen = relevantlen;
    /* assert(((relevantlen == npc(message)->remaining()) || (relevantlen < 255))) */ ;
    if(npc(message)->remaining() == npc(npc(message)->array())->length) {
        this->payload = npc(message)->array();
    } else {
        this->payload = new ::int8_tArray(npc(message)->remaining());
        ::java::lang::System::arraycopy(npc(message)->array(), npc(message)->position(), payload, 0, npc(payload)->length);
    }
}

java::lang::String* org::mpisws::p2p::transport::peerreview::message::UserDataMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"UDM:"_j)->append(topSeq)
        ->append(u","_j)
        ->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(senderHandle)))
        ->append(u","_j)
        ->append(::rice::p2p::util::MathUtils::toHex(hTopMinusOne))
        ->append(u","_j)
        ->append(::rice::p2p::util::MathUtils::toHex(signature))
        ->append(u","_j)
        ->append(relevantLen)
        ->append(u","_j)
        ->append(npc(payload)->length)->toString();
}

int16_t org::mpisws::p2p::transport::peerreview::message::UserDataMessage::getType()
{
    return TYPE;
}

int8_t org::mpisws::p2p::transport::peerreview::message::UserDataMessage::getRelevantCode()
{
    auto relevantCode = (relevantLen == npc(payload)->length) ? static_cast< int8_t >(int32_t(255)) : static_cast< int8_t >(relevantLen);
    return relevantCode;
}

void org::mpisws::p2p::transport::peerreview::message::UserDataMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeLong(topSeq);
    npc(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(senderHandle))->serialize(buf);
    npc(buf)->write(hTopMinusOne, 0, npc(hTopMinusOne)->length);
    npc(buf)->write(signature, 0, npc(signature)->length);
    auto relevantCode = getRelevantCode();
    npc(buf)->writeByte(relevantCode);
    npc(buf)->write(payload, 0, npc(payload)->length);
}

/* <H extends RawSerializable> */org::mpisws::p2p::transport::peerreview::message::UserDataMessage* org::mpisws::p2p::transport::peerreview::message::UserDataMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* serializer, int32_t hashSize, int32_t sigSize) /* throws(IOException) */
{
    clinit();
    auto seq = npc(buf)->readLong();
    auto handle = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(serializer)->deserialize(buf));
    auto hash = new ::int8_tArray(hashSize);
    npc(buf)->read(hash);
    auto sig = new ::int8_tArray(sigSize);
    npc(buf)->read(sig);
    auto relevantCode = npc(buf)->readByte();
    auto len = ::rice::p2p::util::MathUtils::uByteToInt(relevantCode);
    auto msg = new ::int8_tArray(npc(buf)->bytesRemaining());
    npc(buf)->read(msg);
    if(len == 255) {
        len = npc(msg)->length;
    }
    return new UserDataMessage(seq, handle, hash, sig, ::java::nio::ByteBuffer::wrap(msg), len);
}

int64_t org::mpisws::p2p::transport::peerreview::message::UserDataMessage::getTopSeq()
{
    return topSeq;
}

rice::p2p::commonapi::rawserialization::RawSerializable* org::mpisws::p2p::transport::peerreview::message::UserDataMessage::getSenderHandle()
{
    return java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(senderHandle);
}

int8_tArray* org::mpisws::p2p::transport::peerreview::message::UserDataMessage::getHTopMinusOne()
{
    return hTopMinusOne;
}

int8_tArray* org::mpisws::p2p::transport::peerreview::message::UserDataMessage::getSignature()
{
    return signature;
}

int32_t org::mpisws::p2p::transport::peerreview::message::UserDataMessage::getRelevantLen()
{
    return relevantLen;
}

java::nio::ByteBuffer* org::mpisws::p2p::transport::peerreview::message::UserDataMessage::getPayload()
{
    return ::java::nio::ByteBuffer::wrap(payload);
}

org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv* org::mpisws::p2p::transport::peerreview::message::UserDataMessage::getReceiveEvent(::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher)
{
    if(getRelevantLen() < npc(getPayload())->remaining()) {
        return new ::org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(getSenderHandle()), getTopSeq(), getPayload(), getRelevantLen(), hasher);
    } else {
        return new ::org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv(static_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(getSenderHandle())), getTopSeq(), getPayload());
    }
}

int8_tArray* org::mpisws::p2p::transport::peerreview::message::UserDataMessage::getInnerHash(::rice::p2p::commonapi::rawserialization::RawSerializable* myId, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher)
{
    try {
        auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
        npc(myId)->serialize(sob);
        npc(sob)->writeBoolean(getRelevantLen() < getPayloadLen());
        return getInnerHash(npc(sob)->getByteBuffer(), hasher);
    } catch (::java::io::IOException* ioe) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ioe));
    }
}

int8_tArray* org::mpisws::p2p::transport::peerreview::message::UserDataMessage::getInnerHash(::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher)
{
    try {
        auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
        npc(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(senderHandle))->serialize(sob);
        npc(sob)->writeLong(topSeq);
        npc(sob)->writeBoolean(relevantLen < getPayloadLen());
        return getInnerHash(npc(sob)->getByteBuffer(), hasher);
    } catch (::java::io::IOException* ioe) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ioe));
    }
}

int8_tArray* org::mpisws::p2p::transport::peerreview::message::UserDataMessage::getInnerHash(::java::nio::ByteBuffer* header, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher)
{
    if(relevantLen < npc(payload)->length) {
        auto irrelevantHash = npc(hasher)->hash(new ::java::nio::ByteBufferArray({::java::nio::ByteBuffer::wrap(payload, relevantLen, npc(payload)->length - relevantLen)}));
        return npc(hasher)->hash(new ::java::nio::ByteBufferArray({header, ::java::nio::ByteBuffer::wrap(payload, 0, relevantLen), ::java::nio::ByteBuffer::wrap(irrelevantHash)}));
    } else {
        return npc(hasher)->hash(new ::java::nio::ByteBufferArray({header, ::java::nio::ByteBuffer::wrap(payload)}));
    }
}

int32_t org::mpisws::p2p::transport::peerreview::message::UserDataMessage::getPayloadLen()
{
    return npc(payload)->length;
}

int16_t org::mpisws::p2p::transport::peerreview::message::UserDataMessage::getEvidenceType()
{
    return CHAL_SEND;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::message::UserDataMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.message.UserDataMessage", 59);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::message::UserDataMessage::getClass0()
{
    return class_();
}

