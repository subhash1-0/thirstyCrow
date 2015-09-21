// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/messaging/GlacierNeighborResponseMessage.java
#include <rice/p2p/glacier/v2/messaging/GlacierNeighborResponseMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <Array.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
        } // commonapi
    } // p2p
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::messaging::GlacierNeighborResponseMessage::GlacierNeighborResponseMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::messaging::GlacierNeighborResponseMessage::GlacierNeighborResponseMessage(int32_t uid, ::rice::p2p::commonapi::IdArray* neighbors, ::int64_tArray* lastSeen, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag) 
    : GlacierNeighborResponseMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,neighbors,lastSeen,source,dest,tag);
}

rice::p2p::glacier::v2::messaging::GlacierNeighborResponseMessage::GlacierNeighborResponseMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : GlacierNeighborResponseMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::glacier::v2::messaging::GlacierNeighborResponseMessage::TYPE;

void rice::p2p::glacier::v2::messaging::GlacierNeighborResponseMessage::ctor(int32_t uid, ::rice::p2p::commonapi::IdArray* neighbors, ::int64_tArray* lastSeen, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag)
{
    super::ctor(uid, source, dest, true, tag);
    this->neighbors = neighbors;
    this->lastSeen = lastSeen;
}

int32_t rice::p2p::glacier::v2::messaging::GlacierNeighborResponseMessage::numNeighbors()
{
    if((neighbors == nullptr) || (lastSeen == nullptr))
        return 0;

    if(npc(lastSeen)->length < npc(neighbors)->length)
        return npc(lastSeen)->length;

    return npc(neighbors)->length;
}

rice::p2p::commonapi::Id* rice::p2p::glacier::v2::messaging::GlacierNeighborResponseMessage::getNeighbor(int32_t index)
{
    return (*neighbors)[index];
}

int64_t rice::p2p::glacier::v2::messaging::GlacierNeighborResponseMessage::getLastSeen(int32_t index)
{
    return (*lastSeen)[index];
}

java::lang::String* rice::p2p::glacier::v2::messaging::GlacierNeighborResponseMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"[GlacierNeighborResponse with "_j)->append(numNeighbors())
        ->append(u" keys]"_j)->toString();
}

int16_t rice::p2p::glacier::v2::messaging::GlacierNeighborResponseMessage::getType()
{
    return TYPE;
}

void rice::p2p::glacier::v2::messaging::GlacierNeighborResponseMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    super::serialize(buf);
    npc(buf)->writeInt(npc(lastSeen)->length);
    for (auto i = int32_t(0); i < npc(lastSeen)->length; i++) {
        npc(buf)->writeLong((*lastSeen)[i]);
    }
    npc(buf)->writeInt(npc(neighbors)->length);
    for (auto i = int32_t(0); i < npc(neighbors)->length; i++) {
        npc(buf)->writeShort(npc((*neighbors)[i])->getType());
        npc((*neighbors)[i])->serialize(buf);
    }
}

rice::p2p::glacier::v2::messaging::GlacierNeighborResponseMessage* rice::p2p::glacier::v2::messaging::GlacierNeighborResponseMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new GlacierNeighborResponseMessage(buf, endpoint);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::glacier::v2::messaging::GlacierNeighborResponseMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    lastSeen = new ::int64_tArray(npc(buf)->readInt());
    for (auto i = int32_t(0); i < npc(lastSeen)->length; i++) {
        (*lastSeen)[i] = npc(buf)->readLong();
    }
    neighbors = new ::rice::p2p::commonapi::IdArray(npc(buf)->readInt());
    for (auto i = int32_t(0); i < npc(lastSeen)->length; i++) {
        neighbors->set(i, npc(endpoint)->readId(buf, npc(buf)->readShort()));
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierNeighborResponseMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.messaging.GlacierNeighborResponseMessage", 60);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierNeighborResponseMessage::getClass0()
{
    return class_();
}

