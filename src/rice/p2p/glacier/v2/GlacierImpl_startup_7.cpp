// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_startup_7.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Enumeration.hpp>
#include <java/util/Hashtable.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
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
rice::p2p::glacier::v2::GlacierImpl_startup_7::GlacierImpl_startup_7(GlacierImpl *GlacierImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
{
    clinit();
    ctor();
}

java::lang::String* rice::p2p::glacier::v2::GlacierImpl_startup_7::toString()
{
    return u"Traffic shaper"_j;
}

void rice::p2p::glacier::v2::GlacierImpl_startup_7::init_()
{
    nextTimeout = npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis() + GlacierImpl_this->rateLimitedCheckInterval;
}

void rice::p2p::glacier::v2::GlacierImpl_startup_7::receiveResult(::java::lang::Object* o)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"TS received object: "_j)->append(static_cast< ::java::lang::Object* >(o))->toString());

}

void rice::p2p::glacier::v2::GlacierImpl_startup_7::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->logException(u"TS received exception: "_j, e);

}

int64_t rice::p2p::glacier::v2::GlacierImpl_startup_7::getTimeout()
{
    return nextTimeout;
}

void rice::p2p::glacier::v2::GlacierImpl_startup_7::timeoutExpired()
{
    nextTimeout = npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis() + (int32_t(1) * GlacierImpl_this->SECONDS);
    if(npc(GlacierImpl_this->pendingTraffic)->isEmpty()) {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(u"Traffic shaper: Idle"_j);

        nextTimeout += GlacierImpl_this->rateLimitedCheckInterval;
        return;
    }
    auto numCurrentRestores = int32_t(0);
    {
        synchronized synchronized_0(GlacierImpl_this->numActiveRestores);
        {
            numCurrentRestores = (*GlacierImpl_this->numActiveRestores)[int32_t(0)];
        }
    }
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Traffic shaper: "_j)->append(npc(GlacierImpl_this->pendingTraffic)->size())
            ->append(u" jobs waiting ("_j)
            ->append(numCurrentRestores)
            ->append(u" active jobs, "_j)
            ->append(GlacierImpl_this->tokenBucket)
            ->append(u" tokens)"_j)->toString());

    GlacierImpl_this->updateTokenBucket();
    if((numCurrentRestores < GlacierImpl_this->maxActiveRestores) && (GlacierImpl_this->tokenBucket > 0)) {
        for (auto i = int32_t(0); i < GlacierImpl_this->rateLimitedRequestsPerSecond; i++) {
            if(!npc(GlacierImpl_this->pendingTraffic)->isEmpty()) {
                auto keys = npc(GlacierImpl_this->pendingTraffic)->keys();
                auto thisKey = java_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(keys)->nextElement()));
                if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Sending request "_j)->append(static_cast< ::java::lang::Object* >(thisKey))->toString());

                auto c = java_cast< ::rice::Continuation* >(java_cast< ::java::lang::Object* >(npc(GlacierImpl_this->pendingTraffic)->remove(thisKey)));
                npc(c)->receiveResult(new ::java::lang::Boolean(true));
            }
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_7::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_7::getClass0()
{
    return class_();
}

