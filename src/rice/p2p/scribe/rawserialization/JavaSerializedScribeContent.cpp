// Generated from /pastry-2.1/src/rice/p2p/scribe/rawserialization/JavaSerializedScribeContent.java
#include <rice/p2p/scribe/rawserialization/JavaSerializedScribeContent.hpp>

#include <java/io/ByteArrayOutputStream.hpp>
#include <java/io/IOException.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/scribe/ScribeContent.hpp>
#include <rice/p2p/util/rawserialization/JavaSerializationException.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::scribe::rawserialization::JavaSerializedScribeContent::JavaSerializedScribeContent(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::scribe::rawserialization::JavaSerializedScribeContent::JavaSerializedScribeContent(::rice::p2p::scribe::ScribeContent* content) 
    : JavaSerializedScribeContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(content);
}

constexpr int16_t rice::p2p::scribe::rawserialization::JavaSerializedScribeContent::TYPE;

void rice::p2p::scribe::rawserialization::JavaSerializedScribeContent::ctor(::rice::p2p::scribe::ScribeContent* content)
{
    super::ctor();
    this->content = content;
}

void rice::p2p::scribe::rawserialization::JavaSerializedScribeContent::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    try {
        auto baos = new ::java::io::ByteArrayOutputStream();
        auto oos = new ::java::io::ObjectOutputStream(baos);
        npc(oos)->writeObject(static_cast< ::java::lang::Object* >(content));
        npc(oos)->close();
        auto temp = npc(baos)->toByteArray_();
        npc(buf)->writeInt(npc(temp)->length);
        npc(buf)->write(temp, 0, npc(temp)->length);
    } catch (::java::io::IOException* ioe) {
        throw new ::rice::p2p::util::rawserialization::JavaSerializationException(content, ioe);
    }
}

int16_t rice::p2p::scribe::rawserialization::JavaSerializedScribeContent::getType()
{
    return 0;
}

java::lang::String* rice::p2p::scribe::rawserialization::JavaSerializedScribeContent::toString()
{
    return ::java::lang::StringBuilder().append(u"JSSC ["_j)->append(static_cast< ::java::lang::Object* >(content))
        ->append(u"]"_j)->toString();
}

rice::p2p::scribe::ScribeContent* rice::p2p::scribe::rawserialization::JavaSerializedScribeContent::getContent()
{
    return content;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::rawserialization::JavaSerializedScribeContent::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.rawserialization.JavaSerializedScribeContent", 60);
    return c;
}

java::lang::Class* rice::p2p::scribe::rawserialization::JavaSerializedScribeContent::getClass0()
{
    return class_();
}

