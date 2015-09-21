// Generated from /pastry-2.1/src/rice/p2p/replication/messaging/RequestMessage.java
#include <rice/p2p/replication/messaging/RequestMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/util/IdBloomFilter.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::IdRange, ::java::lang::ObjectArray, ::java::io::SerializableArray > IdRangeArray;
        } // commonapi

        namespace util
        {
typedef ::SubArray< ::rice::p2p::util::IdBloomFilter, ::java::lang::ObjectArray, ::java::io::SerializableArray > IdBloomFilterArray;
        } // util
    } // p2p
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::replication::messaging::RequestMessage::RequestMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::replication::messaging::RequestMessage::RequestMessage(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::IdRangeArray* ranges, ::rice::p2p::util::IdBloomFilterArray* filters) 
    : RequestMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(source,ranges,filters);
}

rice::p2p::replication::messaging::RequestMessage::RequestMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : RequestMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::replication::messaging::RequestMessage::TYPE;

void rice::p2p::replication::messaging::RequestMessage::ctor(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::IdRangeArray* ranges, ::rice::p2p::util::IdBloomFilterArray* filters)
{
    super::ctor(source);
    this->ranges = ranges;
    this->filters = filters;
}

rice::p2p::commonapi::IdRangeArray* rice::p2p::replication::messaging::RequestMessage::getRanges()
{
    return ranges;
}

rice::p2p::util::IdBloomFilterArray* rice::p2p::replication::messaging::RequestMessage::getFilters()
{
    return filters;
}

java::lang::String* rice::p2p::replication::messaging::RequestMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"RequestMessage("_j)->append(static_cast< ::java::lang::Object* >(getSource()))
        ->append(u"):"_j)
        ->append(static_cast< ::java::lang::Object* >((ranges == nullptr ? static_cast< ::java::lang::Integer* >(nullptr) : ::java::lang::Integer::valueOf(npc(ranges)->length))))->toString();
}

int16_t rice::p2p::replication::messaging::RequestMessage::getType()
{
    return TYPE;
}

void rice::p2p::replication::messaging::RequestMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    super::serialize(buf);
    npc(buf)->writeInt(npc(filters)->length);
    for (auto i = int32_t(0); i < npc(filters)->length; i++) {
        npc((*filters)[i])->serialize(buf);
    }
    npc(buf)->writeInt(npc(ranges)->length);
    for (auto i = int32_t(0); i < npc(ranges)->length; i++) {
        npc((*ranges)[i])->serialize(buf);
    }
}

rice::p2p::replication::messaging::RequestMessage* rice::p2p::replication::messaging::RequestMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new RequestMessage(buf, endpoint);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::replication::messaging::RequestMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    filters = new ::rice::p2p::util::IdBloomFilterArray(npc(buf)->readInt());
    for (auto i = int32_t(0); i < npc(filters)->length; i++) {
        filters->set(i, new ::rice::p2p::util::IdBloomFilter(buf));
    }
    ranges = new ::rice::p2p::commonapi::IdRangeArray(npc(buf)->readInt());
    for (auto i = int32_t(0); i < npc(ranges)->length; i++) {
        ranges->set(i, npc(endpoint)->readIdRange(buf));
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::messaging::RequestMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.replication.messaging.RequestMessage", 45);
    return c;
}

java::lang::Class* rice::p2p::replication::messaging::RequestMessage::getClass0()
{
    return class_();
}

