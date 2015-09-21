// Generated from /pastry-2.1/src/rice/tutorial/remotesocket/MyApp.java
#include <rice/tutorial/remotesocket/MyApp.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/tutorial/remotesocket/MyApp_MyApp_1.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::remotesocket::MyApp::MyApp(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::remotesocket::MyApp::MyApp(::rice::p2p::commonapi::Node* node, ::rice::p2p::commonapi::IdFactory* factory) 
    : MyApp(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,factory);
}

void rice::tutorial::remotesocket::MyApp::ctor(::rice::p2p::commonapi::Node* node, ::rice::p2p::commonapi::IdFactory* factory)
{
    super::ctor();
    this->endpoint = npc(node)->buildEndpoint(this, u"myinstance"_j);
    this->node = node;
    MSG_LENGTH = npc(npc(npc(npc(node)->getLocalNodeHandle())->getId())->toByteArray_())->length;
    in = ::java::nio::ByteBuffer::allocate(MSG_LENGTH);
    npc(endpoint)->accept(new MyApp_MyApp_1(this, factory));
    npc(endpoint)->register_();
}

rice::p2p::commonapi::Node* rice::tutorial::remotesocket::MyApp::getNode()
{
    return node;
}

void rice::tutorial::remotesocket::MyApp::deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" received "_j)
        ->append(static_cast< ::java::lang::Object* >(message))->toString());
}

void rice::tutorial::remotesocket::MyApp::update(::rice::p2p::commonapi::NodeHandle* handle, bool joined)
{
}

bool rice::tutorial::remotesocket::MyApp::forward(::rice::p2p::commonapi::RouteMessage* message)
{
    return true;
}

java::lang::String* rice::tutorial::remotesocket::MyApp::toString()
{
    return ::java::lang::StringBuilder().append(u"MyApp "_j)->append(static_cast< ::java::lang::Object* >(npc(endpoint)->getId()))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::remotesocket::MyApp::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.remotesocket.MyApp", 32);
    return c;
}

java::lang::Class* rice::tutorial::remotesocket::MyApp::getClass0()
{
    return class_();
}

