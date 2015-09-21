// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregateFactory.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/aggregation/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

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

struct rice::p2p::aggregation::AggregateFactory
    : public virtual ::java::lang::Object
{
    virtual Aggregate* buildAggregate(::rice::p2p::past::gc::GCPastContentArray* components, ::rice::p2p::commonapi::IdArray* pointers) = 0;
    virtual Aggregate* buildAggregate(::rice::p2p::past::gc::rawserialization::RawGCPastContentArray* components, ::rice::p2p::commonapi::IdArray* pointers) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
