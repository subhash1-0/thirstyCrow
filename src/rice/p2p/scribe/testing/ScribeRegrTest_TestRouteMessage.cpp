// Generated from /pastry-2.1/src/rice/p2p/scribe/testing/ScribeRegrTest.java
#include <rice/p2p/scribe/testing/ScribeRegrTest_TestRouteMessage.hpp>

#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>

rice::p2p::scribe::testing::ScribeRegrTest_TestRouteMessage::ScribeRegrTest_TestRouteMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::scribe::testing::ScribeRegrTest_TestRouteMessage::ScribeRegrTest_TestRouteMessage(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* nextHop, ::rice::p2p::commonapi::Message* message) 
    : ScribeRegrTest_TestRouteMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(id,nextHop,message);
}

void rice::p2p::scribe::testing::ScribeRegrTest_TestRouteMessage::ctor(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* nextHop, ::rice::p2p::commonapi::Message* message)
{
    super::ctor();
    this->id = id;
    this->nextHop = nextHop;
    this->message = message;
}

rice::p2p::commonapi::Id* rice::p2p::scribe::testing::ScribeRegrTest_TestRouteMessage::getDestinationId()
{
    return id;
}

rice::p2p::commonapi::NodeHandle* rice::p2p::scribe::testing::ScribeRegrTest_TestRouteMessage::getNextHopHandle()
{
    return nextHop;
}

rice::p2p::commonapi::Message* rice::p2p::scribe::testing::ScribeRegrTest_TestRouteMessage::getMessage()
{
    return message;
}

rice::p2p::commonapi::Message* rice::p2p::scribe::testing::ScribeRegrTest_TestRouteMessage::getMessage(::rice::p2p::commonapi::rawserialization::MessageDeserializer* md)
{
    return message;
}

void rice::p2p::scribe::testing::ScribeRegrTest_TestRouteMessage::setDestinationId(::rice::p2p::commonapi::Id* id)
{
    this->id = id;
}

void rice::p2p::scribe::testing::ScribeRegrTest_TestRouteMessage::setNextHopHandle(::rice::p2p::commonapi::NodeHandle* nextHop)
{
    this->nextHop = nextHop;
}

void rice::p2p::scribe::testing::ScribeRegrTest_TestRouteMessage::setMessage(::rice::p2p::commonapi::Message* message)
{
    this->message = message;
}

void rice::p2p::scribe::testing::ScribeRegrTest_TestRouteMessage::setMessage(::rice::p2p::commonapi::rawserialization::RawMessage* message)
{
    this->message = message;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::testing::ScribeRegrTest_TestRouteMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.testing.ScribeRegrTest.TestRouteMessage", 55);
    return c;
}

java::lang::Class* rice::p2p::scribe::testing::ScribeRegrTest_TestRouteMessage::getClass0()
{
    return class_();
}

