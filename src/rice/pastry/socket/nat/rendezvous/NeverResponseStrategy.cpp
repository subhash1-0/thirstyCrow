// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/NeverResponseStrategy.java
#include <rice/pastry/socket/nat/rendezvous/NeverResponseStrategy.hpp>

rice::pastry::socket::nat::rendezvous::NeverResponseStrategy::NeverResponseStrategy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::rendezvous::NeverResponseStrategy::NeverResponseStrategy()
    : NeverResponseStrategy(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::pastry::socket::nat::rendezvous::NeverResponseStrategy::messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* msg, ::java::util::Map* options)
{
}

void rice::pastry::socket::nat::rendezvous::NeverResponseStrategy::messageSent(::java::lang::Object* i, ::java::nio::ByteBuffer* msg, ::java::util::Map* options)
{
}

bool rice::pastry::socket::nat::rendezvous::NeverResponseStrategy::sendDirect(::java::lang::Object* i, ::java::nio::ByteBuffer* msg, ::java::util::Map* options)
{
    return false;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::NeverResponseStrategy::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.rendezvous.NeverResponseStrategy", 55);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::NeverResponseStrategy::getClass0()
{
    return class_();
}

