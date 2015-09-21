// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/aggregation/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/past/gc/GCPast.hpp>
#include <rice/p2p/glacier/VersioningPast.hpp>
#include <rice/p2p/aggregation/Aggregation.hpp>
#include <rice/p2p/commonapi/Application.hpp>
#include <rice/p2p/util/DebugCommandHandler.hpp>

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

        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
        } // commonapi
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::aggregation::AggregationImpl
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::past::gc::GCPast
    , public virtual ::rice::p2p::glacier::VersioningPast
    , public virtual Aggregation
    , public virtual ::rice::p2p::commonapi::Application
    , public virtual ::rice::p2p::util::DebugCommandHandler
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::past::Past* aggregateStore {  };
    ::rice::persistence::StorageManager* waitingList {  };
    AggregationPolicy* policy {  };
    AggregateList* aggregateList {  };
    ::rice::p2p::commonapi::Endpoint* endpoint {  };
    ::rice::p2p::past::Past* objectStore {  };
    ::java::lang::String* instance {  };
    ::rice::p2p::commonapi::IdFactory* factory {  };
    ::rice::p2p::commonapi::Node* node {  };

private:
    static constexpr char16_t tiFlush { u'\u0001' };
    static constexpr char16_t tiMonitor { u'\u0002' };
    static constexpr char16_t tiConsolidate { u'\u0003' };
    static constexpr char16_t tiStatistics { u'\u0004' };
    static constexpr char16_t tiExpire { u'\u0005' };

public: /* protected */
    ::java::util::Hashtable* timers {  };
    ::rice::Continuation* flushWait {  };
    bool rebuildInProgress {  };
    ::java::util::Vector* monitorIDs {  };
    AggregationStatistics* stats {  };

private:
    static constexpr int64_t SECONDS { int64_t(1000LL) };
    static constexpr int64_t MINUTES { int64_t(60000LL) };
    static constexpr int64_t HOURS { int64_t(3600000LL) };
    static constexpr int64_t DAYS { int64_t(86400000LL) };
    static constexpr int64_t WEEKS { int64_t(604800000LL) };
    bool logStatistics {  };
    int64_t flushDelayAfterJoin {  };
    int64_t flushStressInterval {  };
    int64_t flushInterval {  };
    int32_t maxAggregateSize {  };
    int32_t maxObjectsInAggregate {  };
    int32_t maxAggregatesPerRun {  };
    bool addMissingAfterRefresh {  };
    int32_t maxReaggregationPerRefresh {  };
    int32_t nominalReferenceCount {  };
    int32_t maxPointersPerAggregate {  };
    int64_t pointerArrayLifetime {  };
    int64_t aggregateGracePeriod {  };
    int64_t aggrRefreshInterval {  };
    int64_t aggrRefreshDelayAfterJoin {  };
    int64_t expirationRenewThreshold {  };
    bool monitorEnabled {  };
    int64_t monitorRefreshInterval {  };
    int64_t consolidationDelayAfterJoin {  };
    int64_t consolidationInterval {  };
    int64_t consolidationThreshold {  };
    int32_t consolidationMinObjectsInAggregate {  };
    double consolidationMinComponentsAlive {  };
    int32_t reconstructionMaxConcurrentLookups {  };
    bool aggregateLogEnabled {  };
    int64_t statsGranularity {  };
    int64_t statsRange {  };
    int64_t statsInterval {  };
    double jitterRange {  };
    ::rice::environment::Environment* environment {  };

public: /* protected */
    ::rice::environment::logging::Logger* logger {  };
    ::rice::p2p::past::rawserialization::PastContentDeserializer* contentDeserializer {  };
    ::rice::p2p::past::rawserialization::PastContentHandleDeserializer* contentHandleDeserializer {  };
    AggregateFactory* aggregateFactory {  };
protected:
    void ctor(::rice::p2p::commonapi::Node* node, ::rice::p2p::past::Past* aggregateStore, ::rice::p2p::past::Past* objectStore, ::rice::persistence::StorageManager* waitingList, ::java::lang::String* configFileName, ::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* instance) /* throws(IOException) */;
    void ctor(::rice::p2p::commonapi::Node* node, ::rice::p2p::past::Past* aggregateStore, ::rice::p2p::past::Past* objectStore, ::rice::persistence::StorageManager* waitingList, ::java::lang::String* configFileName, ::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* instance, AggregationPolicy* policy, AggregateFactory* aggregateFactory) /* throws(IOException) */;

private:
    static AggregationPolicy* getDefaultPolicy();
    static AggregateFactory* getDefaultAggregateFactory();
    int64_t jitterTerm(int64_t basis);
    void addTimer(int64_t timeoutMsec, char16_t timeoutID);
    void removeTimer(int32_t timeoutID);
    void panic(::java::lang::String* s) /* throws(Error) */;

public:
    ::java::lang::String* handleDebugCommand(::java::lang::String* command) override;

