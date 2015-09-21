// Generated from /pastry-2.1/src/rice/p2p/scribe/messaging/PublishRequestMessage.java
#include <rice/p2p/scribe/messaging/PublishRequestMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/scribe/ScribeContent.hpp>
#include <rice/p2p/scribe/Topic.hpp>
#include <rice/p2p/scribe/rawserialization/JavaSerializedScribeContent.hpp>
#include <rice/p2p/scribe/rawserialization/RawScribeContent.hpp>
#include <rice/p2p/scribe/rawserialization/ScribeContentDeserializer.hpp>

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

rice::p2p::scribe::messaging::PublishRequestMessage::PublishRequestMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::scribe::messaging::PublishRequestMessage::PublishRequestMessage(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content) 
    : PublishRequestMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(source,topic,content);
}

rice::p2p::scribe::messaging::PublishRequestMessage::PublishRequestMessage(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::rawserialization::RawScribeContent* content) 
    : PublishRequestMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(source,topic,content);
}

rice::p2p::scribe::messaging::PublishRequestMessage::PublishRequestMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::scribe::rawserialization::ScribeContentDeserializer* cd)  /* throws(IOException) */
    : PublishRequestMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint,cd);
}

constexpr int16_t rice::p2p::scribe::messaging::PublishRequestMessage::TYPE;

void rice::p2p::scribe::messaging::PublishRequestMessage::ctor(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content)
{
    ctor(source, topic, dynamic_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(content) != nullptr ? java_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(content) : static_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(new ::rice::p2p::scribe::rawserialization::JavaSerializedScribeContent(content)));
}

void rice::p2p::scribe::messaging::PublishRequestMessage::ctor(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::rawserialization::RawScribeContent* content)
{
    super::ctor(source, topic);
    this->content = content;
}

rice::p2p::scribe::ScribeContent* rice::p2p::scribe::messaging::PublishRequestMessage::getContent()
{
    if(npc(content)->getType() == 0)
        return npc((java_cast< ::rice::p2p::scribe::rawserialization::JavaSerializedScribeContent* >(content)))->getContent();

    return content;
}

java::lang::String* rice::p2p::scribe::messaging::PublishRequestMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"PRM{"_j)->append(static_cast< ::java::lang::Object* >(topic))
        ->append(u"}:["_j)
        ->append(static_cast< ::java::lang::Object* >(content))
        ->append(u"]"_j)->toString();
}

int32_t rice::p2p::scribe::messaging::PublishRequestMessage::getPriority()
{
    return super::getPriority() - int32_t(5);
}

int16_t rice::p2p::scribe::messaging::PublishRequestMessage::getType()
{
    return TYPE;
}

void rice::p2p::scribe::messaging::PublishRequestMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    super::serialize(buf);
    npc(buf)->writeShort(npc(content)->getType());
    npc(content)->serialize(buf);
}

rice::p2p::scribe::messaging::PublishRequestMessage* rice::p2p::scribe::messaging::PublishRequestMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::scribe::rawserialization::ScribeContentDeserializer* scd) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new PublishRequestMessage(buf, endpoint, scd);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::scribe::messaging::PublishRequestMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::scribe::rawserialization::ScribeContentDeserializer* cd) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    auto contentType = npc(buf)->readShort();
    if(contentType == 0) {
        content = new ::rice::p2p::scribe::rawserialization::JavaSerializedScribeContent(npc(cd)->deserializeScribeContent(buf, endpoint, contentType));
    } else {
        content = java_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(npc(cd)->deserializeScribeContent(buf, endpoint, contentType));
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::messaging::PublishRequestMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.messaging.PublishRequestMessage", 47);
    return c;
}

java::lang::Class* rice::p2p::scribe::messaging::PublishRequestMessage::getClass0()
{
    return class_();
}

