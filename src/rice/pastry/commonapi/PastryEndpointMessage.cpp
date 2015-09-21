// Generated from /pastry-2.1/src/rice/pastry/commonapi/PastryEndpointMessage.java
#include <rice/pastry/commonapi/PastryEndpointMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Byte.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/rawserialization/MessageDeserializer.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>
#include <rice/p2p/util/rawserialization/JavaSerializedMessage.hpp>
#include <rice/pastry/NodeHandle.hpp>

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

rice::pastry::commonapi::PastryEndpointMessage::PastryEndpointMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::commonapi::PastryEndpointMessage::PastryEndpointMessage(int32_t address, ::rice::p2p::commonapi::Message* message, ::rice::pastry::NodeHandle* sender) 
    : PastryEndpointMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(address,message,sender);
}

rice::pastry::commonapi::PastryEndpointMessage::PastryEndpointMessage(int32_t address, ::rice::p2p::commonapi::rawserialization::RawMessage* message, ::rice::pastry::NodeHandle* sender) 
    : PastryEndpointMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(address,message,sender);
}

rice::pastry::commonapi::PastryEndpointMessage::PastryEndpointMessage(int32_t address, ::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md, int16_t type, int32_t priority, ::rice::pastry::NodeHandle* sender)  /* throws(IOException) */
    : PastryEndpointMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(address,buf,md,type,priority,sender);
}

constexpr int64_t rice::pastry::commonapi::PastryEndpointMessage::serialVersionUID;

void rice::pastry::commonapi::PastryEndpointMessage::ctor(int32_t address, ::rice::p2p::commonapi::Message* message, ::rice::pastry::NodeHandle* sender)
{
    ctor(address, dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(message) != nullptr ? java_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(message) : static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(new ::rice::p2p::util::rawserialization::JavaSerializedMessage(message)), sender);
}

void rice::pastry::commonapi::PastryEndpointMessage::checkRawType(::rice::p2p::commonapi::rawserialization::RawMessage* message)
{
    clinit();
    if(npc(message)->getType() == 0) {
        if(!(dynamic_cast< ::rice::p2p::util::rawserialization::JavaSerializedMessage* >(message) != nullptr)) {
            throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Message "_j)->append(static_cast< ::java::lang::Object* >(message))
                ->append(u" is raw, but its type is 0, this is only allowed by Java Serialized Messages."_j)->toString());
        }
    }
}

void rice::pastry::commonapi::PastryEndpointMessage::ctor(int32_t address, ::rice::p2p::commonapi::rawserialization::RawMessage* message, ::rice::pastry::NodeHandle* sender)
{
    super::ctor(address);
    checkRawType(message);
    setSender(sender);
    this->message = message;
    setPriority(npc(message)->getPriority());
}

rice::p2p::commonapi::Message* rice::pastry::commonapi::PastryEndpointMessage::getMessage()
{
    if(npc(message)->getType() == 0)
        return npc((java_cast< ::rice::p2p::util::rawserialization::JavaSerializedMessage* >(message)))->getMessage();

    return message;
}

void rice::pastry::commonapi::PastryEndpointMessage::setMessage(::rice::p2p::commonapi::Message* message)
{
    if(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(message) != nullptr) {
        setMessage(java_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(message));
    } else {
        this->message = new ::rice::p2p::util::rawserialization::JavaSerializedMessage(message);
    }
}

void rice::pastry::commonapi::PastryEndpointMessage::setMessage(::rice::p2p::commonapi::rawserialization::RawMessage* message)
{
    this->message = message;
}

java::lang::String* rice::pastry::commonapi::PastryEndpointMessage::toString()
{
    return npc(getMessage())->toString();
}

int16_t rice::pastry::commonapi::PastryEndpointMessage::getType()
{
    return npc(message)->getType();
}

void rice::pastry::commonapi::PastryEndpointMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
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

    npc(message)->serialize(buf);
}

void rice::pastry::commonapi::PastryEndpointMessage::ctor(int32_t address, ::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md, int16_t type, int32_t priority, ::rice::pastry::NodeHandle* sender) /* throws(IOException) */
{
    super::ctor(address);
    int8_t version = int32_t(0);
    switch (version) {
    case int32_t(0):
        setSender(sender);
        if(type == 0) {
            message = new ::rice::p2p::util::rawserialization::JavaSerializedMessage(npc(md)->deserialize(buf, type, priority, sender));
        } else {
            message = java_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(npc(md)->deserialize(buf, type, priority, sender));
        }
        if(getMessage() == nullptr)
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"PEM.deserialize() message = null type:"_j)->append(type)
                ->append(u" md:"_j)
                ->append(static_cast< ::java::lang::Object* >(md))->toString());

        break;
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::commonapi::PastryEndpointMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.commonapi.PastryEndpointMessage", 43);
    return c;
}

java::lang::Class* rice::pastry::commonapi::PastryEndpointMessage::getClass0()
{
    return class_();
}

