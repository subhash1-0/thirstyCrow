// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Error.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuffer.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Thread.hpp>
#include <java/lang/UnsupportedOperationException.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Date.hpp>
#include <java/util/Enumeration.hpp>
#include <java/util/Hashtable.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Vector.hpp>
#include <rice/Continuation_MultiContinuation.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/CancellableTask.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id_Distance.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>
#include <rice/p2p/glacier/Fragment.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/FragmentKeySet.hpp>
#include <rice/p2p/glacier/GlacierException.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/p2p/glacier/v2/BloomFilter.hpp>
#include <rice/p2p/glacier/v2/FragmentAndManifest.hpp>
#include <rice/p2p/glacier/v2/FragmentMetadata.hpp>
#include <rice/p2p/glacier/v2/GlacierContentHandle.hpp>
#include <rice/p2p/glacier/v2/GlacierContinuation.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_insert_23.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_insert_24.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_neighborSeen_25.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_lookupHandles_26.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveManifest_27.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_GlacierImpl_1.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveObject_28.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveFragment_29.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveFragment_30.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_rateLimitedRetrieveFragment_31.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_deliver_32.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_2.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_deliver_33.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_deliver_34.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_deliver_35.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_deliver_36.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_deliver_37.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_deliver_38.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_3.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_4.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_5.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_6.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_7.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_8.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_deleteFragment_9.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_handleDebugCommand_10.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_handleDebugCommand_11.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_handleDebugCommand_12.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_handleDebugCommand_13.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_handleDebugCommand_14.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_handleDebugCommand_15.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_handleDebugCommand_16.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_handleDebugCommand_17.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_handleDebugCommand_18.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_handleDebugCommand_19.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_refresh_20.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_refresh_21.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_distribute_22.hpp>
#include <rice/p2p/glacier/v2/GlacierPolicy.hpp>
#include <rice/p2p/glacier/v2/GlacierStatistics.hpp>
#include <rice/p2p/glacier/v2/GlacierStatisticsListener.hpp>
#include <rice/p2p/glacier/v2/Manifest.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierDataMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierFetchMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierNeighborRequestMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierQueryMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierRangeForwardMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierRangeQueryMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierRangeResponseMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierRefreshPatchMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierRefreshProbeMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierRefreshResponseMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierResponseMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierSyncMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierTimeoutMessage.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>
#include <rice/p2p/past/gc/GCPast.hpp>
#include <rice/p2p/past/gc/GCPastContent.hpp>
#include <rice/p2p/past/rawserialization/JavaPastContentDeserializer.hpp>
#include <rice/p2p/past/rawserialization/JavaPastContentHandleDeserializer.hpp>
#include <rice/p2p/past/rawserialization/PastContentDeserializer.hpp>
#include <rice/p2p/past/rawserialization/PastContentHandleDeserializer.hpp>
#include <rice/persistence/Storage.hpp>
#include <rice/persistence/StorageManager.hpp>
#include <Array.hpp>
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
typedef ::SubArray< ::java::lang::Boolean, ObjectArray, ::java::io::SerializableArray, ComparableArray > BooleanArray;
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
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
typedef ::SubArray< ::rice::p2p::glacier::FragmentKey, ::java::lang::ObjectArray, ::rice::p2p::commonapi::IdArray > FragmentKeyArray;

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

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::GlacierImpl::GlacierImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::GlacierImpl::GlacierImpl(::rice::p2p::commonapi::Node* nodeArg, ::rice::persistence::StorageManager* fragmentStorageArg, ::rice::persistence::StorageManager* neighborStorageArg, int32_t numFragmentsArg, int32_t numSurvivorsArg, ::rice::p2p::commonapi::IdFactory* factoryArg, ::java::lang::String* instanceArg, GlacierPolicy* policyArg) 
    : GlacierImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(nodeArg,fragmentStorageArg,neighborStorageArg,numFragmentsArg,numSurvivorsArg,factoryArg,instanceArg,policyArg);
}

constexpr int64_t rice::p2p::glacier::v2::GlacierImpl::SECONDS;

constexpr int64_t rice::p2p::glacier::v2::GlacierImpl::MINUTES;

constexpr int64_t rice::p2p::glacier::v2::GlacierImpl::HOURS;

constexpr int64_t rice::p2p::glacier::v2::GlacierImpl::DAYS;

constexpr int64_t rice::p2p::glacier::v2::GlacierImpl::WEEKS;

constexpr char16_t rice::p2p::glacier::v2::GlacierImpl::tagNeighbor;

constexpr char16_t rice::p2p::glacier::v2::GlacierImpl::tagSync;

constexpr char16_t rice::p2p::glacier::v2::GlacierImpl::tagSyncManifests;

constexpr char16_t rice::p2p::glacier::v2::GlacierImpl::tagSyncFetch;

constexpr char16_t rice::p2p::glacier::v2::GlacierImpl::tagHandoff;

constexpr char16_t rice::p2p::glacier::v2::GlacierImpl::tagDebug;

constexpr char16_t rice::p2p::glacier::v2::GlacierImpl::tagRefresh;

constexpr char16_t rice::p2p::glacier::v2::GlacierImpl::tagInsert;

constexpr char16_t rice::p2p::glacier::v2::GlacierImpl::tagLookupHandles;

constexpr char16_t rice::p2p::glacier::v2::GlacierImpl::tagLookup;

constexpr char16_t rice::p2p::glacier::v2::GlacierImpl::tagFetch;

constexpr char16_t rice::p2p::glacier::v2::GlacierImpl::tagLocalScan;

constexpr char16_t rice::p2p::glacier::v2::GlacierImpl::tagMax;

void rice::p2p::glacier::v2::GlacierImpl::ctor(::rice::p2p::commonapi::Node* nodeArg, ::rice::persistence::StorageManager* fragmentStorageArg, ::rice::persistence::StorageManager* neighborStorageArg, int32_t numFragmentsArg, int32_t numSurvivorsArg, ::rice::p2p::commonapi::IdFactory* factoryArg, ::java::lang::String* instanceArg, GlacierPolicy* policyArg)
{
    super::ctor();
    this->environment = npc(nodeArg)->getEnvironment();
    this->logger = npc(npc(environment)->getLogManager())->getLogger(GlacierImpl::class_(), instanceArg);
    auto p = npc(environment)->getParameters();
    logStatistics = npc(p)->getBoolean(u"p2p_glacier_logStatistics"_j);
    faultInjectionEnabled = npc(p)->getBoolean(u"p2p_glacier_faultInjectionEnabled"_j);
    insertTimeout = npc(p)->getLong(u"p2p_glacier_insertTimeout"_j);
    minFragmentsAfterInsert = npc(p)->getDouble(u"p2p_glacier_minFragmentsAfterInsert"_j);
    refreshTimeout = npc(p)->getLong(u"p2p_glacier_refreshTimeout"_j);
    expireNeighborsDelayAfterJoin = npc(p)->getLong(u"p2p_glacier_expireNeighborsDelayAfterJoin"_j);
    expireNeighborsInterval = npc(p)->getLong(u"p2p_glacier_expireNeighborsInterval"_j);
    neighborTimeout = npc(p)->getLong(u"p2p_glacier_neighborTimeout"_j);
    syncDelayAfterJoin = npc(p)->getLong(u"p2p_glacier_syncDelayAfterJoin"_j);
    syncMinRemainingLifetime = npc(p)->getLong(u"p2p_glacier_syncMinRemainingLifetime"_j);
    syncMinQuietTime = npc(p)->getLong(u"p2p_glacier_syncMinQuietTime"_j);
    syncBloomFilterNumHashes = npc(p)->getInt(u"p2p_glacier_syncBloomFilterNumHashes"_j);
    syncBloomFilterBitsPerKey = npc(p)->getInt(u"p2p_glacier_syncBloomFilterBitsPerKey"_j);
    syncPartnersPerTrial = npc(p)->getInt(u"p2p_glacier_syncPartnersPerTrial"_j);
    syncInterval = npc(p)->getLong(u"p2p_glacier_syncInterval"_j);
    syncRetryInterval = npc(p)->getLong(u"p2p_glacier_syncRetryInterval"_j);
    syncMaxFragments = npc(p)->getInt(u"p2p_glacier_syncMaxFragments"_j);
    fragmentRequestMaxAttempts = npc(p)->getInt(u"p2p_glacier_fragmentRequestMaxAttempts"_j);
    fragmentRequestTimeoutDefault = npc(p)->getLong(u"p2p_glacier_fragmentRequestTimeoutDefault"_j);
    fragmentRequestTimeoutMin = npc(p)->getLong(u"p2p_glacier_fragmentRequestTimeoutMin"_j);
    fragmentRequestTimeoutMax = npc(p)->getLong(u"p2p_glacier_fragmentRequestTimeoutMax"_j);
    fragmentRequestTimeoutDecrement = npc(p)->getLong(u"p2p_glacier_fragmentRequestTimeoutDecrement"_j);
    manifestRequestTimeout = npc(p)->getLong(u"p2p_glacier_manifestRequestTimeout"_j);
    manifestRequestInitialBurst = npc(p)->getLong(u"p2p_glacier_manifestRequestInitialBurst"_j);
    manifestRequestRetryBurst = npc(p)->getLong(u"p2p_glacier_manifestRequestRetryBurst"_j);
    manifestAggregationFactor = npc(p)->getInt(u"p2p_glacier_manifestAggregationFactor"_j);
    overallRestoreTimeout = npc(p)->getLong(u"p2p_glacier_overallRestoreTimeout"_j);
    handoffDelayAfterJoin = npc(p)->getLong(u"p2p_glacier_handoffDelayAfterJoin"_j);
    handoffInterval = npc(p)->getLong(u"p2p_glacier_handoffInterval"_j);
    handoffMaxFragments = npc(p)->getInt(u"p2p_glacier_handoffMaxFragments"_j);
    garbageCollectionInterval = npc(p)->getLong(u"p2p_glacier_garbageCollectionInterval"_j);
    garbageCollectionMaxFragmentsPerRun = npc(p)->getInt(u"p2p_glacier_garbageCollectionMaxFragmentsPerRun"_j);
    localScanInterval = npc(p)->getLong(u"p2p_glacier_localScanInterval"_j);
    localScanMaxFragmentsPerRun = npc(p)->getInt(u"p2p_glacier_localScanMaxFragmentsPerRun"_j);
    restoreMaxRequestFactor = npc(p)->getDouble(u"p2p_glacier_restoreMaxRequestFactor"_j);
    restoreMaxBoosts = npc(p)->getInt(u"p2p_glacier_restoreMaxBoosts"_j);
    rateLimitedCheckInterval = npc(p)->getLong(u"p2p_glacier_rateLimitedCheckInterval"_j);
    rateLimitedRequestsPerSecond = npc(p)->getInt(u"p2p_glacier_rateLimitedRequestsPerSecond"_j);
    enableBulkRefresh = npc(p)->getBoolean(u"p2p_glacier_enableBulkRefresh"_j);
    bulkRefreshProbeInterval = npc(p)->getLong(u"p2p_glacier_bulkRefreshProbeInterval"_j);
    bulkRefreshMaxProbeFactor = npc(p)->getDouble(u"p2p_glacier_bulkRefreshMaxProbeFactor"_j);
    bulkRefreshManifestInterval = npc(p)->getLong(u"p2p_glacier_bulkRefreshManifestInterval"_j);
    bulkRefreshManifestAggregationFactor = npc(p)->getInt(u"p2p_glacier_bulkRefreshManifestAggregationFactor"_j);
    bulkRefreshPatchAggregationFactor = npc(p)->getInt(u"p2p_glacier_bulkRefreshPatchAggregationFactor"_j);
    bulkRefreshPatchInterval = npc(p)->getLong(u"p2p_glacier_bulkRefreshPatchInterval"_j);
    bulkRefreshPatchRetries = npc(p)->getInt(u"p2p_glacier_bulkRefreshPatchRetries"_j);
    bucketTokensPerSecond = npc(p)->getLong(u"p2p_glacier_bucketTokensPerSecond"_j);
    bucketMaxBurstSize = npc(p)->getLong(u"p2p_glacier_bucketMaxBurstSize"_j);
    jitterRange = npc(p)->getDouble(u"p2p_glacier_jitterRange"_j);
    statisticsReportInterval = npc(p)->getLong(u"p2p_glacier_statisticsReportInterval"_j);
    maxActiveRestores = npc(p)->getInt(u"p2p_glacier_maxActiveRestores"_j);
    this->fragmentStorage = fragmentStorageArg;
    this->neighborStorage = neighborStorageArg;
    this->trashStorage = nullptr;
    this->policy = policyArg;
    this->node = nodeArg;
    this->instance = instanceArg;
    this->endpoint = npc(node)->buildEndpoint(this, instance);
    npc(this->endpoint)->setDeserializer(new GlacierImpl_GlacierImpl_1(this));
    this->contentDeserializer = new ::rice::p2p::past::rawserialization::JavaPastContentDeserializer();
    this->contentHandleDeserializer = new ::rice::p2p::past::rawserialization::JavaPastContentHandleDeserializer();
    this->numFragments = numFragmentsArg;
    this->numSurvivors = numSurvivorsArg;
    this->factory = factoryArg;
    this->responsibleRange = nullptr;
    this->nextUID = 0;
    this->continuations = new ::java::util::Hashtable();
    this->pendingTraffic = new ::java::util::Hashtable();
    this->timer = nullptr;
    this->nextContinuationTimeout = -int32_t(1);
    this->statistics = new GlacierStatistics(tagMax, environment);
    this->listeners = new ::java::util::Vector();
    this->numActiveRestores = new ::int32_tArray(int32_t(1));
    (*this->numActiveRestores)[int32_t(0)] = 0;
    this->currentFragmentRequestTimeout = fragmentRequestTimeoutDefault;
    this->tokenBucket = 0;
    this->bucketLastUpdated = npc(npc(environment)->getTimeSource())->currentTimeMillis();
    determineResponsibleRange();
    npc(endpoint)->register_();
}

