// Generated from /pastry-2.1/src/rice/pastry/testing/RegrTestApp.java
#include <rice/pastry/testing/RTMessage.hpp>

#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>

rice::pastry::testing::RTMessage::RTMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::RTMessage::RTMessage(int32_t addr, ::rice::pastry::NodeHandle* src, ::rice::pastry::Id* tgt) 
    : RTMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(addr,src,tgt);
}

void rice::pastry::testing::RTMessage::ctor(int32_t addr, ::rice::pastry::NodeHandle* src, ::rice::pastry::Id* tgt)
{
    super::ctor(addr);
    sourceNode = src;
    target = tgt;
}

java::lang::String* rice::pastry::testing::RTMessage::toString()
{
    auto s = u""_j;
    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u"RTMsg from "_j)->append(static_cast< ::java::lang::Object* >(sourceNode))
        ->append(u" to "_j)
        ->append(static_cast< ::java::lang::Object* >(target))->toString())->toString();
    return s;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::RTMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.RTMessage", 29);
    return c;
}

java::lang::Class* rice::pastry::testing::RTMessage::getClass0()
{
    return class_();
}

