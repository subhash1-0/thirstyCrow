// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/LeafSetPilotStrategy.java
#include <rice/pastry/socket/nat/rendezvous/LeafSetPilotStrategy.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/rendezvous/PilotManager.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousContact.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>

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

rice::pastry::socket::nat::rendezvous::LeafSetPilotStrategy::LeafSetPilotStrategy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::rendezvous::LeafSetPilotStrategy::LeafSetPilotStrategy(::rice::pastry::leafset::LeafSet* leafSet, ::org::mpisws::p2p::transport::rendezvous::PilotManager* manager, ::rice::environment::Environment* env) 
    : LeafSetPilotStrategy(*static_cast< ::default_init_tag* >(0))
{
    ctor(leafSet,manager,env);
}

void rice::pastry::socket::nat::rendezvous::LeafSetPilotStrategy::ctor(::rice::pastry::leafset::LeafSet* leafSet, ::org::mpisws::p2p::transport::rendezvous::PilotManager* manager, ::rice::environment::Environment* env)
{
    super::ctor();
    this->leafSet = leafSet;
    this->manager = manager;
    npc(java_cast< ::org::mpisws::p2p::transport::rendezvous::PilotManager* >(this->manager))->addOutgoingPilotListener(this);
    this->logger = npc(npc(env)->getLogManager())->getLogger(LeafSetPilotStrategy::class_(), nullptr);
    npc(leafSet)->addNodeSetListener(this);
}

void rice::pastry::socket::nat::rendezvous::LeafSetPilotStrategy::nodeSetUpdate(::rice::pastry::NodeSetEventSource* nodeSetEventSource, ::rice::pastry::NodeHandle* handle, bool added)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"nodeSetUpdate("_j)->append(static_cast< ::java::lang::Object* >(handle))
            ->append(u")"_j)->toString());

    auto nh = java_cast< ::org::mpisws::p2p::transport::rendezvous::RendezvousContact* >(handle);
    if(npc(nh)->canContactDirect()) {
        if(added) {
            npc(manager)->openPilot(nh, nullptr);
        } else {
            npc(manager)->closePilot(nh);
        }
    }
}

void rice::pastry::socket::nat::rendezvous::LeafSetPilotStrategy::pilotOpening(::org::mpisws::p2p::transport::rendezvous::RendezvousContact* i)
{
}

void rice::pastry::socket::nat::rendezvous::LeafSetPilotStrategy::pilotOpening(::java::lang::Object* i)
{ 
    pilotOpening(dynamic_cast< ::org::mpisws::p2p::transport::rendezvous::RendezvousContact* >(i));
}

void rice::pastry::socket::nat::rendezvous::LeafSetPilotStrategy::pilotClosed(::org::mpisws::p2p::transport::rendezvous::RendezvousContact* i)
{
    if(npc(leafSet)->contains(java_cast< ::rice::pastry::NodeHandle* >(i))) {
        npc(manager)->openPilot(i, nullptr);
    }
}

void rice::pastry::socket::nat::rendezvous::LeafSetPilotStrategy::pilotClosed(::java::lang::Object* i)
{ 
    pilotClosed(dynamic_cast< ::org::mpisws::p2p::transport::rendezvous::RendezvousContact* >(i));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::LeafSetPilotStrategy::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.rendezvous.LeafSetPilotStrategy", 54);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::LeafSetPilotStrategy::getClass0()
{
    return class_();
}

