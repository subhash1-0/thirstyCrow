// Generated from /pastry-2.1/src/rice/p2p/past/messaging/LookupMessage.java
#include <rice/p2p/past/messaging/LookupMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/past/PastContent.hpp>
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

rice::p2p::past::messaging::LookupMessage::LookupMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::messaging::LookupMessage::LookupMessage(int32_t uid, ::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest) 
    : LookupMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,id,source,dest);
}

rice::p2p::past::messaging::LookupMessage::LookupMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd)  /* throws(IOException) */
    : LookupMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint,pcd);
}

void rice::p2p::past::messaging::LookupMessage::init()
{
    cached = false;
}

constexpr int16_t rice::p2p::past::messaging::LookupMessage::TYPE;

void rice::p2p::past::messaging::LookupMessage::ctor(int32_t uid, ::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest)
{
    super::ctor(uid, source, dest);
    init();
    this->id = id;
}

rice::p2p::commonapi::Id* rice::p2p::past::messaging::LookupMessage::getId()
{
    return id;
}

bool rice::p2p::past::messaging::LookupMessage::isCached()
{
    return cached;
}

void rice::p2p::past::messaging::LookupMessage::setCached()
{
    cached = true;
}

void rice::p2p::past::messaging::LookupMessage::addHop(::rice::p2p::commonapi::NodeHandle* handle)
{
    this->handle = handle;
}

rice::p2p::commonapi::NodeHandle* rice::p2p::past::messaging::LookupMessage::getPreviousNodeHandle()
{
    return handle;
}

java::lang::String* rice::p2p::past::messaging::LookupMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"[LookupMessage for "_j)->append(static_cast< ::java::lang::Object* >(id))
        ->append(u" data "_j)
        ->append(static_cast< ::java::lang::Object* >(response))
        ->append(u"]"_j)->toString();
}

int16_t rice::p2p::past::messaging::LookupMessage::getType()
{
    return TYPE;
}

void rice::p2p::past::messaging::LookupMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
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
    npc(buf)->writeBoolean(handle != nullptr);
    if(handle != nullptr)
        npc(handle)->serialize(buf);

    npc(buf)->writeShort(npc(id)->getType());
    npc(id)->serialize(buf);
    npc(buf)->writeBoolean(cached);
}

rice::p2p::past::messaging::LookupMessage* rice::p2p::past::messaging::LookupMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new LookupMessage(buf, endpoint, pcd);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::past::messaging::LookupMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    init();
    if(serType == S_SUB()) {
        auto contentType = npc(buf)->readShort();
        response = npc(pcd)->deserializePastContent(buf, endpoint, contentType);
    }
    if(npc(buf)->readBoolean())
        handle = npc(endpoint)->readNodeHandle(buf);

    try {
        id = npc(endpoint)->readId(buf, npc(buf)->readShort());
    } catch (::java::lang::IllegalArgumentException* iae) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(iae))->append(u" "_j)
            ->append(static_cast< ::java::lang::Object* >(this))
            ->append(u" serType:"_j)
            ->append(serType)
            ->append(u" UID:"_j)
            ->append(getUID())
            ->append(u" d:"_j)
            ->append(static_cast< ::java::lang::Object* >(dest))
            ->append(u" s:"_j)
            ->append(static_cast< ::java::lang::Object* >(source))->toString());
        throw iae;
    }
    cached = npc(buf)->readBoolean();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::messaging::LookupMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.messaging.LookupMessage", 37);
    return c;
}

void rice::p2p::past::messaging::LookupMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, bool javaSerialize)
{
    super::serialize(buf, javaSerialize);
}

java::lang::Class* rice::p2p::past::messaging::LookupMessage::getClass0()
{
    return class_();
}

