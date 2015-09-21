// Generated from /pastry-2.1/src/rice/p2p/past/messaging/FetchHandleMessage.java
#include <rice/p2p/past/messaging/FetchHandleMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>
#include <rice/p2p/past/rawserialization/PastContentHandleDeserializer.hpp>
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

rice::p2p::past::messaging::FetchHandleMessage::FetchHandleMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::messaging::FetchHandleMessage::FetchHandleMessage(int32_t uid, ::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest) 
    : FetchHandleMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,id,source,dest);
}

rice::p2p::past::messaging::FetchHandleMessage::FetchHandleMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentHandleDeserializer* pchd)  /* throws(IOException) */
    : FetchHandleMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint,pchd);
}

constexpr int16_t rice::p2p::past::messaging::FetchHandleMessage::TYPE;

void rice::p2p::past::messaging::FetchHandleMessage::ctor(int32_t uid, ::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest)
{
    super::ctor(uid, source, dest);
    this->id = id;
}

rice::p2p::commonapi::Id* rice::p2p::past::messaging::FetchHandleMessage::getId()
{
    return id;
}

java::lang::String* rice::p2p::past::messaging::FetchHandleMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"[FetchHandleMessage for "_j)->append(static_cast< ::java::lang::Object* >(id))
        ->append(u"]"_j)->toString();
}

int16_t rice::p2p::past::messaging::FetchHandleMessage::getType()
{
    return TYPE;
}

void rice::p2p::past::messaging::FetchHandleMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    if(response != nullptr && dynamic_cast< ::rice::p2p::past::rawserialization::RawPastContentHandle* >(response) != nullptr) {
        super::serialize(buf, false);
        auto rpch = java_cast< ::rice::p2p::past::rawserialization::RawPastContentHandle* >(response);
        npc(buf)->writeShort(npc(rpch)->getType());
        npc(rpch)->serialize(buf);
    } else {
        super::serialize(buf, true);
    }
    npc(buf)->writeShort(npc(id)->getType());
    npc(id)->serialize(buf);
}

rice::p2p::past::messaging::FetchHandleMessage* rice::p2p::past::messaging::FetchHandleMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentHandleDeserializer* pchd) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new FetchHandleMessage(buf, endpoint, pchd);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::past::messaging::FetchHandleMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentHandleDeserializer* pchd) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    if(serType == S_SUB()) {
        auto type = npc(buf)->readShort();
        response = npc(pchd)->deserializePastContentHandle(buf, endpoint, type);
    }
    id = npc(endpoint)->readId(buf, npc(buf)->readShort());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::messaging::FetchHandleMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.messaging.FetchHandleMessage", 42);
    return c;
}

void rice::p2p::past::messaging::FetchHandleMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, bool javaSerialize)
{
    super::serialize(buf, javaSerialize);
}

java::lang::Class* rice::p2p::past::messaging::FetchHandleMessage::getClass0()
{
    return class_();
}

