// Generated from /pastry-2.1/src/rice/p2p/scribe/messaging/SubscribeLostMessage.java
#include <rice/p2p/scribe/messaging/SubscribeLostMessage.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Set.hpp>
#include <rice/p2p/commonapi/CancellableTask.hpp>
#include <rice/p2p/scribe/ScribeMultiClient.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::scribe::messaging::SubscribeLostMessage::SubscribeLostMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::scribe::messaging::SubscribeLostMessage::SubscribeLostMessage(::rice::p2p::commonapi::NodeHandle* source, ::java::util::Collection* topics, int32_t id, ::rice::p2p::scribe::ScribeMultiClient* client) 
    : SubscribeLostMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(source,topics,id,client);
}

void rice::p2p::scribe::messaging::SubscribeLostMessage::ctor(::rice::p2p::commonapi::NodeHandle* source, ::java::util::Collection* topics, int32_t id, ::rice::p2p::scribe::ScribeMultiClient* client)
{
    super::ctor();
    this->topics = new ::java::util::HashSet(static_cast< ::java::util::Collection* >(topics));
    this->id = id;
    this->client = client;
}

rice::p2p::scribe::ScribeMultiClient* rice::p2p::scribe::messaging::SubscribeLostMessage::getClient()
{
    return client;
}

java::util::Collection* rice::p2p::scribe::messaging::SubscribeLostMessage::getTopics()
{
    return topics;
}

int32_t rice::p2p::scribe::messaging::SubscribeLostMessage::getId()
{
    return id;
}

int32_t rice::p2p::scribe::messaging::SubscribeLostMessage::getPriority()
{
    return DEFAULT_PRIORITY;
}

void rice::p2p::scribe::messaging::SubscribeLostMessage::putTask(::rice::p2p::commonapi::CancellableTask* task)
{
    this->task = task;
}

void rice::p2p::scribe::messaging::SubscribeLostMessage::cancel()
{
    npc(task)->cancel();
}

bool rice::p2p::scribe::messaging::SubscribeLostMessage::topicsAcked(::java::util::Collection* topic)
{
    npc(topics)->removeAll(static_cast< ::java::util::Collection* >(topic));
    return npc(topics)->isEmpty();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::messaging::SubscribeLostMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.messaging.SubscribeLostMessage", 46);
    return c;
}

java::lang::Class* rice::p2p::scribe::messaging::SubscribeLostMessage::getClass0()
{
    return class_();
}

