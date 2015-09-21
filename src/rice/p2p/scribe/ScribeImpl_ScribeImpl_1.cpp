// Generated from /pastry-2.1/src/rice/p2p/scribe/ScribeImpl.java
#include <rice/p2p/scribe/ScribeImpl_ScribeImpl_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/scribe/ScribeImpl.hpp>
#include <rice/p2p/scribe/messaging/AnycastFailureMessage.hpp>
#include <rice/p2p/scribe/messaging/AnycastMessage.hpp>
#include <rice/p2p/scribe/messaging/DropMessage.hpp>
#include <rice/p2p/scribe/messaging/PublishMessage.hpp>
#include <rice/p2p/scribe/messaging/PublishRequestMessage.hpp>
#include <rice/p2p/scribe/messaging/SubscribeAckMessage.hpp>
#include <rice/p2p/scribe/messaging/SubscribeFailedMessage.hpp>
#include <rice/p2p/scribe/messaging/SubscribeMessage.hpp>
#include <rice/p2p/scribe/messaging/UnsubscribeMessage.hpp>
#include <rice/p2p/scribe/rawserialization/ScribeContentDeserializer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::scribe::ScribeImpl_ScribeImpl_1::ScribeImpl_ScribeImpl_1(ScribeImpl *ScribeImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , ScribeImpl_this(ScribeImpl_this)
{
    clinit();
    ctor();
}

rice::p2p::commonapi::Message* rice::p2p::scribe::ScribeImpl_ScribeImpl_1::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */
{
    try {
        switch (type) {
        case ::rice::p2p::scribe::messaging::AnycastMessage::TYPE:
            return ::rice::p2p::scribe::messaging::AnycastMessage::build(buf, ScribeImpl_this->endpoint, ScribeImpl_this->contentDeserializer);
        case ::rice::p2p::scribe::messaging::SubscribeMessage::TYPE:
            return ::rice::p2p::scribe::messaging::SubscribeMessage::buildSM(buf, ScribeImpl_this->endpoint, ScribeImpl_this->contentDeserializer);
        case ::rice::p2p::scribe::messaging::SubscribeAckMessage::TYPE:
            return ::rice::p2p::scribe::messaging::SubscribeAckMessage::build(buf, ScribeImpl_this->endpoint);
        case ::rice::p2p::scribe::messaging::SubscribeFailedMessage::TYPE:
            return ::rice::p2p::scribe::messaging::SubscribeFailedMessage::build(buf, ScribeImpl_this->endpoint);
        case ::rice::p2p::scribe::messaging::DropMessage::TYPE:
            return ::rice::p2p::scribe::messaging::DropMessage::build(buf, ScribeImpl_this->endpoint);
        case ::rice::p2p::scribe::messaging::PublishMessage::TYPE:
            return ::rice::p2p::scribe::messaging::PublishMessage::build(buf, ScribeImpl_this->endpoint, ScribeImpl_this->contentDeserializer);
        case ::rice::p2p::scribe::messaging::PublishRequestMessage::TYPE:
            return ::rice::p2p::scribe::messaging::PublishRequestMessage::build(buf, ScribeImpl_this->endpoint, ScribeImpl_this->contentDeserializer);
        case ::rice::p2p::scribe::messaging::UnsubscribeMessage::TYPE:
            return ::rice::p2p::scribe::messaging::UnsubscribeMessage::build(buf, ScribeImpl_this->endpoint);
        case ::rice::p2p::scribe::messaging::AnycastFailureMessage::TYPE:
            return ::rice::p2p::scribe::messaging::AnycastFailureMessage::build(buf, ScribeImpl_this->endpoint, ScribeImpl_this->contentDeserializer);
        }

    } catch (::java::io::IOException* e) {
        if(npc(ScribeImpl_this->logger)->level <= ::rice::environment::logging::Logger::SEVERE)
            npc(ScribeImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Exception in deserializer in "_j)->append(npc(ScribeImpl_this->endpoint)->toString())
                ->append(u":"_j)
                ->append(ScribeImpl_this->instance)
                ->append(u" "_j)
                ->append(static_cast< ::java::lang::Object* >(ScribeImpl_this->contentDeserializer))
                ->append(u" "_j)
                ->append(static_cast< ::java::lang::Object* >(e))->toString());

        throw e;
    }
    throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Unknown type:"_j)->append(type)->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::ScribeImpl_ScribeImpl_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::scribe::ScribeImpl_ScribeImpl_1::getClass0()
{
    return class_();
}

