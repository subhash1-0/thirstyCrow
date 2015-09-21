// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_refreshAggregates_21.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/AggregateDescriptor.hpp>
#include <rice/p2p/aggregation/AggregateList.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <ObjectArray.hpp>

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

rice::p2p::aggregation::AggregationImpl_refreshAggregates_21::AggregationImpl_refreshAggregates_21(AggregationImpl *AggregationImpl_this, ::java::util::Vector* refreshAggregateList, ::java::util::Vector* refreshLifetimeList)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
    , refreshAggregateList(refreshAggregateList)
    , refreshLifetimeList(refreshLifetimeList)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_refreshAggregates_21::receiveResult(::java::lang::Object* o)
{
    auto results = java_cast< ::java::lang::ObjectArray* >(o);
    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Received refresh results for "_j)->append(npc(results)->length)
            ->append(u" aggregates"_j)->toString());

    auto numOk = int32_t(0);
    for (auto i = int32_t(0); i < npc(results)->length; i++) {
        if(dynamic_cast< ::java::lang::Boolean* >((*results)[i]) != nullptr) {
            auto aggr = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(refreshAggregateList)->elementAt(i)));
            auto newLifetime = npc((java_cast< ::java::lang::Long* >(java_cast< ::java::lang::Object* >(npc(refreshLifetimeList)->elementAt(i)))))->longValue();
            if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Aggregate #"_j)->append(i)
                    ->append(u" ("_j)
                    ->append(npc(npc(aggr)->key)->toStringFull())
                    ->append(u"): OK, new lifetime is "_j)
                    ->append(newLifetime)->toString());

            npc(AggregationImpl_this->aggregateList)->refreshAggregate(aggr, newLifetime);
            numOk++;
        } else {
            auto aggr = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(refreshAggregateList)->elementAt(i)));
            auto e = java_cast< ::java::lang::Exception* >((*results)[i]);
            if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(AggregationImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Aggregate #"_j)->append(i)
                    ->append(u" ("_j)
                    ->append(npc(npc(aggr)->key)->toStringFull())
                    ->append(u"): Refresh failed, e="_j)->toString(), e);

        }
    }
    npc(AggregationImpl_this->aggregateList)->writeToDisk();
    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Refresh complete, "_j)->append(numOk)
            ->append(u"/"_j)
            ->append(npc(results)->length)
            ->append(u" aggregates refreshed OK"_j)->toString());

}

void rice::p2p::aggregation::AggregationImpl_refreshAggregates_21::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Interface contract broken; exception "_j)->append(static_cast< ::java::lang::Object* >(e))
            ->append(u" returned directly"_j)->toString(), e);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_refreshAggregates_21::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_refreshAggregates_21::getClass0()
{
    return class_();
}

