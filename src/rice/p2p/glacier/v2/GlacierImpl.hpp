// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/glacier/Glacier.hpp>
#include <rice/p2p/past/gc/GCPast.hpp>
#include <rice/p2p/glacier/VersioningPast.hpp>
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
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
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

        namespace glacier
        {
typedef ::SubArray< ::rice::p2p::glacier::Fragment, ::java::lang::ObjectArray, ::java::io::SerializableArray > FragmentArray;

            namespace v2
            {
typedef ::SubArray< ::rice::p2p::glacier::v2::Manifest, ::java::lang::ObjectArray, ::java::io::SerializableArray > ManifestArray;
            } // v2
        } // glacier

        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::IdArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > IdArrayArray;
        } // commonapi
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::glacier::v2::GlacierImpl
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::glacier::Glacier
    , public virtual ::rice::p2p::past::gc::GCPast
    , public virtual ::rice::p2p::glacier::VersioningPast
    , public virtual ::rice::p2p::commonapi::Application
    , public virtual ::rice::p2p::util::DebugCommandHandler
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::persistence::StorageManager* fragmentStorage {  };
    ::rice::persistence::StorageManager* neighborStorage {  };
    GlacierPolicy* policy {  };
    ::rice::p2p::commonapi::Node* node {  };
    int32_t numFragments {  };
    ::java::lang::String* instance {  };
    int32_t numSurvivors {  };
    ::rice::p2p::commonapi::Endpoint* endpoint {  };
    ::rice::p2p::commonapi::IdFactory* factory {  };
    ::java::util::Hashtable* continuations {  };
    ::java::util::Hashtable* pendingTraffic {  };
    ::rice::persistence::StorageManager* trashStorage {  };
    int64_t nextContinuationTimeout {  };
    ::rice::p2p::commonapi::IdRange* responsibleRange {  };
    int32_t nextUID {  };
    ::rice::p2p::commonapi::CancellableTask* timer {  };
    GlacierStatistics* statistics {  };
    ::java::util::Vector* listeners {  };
    int64_t currentFragmentRequestTimeout {  };
    int64_t tokenBucket {  };
    int64_t bucketLastUpdated {  };
    int64_t bucketMin {  };
    int64_t bucketMax {  };
    int64_t bucketConsumed {  };

