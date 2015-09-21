// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/messaging/GlacierSyncMessage.java
#include <rice/p2p/glacier/v2/messaging/GlacierSyncMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/glacier/v2/BloomFilter.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::messaging::GlacierSyncMessage::GlacierSyncMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::messaging::GlacierSyncMessage::GlacierSyncMessage(int32_t uid, ::rice::p2p::commonapi::IdRange* range, int32_t offsetFID, ::rice::p2p::glacier::v2::BloomFilter* BloomFilter, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag) 
    : GlacierSyncMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,range,offsetFID,BloomFilter,source,dest,tag);
}

rice::p2p::glacier::v2::messaging::GlacierSyncMessage::GlacierSyncMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : GlacierSyncMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::glacier::v2::messaging::GlacierSyncMessage::TYPE;

void rice::p2p::glacier::v2::messaging::GlacierSyncMessage::ctor(int32_t uid, ::rice::p2p::commonapi::IdRange* range, int32_t offsetFID, ::rice::p2p::glacier::v2::BloomFilter* BloomFilter, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag)
{
    super::ctor(uid, source, dest, false, tag);
    this->range = range;
    this->offsetFID = offsetFID;
    this->BloomFilter = BloomFilter;
}

int32_t rice::p2p::glacier::v2::messaging::GlacierSyncMessage::getOffsetFID()
{
    return offsetFID;
}

rice::p2p::commonapi::IdRange* rice::p2p::glacier::v2::messaging::GlacierSyncMessage::getRange()
{
    return range;
}

rice::p2p::glacier::v2::BloomFilter* rice::p2p::glacier::v2::messaging::GlacierSyncMessage::getBloomFilter()
{
    return BloomFilter;
}

java::lang::String* rice::p2p::glacier::v2::messaging::GlacierSyncMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"[GlacierSync for range "_j)->append(static_cast< ::java::lang::Object* >(range))
        ->append(u", offset "_j)
        ->append(offsetFID)
        ->append(u"]"_j)->toString();
}

int16_t rice::p2p::glacier::v2::messaging::GlacierSyncMessage::getType()
{
    return TYPE;
}

void rice::p2p::glacier::v2::messaging::GlacierSyncMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    super::serialize(buf);
    npc(buf)->writeInt(offsetFID);
    npc(range)->serialize(buf);
    npc(BloomFilter)->serialize(buf);
}

rice::p2p::glacier::v2::messaging::GlacierSyncMessage* rice::p2p::glacier::v2::messaging::GlacierSyncMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new GlacierSyncMessage(buf, endpoint);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::glacier::v2::messaging::GlacierSyncMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    offsetFID = npc(buf)->readInt();
    range = npc(endpoint)->readIdRange(buf);
    BloomFilter = new ::rice::p2p::glacier::v2::BloomFilter(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierSyncMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.messaging.GlacierSyncMessage", 48);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierSyncMessage::getClass0()
{
    return class_();
}

