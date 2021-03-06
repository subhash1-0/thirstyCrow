// Generated from /pastry-2.1/src/rice/p2p/past/testing/PastRegrTest.java
#include <rice/p2p/past/testing/PastRegrTest_testCaching_6_receive_6_1_receive_6_1_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/p2p/commonapi/RouteMessage.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/messaging/LookupMessage.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testCaching_6.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testCaching_6_receive_6_1.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testCaching_6_receive_6_1_receive_6_1_1_receive_6_1_1_1.hpp>
#include <rice/p2p/past/testing/PastRegrTest_TestRouteMessage.hpp>
#include <rice/p2p/past/testing/PastRegrTest.hpp>
#include <rice/persistence/StorageManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::testing::PastRegrTest_testCaching_6_receive_6_1_receive_6_1_1::PastRegrTest_testCaching_6_receive_6_1_receive_6_1_1(PastRegrTest_testCaching_6_receive_6_1 *PastRegrTest_testCaching_6_receive_6_1_this, ::rice::p2p::past::messaging::LookupMessage* lmsg, ::rice::p2p::past::PastContent* file3, ::rice::p2p::past::PastImpl* local, ::rice::p2p::commonapi::Id* id2)
    : super(PastRegrTest_testCaching_6_receive_6_1_this->PastRegrTest_testCaching_6_this->PastRegrTest_this, *static_cast< ::default_init_tag* >(0))
    , PastRegrTest_testCaching_6_receive_6_1_this(PastRegrTest_testCaching_6_receive_6_1_this)
    , lmsg(lmsg)
    , file3(file3)
    , local(local)
    , id2(id2)
{
    clinit();
    ctor();
}

void rice::p2p::past::testing::PastRegrTest_testCaching_6_receive_6_1_receive_6_1_1::receive(::java::lang::Object* result) /* throws(Exception) */
{
    PastRegrTest_testCaching_6_receive_6_1_this->PastRegrTest_testCaching_6_this->PastRegrTest_this->assertTrue(u"Object should be null"_j, result == nullptr);
    PastRegrTest_testCaching_6_receive_6_1_this->PastRegrTest_testCaching_6_this->PastRegrTest_this->stepDone();
    PastRegrTest_testCaching_6_receive_6_1_this->PastRegrTest_testCaching_6_this->PastRegrTest_this->stepStart(u"Caching Non-Mutable Object"_j);
    npc(lmsg)->receiveResult(static_cast< ::java::lang::Object* >(file3));
    PastRegrTest_testCaching_6_receive_6_1_this->PastRegrTest_testCaching_6_this->PastRegrTest_this->assertTrue(u"Message should continue to be routed"_j, npc(local)->forward(static_cast< ::rice::p2p::commonapi::RouteMessage* >(new PastRegrTest_TestRouteMessage(id2, nullptr, lmsg))));
    PastRegrTest_testCaching_6_receive_6_1_this->PastRegrTest_testCaching_6_this->PastRegrTest_this->stepDone();
    PastRegrTest_testCaching_6_receive_6_1_this->PastRegrTest_testCaching_6_this->PastRegrTest_this->stepStart(u"Cache Should Contain Object"_j);
    npc(npc(local)->getStorageManager())->getObject(id2, new PastRegrTest_testCaching_6_receive_6_1_receive_6_1_1_receive_6_1_1_1(this, id2, local));
    PastRegrTest_testCaching_6_receive_6_1_this->PastRegrTest_testCaching_6_this->PastRegrTest_this->simulate();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::PastRegrTest_testCaching_6_receive_6_1_receive_6_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::PastRegrTest_testCaching_6_receive_6_1_receive_6_1_1::getClass0()
{
    return class_();
}