private:
    static constexpr int64_t SECONDS { int64_t(1000LL) };
    static constexpr int64_t MINUTES { int64_t(60000LL) };
    static constexpr int64_t HOURS { int64_t(3600000LL) };
    static constexpr int64_t DAYS { int64_t(86400000LL) };
    static constexpr int64_t WEEKS { int64_t(604800000LL) };
    bool logStatistics {  };
    bool faultInjectionEnabled {  };
    int64_t insertTimeout {  };
    double minFragmentsAfterInsert {  };
    int64_t refreshTimeout {  };
    int64_t expireNeighborsDelayAfterJoin {  };
    int64_t expireNeighborsInterval {  };
    int64_t neighborTimeout {  };
    int64_t syncDelayAfterJoin {  };
    int64_t syncMinRemainingLifetime {  };
    int64_t syncMinQuietTime {  };
    int32_t syncBloomFilterNumHashes {  };
    int32_t syncBloomFilterBitsPerKey {  };
    int32_t syncPartnersPerTrial {  };
    int64_t syncInterval {  };
    int64_t syncRetryInterval {  };
    int32_t syncMaxFragments {  };
    int32_t fragmentRequestMaxAttempts {  };
    int64_t fragmentRequestTimeoutDefault {  };
    int64_t fragmentRequestTimeoutMin {  };
    int64_t fragmentRequestTimeoutMax {  };
    int64_t fragmentRequestTimeoutDecrement {  };
    int64_t manifestRequestTimeout {  };
    int64_t manifestRequestInitialBurst {  };
    int64_t manifestRequestRetryBurst {  };
    int32_t manifestAggregationFactor {  };
    int64_t overallRestoreTimeout {  };
    int64_t handoffDelayAfterJoin {  };
    int64_t handoffInterval {  };
    int32_t handoffMaxFragments {  };
    int64_t garbageCollectionInterval {  };
    int32_t garbageCollectionMaxFragmentsPerRun {  };
    int64_t localScanInterval {  };
    int32_t localScanMaxFragmentsPerRun {  };
    double restoreMaxRequestFactor {  };
    int32_t restoreMaxBoosts {  };
    int64_t rateLimitedCheckInterval {  };
    int32_t rateLimitedRequestsPerSecond {  };
    bool enableBulkRefresh {  };
    int64_t bulkRefreshProbeInterval {  };
    double bulkRefreshMaxProbeFactor {  };
    int64_t bulkRefreshManifestInterval {  };
    int32_t bulkRefreshManifestAggregationFactor {  };
    int32_t bulkRefreshPatchAggregationFactor {  };
    int64_t bulkRefreshPatchInterval {  };
    int32_t bulkRefreshPatchRetries {  };
    int64_t bucketTokensPerSecond {  };
    int64_t bucketMaxBurstSize {  };
    double jitterRange {  };
    int64_t statisticsReportInterval {  };
    int32_t maxActiveRestores {  };
    ::int32_tArray* numActiveRestores {  };
    static constexpr char16_t tagNeighbor { u'\u0001' };
    static constexpr char16_t tagSync { u'\u0002' };
    static constexpr char16_t tagSyncManifests { u'\u0003' };
    static constexpr char16_t tagSyncFetch { u'\u0004' };
    static constexpr char16_t tagHandoff { u'\u0005' };
    static constexpr char16_t tagDebug { u'\u0006' };
    static constexpr char16_t tagRefresh { u'\u0007' };
    static constexpr char16_t tagInsert { u'\u0008' };
    static constexpr char16_t tagLookupHandles { u'\u0009' };
    static constexpr char16_t tagLookup { u'\u000a' };
    static constexpr char16_t tagFetch { u'\u000b' };
    static constexpr char16_t tagLocalScan { u'\u000c' };
    static constexpr char16_t tagMax { u'\u000d' };
    ::rice::environment::Environment* environment {  };

public: /* protected */
    ::rice::environment::logging::Logger* logger {  };
    ::rice::p2p::past::rawserialization::PastContentDeserializer* contentDeserializer {  };
    ::rice::p2p::past::rawserialization::PastContentHandleDeserializer* contentHandleDeserializer {  };
protected:
    void ctor(::rice::p2p::commonapi::Node* nodeArg, ::rice::persistence::StorageManager* fragmentStorageArg, ::rice::persistence::StorageManager* neighborStorageArg, int32_t numFragmentsArg, int32_t numSurvivorsArg, ::rice::p2p::commonapi::IdFactory* factoryArg, ::java::lang::String* instanceArg, GlacierPolicy* policyArg);

public:
    virtual void startup();

public: /* protected */
    virtual void updateTokenBucket();

private:
    int64_t jitterTerm(int64_t basis);
    void deleteFragment(::rice::p2p::commonapi::Id* fkey, ::rice::Continuation* command);

public:
    virtual void sendMessage(::rice::p2p::commonapi::Id* id, ::rice::p2p::glacier::v2::messaging::GlacierMessage* message, ::rice::p2p::commonapi::NodeHandle* hint);
    virtual void setTrashcan(::rice::persistence::StorageManager* trashStorage);

private:
    ::int8_tArray* getHashInput(::rice::p2p::glacier::VersionKey* vkey, int64_t expiration);
    static ::java::lang::String* dump(::int8_tArray* data, bool linebreak);
    void addContinuation(GlacierContinuation* gc);
    void determineResponsibleRange();

public: /* protected */
    virtual int32_t getUID();

private:
    void setTimer(int32_t timeoutMsec);
    void cancelTimer();
    static ::int8_tArray* getDistance(double d);
    ::rice::p2p::commonapi::Id* getFragmentLocation(::rice::p2p::commonapi::Id* objectKey, int32_t fragmentNr, int64_t version);
    ::rice::p2p::commonapi::Id* getFragmentLocation(::rice::p2p::glacier::FragmentKey* fkey);
    void panic(::java::lang::String* s) /* throws(Error) */;

