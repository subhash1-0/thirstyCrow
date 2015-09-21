// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousJoinProtocol.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousJoinProtocol.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/rendezvous/ContactDirectStrategy.hpp>
#include <org/mpisws/p2p/transport/rendezvous/PilotManager.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/util/OptionsFactory.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/join/JoinRequest.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousJoinProtocol_getJoinRequest_1.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousJoinProtocol_RCJPDeserializer.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousJoinRequest.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory.hpp>

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

rice::pastry::socket::nat::rendezvous::RendezvousJoinProtocol::RendezvousJoinProtocol(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::rendezvous::RendezvousJoinProtocol::RendezvousJoinProtocol(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* lh, ::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::ReadyStrategy* nextReadyStrategy, ::org::mpisws::p2p::transport::rendezvous::PilotManager* pilotManager) 
    : RendezvousJoinProtocol(*static_cast< ::default_init_tag* >(0))
{
    ctor(ln,lh,rt,ls,nextReadyStrategy,pilotManager);
}

void rice::pastry::socket::nat::rendezvous::RendezvousJoinProtocol::ctor(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* lh, ::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::ReadyStrategy* nextReadyStrategy, ::org::mpisws::p2p::transport::rendezvous::PilotManager* pilotManager)
{
    super::ctor(ln, lh, rt, ls, nextReadyStrategy, new RendezvousJoinProtocol_RCJPDeserializer(ln));
    this->pilotManager = pilotManager;
}

void rice::pastry::socket::nat::rendezvous::RendezvousJoinProtocol::getJoinRequest(::rice::pastry::NodeHandle* b, ::rice::Continuation* deliverJRToMe)
{
    auto const bootstrap = java_cast< RendezvousSocketNodeHandle* >(b);
    auto contactStrat = java_cast< ::org::mpisws::p2p::transport::rendezvous::ContactDirectStrategy* >(java_cast< ::java::lang::Object* >(npc(npc(thePastryNode)->getVars())->get(RendezvousSocketPastryNodeFactory::RENDEZVOUS_CONTACT_DIRECT_STRATEGY())));
    if((npc((java_cast< RendezvousSocketNodeHandle* >(npc(thePastryNode)->getLocalHandle())))->canContactDirect()) || (!npc(bootstrap)->canContactDirect() && npc(contactStrat)->canContactDirect(bootstrap))) {
        super::getJoinRequest(bootstrap, deliverJRToMe);
        return;
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"opening pilot to "_j)->append(static_cast< ::java::lang::Object* >(bootstrap))->toString());

    npc(pilotManager)->openPilot(java_cast< RendezvousSocketNodeHandle* >(bootstrap), new RendezvousJoinProtocol_getJoinRequest_1(this, deliverJRToMe, bootstrap));
}

java::util::Map* rice::pastry::socket::nat::rendezvous::RendezvousJoinProtocol::getOptions(::rice::pastry::join::JoinRequest* jr, ::java::util::Map* existing)
{
    if(npc(jr)->accepted()) {
        if(dynamic_cast< RendezvousJoinRequest* >(jr) != nullptr) {
            auto rjr = java_cast< RendezvousJoinRequest* >(jr);
            return ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(existing, ::org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::OPTION_USE_PILOT(), npc(rjr)->getPilot());
        }
    }
    return existing;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousJoinProtocol::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.rendezvous.RendezvousJoinProtocol", 56);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousJoinProtocol::getClass0()
{
    return class_();
}

