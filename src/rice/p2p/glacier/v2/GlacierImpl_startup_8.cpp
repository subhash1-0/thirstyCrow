// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_startup_8.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Enumeration.hpp>
#include <java/util/Hashtable.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/GlacierStatistics.hpp>
#include <rice/p2p/glacier/v2/GlacierStatisticsListener.hpp>
#include <rice/persistence/PersistentStorage.hpp>
#include <rice/persistence/Storage.hpp>
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

rice::p2p::glacier::v2::GlacierImpl_startup_8::GlacierImpl_startup_8(GlacierImpl *GlacierImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
{
    clinit();
    ctor();
}

java::lang::String* rice::p2p::glacier::v2::GlacierImpl_startup_8::toString()
{
    return u"Statistics"_j;
}

void rice::p2p::glacier::v2::GlacierImpl_startup_8::init_()
{
    nextTimeout = npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis() + GlacierImpl_this->statisticsReportInterval;
}

void rice::p2p::glacier::v2::GlacierImpl_startup_8::receiveResult(::java::lang::Object* o)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"STAT received object: "_j)->append(static_cast< ::java::lang::Object* >(o))->toString());

}

void rice::p2p::glacier::v2::GlacierImpl_startup_8::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->logException(u"STAT received exception: "_j, e);

}

int64_t rice::p2p::glacier::v2::GlacierImpl_startup_8::getTimeout()
{
    return nextTimeout;
}

void rice::p2p::glacier::v2::GlacierImpl_startup_8::timeoutExpired()
{
    nextTimeout += GlacierImpl_this->statisticsReportInterval;
    if(!npc(GlacierImpl_this->listeners)->isEmpty()) {
        npc(GlacierImpl_this->statistics)->pendingRequests = npc(GlacierImpl_this->pendingTraffic)->size();
        npc(GlacierImpl_this->statistics)->numNeighbors = npc(npc(GlacierImpl_this->neighborStorage)->scan())->numElements();
        npc(GlacierImpl_this->statistics)->numFragments = npc(npc(GlacierImpl_this->fragmentStorage)->scan())->numElements();
        npc(GlacierImpl_this->statistics)->numContinuations = npc(GlacierImpl_this->continuations)->size();
        npc(GlacierImpl_this->statistics)->responsibleRange = GlacierImpl_this->responsibleRange;
        npc(GlacierImpl_this->statistics)->activeFetches = (*GlacierImpl_this->numActiveRestores)[int32_t(0)];
        npc(GlacierImpl_this->statistics)->bucketMin = GlacierImpl_this->bucketMin;
        npc(GlacierImpl_this->statistics)->bucketMax = GlacierImpl_this->bucketMax;
        npc(GlacierImpl_this->statistics)->bucketConsumed = GlacierImpl_this->bucketConsumed;
        npc(GlacierImpl_this->statistics)->bucketTokensPerSecond = GlacierImpl_this->bucketTokensPerSecond;
        npc(GlacierImpl_this->statistics)->bucketMaxBurstSize = GlacierImpl_this->bucketMaxBurstSize;
        GlacierImpl_this->bucketMin = GlacierImpl_this->tokenBucket;
        GlacierImpl_this->bucketMax = GlacierImpl_this->tokenBucket;
        GlacierImpl_this->bucketConsumed = 0;
        auto storageF = npc(GlacierImpl_this->fragmentStorage)->getStorage();
        if(dynamic_cast< ::rice::persistence::PersistentStorage* >(storageF) != nullptr)
            npc(GlacierImpl_this->statistics)->fragmentStorageSize = npc((java_cast< ::rice::persistence::PersistentStorage* >(storageF)))->getTotalSize();

        auto storageT = (GlacierImpl_this->trashStorage == nullptr) ? static_cast< ::rice::persistence::Storage* >(nullptr) : npc(GlacierImpl_this->trashStorage)->getStorage();
        if(dynamic_cast< ::rice::persistence::PersistentStorage* >(storageT) != nullptr)
            npc(GlacierImpl_this->statistics)->trashStorageSize = npc((java_cast< ::rice::persistence::PersistentStorage* >(storageT)))->getTotalSize();

        if(GlacierImpl_this->logStatistics)
            npc(GlacierImpl_this->statistics)->dump(npc(npc(GlacierImpl_this->environment)->getLogManager())->getLogger(GlacierStatistics::class_(), GlacierImpl_this->instance));

        auto enumeration = npc(GlacierImpl_this->listeners)->elements();
        while (npc(enumeration)->hasMoreElements()) {
            auto gsl = java_cast< GlacierStatisticsListener* >(java_cast< ::java::lang::Object* >(npc(enumeration)->nextElement()));
            npc(gsl)->receiveStatistics(GlacierImpl_this->statistics);
        }
    }
    GlacierImpl_this->statistics = new GlacierStatistics(GlacierImpl_this->tagMax, GlacierImpl_this->environment);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_8::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_8::getClass0()
{
    return class_();
}

