// Generated from /pastry-2.1/src/rice/pastry/testing/PingMessageNew.java
#include <rice/pastry/testing/PingMessageNew.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::testing::PingMessageNew::PingMessageNew(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::PingMessageNew::PingMessageNew(int32_t pingAddress, ::rice::pastry::NodeHandle* src, ::rice::pastry::Id* tgt) 
    : PingMessageNew(*static_cast< ::default_init_tag* >(0))
{
    ctor(pingAddress,src,tgt);
}

void rice::pastry::testing::PingMessageNew::init()
{
    nHops = int32_t(0);
    fDistance = int32_t(0);
}

void rice::pastry::testing::PingMessageNew::ctor(int32_t pingAddress, ::rice::pastry::NodeHandle* src, ::rice::pastry::Id* tgt)
{
    super::ctor(pingAddress);
    init();
    setSender(src);
    target = tgt;
}

java::lang::String* rice::pastry::testing::PingMessageNew::toString()
{
    auto s = u""_j;
    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u"ping from "_j)->append(static_cast< ::java::lang::Object* >(npc(getSender())->getNodeId()))
        ->append(u" to "_j)
        ->append(static_cast< ::java::lang::Object* >(target))->toString())->toString();
    return s;
}

void rice::pastry::testing::PingMessageNew::incrHops()
{
    nHops++;
}

void rice::pastry::testing::PingMessageNew::incrDistance(double dist)
{
    fDistance += dist;
}

int32_t rice::pastry::testing::PingMessageNew::getHops()
{
    return nHops;
}

double rice::pastry::testing::PingMessageNew::getDistance()
{
    return fDistance;
}

rice::pastry::Id* rice::pastry::testing::PingMessageNew::getSource()
{
    return npc(getSender())->getNodeId();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::PingMessageNew::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.PingMessageNew", 34);
    return c;
}

java::lang::Class* rice::pastry::testing::PingMessageNew::getClass0()
{
    return class_();
}

