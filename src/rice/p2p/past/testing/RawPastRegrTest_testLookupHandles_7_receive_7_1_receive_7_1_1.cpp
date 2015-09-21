// Generated from /pastry-2.1/src/rice/p2p/past/testing/RawPastRegrTest.java
#include <rice/p2p/past/testing/RawPastRegrTest_testLookupHandles_7_receive_7_1_receive_7_1_1.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testLookupHandles_7.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testLookupHandles_7_receive_7_1.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testLookupHandles_7_receive_7_1_receive_7_1_1_receive_7_1_1_1.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest.hpp>
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

rice::p2p::past::testing::RawPastRegrTest_testLookupHandles_7_receive_7_1_receive_7_1_1::RawPastRegrTest_testLookupHandles_7_receive_7_1_receive_7_1_1(RawPastRegrTest_testLookupHandles_7_receive_7_1 *RawPastRegrTest_testLookupHandles_7_receive_7_1_this, ::rice::p2p::commonapi::Id* remoteId, ::rice::p2p::past::PastImpl* local)
    : super(RawPastRegrTest_testLookupHandles_7_receive_7_1_this->RawPastRegrTest_testLookupHandles_7_this->RawPastRegrTest_this, *static_cast< ::default_init_tag* >(0))
    , RawPastRegrTest_testLookupHandles_7_receive_7_1_this(RawPastRegrTest_testLookupHandles_7_receive_7_1_this)
    , remoteId(remoteId)
    , local(local)
{
    clinit();
    ctor();
}

void rice::p2p::past::testing::RawPastRegrTest_testLookupHandles_7_receive_7_1_receive_7_1_1::receive(::java::lang::Object* result) /* throws(Exception) */
{
    RawPastRegrTest_testLookupHandles_7_receive_7_1_this->RawPastRegrTest_testLookupHandles_7_this->RawPastRegrTest_this->assertTrue(u"Replicas should not be null"_j, result != nullptr);
    RawPastRegrTest_testLookupHandles_7_receive_7_1_this->RawPastRegrTest_testLookupHandles_7_this->RawPastRegrTest_this->assertTrue(u"Replicas should be handle[]"_j, dynamic_cast< ::rice::p2p::past::PastContentHandleArray* >(result) != nullptr);
    auto handles = java_cast< ::rice::p2p::past::PastContentHandleArray* >(result);
    RawPastRegrTest_testLookupHandles_7_receive_7_1_this->RawPastRegrTest_testLookupHandles_7_this->RawPastRegrTest_this->assertTrue(u"All replicas should be returned"_j, (npc(handles)->length == RawPastRegrTest::REPLICATION_FACTOR + int32_t(1)) || ((RawPastRegrTest_testLookupHandles_7_receive_7_1_this->RawPastRegrTest_testLookupHandles_7_this->RawPastRegrTest_this->NUM_NODES < RawPastRegrTest::REPLICATION_FACTOR + int32_t(1)) && (npc(handles)->length) == RawPastRegrTest_testLookupHandles_7_receive_7_1_this->RawPastRegrTest_testLookupHandles_7_this->RawPastRegrTest_this->NUM_NODES));
    for (auto i = int32_t(0); i < npc(handles)->length; i++) {
        RawPastRegrTest_testLookupHandles_7_receive_7_1_this->RawPastRegrTest_testLookupHandles_7_this->RawPastRegrTest_this->assertTrue(::java::lang::StringBuilder().append(u"Replica "_j)->append(i)
            ->append(u" should not be null"_j)->toString(), (*handles)[i] != nullptr);
        RawPastRegrTest_testLookupHandles_7_receive_7_1_this->RawPastRegrTest_testLookupHandles_7_this->RawPastRegrTest_this->assertEquals(::java::lang::StringBuilder().append(u"Replica "_j)->append(i)
            ->append(u" should be for right object"_j)->toString(), remoteId, npc((*handles)[i])->getId());
    }
    for (auto i = int32_t(0); i < npc(handles)->length; i++) {
        for (auto j = int32_t(0); j < npc(handles)->length; j++) {
            if(i != j) {
                RawPastRegrTest_testLookupHandles_7_receive_7_1_this->RawPastRegrTest_testLookupHandles_7_this->RawPastRegrTest_this->assertTrue(::java::lang::StringBuilder().append(u"Handles "_j)->append(static_cast< ::java::lang::Object* >((*handles)[i]))
                    ->append(u" and "_j)
                    ->append(static_cast< ::java::lang::Object* >((*handles)[j]))
                    ->append(u" should be different"_j)->toString(), (!npc(npc(npc((*handles)[i])->getNodeHandle())->getId())->equals(npc(npc((*handles)[j])->getNodeHandle())->getId())));
            }
        }
    }
    RawPastRegrTest_testLookupHandles_7_receive_7_1_this->RawPastRegrTest_testLookupHandles_7_this->RawPastRegrTest_this->stepDone();
    RawPastRegrTest_testLookupHandles_7_receive_7_1_this->RawPastRegrTest_testLookupHandles_7_this->RawPastRegrTest_this->stepStart(u"Remote Handles Lookup - 12 Replicas"_j);
    npc(local)->lookupHandles(remoteId, int32_t(12), static_cast< ::rice::Continuation* >(new RawPastRegrTest_testLookupHandles_7_receive_7_1_receive_7_1_1_receive_7_1_1_1(this, remoteId)));
    RawPastRegrTest_testLookupHandles_7_receive_7_1_this->RawPastRegrTest_testLookupHandles_7_this->RawPastRegrTest_this->simulate();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_testLookupHandles_7_receive_7_1_receive_7_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_testLookupHandles_7_receive_7_1_receive_7_1_1::getClass0()
{
    return class_();
}

