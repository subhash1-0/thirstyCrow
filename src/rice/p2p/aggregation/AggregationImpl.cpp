// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Double.hpp>
#include <java/lang/Error.hpp>
#include <java/lang/Exception.hpp>
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
#include <java/util/Enumeration.hpp>
#include <java/util/Hashtable.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/TreeSet.hpp>
#include <java/util/Vector.hpp>
#include <rice/Continuation_MultiContinuation.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/aggregation/Aggregate.hpp>
#include <rice/p2p/aggregation/AggregateDescriptor.hpp>
#include <rice/p2p/aggregation/AggregateFactory.hpp>
#include <rice/p2p/aggregation/AggregateList.hpp>
#include <rice/p2p/aggregation/AggregationDefaultPolicy.hpp>
#include <rice/p2p/aggregation/AggregationException.hpp>
#include <rice/p2p/aggregation/AggregationImpl_lookupHandles_36.hpp>
#include <rice/p2p/aggregation/AggregationImpl_reset_37.hpp>
#include <rice/p2p/aggregation/AggregationImpl_AggregationImpl_3.hpp>
#include <rice/p2p/aggregation/AggregationImpl_handleDebugCommand_4.hpp>
#include <rice/p2p/aggregation/AggregationImpl_handleDebugCommand_5.hpp>
#include <rice/p2p/aggregation/AggregationImpl_handleDebugCommand_6.hpp>
#include <rice/p2p/aggregation/AggregationImpl_handleDebugCommand_7.hpp>
#include <rice/p2p/aggregation/AggregationImpl_handleDebugCommand_8.hpp>
#include <rice/p2p/aggregation/AggregationImpl_handleDebugCommand_9.hpp>
#include <rice/p2p/aggregation/AggregationImpl_handleDebugCommand_10.hpp>
#include <rice/p2p/aggregation/AggregationImpl_handleDebugCommand_11.hpp>
#include <rice/p2p/aggregation/AggregationImpl_handleDebugCommand_12.hpp>
#include <rice/p2p/aggregation/AggregationImpl_handleDebugCommand_13.hpp>
#include <rice/p2p/aggregation/AggregationImpl_handleDebugCommand_14.hpp>
#include <rice/p2p/aggregation/AggregationImpl_storeAggregate_15.hpp>
#include <rice/p2p/aggregation/AggregationImpl_storeAggregate_16.hpp>
#include <rice/p2p/aggregation/AggregationImpl_formAggregates_17.hpp>
#include <rice/p2p/aggregation/AggregationImpl_formAggregates_18.hpp>
#include <rice/p2p/aggregation/AggregationImpl_formAggregates_19.hpp>
#include <rice/p2p/aggregation/AggregationImpl_formAggregates_20.hpp>
#include <rice/p2p/aggregation/AggregationImpl_refreshAggregates_21.hpp>
#include <rice/p2p/aggregation/AggregationImpl_consolidateAggregates_22.hpp>
#include <rice/p2p/aggregation/AggregationImpl_reconnectTree_23.hpp>
#include <rice/p2p/aggregation/AggregationImpl_timerExpired_24.hpp>
#include <rice/p2p/aggregation/AggregationImpl_timerExpired_25.hpp>
#include <rice/p2p/aggregation/AggregationImpl_refresh_26.hpp>
#include <rice/p2p/aggregation/AggregationImpl_refresh_27.hpp>
#include <rice/p2p/aggregation/AggregationImpl_refreshInternal_28.hpp>
#include <rice/p2p/aggregation/AggregationImpl_rebuildRecursive_29.hpp>
#include <rice/p2p/aggregation/AggregationImpl_insert_30.hpp>
#include <rice/p2p/aggregation/AggregationImpl_AggregationImpl_1.hpp>
#include <rice/p2p/aggregation/AggregationImpl_insert_31.hpp>
#include <rice/p2p/aggregation/AggregationImpl_retrieveObjectFromAggregate_32.hpp>
#include <rice/p2p/aggregation/AggregationImpl_lookup_33.hpp>
#include <rice/p2p/aggregation/AggregationImpl_lookup_34.hpp>
#include <rice/p2p/aggregation/AggregationImpl_AggregationImpl_2.hpp>
#include <rice/p2p/aggregation/AggregationImpl_lookup_35.hpp>
#include <rice/p2p/aggregation/AggregationPolicy.hpp>
#include <rice/p2p/aggregation/AggregationStatistics.hpp>
#include <rice/p2p/aggregation/ObjectDescriptor.hpp>
#include <rice/p2p/aggregation/messaging/AggregationMessage.hpp>
#include <rice/p2p/aggregation/messaging/AggregationTimeoutMessage.hpp>
#include <rice/p2p/aggregation/messaging/NonAggregate.hpp>
#include <rice/p2p/aggregation/raw/RawAggregateFactory.hpp>
#include <rice/p2p/commonapi/CancellableTask.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/p2p/glacier/VersioningPast.hpp>
#include <rice/p2p/glacier/v2/DebugContent.hpp>
#include <rice/p2p/glacier/v2/GlacierContentHandle.hpp>
#include <rice/p2p/past/Past.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>
#include <rice/p2p/past/gc/GCPast.hpp>
#include <rice/p2p/past/gc/GCPastContent.hpp>
#include <rice/p2p/past/rawserialization/JavaPastContentDeserializer.hpp>
#include <rice/p2p/past/rawserialization/JavaPastContentHandleDeserializer.hpp>
#include <rice/p2p/past/rawserialization/JavaSerializedPastContent.hpp>
#include <rice/p2p/past/rawserialization/PastContentDeserializer.hpp>
#include <rice/p2p/past/rawserialization/PastContentHandleDeserializer.hpp>
#include <rice/p2p/past/rawserialization/RawPastContent.hpp>
#include <rice/p2p/util/DebugCommandHandler.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
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
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

namespace rice
{
    namespace p2p
    {
        namespace past
        {
typedef ::SubArray< ::rice::p2p::past::PastContent, ::java::lang::ObjectArray, ::java::io::SerializableArray > PastContentArray;

            namespace gc
            {
typedef ::SubArray< ::rice::p2p::past::gc::GCPastContent, ::java::lang::ObjectArray, ::rice::p2p::past::PastContentArray > GCPastContentArray;
            } // gc
        } // past

        namespace aggregation
        {
typedef ::SubArray< ::rice::p2p::aggregation::Aggregate, ::java::lang::ObjectArray, ::rice::p2p::past::gc::GCPastContentArray > AggregateArray;
typedef ::SubArray< ::rice::p2p::aggregation::AggregateDescriptor, ::java::lang::ObjectArray > AggregateDescriptorArray;
typedef ::SubArray< ::rice::p2p::aggregation::ObjectDescriptor, ::java::lang::ObjectArray, ::java::io::SerializableArray, ::java::lang::ComparableArray > ObjectDescriptorArray;
        } // aggregation

        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
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

rice::p2p::aggregation::AggregationImpl::AggregationImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::aggregation::AggregationImpl::AggregationImpl(::rice::p2p::commonapi::Node* node, ::rice::p2p::past::Past* aggregateStore, ::rice::p2p::past::Past* objectStore, ::rice::persistence::StorageManager* waitingList, ::java::lang::String* configFileName, ::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* instance)  /* throws(IOException) */
    : AggregationImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,aggregateStore,objectStore,waitingList,configFileName,factory,instance);
}

rice::p2p::aggregation::AggregationImpl::AggregationImpl(::rice::p2p::commonapi::Node* node, ::rice::p2p::past::Past* aggregateStore, ::rice::p2p::past::Past* objectStore, ::rice::persistence::StorageManager* waitingList, ::java::lang::String* configFileName, ::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* instance, AggregationPolicy* policy, AggregateFactory* aggregateFactory)  /* throws(IOException) */
    : AggregationImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,aggregateStore,objectStore,waitingList,configFileName,factory,instance,policy,aggregateFactory);
}

constexpr char16_t rice::p2p::aggregation::AggregationImpl::tiFlush;

constexpr char16_t rice::p2p::aggregation::AggregationImpl::tiMonitor;

constexpr char16_t rice::p2p::aggregation::AggregationImpl::tiConsolidate;

constexpr char16_t rice::p2p::aggregation::AggregationImpl::tiStatistics;

constexpr char16_t rice::p2p::aggregation::AggregationImpl::tiExpire;

constexpr int64_t rice::p2p::aggregation::AggregationImpl::SECONDS;

constexpr int64_t rice::p2p::aggregation::AggregationImpl::MINUTES;

constexpr int64_t rice::p2p::aggregation::AggregationImpl::HOURS;

constexpr int64_t rice::p2p::aggregation::AggregationImpl::DAYS;

constexpr int64_t rice::p2p::aggregation::AggregationImpl::WEEKS;

void rice::p2p::aggregation::AggregationImpl::ctor(::rice::p2p::commonapi::Node* node, ::rice::p2p::past::Past* aggregateStore, ::rice::p2p::past::Past* objectStore, ::rice::persistence::StorageManager* waitingList, ::java::lang::String* configFileName, ::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* instance) /* throws(IOException) */
{
    ctor(node, aggregateStore, objectStore, waitingList, configFileName, factory, instance, nullptr, nullptr);
}

