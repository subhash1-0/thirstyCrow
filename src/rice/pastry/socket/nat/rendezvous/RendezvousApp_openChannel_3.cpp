// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousApp.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousApp_openChannel_3.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Map.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousApp.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::nat::rendezvous::RendezvousApp_openChannel_3::RendezvousApp_openChannel_3(RendezvousApp *RendezvousApp_this, RendezvousSocketNodeHandle* target, RendezvousSocketNodeHandle* rendezvous, RendezvousSocketNodeHandle* source, int32_t uid, ::rice::Continuation* deliverAckToMe, ::java::util::Map* options, ::rice::pastry::routing::RouteMessage* rm)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousApp_this(RendezvousApp_this)
    , target(target)
    , rendezvous(rendezvous)
    , source(source)
    , uid(uid)
    , deliverAckToMe(deliverAckToMe)
    , options(options)
    , rm(rm)
{
    clinit();
    ctor();
}

bool rice::pastry::socket::nat::rendezvous::RendezvousApp_openChannel_3::cancel()
{
    if(npc(RendezvousApp_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(RendezvousApp_this->logger)->log(::java::lang::StringBuilder().append(u"openChannel("_j)->append(static_cast< ::java::lang::Object* >(target))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(rendezvous))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(source))
            ->append(u","_j)
            ->append(uid)
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverAckToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u").cancel()"_j)->toString());

    return npc(rm)->cancel();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousApp_openChannel_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousApp_openChannel_3::getClass0()
{
    return class_();
}

