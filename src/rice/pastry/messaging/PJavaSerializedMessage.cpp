// Generated from /pastry-2.1/src/rice/pastry/messaging/PJavaSerializedMessage.java
#include <rice/pastry/messaging/PJavaSerializedMessage.hpp>

#include <java/io/ByteArrayOutputStream.hpp>
#include <java/io/IOException.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/util/rawserialization/JavaSerializationException.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::messaging::PJavaSerializedMessage::PJavaSerializedMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::messaging::PJavaSerializedMessage::PJavaSerializedMessage(Message* msg) 
    : PJavaSerializedMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(msg);
}

void rice::pastry::messaging::PJavaSerializedMessage::ctor(Message* msg)
{
    super::ctor(npc(msg)->getDestination());
    this->msg = msg;
    if(msg == nullptr)
        throw new ::java::lang::RuntimeException(u"msg cannot be null"_j);

}

int16_t rice::pastry::messaging::PJavaSerializedMessage::getType()
{
    return 0;
}

void rice::pastry::messaging::PJavaSerializedMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    try {
        auto baos = new ::java::io::ByteArrayOutputStream();
        auto oos = new ::java::io::ObjectOutputStream(baos);
        npc(oos)->writeObject(static_cast< ::java::lang::Object* >(msg));
        npc(oos)->close();
        auto temp = npc(baos)->toByteArray_();
        npc(buf)->write(temp, 0, npc(temp)->length);
    } catch (::java::io::IOException* ioe) {
        throw new ::rice::p2p::util::rawserialization::JavaSerializationException(::java::lang::StringBuilder().append(u"Error serializing "_j)->append(static_cast< ::java::lang::Object* >(msg))->toString(), ioe);
    }
}

rice::pastry::messaging::Message* rice::pastry::messaging::PJavaSerializedMessage::getMessage()
{
    return msg;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::messaging::PJavaSerializedMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.messaging.PJavaSerializedMessage", 44);
    return c;
}

java::lang::Class* rice::pastry::messaging::PJavaSerializedMessage::getClass0()
{
    return class_();
}

