// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousApp.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousApp_sendMessage_6.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
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

rice::pastry::socket::nat::rendezvous::RendezvousApp_sendMessage_6::RendezvousApp_sendMessage_6(RendezvousApp *RendezvousApp_this, RendezvousSocketNodeHandle* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options, ::rice::pastry::routing::RouteMessage* rm)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousApp_this(RendezvousApp_this)
    , i(i)
    , m(m)
    , deliverAckToMe(deliverAckToMe)
    , options(options)
    , rm(rm)
{
    clinit();
    ctor();
}

bool rice::pastry::socket::nat::rendezvous::RendezvousApp_sendMessage_6::cancel()
{
    if(npc(RendezvousApp_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(RendezvousApp_this->logger)->log(::java::lang::StringBuilder().append(u"sendMessage("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverAckToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u").cancel()"_j)->toString());

    return npc(rm)->cancel();
}

java::nio::ByteBuffer* rice::pastry::socket::nat::rendezvous::RendezvousApp_sendMessage_6::getMessage()
{
    return m;
}

rice::pastry::socket::nat::rendezvous::RendezvousSocketNodeHandle* rice::pastry::socket::nat::rendezvous::RendezvousApp_sendMessage_6::getIdentifier()
{
    return i;
}

java::util::Map* rice::pastry::socket::nat::rendezvous::RendezvousApp_sendMessage_6::getOptions()
{
    return options;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousApp_sendMessage_6::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousApp_sendMessage_6::getClass0()
{
    return class_();
}

