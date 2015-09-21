// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_reInsert_17_receiveResult_17_1.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/past/PastImpl_reInsert_17.hpp>
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
typedef ::SubArray< ::java::lang::Boolean, ObjectArray, ::java::io::SerializableArray, ComparableArray > BooleanArray;
    } // lang
} // java

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

rice::p2p::past::PastImpl_reInsert_17_receiveResult_17_1::PastImpl_reInsert_17_receiveResult_17_1(PastImpl_reInsert_17 *PastImpl_reInsert_17_this, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_reInsert_17_this(PastImpl_reInsert_17_this)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::PastImpl_reInsert_17_receiveResult_17_1::receiveResult(::java::lang::Object* result)
{
    auto results = java_cast< ::java::lang::BooleanArray* >(result);
    for (auto i = int32_t(0); i < npc(results)->length; i++) {
        if(npc((*results)[i])->booleanValue()) {
            npc(parent)->receiveResult(::java::lang::Boolean::TRUE());
            return;
        }
    }
    npc(parent)->receiveResult(::java::lang::Boolean::FALSE());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_reInsert_17_receiveResult_17_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_reInsert_17_receiveResult_17_1::getClass0()
{
    return class_();
}