void rice::p2p::aggregation::AggregationImpl::ctor(::rice::p2p::commonapi::Node* node, ::rice::p2p::past::Past* aggregateStore, ::rice::p2p::past::Past* objectStore, ::rice::persistence::StorageManager* waitingList, ::java::lang::String* configFileName, ::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* instance, AggregationPolicy* policy, AggregateFactory* aggregateFactory) /* throws(IOException) */
{
    super::ctor();
    this->environment = npc(node)->getEnvironment();
    logger = npc(npc(environment)->getLogManager())->getLogger(AggregationImpl::class_(), instance);
    auto p = npc(environment)->getParameters();
    logStatistics = npc(p)->getBoolean(u"p2p_aggregation_logStatistics"_j);
    flushDelayAfterJoin = npc(p)->getLong(u"p2p_aggregation_flushDelayAfterJoin"_j);
    flushStressInterval = npc(p)->getLong(u"p2p_aggregation_flushStressInterval"_j);
    flushInterval = npc(p)->getLong(u"p2p_aggregation_flushInterval"_j);
    maxAggregateSize = npc(p)->getInt(u"p2p_aggregation_maxAggregateSize"_j);
    maxObjectsInAggregate = npc(p)->getInt(u"p2p_aggregation_maxObjectsInAggregate"_j);
    maxAggregatesPerRun = npc(p)->getInt(u"p2p_aggregation_maxAggregatesPerRun"_j);
    addMissingAfterRefresh = npc(p)->getBoolean(u"p2p_aggregation_addMissingAfterRefresh"_j);
    maxReaggregationPerRefresh = npc(p)->getInt(u"p2p_aggregation_maxReaggregationPerRefresh"_j);
    nominalReferenceCount = npc(p)->getInt(u"p2p_aggregation_nominalReferenceCount"_j);
    maxPointersPerAggregate = npc(p)->getInt(u"p2p_aggregation_maxPointersPerAggregate"_j);
    pointerArrayLifetime = npc(p)->getLong(u"p2p_aggregation_pointerArrayLifetime"_j);
    aggregateGracePeriod = npc(p)->getLong(u"p2p_aggregation_aggregateGracePeriod"_j);
    aggrRefreshInterval = npc(p)->getLong(u"p2p_aggregation_aggrRefreshInterval"_j);
    aggrRefreshDelayAfterJoin = npc(p)->getLong(u"p2p_aggregation_aggrRefreshDelayAfterJoin"_j);
    expirationRenewThreshold = npc(p)->getLong(u"p2p_aggregation_expirationRenewThreshold"_j);
    monitorEnabled = npc(p)->getBoolean(u"p2p_aggregation_monitorEnabled"_j);
    monitorRefreshInterval = npc(p)->getLong(u"p2p_aggregation_monitorRefreshInterval"_j);
    consolidationDelayAfterJoin = npc(p)->getLong(u"p2p_aggregation_consolidationDelayAfterJoin"_j);
    consolidationInterval = npc(p)->getLong(u"p2p_aggregation_consolidationInterval"_j);
    consolidationThreshold = npc(p)->getLong(u"p2p_aggregation_consolidationThreshold"_j);
    consolidationMinObjectsInAggregate = npc(p)->getInt(u"p2p_aggregation_consolidationMinObjectsInAggregate"_j);
    consolidationMinComponentsAlive = npc(p)->getDouble(u"p2p_aggregation_consolidationMinComponentsAlive"_j);
    reconstructionMaxConcurrentLookups = npc(p)->getInt(u"p2p_aggregation_reconstructionMaxConcurrentLookups"_j);
    aggregateLogEnabled = npc(p)->getBoolean(u"p2p_aggregation_aggregateLogEnabled"_j);
    statsGranularity = npc(p)->getLong(u"p2p_aggregation_statsGranularity"_j);
    statsRange = npc(p)->getLong(u"p2p_aggregation_statsRange"_j);
    statsInterval = npc(p)->getLong(u"p2p_aggregation_statsInterval"_j);
    jitterRange = npc(p)->getDouble(u"p2p_aggregation_jitterRange"_j);
    this->aggregateFactory = aggregateFactory;
    if(this->aggregateFactory == nullptr) {
        this->aggregateFactory = getDefaultAggregateFactory();
    }
    this->endpoint = npc(node)->buildEndpoint(this, instance);
    npc(this->endpoint)->setDeserializer(new AggregationImpl_AggregationImpl_1(this));
    this->waitingList = waitingList;
    this->instance = instance;
    this->contentDeserializer = new ::rice::p2p::past::rawserialization::JavaPastContentDeserializer();
    this->contentHandleDeserializer = new ::rice::p2p::past::rawserialization::JavaPastContentHandleDeserializer();
    this->aggregateStore = aggregateStore;
    npc(this->aggregateStore)->setContentDeserializer(new AggregationImpl_AggregationImpl_2(this));
    npc(this->aggregateStore)->setContentHandleDeserializer(new AggregationImpl_AggregationImpl_3(this));
    this->objectStore = objectStore;
    this->node = node;
    this->timers = new ::java::util::Hashtable();
    this->aggregateList = new AggregateList(configFileName, npc(npc(getLocalNodeHandle())->getId())->toString(), factory, aggregateLogEnabled, instance, environment);
    this->stats = npc(aggregateList)->getStatistics(statsGranularity, statsRange, nominalReferenceCount);
    if(policy == nullptr) {
        this->policy = getDefaultPolicy();
    } else {
        this->policy = policy;
    }
    this->factory = factory;
    this->flushWait = nullptr;
    this->rebuildInProgress = false;
    this->monitorIDs = new ::java::util::Vector();
    if(!npc(aggregateList)->readOK())
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(u"Failed to read configuration file; aggregate list must be rebuilt!"_j);
        else if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Aggregate list read OK -- current root: "_j)->append(((npc(aggregateList)->getRoot() == nullptr) ? u"null"_j : npc(npc(aggregateList)->getRoot())->toStringFull()))->toString());


    removeDeadAggregates();
    addTimer(jitterTerm(flushDelayAfterJoin), tiFlush);
    addTimer(jitterTerm(aggrRefreshDelayAfterJoin), tiExpire);
    addTimer(jitterTerm(consolidationDelayAfterJoin), tiConsolidate);
    addTimer(statsInterval, tiStatistics);
    if(monitorEnabled)
        addTimer(monitorRefreshInterval, tiMonitor);

    npc(endpoint)->register_();
}

rice::p2p::aggregation::AggregationPolicy* rice::p2p::aggregation::AggregationImpl::getDefaultPolicy()
{
    clinit();
    return new AggregationDefaultPolicy();
}

rice::p2p::aggregation::AggregateFactory* rice::p2p::aggregation::AggregationImpl::getDefaultAggregateFactory()
{
    clinit();
    return new ::rice::p2p::aggregation::raw::RawAggregateFactory();
}

int64_t rice::p2p::aggregation::AggregationImpl::jitterTerm(int64_t basis)
{
    return static_cast< int64_t >(((int32_t(1) - jitterRange) * basis)) + npc(npc(environment)->getRandomSource())->nextInt(static_cast< int32_t >((int32_t(2) * jitterRange * basis)));
}

void rice::p2p::aggregation::AggregationImpl::addTimer(int64_t timeoutMsec, char16_t timeoutID)
{
    auto timer = npc(endpoint)->scheduleMessage(new ::rice::p2p::aggregation::messaging::AggregationTimeoutMessage(timeoutID, getLocalNodeHandle()), timeoutMsec);
    npc(timers)->put(static_cast< ::java::lang::Object* >(new ::java::lang::Integer(static_cast< int32_t >(timeoutID))), static_cast< ::java::lang::Object* >(timer));
}

void rice::p2p::aggregation::AggregationImpl::removeTimer(int32_t timeoutID)
{
    auto timer = java_cast< ::rice::p2p::commonapi::CancellableTask* >(java_cast< ::java::lang::Object* >(npc(timers)->remove(static_cast< ::java::lang::Object* >(new ::java::lang::Integer(timeoutID)))));
    if(timer != nullptr) {
        npc(timer)->cancel();
    }
}

void rice::p2p::aggregation::AggregationImpl::panic(::java::lang::String* s) /* throws(Error) */
{
    auto err = new ::java::lang::Error(::java::lang::StringBuilder().append(u"Panic "_j)->append(s)->toString());
    if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
        npc(logger)->logException(::java::lang::StringBuilder().append(u"PANIC: "_j)->append(s)->toString(), err);

    throw err;
}

