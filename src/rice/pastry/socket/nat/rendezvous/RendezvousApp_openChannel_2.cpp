// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousApp.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousApp_openChannel_2.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/util/AttachableCancellable.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousApp.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::nat::rendezvous::RendezvousApp_openChannel_2::RendezvousApp_openChannel_2(RendezvousApp *RendezvousApp_this, ::rice::p2p::util::AttachableCancellable* ret, RendezvousSocketNodeHandle* target, RendezvousSocketNodeHandle* rendezvous, RendezvousSocketNodeHandle* source, int32_t uid, ::rice::Continuation* deliverAckToMe, ::java::util::Map* options)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousApp_this(RendezvousApp_this)
    , ret(ret)
    , target(target)
    , rendezvous(rendezvous)
    , source(source)
    , uid(uid)
    , deliverAckToMe(deliverAckToMe)
    , options(options)
{
    clinit();
    ctor();
}

void rice::pastry::socket::nat::rendezvous::RendezvousApp_openChannel_2::run()
{
    npc(ret)->attach(RendezvousApp_this->openChannel(target, rendezvous, source, uid, deliverAckToMe, options));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousApp_openChannel_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousApp_openChannel_2::getClass0()
{
    return class_();
}

