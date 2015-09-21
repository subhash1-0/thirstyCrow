// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousApp.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousApp_openChannel_4.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Map.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousApp.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::nat::rendezvous::RendezvousApp_openChannel_4::RendezvousApp_openChannel_4(RendezvousApp *RendezvousApp_this, RendezvousSocketNodeHandle* target, RendezvousSocketNodeHandle* rendezvous, RendezvousSocketNodeHandle* source, int32_t uid, ::rice::Continuation* deliverAckToMe, ::java::util::Map* options)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousApp_this(RendezvousApp_this)
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

void rice::pastry::socket::nat::rendezvous::RendezvousApp_openChannel_4::sendSuccess(::rice::pastry::routing::RouteMessage* message, ::rice::pastry::NodeHandle* nextHop)
{
    if(npc(RendezvousApp_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
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
            ->append(u").sendSuccess():"_j)
            ->append(static_cast< ::java::lang::Object* >(nextHop))->toString());

    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->receiveResult(::java::lang::Integer::valueOf(uid));

}

void rice::pastry::socket::nat::rendezvous::RendezvousApp_openChannel_4::sendFailed(::rice::pastry::routing::RouteMessage* message, ::java::lang::Exception* e)
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
            ->append(u").sendFailed("_j)
            ->append(static_cast< ::java::lang::Object* >(e))
            ->append(u")"_j)->toString());

    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->receiveException(e);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousApp_openChannel_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousApp_openChannel_4::getClass0()
{
    return class_();
}

