// Generated from /pastry-2.1/src/rice/tutorial/direct/MyMsg.java
#include <rice/tutorial/direct/MyMsg.hpp>

#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Message.hpp>

rice::tutorial::direct::MyMsg::MyMsg(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::direct::MyMsg::MyMsg(::rice::p2p::commonapi::Id* from, ::rice::p2p::commonapi::Id* to) 
    : MyMsg(*static_cast< ::default_init_tag* >(0))
{
    ctor(from,to);
}

void rice::tutorial::direct::MyMsg::ctor(::rice::p2p::commonapi::Id* from, ::rice::p2p::commonapi::Id* to)
{
    super::ctor();
    this->from = from;
    this->to = to;
}

java::lang::String* rice::tutorial::direct::MyMsg::toString()
{
    return ::java::lang::StringBuilder().append(u"MyMsg from "_j)->append(static_cast< ::java::lang::Object* >(from))
        ->append(u" to "_j)
        ->append(static_cast< ::java::lang::Object* >(to))->toString();
}

int32_t rice::tutorial::direct::MyMsg::getPriority()
{
    return ::rice::p2p::commonapi::Message::LOW_PRIORITY;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::direct::MyMsg::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.direct.MyMsg", 26);
    return c;
}

java::lang::Class* rice::tutorial::direct::MyMsg::getClass0()
{
    return class_();
}