private:
    void removeDeadAggregates();
    void storeAggregate(Aggregate* aggr, int64_t expiration, ObjectDescriptorArray* desc, ::rice::p2p::commonapi::IdArray* pointers, ::rice::Continuation* command);
    void flushComplete(::java::lang::Object* o);
    void formAggregates(::rice::Continuation* command);
    int64_t chooseAggregateLifetime(ObjectDescriptorArray* components, int64_t now, int64_t currentLifetime);
    void refreshAggregates();
    void consolidateAggregates();
    void reconnectTree();
    void timerExpired(char16_t timerID);
    void refreshInObjectStore(::rice::p2p::commonapi::IdArray* ids, ::int64_tArray* expirations, ::rice::Continuation* command);

public:
    void refresh(::rice::p2p::commonapi::IdArray* ids, int64_t expiration, ::rice::Continuation* command) override;
    void refresh(::rice::p2p::commonapi::IdArray* ids, ::int64_tArray* expirations, ::rice::Continuation* command) override;
    void refresh(::rice::p2p::commonapi::IdArray* ids, ::int64_tArray* versions, ::int64_tArray* expirations, ::rice::Continuation* command) override;

private:
    void refreshInternal(::rice::p2p::commonapi::IdArray* ids, ::int64_tArray* expirations, ::java::lang::ObjectArray* result, ::rice::Continuation* command);
    int32_t getSize(::rice::p2p::past::PastContent* obj);

public:
    ::java::io::Serializable* getHandle() override;
    void setHandle(::java::io::Serializable* handle, ::rice::Continuation* command) override;

private:
    void rebuildRecursive(::rice::p2p::commonapi::Id* fromKey, ::java::util::Vector* keysInProgress, ::java::util::Vector* keysPostponed, ::java::util::Vector* keysDone, ::rice::Continuation* command);
    void rebuildAggregateList(::rice::Continuation* command);

public:
    void insert(::rice::p2p::past::PastContent* obj, ::rice::Continuation* command) override;
    void insert(::rice::p2p::past::PastContent* obj, int64_t lifetime, ::rice::Continuation* command) override;

private:
    void retrieveObjectFromAggregate(AggregateDescriptor* adc, int32_t objDescIndex, ::rice::Continuation* command);

public:
    void lookup(::rice::p2p::commonapi::Id* id, bool cache, ::rice::Continuation* command) override;
    void lookup(::rice::p2p::commonapi::Id* id, int64_t version, ::rice::Continuation* command) override;
    void lookup(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command) override;
    void lookupHandles(::rice::p2p::commonapi::Id* id, int64_t version, int32_t max, ::rice::Continuation* command) override;
    void lookupHandle(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* handle, ::rice::Continuation* command) override;
    void lookupHandles(::rice::p2p::commonapi::Id* id, int32_t max, ::rice::Continuation* command) override;
    void fetch(::rice::p2p::past::PastContentHandle* handle, ::rice::Continuation* command) override;
    void flush(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command) override;
    void flush(::rice::Continuation* command) override;
    void rollback(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command) override;
    void reset(::rice::Continuation* command) override;
    ::rice::p2p::commonapi::NodeHandle* getLocalNodeHandle() override;
    int32_t getReplicationFactor() override;
    bool forward(::rice::p2p::commonapi::RouteMessage* message) override;
    void update(::rice::p2p::commonapi::NodeHandle* handle, bool joined) override;
    void deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message) override;
    virtual void setFlushInterval(int32_t flushIntervalSec);
    virtual void setMaxAggregateSize(int32_t maxAggregateSize);
    virtual void setMaxObjectsInAggregate(int32_t maxObjectsInAggregate);
    virtual void setRenewThreshold(int32_t expirationRenewThresholdHrs);
    virtual void setConsolidationInterval(int64_t consolidationIntervalSec);
    virtual void setConsolidationThreshold(int64_t consolidationThresholdSec);
    virtual void setConsolidationMinObjectsPerAggregate(int32_t minObjectsInAggregateArg);
    virtual void setConsolidationMinUtilization(double minUtilization);
    virtual ::rice::p2p::past::Past* getAggregateStore();
    virtual ::rice::p2p::past::Past* getObjectStore();
    virtual int32_t getNumObjectsWaiting();
    virtual AggregationStatistics* getStatistics();
    ::java::lang::String* getInstance() override;
    ::rice::environment::Environment* getEnvironment() override;
    void setContentDeserializer(::rice::p2p::past::rawserialization::PastContentDeserializer* deserializer) override;
    void setContentHandleDeserializer(::rice::p2p::past::rawserialization::PastContentHandleDeserializer* deserializer) override;

    // Generated
    AggregationImpl(::rice::p2p::commonapi::Node* node, ::rice::p2p::past::Past* aggregateStore, ::rice::p2p::past::Past* objectStore, ::rice::persistence::StorageManager* waitingList, ::java::lang::String* configFileName, ::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* instance);
    AggregationImpl(::rice::p2p::commonapi::Node* node, ::rice::p2p::past::Past* aggregateStore, ::rice::p2p::past::Past* objectStore, ::rice::persistence::StorageManager* waitingList, ::java::lang::String* configFileName, ::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* instance, AggregationPolicy* policy, AggregateFactory* aggregateFactory);
protected:
    AggregationImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
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
    friend class AggregationImpl_refreshInternal_28_receiveResult_28_3;
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
