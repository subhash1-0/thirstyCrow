// Generated from /pastry-2.1/src/rice/p2p/past/messaging/CacheMessage.java
#include <rice/p2p/past/messaging/CacheMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/rawserialization/JavaSerializedPastContent.hpp>
#include <rice/p2p/past/rawserialization/PastContentDeserializer.hpp>
#include <rice/p2p/past/rawserialization/RawPastContent.hpp>

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

rice::p2p::past::messaging::CacheMessage::CacheMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::messaging::CacheMessage::CacheMessage(int32_t uid, ::rice::p2p::past::PastContent* content, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest) 
    : CacheMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,content,source,dest);
}

rice::p2p::past::messaging::CacheMessage::CacheMessage(int32_t uid, ::rice::p2p::past::rawserialization::RawPastContent* content, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest) 
    : CacheMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,content,source,dest);
}

rice::p2p::past::messaging::CacheMessage::CacheMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd)  /* throws(IOException) */
    : CacheMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint,pcd);
}

constexpr int16_t rice::p2p::past::messaging::CacheMessage::TYPE;

void rice::p2p::past::messaging::CacheMessage::ctor(int32_t uid, ::rice::p2p::past::PastContent* content, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest)
{
    ctor(uid, dynamic_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(content) != nullptr ? java_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(content) : static_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(new ::rice::p2p::past::rawserialization::JavaSerializedPastContent(content)), source, dest);
}

void rice::p2p::past::messaging::CacheMessage::ctor(int32_t uid, ::rice::p2p::past::rawserialization::RawPastContent* content, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest)
{
    super::ctor(uid, source, dest);
    this->content = content;
}

rice::p2p::past::PastContent* rice::p2p::past::messaging::CacheMessage::getContent()
{
    if(npc(content)->getType() == 0)
        return npc((java_cast< ::rice::p2p::past::rawserialization::JavaSerializedPastContent* >(content)))->getContent();

    return content;
}

void rice::p2p::past::messaging::CacheMessage::returnResponse(::rice::Continuation* c, ::rice::environment::Environment* env, ::java::lang::String* instance)
{
    throw new ::java::lang::RuntimeException(u"ERROR: returnResponse should not be called on cacheMessage!"_j);
}

java::lang::String* rice::p2p::past::messaging::CacheMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"[CacheMessage for "_j)->append(static_cast< ::java::lang::Object* >(content))
        ->append(u"]"_j)->toString();
}

int16_t rice::p2p::past::messaging::CacheMessage::getType()
{
    return TYPE;
}

void rice::p2p::past::messaging::CacheMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    super::serialize(buf);
    npc(buf)->writeShort(npc(content)->getType());
    npc(content)->serialize(buf);
}

rice::p2p::past::messaging::CacheMessage* rice::p2p::past::messaging::CacheMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new CacheMessage(buf, endpoint, pcd);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::past::messaging::CacheMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    auto contentType = npc(buf)->readShort();
    if(contentType == 0) {
        content = new ::rice::p2p::past::rawserialization::JavaSerializedPastContent(npc(pcd)->deserializePastContent(buf, endpoint, contentType));
    } else {
        content = java_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(npc(pcd)->deserializePastContent(buf, endpoint, contentType));
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::messaging::CacheMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.messaging.CacheMessage", 36);
    return c;
}

java::lang::Class* rice::p2p::past::messaging::CacheMessage::getClass0()
{
    return class_();
}

