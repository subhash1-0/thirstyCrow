// Generated from /pastry-2.1/src/rice/p2p/aggregation/raw/RawAggregate.java
#include <rice/p2p/aggregation/raw/RawAggregate.hpp>

#include <java/io/IOException.hpp>
#include <java/io/ObjectInputStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/security/MessageDigest.hpp>
#include <java/security/NoSuchAlgorithmException.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/gc/GCPastContent.hpp>
#include <rice/p2p/past/gc/rawserialization/JavaSerializedGCPastContent.hpp>
#include <rice/p2p/past/gc/rawserialization/RawGCPastContent.hpp>
#include <rice/p2p/past/rawserialization/PastContentDeserializer.hpp>
#include <rice/p2p/past/rawserialization/RawPastContent.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
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

        namespace past
        {
typedef ::SubArray< ::rice::p2p::past::PastContent, ::java::lang::ObjectArray, ::java::io::SerializableArray > PastContentArray;

            namespace gc
            {
typedef ::SubArray< ::rice::p2p::past::gc::GCPastContent, ::java::lang::ObjectArray, ::rice::p2p::past::PastContentArray > GCPastContentArray;
            } // gc

            namespace rawserialization
            {
typedef ::SubArray< ::rice::p2p::past::rawserialization::RawPastContent, ::java::lang::ObjectArray, ::rice::p2p::past::PastContentArray > RawPastContentArray;
            } // rawserialization

            namespace gc
            {
                namespace rawserialization
                {
typedef ::SubArray< ::rice::p2p::past::gc::rawserialization::RawGCPastContent, ::java::lang::ObjectArray, ::rice::p2p::past::gc::GCPastContentArray, ::rice::p2p::past::rawserialization::RawPastContentArray > RawGCPastContentArray;
                } // rawserialization
            } // gc
        } // past
    } // p2p
} // rice

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

rice::p2p::aggregation::raw::RawAggregate::RawAggregate(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::aggregation::raw::RawAggregate::RawAggregate(::rice::p2p::past::gc::GCPastContentArray* components, ::rice::p2p::commonapi::IdArray* pointers) 
    : RawAggregate(*static_cast< ::default_init_tag* >(0))
{
    ctor(components,pointers);
}

rice::p2p::aggregation::raw::RawAggregate::RawAggregate(::rice::p2p::past::gc::rawserialization::RawGCPastContentArray* components, ::rice::p2p::commonapi::IdArray* pointers) 
    : RawAggregate(*static_cast< ::default_init_tag* >(0))
{
    ctor(components,pointers);
}

rice::p2p::aggregation::raw::RawAggregate::RawAggregate(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* contentDeserializer)  /* throws(IOException) */
    : RawAggregate(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint,contentDeserializer);
}

constexpr int64_t rice::p2p::aggregation::raw::RawAggregate::serialVersionUID;

constexpr int16_t rice::p2p::aggregation::raw::RawAggregate::TYPE;

void rice::p2p::aggregation::raw::RawAggregate::ctor(::rice::p2p::past::gc::GCPastContentArray* components, ::rice::p2p::commonapi::IdArray* pointers)
{
    super::ctor(components, pointers);
    buildRawComponents(components);
    this->myId = nullptr;
    this->pointers = pointers;
}

void rice::p2p::aggregation::raw::RawAggregate::ctor(::rice::p2p::past::gc::rawserialization::RawGCPastContentArray* components, ::rice::p2p::commonapi::IdArray* pointers)
{
    super::ctor(components, pointers);
    this->rawComponents = components;
    this->myId = nullptr;
    this->pointers = pointers;
}

int32_t rice::p2p::aggregation::raw::RawAggregate::numComponents()
{
    return npc(rawComponents)->length;
}

int8_tArray* rice::p2p::aggregation::raw::RawAggregate::getContentHash()
{
    ::int8_tArray* bytes = nullptr;
    auto numBytes = int32_t(0);
    try {
        auto buf = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
        serializeHelper(buf);
        bytes = npc(buf)->getBytes();
        numBytes = npc(buf)->getWritten();
    } catch (::java::io::IOException* ioe) {
        return nullptr;
    }
    ::java::security::MessageDigest* md = nullptr;
    try {
        md = ::java::security::MessageDigest::getInstance(u"SHA"_j);
    } catch (::java::security::NoSuchAlgorithmException* e) {
        return nullptr;
    }
    npc(md)->reset();
    npc(md)->update(bytes, 0, numBytes);
    return npc(md)->digest();
}

int16_t rice::p2p::aggregation::raw::RawAggregate::getType()
{
    return TYPE;
}

void rice::p2p::aggregation::raw::RawAggregate::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    npc(buf)->writeShort(npc(myId)->getType());
    npc(myId)->serialize(buf);
    serializeHelper(buf);
}

