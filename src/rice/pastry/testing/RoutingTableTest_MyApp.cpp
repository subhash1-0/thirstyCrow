// Generated from /pastry-2.1/src/rice/pastry/testing/RoutingTableTest.java
#include <rice/pastry/testing/RoutingTableTest_MyApp.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/RouteMessage.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/testing/RoutingTableTest.hpp>
#include <rice/tutorial/direct/MyMsg.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::testing::RoutingTableTest_MyApp::RoutingTableTest_MyApp(RoutingTableTest *RoutingTableTest_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , RoutingTableTest_this(RoutingTableTest_this)
{
    clinit();
}

rice::pastry::testing::RoutingTableTest_MyApp::RoutingTableTest_MyApp(RoutingTableTest *RoutingTableTest_this, ::rice::p2p::commonapi::Node* node) 
    : RoutingTableTest_MyApp(RoutingTableTest_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(node);
}

void rice::pastry::testing::RoutingTableTest_MyApp::ctor(::rice::p2p::commonapi::Node* node)
{
    super::ctor();
    this->endpoint = npc(node)->buildEndpoint(this, u"myinstance"_j);
    this->node = node;
    npc(this->endpoint)->register_();
}

rice::p2p::commonapi::Node* rice::pastry::testing::RoutingTableTest_MyApp::getNode()
{
    return node;
}

void rice::pastry::testing::RoutingTableTest_MyApp::routeMyMsg(::rice::p2p::commonapi::Id* id)
{
    if(RoutingTableTest::logHeavy)
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" sending to "_j)
            ->append(static_cast< ::java::lang::Object* >(id))->toString());

    ::rice::p2p::commonapi::Message* msg = new ::rice::tutorial::direct::MyMsg(npc(endpoint)->getId(), id);
    npc(endpoint)->route(id, msg, static_cast< ::rice::p2p::commonapi::NodeHandle* >(nullptr));
}

void rice::pastry::testing::RoutingTableTest_MyApp::routeMyMsgDirect(::rice::pastry::NodeHandle* nh)
{
    if(RoutingTableTest::logHeavy)
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" sending direct to "_j)
            ->append(static_cast< ::java::lang::Object* >(nh))->toString());

    ::rice::p2p::commonapi::Message* msg = new ::rice::tutorial::direct::MyMsg(npc(endpoint)->getId(), npc(nh)->getId());
    npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), msg, static_cast< ::rice::p2p::commonapi::NodeHandle* >(nh));
}

void rice::pastry::testing::RoutingTableTest_MyApp::deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message)
{
    if(RoutingTableTest::logHeavy)
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" received "_j)
            ->append(static_cast< ::java::lang::Object* >(message))->toString());

}

void rice::pastry::testing::RoutingTableTest_MyApp::update(::rice::p2p::commonapi::NodeHandle* handle, bool joined)
{
}

bool rice::pastry::testing::RoutingTableTest_MyApp::forward(::rice::p2p::commonapi::RouteMessage* message)
{
    if(RoutingTableTest::logHeavy)
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u"forwarding "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(message)->getMessage()))->toString());

    return true;
}

java::lang::String* rice::pastry::testing::RoutingTableTest_MyApp::toString()
{
    return ::java::lang::StringBuilder().append(u"MyApp "_j)->append(static_cast< ::java::lang::Object* >(npc(endpoint)->getId()))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::RoutingTableTest_MyApp::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.RoutingTableTest.MyApp", 42);
    return c;
}

java::lang::Class* rice::pastry::testing::RoutingTableTest_MyApp::getClass0()
{
    return class_();
}

