// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregateDescriptor.java
#include <rice/p2p/aggregation/AggregateDescriptor.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/aggregation/ObjectDescriptor.hpp>
#include <rice/p2p/commonapi/Id.hpp>
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
        namespace aggregation
        {
typedef ::SubArray< ::rice::p2p::aggregation::ObjectDescriptor, ::java::lang::ObjectArray, ::java::io::SerializableArray, ::java::lang::ComparableArray > ObjectDescriptorArray;
        } // aggregation

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

rice::p2p::aggregation::AggregateDescriptor::AggregateDescriptor(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::aggregation::AggregateDescriptor::AggregateDescriptor(::rice::p2p::commonapi::Id* key, int64_t currentLifetime, ObjectDescriptorArray* objects, ::rice::p2p::commonapi::IdArray* pointers) 
    : AggregateDescriptor(*static_cast< ::default_init_tag* >(0))
{
    ctor(key,currentLifetime,objects,pointers);
}

void rice::p2p::aggregation::AggregateDescriptor::ctor(::rice::p2p::commonapi::Id* key, int64_t currentLifetime, ObjectDescriptorArray* objects, ::rice::p2p::commonapi::IdArray* pointers)
{
    super::ctor();
    this->key = key;
    this->currentLifetime = currentLifetime;
    this->objects = objects;
    this->pointers = pointers;
    this->marker = false;
    this->referenceCount = 0;
}

int32_t rice::p2p::aggregation::AggregateDescriptor::lookupNewest(::rice::p2p::commonapi::Id* id)
{
    auto result = -int32_t(1);
    for (auto i = int32_t(0); i < npc(objects)->length; i++) 
                if(npc(npc((*objects)[i])->key)->equals(id))
            if((result == -int32_t(1)) || (npc((*objects)[i])->version > npc((*objects)[result])->version))
                result = i;



    return result;
}

int32_t rice::p2p::aggregation::AggregateDescriptor::lookupSpecific(::rice::p2p::commonapi::Id* id, int64_t version)
{
    for (auto i = int32_t(0); i < npc(objects)->length; i++) 
                if(npc(npc((*objects)[i])->key)->equals(id) && (npc((*objects)[i])->version == version))
            return i;


    return -int32_t(1);
}

void rice::p2p::aggregation::AggregateDescriptor::addReference()
{
    referenceCount++;
}

int32_t rice::p2p::aggregation::AggregateDescriptor::objectsAliveAt(int64_t pointInTime)
{
    auto result = int32_t(0);
    for (auto i = int32_t(0); i < npc(objects)->length; i++) 
                if(npc((*objects)[i])->isAliveAt(pointInTime))
            result++;


    return result;
}

int32_t rice::p2p::aggregation::AggregateDescriptor::bytesAliveAt(int64_t pointInTime)
{
    auto result = int32_t(0);
    for (auto i = int32_t(0); i < npc(objects)->length; i++) 
                if(npc((*objects)[i])->isAliveAt(pointInTime))
            result += npc((*objects)[i])->size;


    return result;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregateDescriptor::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.aggregation.AggregateDescriptor", 40);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregateDescriptor::getClass0()
{
    return class_();
}

