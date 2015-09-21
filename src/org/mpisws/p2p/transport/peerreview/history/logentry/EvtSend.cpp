// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/logentry/EvtSend.java
#include <org/mpisws/p2p/transport/peerreview/history/logentry/EvtSend.hpp>

#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
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

org::mpisws::p2p::transport::peerreview::history::logentry::EvtSend::EvtSend(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::history::logentry::EvtSend::EvtSend(::rice::p2p::commonapi::rawserialization::RawSerializable* receiverId, ::java::nio::ByteBuffer* payload, int32_t relevantPayload, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher) 
    : EvtSend(*static_cast< ::default_init_tag* >(0))
{
    ctor(receiverId,payload,relevantPayload,hasher);
}

org::mpisws::p2p::transport::peerreview::history::logentry::EvtSend::EvtSend(::rice::p2p::commonapi::rawserialization::RawSerializable* receiverId, ::java::nio::ByteBuffer* payload) 
    : EvtSend(*static_cast< ::default_init_tag* >(0))
{
    ctor(receiverId,payload);
}

org::mpisws::p2p::transport::peerreview::history::logentry::EvtSend::EvtSend(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, int32_t hashSize)  /* throws(IOException) */
    : EvtSend(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,idSerializer,hashSize);
}

void org::mpisws::p2p::transport::peerreview::history::logentry::EvtSend::ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* receiverId, ::java::nio::ByteBuffer* payload, int32_t relevantPayload, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher)
{
    super::ctor();
    this->receiverId = receiverId;
    this->payload = ::java::nio::ByteBuffer::wrap(npc(payload)->array(), npc(payload)->position(), relevantPayload);
    hash = npc(hasher)->hash(new ::java::nio::ByteBufferArray({this->payload}));
}

void org::mpisws::p2p::transport::peerreview::history::logentry::EvtSend::ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* receiverId, ::java::nio::ByteBuffer* payload)
{
    super::ctor();
    this->receiverId = receiverId;
    this->payload = ::java::nio::ByteBuffer::wrap(npc(payload)->array(), npc(payload)->position(), npc(payload)->remaining());
}

void org::mpisws::p2p::transport::peerreview::history::logentry::EvtSend::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, int32_t hashSize) /* throws(IOException) */
{
    super::ctor();
    receiverId = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(idSerializer)->deserialize(buf));
    auto hasHash = npc(buf)->readBoolean();
    ::int8_tArray* payload_bytes;
    if(hasHash) {
        payload_bytes = new ::int8_tArray(npc(buf)->bytesRemaining() - hashSize);
    } else {
        payload_bytes = new ::int8_tArray(hashSize);
    }
    npc(buf)->read(payload_bytes);
    payload = ::java::nio::ByteBuffer::wrap(payload_bytes);
    if(hasHash) {
        hash = new ::int8_tArray(hashSize);
        npc(buf)->read(hash);
    }
}

void org::mpisws::p2p::transport::peerreview::history::logentry::EvtSend::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(receiverId))->serialize(buf);
    npc(buf)->writeBoolean(hash != nullptr);
    npc(buf)->write(npc(payload)->array(), npc(payload)->position(), npc(payload)->remaining());
    if(hash != nullptr) {
        npc(buf)->write(hash, 0, npc(hash)->length);
    }
}

int16_t org::mpisws::p2p::transport::peerreview::history::logentry::EvtSend::getType()
{
    return EVT_SEND;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::logentry::EvtSend::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.history.logentry.EvtSend", 60);
    return c;
}

java::nio::ByteBuffer* org::mpisws::p2p::transport::peerreview::history::logentry::EvtSend::serialize()
{
    return super::serialize();
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::logentry::EvtSend::getClass0()
{
    return class_();
}

