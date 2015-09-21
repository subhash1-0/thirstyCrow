// Generated from /pastry-2.1/src/rice/tutorial/scribe/MyScribeClient.java
#include <rice/tutorial/scribe/MyScribeClient.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/Observable.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/CancellableTask.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/scribe/Scribe.hpp>
#include <rice/p2p/scribe/ScribeContent.hpp>
#include <rice/p2p/scribe/ScribeImpl.hpp>
#include <rice/p2p/scribe/Topic.hpp>
#include <rice/pastry/commonapi/PastryIdFactory.hpp>
#include <rice/tutorial/scribe/MyScribeClient_PublishContent.hpp>
#include <rice/tutorial/scribe/MyScribeContent.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace util
    {
typedef ::SubArray< ::java::util::Observable, ::java::lang::ObjectArray > ObservableArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandle, ::java::util::ObservableArray, ::java::io::SerializableArray > NodeHandleArray;
        } // commonapi
    } // p2p
} // rice

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

rice::tutorial::scribe::MyScribeClient::MyScribeClient(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::scribe::MyScribeClient::MyScribeClient(::rice::p2p::commonapi::Node* node) 
    : MyScribeClient(*static_cast< ::default_init_tag* >(0))
{
    ctor(node);
}

void rice::tutorial::scribe::MyScribeClient::init()
{
    seqNum = int32_t(0);
}

void rice::tutorial::scribe::MyScribeClient::ctor(::rice::p2p::commonapi::Node* node)
{
    super::ctor();
    init();
    this->endpoint = npc(node)->buildEndpoint(this, u"myinstance"_j);
    myScribe = new ::rice::p2p::scribe::ScribeImpl(node, u"myScribeInstance"_j);
    myTopic = new ::rice::p2p::scribe::Topic(static_cast< ::rice::p2p::commonapi::IdFactory* >(new ::rice::pastry::commonapi::PastryIdFactory(npc(node)->getEnvironment())), u"example topic"_j);
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"myTopic = "_j)->append(static_cast< ::java::lang::Object* >(myTopic))->toString());
    npc(endpoint)->register_();
}

void rice::tutorial::scribe::MyScribeClient::subscribe()
{
    npc(myScribe)->subscribe(myTopic, this);
}

void rice::tutorial::scribe::MyScribeClient::startPublishTask()
{
    publishTask = npc(endpoint)->scheduleMessage(new MyScribeClient_PublishContent(this), 5000, 5000);
}

void rice::tutorial::scribe::MyScribeClient::deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message)
{
    if(dynamic_cast< MyScribeClient_PublishContent* >(message) != nullptr) {
        sendMulticast();
        sendAnycast();
    }
}

void rice::tutorial::scribe::MyScribeClient::sendMulticast()
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Node "_j)->append(static_cast< ::java::lang::Object* >(npc(endpoint)->getLocalNodeHandle()))
        ->append(u" broadcasting "_j)
        ->append(seqNum)->toString());
    auto myMessage = new MyScribeContent(npc(endpoint)->getLocalNodeHandle(), seqNum);
    npc(myScribe)->publish(myTopic, myMessage);
    seqNum++;
}

void rice::tutorial::scribe::MyScribeClient::deliver(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"MyScribeClient.deliver("_j)->append(static_cast< ::java::lang::Object* >(topic))
        ->append(u","_j)
        ->append(static_cast< ::java::lang::Object* >(content))
        ->append(u")"_j)->toString());
    if(npc((java_cast< MyScribeContent* >(content)))->from == nullptr) {
        (new ::java::lang::Exception(u"Stack Trace"_j))->printStackTrace();
    }
}

void rice::tutorial::scribe::MyScribeClient::sendAnycast()
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Node "_j)->append(static_cast< ::java::lang::Object* >(npc(endpoint)->getLocalNodeHandle()))
        ->append(u" anycasting "_j)
        ->append(seqNum)->toString());
    auto myMessage = new MyScribeContent(npc(endpoint)->getLocalNodeHandle(), seqNum);
    npc(myScribe)->anycast(myTopic, myMessage);
    seqNum++;
}

bool rice::tutorial::scribe::MyScribeClient::anycast(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content)
{
    auto returnValue = npc(npc(npc(myScribe)->getEnvironment())->getRandomSource())->nextInt(3) == 0;
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"MyScribeClient.anycast("_j)->append(static_cast< ::java::lang::Object* >(topic))
        ->append(u","_j)
        ->append(static_cast< ::java::lang::Object* >(content))
        ->append(u"):"_j)
        ->append(returnValue)->toString());
    return returnValue;
}

void rice::tutorial::scribe::MyScribeClient::childAdded(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child)
{
}

void rice::tutorial::scribe::MyScribeClient::childRemoved(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child)
{
}

void rice::tutorial::scribe::MyScribeClient::subscribeFailed(::rice::p2p::scribe::Topic* topic)
{
}

bool rice::tutorial::scribe::MyScribeClient::forward(::rice::p2p::commonapi::RouteMessage* message)
{
    return true;
}

void rice::tutorial::scribe::MyScribeClient::update(::rice::p2p::commonapi::NodeHandle* handle, bool joined)
{
}

bool rice::tutorial::scribe::MyScribeClient::isRoot()
{
    return npc(myScribe)->isRoot(myTopic);
}

rice::p2p::commonapi::NodeHandle* rice::tutorial::scribe::MyScribeClient::getParent()
{
    return npc((java_cast< ::rice::p2p::scribe::ScribeImpl* >(myScribe)))->getParent(myTopic);
}

rice::p2p::commonapi::NodeHandleArray* rice::tutorial::scribe::MyScribeClient::getChildren()
{
    return npc(myScribe)->getChildren(myTopic);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::scribe::MyScribeClient::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.scribe.MyScribeClient", 35);
    return c;
}

java::lang::Class* rice::tutorial::scribe::MyScribeClient::getClass0()
{
    return class_();
}

