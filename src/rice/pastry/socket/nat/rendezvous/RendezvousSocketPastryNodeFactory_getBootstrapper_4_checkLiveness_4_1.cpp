// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory_getBootstrapper_4_checkLiveness_4_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>
#include <org/mpisws/p2p/transport/rendezvous/PilotManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory_getBootstrapper_4.hpp>
#include <Array.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getBootstrapper_4_checkLiveness_4_1::RendezvousSocketPastryNodeFactory_getBootstrapper_4_checkLiveness_4_1(RendezvousSocketPastryNodeFactory_getBootstrapper_4 *RendezvousSocketPastryNodeFactory_getBootstrapper_4_this, ::java::util::ArrayList* closeMeWhenReady, ::boolArray* booted, ::org::mpisws::p2p::transport::rendezvous::PilotManager* manager, ::rice::pastry::socket::SocketNodeHandle* h)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousSocketPastryNodeFactory_getBootstrapper_4_this(RendezvousSocketPastryNodeFactory_getBootstrapper_4_this)
    , closeMeWhenReady(closeMeWhenReady)
    , booted(booted)
    , manager(manager)
    , h(h)
{
    clinit();
    ctor();
}

void rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getBootstrapper_4_checkLiveness_4_1::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* result)
{
    auto close = false;
    {
        synchronized synchronized_0(closeMeWhenReady);
        {
            if((*booted)[int32_t(0)]) {
                close = true;
            } else {
                npc(closeMeWhenReady)->add(static_cast< ::java::lang::Object* >(java_cast< RendezvousSocketNodeHandle* >(npc(result)->getIdentifier())));
            }
        }
    }
    if(close) {
        npc(RendezvousSocketPastryNodeFactory_getBootstrapper_4_this->logger)->log(u"closing pilot"_j);
        npc(manager)->closePilot(java_cast< RendezvousSocketNodeHandle* >(npc(result)->getIdentifier()));
        return;
    }
    npc(npc(RendezvousSocketPastryNodeFactory_getBootstrapper_4_this->pn)->getLivenessProvider())->checkLiveness(h, nullptr);
}

void rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getBootstrapper_4_checkLiveness_4_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::org::mpisws::p2p::transport::SocketRequestHandle* >(result));
}

void rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getBootstrapper_4_checkLiveness_4_1::receiveException(::java::lang::Exception* exception)
{
    npc(RendezvousSocketPastryNodeFactory_getBootstrapper_4_this->logger)->logException(::java::lang::StringBuilder().append(u"In Rendezvous Bootstrapper.checkLiveness("_j)->append(static_cast< ::java::lang::Object* >(h))
        ->append(u")"_j)->toString(), exception);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getBootstrapper_4_checkLiveness_4_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getBootstrapper_4_checkLiveness_4_1::getClass0()
{
    return class_();
}

