// Generated from /pastry-2.1/src/rice/pastry/transport/TLDeserializer.java
#include <rice/pastry/transport/TLDeserializer.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Byte.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Map.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/MessageDeserializer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>
#include <rice/pastry/NodeHandleFactory.hpp>
#include <rice/pastry/messaging/PRawMessage.hpp>

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

rice::pastry::transport::TLDeserializer::TLDeserializer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::transport::TLDeserializer::TLDeserializer(::rice::pastry::NodeHandleFactory* nodeHandleFactory, ::rice::environment::Environment* env) 
    : TLDeserializer(*static_cast< ::default_init_tag* >(0))
{
    ctor(nodeHandleFactory,env);
}

void rice::pastry::transport::TLDeserializer::ctor(::rice::pastry::NodeHandleFactory* nodeHandleFactory, ::rice::environment::Environment* env)
{
    super::ctor();
    this->environment = env;
    this->nodeHandleFactory = nodeHandleFactory;
    this->deserializers = new ::java::util::HashMap();
    this->logger = npc(npc(environment)->getLogManager())->getLogger(TLDeserializer::class_(), nullptr);
}

rice::p2p::commonapi::rawserialization::RawMessage* rice::pastry::transport::TLDeserializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */
{
    auto address = npc(buf)->readInt();
    auto priority = npc(buf)->readByte();
    auto type = npc(buf)->readShort();
    auto deserializer = getDeserializer(address);
    if(deserializer == nullptr) {
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown address:"_j)->append(address)->toString());
    }
    auto msg = npc(deserializer)->deserialize(buf, type, priority, sender);
    if(msg == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Deserialized message to null! d:"_j)->append(static_cast< ::java::lang::Object* >(deserializer))
                ->append(u" a:"_j)
                ->append(address)
                ->append(u" t:"_j)
                ->append(type)
                ->append(u" p:"_j)
                ->append(priority)
                ->append(u" s:"_j)
                ->append(static_cast< ::java::lang::Object* >(sender))
                ->append(u" b:"_j)
                ->append(static_cast< ::java::lang::Object* >(buf))->toString());

    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"deserialize():"_j)->append(static_cast< ::java::lang::Object* >(msg))->toString());

    return java_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(msg);
}

void rice::pastry::transport::TLDeserializer::serialize(::rice::p2p::commonapi::rawserialization::RawMessage* m, ::rice::p2p::commonapi::rawserialization::OutputBuffer* o) /* throws(IOException) */
{
    auto msg = java_cast< ::rice::pastry::messaging::PRawMessage* >(m);
    auto address = npc(msg)->getDestination();
    npc(o)->writeInt(address);
    auto priority = npc(msg)->getPriority();
    if(priority > ::java::lang::Byte::MAX_VALUE)
        throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Priority must be in the range of "_j)->append(::java::lang::Byte::MIN_VALUE)
            ->append(u" to "_j)
            ->append(::java::lang::Byte::MAX_VALUE)
            ->append(u".  Lower values are higher priority. Priority of "_j)
            ->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" was "_j)
            ->append(priority)
            ->append(u"."_j)->toString());

    if(priority < ::java::lang::Byte::MIN_VALUE)
        throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Priority must be in the range of "_j)->append(::java::lang::Byte::MIN_VALUE)
            ->append(u" to "_j)
            ->append(::java::lang::Byte::MAX_VALUE)
            ->append(u".  Lower values are higher priority. Priority of "_j)
            ->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" was "_j)
            ->append(priority)
            ->append(u"."_j)->toString());

    npc(o)->writeByte(static_cast< int8_t >(priority));
    auto type = npc(msg)->getType();
    npc(o)->writeShort(type);
    npc(msg)->serialize(o);
}

void rice::pastry::transport::TLDeserializer::clearDeserializer(int32_t address)
{
    npc(deserializers)->remove(::java::lang::Integer::valueOf(address));
}

rice::p2p::commonapi::rawserialization::MessageDeserializer* rice::pastry::transport::TLDeserializer::getDeserializer(int32_t address)
{
    return java_cast< ::rice::p2p::commonapi::rawserialization::MessageDeserializer* >(npc(deserializers)->get(::java::lang::Integer::valueOf(address)));
}

void rice::pastry::transport::TLDeserializer::setDeserializer(int32_t address, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md)
{
    npc(deserializers)->put(::java::lang::Integer::valueOf(address), md);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::transport::TLDeserializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.transport.TLDeserializer", 36);
    return c;
}

java::lang::Class* rice::pastry::transport::TLDeserializer::getClass0()
{
    return class_();
}

