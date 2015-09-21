// Generated from /pastry-2.1/src/rice/tutorial/timer/MyApp.java
#include <rice/tutorial/timer/MyApp.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/CancellableTask.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/tutorial/lesson3/MyMsg.hpp>
#include <rice/tutorial/timer/MyApp_MessageToSelf.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::timer::MyApp::MyApp(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::timer::MyApp::MyApp(::rice::p2p::commonapi::Node* node) 
    : MyApp(*static_cast< ::default_init_tag* >(0))
{
    ctor(node);
}

void rice::tutorial::timer::MyApp::ctor(::rice::p2p::commonapi::Node* node)
{
    super::ctor();
    this->environment = npc(node)->getEnvironment();
    this->endpoint = npc(node)->buildEndpoint(this, u"myinstance"_j);
    npc(endpoint)->register_();
    messageToSelfTask = npc(endpoint)->scheduleMessage(new MyApp_MessageToSelf(this), 3000, 5000);
}

void rice::tutorial::timer::MyApp::cancelTask()
{
    npc(messageToSelfTask)->cancel();
}

void rice::tutorial::timer::MyApp::routeMyMsg(::rice::p2p::commonapi::Id* id)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" sending to "_j)
        ->append(static_cast< ::java::lang::Object* >(id))->toString());
    ::rice::p2p::commonapi::Message* msg = new ::rice::tutorial::lesson3::MyMsg(npc(endpoint)->getId(), id);
    npc(endpoint)->route(id, msg, static_cast< ::rice::p2p::commonapi::NodeHandle* >(nullptr));
}

void rice::tutorial::timer::MyApp::routeMyMsgDirect(::rice::p2p::commonapi::NodeHandle* nh)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" sending direct to "_j)
        ->append(static_cast< ::java::lang::Object* >(nh))->toString());
    ::rice::p2p::commonapi::Message* msg = new ::rice::tutorial::lesson3::MyMsg(npc(endpoint)->getId(), npc(nh)->getId());
    npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), msg, nh);
}

void rice::tutorial::timer::MyApp::deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" received "_j)
        ->append(static_cast< ::java::lang::Object* >(message))->toString());
    if(dynamic_cast< MyApp_MessageToSelf* >(message) != nullptr) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"I got the MessageToSelf at time:"_j)->append(npc(npc(environment)->getTimeSource())->currentTimeMillis())->toString());
    }
}

void rice::tutorial::timer::MyApp::update(::rice::p2p::commonapi::NodeHandle* handle, bool joined)
{
}

bool rice::tutorial::timer::MyApp::forward(::rice::p2p::commonapi::RouteMessage* message)
{
    return true;
}

java::lang::String* rice::tutorial::timer::MyApp::toString()
{
    return ::java::lang::StringBuilder().append(u"MyApp "_j)->append(static_cast< ::java::lang::Object* >(npc(endpoint)->getId()))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::timer::MyApp::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.timer.MyApp", 25);
    return c;
}

java::lang::Class* rice::tutorial::timer::MyApp::getClass0()
{
    return class_();
}

