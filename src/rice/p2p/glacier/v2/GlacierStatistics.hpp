// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierStatistics.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::p2p::glacier::v2::GlacierStatistics
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    ::int32_tArray* messagesSentByTag {  };
    int32_t pendingRequests {  };
    int32_t numNeighbors {  };
    int32_t numFragments {  };
    int32_t numContinuations {  };
    int32_t numObjectsInTrash {  };
    int32_t activeFetches {  };
    ::rice::p2p::commonapi::IdRange* responsibleRange {  };
    int64_t fragmentStorageSize {  };
    int64_t trashStorageSize {  };
    int64_t tbegin {  };
    int64_t bucketMin {  };
    int64_t bucketMax {  };
    int64_t bucketConsumed {  };
    int64_t bucketTokensPerSecond {  };
    int64_t bucketMaxBurstSize {  };
    ::rice::environment::Environment* environment {  };
protected:
    void ctor(int32_t numTags, ::rice::environment::Environment* env);

public:
    virtual void dump(::rice::environment::logging::Logger* logger);

    // Generated
    GlacierStatistics(int32_t numTags, ::rice::environment::Environment* env);
protected:
    GlacierStatistics(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
