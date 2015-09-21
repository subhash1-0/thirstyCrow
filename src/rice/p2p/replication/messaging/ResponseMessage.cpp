// Generated from /pastry-2.1/src/rice/p2p/replication/messaging/ResponseMessage.java
#include <rice/p2p/replication/messaging/ResponseMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
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
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
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
typedef ::SubArray< ::rice::p2p::commonapi::IdRange, ::java::lang::ObjectArray, ::java::io::SerializableArray > IdRangeArray;
typedef ::SubArray< ::rice::p2p::commonapi::IdSet, ::java::lang::ObjectArray, ::java::io::SerializableArray > IdSetArray;
typedef ::SubArray< ::rice::p2p::commonapi::IdArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > IdArrayArray;
        } // commonapi
    } // p2p
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::replication::messaging::ResponseMessage::ResponseMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::replication::messaging::ResponseMessage::ResponseMessage(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::IdRangeArray* ranges, ::rice::p2p::commonapi::IdSetArray* setA) 
    : ResponseMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(source,ranges,setA);
}

rice::p2p::replication::messaging::ResponseMessage::ResponseMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : ResponseMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::replication::messaging::ResponseMessage::TYPE;

void rice::p2p::replication::messaging::ResponseMessage::ctor(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::IdRangeArray* ranges, ::rice::p2p::commonapi::IdSetArray* setA)
{
    super::ctor(source);
    this->ranges = ranges;
    ids = new ::rice::p2p::commonapi::IdArrayArray(npc(setA)->length);
    for (auto i = int32_t(0); i < npc(setA)->length; i++) {
        ids->set(i, npc((*setA)[i])->asArray_());
    }
}

rice::p2p::commonapi::IdRangeArray* rice::p2p::replication::messaging::ResponseMessage::getRanges()
{
    return ranges;
}

rice::p2p::commonapi::IdArrayArray* rice::p2p::replication::messaging::ResponseMessage::getIdSets()
{
    return ids;
}

java::lang::String* rice::p2p::replication::messaging::ResponseMessage::toString()
{
    auto numResponses = int32_t(0);
    for (auto a = int32_t(0); a < npc(ids)->length; a++) {
        numResponses += npc((*ids)[a])->length;
    }
    return ::java::lang::StringBuilder().append(u"ResponseMessage("_j)->append(static_cast< ::java::lang::Object* >(getSource()))
        ->append(u"):"_j)
        ->append(numResponses)->toString();
}

int16_t rice::p2p::replication::messaging::ResponseMessage::getType()
{
    return TYPE;
}

void rice::p2p::replication::messaging::ResponseMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    super::serialize(buf);
    npc(buf)->writeInt(npc(ids)->length);
    for (auto i = int32_t(0); i < npc(ids)->length; i++) {
        auto thisRow = (*ids)[i];
        npc(buf)->writeInt(npc(thisRow)->length);
        for (auto j = int32_t(0); j < npc(thisRow)->length; j++) {
            npc(buf)->writeShort(npc((*thisRow)[j])->getType());
            npc((*thisRow)[j])->serialize(buf);
        }
    }
    npc(buf)->writeInt(npc(ranges)->length);
    for (auto i = int32_t(0); i < npc(ranges)->length; i++) {
        npc((*ranges)[i])->serialize(buf);
    }
}

rice::p2p::replication::messaging::ResponseMessage* rice::p2p::replication::messaging::ResponseMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new ResponseMessage(buf, endpoint);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::replication::messaging::ResponseMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    ids = new ::rice::p2p::commonapi::IdArrayArray(npc(buf)->readInt());
    for (auto i = int32_t(0); i < npc(ids)->length; i++) {
        ids->set(i, new ::rice::p2p::commonapi::IdArray(npc(buf)->readInt()));
        for (auto j = int32_t(0); j < npc((*ids)[i])->length; j++) {
            (*ids)[i]->set(j, npc(endpoint)->readId(buf, npc(buf)->readShort()));
        }
    }
    ranges = new ::rice::p2p::commonapi::IdRangeArray(npc(buf)->readInt());
    for (auto i = int32_t(0); i < npc(ranges)->length; i++) {
        ranges->set(i, npc(endpoint)->readIdRange(buf));
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::messaging::ResponseMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.replication.messaging.ResponseMessage", 46);
    return c;
}

java::lang::Class* rice::p2p::replication::messaging::ResponseMessage::getClass0()
{
    return class_();
}

