// Generated from /pastry-2.1/src/rice/p2p/past/testing/PastRegrTest.java
#include <rice/p2p/past/testing/PastRegrTest_testCaching_6_receive_6_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/p2p/commonapi/RouteMessage.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/messaging/LookupMessage.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testCaching_6.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testCaching_6_receive_6_1_receive_6_1_1.hpp>
#include <rice/p2p/past/testing/PastRegrTest_TestRouteMessage.hpp>
#include <rice/p2p/past/testing/PastRegrTest.hpp>
#include <rice/persistence/StorageManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::testing::PastRegrTest_testCaching_6_receive_6_1::PastRegrTest_testCaching_6_receive_6_1(PastRegrTest_testCaching_6 *PastRegrTest_testCaching_6_this, ::rice::p2p::past::PastContent* file1, ::rice::p2p::commonapi::Id* id2, ::rice::p2p::past::PastImpl* local, ::rice::p2p::past::PastContent* file2, ::rice::p2p::past::PastContent* file3)
    : super(PastRegrTest_testCaching_6_this->PastRegrTest_this, *static_cast< ::default_init_tag* >(0))
    , PastRegrTest_testCaching_6_this(PastRegrTest_testCaching_6_this)
    , file1(file1)
    , id2(id2)
    , local(local)
    , file2(file2)
    , file3(file3)
{
    clinit();
    ctor();
}

void rice::p2p::past::testing::PastRegrTest_testCaching_6_receive_6_1::receive(::java::lang::Object* result) /* throws(Exception) */
{
    PastRegrTest_testCaching_6_this->PastRegrTest_this->assertTrue(u"File should not be null"_j, result != nullptr);
    PastRegrTest_testCaching_6_this->PastRegrTest_this->assertEquals(u"Lookup of file should be correct"_j, file1, result);
    PastRegrTest_testCaching_6_this->PastRegrTest_this->stepDone();
    PastRegrTest_testCaching_6_this->PastRegrTest_this->stepStart(u"Caching Mutable Object"_j);
    auto const lmsg = new ::rice::p2p::past::messaging::LookupMessage(int32_t(1), id2, npc(local)->getLocalNodeHandle(), id2);
    npc(lmsg)->receiveResult(static_cast< ::java::lang::Object* >(file2));
    PastRegrTest_testCaching_6_this->PastRegrTest_this->assertTrue(u"Message should continue to be routed"_j, npc(local)->forward(static_cast< ::rice::p2p::commonapi::RouteMessage* >(new PastRegrTest_TestRouteMessage(id2, nullptr, lmsg))));
    PastRegrTest_testCaching_6_this->PastRegrTest_this->stepDone();
    PastRegrTest_testCaching_6_this->PastRegrTest_this->stepStart(u"Cache Shouldn't Contain Object"_j);
    npc(npc(local)->getStorageManager())->getObject(id2, new PastRegrTest_testCaching_6_receive_6_1_receive_6_1_1(this, lmsg, file3, local, id2));
    PastRegrTest_testCaching_6_this->PastRegrTest_this->simulate();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::PastRegrTest_testCaching_6_receive_6_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::PastRegrTest_testCaching_6_receive_6_1::getClass0()
{
    return class_();
}

