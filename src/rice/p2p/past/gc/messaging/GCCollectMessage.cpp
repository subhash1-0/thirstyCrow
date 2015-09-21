// Generated from /pastry-2.1/src/rice/p2p/past/gc/messaging/GCCollectMessage.java
#include <rice/p2p/past/gc/messaging/GCCollectMessage.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/past/PastException.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::gc::messaging::GCCollectMessage::GCCollectMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::gc::messaging::GCCollectMessage::GCCollectMessage(int32_t id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest) 
    : GCCollectMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(id,source,dest);
}

constexpr int16_t rice::p2p::past::gc::messaging::GCCollectMessage::TYPE;

void rice::p2p::past::gc::messaging::GCCollectMessage::ctor(int32_t id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest)
{
    super::ctor(id, source, dest);
}

void rice::p2p::past::gc::messaging::GCCollectMessage::returnResponse(::rice::Continuation* c, ::rice::environment::Environment* env, ::java::lang::String* instance)
{
    npc(c)->receiveException(new ::rice::p2p::past::PastException(u"Should not be called!"_j));
}

java::lang::String* rice::p2p::past::gc::messaging::GCCollectMessage::toString()
{
    return u"[GCCollectMessage]"_j;
}

int16_t rice::p2p::past::gc::messaging::GCCollectMessage::getType()
{
    return TYPE;
}

void rice::p2p::past::gc::messaging::GCCollectMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"serialize() not supported in MessageLostMessage"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::messaging::GCCollectMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.gc.messaging.GCCollectMessage", 43);
    return c;
}

java::lang::Class* rice::p2p::past::gc::messaging::GCCollectMessage::getClass0()
{
    return class_();
}

