// Generated from /pastry-2.1/src/rice/p2p/scribe/messaging/UnsubscribeMessage.java
#include <rice/p2p/scribe/messaging/UnsubscribeMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Iterator.hpp>
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

rice::p2p::scribe::messaging::UnsubscribeMessage::UnsubscribeMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::scribe::messaging::UnsubscribeMessage::UnsubscribeMessage(::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics) 
    : UnsubscribeMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(source,topics);
}

rice::p2p::scribe::messaging::UnsubscribeMessage::UnsubscribeMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : UnsubscribeMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::scribe::messaging::UnsubscribeMessage::TYPE;

void rice::p2p::scribe::messaging::UnsubscribeMessage::ctor(::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics)
{
    super::ctor();
    this->source = source;
    this->topics = topics;
}

int32_t rice::p2p::scribe::messaging::UnsubscribeMessage::getPriority()
{
    return MEDIUM_HIGH_PRIORITY;
}

rice::p2p::commonapi::NodeHandle* rice::p2p::scribe::messaging::UnsubscribeMessage::getSource()
{
    return source;
}

java::util::List* rice::p2p::scribe::messaging::UnsubscribeMessage::getTopics()
{
    return topics;
}

int16_t rice::p2p::scribe::messaging::UnsubscribeMessage::getType()
{
    return TYPE;
}

void rice::p2p::scribe::messaging::UnsubscribeMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(1)));
    auto hasSource = (source != nullptr);
    npc(buf)->writeBoolean(hasSource);
    if(hasSource)
        npc(source)->serialize(buf);

    npc(buf)->writeInt(npc(topics)->size());
    for (auto _i = npc(topics)->iterator(); _i->hasNext(); ) {
        ::rice::p2p::scribe::Topic* topic = java_cast< ::rice::p2p::scribe::Topic* >(_i->next());
        {
            npc(topic)->serialize(buf);
        }
    }
}

rice::p2p::scribe::messaging::UnsubscribeMessage* rice::p2p::scribe::messaging::UnsubscribeMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return nullptr;
    case int32_t(1):
        return new UnsubscribeMessage(buf, endpoint);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::scribe::messaging::UnsubscribeMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor();
    if(npc(buf)->readBoolean())
        source = npc(endpoint)->readNodeHandle(buf);

    auto numTopics = npc(buf)->readInt();
    topics = new ::java::util::ArrayList(numTopics);
    for (auto i = int32_t(0); i < numTopics; i++) {
        npc(topics)->add(static_cast< ::java::lang::Object* >(new ::rice::p2p::scribe::Topic(buf, endpoint)));
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::messaging::UnsubscribeMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.messaging.UnsubscribeMessage", 44);
    return c;
}

java::lang::Class* rice::p2p::scribe::messaging::UnsubscribeMessage::getClass0()
{
    return class_();
}

