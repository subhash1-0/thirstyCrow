// Generated from /pastry-2.1/src/rice/pastry/socket/nat/CantFindFirewallException.java
#include <rice/pastry/socket/nat/CantFindFirewallException.hpp>

rice::pastry::socket::nat::CantFindFirewallException::CantFindFirewallException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::CantFindFirewallException::CantFindFirewallException(::java::lang::String* msg) 
    : CantFindFirewallException(*static_cast< ::default_init_tag* >(0))
{
    ctor(msg);
}

void rice::pastry::socket::nat::CantFindFirewallException::ctor(::java::lang::String* msg)
{
    super::ctor(msg);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::CantFindFirewallException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.CantFindFirewallException", 48);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::CantFindFirewallException::getClass0()
{
    return class_();
}

