// Generated from /pastry-2.1/src/rice/tutorial/sendfile/MyApp.java
#include <rice/tutorial/sendfile/MyApp.hpp>

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
#include <rice/tutorial/sendfile/MyApp_MyApp_1.hpp>
#include <rice/tutorial/sendfile/MyApp_sendMyMsgDirect_2.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::sendfile::MyApp::MyApp(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::sendfile::MyApp::MyApp(::rice::p2p::commonapi::Node* node, ::rice::p2p::commonapi::IdFactory* factory) 
    : MyApp(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,factory);
}

void rice::tutorial::sendfile::MyApp::ctor(::rice::p2p::commonapi::Node* node, ::rice::p2p::commonapi::IdFactory* factory)
{
    super::ctor();
    this->endpoint = npc(node)->buildEndpoint(this, u"myinstance"_j);
    this->node = node;
    npc(endpoint)->accept(new MyApp_MyApp_1(this));
    npc(endpoint)->register_();
}

rice::p2p::commonapi::Node* rice::tutorial::sendfile::MyApp::getNode()
{
    return node;
}

void rice::tutorial::sendfile::MyApp::sendMyMsgDirect(::rice::p2p::commonapi::NodeHandle* nh)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" opening to "_j)
        ->append(static_cast< ::java::lang::Object* >(nh))->toString());
    npc(endpoint)->connect(nh, new MyApp_sendMyMsgDirect_2(this), 30000);
}

void rice::tutorial::sendfile::MyApp::deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" received "_j)
        ->append(static_cast< ::java::lang::Object* >(message))->toString());
}

void rice::tutorial::sendfile::MyApp::update(::rice::p2p::commonapi::NodeHandle* handle, bool joined)
{
}

bool rice::tutorial::sendfile::MyApp::forward(::rice::p2p::commonapi::RouteMessage* message)
{
    return true;
}

java::lang::String* rice::tutorial::sendfile::MyApp::toString()
{
    return ::java::lang::StringBuilder().append(u"MyApp "_j)->append(static_cast< ::java::lang::Object* >(npc(endpoint)->getId()))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::sendfile::MyApp::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.sendfile.MyApp", 28);
    return c;
}

java::lang::Class* rice::tutorial::sendfile::MyApp::getClass0()
{
    return class_();
}

