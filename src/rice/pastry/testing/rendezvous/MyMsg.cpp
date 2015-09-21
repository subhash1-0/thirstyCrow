// Generated from /pastry-2.1/src/rice/pastry/testing/rendezvous/MyMsg.java
#include <rice/pastry/testing/rendezvous/MyMsg.hpp>

#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Message.hpp>

rice::pastry::testing::rendezvous::MyMsg::MyMsg(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::rendezvous::MyMsg::MyMsg(::rice::p2p::commonapi::Id* from, ::rice::p2p::commonapi::Id* to) 
    : MyMsg(*static_cast< ::default_init_tag* >(0))
{
    ctor(from,to);
}

void rice::pastry::testing::rendezvous::MyMsg::ctor(::rice::p2p::commonapi::Id* from, ::rice::p2p::commonapi::Id* to)
{
    super::ctor();
    this->from = from;
    this->to = to;
}

java::lang::String* rice::pastry::testing::rendezvous::MyMsg::toString()
{
    return ::java::lang::StringBuilder().append(u"MyMsg from "_j)->append(static_cast< ::java::lang::Object* >(from))
        ->append(u" to "_j)
        ->append(static_cast< ::java::lang::Object* >(to))->toString();
}

int32_t rice::pastry::testing::rendezvous::MyMsg::getPriority()
{
    return ::rice::p2p::commonapi::Message::LOW_PRIORITY;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::rendezvous::MyMsg::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.rendezvous.MyMsg", 36);
    return c;
}

java::lang::Class* rice::pastry::testing::rendezvous::MyMsg::getClass0()
{
    return class_();
}

