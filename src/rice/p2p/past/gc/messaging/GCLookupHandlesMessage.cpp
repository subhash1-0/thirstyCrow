// Generated from /pastry-2.1/src/rice/p2p/past/gc/messaging/GCLookupHandlesMessage.java
#include <rice/p2p/past/gc/messaging/GCLookupHandlesMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::gc::messaging::GCLookupHandlesMessage::GCLookupHandlesMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::gc::messaging::GCLookupHandlesMessage::GCLookupHandlesMessage(int32_t uid, ::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest) 
    : GCLookupHandlesMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,id,source,dest);
}

rice::p2p::past::gc::messaging::GCLookupHandlesMessage::GCLookupHandlesMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : GCLookupHandlesMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::past::gc::messaging::GCLookupHandlesMessage::TYPE;

void rice::p2p::past::gc::messaging::GCLookupHandlesMessage::ctor(int32_t uid, ::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest)
{
    super::ctor(uid, id, ::java::lang::Integer::MAX_VALUE, source, dest);
}

java::lang::String* rice::p2p::past::gc::messaging::GCLookupHandlesMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"[GCLookupHandlesMessage for "_j)->append(static_cast< ::java::lang::Object* >(getId()))
        ->append(u"]"_j)->toString();
}

int16_t rice::p2p::past::gc::messaging::GCLookupHandlesMessage::getType()
{
    return TYPE;
}

void rice::p2p::past::gc::messaging::GCLookupHandlesMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    serializeHelper(buf);
}

rice::p2p::past::gc::messaging::GCLookupHandlesMessage* rice::p2p::past::gc::messaging::GCLookupHandlesMessage::buildGC(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new GCLookupHandlesMessage(buf, endpoint);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::past::gc::messaging::GCLookupHandlesMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::messaging::GCLookupHandlesMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.gc.messaging.GCLookupHandlesMessage", 49);
    return c;
}

void rice::p2p::past::gc::messaging::GCLookupHandlesMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, bool javaSerialize)
{
    super::serialize(buf, javaSerialize);
}

java::lang::Class* rice::p2p::past::gc::messaging::GCLookupHandlesMessage::getClass0()
{
    return class_();
}

