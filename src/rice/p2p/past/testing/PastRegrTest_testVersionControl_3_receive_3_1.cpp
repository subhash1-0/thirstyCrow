// Generated from /pastry-2.1/src/rice/p2p/past/testing/PastRegrTest.java
#include <rice/p2p/past/testing/PastRegrTest_testVersionControl_3_receive_3_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testVersionControl_3.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1.hpp>
#include <rice/p2p/past/testing/PastRegrTest.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::testing::PastRegrTest_testVersionControl_3_receive_3_1::PastRegrTest_testVersionControl_3_receive_3_1(PastRegrTest_testVersionControl_3 *PastRegrTest_testVersionControl_3_this, ::rice::p2p::past::PastContent* oldFile, ::rice::p2p::past::PastImpl* local, ::rice::p2p::past::PastContent* newFile, ::rice::p2p::commonapi::Id* remoteId, ::rice::p2p::past::PastContent* newNewFile)
    : super(PastRegrTest_testVersionControl_3_this->PastRegrTest_this, *static_cast< ::default_init_tag* >(0))
    , PastRegrTest_testVersionControl_3_this(PastRegrTest_testVersionControl_3_this)
    , oldFile(oldFile)
    , local(local)
    , newFile(newFile)
    , remoteId(remoteId)
    , newNewFile(newNewFile)
{
    clinit();
    ctor();
}

void rice::p2p::past::testing::PastRegrTest_testVersionControl_3_receive_3_1::receive(::java::lang::Object* result) /* throws(Exception) */
{
    PastRegrTest_testVersionControl_3_this->PastRegrTest_this->assertTrue(u"File should not be null"_j, result != nullptr);
    PastRegrTest_testVersionControl_3_this->PastRegrTest_this->assertEquals(u"Lookup of file should be correct"_j, oldFile, result);
    PastRegrTest_testVersionControl_3_this->PastRegrTest_this->stepDone();
    PastRegrTest_testVersionControl_3_this->PastRegrTest_this->stepStart(u"Overwriting File Insertion"_j);
    npc(local)->insert(newFile, static_cast< ::rice::Continuation* >(new PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1(this, local, remoteId, newFile, newNewFile)));
    PastRegrTest_testVersionControl_3_this->PastRegrTest_this->simulate();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::PastRegrTest_testVersionControl_3_receive_3_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::PastRegrTest_testVersionControl_3_receive_3_1::getClass0()
{
    return class_();
}

