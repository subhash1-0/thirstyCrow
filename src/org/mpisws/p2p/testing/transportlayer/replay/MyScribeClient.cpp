// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/MyScribeClient.java
#include <org/mpisws/p2p/testing/transportlayer/replay/MyScribeClient.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/Observable.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/MyScribeClient_PublishContent.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/MyScribeContent.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
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

org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient::MyScribeClient(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient::MyScribeClient(::rice::p2p::commonapi::Node* node) 
    : MyScribeClient(*static_cast< ::default_init_tag* >(0))
{
    ctor(node);
}

void org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient::init()
{
    seqNum = int32_t(0);
}

void org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient::ctor(::rice::p2p::commonapi::Node* node)
{
    super::ctor();
    init();
    this->node = node;
    logger = npc(npc(npc(node)->getEnvironment())->getLogManager())->getLogger(MyScribeClient::class_(), nullptr);
    this->endpoint = npc(node)->buildEndpoint(this, u"myinstance"_j);
    myScribe = new ::rice::p2p::scribe::ScribeImpl(node, u"myScribeInstance"_j);
    myTopic = new ::rice::p2p::scribe::Topic(static_cast< ::rice::p2p::commonapi::IdFactory* >(new ::rice::pastry::commonapi::PastryIdFactory(npc(node)->getEnvironment())), u"example topic"_j);
    npc(endpoint)->register_();
}

void org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient::subscribe()
{
    npc(myScribe)->subscribe(myTopic, this);
}

void org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient::startPublishTask()
{
    publishTask = npc(endpoint)->scheduleMessage(new MyScribeClient_PublishContent(this), 5000, 5000);
}

void org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient::deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message)
{
    if(dynamic_cast< MyScribeClient_PublishContent* >(message) != nullptr) {
        sendMulticast();
        sendAnycast();
    }
}

void org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient::sendMulticast()
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Node "_j)->append(static_cast< ::java::lang::Object* >(npc(endpoint)->getLocalNodeHandle()))
        ->append(u" broadcasting "_j)
        ->append(seqNum)->toString());
    auto myMessage = new MyScribeContent(npc(endpoint)->getLocalNodeHandle(), seqNum);
    npc(myScribe)->publish(myTopic, myMessage);
    seqNum++;
}

void org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient::deliver(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content)
{
    npc(logger)->log(::java::lang::StringBuilder().append(u"MyScribeClient.deliver("_j)->append(static_cast< ::java::lang::Object* >(topic))
        ->append(u","_j)
        ->append(static_cast< ::java::lang::Object* >(content))
        ->append(u")"_j)->toString());
    if(npc((java_cast< MyScribeContent* >(content)))->from == nullptr) {
        (new ::java::lang::Exception(u"Stack Trace"_j))->printStackTrace();
    }
}

void org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient::sendAnycast()
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Node "_j)->append(static_cast< ::java::lang::Object* >(npc(endpoint)->getLocalNodeHandle()))
        ->append(u" anycasting "_j)
        ->append(seqNum)->toString());
    auto myMessage = new MyScribeContent(npc(endpoint)->getLocalNodeHandle(), seqNum);
    npc(myScribe)->anycast(myTopic, myMessage);
    seqNum++;
}

bool org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient::anycast(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content)
{
    auto returnValue = npc(npc(npc(myScribe)->getEnvironment())->getRandomSource())->nextInt(3) == 0;
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"MyScribeClient.anycast("_j)->append(static_cast< ::java::lang::Object* >(topic))
        ->append(u","_j)
        ->append(static_cast< ::java::lang::Object* >(content))
        ->append(u"):"_j)
        ->append(returnValue)->toString());
    return returnValue;
}

void org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient::childAdded(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child)
{
}

void org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient::childRemoved(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child)
{
}

void org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient::subscribeFailed(::rice::p2p::scribe::Topic* topic)
{
}

bool org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient::forward(::rice::p2p::commonapi::RouteMessage* message)
{
    return true;
}

void org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient::update(::rice::p2p::commonapi::NodeHandle* handle, bool joined)
{
}

bool org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient::isRoot()
{
    return npc(myScribe)->isRoot(myTopic);
}

rice::p2p::commonapi::NodeHandle* org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient::getParent()
{
    return npc((java_cast< ::rice::p2p::scribe::ScribeImpl* >(myScribe)))->getParent(myTopic);
}

rice::p2p::commonapi::NodeHandleArray* org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient::getChildren()
{
    return npc(myScribe)->getChildren(myTopic);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.replay.MyScribeClient", 59);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient::getClass0()
{
    return class_();
}

