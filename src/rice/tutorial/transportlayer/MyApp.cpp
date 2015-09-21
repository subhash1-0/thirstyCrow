// Generated from /pastry-2.1/src/rice/tutorial/transportlayer/MyApp.java
#include <rice/tutorial/transportlayer/MyApp.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/Collections.hpp>
#include <org/mpisws/p2p/transport/wire/WireTransportLayer.hpp>
#include <rice/p2p/commonapi/DeliveryNotification.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/tutorial/transportlayer/MyMsg.hpp>

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

rice::tutorial::transportlayer::MyApp::MyApp(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::transportlayer::MyApp::MyApp(::rice::p2p::commonapi::Node* node) 
    : MyApp(*static_cast< ::default_init_tag* >(0))
{
    ctor(node);
}

void rice::tutorial::transportlayer::MyApp::ctor(::rice::p2p::commonapi::Node* node)
{
    super::ctor();
    this->endpoint = npc(node)->buildEndpoint(this, u"myinstance"_j);
    this->node = node;
    npc(this->endpoint)->register_();
}

rice::p2p::commonapi::Node* rice::tutorial::transportlayer::MyApp::getNode()
{
    return node;
}

void rice::tutorial::transportlayer::MyApp::routeMyMsg(::rice::p2p::commonapi::Id* id)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" sending to "_j)
        ->append(static_cast< ::java::lang::Object* >(id))->toString());
    ::rice::p2p::commonapi::Message* msg = new MyMsg(npc(endpoint)->getId(), id);
    npc(endpoint)->route(id, msg, static_cast< ::rice::p2p::commonapi::NodeHandle* >(nullptr), static_cast< ::rice::p2p::commonapi::DeliveryNotification* >(nullptr), ::java::util::Collections::singletonMap(::org::mpisws::p2p::transport::wire::WireTransportLayer::OPTION_TRANSPORT_TYPE(), java_cast< ::java::lang::Object* >(::java::lang::Integer::valueOf(::org::mpisws::p2p::transport::wire::WireTransportLayer::TRANSPORT_TYPE_DATAGRAM))));
}

void rice::tutorial::transportlayer::MyApp::routeMyMsgDirect(::rice::p2p::commonapi::NodeHandle* nh)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" sending direct to "_j)
        ->append(static_cast< ::java::lang::Object* >(nh))->toString());
    ::rice::p2p::commonapi::Message* msg = new MyMsg(npc(endpoint)->getId(), npc(nh)->getId());
    npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), msg, nh);
}

void rice::tutorial::transportlayer::MyApp::deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" received "_j)
        ->append(static_cast< ::java::lang::Object* >(message))->toString());
}

void rice::tutorial::transportlayer::MyApp::update(::rice::p2p::commonapi::NodeHandle* handle, bool joined)
{
}

bool rice::tutorial::transportlayer::MyApp::forward(::rice::p2p::commonapi::RouteMessage* message)
{
    return true;
}

java::lang::String* rice::tutorial::transportlayer::MyApp::toString()
{
    return ::java::lang::StringBuilder().append(u"MyApp "_j)->append(static_cast< ::java::lang::Object* >(npc(endpoint)->getId()))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::transportlayer::MyApp::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.transportlayer.MyApp", 34);
    return c;
}

java::lang::Class* rice::tutorial::transportlayer::MyApp::getClass0()
{
    return class_();
}

