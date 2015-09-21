// Generated from /pastry-2.1/src/rice/p2p/past/testing/PastRegrTest.java
#include <rice/p2p/past/testing/PastRegrTest_testLookupHandles_5.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testLookupHandles_5_receive_5_1.hpp>
#include <rice/p2p/past/testing/PastRegrTest.hpp>
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

rice::p2p::past::testing::PastRegrTest_testLookupHandles_5::PastRegrTest_testLookupHandles_5(PastRegrTest *PastRegrTest_this, ::rice::p2p::past::PastImpl* local, ::rice::p2p::commonapi::Id* remoteId)
    : super(PastRegrTest_this, *static_cast< ::default_init_tag* >(0))
    , local(local)
    , remoteId(remoteId)
{
    clinit();
    ctor();
}

void rice::p2p::past::testing::PastRegrTest_testLookupHandles_5::receive(::java::lang::Object* result) /* throws(Exception) */
{
    PastRegrTest_this->assertTrue(u"Insert of file result should not be null"_j, result != nullptr);
    PastRegrTest_this->assertTrue(u"Insert of file should return Boolean[]"_j, dynamic_cast< ::java::lang::BooleanArray* >(result) != nullptr);
    for (auto i = int32_t(0); i < npc((java_cast< ::java::lang::BooleanArray* >(result)))->length; i++) {
        PastRegrTest_this->assertTrue(u"Insert of file should not return null at replica"_j, (*(java_cast< ::java::lang::BooleanArray* >(result)))[i] != nullptr);
        PastRegrTest_this->assertTrue(u"Insert of file should succeed at replica"_j, npc((*(java_cast< ::java::lang::BooleanArray* >(result)))[i])->booleanValue());
    }
    PastRegrTest_this->stepDone();
    PastRegrTest_this->runReplicaMaintence();
    PastRegrTest_this->stepStart(u"Remote Handles Lookup - 1 Replica"_j);
    npc(local)->lookupHandles(remoteId, int32_t(1), static_cast< ::rice::Continuation* >(new PastRegrTest_testLookupHandles_5_receive_5_1(this, remoteId, local)));
    PastRegrTest_this->simulate();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::PastRegrTest_testLookupHandles_5::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::PastRegrTest_testLookupHandles_5::getClass0()
{
    return class_();
}

