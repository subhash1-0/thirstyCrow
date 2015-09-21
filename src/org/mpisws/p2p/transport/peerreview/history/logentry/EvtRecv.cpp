// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/logentry/EvtRecv.java
#include <org/mpisws/p2p/transport/peerreview/history/logentry/EvtRecv.hpp>

#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/System.hpp>
#include <java/nio/Buffer.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/HashProvider.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>
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

org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv::EvtRecv(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv::EvtRecv(::rice::p2p::commonapi::rawserialization::RawSerializable* senderHandle, int64_t topSeq, ::java::nio::ByteBuffer* payload) 
    : EvtRecv(*static_cast< ::default_init_tag* >(0))
{
    ctor(senderHandle,topSeq,payload);
}

org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv::EvtRecv(::rice::p2p::commonapi::rawserialization::RawSerializable* senderHandle, int64_t topSeq, ::java::nio::ByteBuffer* payload, int32_t relevantLen, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher) 
    : EvtRecv(*static_cast< ::default_init_tag* >(0))
{
    ctor(senderHandle,topSeq,payload,relevantLen,hasher);
}

org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv::EvtRecv(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* serializer, int32_t hashSize)  /* throws(IOException) */
    : EvtRecv(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,serializer,hashSize);
}

void org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv::ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* senderHandle, int64_t topSeq, ::java::nio::ByteBuffer* payload)
{
    super::ctor();
    this->senderHandle = senderHandle;
    this->senderSeq = topSeq;
    this->payload = new ::int8_tArray(npc(payload)->remaining());
    ::java::lang::System::arraycopy(npc(payload)->array(), npc(payload)->position(), this->payload, 0, npc(payload)->remaining());
}

void org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv::ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* senderHandle, int64_t topSeq, ::java::nio::ByteBuffer* payload, int32_t relevantLen, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher)
{
    super::ctor();
    this->senderHandle = senderHandle;
    this->senderSeq = topSeq;
    this->payload = new ::int8_tArray(npc(payload)->remaining());
    ::java::lang::System::arraycopy(npc(payload)->array(), npc(payload)->position(), this->payload, 0, relevantLen);
    hash = npc(hasher)->hash(new ::java::nio::ByteBufferArray({::java::nio::ByteBuffer::wrap(this->payload)}));
}

int16_t org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv::getType()
{
    return EVT_RECV;
}

void org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* serializer, int32_t hashSize) /* throws(IOException) */
{
    super::ctor();
    senderHandle = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(serializer)->deserialize(buf));
    senderSeq = npc(buf)->readLong();
    auto hashed = npc(buf)->readBoolean();
    auto payloadLength = npc(buf)->bytesRemaining();
    if(hashed)
        payloadLength -= hashSize;

    payload = new ::int8_tArray(payloadLength);
    npc(buf)->read(payload);
    if(hashed) {
        hash = new ::int8_tArray(hashSize);
        npc(buf)->read(hash);
    }
}

void org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(senderHandle))->serialize(buf);
    npc(buf)->writeLong(senderSeq);
    npc(buf)->writeBoolean(hash != nullptr);
    npc(buf)->write(payload, 0, npc(payload)->length);
    if(hash != nullptr)
        npc(buf)->write(hash, 0, npc(hash)->length);

}

rice::p2p::commonapi::rawserialization::RawSerializable* org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv::getSenderHandle()
{
    return java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(senderHandle);
}

int64_t org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv::getSenderSeq()
{
    return senderSeq;
}

int8_tArray* org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv::getPayload()
{
    return payload;
}

int8_tArray* org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv::getHash()
{
    return hash;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.history.logentry.EvtRecv", 60);
    return c;
}

java::nio::ByteBuffer* org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv::serialize()
{
    return super::serialize();
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv::getClass0()
{
    return class_();
}