java::lang::String* rice::p2p::aggregation::AggregationImpl::handleDebugCommand(::java::lang::String* command)
{
    if(npc(command)->indexOf(u" "_j) < 0)
        return nullptr;

    auto requestedInstance = npc(command)->substring(0, npc(command)->indexOf(u" "_j));
    auto myInstance = ::java::lang::StringBuilder().append(u"aggr."_j)->append(npc(instance)->substring(npc(instance)->lastIndexOf(u"-"_j) + int32_t(1)))->toString();
    auto cmd = npc(command)->substring(npc(requestedInstance)->length() + int32_t(1));
    if(!npc(requestedInstance)->equals(static_cast< ::java::lang::Object* >(myInstance)) && !npc(requestedInstance)->equals(static_cast< ::java::lang::Object* >(u"a"_j))) {
        ::java::lang::String* subResult = nullptr;
        if((subResult == nullptr) && (dynamic_cast< ::rice::p2p::util::DebugCommandHandler* >(aggregateStore) != nullptr))
            subResult = npc((java_cast< ::rice::p2p::util::DebugCommandHandler* >(aggregateStore)))->handleDebugCommand(command);

        if((subResult == nullptr) && (dynamic_cast< ::rice::p2p::util::DebugCommandHandler* >(objectStore) != nullptr))
            subResult = npc((java_cast< ::rice::p2p::util::DebugCommandHandler* >(objectStore)))->handleDebugCommand(command);

        return subResult;
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Debug command: "_j)->append(cmd)->toString());

    if(npc(cmd)->startsWith(u"status"_j)) {
        return ::java::lang::StringBuilder().append(npc(stats)->numObjectsTotal)->append(u" objects total\n"_j)
            ->append(npc(stats)->numObjectsAlive)
            ->append(u" objects alive\n"_j)
            ->append(npc(stats)->numAggregatesTotal)
            ->append(u" aggregates total\n"_j)
            ->append(npc(stats)->numPointerArrays)
            ->append(u" pointer arrays\n"_j)
            ->append(npc(stats)->criticalAggregates)
            ->append(u" critical aggregates\n"_j)
            ->append(npc(stats)->orphanedAggregates)
            ->append(u" orphaned aggregates\n"_j)->toString();
    }
    if(npc(cmd)->startsWith(u"insert"_j)) {
        auto numObjects = ::java::lang::Integer::parseInt(npc(cmd)->substring(7));
        auto result = u""_j;
        for (auto i = int32_t(0); i < numObjects; i++) {
            auto randomID = npc(factory)->buildRandomId(npc(environment)->getRandomSource());
            result = ::java::lang::StringBuilder().append(result)->append(npc(randomID)->toStringFull())
                ->append(u"\n"_j)->toString();
            insert(static_cast< ::rice::p2p::past::PastContent* >(new ::rice::p2p::glacier::v2::DebugContent(randomID, false, int32_t(0), new ::int8_tArray({}))), npc(npc(environment)->getTimeSource())->currentTimeMillis() + int32_t(120) * SECONDS, static_cast< ::rice::Continuation* >(new AggregationImpl_handleDebugCommand_4(this)));
        }
        return ::java::lang::StringBuilder().append(result)->append(numObjects)
            ->append(u" object(s) created\n"_j)->toString();
    }
    if(npc(cmd)->startsWith(u"show config"_j)) {
        return ::java::lang::StringBuilder().append(u"flushDelayAfterJoin = "_j)->append(static_cast< int32_t >((flushDelayAfterJoin / SECONDS)))
            ->append(u" sec\n"_j)
            ->append(u"flushInterval = "_j)
            ->append(static_cast< int32_t >((flushInterval / SECONDS)))
            ->append(u" sec\n"_j)
            ->append(u"maxAggregateSize = "_j)
            ->append(maxAggregateSize)
            ->append(u" bytes\n"_j)
            ->append(u"maxObjectsInAggregate = "_j)
            ->append(maxObjectsInAggregate)
            ->append(u" objects\n"_j)
            ->append(u"maxAggregatesPerRun = "_j)
            ->append(maxAggregatesPerRun)
            ->append(u" aggregates\n"_j)
            ->append(u"addMissingAfterRefresh = "_j)
            ->append(addMissingAfterRefresh)
            ->append(u"\n"_j)
            ->append(u"nominalReferenceCount = "_j)
            ->append(nominalReferenceCount)
            ->append(u"\n"_j)
            ->append(u"maxPointersPerAggregate = "_j)
            ->append(maxPointersPerAggregate)
            ->append(u"\n"_j)
            ->append(u"pointerArrayLifetime = "_j)
            ->append(static_cast< int32_t >((pointerArrayLifetime / DAYS)))
            ->append(u" days\n"_j)
            ->append(u"aggrRefreshInterval = "_j)
            ->append(static_cast< int32_t >((aggrRefreshInterval / SECONDS)))
            ->append(u" sec\n"_j)
            ->append(u"aggrRefreshDelayAfterJoin = "_j)
            ->append(static_cast< int32_t >((aggrRefreshDelayAfterJoin / SECONDS)))
            ->append(u" sec\n"_j)
            ->append(u"expirationRenewThreshold = "_j)
            ->append(static_cast< int32_t >((expirationRenewThreshold / HOURS)))
            ->append(u" hrs\n"_j)
            ->append(u"consolidationDelayAfterJoin = "_j)
            ->append(static_cast< int32_t >((consolidationDelayAfterJoin / SECONDS)))
            ->append(u" sec\n"_j)
            ->append(u"consolidationInterval = "_j)
            ->append(static_cast< int32_t >((consolidationInterval / SECONDS)))
            ->append(u" sec\n"_j)
            ->append(u"consolidationThreshold = "_j)
            ->append(static_cast< int32_t >((consolidationThreshold / HOURS)))
            ->append(u" hrs\n"_j)
            ->append(u"consolidationMinObjectsInAggregate = "_j)
            ->append(consolidationMinObjectsInAggregate)
            ->append(u"\n"_j)
            ->append(u"consolidationMinComponentsAlive = "_j)
            ->append(consolidationMinComponentsAlive)
            ->append(u"\n"_j)->toString();
    }
    if(npc(cmd)->startsWith(u"ls"_j)) {
        auto enumeration = npc(aggregateList)->elements();
        auto result = new ::java::lang::StringBuffer();
        int32_t numAggr = int32_t(0), numObj = int32_t(0);
        auto now = npc(npc(environment)->getTimeSource())->currentTimeMillis();
        if(npc(cmd)->indexOf(u"-r"_j) < 0)
            now = 0;

        npc(aggregateList)->recalculateReferenceCounts(nullptr);
        npc(aggregateList)->resetMarkers();
        while (npc(enumeration)->hasMoreElements()) {
            auto aggr = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(enumeration)->nextElement()));
            if(!npc(aggr)->marker) {
                npc(result)->append(::java::lang::StringBuilder().append(u"***"_j)->append(npc(npc(aggr)->key)->toStringFull())
                    ->append(u" ("_j)
                    ->append(npc(npc(aggr)->objects)->length)
                    ->append(u" obj, "_j)
                    ->append(npc(npc(aggr)->pointers)->length)
                    ->append(u" ptr, "_j)
                    ->append(npc(aggr)->referenceCount)
                    ->append(u" ref, exp="_j)
                    ->append((npc(aggr)->currentLifetime - now))
                    ->append(u")\n"_j)->toString());
                for (auto i = int32_t(0); i < npc(npc(aggr)->objects)->length; i++) 
                                        npc(result)->append(::java::lang::StringBuilder().append(u"    #"_j)->append(i)
                        ->append(u" "_j)
                        ->append(npc(npc((*npc(aggr)->objects)[i])->key)->toStringFull())
                        ->append(u"v"_j)
                        ->append(npc((*npc(aggr)->objects)[i])->version)
                        ->append(u", lt="_j)
                        ->append((npc((*npc(aggr)->objects)[i])->currentLifetime - now))
                        ->append(u", rt="_j)
                        ->append((npc((*npc(aggr)->objects)[i])->refreshedLifetime - now))
                        ->append(u", size="_j)
                        ->append(npc((*npc(aggr)->objects)[i])->size)
                        ->append(u" bytes\n"_j)->toString());

                for (auto i = int32_t(0); i < npc(npc(aggr)->pointers)->length; i++) 
                                        npc(result)->append(::java::lang::StringBuilder().append(u"    Ref "_j)->append(npc((*npc(aggr)->pointers)[i])->toStringFull())
                        ->append(u"\n"_j)->toString());

                npc(result)->append(u"\n"_j);
                npc(aggr)->marker = true;
                numAggr++;
                numObj += npc(npc(aggr)->objects)->length;
            }
        }
        npc(result)->append(::java::lang::StringBuilder().append(numAggr)->append(u" aggregate(s), "_j)
            ->append(numObj)
            ->append(u" object(s)"_j)->toString());
        return npc(result)->toString();
    }
    if(npc(cmd)->startsWith(u"write list"_j)) {
        npc(aggregateList)->writeToDisk();
        return ::java::lang::StringBuilder().append(u"Done, new root is "_j)->append(((npc(aggregateList)->getRoot() == nullptr) ? u"null"_j : npc(npc(aggregateList)->getRoot())->toStringFull()))->toString();
    }
    if((npc(cmd)->length() >= 5) && npc(npc(cmd)->substring(0, 5))->equals(static_cast< ::java::lang::Object* >(u"reset"_j))) {
        auto const ret = new ::java::lang::StringArray({static_cast< ::java::lang::String* >(nullptr)});
        reset(static_cast< ::rice::Continuation* >(new AggregationImpl_handleDebugCommand_5(this, ret)));
        while ((*ret)[int32_t(0)] == nullptr) 
                        ::java::lang::Thread::yield();

        return (*ret)[int32_t(0)];
    }
    if(npc(cmd)->startsWith(u"flush"_j)) {
        auto const ret = new ::java::lang::StringArray({static_cast< ::java::lang::String* >(nullptr)});
        flush(static_cast< ::rice::Continuation* >(new AggregationImpl_handleDebugCommand_6(this, ret)));
        while ((*ret)[int32_t(0)] == nullptr) 
                        ::java::lang::Thread::yield();

        return (*ret)[int32_t(0)];
    }
    if(npc(cmd)->startsWith(u"get root"_j)) {
        return ::java::lang::StringBuilder().append(u"root="_j)->append(((npc(aggregateList)->getRoot() == nullptr) ? u"null"_j : npc(npc(aggregateList)->getRoot())->toStringFull()))->toString();
    }
    if(npc(cmd)->startsWith(u"set root"_j)) {
        auto const ret = new ::java::lang::StringArray({static_cast< ::java::lang::String* >(nullptr)});
        setHandle(static_cast< ::java::io::Serializable* >(npc(factory)->buildIdFromToString(npc(cmd)->substring(9))), static_cast< ::rice::Continuation* >(new AggregationImpl_handleDebugCommand_7(this, ret)));
        while ((*ret)[int32_t(0)] == nullptr) 
                        ::java::lang::Thread::yield();

        return (*ret)[int32_t(0)];
    }
    if(npc(cmd)->startsWith(u"lookup"_j)) {
        auto id = npc(factory)->buildIdFromToString(npc(cmd)->substring(7));
        auto const ret = new ::java::lang::StringArray({static_cast< ::java::lang::String* >(nullptr)});
        lookup(id, false, static_cast< ::rice::Continuation* >(new AggregationImpl_handleDebugCommand_8(this, ret)));
        while ((*ret)[int32_t(0)] == nullptr) 
                        ::java::lang::Thread::yield();

        return ::java::lang::StringBuilder().append(u"lookup("_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u")="_j)
            ->append((*ret)[int32_t(0)])->toString();
    }
    if(npc(cmd)->startsWith(u"handles"_j)) {
        auto args = npc(cmd)->substring(8);
        auto id = npc(factory)->buildIdFromToString(npc(args)->substring(npc(args)->indexOf(static_cast< int32_t >(u' ')) + int32_t(1)));
        auto max = ::java::lang::Integer::parseInt(npc(args)->substring(0, npc(args)->indexOf(static_cast< int32_t >(u' '))));
        auto const ret = new ::java::lang::StringArray({static_cast< ::java::lang::String* >(nullptr)});
        lookupHandles(id, max, static_cast< ::rice::Continuation* >(new AggregationImpl_handleDebugCommand_9(this, ret)));
        while ((*ret)[int32_t(0)] == nullptr) 
                        ::java::lang::Thread::yield();

        return ::java::lang::StringBuilder().append(u"Handles("_j)->append(max)
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(id))
            ->append(u"):\n"_j)
            ->append((*ret)[int32_t(0)])->toString();
    }
    if(npc(cmd)->startsWith(u"refresh all"_j)) {
        auto expiration = npc(npc(environment)->getTimeSource())->currentTimeMillis() + ::java::lang::Long::parseLong(npc(cmd)->substring(12));
        auto ids = new ::java::util::TreeSet();
        ::java::lang::String* result;
        npc(aggregateList)->resetMarkers();
        auto enumeration = npc(aggregateList)->elements();
        while (npc(enumeration)->hasMoreElements()) {
            auto aggr = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(enumeration)->nextElement()));
            if(!npc(aggr)->marker) {
                npc(aggr)->marker = true;
                for (auto i = int32_t(0); i < npc(npc(aggr)->objects)->length; i++) 
                                        npc(ids)->add(static_cast< ::java::lang::Object* >(npc((*npc(aggr)->objects)[i])->key));

            }
        }
        if(!npc(ids)->isEmpty()) {
            auto allIds = java_cast< ::rice::p2p::commonapi::IdArray* >(java_cast< ::java::lang::ObjectArray* >(npc(ids)->toArray_(static_cast< ::java::lang::ObjectArray* >(new ::rice::p2p::commonapi::IdArray({})))));
            result = ::java::lang::StringBuilder().append(u"Refreshing "_j)->append(npc(allIds)->length)
                ->append(u" keys...\n"_j)->toString();
            for (auto i = int32_t(0); i < npc(allIds)->length; i++) 
                                result = ::java::lang::StringBuilder().append(result)->append(u"#"_j)
                    ->append(i)
                    ->append(u" "_j)
                    ->append(npc((*allIds)[i])->toStringFull())
                    ->append(u"\n"_j)->toString();

            auto const ret = new ::java::lang::StringArray({static_cast< ::java::lang::String* >(nullptr)});
            refresh(allIds, expiration, static_cast< ::rice::Continuation* >(new AggregationImpl_handleDebugCommand_10(this, ret)));
            while ((*ret)[int32_t(0)] == nullptr) 
                                ::java::lang::Thread::yield();

            result = ::java::lang::StringBuilder().append(result)->append((*ret)[int32_t(0)])->toString();
        } else
            result = u"Aggregate list is empty; nothing to refresh!"_j;
        return result;
    }
    if(npc(cmd)->startsWith(u"refresh"_j)) {
        auto args = npc(cmd)->substring(8);
        auto expirationArg = npc(args)->substring(npc(args)->lastIndexOf(static_cast< int32_t >(u' ')) + int32_t(1));
        auto keyArg = npc(args)->substring(0, npc(args)->lastIndexOf(static_cast< int32_t >(u' ')));
        auto id = npc(factory)->buildIdFromToString(keyArg);
        auto expiration = npc(npc(environment)->getTimeSource())->currentTimeMillis() + ::java::lang::Long::parseLong(expirationArg);
        auto const ret = new ::java::lang::StringArray({static_cast< ::java::lang::String* >(nullptr)});
        refresh(new ::rice::p2p::commonapi::IdArray({id}), expiration, static_cast< ::rice::Continuation* >(new AggregationImpl_handleDebugCommand_11(this, ret)));
        while ((*ret)[int32_t(0)] == nullptr) 
                        ::java::lang::Thread::yield();

        return ::java::lang::StringBuilder().append(u"refresh("_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u", "_j)
            ->append(expiration)
            ->append(u")="_j)
            ->append((*ret)[int32_t(0)])->toString();
    }
    if(npc(cmd)->startsWith(u"monitor remove"_j) && monitorEnabled) {
        auto args = npc(npc(cmd)->substring(15))->split(u" "_j);
        if(npc(args)->length == 1) {
            auto howMany = ::java::lang::Integer::parseInt((*args)[int32_t(0)]);
            if(howMany > npc(monitorIDs)->size())
                howMany = npc(monitorIDs)->size();

            for (auto i = int32_t(0); i < howMany; i++) 
                                npc(monitorIDs)->removeElementAt(npc(npc(environment)->getRandomSource())->nextInt(npc(monitorIDs)->size()));

            return ::java::lang::StringBuilder().append(u"Removed "_j)->append(howMany)
                ->append(u" elements; "_j)
                ->append(npc(monitorIDs)->size())
                ->append(u" elements left"_j)->toString();
        } else
            return u"Syntax: monitor remove <howMany>"_j;
    }
    if(npc(cmd)->startsWith(u"monitor status"_j) && monitorEnabled) {
        return ::java::lang::StringBuilder().append(u"Monitor is "_j)->append((monitorEnabled ? (::java::lang::StringBuilder().append(u"enabled, monitoring "_j)->append(npc(monitorIDs)->size())
            ->append(u" objects"_j)->toString()) : u"disabled"_j))->toString();
    }
    if(npc(cmd)->startsWith(u"monitor ls"_j) && monitorEnabled) {
        auto result = new ::java::lang::StringBuffer();
        auto enumeration = npc(monitorIDs)->elements();
        while (npc(enumeration)->hasMoreElements()) 
                        npc(result)->append(::java::lang::StringBuilder().append(npc((java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(enumeration)->nextElement()))))->toStringFull())->append(u"\n"_j)->toString());

        npc(result)->append(::java::lang::StringBuilder().append(npc(monitorIDs)->size())->append(u" object(s)"_j)->toString());
        return npc(result)->toString();
    }
    if(npc(cmd)->startsWith(u"monitor check"_j) && monitorEnabled) {
        auto const result = new ::java::lang::StringBuffer();
        auto const ret = new ::java::lang::StringArray({static_cast< ::java::lang::String* >(nullptr)});
        if(npc(monitorIDs)->isEmpty())
            return u"Add objects first!"_j;

        auto const now = npc(npc(environment)->getTimeSource())->currentTimeMillis();
        ::rice::Continuation* c = new AggregationImpl_handleDebugCommand_12(this, result, now, ret);
        npc(objectStore)->lookupHandles(java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(monitorIDs)->elementAt(0))), 1, c);
        while ((*ret)[int32_t(0)] == nullptr) 
                        ::java::lang::Thread::yield();

        return npc(result)->toString();
    }
    if(npc(cmd)->startsWith(u"monitor add"_j) && monitorEnabled) {
        auto args = npc(npc(cmd)->substring(12))->split(u" "_j);
        if(npc(args)->length == 6) {
            auto const numFiles = ::java::lang::Integer::parseInt((*args)[int32_t(0)]);
            auto const avgBurstSize = ::java::lang::Integer::parseInt((*args)[int32_t(1)]);
            auto const sizeSkew = ::java::lang::Double::parseDouble((*args)[int32_t(2)]);
            auto const smallSize = ::java::lang::Integer::parseInt((*args)[int32_t(3)]);
            auto const largeSize = ::java::lang::Integer::parseInt((*args)[int32_t(4)]);
            auto const expiration = npc(npc(environment)->getTimeSource())->currentTimeMillis() + ::java::lang::Long::parseLong((*args)[int32_t(5)]);
            ::rice::Continuation* c = new AggregationImpl_handleDebugCommand_13(this, numFiles, avgBurstSize, sizeSkew, smallSize, largeSize, expiration);
            npc(c)->receiveResult(new ::java::lang::Boolean(true));
            return u"In progress..."_j;
        }
        return u"Syntax: monitor add <#files> <avgBurstSize> <sizeSkew> <smallSize> <largeSize> <lifetime>"_j;
    }
    if(npc(cmd)->startsWith(u"killall"_j)) {
        auto args = npc(cmd)->substring(8);
        auto expirationArg = npc(args)->substring(npc(args)->lastIndexOf(static_cast< int32_t >(u' ')) + int32_t(1));
        auto keyArg = npc(args)->substring(0, npc(args)->lastIndexOf(static_cast< int32_t >(u' ')));
        auto id = npc(factory)->buildIdFromToString(keyArg);
        auto expiration = npc(npc(environment)->getTimeSource())->currentTimeMillis() + ::java::lang::Long::parseLong(expirationArg);
        auto aggr = java_cast< AggregateDescriptor* >(npc(aggregateList)->getADC(id));
        if(aggr != nullptr) {
            npc(aggregateList)->setAggregateLifetime(aggr, ::java::lang::Math::min(npc(aggr)->currentLifetime, expiration));
            for (auto i = int32_t(0); i < npc(npc(aggr)->objects)->length; i++) {
                npc(aggregateList)->setObjectCurrentLifetime(aggr, i, ::java::lang::Math::min(npc((*npc(aggr)->objects)[i])->currentLifetime, expiration));
                npc(aggregateList)->setObjectRefreshedLifetime(aggr, i, ::java::lang::Math::min(npc((*npc(aggr)->objects)[i])->refreshedLifetime, expiration));
            }
            return u"OK"_j;
        }
        return ::java::lang::StringBuilder().append(u"Aggregate "_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u" not found in aggregate list"_j)->toString();
    }
    if(npc(cmd)->startsWith(u"waiting"_j)) {
        auto iter = npc(npc(waitingList)->scan())->getIterator();
        auto result = u""_j;
        result = ::java::lang::StringBuilder().append(result)->append(npc(npc(waitingList)->scan())->numElements())
            ->append(u" object(s) waiting\n"_j)->toString();
        while (npc(iter)->hasNext()) {
            auto thisId = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(iter)->next()));
            result = ::java::lang::StringBuilder().append(result)->append(npc(thisId)->toStringFull())
                ->append(u" "_j)
                ->append(static_cast< ::java::lang::Object* >(npc(waitingList)->getMetadata(thisId)))
                ->append(u"\n"_j)->toString();
        }
        return result;
    }
    if(npc(cmd)->startsWith(u"vlookup"_j)) {
        auto vkeyS = npc(npc(cmd)->substring(8))->split(u"v"_j);
        auto key = npc(factory)->buildIdFromToString((*vkeyS)[int32_t(0)]);
        auto version = ::java::lang::Long::parseLong((*vkeyS)[int32_t(1)]);
        auto const ret = new ::java::lang::StringArray({static_cast< ::java::lang::String* >(nullptr)});
        lookup(key, version, static_cast< ::rice::Continuation* >(new AggregationImpl_handleDebugCommand_14(this, ret)));
        while ((*ret)[int32_t(0)] == nullptr) 
                        ::java::lang::Thread::yield();

        return ::java::lang::StringBuilder().append(u"vlookup("_j)->append(static_cast< ::java::lang::Object* >(key))
            ->append(u"v"_j)
            ->append(version)
            ->append(u")="_j)
            ->append((*ret)[int32_t(0)])->toString();
    }
    return nullptr;
}

