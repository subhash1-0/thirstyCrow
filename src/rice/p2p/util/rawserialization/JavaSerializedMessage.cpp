// Generated from /pastry-2.1/src/rice/p2p/util/rawserialization/JavaSerializedMessage.java
#include <rice/p2p/util/rawserialization/JavaSerializedMessage.hpp>

#include <java/io/ByteArrayOutputStream.hpp>
#include <java/io/IOException.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/util/rawserialization/JavaSerializationException.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::rawserialization::JavaSerializedMessage::JavaSerializedMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::rawserialization::JavaSerializedMessage::JavaSerializedMessage(::rice::p2p::commonapi::Message* msg) 
    : JavaSerializedMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(msg);
}

void rice::p2p::util::rawserialization::JavaSerializedMessage::ctor(::rice::p2p::commonapi::Message* msg)
{
    super::ctor();
    this->msg = msg;
    if(msg == nullptr)
        throw new ::java::lang::RuntimeException(u"msg cannot be null"_j);

}

int16_t rice::p2p::util::rawserialization::JavaSerializedMessage::getType()
{
    return 0;
}

void rice::p2p::util::rawserialization::JavaSerializedMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    try {
        auto baos = new ::java::io::ByteArrayOutputStream();
        auto oos = new ::java::io::ObjectOutputStream(baos);
        npc(oos)->writeObject(static_cast< ::java::lang::Object* >(msg));
        npc(oos)->close();
        auto temp = npc(baos)->toByteArray_();
        npc(buf)->write(temp, 0, npc(temp)->length);
    } catch (::java::io::IOException* ioe) {
        throw new JavaSerializationException(msg, ioe);
    }
}

rice::p2p::commonapi::Message* rice::p2p::util::rawserialization::JavaSerializedMessage::getMessage()
{
    return msg;
}

int32_t rice::p2p::util::rawserialization::JavaSerializedMessage::getPriority()
{
    return npc(msg)->getPriority();
}

java::lang::String* rice::p2p::util::rawserialization::JavaSerializedMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"JavaSerializedMessage["_j)->append(static_cast< ::java::lang::Object* >(msg))
        ->append(u"]"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::rawserialization::JavaSerializedMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.rawserialization.JavaSerializedMessage", 52);
    return c;
}

java::lang::Class* rice::p2p::util::rawserialization::JavaSerializedMessage::getClass0()
{
    return class_();
}

