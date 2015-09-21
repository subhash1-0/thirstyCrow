// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationPolicy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/aggregation/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::aggregation::AggregationPolicy
    : public virtual ::java::lang::Object
{
    virtual bool shouldBeAggregated(::rice::p2p::past::PastContent* obj, int32_t size) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