void rice::p2p::aggregation::raw::RawAggregate::serializeHelper(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeShort(static_cast< int16_t >(npc(pointers)->length));
    for (auto i = int32_t(0); i < npc(pointers)->length; i++) {
        npc(buf)->writeShort(npc((*pointers)[i])->getType());
        npc((*pointers)[i])->serialize(buf);
    }
    npc(buf)->writeShort(static_cast< int16_t >(npc(rawComponents)->length));
    for (auto i = int32_t(0); i < npc(rawComponents)->length; i++) {
        npc(buf)->writeShort(npc((*rawComponents)[i])->getType());
        npc((*rawComponents)[i])->serialize(buf);
    }
}

void rice::p2p::aggregation::raw::RawAggregate::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* contentDeserializer) /* throws(IOException) */
{
    super::ctor(nullptr, nullptr);
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        myId = npc(endpoint)->readId(buf, npc(buf)->readShort());
        pointers = new ::rice::p2p::commonapi::IdArray(npc(buf)->readShort());
        for (auto i = int32_t(0); i < npc(pointers)->length; i++) {
            pointers->set(i, npc(endpoint)->readId(buf, npc(buf)->readShort()));
        }
        rawComponents = new ::rice::p2p::past::gc::rawserialization::RawGCPastContentArray(npc(buf)->readShort());
        components = new ::rice::p2p::past::gc::GCPastContentArray(npc(rawComponents)->length);
        for (auto i = int32_t(0); i < npc(rawComponents)->length; i++) {
            auto type = npc(buf)->readShort();
            auto temp = java_cast< ::rice::p2p::past::gc::GCPastContent* >(npc(contentDeserializer)->deserializePastContent(buf, endpoint, type));
            if(type == 0) {
                components->set(i, temp);
                rawComponents->set(i, new ::rice::p2p::past::gc::rawserialization::JavaSerializedGCPastContent(temp));
            } else {
                components->set(i, temp);
                rawComponents->set(i, java_cast< ::rice::p2p::past::gc::rawserialization::RawGCPastContent* >(temp));
            }
        }
        break;
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::aggregation::raw::RawAggregate::readObject(::java::io::ObjectInputStream* in) /* throws(IOException, ClassNotFoundException) */
{
    npc(in)->defaultReadObject();
    buildRawComponents(components);
}

void rice::p2p::aggregation::raw::RawAggregate::buildRawComponents(::rice::p2p::past::gc::GCPastContentArray* components)
{
    this->rawComponents = new ::rice::p2p::past::gc::rawserialization::RawGCPastContentArray(npc(components)->length);
    for (auto i = int32_t(0); i < npc(rawComponents)->length; i++) {
        if(dynamic_cast< ::rice::p2p::past::gc::rawserialization::RawGCPastContent* >((*rawComponents)[i]) != nullptr) {
            this->rawComponents->set(i, java_cast< ::rice::p2p::past::gc::rawserialization::RawGCPastContent* >((*components)[i]));
        } else {
            this->rawComponents->set(i, new ::rice::p2p::past::gc::rawserialization::JavaSerializedGCPastContent((*components)[i]));
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::raw::RawAggregate::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.aggregation.raw.RawAggregate", 37);
    return c;
}

rice::p2p::past::PastContent* rice::p2p::aggregation::raw::RawAggregate::checkInsert(::rice::p2p::commonapi::Id* id, ::rice::p2p::past::PastContent* existingContent)
{
    return Aggregate::checkInsert(id, existingContent);
}

rice::p2p::past::PastContentHandle* rice::p2p::aggregation::raw::RawAggregate::getHandle(::rice::p2p::past::Past* local)
{
    return Aggregate::getHandle(local);
}

rice::p2p::commonapi::Id* rice::p2p::aggregation::raw::RawAggregate::getId()
{
    return Aggregate::getId();
}

bool rice::p2p::aggregation::raw::RawAggregate::isMutable()
{
    return Aggregate::isMutable();
}

rice::p2p::past::gc::GCPastContentHandle* rice::p2p::aggregation::raw::RawAggregate::getHandle(::rice::p2p::past::gc::GCPast* local, int64_t expiration)
{
    return Aggregate::getHandle(local, expiration);
}

rice::p2p::past::gc::GCPastMetadata* rice::p2p::aggregation::raw::RawAggregate::getMetadata(int64_t expiration)
{
    return Aggregate::getMetadata(expiration);
}

int64_t rice::p2p::aggregation::raw::RawAggregate::getVersion()
{
    return Aggregate::getVersion();
}

java::lang::Class* rice::p2p::aggregation::raw::RawAggregate::getClass0()
{
    return class_();
}

