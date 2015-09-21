// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationDefaultPolicy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/aggregation/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/aggregation/AggregationPolicy.hpp>

struct default_init_tag;

class rice::p2p::aggregation::AggregationDefaultPolicy
    : public virtual ::java::lang::Object
    , public virtual AggregationPolicy
{

public:
    typedef ::java::lang::Object super;
    bool shouldBeAggregated(::rice::p2p::past::PastContent* obj, int32_t size) override;

    // Generated
    AggregationDefaultPolicy();
protected:
    AggregationDefaultPolicy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
