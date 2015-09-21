// Generated from /pastry-2.1/src/rice/p2p/scribe/messaging/SubscribeMessage.java
#include <rice/p2p/scribe/messaging/SubscribeMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Collections.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/LinkedList.hpp>
#include <java/util/List.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/scribe/Topic.hpp>

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

rice::p2p::scribe::messaging::SubscribeMessage::SubscribeMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::scribe::messaging::SubscribeMessage::SubscribeMessage(::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics, int32_t id, ::rice::p2p::scribe::rawserialization::RawScribeContent* content) 
    : SubscribeMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(source,topics,id,content);
}

rice::p2p::scribe::messaging::SubscribeMessage::SubscribeMessage(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic, int32_t id, ::rice::p2p::scribe::rawserialization::RawScribeContent* content) 
    : SubscribeMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(source,topic,id,content);
}

rice::p2p::scribe::messaging::SubscribeMessage::SubscribeMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::scribe::rawserialization::ScribeContentDeserializer* contentDeserializer)  /* throws(IOException) */
    : SubscribeMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint,contentDeserializer);
}

constexpr int16_t rice::p2p::scribe::messaging::SubscribeMessage::TYPE;

void rice::p2p::scribe::messaging::SubscribeMessage::ctor(::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics, int32_t id, ::rice::p2p::scribe::rawserialization::RawScribeContent* content)
{
    super::ctor(source, java_cast< ::rice::p2p::scribe::Topic* >(npc(npc(topics)->iterator())->next()), content);
    this->id = id;
    this->subscriber = source;
    this->topics = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(topics));
}

void rice::p2p::scribe::messaging::SubscribeMessage::ctor(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic, int32_t id, ::rice::p2p::scribe::rawserialization::RawScribeContent* content)
{
    ctor(source, ::java::util::Collections::singletonList(topic), id, content);
}

rice::p2p::commonapi::NodeHandle* rice::p2p::scribe::messaging::SubscribeMessage::getSubscriber()
{
    return subscriber;
}

int32_t rice::p2p::scribe::messaging::SubscribeMessage::getId()
{
    return id;
}

java::lang::String* rice::p2p::scribe::messaging::SubscribeMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"[SubscribeMessage{"_j)->append(::java::lang::System::identityHashCode(this))
        ->append(u"} "_j)
        ->append(static_cast< ::java::lang::Object* >(topic))
        ->append(u" subscriber "_j)
        ->append(static_cast< ::java::lang::Object* >(subscriber))
        ->append(u" ID "_j)
        ->append(id)
        ->append(u"]"_j)->toString();
}

int16_t rice::p2p::scribe::messaging::SubscribeMessage::getType()
{
    return TYPE;
}

void rice::p2p::scribe::messaging::SubscribeMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(1)));
    super::serializeHelper(buf);
    npc(buf)->writeInt(id);
    npc(subscriber)->serialize(buf);
    auto numTopics = npc(topics)->size();
    npc(buf)->writeInt(numTopics);
    if(numTopics > 1) {
        auto i = npc(topics)->iterator();
        npc(i)->next();
        while (npc(i)->hasNext()) {
            npc(java_cast< ::rice::p2p::scribe::Topic* >(npc(i)->next()))->serialize(buf);
        }
    }
}

rice::p2p::scribe::messaging::SubscribeMessage* rice::p2p::scribe::messaging::SubscribeMessage::buildSM(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::scribe::rawserialization::ScribeContentDeserializer* scd) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return nullptr;
    case int32_t(1):
        return new SubscribeMessage(buf, endpoint, scd);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::scribe::messaging::SubscribeMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::scribe::rawserialization::ScribeContentDeserializer* contentDeserializer) /* throws(IOException) */
{
    super::ctor(buf, endpoint, contentDeserializer);
    id = npc(buf)->readInt();
    subscriber = npc(endpoint)->readNodeHandle(buf);
    auto numTopics = npc(buf)->readInt();
    topics = new ::java::util::ArrayList(numTopics);
    npc(topics)->add(static_cast< ::java::lang::Object* >(getTopic()));
    for (auto i = int32_t(1); i < numTopics; i++) {
        npc(topics)->add(static_cast< ::java::lang::Object* >(new ::rice::p2p::scribe::Topic(buf, endpoint)));
    }
}

void rice::p2p::scribe::messaging::SubscribeMessage::removeTopics(::java::util::Collection* accepted)
{
    npc(topics)->removeAll(static_cast< ::java::util::Collection* >(accepted));
    if(npc(topics)->isEmpty()) {
        topic = nullptr;
    } else {
        topic = java_cast< ::rice::p2p::scribe::Topic* >(npc(topics)->get(0));
    }
}

java::util::List* rice::p2p::scribe::messaging::SubscribeMessage::getTopics()
{
    return topics;
}

bool rice::p2p::scribe::messaging::SubscribeMessage::isEmpty()
{
    return npc(topics)->isEmpty();
}

rice::p2p::scribe::messaging::SubscribeMessage* rice::p2p::scribe::messaging::SubscribeMessage::copy(::java::util::List* newTopics, ::rice::p2p::scribe::rawserialization::RawScribeContent* content)
{
    auto ret = new SubscribeMessage(getSource(), newTopics, getId(), content);
    npc(ret)->visited = visited;
    npc(ret)->toVisit = toVisit;
    npc(ret)->subscriber = subscriber;
    return ret;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::messaging::SubscribeMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.messaging.SubscribeMessage", 42);
    return c;
}

java::lang::Class* rice::p2p::scribe::messaging::SubscribeMessage::getClass0()
{
    return class_();
}

