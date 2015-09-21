// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_lookup_34.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/AggregationException.hpp>
#include <rice/p2p/aggregation/AggregationImpl_lookup_34_receiveResult_34_1.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/glacier/VersioningPast.hpp>
#include <rice/p2p/past/Past.hpp>

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

rice::p2p::aggregation::AggregationImpl_lookup_34::AggregationImpl_lookup_34(AggregationImpl *AggregationImpl_this, ::rice::p2p::commonapi::Id* id, int64_t version, ::rice::Continuation* command)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
    , id(id)
    , version(version)
    , command(command)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_lookup_34::receiveResult(::java::lang::Object* o)
{
    if(o != nullptr) {
        if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"VL: Found in Aggregate.VersioningPAST: "_j)->append(static_cast< ::java::lang::Object* >(id))
                ->append(u"v"_j)
                ->append(version)->toString());

        npc(command)->receiveResult(o);
    } else {
        if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"VL: Not found in Aggregate.VersioningPAST: "_j)->append(static_cast< ::java::lang::Object* >(id))
                ->append(u"v"_j)
                ->append(version)->toString());

        if(dynamic_cast< ::rice::p2p::glacier::VersioningPast* >(AggregationImpl_this->objectStore) != nullptr) {
            auto vpast = java_cast< ::rice::p2p::glacier::VersioningPast* >(AggregationImpl_this->objectStore);
            npc(vpast)->lookup(id, version, new AggregationImpl_lookup_34_receiveResult_34_1(this, id, version, command));
        } else {
            if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(AggregationImpl_this->logger)->log(u"VL: Object store does not support versioning"_j);

            npc(command)->receiveException(new AggregationException(::java::lang::StringBuilder().append(u"Cannot find "_j)->append(static_cast< ::java::lang::Object* >(id))
                ->append(u"v"_j)
                ->append(version)
                ->append(u" -- try rebuilding aggregate list?"_j)->toString()));
        }
    }
}

void rice::p2p::aggregation::AggregationImpl_lookup_34::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Aggregate.VersioningPAST returned exception for "_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u"v"_j)
            ->append(version)
            ->append(u": "_j)->toString(), e);

    npc(command)->receiveException(new AggregationException(::java::lang::StringBuilder().append(u"Aggregate.VersioningPAST returned exception for "_j)->append(static_cast< ::java::lang::Object* >(id))
        ->append(u"v"_j)
        ->append(version)
        ->append(u": "_j)
        ->append(static_cast< ::java::lang::Object* >(e))->toString()));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_lookup_34::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_lookup_34::getClass0()
{
    return class_();
}

