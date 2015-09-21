// Generated from /pastry-2.1/src/rice/p2p/aggregation/Aggregate.java
#include <rice/p2p/aggregation/Aggregate.hpp>

#include <java/io/ByteArrayOutputStream.hpp>
#include <java/io/IOException.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/security/MessageDigest.hpp>
#include <java/security/NoSuchAlgorithmException.hpp>
#include <rice/p2p/aggregation/AggregateHandle.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/Past.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/gc/GCPast.hpp>
#include <rice/p2p/past/gc/GCPastContent.hpp>
#include <rice/p2p/past/gc/GCPastMetadata.hpp>
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
        } // past
    } // p2p
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::Aggregate::Aggregate(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::aggregation::Aggregate::Aggregate(::rice::p2p::past::gc::GCPastContentArray* components, ::rice::p2p::commonapi::IdArray* pointers) 
    : Aggregate(*static_cast< ::default_init_tag* >(0))
{
    ctor(components,pointers);
}

constexpr int64_t rice::p2p::aggregation::Aggregate::serialVersionUID;

void rice::p2p::aggregation::Aggregate::ctor(::rice::p2p::past::gc::GCPastContentArray* components, ::rice::p2p::commonapi::IdArray* pointers)
{
    super::ctor();
    this->components = components;
    this->myId = nullptr;
    this->pointers = pointers;
}

void rice::p2p::aggregation::Aggregate::setId(::rice::p2p::commonapi::Id* myId)
{
    this->myId = myId;
}

rice::p2p::commonapi::Id* rice::p2p::aggregation::Aggregate::getId()
{
    return myId;
}

rice::p2p::commonapi::IdArray* rice::p2p::aggregation::Aggregate::getPointers()
{
    return pointers;
}

int32_t rice::p2p::aggregation::Aggregate::numComponents()
{
    return npc(components)->length;
}

rice::p2p::past::gc::GCPastContent* rice::p2p::aggregation::Aggregate::getComponent(int32_t index)
{
    return (*components)[index];
}

int64_t rice::p2p::aggregation::Aggregate::getVersion()
{
    return 0;
}

bool rice::p2p::aggregation::Aggregate::isMutable()
{
    return false;
}

rice::p2p::past::PastContent* rice::p2p::aggregation::Aggregate::checkInsert(::rice::p2p::commonapi::Id* id, ::rice::p2p::past::PastContent* existingContent) /* throws(PastException) */
{
    if(existingContent == nullptr) {
        return this;
    } else {
        return existingContent;
    }
}

int8_tArray* rice::p2p::aggregation::Aggregate::getContentHash()
{
    ::int8_tArray* bytes = nullptr;
    try {
        auto byteStream = new ::java::io::ByteArrayOutputStream();
        auto objectStream = new ::java::io::ObjectOutputStream(byteStream);
        npc(objectStream)->writeObject(static_cast< ::java::lang::Object* >(components));
        npc(objectStream)->writeObject(static_cast< ::java::lang::Object* >(pointers));
        npc(objectStream)->flush();
        bytes = npc(byteStream)->toByteArray_();
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
    npc(md)->update(bytes);
    return npc(md)->digest();
}

rice::p2p::past::PastContentHandle* rice::p2p::aggregation::Aggregate::getHandle(::rice::p2p::past::Past* local)
{
    return new AggregateHandle(npc(local)->getLocalNodeHandle(), myId, getVersion(), ::rice::p2p::past::gc::GCPast::INFINITY_EXPIRATION);
}

rice::p2p::past::gc::GCPastContentHandle* rice::p2p::aggregation::Aggregate::getHandle(::rice::p2p::past::gc::GCPast* local, int64_t expiration)
{
    return new AggregateHandle(npc(local)->getLocalNodeHandle(), myId, getVersion(), expiration);
}

rice::p2p::past::gc::GCPastMetadata* rice::p2p::aggregation::Aggregate::getMetadata(int64_t expiration)
{
    return new ::rice::p2p::past::gc::GCPastMetadata(expiration);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::Aggregate::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.aggregation.Aggregate", 30);
    return c;
}

java::lang::Class* rice::p2p::aggregation::Aggregate::getClass0()
{
    return class_();
}

