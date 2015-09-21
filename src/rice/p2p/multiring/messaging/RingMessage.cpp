// Generated from /pastry-2.1/src/rice/p2p/multiring/messaging/RingMessage.java
#include <rice/p2p/multiring/messaging/RingMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Byte.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Hashtable.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/MessageDeserializer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>
#include <rice/p2p/multiring/RingId.hpp>
#include <rice/p2p/util/rawserialization/JavaSerializedMessage.hpp>

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

rice::p2p::multiring::messaging::RingMessage::RingMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::multiring::messaging::RingMessage::RingMessage(::rice::p2p::multiring::RingId* id, ::rice::p2p::commonapi::rawserialization::RawMessage* message, ::java::lang::String* application) 
    : RingMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(id,message,application);
}

rice::p2p::multiring::messaging::RingMessage::RingMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* ringEndpoint, ::java::util::Hashtable* endpoints)  /* throws(IOException) */
    : RingMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,ringEndpoint,endpoints);
}

constexpr int64_t rice::p2p::multiring::messaging::RingMessage::serialVersionUID;

constexpr int16_t rice::p2p::multiring::messaging::RingMessage::TYPE;

void rice::p2p::multiring::messaging::RingMessage::ctor(::rice::p2p::multiring::RingId* id, ::rice::p2p::commonapi::rawserialization::RawMessage* message, ::java::lang::String* application)
{
    super::ctor();
    this->id = id;
    this->message = message;
    this->application = application;
}

int32_t rice::p2p::multiring::messaging::RingMessage::getPriority()
{
    return npc(message)->getPriority();
}

rice::p2p::multiring::RingId* rice::p2p::multiring::messaging::RingMessage::getId()
{
    return id;
}

rice::p2p::commonapi::rawserialization::RawMessage* rice::p2p::multiring::messaging::RingMessage::getRawMessage()
{
    return message;
}

rice::p2p::commonapi::Message* rice::p2p::multiring::messaging::RingMessage::getMessage()
{
    if(npc(message)->getType() == 0) {
        return npc((java_cast< ::rice::p2p::util::rawserialization::JavaSerializedMessage* >(message)))->getMessage();
    }
    return message;
}

java::lang::String* rice::p2p::multiring::messaging::RingMessage::getApplication()
{
    return application;
}

int16_t rice::p2p::multiring::messaging::RingMessage::getType()
{
    return TYPE;
}

void rice::p2p::multiring::messaging::RingMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(id)->serialize(buf);
    npc(buf)->writeUTF(application);
    npc(buf)->writeShort(npc(message)->getType());
    auto priority = npc(message)->getPriority();
    if(priority > ::java::lang::Byte::MAX_VALUE)
        throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Priority must be in the range of "_j)->append(::java::lang::Byte::MIN_VALUE)
            ->append(u" to "_j)
            ->append(::java::lang::Byte::MAX_VALUE)
            ->append(u".  Lower values are higher priority. Priority of "_j)
            ->append(static_cast< ::java::lang::Object* >(message))
            ->append(u" was "_j)
            ->append(priority)
            ->append(u"."_j)->toString());

    if(priority < ::java::lang::Byte::MIN_VALUE)
        throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Priority must be in the range of "_j)->append(::java::lang::Byte::MIN_VALUE)
            ->append(u" to "_j)
            ->append(::java::lang::Byte::MAX_VALUE)
            ->append(u".  Lower values are higher priority. Priority of "_j)
            ->append(static_cast< ::java::lang::Object* >(message))
            ->append(u" was "_j)
            ->append(priority)
            ->append(u"."_j)->toString());

    npc(buf)->writeByte(static_cast< int8_t >(priority));
    npc(message)->serialize(buf);
}

void rice::p2p::multiring::messaging::RingMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* ringEndpoint, ::java::util::Hashtable* endpoints) /* throws(IOException) */
{
    super::ctor();
    id = new ::rice::p2p::multiring::RingId(buf, ringEndpoint);
    application = npc(buf)->readUTF();
    auto endpoint = java_cast< ::rice::p2p::commonapi::Endpoint* >(java_cast< ::rice::p2p::commonapi::Endpoint* >(npc(endpoints)->get(static_cast< ::java::lang::Object* >(application))));
    if(endpoint == nullptr) {
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Couldn't find application:"_j)->append(application)->toString());
    }
    auto md = npc(endpoint)->getDeserializer();
    auto type = npc(buf)->readShort();
    auto priority = npc(buf)->readByte();
    auto m = npc(md)->deserialize(buf, type, priority, nullptr);
    if(type == 0) {
        message = new ::rice::p2p::util::rawserialization::JavaSerializedMessage(m);
    } else {
        message = java_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(m);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::multiring::messaging::RingMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.multiring.messaging.RingMessage", 40);
    return c;
}

java::lang::Class* rice::p2p::multiring::messaging::RingMessage::getClass0()
{
    return class_();
}