void rice::p2p::glacier::v2::GlacierImpl::startup()
{
    addContinuation(new GlacierImpl_startup_2(this));
    addContinuation(new GlacierImpl_startup_3(this));
    addContinuation(new GlacierImpl_startup_4(this));
    addContinuation(new GlacierImpl_startup_5(this));
    addContinuation(new GlacierImpl_startup_6(this));
    addContinuation(new GlacierImpl_startup_7(this));
    addContinuation(new GlacierImpl_startup_8(this));
}

void rice::p2p::glacier::v2::GlacierImpl::updateTokenBucket()
{
    auto const now = npc(npc(environment)->getTimeSource())->currentTimeMillis();
    auto const contentsBefore = tokenBucket;
    while (bucketLastUpdated < now) {
        bucketLastUpdated += SECONDS / int32_t(10);
        tokenBucket += bucketTokensPerSecond / int32_t(10);
        if(tokenBucket > bucketMaxBurstSize)
            tokenBucket = bucketMaxBurstSize;

    }
    if(bucketMax < tokenBucket)
        bucketMax = tokenBucket;

    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Token bucket contains "_j)->append(tokenBucket)
            ->append(u" tokens (added "_j)
            ->append((tokenBucket - contentsBefore))
            ->append(u")"_j)->toString());

}

int64_t rice::p2p::glacier::v2::GlacierImpl::jitterTerm(int64_t basis)
{
    return static_cast< int64_t >(((int32_t(1) - jitterRange) * basis)) + npc(npc(environment)->getRandomSource())->nextInt(static_cast< int32_t >((int32_t(2) * jitterRange * basis)));
}

void rice::p2p::glacier::v2::GlacierImpl::deleteFragment(::rice::p2p::commonapi::Id* fkey, ::rice::Continuation* command)
{
    if(trashStorage != nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Moving fragment "_j)->append(npc(fkey)->toStringFull())
                ->append(u" to trash"_j)->toString());

        npc(fragmentStorage)->getObject(fkey, new GlacierImpl_deleteFragment_9(this, fkey, command));
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Deleting fragment "_j)->append(npc(fkey)->toStringFull())->toString());

        npc(fragmentStorage)->unstore(fkey, command);
    }
}

void rice::p2p::glacier::v2::GlacierImpl::sendMessage(::rice::p2p::commonapi::Id* id, ::rice::p2p::glacier::v2::messaging::GlacierMessage* message, ::rice::p2p::commonapi::NodeHandle* hint)
{
    auto className = npc(npc(message)->getClass())->getName();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Send "_j)->append(((hint == nullptr) ? u"OVR"_j : u"DIR"_j))
            ->append(u" T"_j)
            ->append((static_cast< int32_t >(npc(message)->getTag())))
            ->append(u" "_j)
            ->append(npc(className)->substring(npc(className)->lastIndexOf(static_cast< int32_t >(u'.')) + int32_t(8)))->toString());

    (*npc(statistics)->messagesSentByTag)[npc(message)->getTag()]++;
    npc(endpoint)->route(id, static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(message), hint);
}

void rice::p2p::glacier::v2::GlacierImpl::setTrashcan(::rice::persistence::StorageManager* trashStorage)
{
    this->trashStorage = trashStorage;
}

int8_tArray* rice::p2p::glacier::v2::GlacierImpl::getHashInput(::rice::p2p::glacier::VersionKey* vkey, int64_t expiration)
{
    auto a = npc(vkey)->toByteArray_();
    auto b = new ::int8_tArray(npc(a)->length + int32_t(8));
    for (auto i = int32_t(0); i < npc(a)->length; i++) 
                (*b)[i] = (*a)[i];

    (*b)[npc(a)->length + int32_t(0)] = static_cast< int8_t >((int32_t(255) & (expiration >> int32_t(56))));
    (*b)[npc(a)->length + int32_t(1)] = static_cast< int8_t >((int32_t(255) & (expiration >> int32_t(48))));
    (*b)[npc(a)->length + int32_t(2)] = static_cast< int8_t >((int32_t(255) & (expiration >> int32_t(40))));
    (*b)[npc(a)->length + int32_t(3)] = static_cast< int8_t >((int32_t(255) & (expiration >> int32_t(32))));
    (*b)[npc(a)->length + int32_t(4)] = static_cast< int8_t >((int32_t(255) & (expiration >> int32_t(24))));
    (*b)[npc(a)->length + int32_t(5)] = static_cast< int8_t >((int32_t(255) & (expiration >> int32_t(16))));
    (*b)[npc(a)->length + int32_t(6)] = static_cast< int8_t >((int32_t(255) & (expiration >> int32_t(8))));
    (*b)[npc(a)->length + int32_t(7)] = static_cast< int8_t >((int32_t(255) & (expiration)));
    return b;
}

java::lang::String* rice::p2p::glacier::v2::GlacierImpl::dump(::int8_tArray* data, bool linebreak)
{
    clinit();
    auto const hex = u"0123456789ABCDEF"_j;
    auto result = u""_j;
    for (auto i = int32_t(0); i < npc(data)->length; i++) {
        int32_t d = (*data)[i];
        if(d < 0)
            d += 256;

        auto hi = (d >> int32_t(4));
        auto lo = (d & int32_t(15));
        result = ::java::lang::StringBuilder().append(result)->append(npc(hex)->charAt(hi))
            ->append(npc(hex)->charAt(lo))->toString();
        if(linebreak && (((i % int32_t(16)) == 15) || (i == (npc(data)->length - int32_t(1)))))
            result = ::java::lang::StringBuilder().append(result)->append(u"\n"_j)->toString();
        else if(i != (npc(data)->length - int32_t(1)))
            result = ::java::lang::StringBuilder().append(result)->append(u" "_j)->toString();

    }
    return result;
}

void rice::p2p::glacier::v2::GlacierImpl::addContinuation(GlacierContinuation* gc)
{
    auto thisUID = getUID();
    npc(gc)->setup(thisUID);
    npc(continuations)->put(static_cast< ::java::lang::Object* >(new ::java::lang::Integer(thisUID)), static_cast< ::java::lang::Object* >(gc));
    npc(gc)->init_();
    auto thisTimeout = npc(gc)->getTimeout();
    auto now = npc(npc(environment)->getTimeSource())->currentTimeMillis();
    if((nextContinuationTimeout == -int32_t(1)) || (thisTimeout < nextContinuationTimeout)) {
        if(nextContinuationTimeout != -int32_t(1))
            cancelTimer();

        nextContinuationTimeout = thisTimeout;
        if(nextContinuationTimeout > now)
            setTimer(static_cast< int32_t >((nextContinuationTimeout - now)));
        else
            timerExpired();
    }
}

