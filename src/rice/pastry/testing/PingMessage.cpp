// Generated from /pastry-2.1/src/rice/pastry/testing/PingClient.java
#include <rice/pastry/testing/PingMessage.hpp>

#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/pastry/Id.hpp>

rice::pastry::testing::PingMessage::PingMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::PingMessage::PingMessage(int32_t pingAddress, ::rice::pastry::Id* src, ::rice::pastry::Id* tgt) 
    : PingMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(pingAddress,src,tgt);
}

void rice::pastry::testing::PingMessage::ctor(int32_t pingAddress, ::rice::pastry::Id* src, ::rice::pastry::Id* tgt)
{
    super::ctor(pingAddress);
    source = src;
    target = tgt;
}

java::lang::String* rice::pastry::testing::PingMessage::toString()
{
    auto s = u""_j;
    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u"ping from "_j)->append(static_cast< ::java::lang::Object* >(source))
        ->append(u" to "_j)
        ->append(static_cast< ::java::lang::Object* >(target))->toString())->toString();
    return s;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::PingMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.PingMessage", 31);
    return c;
}

java::lang::Class* rice::pastry::testing::PingMessage::getClass0()
{
    return class_();
}