public:
    ::java::lang::String* handleDebugCommand(::java::lang::String* command) override;
    void insert(::rice::p2p::past::PastContent* obj, ::rice::Continuation* command) override;
    void refresh(::rice::p2p::commonapi::IdArray* ids, ::int64_tArray* expirations, ::rice::Continuation* command) override;
    void refresh(::rice::p2p::commonapi::IdArray* ids, int64_t expiration, ::rice::Continuation* command) override;
    void refresh(::rice::p2p::commonapi::IdArray* ids, ::int64_tArray* versions, ::int64_tArray* expirations, ::rice::Continuation* command) override;

private:
    void distribute(::rice::p2p::glacier::VersionKey* key, ::rice::p2p::glacier::FragmentArray* fragments, ManifestArray* manifests, int64_t expiration, char16_t tag, ::rice::Continuation* command);

public:
    void insert(::rice::p2p::past::PastContent* obj, int64_t expiration, ::rice::Continuation* command) override;

private:
    void timerExpired();

public:
    virtual void neighborSeen(::rice::p2p::commonapi::Id* nodeId, int64_t when);
    bool forward(::rice::p2p::commonapi::RouteMessage* message) override;
    void update(::rice::p2p::commonapi::NodeHandle* handle, bool joined) override;
    void lookupHandle(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* handle, ::rice::Continuation* command) override;
    void lookupHandles(::rice::p2p::commonapi::Id* id, int32_t num, ::rice::Continuation* command) override;
    void lookupHandles(::rice::p2p::commonapi::Id* id, int64_t version, int32_t num, ::rice::Continuation* command) override;
    void lookup(::rice::p2p::commonapi::Id* id, int64_t version, ::rice::Continuation* command) override;
    void lookup(::rice::p2p::commonapi::Id* id, bool cache, ::rice::Continuation* command) override;
    void lookup(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command) override;
    void fetch(::rice::p2p::past::PastContentHandle* handle, ::rice::Continuation* command) override;
    virtual void retrieveManifest(::rice::p2p::glacier::VersionKey* key, char16_t tag, ::rice::Continuation* command);
    virtual void retrieveObject(::rice::p2p::glacier::VersionKey* key, Manifest* manifest, bool beStrict, char16_t tag, ::rice::Continuation* c);
    virtual void retrieveFragment(::rice::p2p::glacier::FragmentKey* key, Manifest* manifest, char16_t tag, GlacierContinuation* c);
    virtual void rateLimitedRetrieveFragment(::rice::p2p::glacier::FragmentKey* key, Manifest* manifest, char16_t tag, GlacierContinuation* c);
    virtual ::rice::p2p::commonapi::IdArrayArray* getNeighborRanges();
    void deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message) override;
    int32_t getReplicationFactor() override;
    ::rice::p2p::commonapi::NodeHandle* getLocalNodeHandle() override;
    virtual void setSyncInterval(int32_t syncIntervalSec);
    virtual void setSyncMaxFragments(int32_t syncMaxFragments);
    virtual void setRateLimit(int32_t rps);
    virtual void setNeighborTimeout(int64_t neighborTimeoutMin);
    virtual void setBandwidthLimit(int64_t bytesPerSecond, int64_t maxBurst);
    virtual int64_t getTrashSize();
    virtual void emptyTrash(::rice::Continuation* c);
    virtual void addStatisticsListener(GlacierStatisticsListener* gsl);
    virtual void removeStatisticsListener(GlacierStatisticsListener* gsl);
    ::rice::environment::Environment* getEnvironment() override;
    ::java::lang::String* getInstance() override;
    void setContentDeserializer(::rice::p2p::past::rawserialization::PastContentDeserializer* deserializer) override;
    void setContentHandleDeserializer(::rice::p2p::past::rawserialization::PastContentHandleDeserializer* deserializer) override;

    // Generated
    GlacierImpl(::rice::p2p::commonapi::Node* nodeArg, ::rice::persistence::StorageManager* fragmentStorageArg, ::rice::persistence::StorageManager* neighborStorageArg, int32_t numFragmentsArg, int32_t numSurvivorsArg, ::rice::p2p::commonapi::IdFactory* factoryArg, ::java::lang::String* instanceArg, GlacierPolicy* policyArg);
