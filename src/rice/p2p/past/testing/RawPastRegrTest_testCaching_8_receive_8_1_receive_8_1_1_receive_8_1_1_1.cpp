// Generated from /pastry-2.1/src/rice/p2p/past/testing/RawPastRegrTest.java
#include <rice/p2p/past/testing/RawPastRegrTest_testCaching_8_receive_8_1_receive_8_1_1_receive_8_1_1_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/messaging/LookupMessage.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testCaching_8.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testCaching_8_receive_8_1.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testCaching_8_receive_8_1_receive_8_1_1.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::testing::RawPastRegrTest_testCaching_8_receive_8_1_receive_8_1_1_receive_8_1_1_1::RawPastRegrTest_testCaching_8_receive_8_1_receive_8_1_1_receive_8_1_1_1(RawPastRegrTest_testCaching_8_receive_8_1_receive_8_1_1 *RawPastRegrTest_testCaching_8_receive_8_1_receive_8_1_1_this, ::rice::p2p::commonapi::Id* id2, ::rice::p2p::past::PastImpl* local)
    : super(RawPastRegrTest_testCaching_8_receive_8_1_receive_8_1_1_this->RawPastRegrTest_testCaching_8_receive_8_1_this->RawPastRegrTest_testCaching_8_this->RawPastRegrTest_this, *static_cast< ::default_init_tag* >(0))
    , RawPastRegrTest_testCaching_8_receive_8_1_receive_8_1_1_this(RawPastRegrTest_testCaching_8_receive_8_1_receive_8_1_1_this)
    , id2(id2)
    , local(local)
{
    clinit();
    ctor();
}

void rice::p2p::past::testing::RawPastRegrTest_testCaching_8_receive_8_1_receive_8_1_1_receive_8_1_1_1::receive(::java::lang::Object* result) /* throws(Exception) */
{
    RawPastRegrTest_testCaching_8_receive_8_1_receive_8_1_1_this->RawPastRegrTest_testCaching_8_receive_8_1_this->RawPastRegrTest_testCaching_8_this->RawPastRegrTest_this->stepDone();
    auto lmsg = new ::rice::p2p::past::messaging::LookupMessage(-int32_t(1), id2, npc(local)->getLocalNodeHandle(), id2);
    RawPastRegrTest_testCaching_8_receive_8_1_receive_8_1_1_this->RawPastRegrTest_testCaching_8_receive_8_1_this->RawPastRegrTest_testCaching_8_this->RawPastRegrTest_this->stepStart(u"Lookup Satisfied By Cache"_j);
    RawPastRegrTest_testCaching_8_receive_8_1_receive_8_1_1_this->RawPastRegrTest_testCaching_8_receive_8_1_this->RawPastRegrTest_testCaching_8_this->RawPastRegrTest_this->stepDone();
    RawPastRegrTest_testCaching_8_receive_8_1_receive_8_1_1_this->RawPastRegrTest_testCaching_8_receive_8_1_this->RawPastRegrTest_testCaching_8_this->RawPastRegrTest_this->sectionDone();
    RawPastRegrTest_testCaching_8_receive_8_1_receive_8_1_1_this->RawPastRegrTest_testCaching_8_receive_8_1_this->RawPastRegrTest_testCaching_8_this->RawPastRegrTest_this->cleanUp();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_testCaching_8_receive_8_1_receive_8_1_1_receive_8_1_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_testCaching_8_receive_8_1_receive_8_1_1_receive_8_1_1_1::getClass0()
{
    return class_();
}

