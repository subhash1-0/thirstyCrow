// Generated from /pastry-2.1/src/rice/p2p/util/rawserialization/JavaSerializer.java
#include <rice/p2p/util/rawserialization/JavaSerializer.hpp>

#include <java/io/ByteArrayOutputStream.hpp>
#include <java/io/IOException.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
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

rice::p2p::util::rawserialization::JavaSerializer::JavaSerializer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::rawserialization::JavaSerializer::JavaSerializer()
    : JavaSerializer(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::rawserialization::JavaSerializer::serialize(::rice::p2p::commonapi::Message* msg, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    clinit();
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

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::rawserialization::JavaSerializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.rawserialization.JavaSerializer", 45);
    return c;
}

java::lang::Class* rice::p2p::util::rawserialization::JavaSerializer::getClass0()
{
    return class_();
}