void rice::p2p::glacier::v2::GlacierImpl::determineResponsibleRange()
{
    ::rice::p2p::commonapi::Id* cwPeer = nullptr;
    ::rice::p2p::commonapi::Id* ccwPeer = nullptr;
    ::rice::p2p::commonapi::Id* xcwPeer = nullptr;
    ::rice::p2p::commonapi::Id* xccwPeer = nullptr;
    auto myNodeId = npc(getLocalNodeHandle())->getId();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(u"Determining responsible range"_j);

    auto iter = npc(npc(neighborStorage)->scan())->getIterator();
    while (npc(iter)->hasNext()) {
        auto thisNeighbor = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(iter)->next()));
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Considering neighbor: "_j)->append(static_cast< ::java::lang::Object* >(thisNeighbor))->toString());

        if(npc(myNodeId)->clockwise(thisNeighbor)) {
            if((cwPeer == nullptr) || npc(thisNeighbor)->isBetween(myNodeId, cwPeer))
                cwPeer = thisNeighbor;

            if((xcwPeer == nullptr) || npc(xcwPeer)->clockwise(thisNeighbor))
                xcwPeer = thisNeighbor;

        } else {
            if((ccwPeer == nullptr) || npc(thisNeighbor)->isBetween(ccwPeer, myNodeId))
                ccwPeer = thisNeighbor;

            if((xccwPeer == nullptr) || !npc(xccwPeer)->clockwise(thisNeighbor))
                xccwPeer = thisNeighbor;

        }
    }
    if(ccwPeer == nullptr)
        ccwPeer = xcwPeer;

    if(cwPeer == nullptr)
        cwPeer = xccwPeer;

    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"XCCW: "_j)->append(static_cast< ::java::lang::Object* >(xccwPeer))
            ->append(u" CCW: "_j)
            ->append(static_cast< ::java::lang::Object* >(ccwPeer))
            ->append(u" ME: "_j)
            ->append(static_cast< ::java::lang::Object* >(myNodeId))
            ->append(u" CW: "_j)
            ->append(static_cast< ::java::lang::Object* >(cwPeer))
            ->append(u" XCW: "_j)
            ->append(static_cast< ::java::lang::Object* >(xcwPeer))->toString());

    if((ccwPeer == nullptr) || (cwPeer == nullptr)) {
        responsibleRange = npc(factory)->buildIdRange(myNodeId, myNodeId);
        return;
    }
    ::rice::p2p::commonapi::Id_Distance* ccwHalfDistance;
    if(!npc(myNodeId)->clockwise(ccwPeer))
        ccwHalfDistance = npc(npc(ccwPeer)->distanceFromId(myNodeId))->shiftDistance(1, 0);
    else
        ccwHalfDistance = npc(npc(ccwPeer)->longDistanceFromId(myNodeId))->shiftDistance(1, 0);
    ::rice::p2p::commonapi::Id_Distance* cwHalfDistance;
    if(npc(myNodeId)->clockwise(cwPeer))
        cwHalfDistance = npc(npc(cwPeer)->distanceFromId(myNodeId))->shiftDistance(1, 0);
    else
        cwHalfDistance = npc(npc(cwPeer)->longDistanceFromId(myNodeId))->shiftDistance(1, 0);
    responsibleRange = npc(factory)->buildIdRange(npc(ccwPeer)->addToId(ccwHalfDistance), npc(myNodeId)->addToId(cwHalfDistance));
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"New range: "_j)->append(static_cast< ::java::lang::Object* >(responsibleRange))->toString());

}

int32_t rice::p2p::glacier::v2::GlacierImpl::getUID()
{
    return nextUID++;
}

void rice::p2p::glacier::v2::GlacierImpl::setTimer(int32_t timeoutMsec)
{
    timer = npc(endpoint)->scheduleMessage(new ::rice::p2p::glacier::v2::messaging::GlacierTimeoutMessage(int32_t(0), getLocalNodeHandle()), timeoutMsec);
}

void rice::p2p::glacier::v2::GlacierImpl::cancelTimer()
{
    if(timer != nullptr) {
        npc(timer)->cancel();
        timer = nullptr;
    }
}

int8_tArray* rice::p2p::glacier::v2::GlacierImpl::getDistance(double d)
{
    clinit();
    auto result = new ::int8_tArray(int32_t(20));
    auto c = 0.5;
    for (auto i = int32_t(19); i >= 0; i--) {
        (*result)[i] = 0;
        for (auto j = int32_t(7); j >= 0; j--) {
            if(d >= c) {
                (*result)[i] |= (int32_t(1) << j);
                d -= c;
            }
            c /= 2;
        }
    }
    return result;
}

rice::p2p::commonapi::Id* rice::p2p::glacier::v2::GlacierImpl::getFragmentLocation(::rice::p2p::commonapi::Id* objectKey, int32_t fragmentNr, int64_t version)
{
    auto totalOffset = ((static_cast< float >(fragmentNr)) / (static_cast< float >(numFragments))) + version * (1.0 / 2.7182821);
    return npc(objectKey)->addToId(npc(factory)->buildIdDistance(getDistance(totalOffset - ::java::lang::Math::floor(totalOffset))));
}

rice::p2p::commonapi::Id* rice::p2p::glacier::v2::GlacierImpl::getFragmentLocation(::rice::p2p::glacier::FragmentKey* fkey)
{
    return getFragmentLocation(npc(npc(fkey)->getVersionKey())->getId(), npc(fkey)->getFragmentID(), npc(npc(fkey)->getVersionKey())->getVersion());
}

