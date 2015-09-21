// Generated from /pastry-2.1/src/rice/p2p/scribe/messaging/ScribeMessage.java
#include <rice/p2p/scribe/messaging/ScribeMessage.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/scribe/Topic.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::scribe::messaging::ScribeMessage::ScribeMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::scribe::messaging::ScribeMessage::ScribeMessage(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic) 
    : ScribeMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(source,topic);
}

rice::p2p::scribe::messaging::ScribeMessage::ScribeMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : ScribeMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int64_t rice::p2p::scribe::messaging::ScribeMessage::serialVersionUID;

void rice::p2p::scribe::messaging::ScribeMessage::ctor(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic)
{
    super::ctor();
    this->source = source;
    this->topic = topic;
}

int32_t rice::p2p::scribe::messaging::ScribeMessage::getPriority()
{
    return MEDIUM_HIGH_PRIORITY;
}

rice::p2p::commonapi::NodeHandle* rice::p2p::scribe::messaging::ScribeMessage::getSource()
{
    return source;
}

void rice::p2p::scribe::messaging::ScribeMessage::setSource(::rice::p2p::commonapi::NodeHandle* source)
{
    this->source = source;
}

rice::p2p::scribe::Topic* rice::p2p::scribe::messaging::ScribeMessage::getTopic()
{
    return topic;
}

void rice::p2p::scribe::messaging::ScribeMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor();
    if(npc(buf)->readBoolean())
        source = npc(endpoint)->readNodeHandle(buf);

    topic = new ::rice::p2p::scribe::Topic(buf, endpoint);
}

void rice::p2p::scribe::messaging::ScribeMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    auto hasSource = (source != nullptr);
    npc(buf)->writeBoolean(hasSource);
    if(hasSource)
        npc(source)->serialize(buf);

    npc(topic)->serialize(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::messaging::ScribeMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.messaging.ScribeMessage", 39);
    return c;
}

java::lang::Class* rice::p2p::scribe::messaging::ScribeMessage::getClass0()
{
    return class_();
}