void rice::p2p::aggregation::AggregationImpl::removeDeadAggregates()
{
    auto toRemove = new ::java::util::Vector();
    auto enumeration = npc(aggregateList)->elements();
    auto now = npc(npc(environment)->getTimeSource())->currentTimeMillis();
    while (npc(enumeration)->hasMoreElements()) {
        auto adc = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(enumeration)->nextElement()));
        if(npc(adc)->currentLifetime < (now - aggregateGracePeriod)) {
            if(!npc(toRemove)->contains(static_cast< ::java::lang::Object* >(adc)))
                npc(toRemove)->add(static_cast< ::java::lang::Object* >(adc));

            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Scheduling dead aggregate for removal: "_j)->append(npc(npc(adc)->key)->toStringFull())
                    ->append(u"(expired "_j)
                    ->append(npc(adc)->currentLifetime)
                    ->append(u")"_j)->toString());

        }
    }
    if(npc(toRemove)->size() > 0) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Removing "_j)->append(npc(toRemove)->size())
                ->append(u" dead aggregates..."_j)->toString());

        auto rem = npc(toRemove)->elements();
        while (npc(rem)->hasMoreElements()) 
                        npc(aggregateList)->removeAggregateDescriptor(java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(rem)->nextElement())));

    }
}

void rice::p2p::aggregation::AggregationImpl::storeAggregate(Aggregate* aggr, int64_t expiration, ObjectDescriptorArray* desc, ::rice::p2p::commonapi::IdArray* pointers, ::rice::Continuation* command)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(u"storeAggregate() schedules content hash computation..."_j);

    npc(endpoint)->process(new AggregationImpl_storeAggregate_15(this, aggr), new AggregationImpl_storeAggregate_16(this, aggr, expiration, desc, pointers, command));
}

