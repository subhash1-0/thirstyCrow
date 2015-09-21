// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousLivenessProvider.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousLivenessProvider.hpp>

rice::pastry::socket::nat::rendezvous::RendezvousLivenessProvider::RendezvousLivenessProvider(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::rendezvous::RendezvousLivenessProvider::RendezvousLivenessProvider()
    : RendezvousLivenessProvider(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousLivenessProvider::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.rendezvous.RendezvousLivenessProvider", 60);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousLivenessProvider::getClass0()
{
    return class_();
}

