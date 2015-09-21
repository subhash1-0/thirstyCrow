// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.java
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_DeadChecker.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/ref/WeakReference.hpp>
#include <java/util/Map.hpp>
#include <java/util/Random.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_EntityManager.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/selector/Timer.hpp>

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
org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_DeadChecker::LivenessTransportLayerImpl_DeadChecker(LivenessTransportLayerImpl *LivenessTransportLayerImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , LivenessTransportLayerImpl_this(LivenessTransportLayerImpl_this)
{
    clinit();
}

org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_DeadChecker::LivenessTransportLayerImpl_DeadChecker(LivenessTransportLayerImpl *LivenessTransportLayerImpl_this, LivenessTransportLayerImpl_EntityManager* manager, int32_t numTries, int32_t initialDelay, ::java::util::Map* options) 
    : LivenessTransportLayerImpl_DeadChecker(LivenessTransportLayerImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(manager,numTries,initialDelay,options);
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_DeadChecker::init()
{
    tries = int32_t(1);
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_DeadChecker::ctor(LivenessTransportLayerImpl_EntityManager* manager, int32_t numTries, int32_t initialDelay, ::java::util::Map* options)
{
    super::ctor();
    init();
    if(npc(LivenessTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE) {
        npc(LivenessTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"DeadChecker@"_j)->append(::java::lang::System::identityHashCode(this))
            ->append(u" CHECKING DEATH OF PATH "_j)
            ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(npc(manager)->identifier)->get())))
            ->append(u" rto:"_j)
            ->append(initialDelay)
            ->append(u" options:"_j)
            ->append(static_cast< ::java::lang::Object* >(options))->toString());
    }
    this->manager = manager;
    this->numTries = numTries;
    this->options = options;
    this->initialDelay = initialDelay;
    this->startTime = npc(LivenessTransportLayerImpl_this->time)->currentTimeMillis();
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_DeadChecker::pingResponse(int64_t RTT, ::java::util::Map* options)
{
    if(!cancelled) {
        if(tries > 1) {
            auto delay = npc(LivenessTransportLayerImpl_this->time)->currentTimeMillis() - startTime;
            if(npc(LivenessTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(LivenessTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"DeadChecker.pingResponse("_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(npc(manager)->identifier)->get())))
                    ->append(u") tries="_j)
                    ->append(tries)
                    ->append(u" estimated="_j)
                    ->append(initialDelay)
                    ->append(u" totalDelay="_j)
                    ->append(delay)->toString());

        }
    }
    if(npc(LivenessTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(LivenessTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Terminated DeadChecker@"_j)->append(::java::lang::System::identityHashCode(this))
            ->append(u"("_j)
            ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(npc(manager)->identifier)->get())))
            ->append(u") due to ping."_j)->toString());

    cancel();
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_DeadChecker::run()
{
    if(LivenessTransportLayerImpl_this->destroyed)
        return;

    if(tries < numTries) {
        tries++;
        npc(manager)->markSuspected(options);
        auto temp = java_cast< ::java::lang::Object* >(npc(npc(manager)->identifier)->get());
        if(temp != nullptr) {
            if(npc(LivenessTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(LivenessTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"DeadChecker@"_j)->append(::java::lang::System::identityHashCode(this))
                    ->append(u"("_j)
                    ->append(static_cast< ::java::lang::Object* >(temp))
                    ->append(u") pinging "_j)
                    ->append(tries)
                    ->append(u" "_j)
                    ->append(static_cast< ::java::lang::Object* >(npc(manager)->getPending()))->toString());

            LivenessTransportLayerImpl_this->ping(temp, options);
        }
        auto absPD = static_cast< int32_t >((LivenessTransportLayerImpl_this->PING_DELAY * ::java::lang::Math::pow(2, tries - int32_t(1))));
        auto jitterAmt = static_cast< int32_t >(((static_cast< float >(absPD)) * LivenessTransportLayerImpl_this->PING_JITTER));
        auto scheduledTime = absPD - jitterAmt + npc(LivenessTransportLayerImpl_this->random)->nextInt(jitterAmt * int32_t(2));
        npc(LivenessTransportLayerImpl_this->timer)->schedule(this, scheduledTime);
    } else {
        if(npc(LivenessTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(LivenessTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"DeadChecker@"_j)->append(::java::lang::System::identityHashCode(this))
                ->append(u"("_j)
                ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(npc(manager)->identifier)->get())))
                ->append(u") expired - marking as dead."_j)->toString());

        npc(manager)->markDead(options);
    }
}

bool org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_DeadChecker::cancel()
{
    {
        synchronized synchronized_0(manager);
        {
            npc(manager)->setPending(nullptr);
        }
    }
    return super::cancel();
}

java::lang::String* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_DeadChecker::toString()
{
    return ::java::lang::StringBuilder().append(u"DeadChecker("_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(npc(manager)->identifier)->get())))
        ->append(u" #"_j)
        ->append(::java::lang::System::identityHashCode(this))
        ->append(u"):"_j)
        ->append(tries)
        ->append(u"/"_j)
        ->append(numTries)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_DeadChecker::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.liveness.LivenessTransportLayerImpl.DeadChecker", 72);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_DeadChecker::getClass0()
{
    return class_();
}