void rice::p2p::aggregation::AggregationImpl::flushComplete(::java::lang::Object* o)
{
    if(flushWait != nullptr) {
        auto c = flushWait;
        flushWait = nullptr;
        if(dynamic_cast< ::java::lang::Exception* >(o) != nullptr)
            npc(c)->receiveException(java_cast< ::java::lang::Exception* >(o));
        else
            npc(c)->receiveResult(o);
    }
}

void rice::p2p::aggregation::AggregationImpl::formAggregates(::rice::Continuation* command)
{
    if(flushWait != nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(u"Flush in progress... daisy-chaining continuation"_j);

        auto const parent = flushWait;
        flushWait = new AggregationImpl_formAggregates_17(this, command, parent);
        return;
    }
    flushWait = command;
    auto waitingKeys = npc(waitingList)->scan();
    if(npc(waitingKeys)->numElements() == 0) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(u"NO BINS TO PACK"_j);

        flushComplete(new ::java::lang::Boolean(true));
        return;
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(u"BIN PACKING STARTED"_j);

    auto currentAggregate = new ::java::util::Vector();
    auto aggregates = new ::java::util::Vector();
    auto deletionVector = new ::java::util::Vector();
    auto iter = npc(waitingKeys)->getIterator();
    int64_t currentAggregateSize = int32_t(0);
    auto currentObjectsInAggregate = int32_t(0);
    while (true) {
        ObjectDescriptor* thisObject = nullptr;
        auto mustAddObject = false;
        if(npc(aggregates)->size() >= maxAggregatesPerRun)
            break;

        while (npc(iter)->hasNext()) {
            auto thisId = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(iter)->next()));
            thisObject = java_cast< ObjectDescriptor* >(npc(waitingList)->getMetadata(thisId));
            if(thisObject != nullptr) {
                thisObject = new ObjectDescriptor(npc(thisObject)->key, npc(thisObject)->version, npc(thisObject)->currentLifetime, npc(thisObject)->refreshedLifetime, npc(thisObject)->size);
                if((((currentAggregateSize + npc(thisObject)->size) <= maxAggregateSize) || npc(currentAggregate)->isEmpty()) && (currentObjectsInAggregate < maxObjectsInAggregate)) {
                    currentAggregateSize += npc(thisObject)->size;
                    currentObjectsInAggregate++;
                    npc(currentAggregate)->add(static_cast< ::java::lang::Object* >(thisObject));
                } else {
                    mustAddObject = true;
                    break;
                }
            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Metadata in waiting object "_j)->append(npc(thisId)->toStringFull())
                        ->append(u" appears to be damaged. Scheduling for deletion..."_j)->toString());

                npc(deletionVector)->add(static_cast< ::java::lang::Object* >(thisId));
            }
        }
        auto numObjectsInAggregate = npc(currentAggregate)->size();
        if(numObjectsInAggregate < 1) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(u"Waiting list seems to consist entirely of damaged objects -- please remove!"_j);

            flushComplete(new ::java::lang::Boolean(true));
            return;
        }
        auto desc = new ObjectDescriptorArray(numObjectsInAggregate);
        for (auto i = int32_t(0); i < numObjectsInAggregate; i++) {
            desc->set(i, java_cast< ObjectDescriptor* >(java_cast< ::java::lang::Object* >(npc(currentAggregate)->elementAt(i))));
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"#"_j)->append(i)
                    ->append(u": "_j)
                    ->append(static_cast< ::java::lang::Object* >(npc((*desc)[i])->key))
                    ->append(u" "_j)
                    ->append(npc((*desc)[i])->size)
                    ->append(u" bytes"_j)->toString());

        }
        npc(aggregates)->add(static_cast< ::java::lang::Object* >(desc));
        npc(currentAggregate)->clear();
        currentObjectsInAggregate = 0;
        currentAggregateSize = 0;
        if(mustAddObject) {
            npc(currentAggregate)->add(static_cast< ::java::lang::Object* >(thisObject));
            currentAggregateSize += npc(thisObject)->size;
        } else {
            if(!npc(iter)->hasNext())
                break;

        }
    }
    auto delenda = npc(deletionVector)->elements();
    while (npc(delenda)->hasMoreElements()) {
        auto const thisId = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(delenda)->nextElement()));
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Deleting object "_j)->append(npc(thisId)->toStringFull())
                ->append(u" from waiting list (broken metadata)"_j)->toString());

        npc(waitingList)->unstore(thisId, new AggregationImpl_formAggregates_18(this, thisId));
    }
    auto c = new ::rice::Continuation_MultiContinuation(new AggregationImpl_formAggregates_19(this), npc(aggregates)->size());
    for (auto i = int32_t(0); i < npc(aggregates)->size(); i++) {
        auto const desc = java_cast< ObjectDescriptorArray* >(java_cast< ::java::lang::Object* >(npc(aggregates)->elementAt(i)));
        auto const obj = new ::rice::p2p::past::gc::GCPastContentArray(npc(desc)->length);
        auto const aggrExpirationF = chooseAggregateLifetime(desc, npc(npc(environment)->getTimeSource())->currentTimeMillis(), 0);
        auto const thisContinuation = npc(c)->getSubContinuation(i);
        auto const iF = i;
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Retrieving #"_j)->append(i)
                ->append(u".0: "_j)
                ->append(static_cast< ::java::lang::Object* >(npc((*desc)[int32_t(0)])->key))->toString());

        npc(waitingList)->getObject(new ::rice::p2p::glacier::VersionKey(npc((*desc)[int32_t(0)])->key, npc((*desc)[int32_t(0)])->version), new AggregationImpl_formAggregates_20(this, obj, desc, iF, aggrExpirationF, thisContinuation));
    }
}

int64_t rice::p2p::aggregation::AggregationImpl::chooseAggregateLifetime(ObjectDescriptorArray* components, int64_t now, int64_t currentLifetime)
{
    int64_t maxLifetime = int32_t(0);
    for (auto i = int32_t(0); i < npc(components)->length; i++) 
                if(npc((*components)[i])->refreshedLifetime > maxLifetime)
            maxLifetime = npc((*components)[i])->refreshedLifetime;


    return maxLifetime;
}

void rice::p2p::aggregation::AggregationImpl::refreshAggregates()
{
    auto enumeration = npc(aggregateList)->elements();
    auto now = npc(npc(environment)->getTimeSource())->currentTimeMillis();
    auto removeList = new ::java::util::Vector();
    auto const refreshAggregateList = new ::java::util::Vector();
    auto const refreshLifetimeList = new ::java::util::Vector();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(u"Checking aggregate lifetimes"_j);

    npc(aggregateList)->resetMarkers();
    while (npc(enumeration)->hasMoreElements()) {
        auto aggr = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(enumeration)->nextElement()));
        if(!npc(aggr)->marker) {
            npc(aggr)->marker = true;
            auto isBeingRefreshed = false;
            if(npc(aggr)->currentLifetime < (now + expirationRenewThreshold)) {
                auto newLifetime = chooseAggregateLifetime(npc(aggr)->objects, now, npc(aggr)->currentLifetime);
                if(newLifetime > npc(aggr)->currentLifetime) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Refreshing aggregate "_j)->append(npc(npc(aggr)->key)->toStringFull())
                            ->append(u", new expiration is "_j)
                            ->append(newLifetime)->toString());

                    isBeingRefreshed = true;
                    npc(refreshAggregateList)->add(static_cast< ::java::lang::Object* >(aggr));
                    npc(refreshLifetimeList)->add(static_cast< ::java::lang::Object* >(new ::java::lang::Long(newLifetime)));
                }
            }
            if((npc(aggr)->currentLifetime < now) && !isBeingRefreshed) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Adding expired aggregate "_j)->append(static_cast< ::java::lang::Object* >(npc(aggr)->key))
                        ->append(u" to remove list"_j)->toString());

                npc(removeList)->add(static_cast< ::java::lang::Object* >(aggr));
            }
        }
    }
    auto deletedOne = false;
    while (!npc(removeList)->isEmpty()) {
        auto aggr = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(removeList)->elementAt(0)));
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Removing expired aggregate "_j)->append(npc(npc(aggr)->key)->toStringFull())
                ->append(u" from list"_j)->toString());

        npc(removeList)->removeElementAt(0);
        deletedOne = true;
        npc(aggregateList)->removeAggregateDescriptor(aggr);
    }
    if(deletedOne)
        npc(aggregateList)->writeToDisk();

    if(!npc(refreshAggregateList)->isEmpty()) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Refreshing "_j)->append(npc(refreshAggregateList)->size())
                ->append(u" aggregate(s)"_j)->toString());

        if(dynamic_cast< ::rice::p2p::past::gc::GCPast* >(aggregateStore) != nullptr) {
            auto ids = new ::rice::p2p::commonapi::IdArray(npc(refreshAggregateList)->size());
            auto lifetimes = new ::int64_tArray(npc(refreshAggregateList)->size());
            for (auto i = int32_t(0); i < npc(refreshAggregateList)->size(); i++) {
                ids->set(i, npc((java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(refreshAggregateList)->elementAt(i)))))->key);
                (*lifetimes)[i] = npc((java_cast< ::java::lang::Long* >(java_cast< ::java::lang::Object* >(npc(refreshLifetimeList)->elementAt(i)))))->longValue();
            }
            npc((java_cast< ::rice::p2p::past::gc::GCPast* >(aggregateStore)))->refresh(ids, lifetimes, static_cast< ::rice::Continuation* >(new AggregationImpl_refreshAggregates_21(this, refreshAggregateList, refreshLifetimeList)));
        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(u"Aggregate store does not support GC; refreshing directly"_j);

            for (auto i = int32_t(0); i < npc(refreshAggregateList)->size(); i++) {
                auto aggr = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(refreshAggregateList)->elementAt(i)));
                auto newLifetime = npc((java_cast< ::java::lang::Long* >(java_cast< ::java::lang::Object* >(npc(refreshLifetimeList)->elementAt(i)))))->longValue();
                npc(aggregateList)->refreshAggregate(aggr, newLifetime);
            }
        }
    }
}

