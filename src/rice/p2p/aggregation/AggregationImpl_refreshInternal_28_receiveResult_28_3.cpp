// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_refreshInternal_28_receiveResult_28_3.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/AggregationException.hpp>
#include <rice/p2p/aggregation/AggregationImpl_refreshInternal_28.hpp>
#include <rice/p2p/aggregation/AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/aggregation/AggregationPolicy.hpp>
#include <rice/p2p/aggregation/ObjectDescriptor.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/gc/GCPastContent.hpp>
#include <rice/persistence/StorageManager.hpp>

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

rice::p2p::aggregation::AggregationImpl_refreshInternal_28_receiveResult_28_3::AggregationImpl_refreshInternal_28_receiveResult_28_3(AggregationImpl_refreshInternal_28 *AggregationImpl_refreshInternal_28_this, ::rice::p2p::commonapi::Id* id, int64_t expiration, ::rice::Continuation* myParent)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_refreshInternal_28_this(AggregationImpl_refreshInternal_28_this)
    , id(id)
    , expiration(expiration)
    , myParent(myParent)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_refreshInternal_28_receiveResult_28_3::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< ::rice::p2p::past::PastContent* >(o) != nullptr) {
        auto const obj = java_cast< ::rice::p2p::past::PastContent* >(o);
        if(npc(AggregationImpl_refreshInternal_28_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(AggregationImpl_refreshInternal_28_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Refresh: Found in PAST, but not in aggregate list: "_j)->append(npc(id)->toStringFull())->toString());

        int64_t theVersion;
        if(dynamic_cast< ::rice::p2p::past::gc::GCPastContent* >(o) != nullptr) {
            theVersion = npc((java_cast< ::rice::p2p::past::gc::GCPastContent* >(obj)))->getVersion();
        } else {
            theVersion = 0;
        }
        auto const vkey = new ::rice::p2p::glacier::VersionKey(npc(obj)->getId(), theVersion);
        auto const theVersionF = theVersion;
        auto const theSize = AggregationImpl_refreshInternal_28_this->AggregationImpl_this->getSize(obj);
        if(npc(AggregationImpl_refreshInternal_28_this->AggregationImpl_this->policy)->shouldBeAggregated(obj, theSize)) {
            if(!npc(AggregationImpl_refreshInternal_28_this->AggregationImpl_this->waitingList)->exists(vkey)) {
                if(npc(AggregationImpl_refreshInternal_28_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(AggregationImpl_refreshInternal_28_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"ADDING MISSING OBJECT AFTER REFRESH: "_j)->append(static_cast< ::java::lang::Object* >(npc(obj)->getId()))->toString());

                npc(AggregationImpl_refreshInternal_28_this->AggregationImpl_this->waitingList)->store(vkey, new ObjectDescriptor(npc(obj)->getId(), theVersionF, expiration, expiration, theSize), obj, new AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1(this, obj, id, myParent));
                return;
            } else {
                if(npc(AggregationImpl_refreshInternal_28_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(AggregationImpl_refreshInternal_28_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Refresh: Missing object already in waiting list: "_j)->append(npc(id)->toStringFull())->toString());

                npc(myParent)->receiveResult(new ::java::lang::Boolean(true));
                return;
            }
        }
        if(npc(AggregationImpl_refreshInternal_28_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(AggregationImpl_refreshInternal_28_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Refresh: Missing object should not be aggregated: "_j)->append(npc(id)->toStringFull())->toString());

        npc(myParent)->receiveResult(new ::java::lang::Boolean(true));
        return;
    } else {
        if(npc(AggregationImpl_refreshInternal_28_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(AggregationImpl_refreshInternal_28_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Refresh: Cannot find refreshed object "_j)->append(npc(id)->toStringFull())
                ->append(u", lookup returns "_j)
                ->append(static_cast< ::java::lang::Object* >(o))->toString());

        npc(myParent)->receiveException(new AggregationException(::java::lang::StringBuilder().append(u"Object not found during reaggregation: "_j)->append(npc(id)->toStringFull())->toString()));
    }
}

void rice::p2p::aggregation::AggregationImpl_refreshInternal_28_receiveResult_28_3::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_refreshInternal_28_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_refreshInternal_28_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Refresh: Exception received while reaggregating "_j)->append(npc(id)->toStringFull())
            ->append(u", e="_j)
            ->append(static_cast< ::java::lang::Object* >(e))->toString());

    npc(myParent)->receiveException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_refreshInternal_28_receiveResult_28_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_refreshInternal_28_receiveResult_28_3::getClass0()
{
    return class_();
}

