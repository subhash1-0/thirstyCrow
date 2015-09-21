// Generated from /pastry-2.1/src/rice/p2p/past/testing/RawPastRegrTest.java
#include <rice/p2p/past/testing/RawPastRegrTest_TestPastContentHandle.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/past/Past.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::testing::RawPastRegrTest_TestPastContentHandle::RawPastRegrTest_TestPastContentHandle(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::testing::RawPastRegrTest_TestPastContentHandle::RawPastRegrTest_TestPastContentHandle(::rice::p2p::past::Past* past, ::rice::p2p::commonapi::Id* id) 
    : RawPastRegrTest_TestPastContentHandle(*static_cast< ::default_init_tag* >(0))
{
    ctor(past,id);
}

rice::p2p::past::testing::RawPastRegrTest_TestPastContentHandle::RawPastRegrTest_TestPastContentHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : RawPastRegrTest_TestPastContentHandle(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::past::testing::RawPastRegrTest_TestPastContentHandle::TYPE;

void rice::p2p::past::testing::RawPastRegrTest_TestPastContentHandle::ctor(::rice::p2p::past::Past* past, ::rice::p2p::commonapi::Id* id)
{
    super::ctor();
    this->handle = npc(past)->getLocalNodeHandle();
    this->id = id;
}

rice::p2p::commonapi::Id* rice::p2p::past::testing::RawPastRegrTest_TestPastContentHandle::getId()
{
    return id;
}

rice::p2p::commonapi::NodeHandle* rice::p2p::past::testing::RawPastRegrTest_TestPastContentHandle::getNodeHandle()
{
    return handle;
}

int16_t rice::p2p::past::testing::RawPastRegrTest_TestPastContentHandle::getType()
{
    return TYPE;
}

void rice::p2p::past::testing::RawPastRegrTest_TestPastContentHandle::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor();
    handle = npc(endpoint)->readNodeHandle(buf);
    id = npc(endpoint)->readId(buf, npc(buf)->readShort());
}

void rice::p2p::past::testing::RawPastRegrTest_TestPastContentHandle::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(handle)->serialize(buf);
    npc(buf)->writeShort(npc(id)->getType());
    npc(id)->serialize(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_TestPastContentHandle::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.testing.RawPastRegrTest.TestPastContentHandle", 59);
    return c;
}

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_TestPastContentHandle::getClass0()
{
    return class_();
}

