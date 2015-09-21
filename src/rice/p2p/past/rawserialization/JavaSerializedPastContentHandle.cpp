// Generated from /pastry-2.1/src/rice/p2p/past/rawserialization/JavaSerializedPastContentHandle.java
#include <rice/p2p/past/rawserialization/JavaSerializedPastContentHandle.hpp>

#include <java/io/ByteArrayOutputStream.hpp>
#include <java/io/IOException.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>
#include <rice/p2p/util/rawserialization/JavaSerializationException.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::rawserialization::JavaSerializedPastContentHandle::JavaSerializedPastContentHandle(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::rawserialization::JavaSerializedPastContentHandle::JavaSerializedPastContentHandle(::rice::p2p::past::PastContentHandle* handle) 
    : JavaSerializedPastContentHandle(*static_cast< ::default_init_tag* >(0))
{
    ctor(handle);
}

constexpr int16_t rice::p2p::past::rawserialization::JavaSerializedPastContentHandle::TYPE;

void rice::p2p::past::rawserialization::JavaSerializedPastContentHandle::ctor(::rice::p2p::past::PastContentHandle* handle)
{
    super::ctor();
    this->handle = handle;
}

void rice::p2p::past::rawserialization::JavaSerializedPastContentHandle::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    try {
        auto baos = new ::java::io::ByteArrayOutputStream();
        auto oos = new ::java::io::ObjectOutputStream(baos);
        npc(oos)->writeObject(static_cast< ::java::lang::Object* >(handle));
        npc(oos)->close();
        auto temp = npc(baos)->toByteArray_();
        npc(buf)->writeInt(npc(temp)->length);
        npc(buf)->write(temp, 0, npc(temp)->length);
    } catch (::java::io::IOException* ioe) {
        throw new ::rice::p2p::util::rawserialization::JavaSerializationException(handle, ioe);
    }
}

int16_t rice::p2p::past::rawserialization::JavaSerializedPastContentHandle::getType()
{
    return TYPE;
}

java::lang::String* rice::p2p::past::rawserialization::JavaSerializedPastContentHandle::toString()
{
    return ::java::lang::StringBuilder().append(u"JSPCH ["_j)->append(static_cast< ::java::lang::Object* >(handle))
        ->append(u"]"_j)->toString();
}

rice::p2p::commonapi::Id* rice::p2p::past::rawserialization::JavaSerializedPastContentHandle::getId()
{
    return npc(handle)->getId();
}

rice::p2p::commonapi::NodeHandle* rice::p2p::past::rawserialization::JavaSerializedPastContentHandle::getNodeHandle()
{
    return npc(handle)->getNodeHandle();
}

rice::p2p::past::PastContentHandle* rice::p2p::past::rawserialization::JavaSerializedPastContentHandle::getPCH()
{
    return handle;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::rawserialization::JavaSerializedPastContentHandle::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.rawserialization.JavaSerializedPastContentHandle", 62);
    return c;
}

java::lang::Class* rice::p2p::past::rawserialization::JavaSerializedPastContentHandle::getClass0()
{
    return class_();
}

