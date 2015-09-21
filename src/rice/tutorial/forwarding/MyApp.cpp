// Generated from /pastry-2.1/src/rice/tutorial/forwarding/MyApp.java
#include <rice/tutorial/forwarding/MyApp.hpp>

#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/ClassCastException.hpp>
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
#include <rice/tutorial/forwarding/MyMsg.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::forwarding::MyApp::MyApp(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::forwarding::MyApp::MyApp(::rice::p2p::commonapi::Node* node) 
    : MyApp(*static_cast< ::default_init_tag* >(0))
{
    ctor(node);
}

void rice::tutorial::forwarding::MyApp::ctor(::rice::p2p::commonapi::Node* node)
{
    super::ctor();
    this->endpoint = npc(node)->buildEndpoint(this, u"myinstance"_j);
    this->node = node;
    npc(this->endpoint)->register_();
}

rice::p2p::commonapi::Node* rice::tutorial::forwarding::MyApp::getNode()
{
    return node;
}

void rice::tutorial::forwarding::MyApp::routeMyMsg(::rice::p2p::commonapi::Id* id)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" sending to "_j)
        ->append(static_cast< ::java::lang::Object* >(id))->toString());
    ::rice::p2p::commonapi::Message* msg = new MyMsg(npc(endpoint)->getId(), id);
    npc(endpoint)->route(id, msg, static_cast< ::rice::p2p::commonapi::NodeHandle* >(nullptr));
}

void rice::tutorial::forwarding::MyApp::routeMyMsgDirect(::rice::p2p::commonapi::NodeHandle* nh)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" sending direct to "_j)
        ->append(static_cast< ::java::lang::Object* >(nh))->toString());
    ::rice::p2p::commonapi::Message* msg = new MyMsg(npc(endpoint)->getId(), npc(nh)->getId());
    npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), msg, nh);
}

void rice::tutorial::forwarding::MyApp::deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" received "_j)
        ->append(static_cast< ::java::lang::Object* >(message))->toString());
}

void rice::tutorial::forwarding::MyApp::update(::rice::p2p::commonapi::NodeHandle* handle, bool joined)
{
}

bool rice::tutorial::forwarding::MyApp::forward(::rice::p2p::commonapi::RouteMessage* message)
{
    try {
        auto msg = java_cast< MyMsg* >(npc(message)->getMessage(npc(endpoint)->getDeserializer()));
        npc(msg)->addHop(npc(endpoint)->getLocalNodeHandle());
    } catch (::java::io::IOException* ioe) {
        npc(ioe)->printStackTrace();
    }
    return true;
}

java::lang::String* rice::tutorial::forwarding::MyApp::toString()
{
    return ::java::lang::StringBuilder().append(u"MyApp "_j)->append(static_cast< ::java::lang::Object* >(npc(endpoint)->getId()))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::forwarding::MyApp::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.forwarding.MyApp", 30);
    return c;
}

java::lang::Class* rice::tutorial::forwarding::MyApp::getClass0()
{
    return class_();
}

