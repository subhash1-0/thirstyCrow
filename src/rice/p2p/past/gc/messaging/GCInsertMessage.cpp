// Generated from /pastry-2.1/src/rice/p2p/past/gc/messaging/GCInsertMessage.java
#include <rice/p2p/past/gc/messaging/GCInsertMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/past/rawserialization/RawPastContent.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::gc::messaging::GCInsertMessage::GCInsertMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::gc::messaging::GCInsertMessage::GCInsertMessage(int32_t uid, ::rice::p2p::past::PastContent* content, int64_t expiration, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest) 
    : GCInsertMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,content,expiration,source,dest);
}

rice::p2p::past::gc::messaging::GCInsertMessage::GCInsertMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd)  /* throws(IOException) */
    : GCInsertMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint,pcd);
}

constexpr int16_t rice::p2p::past::gc::messaging::GCInsertMessage::TYPE;

void rice::p2p::past::gc::messaging::GCInsertMessage::ctor(int32_t uid, ::rice::p2p::past::PastContent* content, int64_t expiration, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest)
{
    super::ctor(uid, content, source, dest);
    this->expiration = expiration;
}

int64_t rice::p2p::past::gc::messaging::GCInsertMessage::getExpiration()
{
    return expiration;
}

java::lang::String* rice::p2p::past::gc::messaging::GCInsertMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"[GCInsertMessage for "_j)->append(static_cast< ::java::lang::Object* >(content))
        ->append(u" exp "_j)
        ->append(expiration)
        ->append(u"]"_j)->toString();
}

int16_t rice::p2p::past::gc::messaging::GCInsertMessage::getType()
{
    return TYPE;
}

void rice::p2p::past::gc::messaging::GCInsertMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    super::serializeHelper(buf);
    npc(buf)->writeLong(expiration);
}

rice::p2p::past::gc::messaging::GCInsertMessage* rice::p2p::past::gc::messaging::GCInsertMessage::buildGC(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new GCInsertMessage(buf, endpoint, pcd);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::past::gc::messaging::GCInsertMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd) /* throws(IOException) */
{
    super::ctor(buf, endpoint, pcd);
    expiration = npc(buf)->readLong();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::messaging::GCInsertMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.gc.messaging.GCInsertMessage", 42);
    return c;
}

void rice::p2p::past::gc::messaging::GCInsertMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, bool javaSerialize)
{
    super::serialize(buf, javaSerialize);
}

java::lang::Class* rice::p2p::past::gc::messaging::GCInsertMessage::getClass0()
{
    return class_();
}

