// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_lookup_35.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/commonapi/Id.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::AggregationImpl_lookup_35::AggregationImpl_lookup_35(AggregationImpl *AggregationImpl_this, ::rice::p2p::commonapi::Id* id, int64_t version, ::rice::Continuation* command)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
    , id(id)
    , version(version)
    , command(command)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_lookup_35::receiveResult(::java::lang::Object* o)
{
    if(o != nullptr) {
        if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"VL: Found in Object.VersioningPAST: "_j)->append(static_cast< ::java::lang::Object* >(id))
                ->append(u"v"_j)
                ->append(version)->toString());

        npc(command)->receiveResult(o);
    } else {
        if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"VL: LOOKUP FAILED, OBJECT NOT FOUND: "_j)->append(static_cast< ::java::lang::Object* >(id))
                ->append(u"v"_j)
                ->append(version)->toString());

        npc(command)->receiveResult(nullptr);
    }
}

void rice::p2p::aggregation::AggregationImpl_lookup_35::receiveException(::java::lang::Exception* e)
{
    npc(command)->receiveException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_lookup_35::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_lookup_35::getClass0()
{
    return class_();
}