void rice::p2p::glacier::v2::GlacierImpl::panic(::java::lang::String* s) /* throws(Error) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"PANIC: "_j)->append(s)->toString());

    throw new ::java::lang::Error(u"Panic"_j);
}

java::lang::String* rice::p2p::glacier::v2::GlacierImpl::handleDebugCommand(::java::lang::String* command)
{
    if(npc(command)->indexOf(u" "_j) < 0)
        return nullptr;

    auto myInstance = ::java::lang::StringBuilder().append(u"glacier."_j)->append(npc(instance)->substring(npc(instance)->lastIndexOf(u"-"_j) + int32_t(1)))->toString();
    auto requestedInstance = npc(command)->substring(0, npc(command)->indexOf(u" "_j));
    auto cmd = npc(command)->substring(npc(requestedInstance)->length() + int32_t(1));
    if(!npc(requestedInstance)->equals(static_cast< ::java::lang::Object* >(myInstance)) && !npc(requestedInstance)->equals(static_cast< ::java::lang::Object* >(u"g"_j)))
        return nullptr;

    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Debug command: "_j)->append(cmd)->toString());

    if(npc(cmd)->startsWith(u"ls"_j)) {
        auto keyset = java_cast< ::rice::p2p::glacier::FragmentKeySet* >(npc(fragmentStorage)->scan());
        auto iter = npc(keyset)->getIterator();
        auto result = new ::java::lang::StringBuffer();
        auto now = npc(npc(environment)->getTimeSource())->currentTimeMillis();
        if(npc(cmd)->indexOf(u"-r"_j) < 0)
            now = 0;

        npc(result)->append(::java::lang::StringBuilder().append(npc(keyset)->numElements())->append(u" fragment(s)\n"_j)->toString());
        while (npc(iter)->hasNext()) {
            auto thisKey = java_cast< ::rice::p2p::glacier::FragmentKey* >(java_cast< ::java::lang::Object* >(npc(iter)->next()));
            auto isMine = npc(responsibleRange)->containsId(getFragmentLocation(thisKey));
            auto metadata = java_cast< FragmentMetadata* >(npc(fragmentStorage)->getMetadata(thisKey));
            if(metadata != nullptr) {
                npc(result)->append(::java::lang::StringBuilder().append(npc((java_cast< ::rice::p2p::commonapi::Id* >(thisKey)))->toStringFull())->append(u" "_j)
                    ->append((isMine ? u"OK"_j : u"MI"_j))
                    ->append(u" "_j)
                    ->append((npc(metadata)->getCurrentExpiration() - now))
                    ->append(u" "_j)
                    ->append((npc(metadata)->getPreviousExpiration() - now))
                    ->append(u"\n"_j)->toString());
            }
        }
        return npc(result)->toString();
    }
    if(npc(cmd)->startsWith(u"show config"_j)) {
        return ::java::lang::StringBuilder().append(u"numFragments = "_j)->append(numFragments)
            ->append(u"\n"_j)
            ->append(u"numSurvivors = "_j)
            ->append(numSurvivors)
            ->append(u"\n"_j)
            ->append(u"insertTimeout = "_j)
            ->append(static_cast< int32_t >((insertTimeout / SECONDS)))
            ->append(u" sec\n"_j)
            ->append(u"minFragmentsAfterInsert = "_j)
            ->append(minFragmentsAfterInsert)
            ->append(u"x"_j)
            ->append(numSurvivors)
            ->append(u"\n"_j)
            ->append(u"refreshTimeout = "_j)
            ->append(static_cast< int32_t >((refreshTimeout / SECONDS)))
            ->append(u" sec\n"_j)
            ->append(u"expireNeighborsDelayAfterJoin = "_j)
            ->append(static_cast< int32_t >((expireNeighborsDelayAfterJoin / SECONDS)))
            ->append(u" sec\n"_j)
            ->append(u"expireNeighborsInterval = "_j)
            ->append(static_cast< int32_t >((expireNeighborsInterval / MINUTES)))
            ->append(u" min\n"_j)
            ->append(u"neighborTimeout = "_j)
            ->append(static_cast< int32_t >((neighborTimeout / HOURS)))
            ->append(u" hrs\n"_j)
            ->append(u"syncDelayAfterJoin = "_j)
            ->append(static_cast< int32_t >((syncDelayAfterJoin / SECONDS)))
            ->append(u" sec\n"_j)
            ->append(u"syncMinRemainingLifetime = "_j)
            ->append(static_cast< int32_t >((syncMinRemainingLifetime / SECONDS)))
            ->append(u" sec\n"_j)
            ->append(u"syncMinQuietTime = "_j)
            ->append(static_cast< int32_t >((syncMinQuietTime / SECONDS)))
            ->append(u" sec\n"_j)
            ->append(u"syncBloomFilter = "_j)
            ->append(syncBloomFilterNumHashes)
            ->append(u" hashes, "_j)
            ->append(syncBloomFilterBitsPerKey)
            ->append(u" bpk\n"_j)
            ->append(u"syncPartnersPerTrial = "_j)
            ->append(syncPartnersPerTrial)
            ->append(u"\n"_j)
            ->append(u"syncInterval = "_j)
            ->append(static_cast< int32_t >((syncInterval / MINUTES)))
            ->append(u" min\n"_j)
            ->append(u"syncMaxFragments = "_j)
            ->append(syncMaxFragments)
            ->append(u"\n"_j)
            ->append(u"fragmentRequestMaxAttempts = "_j)
            ->append(fragmentRequestMaxAttempts)
            ->append(u"\n"_j)
            ->append(u"fragmentRequestTimeoutDefault = "_j)
            ->append(static_cast< int32_t >((fragmentRequestTimeoutDefault / SECONDS)))
            ->append(u" sec\n"_j)
            ->append(u"manifestRequestTimeout = "_j)
            ->append(static_cast< int32_t >((manifestRequestTimeout / SECONDS)))
            ->append(u" sec\n"_j)
            ->append(u"manifestBurst = "_j)
            ->append(manifestRequestInitialBurst)
            ->append(u" -> "_j)
            ->append(manifestRequestRetryBurst)
            ->append(u"\n"_j)
            ->append(u"manifestAggregationFactor = "_j)
            ->append(manifestAggregationFactor)
            ->append(u"\n"_j)
            ->append(u"overallRestoreTimeout = "_j)
            ->append(static_cast< int32_t >((overallRestoreTimeout / SECONDS)))
            ->append(u" sec\n"_j)
            ->append(u"handoffDelayAfterJoin = "_j)
            ->append(static_cast< int32_t >((handoffDelayAfterJoin / SECONDS)))
            ->append(u" sec\n"_j)
            ->append(u"handoffInterval = "_j)
            ->append(static_cast< int32_t >((handoffInterval / SECONDS)))
            ->append(u" sec\n"_j)
            ->append(u"handoffMaxFragments = "_j)
            ->append(handoffMaxFragments)
            ->append(u"\n"_j)
            ->append(u"garbageCollectionInterval = "_j)
            ->append(static_cast< int32_t >((garbageCollectionInterval / MINUTES)))
            ->append(u" min\n"_j)
            ->append(u"garbageCollectionMaxFragmentsPerRun = "_j)
            ->append(garbageCollectionMaxFragmentsPerRun)
            ->append(u"\n"_j)
            ->append(u"localScanInterval = "_j)
            ->append(static_cast< int32_t >((localScanInterval / MINUTES)))
            ->append(u" min\n"_j)
            ->append(u"localScanMaxFragmentsPerRun = "_j)
            ->append(localScanMaxFragmentsPerRun)
            ->append(u"\n"_j)
            ->append(u"restoreMaxRequestFactor = "_j)
            ->append(restoreMaxRequestFactor)
            ->append(u"\n"_j)
            ->append(u"restoreMaxBoosts = "_j)
            ->append(restoreMaxBoosts)
            ->append(u"\n"_j)
            ->append(u"rateLimitedCheckInterval = "_j)
            ->append(static_cast< int32_t >((rateLimitedCheckInterval / SECONDS)))
            ->append(u" sec\n"_j)
            ->append(u"rateLimitedRequestsPerSecond = "_j)
            ->append(rateLimitedRequestsPerSecond)
            ->append(u"\n"_j)->toString();
    }
    if(npc(cmd)->startsWith(u"flush"_j) && faultInjectionEnabled) {
        auto keyset = java_cast< ::rice::p2p::glacier::FragmentKeySet* >(npc(fragmentStorage)->scan());
        auto iter = npc(keyset)->getIterator();
        while (npc(iter)->hasNext()) {
            auto thisKey = java_cast< ::rice::p2p::glacier::FragmentKey* >(java_cast< ::java::lang::Object* >(npc(iter)->next()));
            npc(fragmentStorage)->unstore(thisKey, new GlacierImpl_handleDebugCommand_10(this));
        }
        return ::java::lang::StringBuilder().append(npc(keyset)->numElements())->append(u" objects deleted\n"_j)->toString();
    }
    if(npc(cmd)->startsWith(u"refresh"_j)) {
        auto args = npc(cmd)->substring(8);
        auto expirationArg = npc(args)->substring(npc(args)->lastIndexOf(static_cast< int32_t >(u' ')) + int32_t(1));
        auto keyArg = npc(args)->substring(0, npc(args)->lastIndexOf(static_cast< int32_t >(u' ')));
        auto id = npc(factory)->buildIdFromToString(keyArg);
        auto expiration = npc(npc(environment)->getTimeSource())->currentTimeMillis() + ::java::lang::Long::parseLong(expirationArg);
        auto const ret = new ::java::lang::StringArray({static_cast< ::java::lang::String* >(nullptr)});
        refresh(new ::rice::p2p::commonapi::IdArray({id}), expiration, static_cast< ::rice::Continuation* >(new GlacierImpl_handleDebugCommand_11(this, ret)));
        while ((*ret)[int32_t(0)] == nullptr) 
                        ::java::lang::Thread::yield();

        return ::java::lang::StringBuilder().append(u"refresh("_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u", "_j)
            ->append(expiration)
            ->append(u")="_j)
            ->append((*ret)[int32_t(0)])->toString();
    }
    if(npc(cmd)->startsWith(u"neighbors"_j)) {
        auto const iter = npc(npc(neighborStorage)->scan())->getIterator();
        auto const result = new ::java::lang::StringBuffer();
        auto const now = (npc(cmd)->indexOf(u"-r"_j) < 0) ? static_cast< int64_t >(int32_t(0)) : npc(npc(environment)->getTimeSource())->currentTimeMillis();
        auto const ret = new ::java::lang::StringArray({static_cast< ::java::lang::String* >(nullptr)});
        npc(result)->append(::java::lang::StringBuilder().append(npc(npc(neighborStorage)->scan())->numElements())->append(u" neighbor(s)\n"_j)->toString());
        ::rice::Continuation* c = new GlacierImpl_handleDebugCommand_12(this, result, now, iter, ret);
        npc(c)->receiveResult(nullptr);
        while ((*ret)[int32_t(0)] == nullptr) 
                        ::java::lang::Thread::yield();

        npc(result)->append(::java::lang::StringBuilder().append((*ret)[int32_t(0)])->append(u"\n"_j)->toString());
        return npc(result)->toString();
    }
    if(npc(cmd)->startsWith(u"status"_j)) {
        auto result = u""_j;
        result = ::java::lang::StringBuilder().append(result)->append(u"Responsible for: "_j)
            ->append(static_cast< ::java::lang::Object* >(responsibleRange))
            ->append(u"\n"_j)->toString();
        result = ::java::lang::StringBuilder().append(result)->append(u"Local time: "_j)
            ->append(static_cast< ::java::lang::Object* >((new ::java::util::Date())))
            ->append(u"\n\n"_j)->toString();
        result = ::java::lang::StringBuilder().append(result)->append(npc(npc(fragmentStorage)->scan())->numElements())
            ->append(u" fragments\n"_j)->toString();
        result = ::java::lang::StringBuilder().append(result)->append(npc(npc(neighborStorage)->scan())->numElements())
            ->append(u" neighbors\n"_j)->toString();
        result = ::java::lang::StringBuilder().append(result)->append(npc(continuations)->size())
            ->append(u" active continuations\n"_j)->toString();
        result = ::java::lang::StringBuilder().append(result)->append(npc(pendingTraffic)->size())
            ->append(u" pending requests\n"_j)->toString();
        return result;
    }
    if(npc(cmd)->startsWith(u"insert"_j) && faultInjectionEnabled) {
        auto args = npc(cmd)->substring(7);
        auto expirationArg = npc(args)->substring(npc(args)->lastIndexOf(static_cast< int32_t >(u' ')) + int32_t(1));
        auto numObjectsArg = npc(args)->substring(0, npc(args)->lastIndexOf(static_cast< int32_t >(u' ')));
        auto const numObjects = ::java::lang::Integer::parseInt(numObjectsArg);
        auto const lifetime = ::java::lang::Integer::parseInt(expirationArg);
        auto result = u""_j;
        for (auto i = int32_t(0); i < numObjects; i++) {
            auto const randomID = npc(factory)->buildRandomId(npc(environment)->getRandomSource());
            result = ::java::lang::StringBuilder().append(result)->append(npc(randomID)->toStringFull())
                ->append(u"\n"_j)->toString();
            npc(pendingTraffic)->put(static_cast< ::java::lang::Object* >(new ::rice::p2p::glacier::VersionKey(randomID, static_cast< int64_t >(int32_t(0)))), static_cast< ::java::lang::Object* >(new GlacierImpl_handleDebugCommand_13(this, randomID, lifetime)));
        }
        return ::java::lang::StringBuilder().append(result)->append(numObjects)
            ->append(u" object(s) with lifetime "_j)
            ->append(lifetime)
            ->append(u"ms created\n"_j)->toString();
    }
    if(npc(cmd)->startsWith(u"delete"_j) && faultInjectionEnabled) {
        auto vkeyS = npc(npc(cmd)->substring(7))->split(u"[v#]"_j);
        auto key = npc(factory)->buildIdFromToString((*vkeyS)[int32_t(0)]);
        auto version = ::java::lang::Long::parseLong((*vkeyS)[int32_t(1)]);
        auto vkey = new ::rice::p2p::glacier::VersionKey(key, version);
        auto id = new ::rice::p2p::glacier::FragmentKey(vkey, ::java::lang::Integer::parseInt((*vkeyS)[int32_t(2)]));
        auto const ret = new ::java::lang::StringArray({static_cast< ::java::lang::String* >(nullptr)});
        npc(fragmentStorage)->unstore(id, new GlacierImpl_handleDebugCommand_14(this, ret));
        while ((*ret)[int32_t(0)] == nullptr) 
                        ::java::lang::Thread::yield();

        return ::java::lang::StringBuilder().append(u"delete("_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u")="_j)
            ->append((*ret)[int32_t(0)])->toString();
    }
    if(npc(cmd)->startsWith(u"burst"_j) && faultInjectionEnabled) {
        auto vkeyS = npc(npc(cmd)->substring(6))->split(u"[v#]"_j);
        auto key = npc(factory)->buildIdFromToString((*vkeyS)[int32_t(0)]);
        auto version = ::java::lang::Long::parseLong((*vkeyS)[int32_t(1)]);
        auto vkey = new ::rice::p2p::glacier::VersionKey(key, version);
        auto const id = new ::rice::p2p::glacier::FragmentKey(vkey, ::java::lang::Integer::parseInt((*vkeyS)[int32_t(2)]));
        auto const fragmentLoc = getFragmentLocation(id);
        auto const ret = new ::java::lang::StringArray({u""_j});
        auto const done = new ::java::lang::BooleanArray({static_cast< ::java::lang::Boolean* >(nullptr)});
        auto const now = npc(npc(environment)->getTimeSource())->currentTimeMillis();
        addContinuation(new GlacierImpl_handleDebugCommand_15(this, fragmentLoc, id, ret, now, done));
        while ((*done)[int32_t(0)] == nullptr) 
                        ::java::lang::Thread::yield();

        return ::java::lang::StringBuilder().append(u"burst("_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u")="_j)
            ->append((*ret)[int32_t(0)])->toString();
    }
    if(npc(cmd)->startsWith(u"manifest"_j)) {
        auto vkeyS = npc(npc(cmd)->substring(9))->split(u"v"_j);
        auto key = npc(factory)->buildIdFromToString((*vkeyS)[int32_t(0)]);
        auto version = ::java::lang::Long::parseLong((*vkeyS)[int32_t(1)]);
        auto vkey = new ::rice::p2p::glacier::VersionKey(key, version);
        auto const ret = new ::java::lang::StringArray({static_cast< ::java::lang::String* >(nullptr)});
        retrieveManifest(vkey, tagDebug, new GlacierImpl_handleDebugCommand_16(this, ret));
        while ((*ret)[int32_t(0)] == nullptr) 
                        ::java::lang::Thread::yield();

        return ::java::lang::StringBuilder().append(u"manifest("_j)->append(static_cast< ::java::lang::Object* >(vkey))
            ->append(u")="_j)
            ->append((*ret)[int32_t(0)])->toString();
    }
    if(npc(cmd)->startsWith(u"retrieve"_j)) {
        auto vkeyS = npc(npc(cmd)->substring(9))->split(u"[v#]"_j);
        auto key = npc(factory)->buildIdFromToString((*vkeyS)[int32_t(0)]);
        auto version = ::java::lang::Long::parseLong((*vkeyS)[int32_t(1)]);
        auto vkey = new ::rice::p2p::glacier::VersionKey(key, version);
        auto const id = new ::rice::p2p::glacier::FragmentKey(vkey, ::java::lang::Integer::parseInt((*vkeyS)[int32_t(2)]));
        auto const metadata = java_cast< FragmentMetadata* >(npc(fragmentStorage)->getMetadata(id));
        auto const ret = new ::java::lang::StringArray({static_cast< ::java::lang::String* >(nullptr)});
        npc(fragmentStorage)->getObject(id, new GlacierImpl_handleDebugCommand_17(this, ret, id, metadata));
        while ((*ret)[int32_t(0)] == nullptr) 
                        ::java::lang::Thread::yield();

        return ::java::lang::StringBuilder().append(u"retrieve("_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u")="_j)
            ->append((*ret)[int32_t(0)])->toString();
    }
    if(npc(cmd)->startsWith(u"validate"_j)) {
        auto keyset = java_cast< ::rice::p2p::glacier::FragmentKeySet* >(npc(fragmentStorage)->scan());
        auto const iter = npc(keyset)->getIterator();
        auto const result = new ::java::lang::StringBuffer();
        npc(result)->append(::java::lang::StringBuilder().append(npc(keyset)->numElements())->append(u" fragment(s)\n"_j)->toString());
        auto const ret = new ::java::lang::StringArray({static_cast< ::java::lang::String* >(nullptr)});
        if(npc(iter)->hasNext()) {
            auto const thisKey = java_cast< ::rice::p2p::glacier::FragmentKey* >(java_cast< ::java::lang::Object* >(npc(iter)->next()));
            npc(fragmentStorage)->getObject(thisKey, new GlacierImpl_handleDebugCommand_18(this, thisKey, result, iter, ret));
            while ((*ret)[int32_t(0)] == nullptr) 
                                ::java::lang::Thread::yield();

            return ::java::lang::StringBuilder().append(u"validate="_j)->append((*ret)[int32_t(0)])
                ->append(u"\n\n"_j)
                ->append(npc(result)->toString())->toString();
        }
        return ::java::lang::StringBuilder().append(u"validate: no objects\n\n"_j)->append(npc(result)->toString())->toString();
    }
    if(npc(cmd)->startsWith(u"fetch"_j)) {
        auto vkeyS = npc(npc(cmd)->substring(6))->split(u"[v#]"_j);
        auto key = npc(factory)->buildIdFromToString((*vkeyS)[int32_t(0)]);
        auto version = ::java::lang::Long::parseLong((*vkeyS)[int32_t(1)]);
        auto vkey = new ::rice::p2p::glacier::VersionKey(key, version);
        auto const id = new ::rice::p2p::glacier::FragmentKey(vkey, ::java::lang::Integer::parseInt((*vkeyS)[int32_t(2)]));
        auto const now = npc(npc(environment)->getTimeSource())->currentTimeMillis();
        auto const fragmentLoc = getFragmentLocation(id);
        auto const ret = new ::java::lang::StringArray({static_cast< ::java::lang::String* >(nullptr)});
        addContinuation(new GlacierImpl_handleDebugCommand_19(this, fragmentLoc, id, ret, now));
        while (((*ret)[int32_t(0)] == nullptr) && (npc(npc(environment)->getTimeSource())->currentTimeMillis() < (now + int32_t(5) * SECONDS))) 
                        ::java::lang::Thread::yield();

        if((*ret)[int32_t(0)] == nullptr)
            ret->set(int32_t(0), u"Timeout"_j);

        return ::java::lang::StringBuilder().append(u"fetch("_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u"@"_j)
            ->append(static_cast< ::java::lang::Object* >(fragmentLoc))
            ->append(u")="_j)
            ->append((*ret)[int32_t(0)])->toString();
    }
    return nullptr;
}

void rice::p2p::glacier::v2::GlacierImpl::insert(::rice::p2p::past::PastContent* obj, ::rice::Continuation* command)
{
    insert(obj, ::rice::p2p::past::gc::GCPast::INFINITY_EXPIRATION, command);
}

void rice::p2p::glacier::v2::GlacierImpl::refresh(::rice::p2p::commonapi::IdArray* ids, ::int64_tArray* expirations, ::rice::Continuation* command)
{
    auto versions = new ::int64_tArray(npc(ids)->length);
    ::java::util::Arrays::fill(versions, static_cast< int64_t >(int32_t(0)));
    refresh(ids, versions, expirations, command);
}

void rice::p2p::glacier::v2::GlacierImpl::refresh(::rice::p2p::commonapi::IdArray* ids, int64_t expiration, ::rice::Continuation* command)
{
    auto expirations = new ::int64_tArray(npc(ids)->length);
    ::java::util::Arrays::fill(expirations, expiration);
    refresh(ids, expirations, command);
}

void rice::p2p::glacier::v2::GlacierImpl::refresh(::rice::p2p::commonapi::IdArray* ids, ::int64_tArray* versions, ::int64_tArray* expirations, ::rice::Continuation* command)
{
    if(!enableBulkRefresh) {
        auto const mc = new ::rice::Continuation_MultiContinuation(command, npc(ids)->length);
        for (auto i = int32_t(0); i < npc(ids)->length; i++) {
            auto const thisContinuation = npc(mc)->getSubContinuation(i);
            auto const thisId = (*ids)[i];
            auto const thisVersion = (*versions)[i];
            auto const thisExpiration = (*expirations)[i];
            if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(logger)->log(::java::lang::StringBuilder().append(u"refresh("_j)->append(npc(thisId)->toStringFull())
                    ->append(u"v"_j)
                    ->append(thisVersion)
                    ->append(u", exp="_j)
                    ->append(thisExpiration)
                    ->append(u")"_j)->toString());

            auto const thisVersionKey = new ::rice::p2p::glacier::VersionKey(thisId, thisVersion);
            auto prev = java_cast< ::rice::Continuation* >(java_cast< ::java::lang::Object* >(npc(pendingTraffic)->put(static_cast< ::java::lang::Object* >(thisVersionKey), static_cast< ::java::lang::Object* >(new GlacierImpl_refresh_20(this, thisVersionKey, thisId, thisVersion, thisExpiration, thisContinuation)))));
            if(prev != nullptr)
                npc(prev)->receiveException(new ::rice::p2p::glacier::GlacierException(u"Key collision in traffic shaper (refresh)"_j));

        }
    } else {
        addContinuation(new GlacierImpl_refresh_21(this, ids, versions, command, expirations));
    }
}

void rice::p2p::glacier::v2::GlacierImpl::distribute(::rice::p2p::glacier::VersionKey* key, ::rice::p2p::glacier::FragmentArray* fragments, ManifestArray* manifests, int64_t expiration, char16_t tag, ::rice::Continuation* command)
{
    auto const tStart = npc(npc(environment)->getTimeSource())->currentTimeMillis();
    addContinuation(new GlacierImpl_distribute_22(this, fragments, key, tag, manifests, expiration, command, tStart));
}

void rice::p2p::glacier::v2::GlacierImpl::insert(::rice::p2p::past::PastContent* obj, int64_t expiration, ::rice::Continuation* command)
{
    auto theVersion = (dynamic_cast< ::rice::p2p::past::gc::GCPastContent* >(obj) != nullptr) ? npc((java_cast< ::rice::p2p::past::gc::GCPastContent* >(obj)))->getVersion() : static_cast< int64_t >(int32_t(0));
    auto const vkey = new ::rice::p2p::glacier::VersionKey(npc(obj)->getId(), theVersion);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"insert("_j)->append(static_cast< ::java::lang::Object* >(obj))
            ->append(u" (id="_j)
            ->append(npc(vkey)->toStringFull())
            ->append(u", mutable="_j)
            ->append(npc(obj)->isMutable())
            ->append(u")"_j)->toString());

    npc(endpoint)->process(new GlacierImpl_insert_23(this, obj), new GlacierImpl_insert_24(this, command, vkey, obj, expiration));
}

void rice::p2p::glacier::v2::GlacierImpl::timerExpired()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(u"Timer expired"_j);

    auto foundTerminated = false;
    int64_t earliestTimeout;
    int32_t numDelete;
    do {
        auto now = npc(npc(environment)->getTimeSource())->currentTimeMillis();
        auto deleteList = new ::int32_tArray(int32_t(100));
        numDelete = 0;
        earliestTimeout = -int32_t(1);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Timer run at "_j)->append(now)->toString());

        auto enu = npc(continuations)->elements();
        while (npc(enu)->hasMoreElements()) {
            auto gc = java_cast< GlacierContinuation* >(java_cast< ::java::lang::Object* >(npc(enu)->nextElement()));
            auto currentTimeout = npc(gc)->getTimeout();
            if(!npc(gc)->hasTerminated() && currentTimeout < (now + int32_t(1) * SECONDS)) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Timer: Resuming ["_j)->append(static_cast< ::java::lang::Object* >(gc))
                        ->append(u"]"_j)->toString());

                npc(gc)->syncTimeoutExpired();
                if(!npc(gc)->hasTerminated() && (npc(gc)->getTimeout() <= currentTimeout))
                    panic(::java::lang::StringBuilder().append(u"Continuation does not set new timeout: "_j)->append(static_cast< ::java::lang::Object* >(gc))->toString());

            }
            if(!npc(gc)->hasTerminated()) {
                if((earliestTimeout == -int32_t(1)) || (npc(gc)->getTimeout() < earliestTimeout))
                    earliestTimeout = npc(gc)->getTimeout();

            } else {
                if(numDelete < 100)
                    (*deleteList)[numDelete++] = npc(gc)->getMyUID();

            }
        }
        if(numDelete > 0) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Deleting "_j)->append(numDelete)
                    ->append(u" expired continuations"_j)->toString());

            for (auto i = int32_t(0); i < numDelete; i++) 
                                npc(continuations)->remove(static_cast< ::java::lang::Object* >(new ::java::lang::Integer((*deleteList)[i])));

        }
    } while ((numDelete == 100) || ((earliestTimeout >= 0) && (earliestTimeout < npc(npc(environment)->getTimeSource())->currentTimeMillis())));
    if(earliestTimeout >= 0) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Next timeout is at "_j)->append(earliestTimeout)->toString());

        setTimer(static_cast< int32_t >(::java::lang::Math::max(earliestTimeout - npc(npc(environment)->getTimeSource())->currentTimeMillis(), int32_t(1) * SECONDS)));
    } else if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(u"No more timeouts"_j);

}

void rice::p2p::glacier::v2::GlacierImpl::neighborSeen(::rice::p2p::commonapi::Id* nodeId, int64_t when)
{
    if(npc(nodeId)->equals(npc(getLocalNodeHandle())->getId()))
        return;

    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Neighbor "_j)->append(static_cast< ::java::lang::Object* >(nodeId))
            ->append(u" was seen at "_j)
            ->append(when)->toString());

    if(when > npc(npc(environment)->getTimeSource())->currentTimeMillis()) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Neighbor: "_j)->append(when)
                ->append(u" is in the future (now="_j)
                ->append(npc(npc(environment)->getTimeSource())->currentTimeMillis())
                ->append(u")"_j)->toString());

        when = npc(npc(environment)->getTimeSource())->currentTimeMillis();
    }
    auto const fNodeId = nodeId;
    auto const fWhen = when;
    npc(neighborStorage)->getObject(nodeId, new GlacierImpl_neighborSeen_25(this, fNodeId, fWhen));
}

bool rice::p2p::glacier::v2::GlacierImpl::forward(::rice::p2p::commonapi::RouteMessage* message)
{
    return true;
}

void rice::p2p::glacier::v2::GlacierImpl::update(::rice::p2p::commonapi::NodeHandle* handle, bool joined)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Leafset update: "_j)->append(static_cast< ::java::lang::Object* >(handle))
            ->append(u" has "_j)
            ->append((joined ? u"joined"_j : u"left"_j))->toString());

    if(!joined)
        return;

    neighborSeen(npc(handle)->getId(), npc(npc(environment)->getTimeSource())->currentTimeMillis());
}

void rice::p2p::glacier::v2::GlacierImpl::lookupHandle(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* handle, ::rice::Continuation* command)
{
    npc(command)->receiveException(new ::java::lang::UnsupportedOperationException(u"LookupHandle() is not supported on Glacier"_j));
}

void rice::p2p::glacier::v2::GlacierImpl::lookupHandles(::rice::p2p::commonapi::Id* id, int32_t num, ::rice::Continuation* command)
{
    lookupHandles(id, static_cast< int64_t >(int32_t(0)), num, command);
}

void rice::p2p::glacier::v2::GlacierImpl::lookupHandles(::rice::p2p::commonapi::Id* id, int64_t version, int32_t num, ::rice::Continuation* command)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"lookupHandles("_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u"v"_j)
            ->append(version)
            ->append(u", n="_j)
            ->append(num)
            ->append(u")"_j)->toString());

    retrieveManifest(new ::rice::p2p::glacier::VersionKey(id, version), tagLookupHandles, new GlacierImpl_lookupHandles_26(this, id, command, version));
}

void rice::p2p::glacier::v2::GlacierImpl::lookup(::rice::p2p::commonapi::Id* id, int64_t version, ::rice::Continuation* command)
{
    auto vkey = new ::rice::p2p::glacier::VersionKey(id, version);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"lookup("_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u"v"_j)
            ->append(version)
            ->append(u")"_j)->toString());

    retrieveObject(vkey, nullptr, true, tagLookup, command);
}

void rice::p2p::glacier::v2::GlacierImpl::lookup(::rice::p2p::commonapi::Id* id, bool cache, ::rice::Continuation* command)
{
    lookup(id, static_cast< int64_t >(int32_t(0)), command);
}

void rice::p2p::glacier::v2::GlacierImpl::lookup(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command)
{
    lookup(id, static_cast< int64_t >(int32_t(0)), command);
}

void rice::p2p::glacier::v2::GlacierImpl::fetch(::rice::p2p::past::PastContentHandle* handle, ::rice::Continuation* command)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"fetch("_j)->append(static_cast< ::java::lang::Object* >(npc(handle)->getId()))
            ->append(u")"_j)->toString());

    if(!(dynamic_cast< GlacierContentHandle* >(handle) != nullptr)) {
        npc(command)->receiveException(new ::rice::p2p::glacier::GlacierException(u"Unknown handle type"_j));
        return;
    }
    auto gch = java_cast< GlacierContentHandle* >(handle);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"exact: fetch("_j)->append(static_cast< ::java::lang::Object* >(npc(gch)->getId()))
            ->append(u"v"_j)
            ->append(npc(gch)->getVersion())
            ->append(u")"_j)->toString());

    retrieveObject(new ::rice::p2p::glacier::VersionKey(npc(gch)->getId(), npc(gch)->getVersion()), npc(gch)->getManifest(), true, tagFetch, command);
}

void rice::p2p::glacier::v2::GlacierImpl::retrieveManifest(::rice::p2p::glacier::VersionKey* key, char16_t tag, ::rice::Continuation* command)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"retrieveManifest(key="_j)->append(static_cast< ::java::lang::Object* >(key))
            ->append(u" tag="_j)
            ->append(tag)
            ->append(u")"_j)->toString());

    addContinuation(new GlacierImpl_retrieveManifest_27(this, key, tag, command));
}

void rice::p2p::glacier::v2::GlacierImpl::retrieveObject(::rice::p2p::glacier::VersionKey* key, Manifest* manifest, bool beStrict, char16_t tag, ::rice::Continuation* c)
{
    addContinuation(new GlacierImpl_retrieveObject_28(this, key, manifest, c, tag, beStrict));
}

void rice::p2p::glacier::v2::GlacierImpl::retrieveFragment(::rice::p2p::glacier::FragmentKey* key, Manifest* manifest, char16_t tag, GlacierContinuation* c)
{
    ::rice::Continuation* const c2 = new GlacierImpl_retrieveFragment_29(this, manifest, key, c, tag);
    if(trashStorage != nullptr) {
        npc(trashStorage)->getObject(key, new GlacierImpl_retrieveFragment_30(this, key, c2));
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"retrieveFragment: Key "_j)->append(npc(key)->toStringFull())
                ->append(u" not found in trash"_j)->toString());

        npc(c2)->receiveResult(nullptr);
    }
}

void rice::p2p::glacier::v2::GlacierImpl::rateLimitedRetrieveFragment(::rice::p2p::glacier::FragmentKey* key, Manifest* manifest, char16_t tag, GlacierContinuation* c)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"rateLimitedRetrieveFragment("_j)->append(static_cast< ::java::lang::Object* >(key))
            ->append(u")"_j)->toString());

    if(npc(pendingTraffic)->containsKey(static_cast< ::java::lang::Object* >(key))) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(u"Fragment is already being retrieved -- discarding request"_j);

        return;
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Added pending job: retrieveFragment("_j)->append(static_cast< ::java::lang::Object* >(key))
            ->append(u")"_j)->toString());

    auto prev = java_cast< ::rice::Continuation* >(java_cast< ::java::lang::Object* >(npc(pendingTraffic)->put(static_cast< ::java::lang::Object* >(key), static_cast< ::java::lang::Object* >(new GlacierImpl_rateLimitedRetrieveFragment_31(this, key, manifest, tag, c)))));
    if(prev != nullptr)
        npc(prev)->receiveException(new ::rice::p2p::glacier::GlacierException(u"Key collision in traffic shaper (rateLimitedRetrieveFragment)"_j));

}

rice::p2p::commonapi::IdArrayArray* rice::p2p::glacier::v2::GlacierImpl::getNeighborRanges()
{
    auto iter = npc(npc(neighborStorage)->scan())->getIterator();
    auto ccwIDs = new ::java::util::Vector();
    auto cwIDs = new ::java::util::Vector();
    auto myID = npc(getLocalNodeHandle())->getId();
    while (npc(iter)->hasNext()) {
        auto thisNeighbor = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(iter)->next()));
        if(npc(myID)->clockwise(thisNeighbor))
            npc(cwIDs)->add(static_cast< ::java::lang::Object* >(thisNeighbor));
        else
            npc(ccwIDs)->add(static_cast< ::java::lang::Object* >(thisNeighbor));
    }
    for (auto j = int32_t(0); j < 2; j++) {
        auto v = (j == 0) ? cwIDs : ccwIDs;
        auto madeProgress = true;
        while (madeProgress) {
            madeProgress = false;
            for (auto i = int32_t(0); i < (npc(v)->size() - int32_t(1)); i++) {
                if(npc((java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(v)->elementAt(i + int32_t(1))))))->clockwise(java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(v)->elementAt(i))))) {
                    auto h = java_cast< ::java::lang::Object* >(npc(v)->elementAt(i));
                    npc(v)->setElementAt(java_cast< ::java::lang::Object* >(npc(v)->elementAt(i + int32_t(1))), i);
                    npc(v)->setElementAt(h, i + int32_t(1));
                    madeProgress = true;
                }
            }
        }
    }
    auto allIDs = new ::java::util::Vector();
    npc(allIDs)->addAll(static_cast< ::java::util::Collection* >(ccwIDs));
    npc(allIDs)->add(static_cast< ::java::lang::Object* >(myID));
    npc(allIDs)->addAll(static_cast< ::java::util::Collection* >(cwIDs));
    auto result = new ::rice::p2p::commonapi::IdArrayArray(npc(allIDs)->size());
    for (auto i = int32_t(0); i < npc(allIDs)->size(); i++) {
        auto currentElement = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(allIDs)->elementAt(i)));
        ::rice::p2p::commonapi::Id* cwId;
        ::rice::p2p::commonapi::Id* ccwId;
        if(i > 0) {
            auto previousElement = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(allIDs)->elementAt(i - int32_t(1))));
            ccwId = npc(previousElement)->addToId(npc(npc(previousElement)->distanceFromId(currentElement))->shiftDistance(1, 0));
        } else {
            ccwId = currentElement;
        }
        if(i < (npc(allIDs)->size() - int32_t(1))) {
            auto nextElement = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(allIDs)->elementAt(i + int32_t(1))));
            cwId = npc(currentElement)->addToId(npc(npc(currentElement)->distanceFromId(nextElement))->shiftDistance(1, 0));
        } else {
            cwId = currentElement;
        }
        (*result)[i]->set(int32_t(0), ccwId);
        (*result)[i]->set(int32_t(1), currentElement);
        (*result)[i]->set(int32_t(2), cwId);
    }
    return result;
}

void rice::p2p::glacier::v2::GlacierImpl::deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message)
{
    auto const msg = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierMessage* >(message);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Received message "_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" with destination "_j)
            ->append(static_cast< ::java::lang::Object* >(id))
            ->append(u" from "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(npc(msg)->getSource())->getId()))->toString());

    if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierDataMessage* >(msg) != nullptr) {
        auto gdm = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierDataMessage* >(msg);
        int64_t thisSize = int32_t(1000);
        updateTokenBucket();
        for (auto i = int32_t(0); i < npc(gdm)->numKeys(); i++) {
            if(npc(gdm)->getFragment(i) != nullptr)
                thisSize += npc(npc(npc(gdm)->getFragment(i))->getPayload())->length;

            if(npc(gdm)->getManifest(i) != nullptr)
                thisSize += numFragments * int32_t(21);

        }
        tokenBucket -= thisSize;
        bucketConsumed += thisSize;
        if(bucketMin > tokenBucket)
            bucketMin = tokenBucket;

        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Token bucket contains "_j)->append(tokenBucket)
                ->append(u" tokens (consumed "_j)
                ->append(thisSize)
                ->append(u")"_j)->toString());

    }
    if(npc(msg)->isResponse()) {
        auto gc = java_cast< GlacierContinuation* >(java_cast< ::java::lang::Object* >(npc(continuations)->get(static_cast< ::java::lang::Object* >(new ::java::lang::Integer(npc(msg)->getUID())))));
        if(gc != nullptr) {
            if(!npc(gc)->terminated) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Resuming ["_j)->append(static_cast< ::java::lang::Object* >(gc))
                        ->append(u"]"_j)->toString());

                npc(gc)->syncReceiveResult(msg);
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(u"---"_j);

            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Message UID#"_j)->append(npc(msg)->getUID())
                        ->append(u" is response, but continuation has already terminated"_j)->toString());

            }
        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Unusual: Message UID#"_j)->append(npc(msg)->getUID())
                    ->append(u" is response, but continuation not found"_j)->toString());

        }
        return;
    }
    if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierQueryMessage* >(msg) != nullptr) {
        auto gqm = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierQueryMessage* >(msg);
        auto keyA = new ::rice::p2p::glacier::FragmentKeyArray(npc(gqm)->numKeys());
        auto haveItA = new ::boolArray(npc(gqm)->numKeys());
        auto expirationA = new ::int64_tArray(npc(gqm)->numKeys());
        auto authoritativeA = new ::boolArray(npc(gqm)->numKeys());
        for (auto i = int32_t(0); i < npc(gqm)->numKeys(); i++) {
            auto fragmentLocation = getFragmentLocation(npc(gqm)->getKey(i));
            if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Queried for "_j)->append(static_cast< ::java::lang::Object* >(npc(gqm)->getKey(i)))
                    ->append(u" (at "_j)
                    ->append(static_cast< ::java::lang::Object* >(fragmentLocation))
                    ->append(u")"_j)->toString());

            keyA->set(i, npc(gqm)->getKey(i));
            (*haveItA)[i] = npc(fragmentStorage)->exists(npc(gqm)->getKey(i));
            if((*haveItA)[i]) {
                auto metadata = java_cast< FragmentMetadata* >(npc(fragmentStorage)->getMetadata(npc(gqm)->getKey(i)));
                if(metadata != nullptr) {
                    (*expirationA)[i] = npc(metadata)->getCurrentExpiration();
                } else {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"QUERY cannot read metadata in object "_j)->append(npc(npc(gqm)->getKey(i))->toStringFull())
                            ->append(u", storage returned null"_j)->toString());

                    (*expirationA)[i] = 0;
                    (*haveItA)[i] = false;
                }
            } else {
                (*expirationA)[i] = 0;
            }
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"My range is "_j)->append(static_cast< ::java::lang::Object* >(responsibleRange))->toString());

            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Location is "_j)->append(static_cast< ::java::lang::Object* >(fragmentLocation))->toString());

            (*authoritativeA)[i] = npc(responsibleRange)->containsId(fragmentLocation);
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Result: haveIt="_j)->append((*haveItA)[i])
                    ->append(u" amAuthority="_j)
                    ->append((*authoritativeA)[i])
                    ->append(u" expiration="_j)
                    ->append((*expirationA)[i])->toString());

        }
        sendMessage(nullptr, new ::rice::p2p::glacier::v2::messaging::GlacierResponseMessage(npc(gqm)->getUID(), keyA, haveItA, expirationA, authoritativeA, getLocalNodeHandle(), npc(npc(gqm)->getSource())->getId(), true, npc(gqm)->getTag()), npc(gqm)->getSource());
    } else if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierNeighborRequestMessage* >(msg) != nullptr) {
        auto const gnrm = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierNeighborRequestMessage* >(msg);
        auto const requestedNeighbors = npc(neighborStorage)->scan(npc(gnrm)->getRequestedRange());
        auto const numRequested = npc(requestedNeighbors)->numElements();
        if(numRequested < 1) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(u"No neighbors in that range -- canceled"_j);

            return;
        }
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Neighbor request for "_j)->append(static_cast< ::java::lang::Object* >(npc(gnrm)->getRequestedRange()))
                ->append(u", found "_j)
                ->append(numRequested)
                ->append(u" neighbors"_j)->toString());

        auto const neighbors = new ::rice::p2p::commonapi::IdArray(numRequested);
        auto const lastSeen = new ::int64_tArray(numRequested);
        auto iter = npc(requestedNeighbors)->getIterator();
        for (auto i = int32_t(0); i < numRequested; i++) 
                        neighbors->set(i, java_cast< ::rice::p2p::commonapi::Id* >((java_cast< ::java::lang::Object* >(npc(iter)->next()))));

        npc(neighborStorage)->getObject((*neighbors)[int32_t(0)], new GlacierImpl_deliver_32(this, gnrm, neighbors, lastSeen, numRequested));
        return;
    } else if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierSyncMessage* >(msg) != nullptr) {
        auto const gsm = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierSyncMessage* >(msg);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"SyncRequest from "_j)->append(static_cast< ::java::lang::Object* >(npc(npc(gsm)->getSource())->getId()))
                ->append(u" for "_j)
                ->append(static_cast< ::java::lang::Object* >(npc(gsm)->getRange()))
                ->append(u" offset "_j)
                ->append(npc(gsm)->getOffsetFID())->toString());

        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Contains "_j)->append(static_cast< ::java::lang::Object* >(npc(gsm)->getBloomFilter()))->toString());

        auto iter = npc(npc(fragmentStorage)->scan())->getIterator();
        auto const range = npc(gsm)->getRange();
        auto const offset = npc(gsm)->getOffsetFID();
        auto const bv = npc(gsm)->getBloomFilter();
        auto const earliestAcceptableExpiration = npc(npc(environment)->getTimeSource())->currentTimeMillis() + syncMinRemainingLifetime;
        auto const latestAcceptableStoredSince = npc(npc(environment)->getTimeSource())->currentTimeMillis() - syncMinQuietTime;
        auto const missing = new ::java::util::Vector();
        while (npc(iter)->hasNext()) {
            auto fkey = java_cast< ::rice::p2p::glacier::FragmentKey* >(java_cast< ::java::lang::Object* >(npc(iter)->next()));
            auto thisPos = getFragmentLocation(fkey);
            if(npc(range)->containsId(thisPos)) {
                auto metadata = java_cast< FragmentMetadata* >(npc(fragmentStorage)->getMetadata(fkey));
                if(metadata != nullptr) {
                    if(!npc(bv)->contains(getHashInput(npc(fkey)->getVersionKey(), npc(metadata)->getCurrentExpiration()))) {
                        if(npc(metadata)->getCurrentExpiration() >= earliestAcceptableExpiration) {
                            if(npc(metadata)->getStoredSince() <= latestAcceptableStoredSince) {
                                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                                    npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(fkey))->append(u" @"_j)
                                        ->append(static_cast< ::java::lang::Object* >(thisPos))
                                        ->append(u" - MISSING"_j)->toString());

                                npc(missing)->add(static_cast< ::java::lang::Object* >(fkey));
                                if(npc(missing)->size() >= syncMaxFragments) {
                                    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                                        npc(logger)->log(::java::lang::StringBuilder().append(u"Limit of "_j)->append(syncMaxFragments)
                                            ->append(u" missing fragments reached"_j)->toString());

                                    break;
                                }
                            } else {
                                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                                    npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(fkey))->append(u" @"_j)
                                        ->append(static_cast< ::java::lang::Object* >(thisPos))
                                        ->append(u" - TOO FRESH (stored "_j)
                                        ->append((npc(npc(environment)->getTimeSource())->currentTimeMillis() - npc(metadata)->getStoredSince()))
                                        ->append(u"ms)"_j)->toString());

                            }
                        } else {
                            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                                npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(fkey))->append(u" @"_j)
                                    ->append(static_cast< ::java::lang::Object* >(thisPos))
                                    ->append(u" - EXPIRES SOON (in "_j)
                                    ->append((npc(metadata)->getCurrentExpiration() - npc(npc(environment)->getTimeSource())->currentTimeMillis()))
                                    ->append(u"ms)"_j)->toString());

                        }
                    } else {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                            npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(fkey))->append(u" @"_j)
                                ->append(static_cast< ::java::lang::Object* >(thisPos))
                                ->append(u" - OK"_j)->toString());

                    }
                } else {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"SYNC RESPONSE cannot read metadata in object "_j)->append(npc(fkey)->toStringFull())
                            ->append(u", storage returned null"_j)->toString());

                }
            } else if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(fkey))->append(u" @"_j)
                    ->append(static_cast< ::java::lang::Object* >(thisPos))
                    ->append(u" - OUT OF RANGE"_j)->toString());

        }
        if(npc(missing)->isEmpty()) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(logger)->log(u"No fragments missing. OK. "_j);

            return;
        }
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Sending "_j)->append(npc(missing)->size())
                ->append(u" fragments to "_j)
                ->append(static_cast< ::java::lang::Object* >(npc(npc(gsm)->getSource())->getId()))->toString());

        npc(fragmentStorage)->getObject(java_cast< ::rice::p2p::glacier::FragmentKey* >(java_cast< ::java::lang::Object* >(npc(missing)->elementAt(0))), new GlacierImpl_deliver_33(this, missing, gsm, offset));
        return;
    } else if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierRefreshProbeMessage* >(msg) != nullptr) {
        auto const grpm = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierRefreshProbeMessage* >(msg);
        auto requestedId = npc(grpm)->getRequestedId();
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Refresh probe for "_j)->append(static_cast< ::java::lang::Object* >(requestedId))
                ->append(u" (RR="_j)
                ->append(static_cast< ::java::lang::Object* >(responsibleRange))
                ->append(u")"_j)->toString());

        auto ranges = getNeighborRanges();
        ::rice::p2p::commonapi::IdRange* returnedRange = nullptr;
        auto online = false;
        if(npc(responsibleRange)->containsId(requestedId)) {
            returnedRange = responsibleRange;
            online = true;
        } else {
            online = false;
            for (auto i = int32_t(0); i < npc(ranges)->length; i++) {
                auto thisRange = npc(factory)->buildIdRange((*(*ranges)[i])[int32_t(0)], (*(*ranges)[i])[int32_t(2)]);
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u" - "_j)->append(static_cast< ::java::lang::Object* >(thisRange))
                        ->append(u" ("_j)
                        ->append(static_cast< ::java::lang::Object* >((*(*ranges)[i])[int32_t(1)]))
                        ->append(u")"_j)->toString());

                if(npc(thisRange)->containsId(requestedId))
                    returnedRange = thisRange;

            }
        }
        sendMessage(nullptr, new ::rice::p2p::glacier::v2::messaging::GlacierRefreshResponseMessage(npc(grpm)->getUID(), returnedRange, online, getLocalNodeHandle(), npc(npc(grpm)->getSource())->getId(), npc(grpm)->getTag()), npc(grpm)->getSource());
    } else if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage* >(msg) != nullptr) {
        auto const grpm = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage* >(msg);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"AR Refresh patches received for "_j)->append(npc(grpm)->numKeys())
                ->append(u" keys. Processing..."_j)->toString());

        ::rice::Continuation* c = new GlacierImpl_deliver_34(this, grpm);
        npc(c)->receiveResult(nullptr);
    } else if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierRangeQueryMessage* >(msg) != nullptr) {
        auto const grqm = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierRangeQueryMessage* >(msg);
        auto requestedRange = npc(grqm)->getRequestedRange();
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Range query for "_j)->append(static_cast< ::java::lang::Object* >(requestedRange))->toString());

        auto ranges = getNeighborRanges();
        for (auto i = int32_t(0); i < npc(ranges)->length; i++) {
            auto thisRange = npc(factory)->buildIdRange((*(*ranges)[i])[int32_t(0)], (*(*ranges)[i])[int32_t(2)]);
            auto intersectRange = npc(requestedRange)->intersectRange(thisRange);
            if(!npc(intersectRange)->isEmpty()) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"     - Intersects: "_j)->append(static_cast< ::java::lang::Object* >(intersectRange))
                        ->append(u", sending RangeForward"_j)->toString());

                sendMessage((*(*ranges)[i])[int32_t(1)], new ::rice::p2p::glacier::v2::messaging::GlacierRangeForwardMessage(npc(grqm)->getUID(), requestedRange, npc(grqm)->getSource(), getLocalNodeHandle(), (*(*ranges)[i])[int32_t(1)], npc(grqm)->getTag()), nullptr);
            }
        }
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(u"Finished processing range query"_j);

        return;
    } else if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierRangeForwardMessage* >(msg) != nullptr) {
        auto grfm = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierRangeForwardMessage* >(msg);
        if(!npc(npc(grfm)->getDestination())->equals(npc(getLocalNodeHandle())->getId())) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Glog(Logger.WARNINGNot for us (dest="_j)->append(static_cast< ::java::lang::Object* >(npc(grfm)->getDestination()))
                    ->append(u", we="_j)
                    ->append(static_cast< ::java::lang::Object* >(npc(getLocalNodeHandle())->getId()))->toString());

            return;
        }
        auto commonRange = npc(responsibleRange)->intersectRange(npc(grfm)->getRequestedRange());
        if(!npc(commonRange)->isEmpty()) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Range forward: Returning common range "_j)->append(static_cast< ::java::lang::Object* >(commonRange))
                    ->append(u" to requestor "_j)
                    ->append(static_cast< ::java::lang::Object* >(npc(grfm)->getRequestor()))->toString());

            sendMessage(nullptr, new ::rice::p2p::glacier::v2::messaging::GlacierRangeResponseMessage(npc(grfm)->getUID(), commonRange, getLocalNodeHandle(), npc(npc(grfm)->getRequestor())->getId(), npc(grfm)->getTag()), npc(grfm)->getRequestor());
        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Received GRFM by "_j)->append(static_cast< ::java::lang::Object* >(npc(grfm)->getRequestor()))
                    ->append(u", but no common range??!? -- ignored"_j)->toString());

        }
        return;
    } else if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierFetchMessage* >(msg) != nullptr) {
        auto const gfm = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierFetchMessage* >(msg);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Fetch request for "_j)->append(static_cast< ::java::lang::Object* >(npc(gfm)->getKey(0)))
                ->append(((npc(gfm)->getNumKeys() > 1) ? (::java::lang::StringBuilder().append(u" and "_j)->append((npc(gfm)->getNumKeys() - int32_t(1)))
                    ->append(u" other keys"_j)->toString()) : u""_j))
                ->append(u", request="_j)
                ->append(npc(gfm)->getRequest())->toString());

        npc(fragmentStorage)->getObject(npc(gfm)->getKey(0), new GlacierImpl_deliver_35(this, gfm));
    } else if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierDataMessage* >(msg) != nullptr) {
        auto const gdm = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierDataMessage* >(msg);
        for (auto i = int32_t(0); i < npc(gdm)->numKeys(); i++) {
            auto const thisKey = npc(gdm)->getKey(i);
            auto const thisFragment = npc(gdm)->getFragment(i);
            auto const thisManifest = npc(gdm)->getManifest(i);
            if((thisFragment != nullptr) && (thisManifest != nullptr)) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Data: Fragment+Manifest for "_j)->append(static_cast< ::java::lang::Object* >(thisKey))->toString());

                if(!npc(responsibleRange)->containsId(getFragmentLocation(thisKey))) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Not responsible for "_j)->append(static_cast< ::java::lang::Object* >(thisKey))
                            ->append(u" (at "_j)
                            ->append(static_cast< ::java::lang::Object* >(getFragmentLocation(thisKey)))
                            ->append(u") -- discarding"_j)->toString());

                    continue;
                }
                if(!npc(policy)->checkSignature(thisManifest, npc(thisKey)->getVersionKey())) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(u"Manifest is not signed properly"_j);

                    continue;
                }
                if(!npc(thisManifest)->validatesFragment(thisFragment, npc(thisKey)->getFragmentID(), npc(npc(environment)->getLogManager())->getLogger(Manifest::class_(), instance))) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(u"Manifest does not validate this fragment"_j);

                    continue;
                }
                if(!npc(fragmentStorage)->exists(thisKey)) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(logger)->log(u"Verified ok. Storing locally."_j);

                    auto fam = new FragmentAndManifest(thisFragment, thisManifest);
                    npc(fragmentStorage)->store(thisKey, new FragmentMetadata(npc(thisManifest)->getExpiration(), int32_t(0), npc(npc(environment)->getTimeSource())->currentTimeMillis()), fam, new GlacierImpl_deliver_36(this, thisKey, gdm, thisManifest));
                } else {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(u"We already have a fragment with this key! -- discarding"_j);

                    continue;
                }
                continue;
            }
            if((thisFragment == nullptr) && (thisManifest != nullptr)) {
                if(!npc(responsibleRange)->containsId(getFragmentLocation(thisKey))) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Not responsible for "_j)->append(static_cast< ::java::lang::Object* >(thisKey))
                            ->append(u" (at "_j)
                            ->append(static_cast< ::java::lang::Object* >(getFragmentLocation(thisKey)))
                            ->append(u") -- discarding"_j)->toString());

                    continue;
                }
                if(npc(fragmentStorage)->exists(thisKey)) {
                    auto const metadata = java_cast< FragmentMetadata* >(npc(fragmentStorage)->getMetadata(thisKey));
                    if((metadata == nullptr) || (npc(metadata)->getCurrentExpiration() < npc(thisManifest)->getExpiration())) {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                            npc(logger)->log(::java::lang::StringBuilder().append(u"Replacing old manifest for "_j)->append(static_cast< ::java::lang::Object* >(thisKey))
                                ->append(u" (expires "_j)
                                ->append(((metadata == nullptr) ? u"(broken)"_j : ::java::lang::StringBuilder().append(u""_j)->append(npc(metadata)->getCurrentExpiration())->toString()))
                                ->append(u") by new one (expires "_j)
                                ->append(npc(thisManifest)->getExpiration())
                                ->append(u")"_j)->toString());

                        npc(fragmentStorage)->getObject(thisKey, new GlacierImpl_deliver_37(this, thisKey, thisManifest, metadata, gdm));
                    } else {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                            npc(logger)->log(::java::lang::StringBuilder().append(u"We already have exp="_j)->append(((metadata == nullptr) ? u"(broken)"_j : ::java::lang::StringBuilder().append(u""_j)->append(npc(metadata)->getCurrentExpiration())->toString()))
                                ->append(u", discarding manifest for "_j)
                                ->append(static_cast< ::java::lang::Object* >(thisKey))
                                ->append(u" with exp="_j)
                                ->append(npc(thisManifest)->getExpiration())->toString());

                    }
                    continue;
                }
                if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Data: Manifest for: "_j)->append(static_cast< ::java::lang::Object* >(thisKey))
                        ->append(u", must fetch"_j)->toString());

                auto const tStart = npc(npc(environment)->getTimeSource())->currentTimeMillis();
                rateLimitedRetrieveFragment(thisKey, thisManifest, tagSyncFetch, new GlacierImpl_deliver_38(this, thisKey, thisManifest, tStart));
                continue;
            }
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(u"Case not implemented! -- GDM"_j);

        }
        return;
    } else if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierTimeoutMessage* >(msg) != nullptr) {
        timerExpired();
        return;
    } else {
        panic(::java::lang::StringBuilder().append(u"GLACIER ERROR - Received message "_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" of unknown type."_j)->toString());
    }
}

int32_t rice::p2p::glacier::v2::GlacierImpl::getReplicationFactor()
{
    return 1;
}

rice::p2p::commonapi::NodeHandle* rice::p2p::glacier::v2::GlacierImpl::getLocalNodeHandle()
{
    return npc(endpoint)->getLocalNodeHandle();
}

void rice::p2p::glacier::v2::GlacierImpl::setSyncInterval(int32_t syncIntervalSec)
{
    this->syncInterval = syncIntervalSec * SECONDS;
}

void rice::p2p::glacier::v2::GlacierImpl::setSyncMaxFragments(int32_t syncMaxFragments)
{
    this->syncMaxFragments = syncMaxFragments;
}

void rice::p2p::glacier::v2::GlacierImpl::setRateLimit(int32_t rps)
{
    this->rateLimitedRequestsPerSecond = rps;
}

void rice::p2p::glacier::v2::GlacierImpl::setNeighborTimeout(int64_t neighborTimeoutMin)
{
    this->neighborTimeout = neighborTimeoutMin * MINUTES;
}

void rice::p2p::glacier::v2::GlacierImpl::setBandwidthLimit(int64_t bytesPerSecond, int64_t maxBurst)
{
    this->bucketTokensPerSecond = bytesPerSecond;
    this->bucketMaxBurstSize = maxBurst;
}

int64_t rice::p2p::glacier::v2::GlacierImpl::getTrashSize()
{
    if(trashStorage == nullptr)
        return 0;

    return npc(npc(trashStorage)->getStorage())->getTotalSize();
}

void rice::p2p::glacier::v2::GlacierImpl::emptyTrash(::rice::Continuation* c)
{
    if(trashStorage != nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(u"Emptying trash (removing all objects)"_j);

        npc(trashStorage)->flush(c);
    } else {
        npc(c)->receiveResult(nullptr);
    }
}

void rice::p2p::glacier::v2::GlacierImpl::addStatisticsListener(GlacierStatisticsListener* gsl)
{
    npc(listeners)->add(static_cast< ::java::lang::Object* >(gsl));
}

void rice::p2p::glacier::v2::GlacierImpl::removeStatisticsListener(GlacierStatisticsListener* gsl)
{
    npc(listeners)->removeElement(gsl);
}

rice::environment::Environment* rice::p2p::glacier::v2::GlacierImpl::getEnvironment()
{
    return environment;
}

java::lang::String* rice::p2p::glacier::v2::GlacierImpl::getInstance()
{
    return instance;
}

void rice::p2p::glacier::v2::GlacierImpl::setContentDeserializer(::rice::p2p::past::rawserialization::PastContentDeserializer* deserializer)
{
    contentDeserializer = deserializer;
}

void rice::p2p::glacier::v2::GlacierImpl::setContentHandleDeserializer(::rice::p2p::past::rawserialization::PastContentHandleDeserializer* deserializer)
{
    contentHandleDeserializer = deserializer;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.GlacierImpl", 31);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl::getClass0()
{
    return class_();
}

