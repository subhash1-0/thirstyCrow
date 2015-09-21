// Generated from /pastry-2.1/src/rice/p2p/aggregation/raw/RawAggregateFactory.java
#include <rice/p2p/aggregation/raw/RawAggregateFactory.hpp>

#include <rice/p2p/aggregation/raw/RawAggregate.hpp>

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
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
        } // commonapi

        namespace past
        {
typedef ::SubArray< ::rice::p2p::past::PastContent, ::java::lang::ObjectArray, ::java::io::SerializableArray > PastContentArray;

            namespace gc
            {
typedef ::SubArray< ::rice::p2p::past::gc::GCPastContent, ::java::lang::ObjectArray, ::rice::p2p::past::PastContentArray > GCPastContentArray;
            } // gc

            namespace rawserialization
            {
typedef ::SubArray< ::rice::p2p::past::rawserialization::RawPastContent, ::java::lang::ObjectArray, ::rice::p2p::past::PastContentArray > RawPastContentArray;
            } // rawserialization

            namespace gc
            {
                namespace rawserialization
                {
typedef ::SubArray< ::rice::p2p::past::gc::rawserialization::RawGCPastContent, ::java::lang::ObjectArray, ::rice::p2p::past::gc::GCPastContentArray, ::rice::p2p::past::rawserialization::RawPastContentArray > RawGCPastContentArray;
                } // rawserialization
            } // gc
        } // past
    } // p2p
} // rice

rice::p2p::aggregation::raw::RawAggregateFactory::RawAggregateFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::aggregation::raw::RawAggregateFactory::RawAggregateFactory()
    : RawAggregateFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::p2p::aggregation::Aggregate* rice::p2p::aggregation::raw::RawAggregateFactory::buildAggregate(::rice::p2p::past::gc::GCPastContentArray* components, ::rice::p2p::commonapi::IdArray* pointers)
{
    return new RawAggregate(components, pointers);
}

rice::p2p::aggregation::Aggregate* rice::p2p::aggregation::raw::RawAggregateFactory::buildAggregate(::rice::p2p::past::gc::rawserialization::RawGCPastContentArray* components, ::rice::p2p::commonapi::IdArray* pointers)
{
    return new RawAggregate(components, pointers);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::raw::RawAggregateFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.aggregation.raw.RawAggregateFactory", 44);
    return c;
}

java::lang::Class* rice::p2p::aggregation::raw::RawAggregateFactory::getClass0()
{
    return class_();
}

