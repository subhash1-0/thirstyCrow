// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierStatistics.java
#include <rice/p2p/glacier/v2/GlacierStatistics.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runtime.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::GlacierStatistics::GlacierStatistics(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::GlacierStatistics::GlacierStatistics(int32_t numTags, ::rice::environment::Environment* env) 
    : GlacierStatistics(*static_cast< ::default_init_tag* >(0))
{
    ctor(numTags,env);
}

void rice::p2p::glacier::v2::GlacierStatistics::ctor(int32_t numTags, ::rice::environment::Environment* env)
{
    super::ctor();
    this->environment = env;
    this->messagesSentByTag = new ::int32_tArray(numTags);
    this->pendingRequests = 0;
    this->numNeighbors = 0;
    this->numFragments = 0;
    this->numContinuations = 0;
    this->numObjectsInTrash = 0;
    this->fragmentStorageSize = 0;
    this->trashStorageSize = 0;
    this->activeFetches = 0;
    this->tbegin = npc(npc(env)->getTimeSource())->currentTimeMillis();
    this->bucketMin = 0;
    this->bucketMax = 0;
    this->bucketConsumed = 0;
}

void rice::p2p::glacier::v2::GlacierStatistics::dump(::rice::environment::logging::Logger* logger)
{
    auto s = u""_j;
    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u"@L.ME free="_j)->append(npc(::java::lang::Runtime::getRuntime())->freeMemory())
        ->append(u" max="_j)
        ->append(npc(::java::lang::Runtime::getRuntime())->maxMemory())
        ->append(u" total="_j)
        ->append(npc(::java::lang::Runtime::getRuntime())->totalMemory())
        ->append(u"\n"_j)->toString())->toString();
    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u"@L.GL interval="_j)->append(tbegin)
        ->append(u"-"_j)
        ->append(npc(npc(environment)->getTimeSource())->currentTimeMillis())
        ->append(u" range="_j)
        ->append(static_cast< ::java::lang::Object* >(responsibleRange))
        ->append(u"\n"_j)->toString())->toString();
    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u"@L.GL   neighbors="_j)->append(numNeighbors)
        ->append(u" fragments="_j)
        ->append(numFragments)
        ->append(u" trash="_j)
        ->append(numObjectsInTrash)
        ->append(u"\n"_j)->toString())->toString();
    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u"@L.GL   continuations="_j)->append(numContinuations)
        ->append(u" pending="_j)
        ->append(pendingRequests)
        ->append(u"\n"_j)->toString())->toString();
    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u"@L.GL   fragSizeBytes="_j)->append(fragmentStorageSize)
        ->append(u" trashSizeBytes="_j)
        ->append(trashStorageSize)
        ->append(u"\n"_j)->toString())->toString();
    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u"@L.GL   activeFetches="_j)->append(activeFetches)
        ->append(u" bucketMin="_j)
        ->append(bucketMin)
        ->append(u" bucketMax="_j)
        ->append(bucketMax)
        ->append(u"\n"_j)->toString())->toString();
    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u"@L.GL   bucketConsumed="_j)->append(bucketConsumed)
        ->append(u"\n"_j)->toString())->toString();
    s = ::java::lang::StringBuilder(s).append(u"@L.GL   byTag="_j)->toString();
    for (auto i = int32_t(0); i < npc(messagesSentByTag)->length; i++) 
                s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append((*messagesSentByTag)[i])->append(u" "_j)->toString())->toString();

    s = ::java::lang::StringBuilder(s).append(u"\n"_j)->toString();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(s);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierStatistics::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.GlacierStatistics", 37);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierStatistics::getClass0()
{
    return class_();
}

