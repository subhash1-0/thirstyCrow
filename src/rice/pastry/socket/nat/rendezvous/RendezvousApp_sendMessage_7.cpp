// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousApp.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousApp_sendMessage_7.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
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

rice::pastry::socket::nat::rendezvous::RendezvousApp_sendMessage_7::RendezvousApp_sendMessage_7(RendezvousApp *RendezvousApp_this, RendezvousSocketNodeHandle* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options, ::org::mpisws::p2p::transport::MessageRequestHandle* ret)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousApp_this(RendezvousApp_this)
    , i(i)
    , m(m)
    , deliverAckToMe(deliverAckToMe)
    , options(options)
    , ret(ret)
{
    clinit();
    ctor();
}

void rice::pastry::socket::nat::rendezvous::RendezvousApp_sendMessage_7::sendSuccess(::rice::pastry::routing::RouteMessage* message, ::rice::pastry::NodeHandle* nextHop)
{
    if(npc(RendezvousApp_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(RendezvousApp_this->logger)->log(::java::lang::StringBuilder().append(u"sendMessage("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverAckToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u").sendSuccess():"_j)
            ->append(static_cast< ::java::lang::Object* >(nextHop))->toString());

    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->ack(ret);

}

void rice::pastry::socket::nat::rendezvous::RendezvousApp_sendMessage_7::sendFailed(::rice::pastry::routing::RouteMessage* message, ::java::lang::Exception* e)
{
    if(npc(RendezvousApp_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(RendezvousApp_this->logger)->log(::java::lang::StringBuilder().append(u"sendMessage("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverAckToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u").sendFailed("_j)
            ->append(static_cast< ::java::lang::Object* >(e))
            ->append(u")"_j)->toString());

    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->sendFailed(ret, e);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousApp_sendMessage_7::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousApp_sendMessage_7::getClass0()
{
    return class_();
}

