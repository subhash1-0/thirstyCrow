// Generated from /pastry-2.1/src/rice/pastry/join/InitiateJoin.java
#include <rice/pastry/join/InitiateJoin.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Observable.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/join/JoinAddress.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace util
    {
typedef ::SubArray< ::java::util::Observable, ::java::lang::ObjectArray > ObservableArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandle, ::java::util::ObservableArray, ::java::io::SerializableArray > NodeHandleArray;

            namespace rawserialization
            {
typedef ::SubArray< ::rice::p2p::commonapi::rawserialization::RawSerializable, ::java::lang::ObjectArray > RawSerializableArray;
            } // rawserialization
        } // commonapi
    } // p2p

    namespace pastry
    {
typedef ::SubArray< ::rice::pastry::NodeHandle, ::rice::p2p::commonapi::NodeHandleArray, ::rice::p2p::commonapi::rawserialization::RawSerializableArray > NodeHandleArray;
    } // pastry
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

rice::pastry::join::InitiateJoin::InitiateJoin(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::join::InitiateJoin::InitiateJoin(::java::util::Collection* nh) 
    : InitiateJoin(*static_cast< ::default_init_tag* >(0))
{
    ctor(nh);
}

rice::pastry::join::InitiateJoin::InitiateJoin(::java::util::Date* stamp, ::java::util::Collection* nh) 
    : InitiateJoin(*static_cast< ::default_init_tag* >(0))
{
    ctor(stamp,nh);
}

void rice::pastry::join::InitiateJoin::ctor(::java::util::Collection* nh)
{
    ctor(nullptr, nh);
}

void rice::pastry::join::InitiateJoin::ctor(::java::util::Date* stamp, ::java::util::Collection* nh)
{
    super::ctor(JoinAddress::getCode(), stamp);
    handle = java_cast< ::rice::pastry::NodeHandleArray* >(npc(nh)->toArray_(new ::rice::pastry::NodeHandleArray(int32_t(1))));
}

rice::pastry::NodeHandle* rice::pastry::join::InitiateJoin::getHandle()
{
    for (auto i = int32_t(0); i < npc(handle)->length; i++) {
        if(npc((*handle)[i])->isAlive())
            return (*handle)[i];

    }
    return nullptr;
}

java::lang::String* rice::pastry::join::InitiateJoin::toString()
{
    auto s = u"IJ{"_j;
    for (auto i = int32_t(0); i < npc(handle)->length; i++) {
        s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >((*handle)[i]))->append(u":"_j)
            ->append(npc((*handle)[i])->isAlive())->toString())->toString();
        if(i != npc(handle)->length - int32_t(1))
            s = ::java::lang::StringBuilder(s).append(u","_j)->toString();

    }
    s = ::java::lang::StringBuilder(s).append(u"}"_j)->toString();
    return s;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::join::InitiateJoin::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.join.InitiateJoin", 29);
    return c;
}

java::lang::Class* rice::pastry::join::InitiateJoin::getClass0()
{
    return class_();
}

