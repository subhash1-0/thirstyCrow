// Generated from /pastry-2.1/src/rice/p2p/past/gc/rawserialization/JavaSerializedGCPastContent.java
#include <rice/p2p/past/gc/rawserialization/JavaSerializedGCPastContent.hpp>

#include <java/io/ByteArrayOutputStream.hpp>
#include <java/io/IOException.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>
#include <rice/p2p/past/gc/GCPastContent.hpp>
#include <rice/p2p/past/gc/GCPastContentHandle.hpp>
#include <rice/p2p/past/gc/GCPastMetadata.hpp>
#include <rice/p2p/util/rawserialization/JavaSerializationException.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::gc::rawserialization::JavaSerializedGCPastContent::JavaSerializedGCPastContent(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::gc::rawserialization::JavaSerializedGCPastContent::JavaSerializedGCPastContent(::rice::p2p::past::gc::GCPastContent* content) 
    : JavaSerializedGCPastContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(content);
}

constexpr int16_t rice::p2p::past::gc::rawserialization::JavaSerializedGCPastContent::TYPE;

void rice::p2p::past::gc::rawserialization::JavaSerializedGCPastContent::ctor(::rice::p2p::past::gc::GCPastContent* content)
{
    super::ctor();
    this->content = content;
}

void rice::p2p::past::gc::rawserialization::JavaSerializedGCPastContent::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
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

int16_t rice::p2p::past::gc::rawserialization::JavaSerializedGCPastContent::getType()
{
    return TYPE;
}

java::lang::String* rice::p2p::past::gc::rawserialization::JavaSerializedGCPastContent::toString()
{
    return ::java::lang::StringBuilder().append(u"JSPC ["_j)->append(static_cast< ::java::lang::Object* >(content))
        ->append(u"]"_j)->toString();
}

rice::p2p::past::PastContent* rice::p2p::past::gc::rawserialization::JavaSerializedGCPastContent::getContent()
{
    return content;
}

rice::p2p::past::PastContent* rice::p2p::past::gc::rawserialization::JavaSerializedGCPastContent::checkInsert(::rice::p2p::commonapi::Id* id, ::rice::p2p::past::PastContent* existingContent) /* throws(PastException) */
{
    return npc(content)->checkInsert(id, existingContent);
}

rice::p2p::past::PastContentHandle* rice::p2p::past::gc::rawserialization::JavaSerializedGCPastContent::getHandle(::rice::p2p::past::Past* local)
{
    return npc(content)->getHandle(local);
}

rice::p2p::commonapi::Id* rice::p2p::past::gc::rawserialization::JavaSerializedGCPastContent::getId()
{
    return npc(content)->getId();
}

bool rice::p2p::past::gc::rawserialization::JavaSerializedGCPastContent::isMutable()
{
    return npc(content)->isMutable();
}

int64_t rice::p2p::past::gc::rawserialization::JavaSerializedGCPastContent::getVersion()
{
    return npc(content)->getVersion();
}

rice::p2p::past::gc::GCPastContentHandle* rice::p2p::past::gc::rawserialization::JavaSerializedGCPastContent::getHandle(::rice::p2p::past::gc::GCPast* local, int64_t expiration)
{
    return npc(content)->getHandle(local, expiration);
}

rice::p2p::past::gc::GCPastMetadata* rice::p2p::past::gc::rawserialization::JavaSerializedGCPastContent::getMetadata(int64_t expiration)
{
    return npc(content)->getMetadata(expiration);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::rawserialization::JavaSerializedGCPastContent::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.gc.rawserialization.JavaSerializedGCPastContent", 61);
    return c;
}

java::lang::Class* rice::p2p::past::gc::rawserialization::JavaSerializedGCPastContent::getClass0()
{
    return class_();
}

