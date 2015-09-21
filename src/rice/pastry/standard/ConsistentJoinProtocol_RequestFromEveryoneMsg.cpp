// Generated from /pastry-2.1/src/rice/pastry/standard/ConsistentJoinProtocol.java
#include <rice/pastry/standard/ConsistentJoinProtocol_RequestFromEveryoneMsg.hpp>

#include <rice/pastry/standard/ConsistentJoinProtocol.hpp>

rice::pastry::standard::ConsistentJoinProtocol_RequestFromEveryoneMsg::ConsistentJoinProtocol_RequestFromEveryoneMsg(ConsistentJoinProtocol *ConsistentJoinProtocol_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , ConsistentJoinProtocol_this(ConsistentJoinProtocol_this)
{
    clinit();
}

rice::pastry::standard::ConsistentJoinProtocol_RequestFromEveryoneMsg::ConsistentJoinProtocol_RequestFromEveryoneMsg(ConsistentJoinProtocol *ConsistentJoinProtocol_this, int32_t address) 
    : ConsistentJoinProtocol_RequestFromEveryoneMsg(ConsistentJoinProtocol_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(address);
}

void rice::pastry::standard::ConsistentJoinProtocol_RequestFromEveryoneMsg::ctor(int32_t address)
{
    super::ctor(address);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::ConsistentJoinProtocol_RequestFromEveryoneMsg::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.ConsistentJoinProtocol.RequestFromEveryoneMsg", 66);
    return c;
}

java::lang::Class* rice::pastry::standard::ConsistentJoinProtocol_RequestFromEveryoneMsg::getClass0()
{
    return class_();
}

