// Generated from /pastry-2.1/src/rice/p2p/scribe/ScribePolicy.java
#include <rice/p2p/scribe/ScribePolicy_DefaultScribePolicy.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Observable.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/scribe/Scribe.hpp>
#include <rice/p2p/scribe/ScribeClient.hpp>
#include <rice/p2p/scribe/ScribeContent.hpp>
#include <rice/p2p/scribe/ScribePolicy_DefaultScribePolicy_BogusSubscribeMessage.hpp>
#include <rice/p2p/scribe/Topic.hpp>
#include <rice/p2p/scribe/messaging/AnycastMessage.hpp>
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

        namespace scribe
        {
typedef ::SubArray< ::rice::p2p::scribe::ScribeClient, ::java::lang::ObjectArray > ScribeClientArray;
        } // scribe
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

rice::p2p::scribe::ScribePolicy_DefaultScribePolicy::ScribePolicy_DefaultScribePolicy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::scribe::ScribePolicy_DefaultScribePolicy::ScribePolicy_DefaultScribePolicy(::rice::environment::Environment* env) 
    : ScribePolicy_DefaultScribePolicy(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

void rice::p2p::scribe::ScribePolicy_DefaultScribePolicy::ctor(::rice::environment::Environment* env)
{
    super::ctor();
    environment = env;
}

java::util::List* rice::p2p::scribe::ScribePolicy_DefaultScribePolicy::allowSubscribe(Scribe* scribe, ::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics, ScribeContent* content)
{
    auto i = npc(topics)->iterator();
    while (npc(i)->hasNext()) {
        auto topic = java_cast< Topic* >(npc(i)->next());
        if(!allowSubscribe(new ScribePolicy_DefaultScribePolicy_BogusSubscribeMessage(this, source, topic, int32_t(0), content), java_cast< ScribeClientArray* >(npc(npc(scribe)->getClients(topic))->toArray_(new ScribeClientArray(int32_t(0)))), java_cast< ::rice::p2p::commonapi::NodeHandleArray* >(npc(npc(scribe)->getChildrenOfTopic(topic))->toArray_(new ::rice::p2p::commonapi::NodeHandleArray(int32_t(0)))))) {
            npc(i)->remove();
        }
    }
    return topics;
}

bool rice::p2p::scribe::ScribePolicy_DefaultScribePolicy::allowSubscribe(::rice::p2p::scribe::messaging::SubscribeMessage* message, ScribeClientArray* clients, ::rice::p2p::commonapi::NodeHandleArray* children)
{
    return true;
}

void rice::p2p::scribe::ScribePolicy_DefaultScribePolicy::directAnycast(::rice::p2p::scribe::messaging::AnycastMessage* message, ::rice::p2p::commonapi::NodeHandle* parent, ::java::util::Collection* theChildren)
{
    if(parent != nullptr) {
        npc(message)->addLast(parent);
    }
    auto children = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(theChildren));
    while (!npc(children)->isEmpty()) {
        npc(message)->addFirst(java_cast< ::rice::p2p::commonapi::NodeHandle* >(npc(children)->remove(npc(npc(environment)->getRandomSource())->nextInt(npc(children)->size()))));
    }
}

void rice::p2p::scribe::ScribePolicy_DefaultScribePolicy::childAdded(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child)
{
}

void rice::p2p::scribe::ScribePolicy_DefaultScribePolicy::childRemoved(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child)
{
}

void rice::p2p::scribe::ScribePolicy_DefaultScribePolicy::intermediateNode(::rice::p2p::scribe::messaging::ScribeMessage* message)
{
}

void rice::p2p::scribe::ScribePolicy_DefaultScribePolicy::recvAnycastFail(Topic* topic, ::rice::p2p::commonapi::NodeHandle* failedAtNode, ScribeContent* content)
{
}

rice::p2p::scribe::ScribeContent* rice::p2p::scribe::ScribePolicy_DefaultScribePolicy::divideContent(::java::util::List* theTopics, ScribeContent* content)
{
    return content;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::ScribePolicy_DefaultScribePolicy::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.ScribePolicy.DefaultScribePolicy", 48);
    return c;
}

java::lang::Class* rice::p2p::scribe::ScribePolicy_DefaultScribePolicy::getClass0()
{
    return class_();
}

