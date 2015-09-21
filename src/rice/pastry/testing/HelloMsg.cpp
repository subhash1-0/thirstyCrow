// Generated from /pastry-2.1/src/rice/pastry/testing/HelloMsg.java
#include <rice/pastry/testing/HelloMsg.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::testing::HelloMsg::HelloMsg(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::HelloMsg::HelloMsg(int32_t addr, ::rice::pastry::NodeHandle* src, ::rice::p2p::commonapi::Id* tgt, int32_t mid) 
    : HelloMsg(*static_cast< ::default_init_tag* >(0))
{
    ctor(addr,src,tgt,mid);
}

void rice::pastry::testing::HelloMsg::init()
{
    messageDirect = false;
}

void rice::pastry::testing::HelloMsg::ctor(int32_t addr, ::rice::pastry::NodeHandle* src, ::rice::p2p::commonapi::Id* tgt, int32_t mid)
{
    super::ctor(addr);
    init();
    target = tgt;
    msgid = mid;
    this->src = src;
}

java::lang::String* rice::pastry::testing::HelloMsg::toString()
{
    return ::java::lang::StringBuilder().append(u"Hello #"_j)->append(msgid)
        ->append(u" from "_j)
        ->append(static_cast< ::java::lang::Object* >(npc(src)->getId()))->toString();
}

java::lang::String* rice::pastry::testing::HelloMsg::getInfo()
{
    auto s = toString();
    if(messageDirect) {
        s = ::java::lang::StringBuilder(s).append(u" direct"_j)->toString();
    } else {
        s = ::java::lang::StringBuilder(s).append(u" routed"_j)->toString();
    }
    return s;
}

int32_t rice::pastry::testing::HelloMsg::getId()
{
    return msgid;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::HelloMsg::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.HelloMsg", 28);
    return c;
}

java::lang::Class* rice::pastry::testing::HelloMsg::getClass0()
{
    return class_();
}

