// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousJoinProtocol.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousJoinProtocol_getJoinRequest_1.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousJoinProtocol.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousJoinRequest.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::nat::rendezvous::RendezvousJoinProtocol_getJoinRequest_1::RendezvousJoinProtocol_getJoinRequest_1(RendezvousJoinProtocol *RendezvousJoinProtocol_this, ::rice::Continuation* deliverJRToMe, RendezvousSocketNodeHandle* bootstrap)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousJoinProtocol_this(RendezvousJoinProtocol_this)
    , deliverJRToMe(deliverJRToMe)
    , bootstrap(bootstrap)
{
    clinit();
    ctor();
}

void rice::pastry::socket::nat::rendezvous::RendezvousJoinProtocol_getJoinRequest_1::receiveException(::java::lang::Exception* exception)
{
    npc(deliverJRToMe)->receiveException(exception);
}

void rice::pastry::socket::nat::rendezvous::RendezvousJoinProtocol_getJoinRequest_1::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* result)
{
    auto jr = new RendezvousJoinRequest(RendezvousJoinProtocol_this->localHandle, npc(npc(RendezvousJoinProtocol_this->thePastryNode)->getRoutingTable())->baseBitLength(), npc(npc(npc(RendezvousJoinProtocol_this->thePastryNode)->getEnvironment())->getTimeSource())->currentTimeMillis(), static_cast< ::rice::pastry::NodeHandle* >(bootstrap));
    npc(deliverJRToMe)->receiveResult(jr);
}

void rice::pastry::socket::nat::rendezvous::RendezvousJoinProtocol_getJoinRequest_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::org::mpisws::p2p::transport::SocketRequestHandle* >(result));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousJoinProtocol_getJoinRequest_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousJoinProtocol_getJoinRequest_1::getClass0()
{
    return class_();
}

