// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_startup_3.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_3_receiveResult_3_1.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_3_receiveResult_3_2.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierRangeQueryMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierRangeResponseMessage.hpp>
#include <rice/persistence/StorageManager.hpp>
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

rice::p2p::glacier::v2::GlacierImpl_startup_3::GlacierImpl_startup_3(GlacierImpl *GlacierImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
{
    clinit();
    ctor();
}

java::lang::String* rice::p2p::glacier::v2::GlacierImpl_startup_3::toString()
{
    return u"Sync continuation"_j;
}

void rice::p2p::glacier::v2::GlacierImpl_startup_3::init_()
{
    nextTimeout = npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis() + GlacierImpl_this->syncDelayAfterJoin;
}

void rice::p2p::glacier::v2::GlacierImpl_startup_3::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierRangeResponseMessage* >(o) != nullptr) {
        auto const grrm = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierRangeResponseMessage* >(o);
        auto ccwId = GlacierImpl_this->getFragmentLocation(npc(npc(grrm)->getCommonRange())->getCCWId(), GlacierImpl_this->numFragments - offset, 0);
        auto cwId = GlacierImpl_this->getFragmentLocation(npc(npc(grrm)->getCommonRange())->getCWId(), GlacierImpl_this->numFragments - offset, 0);
        auto const originalRange = npc(GlacierImpl_this->factory)->buildIdRange(ccwId, cwId);
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Range response (offset: "_j)->append(offset)
                ->append(u"): "_j)
                ->append(static_cast< ::java::lang::Object* >(npc(grrm)->getCommonRange()))
                ->append(u", original="_j)
                ->append(static_cast< ::java::lang::Object* >(originalRange))->toString());

        auto const keySet = npc(GlacierImpl_this->fragmentStorage)->scan();
        npc(GlacierImpl_this->endpoint)->process(new GlacierImpl_startup_3_receiveResult_3_1(this, keySet, originalRange), new GlacierImpl_startup_3_receiveResult_3_2(this, keySet, grrm));
    } else {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Unknown result in sync continuation: "_j)->append(static_cast< ::java::lang::Object* >(o))
                ->append(u" -- discarded"_j)->toString());

    }
}

void rice::p2p::glacier::v2::GlacierImpl_startup_3::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->logException(u"Exception in sync continuation: "_j, e);

    terminate();
}

void rice::p2p::glacier::v2::GlacierImpl_startup_3::timeoutExpired()
{
    if((*GlacierImpl_this->numActiveRestores)[int32_t(0)] > 0) {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Sync postponed; "_j)->append((*GlacierImpl_this->numActiveRestores)[int32_t(0)])
                ->append(u" fetches pending"_j)->toString());

        nextTimeout = npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis() + GlacierImpl_this->jitterTerm(GlacierImpl_this->syncRetryInterval);
    } else {
        nextTimeout = npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis() + GlacierImpl_this->jitterTerm(GlacierImpl_this->syncInterval);
        offset = int32_t(1) + npc(npc(GlacierImpl_this->environment)->getRandomSource())->nextInt(GlacierImpl_this->numFragments - int32_t(1));
        auto dest = GlacierImpl_this->getFragmentLocation(npc(GlacierImpl_this->getLocalNodeHandle())->getId(), offset, 0);
        auto ccwId = GlacierImpl_this->getFragmentLocation(npc(GlacierImpl_this->responsibleRange)->getCCWId(), offset, 0);
        auto cwId = GlacierImpl_this->getFragmentLocation(npc(GlacierImpl_this->responsibleRange)->getCWId(), offset, 0);
        auto requestedRange = npc(GlacierImpl_this->factory)->buildIdRange(ccwId, cwId);
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Sending range query for ("_j)->append(static_cast< ::java::lang::Object* >(requestedRange))
                ->append(u") to "_j)
                ->append(static_cast< ::java::lang::Object* >(dest))->toString());

        GlacierImpl_this->sendMessage(dest, new ::rice::p2p::glacier::v2::messaging::GlacierRangeQueryMessage(getMyUID(), requestedRange, GlacierImpl_this->getLocalNodeHandle(), dest, GlacierImpl_this->tagSync), nullptr);
    }
}

int64_t rice::p2p::glacier::v2::GlacierImpl_startup_3::getTimeout()
{
    return nextTimeout;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_3::getClass0()
{
    return class_();
}

