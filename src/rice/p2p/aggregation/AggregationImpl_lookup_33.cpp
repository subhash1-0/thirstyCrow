// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_lookup_33.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/AggregateDescriptor.hpp>
#include <rice/p2p/aggregation/AggregateList.hpp>
#include <rice/p2p/aggregation/AggregationException.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/commonapi/Id.hpp>

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

rice::p2p::aggregation::AggregationImpl_lookup_33::AggregationImpl_lookup_33(AggregationImpl *AggregationImpl_this, ::rice::p2p::commonapi::Id* id, ::rice::Continuation* command)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
    , id(id)
    , command(command)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_lookup_33::receiveResult(::java::lang::Object* o)
{
    if(o != nullptr) {
        if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"NL: Found in PAST: "_j)->append(static_cast< ::java::lang::Object* >(id))->toString());

        npc(command)->receiveResult(o);
    } else {
        auto adc = java_cast< AggregateDescriptor* >(npc(AggregationImpl_this->aggregateList)->getADC(id));
        if(adc != nullptr) {
            if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(AggregationImpl_this->logger)->log(u"NL: Must retrieve from aggregate"_j);

            auto objDescIndex = npc(adc)->lookupNewest(id);
            if(objDescIndex < 0) {
                if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(AggregationImpl_this->logger)->log(u"NL: Aggregate found, but object not found in aggregate?!? -- aborted"_j);

                npc(command)->receiveException(new AggregationException(u"Inconsistency detected in aggregate list -- try restarting the application"_j));
                return;
            }
            AggregationImpl_this->retrieveObjectFromAggregate(adc, objDescIndex, command);
        } else {
            if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"NL: LOOKUP FAILED, OBJECT NOT FOUND: "_j)->append(static_cast< ::java::lang::Object* >(id))->toString());

            npc(command)->receiveResult(nullptr);
        }
    }
}

void rice::p2p::aggregation::AggregationImpl_lookup_33::receiveException(::java::lang::Exception* e)
{
    npc(command)->receiveException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_lookup_33::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_lookup_33::getClass0()
{
    return class_();
}

