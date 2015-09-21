// Generated from /pastry-2.1/src/rice/p2p/past/testing/RawPastRegrTest.java
#include <rice/p2p/past/testing/RawPastRegrTest_testRouteRequest_4.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testRouteRequest_4_receive_4_1.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::testing::RawPastRegrTest_testRouteRequest_4::RawPastRegrTest_testRouteRequest_4(RawPastRegrTest *RawPastRegrTest_this, ::rice::p2p::past::PastImpl* local, ::rice::p2p::past::PastContent* file, ::rice::p2p::commonapi::Id* remoteId, ::rice::p2p::past::PastImpl* remote)
    : super(RawPastRegrTest_this, *static_cast< ::default_init_tag* >(0))
    , local(local)
    , file(file)
    , remoteId(remoteId)
    , remote(remote)
{
    clinit();
    ctor();
}

void rice::p2p::past::testing::RawPastRegrTest_testRouteRequest_4::receive(::java::lang::Object* result) /* throws(Exception) */
{
    RawPastRegrTest_this->assertTrue(u"File returned should be null"_j, result == nullptr);
    RawPastRegrTest_this->stepDone();
    RawPastRegrTest_this->stepStart(u"File Insertion"_j);
    npc(local)->insert(file, static_cast< ::rice::Continuation* >(new RawPastRegrTest_testRouteRequest_4_receive_4_1(this, local, remoteId, file, remote)));
    RawPastRegrTest_this->simulate();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_testRouteRequest_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_testRouteRequest_4::getClass0()
{
    return class_();
}

