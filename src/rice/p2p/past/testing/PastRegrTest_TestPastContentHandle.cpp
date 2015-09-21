// Generated from /pastry-2.1/src/rice/p2p/past/testing/PastRegrTest.java
#include <rice/p2p/past/testing/PastRegrTest_TestPastContentHandle.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/past/Past.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::testing::PastRegrTest_TestPastContentHandle::PastRegrTest_TestPastContentHandle(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::testing::PastRegrTest_TestPastContentHandle::PastRegrTest_TestPastContentHandle(::rice::p2p::past::Past* past, ::rice::p2p::commonapi::Id* id) 
    : PastRegrTest_TestPastContentHandle(*static_cast< ::default_init_tag* >(0))
{
    ctor(past,id);
}

void rice::p2p::past::testing::PastRegrTest_TestPastContentHandle::ctor(::rice::p2p::past::Past* past, ::rice::p2p::commonapi::Id* id)
{
    super::ctor();
    this->handle = npc(past)->getLocalNodeHandle();
    this->id = id;
}

rice::p2p::commonapi::Id* rice::p2p::past::testing::PastRegrTest_TestPastContentHandle::getId()
{
    return id;
}

rice::p2p::commonapi::NodeHandle* rice::p2p::past::testing::PastRegrTest_TestPastContentHandle::getNodeHandle()
{
    return handle;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::PastRegrTest_TestPastContentHandle::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.testing.PastRegrTest.TestPastContentHandle", 56);
    return c;
}

java::lang::Class* rice::p2p::past::testing::PastRegrTest_TestPastContentHandle::getClass0()
{
    return class_();
}

