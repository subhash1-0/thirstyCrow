// Generated from /pastry-2.1/src/rice/p2p/past/messaging/FetchMessage.java
#include <rice/p2p/past/messaging/FetchMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>
#include <rice/p2p/past/rawserialization/JavaSerializedPastContentHandle.hpp>
#include <rice/p2p/past/rawserialization/PastContentDeserializer.hpp>
#include <rice/p2p/past/rawserialization/PastContentHandleDeserializer.hpp>
#include <rice/p2p/past/rawserialization/RawPastContent.hpp>
#include <rice/p2p/past/rawserialization/RawPastContentHandle.hpp>

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

rice::p2p::past::messaging::FetchMessage::FetchMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::messaging::FetchMessage::FetchMessage(int32_t uid, ::rice::p2p::past::PastContentHandle* handle, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest) 
    : FetchMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,handle,source,dest);
}

rice::p2p::past::messaging::FetchMessage::FetchMessage(int32_t uid, ::rice::p2p::past::rawserialization::RawPastContentHandle* handle, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest) 
    : FetchMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,handle,source,dest);
}

rice::p2p::past::messaging::FetchMessage::FetchMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd, ::rice::p2p::past::rawserialization::PastContentHandleDeserializer* pchd)  /* throws(IOException) */
    : FetchMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint,pcd,pchd);
}

void rice::p2p::past::messaging::FetchMessage::init()
{
    cached = false;
}

constexpr int16_t rice::p2p::past::messaging::FetchMessage::TYPE;

void rice::p2p::past::messaging::FetchMessage::ctor(int32_t uid, ::rice::p2p::past::PastContentHandle* handle, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest)
{
    ctor(uid, dynamic_cast< ::rice::p2p::past::rawserialization::RawPastContentHandle* >(handle) != nullptr ? java_cast< ::rice::p2p::past::rawserialization::RawPastContentHandle* >(handle) : static_cast< ::rice::p2p::past::rawserialization::RawPastContentHandle* >(new ::rice::p2p::past::rawserialization::JavaSerializedPastContentHandle(handle)), source, dest);
}

void rice::p2p::past::messaging::FetchMessage::ctor(int32_t uid, ::rice::p2p::past::rawserialization::RawPastContentHandle* handle, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest)
{
    super::ctor(uid, source, dest);
    init();
    this->handle = handle;
}

rice::p2p::past::PastContentHandle* rice::p2p::past::messaging::FetchMessage::getHandle()
{
    if(npc(handle)->getType() == 0)
        return npc((java_cast< ::rice::p2p::past::rawserialization::JavaSerializedPastContentHandle* >(handle)))->getPCH();

    return handle;
}

bool rice::p2p::past::messaging::FetchMessage::isCached()
{
    return cached;
}

void rice::p2p::past::messaging::FetchMessage::setCached()
{
    cached = true;
}

java::lang::String* rice::p2p::past::messaging::FetchMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"[FetchMessage for "_j)->append(static_cast< ::java::lang::Object* >(handle))
        ->append(u" cached? "_j)
        ->append(cached)
        ->append(u"]"_j)->toString();
}

int16_t rice::p2p::past::messaging::FetchMessage::getType()
{
    return TYPE;
}

void rice::p2p::past::messaging::FetchMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    if(response != nullptr && dynamic_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(response) != nullptr) {
        super::serialize(buf, false);
        auto rpc = java_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(response);
        npc(buf)->writeShort(npc(rpc)->getType());
        npc(rpc)->serialize(buf);
    } else {
        super::serialize(buf, true);
    }
    npc(buf)->writeBoolean(cached);
    npc(buf)->writeShort(npc(handle)->getType());
    npc(handle)->serialize(buf);
}

rice::p2p::past::messaging::FetchMessage* rice::p2p::past::messaging::FetchMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd, ::rice::p2p::past::rawserialization::PastContentHandleDeserializer* pchd) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new FetchMessage(buf, endpoint, pcd, pchd);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::past::messaging::FetchMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd, ::rice::p2p::past::rawserialization::PastContentHandleDeserializer* pchd) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    init();
    if(serType == S_SUB()) {
        auto type2 = npc(buf)->readShort();
        response = npc(pcd)->deserializePastContent(buf, endpoint, type2);
    }
    cached = npc(buf)->readBoolean();
    auto type = npc(buf)->readShort();
    if(type == 0) {
        handle = new ::rice::p2p::past::rawserialization::JavaSerializedPastContentHandle(npc(pchd)->deserializePastContentHandle(buf, endpoint, type));
    } else {
        handle = java_cast< ::rice::p2p::past::rawserialization::RawPastContentHandle* >(npc(pchd)->deserializePastContentHandle(buf, endpoint, type));
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::messaging::FetchMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.messaging.FetchMessage", 36);
    return c;
}

void rice::p2p::past::messaging::FetchMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, bool javaSerialize)
{
    super::serialize(buf, javaSerialize);
}

java::lang::Class* rice::p2p::past::messaging::FetchMessage::getClass0()
{
    return class_();
}

