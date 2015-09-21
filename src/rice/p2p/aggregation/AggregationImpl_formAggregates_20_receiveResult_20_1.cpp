// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_formAggregates_20_receiveResult_20_1.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/Continuation_MultiContinuation.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/AggregationImpl_formAggregates_20.hpp>
#include <rice/p2p/aggregation/AggregationImpl_formAggregates_20_receiveResult_20_1_receiveResult_20_1_1.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/aggregation/ObjectDescriptor.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/persistence/StorageManager.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang
} // java

namespace rice
{
    namespace p2p
    {
        namespace aggregation
        {
typedef ::SubArray< ::rice::p2p::aggregation::ObjectDescriptor, ::java::lang::ObjectArray, ::java::io::SerializableArray, ::java::lang::ComparableArray > ObjectDescriptorArray;
        } // aggregation
    } // p2p
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::AggregationImpl_formAggregates_20_receiveResult_20_1::AggregationImpl_formAggregates_20_receiveResult_20_1(AggregationImpl_formAggregates_20 *AggregationImpl_formAggregates_20_this, ::rice::Continuation* thisContinuation, ObjectDescriptorArray* desc)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_formAggregates_20_this(AggregationImpl_formAggregates_20_this)
    , thisContinuation(thisContinuation)
    , desc(desc)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_formAggregates_20_receiveResult_20_1::receiveResult(::java::lang::Object* o)
{
    auto const c2 = new ::rice::Continuation_MultiContinuation(thisContinuation, npc(desc)->length);
    for (auto i = int32_t(0); i < npc(desc)->length; i++) {
        auto const c2s = npc(c2)->getSubContinuation(i);
        npc(AggregationImpl_formAggregates_20_this->AggregationImpl_this->waitingList)->unstore(new ::rice::p2p::glacier::VersionKey(npc((*desc)[i])->key, npc((*desc)[i])->version), new AggregationImpl_formAggregates_20_receiveResult_20_1_receiveResult_20_1_1(this, c2s));
    }
}

void rice::p2p::aggregation::AggregationImpl_formAggregates_20_receiveResult_20_1::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_formAggregates_20_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_formAggregates_20_this->AggregationImpl_this->logger)->logException(u"Exception while storing new aggregate: "_j, e);

    npc(thisContinuation)->receiveException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_formAggregates_20_receiveResult_20_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_formAggregates_20_receiveResult_20_1::getClass0()
{
    return class_();
}

