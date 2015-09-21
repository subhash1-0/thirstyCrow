// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/aggregation/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::p2p::aggregation::AggregationImpl_refreshInternal_28_receiveResult_28_3
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    void receiveResult(::java::lang::Object* o) override;
    void receiveException(::java::lang::Exception* e) override;

    // Generated
    AggregationImpl_refreshInternal_28_receiveResult_28_3(AggregationImpl_refreshInternal_28 *AggregationImpl_refreshInternal_28_this, ::rice::p2p::commonapi::Id* id, int64_t expiration, ::rice::Continuation* myParent);
    static ::java::lang::Class *class_();
    AggregationImpl_refreshInternal_28 *AggregationImpl_refreshInternal_28_this;
    ::rice::p2p::commonapi::Id* id;
    int64_t expiration;
    ::rice::Continuation* myParent;

private:
    virtual ::java::lang::Class* getClass0();
    friend class AggregationImpl;
    friend class AggregationImpl_AggregationImpl_1;
    friend class AggregationImpl_AggregationImpl_2;
    friend class AggregationImpl_AggregationImpl_3;
    friend class AggregationImpl_handleDebugCommand_4;
    friend class AggregationImpl_handleDebugCommand_5;
    friend class AggregationImpl_handleDebugCommand_6;
    friend class AggregationImpl_handleDebugCommand_7;
    friend class AggregationImpl_handleDebugCommand_8;
    friend class AggregationImpl_handleDebugCommand_9;
    friend class AggregationImpl_handleDebugCommand_10;
    friend class AggregationImpl_handleDebugCommand_11;
    friend class AggregationImpl_handleDebugCommand_12;
    friend class AggregationImpl_handleDebugCommand_13;
    friend class AggregationImpl_handleDebugCommand_13_receiveResult_13_1;
    friend class AggregationImpl_handleDebugCommand_14;
    friend class AggregationImpl_storeAggregate_15;
    friend class AggregationImpl_storeAggregate_16;
    friend class AggregationImpl_storeAggregate_16_receiveResult_16_1;
    friend class AggregationImpl_formAggregates_17;
    friend class AggregationImpl_formAggregates_18;
    friend class AggregationImpl_formAggregates_19;
    friend class AggregationImpl_formAggregates_20;
    friend class AggregationImpl_formAggregates_20_receiveResult_20_1;
    friend class AggregationImpl_formAggregates_20_receiveResult_20_1_receiveResult_20_1_1;
    friend class AggregationImpl_refreshAggregates_21;
    friend class AggregationImpl_consolidateAggregates_22;
    friend class AggregationImpl_consolidateAggregates_22_receiveResult_22_1;
    friend class AggregationImpl_reconnectTree_23;
    friend class AggregationImpl_timerExpired_24;
    friend class AggregationImpl_timerExpired_25;
    friend class AggregationImpl_refresh_26;
    friend class AggregationImpl_refresh_26_refreshInAggregates_26_1;
    friend class AggregationImpl_refresh_27;
    friend class AggregationImpl_refreshInternal_28;
    friend class AggregationImpl_refreshInternal_28_receiveResult_28_1;
    friend class AggregationImpl_refreshInternal_28_receiveResult_28_2;
    friend class AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1;
    friend class AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1_receiveResult_28_3_1_1;
    friend class AggregationImpl_rebuildRecursive_29;
    friend class AggregationImpl_rebuildRecursive_29_receiveResult_29_1;
    friend class AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1;
    friend class AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1_receiveResult_29_1_1_1;
    friend class AggregationImpl_insert_30;
    friend class AggregationImpl_insert_31;
    friend class AggregationImpl_retrieveObjectFromAggregate_32;
    friend class AggregationImpl_retrieveObjectFromAggregate_32_receiveResult_32_1;
    friend class AggregationImpl_retrieveObjectFromAggregate_32_receiveResult_32_2;
    friend class AggregationImpl_retrieveObjectFromAggregate_32_receiveResult_32_2_receiveResult_32_2_1;
    friend class AggregationImpl_lookup_33;
    friend class AggregationImpl_lookup_34;
    friend class AggregationImpl_lookup_34_receiveResult_34_1;
    friend class AggregationImpl_lookup_35;
    friend class AggregationImpl_lookupHandles_36;
    friend class AggregationImpl_lookupHandles_36_receiveResult_36_1;
    friend class AggregationImpl_reset_37;
};
