// Generated from /pastry-2.1/src/rice/tutorial/rawserialization/MyMsg.java
#include <rice/tutorial/rawserialization/MyMsg.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::rawserialization::MyMsg::MyMsg(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::rawserialization::MyMsg::MyMsg(::rice::p2p::commonapi::Id* from, ::rice::p2p::commonapi::Id* to) 
    : MyMsg(*static_cast< ::default_init_tag* >(0))
{
    ctor(from,to);
}

rice::tutorial::rawserialization::MyMsg::MyMsg(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : MyMsg(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::tutorial::rawserialization::MyMsg::TYPE;

void rice::tutorial::rawserialization::MyMsg::ctor(::rice::p2p::commonapi::Id* from, ::rice::p2p::commonapi::Id* to)
{
    super::ctor();
    this->from = from;
    this->to = to;
}

java::lang::String* rice::tutorial::rawserialization::MyMsg::toString()
{
    return ::java::lang::StringBuilder().append(u"MyMsg from "_j)->append(static_cast< ::java::lang::Object* >(from))
        ->append(u" to "_j)
        ->append(static_cast< ::java::lang::Object* >(to))->toString();
}

int32_t rice::tutorial::rawserialization::MyMsg::getPriority()
{
    return ::rice::p2p::commonapi::Message::LOW_PRIORITY;
}

int16_t rice::tutorial::rawserialization::MyMsg::getType()
{
    return TYPE;
}

void rice::tutorial::rawserialization::MyMsg::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor();
    from = npc(endpoint)->readId(buf, npc(buf)->readShort());
    to = npc(endpoint)->readId(buf, npc(buf)->readShort());
}

void rice::tutorial::rawserialization::MyMsg::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeShort(npc(from)->getType());
    npc(from)->serialize(buf);
    npc(buf)->writeShort(npc(to)->getType());
    npc(to)->serialize(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::rawserialization::MyMsg::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.rawserialization.MyMsg", 36);
    return c;
}

java::lang::Class* rice::tutorial::rawserialization::MyMsg::getClass0()
{
    return class_();
}

