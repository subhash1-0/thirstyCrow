// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationStatistics.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/aggregation/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::p2p::aggregation::AggregationStatistics
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    int64_t granularity {  };
    int32_t numObjectsTotal {  };
    int32_t numObjectsAlive {  };
    int32_t numAggregatesTotal {  };
    int32_t numPointerArrays {  };
    int32_t criticalAggregates {  };
    int32_t orphanedAggregates {  };
    ::int32_tArray* objectLifetimeHisto {  };
    ::int32_tArray* aggregateLifetimeHisto {  };
    int64_t totalObjectsSize {  };
    int64_t liveObjectsSize {  };
    int64_t time {  };

private:
    ::rice::environment::Environment* environment {  };
protected:
    void ctor(int32_t histoLength, int64_t granularityArg, ::rice::environment::Environment* env);

public:
    virtual void dump(::rice::environment::logging::Logger* logger);

    // Generated
    AggregationStatistics(int32_t histoLength, int64_t granularityArg, ::rice::environment::Environment* env);
protected:
    AggregationStatistics(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
