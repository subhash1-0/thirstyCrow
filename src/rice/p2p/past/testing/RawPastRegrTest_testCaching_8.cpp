// Generated from /pastry-2.1/src/rice/p2p/past/testing/RawPastRegrTest.java
#include <rice/p2p/past/testing/RawPastRegrTest_testCaching_8.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testCaching_8_receive_8_1.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::testing::RawPastRegrTest_testCaching_8::RawPastRegrTest_testCaching_8(RawPastRegrTest *RawPastRegrTest_this, ::rice::p2p::past::PastImpl* local, ::rice::p2p::commonapi::Id* id1, ::rice::p2p::past::PastContent* file1, ::rice::p2p::commonapi::Id* id2, ::rice::p2p::past::PastContent* file2, ::rice::p2p::past::PastContent* file3)
    : super(RawPastRegrTest_this, *static_cast< ::default_init_tag* >(0))
    , local(local)
    , id1(id1)
    , file1(file1)
    , id2(id2)
    , file2(file2)
    , file3(file3)
{
    clinit();
    ctor();
}

void rice::p2p::past::testing::RawPastRegrTest_testCaching_8::receive(::java::lang::Object* result) /* throws(Exception) */
{
    RawPastRegrTest_this->assertTrue(u"Object should not be null"_j, result != nullptr);
    RawPastRegrTest_this->assertTrue(u"Object should be True"_j, npc(result)->equals(new ::java::lang::Boolean(true)));
    RawPastRegrTest_this->stepDone();
    RawPastRegrTest_this->stepStart(u"Local Lookup Satisfied by Cache"_j);
    npc(local)->lookup(id1, static_cast< ::rice::Continuation* >(new RawPastRegrTest_testCaching_8_receive_8_1(this, file1, id2, local, file2, file3)));
    RawPastRegrTest_this->simulate();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_testCaching_8::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_testCaching_8::getClass0()
{
    return class_();
}

