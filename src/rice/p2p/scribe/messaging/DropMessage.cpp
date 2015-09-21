// Generated from /pastry-2.1/src/rice/p2p/scribe/messaging/DropMessage.java
#include <rice/p2p/scribe/messaging/DropMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::scribe::messaging::DropMessage::DropMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::scribe::messaging::DropMessage::DropMessage(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic) 
    : DropMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(source,topic);
}

rice::p2p::scribe::messaging::DropMessage::DropMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : DropMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::scribe::messaging::DropMessage::TYPE;

void rice::p2p::scribe::messaging::DropMessage::ctor(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic)
{
    super::ctor(source, topic);
}

int16_t rice::p2p::scribe::messaging::DropMessage::getType()
{
    return TYPE;
}

void rice::p2p::scribe::messaging::DropMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    super::serialize(buf);
}

rice::p2p::scribe::messaging::DropMessage* rice::p2p::scribe::messaging::DropMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new DropMessage(buf, endpoint);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::scribe::messaging::DropMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::messaging::DropMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.messaging.DropMessage", 37);
    return c;
}

java::lang::Class* rice::p2p::scribe::messaging::DropMessage::getClass0()
{
    return class_();
}

