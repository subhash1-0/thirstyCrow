// Generated from /pastry-2.1/src/rice/p2p/past/testing/PastRegrTest.java
#include <rice/p2p/past/testing/PastRegrTest_testCaching_6.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testCaching_6_receive_6_1.hpp>
#include <rice/p2p/past/testing/PastRegrTest.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::testing::PastRegrTest_testCaching_6::PastRegrTest_testCaching_6(PastRegrTest *PastRegrTest_this, ::rice::p2p::past::PastImpl* local, ::rice::p2p::commonapi::Id* id1, ::rice::p2p::past::PastContent* file1, ::rice::p2p::commonapi::Id* id2, ::rice::p2p::past::PastContent* file2, ::rice::p2p::past::PastContent* file3)
    : super(PastRegrTest_this, *static_cast< ::default_init_tag* >(0))
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

void rice::p2p::past::testing::PastRegrTest_testCaching_6::receive(::java::lang::Object* result) /* throws(Exception) */
{
    PastRegrTest_this->assertTrue(u"Object should not be null"_j, result != nullptr);
    PastRegrTest_this->assertTrue(u"Object should be True"_j, npc(result)->equals(new ::java::lang::Boolean(true)));
    PastRegrTest_this->stepDone();
    PastRegrTest_this->stepStart(u"Local Lookup Satisfied by Cache"_j);
    npc(local)->lookup(id1, static_cast< ::rice::Continuation* >(new PastRegrTest_testCaching_6_receive_6_1(this, file1, id2, local, file2, file3)));
    PastRegrTest_this->simulate();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::PastRegrTest_testCaching_6::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::PastRegrTest_testCaching_6::getClass0()
{
    return class_();
}

