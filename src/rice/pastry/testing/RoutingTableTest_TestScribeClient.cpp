// Generated from /pastry-2.1/src/rice/pastry/testing/RoutingTableTest.java
#include <rice/pastry/testing/RoutingTableTest_TestScribeClient.hpp>

#include <rice/p2p/scribe/Scribe.hpp>
#include <rice/p2p/scribe/Topic.hpp>
#include <rice/pastry/testing/RoutingTableTest.hpp>

rice::pastry::testing::RoutingTableTest_TestScribeClient::RoutingTableTest_TestScribeClient(RoutingTableTest *RoutingTableTest_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , RoutingTableTest_this(RoutingTableTest_this)
{
    clinit();
}

rice::pastry::testing::RoutingTableTest_TestScribeClient::RoutingTableTest_TestScribeClient(RoutingTableTest *RoutingTableTest_this, ::rice::p2p::scribe::Scribe* scribe, ::rice::p2p::scribe::Topic* topic) 
    : RoutingTableTest_TestScribeClient(RoutingTableTest_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(scribe,topic);
}

void rice::pastry::testing::RoutingTableTest_TestScribeClient::ctor(::rice::p2p::scribe::Scribe* scribe, ::rice::p2p::scribe::Topic* topic)
{
    super::ctor();
    this->scribe = scribe;
    this->topic = topic;
    this->acceptAnycast_ = false;
    this->subscribeFailed_ = false;
}

void rice::pastry::testing::RoutingTableTest_TestScribeClient::acceptAnycast(bool value)
{
    this->acceptAnycast_ = value;
}

bool rice::pastry::testing::RoutingTableTest_TestScribeClient::anycast(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content)
{
    return acceptAnycast_;
}

void rice::pastry::testing::RoutingTableTest_TestScribeClient::deliver(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content)
{
}

void rice::pastry::testing::RoutingTableTest_TestScribeClient::childAdded(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child)
{
}

void rice::pastry::testing::RoutingTableTest_TestScribeClient::childRemoved(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child)
{
}

void rice::pastry::testing::RoutingTableTest_TestScribeClient::subscribeFailed(::rice::p2p::scribe::Topic* topic)
{
    subscribeFailed_ = true;
}

bool rice::pastry::testing::RoutingTableTest_TestScribeClient::getSubscribeFailed()
{
    return subscribeFailed_;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::RoutingTableTest_TestScribeClient::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.RoutingTableTest.TestScribeClient", 53);
    return c;
}

java::lang::Class* rice::pastry::testing::RoutingTableTest_TestScribeClient::getClass0()
{
    return class_();
}

