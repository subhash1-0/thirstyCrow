// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/manager/simple/SimpleSourceRouteStrategy.java
#include <org/mpisws/p2p/transport/sourceroute/manager/simple/SimpleSourceRouteStrategy.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteFactory.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/simple/NextHopStrategy.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/util/TimerWeakHashMap.hpp>
#include <rice/selector/SelectorManager.hpp>

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

org::mpisws::p2p::transport::sourceroute::manager::simple::SimpleSourceRouteStrategy::SimpleSourceRouteStrategy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::sourceroute::manager::simple::SimpleSourceRouteStrategy::SimpleSourceRouteStrategy(::java::lang::Object* localAddress, ::org::mpisws::p2p::transport::sourceroute::SourceRouteFactory* srFactory, NextHopStrategy* strategy, ::rice::environment::Environment* env) 
    : SimpleSourceRouteStrategy(*static_cast< ::default_init_tag* >(0))
{
    ctor(localAddress,srFactory,strategy,env);
}

void org::mpisws::p2p::transport::sourceroute::manager::simple::SimpleSourceRouteStrategy::ctor(::java::lang::Object* localAddress, ::org::mpisws::p2p::transport::sourceroute::SourceRouteFactory* srFactory, NextHopStrategy* strategy, ::rice::environment::Environment* env)
{
    super::ctor();
    this->localAddress = localAddress;
    this->srFactory = srFactory;
    this->strategy = strategy;
    this->environment = env;
    this->logger = npc(npc(environment)->getLogManager())->getLogger(SimpleSourceRouteStrategy::class_(), nullptr);
    routes = new ::rice::p2p::util::TimerWeakHashMap(npc(environment)->getSelectorManager(), int32_t(300000));
}

java::util::Collection* org::mpisws::p2p::transport::sourceroute::manager::simple::SimpleSourceRouteStrategy::getSourceRoutes(::java::lang::Object* destination)
{
    auto nextHops = npc(strategy)->getNextHops(destination);
    ::java::util::List* ret = new ::java::util::ArrayList(npc(nextHops)->size());
    for (auto _i = npc(nextHops)->iterator(); _i->hasNext(); ) {
        ::java::lang::Object* intermediate = java_cast< ::java::lang::Object* >(_i->next());
        {
            if(!npc(intermediate)->equals(destination)) {
                ::java::util::List* hopList = new ::java::util::ArrayList(int32_t(3));
                npc(hopList)->add(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(localAddress)));
                npc(hopList)->add(static_cast< ::java::lang::Object* >(intermediate));
                npc(hopList)->add(static_cast< ::java::lang::Object* >(destination));
                auto route = npc(srFactory)->getSourceRoute(static_cast< ::java::util::List* >(hopList));
                npc(ret)->add(static_cast< ::java::lang::Object* >(route));
            }
        }
    }
    return ret;
}

org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::transport::sourceroute::manager::simple::SimpleSourceRouteStrategy::getRoute(::java::lang::Object* intermediate, ::java::lang::Object* dest)
{
    auto route = java_cast< ::org::mpisws::p2p::transport::sourceroute::SourceRoute* >(npc(routes)->get(static_cast< ::java::lang::Object* >(dest)));
    if(route == nullptr) {
        route = npc(srFactory)->getSourceRoute(java_cast< ::java::lang::Object* >(localAddress), dest);
        npc(routes)->put(static_cast< ::java::lang::Object* >(dest), static_cast< ::java::lang::Object* >(route));
    }
    return route;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::sourceroute::manager::simple::SimpleSourceRouteStrategy::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.sourceroute.manager.simple.SimpleSourceRouteStrategy", 77);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::sourceroute::manager::simple::SimpleSourceRouteStrategy::getClass0()
{
    return class_();
}

