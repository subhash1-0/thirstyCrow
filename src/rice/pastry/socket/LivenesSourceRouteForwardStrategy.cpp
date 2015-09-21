// Generated from /pastry-2.1/src/rice/pastry/socket/LivenesSourceRouteForwardStrategy.java
#include <rice/pastry/socket/LivenesSourceRouteForwardStrategy.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteFactory.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::LivenesSourceRouteForwardStrategy::LivenesSourceRouteForwardStrategy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::LivenesSourceRouteForwardStrategy::LivenesSourceRouteForwardStrategy(::org::mpisws::p2p::transport::sourceroute::SourceRouteFactory* factory, ::rice::environment::Environment* env) 
    : LivenesSourceRouteForwardStrategy(*static_cast< ::default_init_tag* >(0))
{
    ctor(factory,env);
}

void rice::pastry::socket::LivenesSourceRouteForwardStrategy::ctor(::org::mpisws::p2p::transport::sourceroute::SourceRouteFactory* factory, ::rice::environment::Environment* env)
{
    super::ctor();
    this->factory = factory;
    this->logger = npc(npc(env)->getLogManager())->getLogger(LivenesSourceRouteForwardStrategy::class_(), nullptr);
}

void rice::pastry::socket::LivenesSourceRouteForwardStrategy::setLivenessProvider(::org::mpisws::p2p::transport::liveness::LivenessProvider* liveness)
{
    this->liveness = liveness;
}

bool rice::pastry::socket::LivenesSourceRouteForwardStrategy::forward(::java::lang::Object* nextHop, ::org::mpisws::p2p::transport::sourceroute::SourceRoute* sr, bool socket, ::java::util::Map* options)
{
    if(!socket)
        return true;

    auto i = npc(factory)->getSourceRoute(static_cast< ::java::lang::Object* >(nextHop));
    auto ret = (npc(liveness)->getLiveness(i, options) < ::org::mpisws::p2p::transport::liveness::LivenessProvider::LIVENESS_DEAD);
    if(!ret)
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Not forwarding socket to "_j)->append(static_cast< ::java::lang::Object* >(nextHop))
                ->append(u" sr:"_j)
                ->append(static_cast< ::java::lang::Object* >(sr))
                ->append(u" because I believe it is dead."_j)->toString());


    return ret;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::LivenesSourceRouteForwardStrategy::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.LivenesSourceRouteForwardStrategy", 52);
    return c;
}

java::lang::Class* rice::pastry::socket::LivenesSourceRouteForwardStrategy::getClass0()
{
    return class_();
}

