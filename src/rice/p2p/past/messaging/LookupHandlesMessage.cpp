// Generated from /pastry-2.1/src/rice/p2p/past/messaging/LookupHandlesMessage.java
#include <rice/p2p/past/messaging/LookupHandlesMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>

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

rice::p2p::past::messaging::LookupHandlesMessage::LookupHandlesMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::messaging::LookupHandlesMessage::LookupHandlesMessage(int32_t uid, ::rice::p2p::commonapi::Id* id, int32_t max, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest) 
    : LookupHandlesMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,id,max,source,dest);
}

rice::p2p::past::messaging::LookupHandlesMessage::LookupHandlesMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : LookupHandlesMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::past::messaging::LookupHandlesMessage::TYPE;

void rice::p2p::past::messaging::LookupHandlesMessage::ctor(int32_t uid, ::rice::p2p::commonapi::Id* id, int32_t max, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest)
{
    super::ctor(uid, source, dest);
    this->id = id;
    this->max = max;
}

rice::p2p::commonapi::Id* rice::p2p::past::messaging::LookupHandlesMessage::getId()
{
    return id;
}

int32_t rice::p2p::past::messaging::LookupHandlesMessage::getMax()
{
    return max;
}

java::lang::String* rice::p2p::past::messaging::LookupHandlesMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"[LookupHandlesMessage (response "_j)->append(isResponse())
        ->append(u" "_j)
        ->append(static_cast< ::java::lang::Object* >(response))
        ->append(u") for "_j)
        ->append(static_cast< ::java::lang::Object* >(id))
        ->append(u" max "_j)
        ->append(max)
        ->append(u"]"_j)->toString();
}

int16_t rice::p2p::past::messaging::LookupHandlesMessage::getType()
{
    return TYPE;
}

void rice::p2p::past::messaging::LookupHandlesMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    serializeHelper(buf);
}

void rice::p2p::past::messaging::LookupHandlesMessage::serializeHelper(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    if(response != nullptr && dynamic_cast< ::rice::p2p::commonapi::NodeHandleSet* >(response) != nullptr) {
        super::serialize(buf, false);
        auto set = java_cast< ::rice::p2p::commonapi::NodeHandleSet* >(response);
        npc(buf)->writeShort(npc(set)->getType());
        npc(set)->serialize(buf);
    } else {
        super::serialize(buf, true);
    }
    npc(buf)->writeInt(max);
    npc(buf)->writeShort(npc(id)->getType());
    npc(id)->serialize(buf);
}

rice::p2p::past::messaging::LookupHandlesMessage* rice::p2p::past::messaging::LookupHandlesMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new LookupHandlesMessage(buf, endpoint);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::past::messaging::LookupHandlesMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    if(serType == S_SUB()) {
        auto type = npc(buf)->readShort();
        response = npc(endpoint)->readNodeHandleSet(buf, type);
    }
    max = npc(buf)->readInt();
    id = npc(endpoint)->readId(buf, npc(buf)->readShort());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::messaging::LookupHandlesMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.messaging.LookupHandlesMessage", 44);
    return c;
}

void rice::p2p::past::messaging::LookupHandlesMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, bool javaSerialize)
{
    super::serialize(buf, javaSerialize);
}

java::lang::Class* rice::p2p::past::messaging::LookupHandlesMessage::getClass0()
{
    return class_();
}

