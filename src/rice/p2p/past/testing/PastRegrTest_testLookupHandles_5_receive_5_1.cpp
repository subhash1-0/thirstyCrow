// Generated from /pastry-2.1/src/rice/p2p/past/testing/PastRegrTest.java
#include <rice/p2p/past/testing/PastRegrTest_testLookupHandles_5_receive_5_1.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/System.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testLookupHandles_5.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testLookupHandles_5_receive_5_1_receive_5_1_1.hpp>
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
} // java

namespace rice
{
    namespace p2p
    {
        namespace past
        {
typedef ::SubArray< ::rice::p2p::past::PastContentHandle, ::java::lang::ObjectArray, ::java::io::SerializableArray > PastContentHandleArray;
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

rice::p2p::past::testing::PastRegrTest_testLookupHandles_5_receive_5_1::PastRegrTest_testLookupHandles_5_receive_5_1(PastRegrTest_testLookupHandles_5 *PastRegrTest_testLookupHandles_5_this, ::rice::p2p::commonapi::Id* remoteId, ::rice::p2p::past::PastImpl* local)
    : super(PastRegrTest_testLookupHandles_5_this->PastRegrTest_this, *static_cast< ::default_init_tag* >(0))
    , PastRegrTest_testLookupHandles_5_this(PastRegrTest_testLookupHandles_5_this)
    , remoteId(remoteId)
    , local(local)
{
    clinit();
    ctor();
}

void rice::p2p::past::testing::PastRegrTest_testLookupHandles_5_receive_5_1::receive(::java::lang::Object* result) /* throws(Exception) */
{
    PastRegrTest_testLookupHandles_5_this->PastRegrTest_this->assertTrue(u"Replicas should not be null"_j, result != nullptr);
    PastRegrTest_testLookupHandles_5_this->PastRegrTest_this->assertTrue(u"Replicas should be handle[]"_j, dynamic_cast< ::rice::p2p::past::PastContentHandleArray* >(result) != nullptr);
    PastRegrTest_testLookupHandles_5_this->PastRegrTest_this->assertTrue(u"Only 1 replica should be returned"_j, npc((java_cast< ::rice::p2p::past::PastContentHandleArray* >(result)))->length == 1);
    if((*(java_cast< ::rice::p2p::past::PastContentHandleArray* >(result)))[int32_t(0)] == nullptr) {
        npc(::java::lang::System::out())->println(u"PastRegrTest.problem"_j);
    }
    PastRegrTest_testLookupHandles_5_this->PastRegrTest_this->assertEquals(u"Replica should be for right object"_j, remoteId, npc((*(java_cast< ::rice::p2p::past::PastContentHandleArray* >(result)))[int32_t(0)])->getId());
    PastRegrTest_testLookupHandles_5_this->PastRegrTest_this->stepDone();
    PastRegrTest_testLookupHandles_5_this->PastRegrTest_this->stepStart(u"Remote Handles Lookup - All Replicas"_j);
    npc(local)->lookupHandles(remoteId, PastRegrTest::REPLICATION_FACTOR + int32_t(1), static_cast< ::rice::Continuation* >(new PastRegrTest_testLookupHandles_5_receive_5_1_receive_5_1_1(this, remoteId, local)));
    PastRegrTest_testLookupHandles_5_this->PastRegrTest_this->simulate();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::PastRegrTest_testLookupHandles_5_receive_5_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::PastRegrTest_testLookupHandles_5_receive_5_1::getClass0()
{
    return class_();
}