void rice::p2p::aggregation::AggregationImpl::consolidateAggregates()
{
    auto const now = npc(npc(environment)->getTimeSource())->currentTimeMillis();
    auto enumeration = npc(aggregateList)->elements();
    auto candidateList = new ::java::util::Vector();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(u"Looking for aggregates to consolidate"_j);

    npc(aggregateList)->resetMarkers();
    while (npc(enumeration)->hasMoreElements()) {
        auto aggr = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(enumeration)->nextElement()));
        if(!npc(aggr)->marker) {
            npc(aggr)->marker = true;
            if((npc(aggr)->currentLifetime > (now + expirationRenewThreshold)) && (npc(aggr)->currentLifetime < (now + consolidationThreshold)) && (npc(aggr)->objectsAliveAt(now) > 0)) {
                auto fractionAlive = (static_cast< float >(npc(aggr)->objectsAliveAt(now))) / npc(npc(aggr)->objects)->length;
                if((npc(npc(aggr)->objects)->length < consolidationMinObjectsInAggregate) || (fractionAlive < consolidationMinComponentsAlive)) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Can consolidate: "_j)->append(npc(npc(aggr)->key)->toStringFull())
                            ->append(u", "_j)
                            ->append(npc(aggr)->objectsAliveAt(now))
                            ->append(u"/"_j)
                            ->append(npc(npc(aggr)->objects)->length)
                            ->append(u" alive"_j)->toString());

                    npc(candidateList)->add(static_cast< ::java::lang::Object* >(aggr));
                }
            }
        }
    }
    if(npc(candidateList)->isEmpty()) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(u"No candidates for consolidation"_j);

        return;
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(npc(candidateList)->size())->append(u" candidate(s) for consolidation"_j)->toString());

    auto const componentList = new ::java::util::Vector();
    auto objectsSoFar = int32_t(0);
    auto bytesSoFar = int32_t(0);
    while (!npc(candidateList)->isEmpty()) {
        auto adc = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(candidateList)->remove(npc(npc(environment)->getRandomSource())->nextInt(npc(candidateList)->size()))));
        npc(componentList)->add(static_cast< ::java::lang::Object* >(adc));
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Picked candidate "_j)->append(npc(npc(adc)->key)->toStringFull())
                ->append(u" ("_j)
                ->append(npc(adc)->objectsAliveAt(now))
                ->append(u"/"_j)
                ->append(npc(npc(adc)->objects)->length)
                ->append(u" objects, "_j)
                ->append(npc(adc)->bytesAliveAt(now))
                ->append(u" bytes alive)"_j)->toString());

        objectsSoFar += npc(adc)->objectsAliveAt(now);
        bytesSoFar += npc(adc)->bytesAliveAt(now);
        auto p = int32_t(0);
        while (p < npc(candidateList)->size()) {
            auto adx = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(candidateList)->elementAt(p)));
            if(((npc(adx)->objectsAliveAt(now) + objectsSoFar) > maxObjectsInAggregate) || ((npc(adx)->bytesAliveAt(now) + bytesSoFar) > maxAggregateSize))
                npc(candidateList)->removeElementAt(p);
            else
                p++;
        }
    }
    if(npc(componentList)->isEmpty() || (objectsSoFar < consolidationMinObjectsInAggregate)) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Not enough objects ("_j)->append(objectsSoFar)
                ->append(u" found, "_j)
                ->append(consolidationMinObjectsInAggregate)
                ->append(u" required), postponing..."_j)->toString());

        return;
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Consolidation: Decided to consolidate "_j)->append(objectsSoFar)
            ->append(u" objects from "_j)
            ->append(npc(componentList)->size())
            ->append(u" aggregates ("_j)
            ->append(bytesSoFar)
            ->append(u" bytes)"_j)->toString());

    auto const adc = java_cast< AggregateDescriptorArray* >(java_cast< ::java::lang::ObjectArray* >(npc(componentList)->toArray_(static_cast< ::java::lang::ObjectArray* >(new AggregateDescriptorArray({})))));
    auto const aggr = new AggregateArray(npc(adc)->length);
    auto const objectsTotal = objectsSoFar;
    auto const firstKey = npc((*adc)[int32_t(0)])->key;
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Consolidation: Fetching aggregate #0: "_j)->append(npc(firstKey)->toStringFull())->toString());

    npc(aggregateStore)->lookup(firstKey, new AggregationImpl_consolidateAggregates_22(this, aggr, componentList, objectsTotal, adc, now));
}

void rice::p2p::aggregation::AggregationImpl::reconnectTree()
{
    if(rebuildInProgress) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(u"Skipping connectivity check (rebuild in progress)"_j);

        return;
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(u"Checking for disconnections"_j);

    auto disconnected = npc(aggregateList)->getSomePointers(1, maxPointersPerAggregate, nullptr);
    if(npc(disconnected)->length < 2) {
        auto newRoot = (npc(disconnected)->length == 1) ? (*disconnected)[int32_t(0)] : static_cast< ::rice::p2p::commonapi::Id* >(nullptr);
        auto currentRoot = npc(aggregateList)->getRoot();
        if(((newRoot == nullptr) && (currentRoot != nullptr)) || ((newRoot != nullptr) && (currentRoot == nullptr)) || ((newRoot != nullptr) && (currentRoot != nullptr) && !npc(newRoot)->equals(currentRoot)))
            npc(aggregateList)->setRoot(newRoot);

        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"No aggregates disconnected (n="_j)->append(npc(disconnected)->length)
                ->append(u")"_j)->toString());

        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"root="_j)->append(((npc(aggregateList)->getRoot() == nullptr) ? u"null"_j : npc(npc(aggregateList)->getRoot())->toStringFull()))->toString());

        return;
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Found "_j)->append(npc(disconnected)->length)
            ->append(u" disconnected aggregates; inserting pointer array"_j)->toString());

    storeAggregate(npc(aggregateFactory)->buildAggregate(new ::rice::p2p::past::gc::GCPastContentArray({}), disconnected), npc(npc(environment)->getTimeSource())->currentTimeMillis() + pointerArrayLifetime, new ObjectDescriptorArray({}), disconnected, new AggregationImpl_reconnectTree_23(this));
}

void rice::p2p::aggregation::AggregationImpl::timerExpired(char16_t timerID)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"TIMER EXPIRED: #"_j)->append(static_cast< int32_t >(timerID))->toString());

    switch (timerID) {
    case tiFlush: {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Scheduled flush, waiting list: "_j)->append(npc(waitingList)->getSize())->toString());

            formAggregates(new AggregationImpl_timerExpired_24(this));
            if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Waiting list: "_j)->append(npc(waitingList)->getSize())
                    ->append(u" Scan: "_j)
                    ->append(getNumObjectsWaiting())
                    ->append(u" Max: "_j)
                    ->append((maxObjectsInAggregate * maxAggregatesPerRun))->toString());

            if(getNumObjectsWaiting() >= (maxObjectsInAggregate * maxAggregatesPerRun)) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                    npc(logger)->log(u"Retrying later"_j);

                addTimer(jitterTerm(flushStressInterval), tiFlush);
            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                    npc(logger)->log(u"OK, waiting for next deadline"_j);

                addTimer(jitterTerm(flushInterval), tiFlush);
            }
            break;
        }
    case tiExpire: {
            refreshAggregates();
            reconnectTree();
            addTimer(jitterTerm(aggrRefreshInterval), tiExpire);
            break;
        }
    case tiConsolidate: {
            consolidateAggregates();
            addTimer(jitterTerm(consolidationInterval), tiConsolidate);
            break;
        }
    case tiMonitor: {
            auto ids = java_cast< ::rice::p2p::commonapi::IdArray* >(java_cast< ::java::lang::ObjectArray* >(npc(monitorIDs)->toArray_(static_cast< ::java::lang::ObjectArray* >(new ::rice::p2p::commonapi::IdArray({})))));
            if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Monitor: Refreshing "_j)->append(npc(ids)->length)
                    ->append(u" objects"_j)->toString());

            refresh(ids, npc(npc(environment)->getTimeSource())->currentTimeMillis() + int32_t(3) * monitorRefreshInterval, static_cast< ::rice::Continuation* >(new AggregationImpl_timerExpired_25(this)));
            addTimer(monitorRefreshInterval, tiMonitor);
            break;
        }
    case tiStatistics: {
            stats = npc(aggregateList)->getStatistics(statsGranularity, statsRange, nominalReferenceCount);
            npc(stats)->dump(npc(npc(environment)->getLogManager())->getLogger(AggregationStatistics::class_(), instance));
            addTimer(statsInterval, tiStatistics);
            break;
        }
    default: {
            panic(::java::lang::StringBuilder().append(u"Unknown timer expired: "_j)->append(static_cast< int32_t >(timerID))->toString());
        }
    }

}

void rice::p2p::aggregation::AggregationImpl::refreshInObjectStore(::rice::p2p::commonapi::IdArray* ids, ::int64_tArray* expirations, ::rice::Continuation* command)
{
    if(dynamic_cast< ::rice::p2p::past::gc::GCPast* >(objectStore) != nullptr) {
        npc((java_cast< ::rice::p2p::past::gc::GCPast* >(objectStore)))->refresh(ids, expirations, command);
    } else {
        npc(command)->receiveResult(new ::java::lang::Boolean(true));
    }
}

