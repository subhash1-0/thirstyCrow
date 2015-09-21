// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastImpl.java
#include <rice/p2p/past/gc/GCPastImpl_refresh_2.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Arrays.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/gc/GCPastImpl.hpp>
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

rice::p2p::past::gc::GCPastImpl_refresh_2::GCPastImpl_refresh_2(GCPastImpl *GCPastImpl_this, ::rice::p2p::commonapi::IdArray* array, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , GCPastImpl_this(GCPastImpl_this)
    , array(array)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::gc::GCPastImpl_refresh_2::receiveResult(::java::lang::Object* o)
{
    auto result = new ::java::lang::ObjectArray(npc(array)->length);
    ::java::util::Arrays::fill(result, static_cast< ::java::lang::Object* >(::java::lang::Boolean::TRUE()));
    npc(parent)->receiveResult(result);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCPastImpl_refresh_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCPastImpl_refresh_2::getClass0()
{
    return class_();
}

