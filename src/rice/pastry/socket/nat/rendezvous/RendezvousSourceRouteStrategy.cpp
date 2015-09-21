// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousSourceRouteStrategy.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousSourceRouteStrategy.hpp>

rice::pastry::socket::nat::rendezvous::RendezvousSourceRouteStrategy::RendezvousSourceRouteStrategy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::rendezvous::RendezvousSourceRouteStrategy::RendezvousSourceRouteStrategy()
    : RendezvousSourceRouteStrategy(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::util::Collection* rice::pastry::socket::nat::rendezvous::RendezvousSourceRouteStrategy::getSourceRoutes(::java::lang::Object* destination)
{
    return nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousSourceRouteStrategy::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.rendezvous.RendezvousSourceRouteStrategy", 63);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousSourceRouteStrategy::getClass0()
{
    return class_();
}

