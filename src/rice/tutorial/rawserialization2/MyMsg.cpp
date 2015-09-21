// Generated from /pastry-2.1/src/rice/tutorial/rawserialization2/MyMsg.java
#include <rice/tutorial/rawserialization2/MyMsg.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/util/rawserialization/JavaSerializer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::rawserialization2::MyMsg::MyMsg(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::rawserialization2::MyMsg::MyMsg(::rice::p2p::commonapi::NodeHandle* from, ::rice::p2p::commonapi::Id* to) 
    : MyMsg(*static_cast< ::default_init_tag* >(0))
{
    ctor(from,to);
}

void rice::tutorial::rawserialization2::MyMsg::ctor(::rice::p2p::commonapi::NodeHandle* from, ::rice::p2p::commonapi::Id* to)
{
    super::ctor(int32_t(0), npc(from)->getId(), from, to);
    this->from = npc(from)->getId();
    this->to = to;
}

java::lang::String* rice::tutorial::rawserialization2::MyMsg::toString()
{
    return ::java::lang::StringBuilder().append(u"MyMsg from "_j)->append(static_cast< ::java::lang::Object* >(from))
        ->append(u" to "_j)
        ->append(static_cast< ::java::lang::Object* >(to))->toString();
}

int32_t rice::tutorial::rawserialization2::MyMsg::getPriority()
{
    return ::rice::p2p::commonapi::Message::LOW_PRIORITY;
}

void rice::tutorial::rawserialization2::MyMsg::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    ::rice::p2p::util::rawserialization::JavaSerializer::serialize(this, buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::rawserialization2::MyMsg::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.rawserialization2.MyMsg", 37);
    return c;
}

void rice::tutorial::rawserialization2::MyMsg::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, bool javaSerialize)
{
    super::serialize(buf, javaSerialize);
}

java::lang::Class* rice::tutorial::rawserialization2::MyMsg::getClass0()
{
    return class_();
}

