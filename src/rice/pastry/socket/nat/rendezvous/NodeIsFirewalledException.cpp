// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/NodeIsFirewalledException.java
#include <rice/pastry/socket/nat/rendezvous/NodeIsFirewalledException.hpp>

#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/pastry/NodeHandle.hpp>

rice::pastry::socket::nat::rendezvous::NodeIsFirewalledException::NodeIsFirewalledException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::rendezvous::NodeIsFirewalledException::NodeIsFirewalledException(::rice::pastry::NodeHandle* handle) 
    : NodeIsFirewalledException(*static_cast< ::default_init_tag* >(0))
{
    ctor(handle);
}

void rice::pastry::socket::nat::rendezvous::NodeIsFirewalledException::ctor(::rice::pastry::NodeHandle* handle)
{
    super::ctor(::java::lang::StringBuilder().append(u"Node "_j)->append(static_cast< ::java::lang::Object* >(handle))
        ->append(u" is firewalled."_j)->toString());
    this->handle = handle;
}

rice::pastry::NodeHandle* rice::pastry::socket::nat::rendezvous::NodeIsFirewalledException::getHandle()
{
    return handle;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::NodeIsFirewalledException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.rendezvous.NodeIsFirewalledException", 59);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::NodeIsFirewalledException::getClass0()
{
    return class_();
}

