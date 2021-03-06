// Generated from /pastry-2.1/src/rice/p2p/past/testing/RawPastRegrTest.java
#include <rice/p2p/past/testing/RawPastRegrTest_testFetch_6.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testFetch_6_receive_6_1.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest.hpp>
#include <rice/persistence/StorageManager.hpp>

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

rice::p2p::past::testing::RawPastRegrTest_testFetch_6::RawPastRegrTest_testFetch_6(RawPastRegrTest *RawPastRegrTest_this, ::rice::p2p::past::PastImpl* remote2, ::rice::p2p::commonapi::Id* id, ::rice::p2p::past::PastContent* file2, ::rice::p2p::past::PastImpl* local, ::rice::p2p::past::PastContentHandle* handle1, ::rice::p2p::past::PastContent* file1, ::rice::p2p::past::PastContentHandle* handle2, ::rice::p2p::past::PastImpl* remote1)
    : super(RawPastRegrTest_this, *static_cast< ::default_init_tag* >(0))
    , remote2(remote2)
    , id(id)
    , file2(file2)
    , local(local)
    , handle1(handle1)
    , file1(file1)
    , handle2(handle2)
    , remote1(remote1)
{
    clinit();
    ctor();
}

void rice::p2p::past::testing::RawPastRegrTest_testFetch_6::receive(::java::lang::Object* result) /* throws(Exception) */
{
    RawPastRegrTest_this->assertTrue(u"Storage of file 1 should succeed"_j, npc((java_cast< ::java::lang::Boolean* >(result)))->booleanValue());
    RawPastRegrTest_this->stepDone();
    RawPastRegrTest_this->stepStart(u"File 2 Insertion"_j);
    npc(npc(remote2)->getStorageManager())->store(id, nullptr, file2, new RawPastRegrTest_testFetch_6_receive_6_1(this, local, handle1, file1, file2, handle2, remote1, id, remote2));
    RawPastRegrTest_this->simulate();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_testFetch_6::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_testFetch_6::getClass0()
{
    return class_();
}