protected:
    GlacierImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class GlacierImpl_GlacierImpl_1;
    friend class GlacierImpl_startup_2;
    friend class GlacierImpl_startup_2_timeoutExpired_2_1;
    friend class GlacierImpl_startup_2_timeoutExpired_2_1_receiveResult_2_1_1;
    friend class GlacierImpl_startup_3;
    friend class GlacierImpl_startup_3_receiveResult_3_1;
    friend class GlacierImpl_startup_3_receiveResult_3_2;
    friend class GlacierImpl_startup_4;
    friend class GlacierImpl_startup_4_receiveResult_4_1;
    friend class GlacierImpl_startup_4_receiveResult_4_2;
    friend class GlacierImpl_startup_4_receiveResult_4_3;
    friend class GlacierImpl_startup_5;
    friend class GlacierImpl_startup_5_timeoutExpired_5_1;
    friend class GlacierImpl_startup_6;
    friend class GlacierImpl_startup_6_timeoutExpired_6_1;
    friend class GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1;
    friend class GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1_receiveResult_6_1_1_1;
    friend class GlacierImpl_startup_7;
    friend class GlacierImpl_startup_8;
    friend class GlacierImpl_deleteFragment_9;
    friend class GlacierImpl_deleteFragment_9_receiveResult_9_1;
    friend class GlacierImpl_handleDebugCommand_10;
    friend class GlacierImpl_handleDebugCommand_11;
    friend class GlacierImpl_handleDebugCommand_12;
    friend class GlacierImpl_handleDebugCommand_13;
    friend class GlacierImpl_handleDebugCommand_13_receiveResult_13_1;
    friend class GlacierImpl_handleDebugCommand_14;
    friend class GlacierImpl_handleDebugCommand_15;
    friend class GlacierImpl_handleDebugCommand_16;
    friend class GlacierImpl_handleDebugCommand_17;
    friend class GlacierImpl_handleDebugCommand_18;
    friend class GlacierImpl_handleDebugCommand_19;
    friend class GlacierImpl_refresh_20;
    friend class GlacierImpl_refresh_20_receiveResult_20_1;
    friend class GlacierImpl_refresh_21;
    friend class GlacierImpl_distribute_22;
    friend class GlacierImpl_insert_23;
    friend class GlacierImpl_insert_24;
    friend class GlacierImpl_insert_24_receiveResult_24_1;
    friend class GlacierImpl_insert_24_receiveResult_24_2;
    friend class GlacierImpl_neighborSeen_25;
    friend class GlacierImpl_neighborSeen_25_receiveResult_25_1;
    friend class GlacierImpl_lookupHandles_26;
    friend class GlacierImpl_retrieveManifest_27;
    friend class GlacierImpl_retrieveObject_28;
    friend class GlacierImpl_retrieveFragment_29;
    friend class GlacierImpl_retrieveFragment_29_receiveResult_29_1;
    friend class GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1;
    friend class GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_receiveResult_29_1_1_1;
    friend class GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_receiveResult_29_1_1_2;
    friend class GlacierImpl_retrieveFragment_30;
    friend class GlacierImpl_rateLimitedRetrieveFragment_31;
    friend class GlacierImpl_deliver_32;
    friend class GlacierImpl_deliver_33;
    friend class GlacierImpl_deliver_34;
    friend class GlacierImpl_deliver_35;
    friend class GlacierImpl_deliver_36;
    friend class GlacierImpl_deliver_37;
    friend class GlacierImpl_deliver_37_receiveResult_37_1;
    friend class GlacierImpl_deliver_38;
    friend class GlacierImpl_deliver_38_receiveResult_38_1;
};
