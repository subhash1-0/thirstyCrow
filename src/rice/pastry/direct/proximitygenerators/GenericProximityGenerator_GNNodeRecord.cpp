// Generated from /pastry-2.1/src/rice/pastry/direct/proximitygenerators/GenericProximityGenerator.java
#include <rice/pastry/direct/proximitygenerators/GenericProximityGenerator_GNNodeRecord.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/lang/Float.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/pastry/direct/NodeRecord.hpp>
#include <rice/pastry/direct/proximitygenerators/GenericProximityGenerator.hpp>
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
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
    } // lang
} // java

namespace 
{
typedef ::SubArray< ::floatArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > floatArrayArray;
} // 

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

rice::pastry::direct::proximitygenerators::GenericProximityGenerator_GNNodeRecord::GenericProximityGenerator_GNNodeRecord(GenericProximityGenerator *GenericProximityGenerator_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , GenericProximityGenerator_this(GenericProximityGenerator_this)
{
    clinit();
}

rice::pastry::direct::proximitygenerators::GenericProximityGenerator_GNNodeRecord::GenericProximityGenerator_GNNodeRecord(GenericProximityGenerator *GenericProximityGenerator_this) 
    : GenericProximityGenerator_GNNodeRecord(GenericProximityGenerator_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::pastry::direct::proximitygenerators::GenericProximityGenerator_GNNodeRecord::ctor()
{
    super::ctor();
    if(GenericProximityGenerator_this->numNodes >= GenericProximityGenerator::MAXOVERLAYSIZE() * GenericProximityGenerator_this->nodesPerStub)
        throw new ::java::lang::RuntimeException(u"No more nodes int he network."_j);

    index = npc(GenericProximityGenerator_this->random)->nextInt(GenericProximityGenerator::MAXOVERLAYSIZE());
    while (GenericProximityGenerator_this->stubIsFull(index)) {
        index = npc(GenericProximityGenerator_this->random)->nextInt(GenericProximityGenerator::MAXOVERLAYSIZE());
    }
    GenericProximityGenerator_this->incrementStub(index);
}

float rice::pastry::direct::proximitygenerators::GenericProximityGenerator_GNNodeRecord::proximity(::rice::pastry::direct::NodeRecord* that)
{
    return ::java::lang::Math::round(networkDelay(that) + npc(that)->networkDelay(this));
}

float rice::pastry::direct::proximitygenerators::GenericProximityGenerator_GNNodeRecord::networkDelay(::rice::pastry::direct::NodeRecord* that)
{
    auto nr = java_cast< GenericProximityGenerator_GNNodeRecord* >(that);
    auto res = (*(*GenericProximityGenerator_this->distance)[index])[npc(nr)->index];
    if(res < 0)
        return ::java::lang::Float::MAX_VALUE;

    if((res < GenericProximityGenerator_this->MIN_DIST) && !this->equals(that))
        return GenericProximityGenerator_this->MIN_DIST;

    return res;
}

int32_t rice::pastry::direct::proximitygenerators::GenericProximityGenerator_GNNodeRecord::getIndex()
{
    return index;
}

void rice::pastry::direct::proximitygenerators::GenericProximityGenerator_GNNodeRecord::markDead()
{
    GenericProximityGenerator_this->decrementStub(index);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::proximitygenerators::GenericProximityGenerator_GNNodeRecord::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.direct.proximitygenerators.GenericProximityGenerator.GNNodeRecord", 77);
    return c;
}

java::lang::Class* rice::pastry::direct::proximitygenerators::GenericProximityGenerator_GNNodeRecord::getClass0()
{
    return class_();
}