void rice::p2p::aggregation::AggregationImpl::refresh(::rice::p2p::commonapi::IdArray* ids, int64_t expiration, ::rice::Continuation* command)
{
    auto expirations = new ::int64_tArray(npc(ids)->length);
    ::java::util::Arrays::fill(expirations, expiration);
    refresh(ids, expirations, command);
}

void rice::p2p::aggregation::AggregationImpl::refresh(::rice::p2p::commonapi::IdArray* ids, ::int64_tArray* expirations, ::rice::Continuation* command)
{
    if(npc(ids)->length < 1) {
        npc(command)->receiveResult(new ::java::lang::BooleanArray({}));
        return;
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Refreshing "_j)->append(npc(ids)->length)
            ->append(u" keys"_j)->toString());

    refreshInObjectStore(ids, expirations, new AggregationImpl_refresh_26(this, ids, command, expirations));
}

void rice::p2p::aggregation::AggregationImpl::refresh(::rice::p2p::commonapi::IdArray* ids, ::int64_tArray* versions, ::int64_tArray* expirations, ::rice::Continuation* command)
{
    auto const result = new ::java::lang::ObjectArray(npc(ids)->length);
    for (auto i = int32_t(0); i < npc(ids)->length; i++) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Refresh("_j)->append(static_cast< ::java::lang::Object* >((*ids)[i]))
                ->append(u"v"_j)
                ->append((*versions)[i])
                ->append(u", expiration="_j)
                ->append((*expirations)[i])
                ->append(u")"_j)->toString());

        auto adc = java_cast< AggregateDescriptor* >(npc(aggregateList)->getADC(new ::rice::p2p::glacier::VersionKey((*ids)[i], (*versions)[i])));
        if(adc != nullptr) {
            auto objDescIndex = npc(adc)->lookupSpecific((*ids)[i], (*versions)[i]);
            if(objDescIndex < 0) {
                result->set(i, new AggregationException(u"Inconsistency detected in aggregate list -- try restarting the application"_j));
            } else {
                if(npc((*npc(adc)->objects)[objDescIndex])->refreshedLifetime < (*expirations)[i])
                    npc(aggregateList)->setObjectRefreshedLifetime(adc, objDescIndex, (*expirations)[i]);

                result->set(i, new ::java::lang::Boolean(true));
            }
        } else
            result->set(i, new AggregationException(u"Not found"_j));
    }
    if(dynamic_cast< ::rice::p2p::glacier::VersioningPast* >(objectStore) != nullptr) {
        npc((java_cast< ::rice::p2p::glacier::VersioningPast* >(objectStore)))->refresh(ids, versions, expirations, new AggregationImpl_refresh_27(this, result, command));
    } else {
        npc(command)->receiveResult(result);
    }
}

void rice::p2p::aggregation::AggregationImpl::refreshInternal(::rice::p2p::commonapi::IdArray* ids, ::int64_tArray* expirations, ::java::lang::ObjectArray* result, ::rice::Continuation* command)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"refreshInternal: Accepted "_j)->append(npc(ids)->length)
            ->append(u" keys, starting with first key..."_j)->toString());

    ::rice::Continuation* const theContinuation = new AggregationImpl_refreshInternal_28(this, ids, result, command, expirations);
    npc(theContinuation)->receiveResult(nullptr);
}

int32_t rice::p2p::aggregation::AggregationImpl::getSize(::rice::p2p::past::PastContent* obj)
{
    try {
        ::rice::p2p::past::rawserialization::RawPastContent* rpc;
        if(dynamic_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(obj) != nullptr) {
            rpc = java_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(obj);
        } else {
            rpc = new ::rice::p2p::past::rawserialization::JavaSerializedPastContent(obj);
        }
        auto buf = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
        npc(buf)->writeShort(npc(rpc)->getType());
        npc(rpc)->serialize(buf);
        return npc(buf)->getWritten();
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Cannot serialize object, size unknown: "_j)->append(static_cast< ::java::lang::Object* >(ioe))->toString());

    }
    return 0;
}

java::io::Serializable* rice::p2p::aggregation::AggregationImpl::getHandle()
{
    return npc(aggregateList)->getRoot();
}

void rice::p2p::aggregation::AggregationImpl::setHandle(::java::io::Serializable* handle, ::rice::Continuation* command)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"setHandle("_j)->append(static_cast< ::java::lang::Object* >(handle))
            ->append(u")"_j)->toString());

    if(!(dynamic_cast< ::rice::p2p::commonapi::Id* >(handle) != nullptr)) {
        npc(command)->receiveException(new AggregationException(u"Illegal handle"_j));
        return;
    }
    if(npc(aggregateList)->getADC(java_cast< ::rice::p2p::commonapi::Id* >(handle)) != nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Rebuild: Handle "_j)->append(static_cast< ::java::lang::Object* >(handle))
                ->append(u" is already covered by current root"_j)->toString());

        npc(command)->receiveResult(new ::java::lang::Boolean(true));
    }
    npc(aggregateList)->setRoot(java_cast< ::rice::p2p::commonapi::Id* >(handle));
    rebuildAggregateList(command);
}

void rice::p2p::aggregation::AggregationImpl::rebuildRecursive(::rice::p2p::commonapi::Id* fromKey, ::java::util::Vector* keysInProgress, ::java::util::Vector* keysPostponed, ::java::util::Vector* keysDone, ::rice::Continuation* command)
{
    npc(keysInProgress)->add(static_cast< ::java::lang::Object* >(fromKey));
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Rebuild: Fetching handles for aggregate "_j)->append(npc(fromKey)->toStringFull())->toString());

    npc(aggregateStore)->lookupHandles(fromKey, 999, new AggregationImpl_rebuildRecursive_29(this, fromKey, keysInProgress, keysDone, keysPostponed, command));
}

void rice::p2p::aggregation::AggregationImpl::rebuildAggregateList(::rice::Continuation* command)
{
    auto keysInProgress = new ::java::util::Vector();
    auto keysPostponed = new ::java::util::Vector();
    auto keysDone = new ::java::util::Vector();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"rebuildAggregateList("_j)->append(static_cast< ::java::lang::Object* >(npc(aggregateList)->getRoot()))
            ->append(u")"_j)->toString());

    if(npc(aggregateList)->getRoot() == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(u"rebuildAggregateList invoked while rootKey is null"_j);

        npc(command)->receiveException(new AggregationException(u"Set handle first!"_j));
        return;
    }
    rebuildInProgress = true;
    rebuildRecursive(npc(aggregateList)->getRoot(), keysInProgress, keysPostponed, keysDone, command);
}

void rice::p2p::aggregation::AggregationImpl::insert(::rice::p2p::past::PastContent* obj, ::rice::Continuation* command)
{
    insert(obj, INFINITY_EXPIRATION, command);
}

void rice::p2p::aggregation::AggregationImpl::insert(::rice::p2p::past::PastContent* obj, int64_t lifetime, ::rice::Continuation* command)
{
    int64_t theVersion;
    if(dynamic_cast< ::rice::p2p::past::gc::GCPastContent* >(obj) != nullptr) {
        theVersion = npc((java_cast< ::rice::p2p::past::gc::GCPastContent* >(obj)))->getVersion();
    } else {
        theVersion = 0;
    }
    auto const vkey = new ::rice::p2p::glacier::VersionKey(npc(obj)->getId(), theVersion);
    auto const theVersionF = theVersion;
    auto const theSize = getSize(obj);
    if(npc(policy)->shouldBeAggregated(obj, theSize)) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"AGGREGATE INSERT: "_j)->append(static_cast< ::java::lang::Object* >(npc(obj)->getId()))
                ->append(u" version="_j)
                ->append(theVersion)
                ->append(u" size="_j)
                ->append(theSize)
                ->append(u" class="_j)
                ->append(npc(npc(obj)->getClass())->getName())->toString());

        if(dynamic_cast< ::rice::p2p::past::gc::GCPast* >(objectStore) != nullptr)
            npc((java_cast< ::rice::p2p::past::gc::GCPast* >(objectStore)))->insert(obj, lifetime, command);
        else
            npc(objectStore)->insert(obj, command);
        npc(waitingList)->store(vkey, new ObjectDescriptor(npc(obj)->getId(), theVersionF, lifetime, lifetime, theSize), obj, new AggregationImpl_insert_30(this, obj));
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"INSERT WITHOUT AGGREGATION: "_j)->append(static_cast< ::java::lang::Object* >(npc(obj)->getId()))
                ->append(u" version="_j)
                ->append(theVersionF)
                ->append(u" size="_j)
                ->append(theSize)
                ->append(u" class="_j)
                ->append(npc(npc(obj)->getClass())->getName())->toString());

        ::rice::Continuation* c = new AggregationImpl_insert_31(this, obj, command);
        if(dynamic_cast< ::rice::p2p::past::gc::GCPast* >(objectStore) != nullptr)
            npc((java_cast< ::rice::p2p::past::gc::GCPast* >(objectStore)))->insert(obj, lifetime, c);
        else
            npc(objectStore)->insert(obj, c);
        if(dynamic_cast< ::rice::p2p::past::gc::GCPast* >(aggregateStore) != nullptr)
            npc((java_cast< ::rice::p2p::past::gc::GCPast* >(aggregateStore)))->insert(new ::rice::p2p::aggregation::messaging::NonAggregate(obj), lifetime, c);
        else
            npc(aggregateStore)->insert(new ::rice::p2p::aggregation::messaging::NonAggregate(obj), c);
    }
}

void rice::p2p::aggregation::AggregationImpl::retrieveObjectFromAggregate(AggregateDescriptor* adc, int32_t objDescIndex, ::rice::Continuation* command)
{
    npc(aggregateStore)->lookup(npc(adc)->key, new AggregationImpl_retrieveObjectFromAggregate_32(this, adc, command, objDescIndex));
}

void rice::p2p::aggregation::AggregationImpl::lookup(::rice::p2p::commonapi::Id* id, bool cache, ::rice::Continuation* command)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"lookup("_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u", cache="_j)
            ->append(cache)
            ->append(u")"_j)->toString());

    npc(objectStore)->lookup(id, cache, new AggregationImpl_lookup_33(this, id, command));
}

