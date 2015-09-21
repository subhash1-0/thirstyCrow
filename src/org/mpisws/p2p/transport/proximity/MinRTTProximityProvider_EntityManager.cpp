// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/proximity/MinRTTProximityProvider.java
#include <org/mpisws/p2p/transport/proximity/MinRTTProximityProvider_EntityManager.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/liveness/Pinger.hpp>
#include <org/mpisws/p2p/transport/proximity/MinRTTProximityProvider.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityProvider.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>

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

org::mpisws::p2p::transport::proximity::MinRTTProximityProvider_EntityManager::MinRTTProximityProvider_EntityManager(MinRTTProximityProvider *MinRTTProximityProvider_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , MinRTTProximityProvider_this(MinRTTProximityProvider_this)
{
    clinit();
}

org::mpisws::p2p::transport::proximity::MinRTTProximityProvider_EntityManager::MinRTTProximityProvider_EntityManager(MinRTTProximityProvider *MinRTTProximityProvider_this, ::java::lang::Object* route) 
    : MinRTTProximityProvider_EntityManager(MinRTTProximityProvider_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(route);
}

void org::mpisws::p2p::transport::proximity::MinRTTProximityProvider_EntityManager::init()
{
    lastPingTime = ::java::lang::Integer::MIN_VALUE;
}

void org::mpisws::p2p::transport::proximity::MinRTTProximityProvider_EntityManager::ctor(::java::lang::Object* route)
{
    super::ctor();
    init();
    if(route == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"route is null"_j);

    this->identifier = route;
    proximity_ = ProximityProvider::DEFAULT_PROXIMITY;
}

void org::mpisws::p2p::transport::proximity::MinRTTProximityProvider_EntityManager::ping(::java::util::Map* options)
{
    auto now = npc(MinRTTProximityProvider_this->time)->currentTimeMillis();
    if((now - lastPingTime) < MinRTTProximityProvider_this->pingThrottle) {
        if(npc(MinRTTProximityProvider_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(MinRTTProximityProvider_this->logger)->log(::java::lang::StringBuilder().append(u"Dropping ping because pingThrottle."_j)->append((MinRTTProximityProvider_this->pingThrottle - (now - lastPingTime)))->toString());

        return;
    }
    lastPingTime = now;
    npc(MinRTTProximityProvider_this->tl)->ping(java_cast< ::java::lang::Object* >(identifier), options);
}

int32_t org::mpisws::p2p::transport::proximity::MinRTTProximityProvider_EntityManager::proximity()
{
    return proximity_;
}

void org::mpisws::p2p::transport::proximity::MinRTTProximityProvider_EntityManager::markProximity(int32_t proximity, ::java::util::Map* options)
{
    if(proximity < 0)
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"proximity must be >= 0, was:"_j)->append(proximity)->toString());

    if(npc(MinRTTProximityProvider_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(MinRTTProximityProvider_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".markProximity("_j)
            ->append(proximity)
            ->append(u")"_j)->toString());

    if(this->proximity_ > proximity) {
        if(npc(MinRTTProximityProvider_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(MinRTTProximityProvider_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" updating proximity to "_j)
                ->append(proximity)->toString());

        this->proximity_ = proximity;
        MinRTTProximityProvider_this->notifyProximityListeners(java_cast< ::java::lang::Object* >(identifier), proximity, options);
    }
}

java::lang::String* org::mpisws::p2p::transport::proximity::MinRTTProximityProvider_EntityManager::toString()
{
    return npc(java_cast< ::java::lang::Object* >(identifier))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::proximity::MinRTTProximityProvider_EntityManager::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.proximity.MinRTTProximityProvider.EntityManager", 72);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::proximity::MinRTTProximityProvider_EntityManager::getClass0()
{
    return class_();
}

