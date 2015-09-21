// Generated from /pastry-2.1/src/rice/p2p/past/messaging/MessageLostMessage.java
#include <rice/p2p/past/messaging/MessageLostMessage.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/past/PastException.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::messaging::MessageLostMessage::MessageLostMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::messaging::MessageLostMessage::MessageLostMessage(int32_t uid, ::rice::p2p::commonapi::NodeHandle* local, ::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message, ::rice::p2p::commonapi::NodeHandle* hint) 
    : MessageLostMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,local,id,message,hint);
}

constexpr int16_t rice::p2p::past::messaging::MessageLostMessage::TYPE;

constexpr int64_t rice::p2p::past::messaging::MessageLostMessage::serialVersionUID;

void rice::p2p::past::messaging::MessageLostMessage::ctor(int32_t uid, ::rice::p2p::commonapi::NodeHandle* local, ::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message, ::rice::p2p::commonapi::NodeHandle* hint)
{
    super::ctor(uid, local, npc(local)->getId());
    setResponse();
    this->hint = hint;
    if(message != nullptr) {
        this->messageString = npc(message)->toString();
    } else {
        this->messageString = u""_j;
    }
    this->id = id;
}

void rice::p2p::past::messaging::MessageLostMessage::returnResponse(::rice::Continuation* c, ::rice::environment::Environment* env, ::java::lang::String* instance)
{
    auto logger = npc(npc(env)->getLogManager())->getLogger(getClass(), instance);
    ::java::lang::Exception* e = new ::rice::p2p::past::PastException(::java::lang::StringBuilder().append(u"Outgoing message '"_j)->append(messageString)
        ->append(u"' to "_j)
        ->append(static_cast< ::java::lang::Object* >(id))
        ->append(u"/"_j)
        ->append(static_cast< ::java::lang::Object* >(hint))
        ->append(u" was lost - please try again."_j)->toString());
    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(logger)->logException(::java::lang::StringBuilder().append(u"ERROR: Outgoing PAST message "_j)->append(messageString)
            ->append(u" with UID "_j)
            ->append(getUID())
            ->append(u" was lost"_j)->toString(), e);

    npc(c)->receiveException(e);
}

java::lang::String* rice::p2p::past::messaging::MessageLostMessage::toString()
{
    return u"[MessageLostMessage]"_j;
}

int16_t rice::p2p::past::messaging::MessageLostMessage::getType()
{
    return TYPE;
}

void rice::p2p::past::messaging::MessageLostMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"serialize() not supported in MessageLostMessage"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::messaging::MessageLostMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.messaging.MessageLostMessage", 42);
    return c;
}

java::lang::Class* rice::p2p::past::messaging::MessageLostMessage::getClass0()
{
    return class_();
}