void rice::p2p::aggregation::AggregationImpl::lookup(::rice::p2p::commonapi::Id* id, int64_t version, ::rice::Continuation* command)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"lookup("_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u", version="_j)
            ->append(version)
            ->append(u")"_j)->toString());

    auto adc = java_cast< AggregateDescriptor* >(npc(aggregateList)->getADC(new ::rice::p2p::glacier::VersionKey(id, version)));
    if(adc != nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(u"VL: Retrieving from aggregate"_j);

        auto objDescIndex = npc(adc)->lookupSpecific(id, version);
        if(objDescIndex < 0) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(u"VL: Aggregate found, but object not found in aggregate?!? -- aborted"_j);

            npc(command)->receiveException(new AggregationException(u"Inconsistency detected in aggregate list -- try restarting the application"_j));
            return;
        }
        retrieveObjectFromAggregate(adc, objDescIndex, command);
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"VL: Not found in aggregate list: "_j)->append(static_cast< ::java::lang::Object* >(id))
                ->append(u"v"_j)
                ->append(version)->toString());

        if(dynamic_cast< ::rice::p2p::glacier::VersioningPast* >(aggregateStore) != nullptr) {
            auto vaggr = java_cast< ::rice::p2p::glacier::VersioningPast* >(aggregateStore);
            npc(vaggr)->lookup(id, version, new AggregationImpl_lookup_34(this, id, version, command));
        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(u"VL: Aggregate store does not support versioning"_j);

            if(dynamic_cast< ::rice::p2p::glacier::VersioningPast* >(objectStore) != nullptr) {
                auto vpast = java_cast< ::rice::p2p::glacier::VersioningPast* >(objectStore);
                npc(vpast)->lookup(id, version, new AggregationImpl_lookup_35(this, id, version, command));
            }
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(u"VL: Object store does not support versioning"_j);

            npc(command)->receiveResult(nullptr);
        }
    }
}

void rice::p2p::aggregation::AggregationImpl::lookup(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command)
{
    lookup(id, true, command);
}

void rice::p2p::aggregation::AggregationImpl::lookupHandles(::rice::p2p::commonapi::Id* id, int64_t version, int32_t max, ::rice::Continuation* command)
{
    npc((java_cast< ::rice::p2p::glacier::VersioningPast* >(aggregateStore)))->lookupHandles(id, version, max, command);
}

void rice::p2p::aggregation::AggregationImpl::lookupHandle(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* handle, ::rice::Continuation* command)
{
    npc(command)->receiveException(new ::java::lang::UnsupportedOperationException(u"LookupHandle() is not supported on Aggregation"_j));
}

void rice::p2p::aggregation::AggregationImpl::lookupHandles(::rice::p2p::commonapi::Id* id, int32_t max, ::rice::Continuation* command)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"lookupHandles("_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u","_j)
            ->append(max)
            ->append(u")"_j)->toString());

    npc(objectStore)->lookupHandles(id, max, new AggregationImpl_lookupHandles_36(this, id, max, command));
}

void rice::p2p::aggregation::AggregationImpl::fetch(::rice::p2p::past::PastContentHandle* handle, ::rice::Continuation* command)
{
    if(dynamic_cast< ::rice::p2p::glacier::v2::GlacierContentHandle* >(handle) != nullptr)
        npc(aggregateStore)->fetch(handle, command);
    else
        npc(objectStore)->fetch(handle, command);
}

void rice::p2p::aggregation::AggregationImpl::flush(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command)
{
    auto iter = npc(npc(waitingList)->scan())->getIterator();
    auto objectIsWaiting = false;
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"flush("_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u") invoked"_j)->toString());

    while (npc(iter)->hasNext()) {
        auto thisKey = java_cast< ::rice::p2p::glacier::VersionKey* >(java_cast< ::java::lang::Object* >(npc(iter)->next()));
        if(npc(npc(thisKey)->getId())->equals(id)) {
            objectIsWaiting = true;
            break;
        }
    }
    if(objectIsWaiting)
        formAggregates(command);
    else
        npc(command)->receiveResult(new ::java::lang::Boolean(true));
}

void rice::p2p::aggregation::AggregationImpl::flush(::rice::Continuation* command)
{
    formAggregates(command);
}

void rice::p2p::aggregation::AggregationImpl::rollback(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command)
{
    auto adc = java_cast< AggregateDescriptor* >(npc(aggregateList)->getADC(id));
    if(adc != nullptr) {
        auto objDescIndex = npc(adc)->lookupNewest(id);
        if(objDescIndex < 0) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(u"Rollback: Aggregate found, but object not found in aggregate?!? -- aborted"_j);

            npc(command)->receiveException(new AggregationException(u"Inconsistency detected in aggregate list -- try restarting the application"_j));
            return;
        }
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Rollback: Found "_j)->append(static_cast< ::java::lang::Object* >(npc((*npc(adc)->objects)[objDescIndex])->key))
                ->append(u"v"_j)
                ->append(npc((*npc(adc)->objects)[objDescIndex])->version)->toString());

        retrieveObjectFromAggregate(adc, objDescIndex, command);
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Rollback: No version of "_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u" found"_j)->toString());

    npc(command)->receiveResult(nullptr);
}

void rice::p2p::aggregation::AggregationImpl::reset(::rice::Continuation* command)
{
    npc(aggregateList)->clear();
    auto iter = npc(npc(waitingList)->scan())->getIterator();
    while (npc(iter)->hasNext()) {
        auto thisKey = java_cast< ::rice::p2p::glacier::VersionKey* >(java_cast< ::java::lang::Object* >(npc(iter)->next()));
        npc(waitingList)->unstore(thisKey, new AggregationImpl_reset_37(this));
    }
    npc(command)->receiveResult(new ::java::lang::Boolean(true));
}

rice::p2p::commonapi::NodeHandle* rice::p2p::aggregation::AggregationImpl::getLocalNodeHandle()
{
    return npc(objectStore)->getLocalNodeHandle();
}

int32_t rice::p2p::aggregation::AggregationImpl::getReplicationFactor()
{
    return npc(objectStore)->getReplicationFactor();
}

bool rice::p2p::aggregation::AggregationImpl::forward(::rice::p2p::commonapi::RouteMessage* message)
{
    return true;
}

void rice::p2p::aggregation::AggregationImpl::update(::rice::p2p::commonapi::NodeHandle* handle, bool joined)
{
}

void rice::p2p::aggregation::AggregationImpl::deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message)
{
    auto const msg = java_cast< ::rice::p2p::aggregation::messaging::AggregationMessage* >(message);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Received message "_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" with destination "_j)
            ->append(static_cast< ::java::lang::Object* >(id))
            ->append(u" from "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(npc(msg)->getSource())->getId()))->toString());

    if(dynamic_cast< ::rice::p2p::aggregation::messaging::AggregationTimeoutMessage* >(msg) != nullptr) {
        auto gtm = java_cast< ::rice::p2p::aggregation::messaging::AggregationTimeoutMessage* >(msg);
        timerExpired(static_cast< char16_t >(npc(gtm)->getUID()));
        return;
    } else {
        panic(::java::lang::StringBuilder().append(u"AGGREGATION ERROR - Received message "_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" of unknown type."_j)->toString());
    }
}

void rice::p2p::aggregation::AggregationImpl::setFlushInterval(int32_t flushIntervalSec)
{
    flushInterval = flushIntervalSec * SECONDS;
}

void rice::p2p::aggregation::AggregationImpl::setMaxAggregateSize(int32_t maxAggregateSize)
{
    this->maxAggregateSize = maxAggregateSize;
}

void rice::p2p::aggregation::AggregationImpl::setMaxObjectsInAggregate(int32_t maxObjectsInAggregate)
{
    this->maxObjectsInAggregate = maxObjectsInAggregate;
}

void rice::p2p::aggregation::AggregationImpl::setRenewThreshold(int32_t expirationRenewThresholdHrs)
{
    this->expirationRenewThreshold = expirationRenewThresholdHrs * HOURS;
}

void rice::p2p::aggregation::AggregationImpl::setConsolidationInterval(int64_t consolidationIntervalSec)
{
    this->consolidationInterval = consolidationIntervalSec * SECONDS;
}

void rice::p2p::aggregation::AggregationImpl::setConsolidationThreshold(int64_t consolidationThresholdSec)
{
    this->consolidationThreshold = consolidationThresholdSec * SECONDS;
}

void rice::p2p::aggregation::AggregationImpl::setConsolidationMinObjectsPerAggregate(int32_t minObjectsInAggregateArg)
{
    this->consolidationMinObjectsInAggregate = minObjectsInAggregateArg;
}

void rice::p2p::aggregation::AggregationImpl::setConsolidationMinUtilization(double minUtilization)
{
    this->consolidationMinComponentsAlive = minUtilization;
}

rice::p2p::past::Past* rice::p2p::aggregation::AggregationImpl::getAggregateStore()
{
    return aggregateStore;
}

rice::p2p::past::Past* rice::p2p::aggregation::AggregationImpl::getObjectStore()
{
    return objectStore;
}

int32_t rice::p2p::aggregation::AggregationImpl::getNumObjectsWaiting()
{
    return npc(npc(waitingList)->scan())->numElements();
}

rice::p2p::aggregation::AggregationStatistics* rice::p2p::aggregation::AggregationImpl::getStatistics()
{
    return stats;
}

java::lang::String* rice::p2p::aggregation::AggregationImpl::getInstance()
{
    return instance;
}

rice::environment::Environment* rice::p2p::aggregation::AggregationImpl::getEnvironment()
{
    return environment;
}

void rice::p2p::aggregation::AggregationImpl::setContentDeserializer(::rice::p2p::past::rawserialization::PastContentDeserializer* deserializer)
{
    contentDeserializer = deserializer;
    npc(objectStore)->setContentDeserializer(contentDeserializer);
}

void rice::p2p::aggregation::AggregationImpl::setContentHandleDeserializer(::rice::p2p::past::rawserialization::PastContentHandleDeserializer* deserializer)
{
    contentHandleDeserializer = deserializer;
    npc(objectStore)->setContentHandleDeserializer(deserializer);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.aggregation.AggregationImpl", 36);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl::getClass0()
{
    return class_();
}

