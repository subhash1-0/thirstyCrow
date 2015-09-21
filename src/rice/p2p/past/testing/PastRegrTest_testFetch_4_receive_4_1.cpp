// Generated from /pastry-2.1/src/rice/p2p/past/testing/PastRegrTest.java
#include <rice/p2p/past/testing/PastRegrTest_testFetch_4_receive_4_1.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testFetch_4.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testFetch_4_receive_4_1_receive_4_1_1.hpp>
#include <rice/p2p/past/testing/PastRegrTest.hpp>

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

rice::p2p::past::testing::PastRegrTest_testFetch_4_receive_4_1::PastRegrTest_testFetch_4_receive_4_1(PastRegrTest_testFetch_4 *PastRegrTest_testFetch_4_this, ::rice::p2p::past::PastImpl* local, ::rice::p2p::past::PastContentHandle* handle1, ::rice::p2p::past::PastContent* file1, ::rice::p2p::past::PastContent* file2, ::rice::p2p::past::PastContentHandle* handle2, ::rice::p2p::past::PastImpl* remote1, ::rice::p2p::commonapi::Id* id, ::rice::p2p::past::PastImpl* remote2)
    : super(PastRegrTest_testFetch_4_this->PastRegrTest_this, *static_cast< ::default_init_tag* >(0))
    , PastRegrTest_testFetch_4_this(PastRegrTest_testFetch_4_this)
    , local(local)
    , handle1(handle1)
    , file1(file1)
    , file2(file2)
    , handle2(handle2)
    , remote1(remote1)
    , id(id)
    , remote2(remote2)
{
    clinit();
    ctor();
}

void rice::p2p::past::testing::PastRegrTest_testFetch_4_receive_4_1::receive(::java::lang::Object* result) /* throws(Exception) */
{
    PastRegrTest_testFetch_4_this->PastRegrTest_this->assertTrue(u"Storage of file 2 should succeed"_j, npc((java_cast< ::java::lang::Boolean* >(result)))->booleanValue());
    PastRegrTest_testFetch_4_this->PastRegrTest_this->stepDone();
    PastRegrTest_testFetch_4_this->PastRegrTest_this->stepStart(u"File 1 Fetch"_j);
    npc(local)->fetch(handle1, static_cast< ::rice::Continuation* >(new PastRegrTest_testFetch_4_receive_4_1_receive_4_1_1(this, file1, file2, local, handle2, remote1, id, remote2)));
    PastRegrTest_testFetch_4_this->PastRegrTest_this->simulate();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::PastRegrTest_testFetch_4_receive_4_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::PastRegrTest_testFetch_4_receive_4_1::getClass0()
{
    return class_();
}

