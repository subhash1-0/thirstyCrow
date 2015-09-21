// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousRouterStrategy.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousRouterStrategy.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayer.hpp>
#include <org/mpisws/p2p/transport/util/OptionsFactory.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.hpp>

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

rice::pastry::socket::nat::rendezvous::RendezvousRouterStrategy::RendezvousRouterStrategy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::rendezvous::RendezvousRouterStrategy::RendezvousRouterStrategy(::org::mpisws::p2p::transport::priority::PriorityTransportLayer* priority, ::rice::environment::Environment* env) 
    : RendezvousRouterStrategy(*static_cast< ::default_init_tag* >(0))
{
    ctor(priority,env);
}

void rice::pastry::socket::nat::rendezvous::RendezvousRouterStrategy::ctor(::org::mpisws::p2p::transport::priority::PriorityTransportLayer* priority, ::rice::environment::Environment* env)
{
    super::ctor();
    this->priority = priority;
    this->environment = env;
    this->logger = npc(npc(env)->getLogManager())->getLogger(RendezvousRouterStrategy::class_(), nullptr);
}

rice::pastry::NodeHandle* rice::pastry::socket::nat::rendezvous::RendezvousRouterStrategy::pickNextHop(::rice::pastry::routing::RouteMessage* msg, ::java::util::Iterator* i)
{
    if(!npc(i)->hasNext())
        return nullptr;

    auto best = java_cast< ::rice::pastry::NodeHandle* >(npc(i)->next());
    auto bestRating = routingQuality(best);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Routing "_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u"(0) "_j)
            ->append(static_cast< ::java::lang::Object* >(best))
            ->append(u":"_j)
            ->append(bestRating)->toString());

    if(bestRating == 0)
        return best;

    auto ctr = int32_t(1);
    while (npc(i)->hasNext()) {
        auto next = java_cast< ::rice::pastry::NodeHandle* >(npc(i)->next());
        auto nextRating = routingQuality(next);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Routing "_j)->append(static_cast< ::java::lang::Object* >(msg))
                ->append(u"("_j)
                ->append((ctr++))
                ->append(u") "_j)
                ->append(static_cast< ::java::lang::Object* >(next))
                ->append(u":"_j)
                ->append(nextRating)->toString());

        if(nextRating == 0)
            return next;

        if(nextRating < bestRating) {
            best = next;
            bestRating = nextRating;
        }
    }
    if(bestRating > 3) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Can't find route for "_j)->append(static_cast< ::java::lang::Object* >(msg))->toString());

        return nullptr;
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Routing "_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u"returning "_j)
            ->append(static_cast< ::java::lang::Object* >(best))
            ->append(u":"_j)
            ->append(bestRating)->toString());

    return best;
}

int32_t rice::pastry::socket::nat::rendezvous::RendezvousRouterStrategy::routingQuality(::rice::pastry::NodeHandle* nh)
{
    auto rnh = java_cast< RendezvousSocketNodeHandle* >(nh);
    if(!npc(nh)->isAlive()) {
        return 10;
    }
    auto connectionStatus = npc(priority)->connectionStatus(npc(rnh)->eaddress);
    auto liveness = npc(nh)->getLiveness();
    auto contactDirect = npc(rnh)->canContactDirect();
    if(contactDirect) {
        auto ret = int32_t(2);
        if(liveness == ::rice::pastry::NodeHandle::LIVENESS_ALIVE)
            ret--;

        if(connectionStatus == ::org::mpisws::p2p::transport::priority::PriorityTransportLayer::STATUS_CONNECTED) {
            ret--;
        } else {
            npc(priority)->openPrimaryConnection(npc(rnh)->eaddress, getOptions(rnh));
        }
        return ret;
    }
    if(connectionStatus > ::org::mpisws::p2p::transport::priority::PriorityTransportLayer::STATUS_CONNECTING) {
        npc(priority)->openPrimaryConnection(npc(rnh)->eaddress, getOptions(rnh));
    }
    if(connectionStatus == ::org::mpisws::p2p::transport::priority::PriorityTransportLayer::STATUS_CONNECTED) {
        if(liveness == ::rice::pastry::NodeHandle::LIVENESS_ALIVE)
            return 0;

        return 1;
    }
    return 5;
}

java::util::Map* rice::pastry::socket::nat::rendezvous::RendezvousRouterStrategy::getOptions(::rice::pastry::NodeHandle* nh)
{
    return ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(nullptr, ::org::mpisws::p2p::transport::identity::IdentityImpl::NODE_HANDLE_FROM_INDEX(), nh);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousRouterStrategy::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.rendezvous.RendezvousRouterStrategy", 58);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousRouterStrategy::getClass0()
{
    return class_();
}

