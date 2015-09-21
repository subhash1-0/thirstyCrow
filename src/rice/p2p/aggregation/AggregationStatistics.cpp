// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationStatistics.java
#include <rice/p2p/aggregation/AggregationStatistics.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Arrays.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::AggregationStatistics::AggregationStatistics(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::aggregation::AggregationStatistics::AggregationStatistics(int32_t histoLength, int64_t granularityArg, ::rice::environment::Environment* env) 
    : AggregationStatistics(*static_cast< ::default_init_tag* >(0))
{
    ctor(histoLength,granularityArg,env);
}

void rice::p2p::aggregation::AggregationStatistics::ctor(int32_t histoLength, int64_t granularityArg, ::rice::environment::Environment* env)
{
    super::ctor();
    this->environment = env;
    numObjectsTotal = 0;
    numObjectsAlive = 0;
    numAggregatesTotal = 0;
    numPointerArrays = 0;
    totalObjectsSize = 0;
    liveObjectsSize = 0;
    granularity = granularityArg;
    objectLifetimeHisto = new ::int32_tArray(histoLength);
    ::java::util::Arrays::fill(objectLifetimeHisto, int32_t(0));
    aggregateLifetimeHisto = new ::int32_tArray(histoLength);
    ::java::util::Arrays::fill(aggregateLifetimeHisto, int32_t(0));
    time = npc(npc(environment)->getTimeSource())->currentTimeMillis();
}

void rice::p2p::aggregation::AggregationStatistics::dump(::rice::environment::logging::Logger* logger)
{
    auto s = ::java::lang::StringBuilder().append(u"@L.AG interval="_j)->append(time)
        ->append(u"-"_j)
        ->append(npc(npc(environment)->getTimeSource())->currentTimeMillis())
        ->append(u" granularity="_j)
        ->append(granularity)
        ->append(u"\n"_j)->toString();
    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u"@L.AG   objsTotal="_j)->append(numObjectsTotal)
        ->append(u" objsAlive="_j)
        ->append(numObjectsAlive)
        ->append(u"\n"_j)->toString())->toString();
    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u"@L.AG   objBytesTotal="_j)->append(totalObjectsSize)
        ->append(u" objBytesAlive="_j)
        ->append(liveObjectsSize)
        ->append(u"\n"_j)->toString())->toString();
    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u"@L.AG   aggrTotal="_j)->append(numAggregatesTotal)
        ->append(u" ptrArrays="_j)
        ->append(numPointerArrays)
        ->append(u" critical="_j)
        ->append(criticalAggregates)
        ->append(u" orphaned="_j)
        ->append(orphanedAggregates)->toString())->toString();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(s);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationStatistics::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.aggregation.AggregationStatistics", 42);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationStatistics::getClass0()
{
    return class_();
}

