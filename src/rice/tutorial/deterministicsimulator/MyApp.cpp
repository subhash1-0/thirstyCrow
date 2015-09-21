// Generated from /pastry-2.1/src/rice/tutorial/deterministicsimulator/MyApp.java
#include <rice/tutorial/deterministicsimulator/MyApp.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/tutorial/deterministicsimulator/MyMsg.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::deterministicsimulator::MyApp::MyApp(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::deterministicsimulator::MyApp::MyApp(::rice::p2p::commonapi::Node* node) 
    : MyApp(*static_cast< ::default_init_tag* >(0))
{
    ctor(node);
}

void rice::tutorial::deterministicsimulator::MyApp::ctor(::rice::p2p::commonapi::Node* node)
{
    super::ctor();
    this->endpoint = npc(node)->buildEndpoint(this, u"myinstance"_j);
    this->node = node;
    npc(this->endpoint)->register_();
}

rice::p2p::commonapi::Node* rice::tutorial::deterministicsimulator::MyApp::getNode()
{
    return node;
}

void rice::tutorial::deterministicsimulator::MyApp::routeMyMsg(::rice::p2p::commonapi::Id* id)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" sending to "_j)
        ->append(static_cast< ::java::lang::Object* >(id))
        ->append(u" at "_j)
        ->append(npc(npc(npc(endpoint)->getEnvironment())->getTimeSource())->currentTimeMillis())->toString());
    ::rice::p2p::commonapi::Message* msg = new MyMsg(npc(endpoint)->getId(), id);
    npc(endpoint)->route(id, msg, static_cast< ::rice::p2p::commonapi::NodeHandle* >(nullptr));
}

void rice::tutorial::deterministicsimulator::MyApp::routeMyMsgDirect(::rice::p2p::commonapi::NodeHandle* nh)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" sending direct to "_j)
        ->append(static_cast< ::java::lang::Object* >(nh))
        ->append(u" at "_j)
        ->append(npc(npc(npc(endpoint)->getEnvironment())->getTimeSource())->currentTimeMillis())->toString());
    ::rice::p2p::commonapi::Message* msg = new MyMsg(npc(endpoint)->getId(), npc(nh)->getId());
    npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), msg, nh);
}

void rice::tutorial::deterministicsimulator::MyApp::deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" received "_j)
        ->append(static_cast< ::java::lang::Object* >(message))
        ->append(u" at "_j)
        ->append(npc(npc(npc(endpoint)->getEnvironment())->getTimeSource())->currentTimeMillis())->toString());
}

void rice::tutorial::deterministicsimulator::MyApp::update(::rice::p2p::commonapi::NodeHandle* handle, bool joined)
{
}

bool rice::tutorial::deterministicsimulator::MyApp::forward(::rice::p2p::commonapi::RouteMessage* message)
{
    return true;
}

java::lang::String* rice::tutorial::deterministicsimulator::MyApp::toString()
{
    return ::java::lang::StringBuilder().append(u"MyApp "_j)->append(static_cast< ::java::lang::Object* >(npc(endpoint)->getId()))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::deterministicsimulator::MyApp::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.deterministicsimulator.MyApp", 42);
    return c;
}

java::lang::Class* rice::tutorial::deterministicsimulator::MyApp::getClass0()
{
    return class_();
}

