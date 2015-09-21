// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_refresh_21.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/Observable.hpp>
#include <java/util/Vector.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/GlacierException.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/GlacierPolicy.hpp>
#include <rice/p2p/glacier/v2/Manifest.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierDataMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierFetchMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierRefreshCompleteMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierRefreshPatchMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierRefreshProbeMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierRefreshResponseMessage.hpp>
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
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace util
    {
typedef ::SubArray< ::java::util::Observable, ::java::lang::ObjectArray > ObservableArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandle, ::java::util::ObservableArray, ::java::io::SerializableArray > NodeHandleArray;
        } // commonapi

        namespace glacier
        {
typedef ::SubArray< ::rice::p2p::glacier::FragmentKey, ::java::lang::ObjectArray, ::rice::p2p::commonapi::IdArray > FragmentKeyArray;
typedef ::SubArray< ::rice::p2p::glacier::VersionKey, ::java::lang::ObjectArray, ::rice::p2p::commonapi::IdArray, ::java::io::SerializableArray > VersionKeyArray;

            namespace v2
            {
typedef ::SubArray< ::rice::p2p::glacier::v2::Manifest, ::java::lang::ObjectArray, ::java::io::SerializableArray > ManifestArray;
            } // v2
        } // glacier
    } // p2p
} // rice

namespace 
{
typedef ::SubArray< ::int8_tArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > int8_tArrayArray;
} // 

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::IdArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > IdArrayArray;
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandleArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > NodeHandleArrayArray;
        } // commonapi

        namespace glacier
        {
typedef ::SubArray< ::rice::p2p::glacier::FragmentKeyArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > FragmentKeyArrayArray;
        } // glacier
    } // p2p
} // rice

namespace 
{
typedef ::SubArray< ::boolArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > boolArrayArray;
} // 

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

rice::p2p::glacier::v2::GlacierImpl_refresh_21::GlacierImpl_refresh_21(GlacierImpl *GlacierImpl_this, ::rice::p2p::commonapi::IdArray* ids, ::int64_tArray* versions, ::rice::Continuation* command, ::int64_tArray* expirations)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
    , ids(ids)
    , versions(versions)
    , command(command)
    , expirations(expirations)
{
    clinit();
    init();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_refresh_21::init()
{
    minAcceptable = static_cast< int32_t >((GlacierImpl_this->numSurvivors * GlacierImpl_this->minFragmentsAfterInsert));
}

constexpr int32_t rice::p2p::glacier::v2::GlacierImpl_refresh_21::stageProbing;

constexpr int32_t rice::p2p::glacier::v2::GlacierImpl_refresh_21::stageFetchingManifests;

constexpr int32_t rice::p2p::glacier::v2::GlacierImpl_refresh_21::stagePatching;

java::lang::String* rice::p2p::glacier::v2::GlacierImpl_refresh_21::toString()
{
    return ::java::lang::StringBuilder().append(u"AggregateRefresh continuation ("_j)->append(npc(fragmentKey)->length)
        ->append(u" fragments)"_j)->toString();
}

void rice::p2p::glacier::v2::GlacierImpl_refresh_21::init_()
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(GlacierImpl_this->logger)->log(u"Initializing AggregateRefresh continuation"_j);

    fragmentKey = new ::rice::p2p::glacier::FragmentKeyArrayArray(npc(ids)->length);
    fragmentLocation = new ::rice::p2p::commonapi::IdArrayArray(npc(ids)->length);
    fragmentHolder = new ::rice::p2p::commonapi::NodeHandleArrayArray(npc(ids)->length);
    fragmentChecked = new ::boolArrayArray(npc(ids)->length);
    manifests = new ManifestArray(npc(ids)->length);
    versionKey = new ::rice::p2p::glacier::VersionKeyArray(npc(ids)->length);
    successes = new ::int32_tArray(npc(ids)->length);
    nextTimeout = npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis() + GlacierImpl_this->bulkRefreshProbeInterval;
    currentStage = stageProbing;
    holders = new ::java::util::Vector();
    retriesRemaining = static_cast< int32_t >((GlacierImpl_this->bulkRefreshMaxProbeFactor * GlacierImpl_this->numFragments));
    answered = false;
    auto haveFragmentMyself = false;
    for (auto i = int32_t(0); i < npc(ids)->length; i++) {
        manifests->set(i, nullptr);
        versionKey->set(i, new ::rice::p2p::glacier::VersionKey((*ids)[i], (*versions)[i]));
        for (auto j = int32_t(0); j < GlacierImpl_this->numFragments; j++) {
            (*fragmentKey)[i]->set(j, new ::rice::p2p::glacier::FragmentKey(new ::rice::p2p::glacier::VersionKey((*ids)[i], (*versions)[i]), j));
            (*fragmentLocation)[i]->set(j, GlacierImpl_this->getFragmentLocation((*(*fragmentKey)[i])[j]));
            (*(*fragmentChecked)[i])[j] = false;
            if(npc(GlacierImpl_this->fragmentStorage)->getMetadata((*(*fragmentKey)[i])[j]) != nullptr) {
                haveFragmentMyself = true;
                (*fragmentHolder)[i]->set(j, GlacierImpl_this->getLocalNodeHandle());
            } else {
                (*fragmentHolder)[i]->set(j, nullptr);
            }
        }
    }
    if(haveFragmentMyself)
        npc(holders)->add(static_cast< ::java::lang::Object* >(GlacierImpl_this->getLocalNodeHandle()));

    ::java::util::Arrays::fill(successes, int32_t(0));
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"AR Initialization completed, "_j)->append(npc(fragmentKey)->length)
            ->append(u" candidate objects. Triggering first probe..."_j)->toString());

    timeoutExpired();
}

void rice::p2p::glacier::v2::GlacierImpl_refresh_21::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierRefreshResponseMessage* >(o) != nullptr) {
        auto grrm = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierRefreshResponseMessage* >(o);
        auto thisRange = npc(grrm)->getRange();
        auto holder = npc(grrm)->isOnline() ? npc(grrm)->getSource() : static_cast< ::rice::p2p::commonapi::NodeHandle* >(nullptr);
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"AR got refresh response: range "_j)->append(static_cast< ::java::lang::Object* >(thisRange))
                ->append(u", online="_j)
                ->append(npc(grrm)->isOnline())->toString());

        if(thisRange != nullptr) {
            for (auto i = int32_t(0); i < npc(ids)->length; i++) {
                for (auto j = int32_t(0); j < GlacierImpl_this->numFragments; j++) {
                    if(npc(thisRange)->containsId((*(*fragmentLocation)[i])[j])) {
                        (*(*fragmentChecked)[i])[j] = true;
                        (*fragmentHolder)[i]->set(j, holder);
                    }
                }
            }
        }
        if(!npc(holders)->contains(static_cast< ::java::lang::Object* >(holder)))
            npc(holders)->add(static_cast< ::java::lang::Object* >(holder));

    } else if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierDataMessage* >(o) != nullptr) {
        auto gdm = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierDataMessage* >(o);
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"AR Received data message with "_j)->append(npc(gdm)->numKeys())
                ->append(u" keys"_j)->toString());

        for (auto i = int32_t(0); i < npc(gdm)->numKeys(); i++) {
            if((npc(gdm)->getManifest(i) != nullptr) && (npc(gdm)->getKey(i) != nullptr)) {
                auto thisManifest = npc(gdm)->getManifest(i);
                auto thisKey = npc(gdm)->getKey(i);
                if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"AR Received manifest for "_j)->append(static_cast< ::java::lang::Object* >(npc(gdm)->getKey(i)))
                        ->append(u", checking signature..."_j)->toString());

                if(npc(GlacierImpl_this->policy)->checkSignature(thisManifest, npc(thisKey)->getVersionKey())) {
                    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(GlacierImpl_this->logger)->log(u"AR Signature OK"_j);

                    for (auto j = int32_t(0); j < npc(ids)->length; j++) {
                        if(((*manifests)[j] == nullptr) && (npc((*versionKey)[j])->equals(static_cast< ::java::lang::Object* >(npc(thisKey)->getVersionKey())))) {
                            manifests->set(j, thisManifest);
                            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"AR Storing under #"_j)->append(j)->toString());

                        }
                    }
                } else {
                    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(GlacierImpl_this->logger)->log(u"AR Invalid signature"_j);

                }
            }
        }
    } else if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierRefreshCompleteMessage* >(o) != nullptr) {
        auto grcm = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierRefreshCompleteMessage* >(o);
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"AR Refresh completion reported by "_j)->append(static_cast< ::java::lang::Object* >(npc(grcm)->getSource()))->toString());

        for (auto i = int32_t(0); i < npc(grcm)->numKeys(); i++) {
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"AR Refresh completion: Key "_j)->append(static_cast< ::java::lang::Object* >(npc(grcm)->getKey(i)))
                    ->append(u", "_j)
                    ->append(npc(grcm)->getUpdates(i))
                    ->append(u" update(s)"_j)->toString());

            auto index = -int32_t(1);
            for (auto j = int32_t(0); j < npc(ids)->length; j++) {
                if(npc(npc(grcm)->getKey(i))->equals(static_cast< ::java::lang::Object* >((*versionKey)[j])))
                    index = j;

            }
            if(index >= 0) {
                auto maxSuccesses = int32_t(0);
                for (auto j = int32_t(0); j < GlacierImpl_this->numFragments; j++) {
                    if(!(*(*fragmentChecked)[index])[j] && ((*(*fragmentHolder)[index])[j] != nullptr) && (npc((*(*fragmentHolder)[index])[j])->equals(npc(grcm)->getSource()))) {
                        maxSuccesses++;
                        (*(*fragmentChecked)[index])[j] = true;
                    }
                }
                if(npc(grcm)->getUpdates(i) > maxSuccesses) {
                    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Node "_j)->append(static_cast< ::java::lang::Object* >(npc(grcm)->getSource()))
                            ->append(u" reports "_j)
                            ->append(npc(grcm)->getUpdates(i))
                            ->append(u" for "_j)
                            ->append(static_cast< ::java::lang::Object* >(npc(grcm)->getKey(i)))
                            ->append(u", but is responsible for only "_j)
                            ->append(maxSuccesses)
                            ->append(u" fragments -- duplicate message, or under attack?"_j)->toString());

                    (*successes)[index] += maxSuccesses;
                } else {
                    (*successes)[index] += npc(grcm)->getUpdates(i);
                }
            } else {
                if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Node "_j)->append(static_cast< ::java::lang::Object* >(npc(grcm)->getSource()))
                        ->append(u" reports completion for "_j)
                        ->append(static_cast< ::java::lang::Object* >(npc(grcm)->getKey(i)))
                        ->append(u", but no refresh request matches?!?"_j)->toString());

            }
        }
        if(!answered) {
            auto allSuccessful = true;
            for (auto i = int32_t(0); i < npc(successes)->length; i++) 
                                if((*successes)[i] < minAcceptable)
                    allSuccessful = false;


            if(allSuccessful) {
                if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(GlacierImpl_this->logger)->log(u"AR Reporing success"_j);

                auto result = new ::java::lang::ObjectArray(npc(ids)->length);
                for (auto i = int32_t(0); i < npc(ids)->length; i++) 
                                        result->set(i, new ::java::lang::Boolean(true));

                answered = true;
                npc(command)->receiveResult(result);
            }
        }
    } else {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Unexpected result in AR continuation: "_j)->append(static_cast< ::java::lang::Object* >(o))
                ->append(u" -- discarded"_j)->toString());

    }
}

void rice::p2p::glacier::v2::GlacierImpl_refresh_21::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->logException(u"Exception during AggregateRefresh: "_j, e);

    terminate();
    if(!answered) {
        auto result = new ::java::lang::ObjectArray(npc(ids)->length);
        ::java::lang::Exception* ee = new ::rice::p2p::glacier::GlacierException(::java::lang::StringBuilder().append(u"Exception during refresh: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        for (auto i = int32_t(0); i < npc(ids)->length; i++) 
                        result->set(i, ee);

        answered = true;
        npc(command)->receiveResult(result);
    }
}

void rice::p2p::glacier::v2::GlacierImpl_refresh_21::timeoutExpired()
{
    if(currentStage == stageProbing) {
        nextTimeout = npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis() + GlacierImpl_this->bulkRefreshProbeInterval;
        auto nextProbe = npc(npc(GlacierImpl_this->environment)->getRandomSource())->nextInt(npc(ids)->length);
        auto nextFID = npc(npc(GlacierImpl_this->environment)->getRandomSource())->nextInt(GlacierImpl_this->numFragments);
        auto maxSteps = npc(ids)->length * GlacierImpl_this->numFragments;
        while ((maxSteps > 0) && (*(*fragmentChecked)[nextProbe])[nextFID]) {
            nextFID++;
            if(nextFID >= GlacierImpl_this->numFragments) {
                nextFID = 0;
                nextProbe = (nextProbe + int32_t(1)) % npc(ids)->length;
            }
            maxSteps--;
        }
        if(!(*(*fragmentChecked)[nextProbe])[nextFID] && (retriesRemaining > 0)) {
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"AR Sending a probe to "_j)->append(static_cast< ::java::lang::Object* >((*(*fragmentKey)[nextProbe])[nextFID]))
                    ->append(u" at "_j)
                    ->append(static_cast< ::java::lang::Object* >((*(*fragmentLocation)[nextProbe])[nextFID]))
                    ->append(u" ("_j)
                    ->append(retriesRemaining)
                    ->append(u" probes left)"_j)->toString());

            (*(*fragmentChecked)[nextProbe])[nextFID] = true;
            retriesRemaining--;
            GlacierImpl_this->sendMessage((*(*fragmentLocation)[nextProbe])[nextFID], new ::rice::p2p::glacier::v2::messaging::GlacierRefreshProbeMessage(getMyUID(), (*(*fragmentLocation)[nextProbe])[nextFID], GlacierImpl_this->getLocalNodeHandle(), (*(*fragmentLocation)[nextProbe])[nextFID], GlacierImpl_this->tagRefresh), nullptr);
        } else {
            currentStage = stageFetchingManifests;
            retriesRemaining = 3;
        }
    }
    if(currentStage == stageFetchingManifests) {
        nextTimeout = npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis() + GlacierImpl_this->bulkRefreshManifestInterval;
        auto objectCovered = new ::boolArray(npc(ids)->length);
        auto allObjectsCovered = true;
        for (auto i = int32_t(0); i < npc(ids)->length; i++) {
            (*objectCovered)[i] = ((*manifests)[i] != nullptr);
            allObjectsCovered &= (*objectCovered)[i];
        }
        if(!allObjectsCovered && ((retriesRemaining--) > 0)) {
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"AR Fetching manifests, "_j)->append(retriesRemaining)
                    ->append(u" attempts remaining"_j)->toString());

            while (true) {
                auto idx = npc(npc(GlacierImpl_this->environment)->getRandomSource())->nextInt(npc(ids)->length);
                auto maxSteps = npc(ids)->length + int32_t(2);
                while ((*objectCovered)[idx] && ((--maxSteps) > 0)) 
                                        idx = (idx + int32_t(1)) % npc(ids)->length;

                if(maxSteps <= 0)
                    break;

                auto fid = npc(npc(GlacierImpl_this->environment)->getRandomSource())->nextInt(GlacierImpl_this->numFragments);
                maxSteps = GlacierImpl_this->numFragments + int32_t(2);
                while (((*(*fragmentHolder)[idx])[fid] == nullptr) && ((--maxSteps) > 0)) 
                                        fid = (fid + int32_t(1)) % GlacierImpl_this->numFragments;

                if((*(*fragmentHolder)[idx])[fid] != nullptr) {
                    auto thisHolder = (*(*fragmentHolder)[idx])[fid];
                    auto idsToQuery = new ::java::util::Vector();
                    for (auto i = int32_t(0); i < npc(ids)->length; i++) {
                        if(!(*objectCovered)[i]) {
                            for (auto j = int32_t(0); j < GlacierImpl_this->numFragments; j++) {
                                if(((*(*fragmentHolder)[i])[j] != nullptr) && (npc((*(*fragmentHolder)[i])[j])->equals(thisHolder))) {
                                    npc(idsToQuery)->add(static_cast< ::java::lang::Object* >((*(*fragmentKey)[i])[j]));
                                    (*objectCovered)[i] = true;
                                    break;
                                }
                            }
                        }
                    }
                    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"AR Asking "_j)->append(static_cast< ::java::lang::Object* >(thisHolder))
                            ->append(u" for "_j)
                            ->append(npc(idsToQuery)->size())
                            ->append(u" manifests"_j)->toString());

                    for (auto i = int32_t(0); i < npc(idsToQuery)->size(); i += GlacierImpl_this->bulkRefreshManifestAggregationFactor) {
                        auto idsHere = ::java::lang::Math::min(npc(idsToQuery)->size() - i, GlacierImpl_this->bulkRefreshManifestAggregationFactor);
                        auto keys = new ::rice::p2p::glacier::FragmentKeyArray(idsHere);
                        for (auto j = int32_t(0); j < idsHere; j++) 
                                                        keys->set(j, java_cast< ::rice::p2p::glacier::FragmentKey* >(java_cast< ::java::lang::Object* >(npc(idsToQuery)->elementAt(i + j))));

                        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"AR Sending a manifest fetch with "_j)->append(idsHere)
                                ->append(u" IDs, starting at "_j)
                                ->append(static_cast< ::java::lang::Object* >((*keys)[int32_t(0)]))->toString());

                        GlacierImpl_this->sendMessage(nullptr, new ::rice::p2p::glacier::v2::messaging::GlacierFetchMessage(getMyUID(), keys, ::rice::p2p::glacier::v2::messaging::GlacierFetchMessage::FETCH_MANIFEST, GlacierImpl_this->getLocalNodeHandle(), npc(thisHolder)->getId(), GlacierImpl_this->tagRefresh), thisHolder);
                    }
                } else {
                    (*objectCovered)[idx] = true;
                }
            }
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(GlacierImpl_this->logger)->log(u"AR Manifest fetches sent; awaiting responses..."_j);

        } else {
            currentStage = stagePatching;
            retriesRemaining = GlacierImpl_this->bulkRefreshPatchRetries;
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(GlacierImpl_this->logger)->log(u"AR Patching manifests..."_j);

            for (auto i = int32_t(0); i < npc(ids)->length; i++) 
                                if((*manifests)[i] != nullptr)
                    manifests->set(i, npc(GlacierImpl_this->policy)->updateManifest((*versionKey)[i], (*manifests)[i], (*expirations)[i]));


            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(GlacierImpl_this->logger)->log(u"AR Done patching manifests"_j);

            for (auto i = int32_t(0); i < npc(ids)->length; i++) 
                                for (auto j = int32_t(0); j < GlacierImpl_this->numFragments; j++) 
                                        (*(*fragmentChecked)[i])[j] = (((*(*fragmentHolder)[i])[j] == nullptr) || ((*manifests)[i] == nullptr));


        }
    }
    if(currentStage == stagePatching) {
        nextTimeout = npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis() + GlacierImpl_this->bulkRefreshPatchInterval;
        if((retriesRemaining--) > 0) {
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"AR Sending patches... ("_j)->append(retriesRemaining)
                    ->append(u" retries left)"_j)->toString());

            auto totalPatchesSent = int32_t(0);
            for (auto h = int32_t(0); h < npc(holders)->size(); h++) {
                auto thisHolder = java_cast< ::rice::p2p::commonapi::NodeHandle* >(java_cast< ::java::lang::Object* >(npc(holders)->elementAt(h)));
                auto sendPatchForObject = new ::boolArray(npc(ids)->length);
                auto numPatches = int32_t(0);
                for (auto i = int32_t(0); i < npc(ids)->length; i++) {
                    (*sendPatchForObject)[i] = false;
                    for (auto j = int32_t(0); j < GlacierImpl_this->numFragments; j++) 
                                                if(!(*(*fragmentChecked)[i])[j] && npc((*(*fragmentHolder)[i])[j])->equals(thisHolder))
                            (*sendPatchForObject)[i] = true;


                    if((*sendPatchForObject)[i])
                        numPatches++;

                }
                if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"AR Holder #"_j)->append(h)
                        ->append(u" ("_j)
                        ->append(static_cast< ::java::lang::Object* >(thisHolder))
                        ->append(u") should get "_j)
                        ->append(numPatches)
                        ->append(u" patches"_j)->toString());

                auto nextPatch = int32_t(0);
                for (auto i = int32_t(0); i < numPatches; i += GlacierImpl_this->bulkRefreshPatchAggregationFactor) {
                    auto patchesHere = ::java::lang::Math::min(numPatches - i, GlacierImpl_this->bulkRefreshPatchAggregationFactor);
                    auto keys = new ::rice::p2p::glacier::VersionKeyArray(patchesHere);
                    auto lifetimes = new ::int64_tArray(patchesHere);
                    auto signatures = new ::int8_tArrayArray(patchesHere);
                    for (auto j = int32_t(0); j < patchesHere; j++) {
                        while (!(*sendPatchForObject)[nextPatch]) 
                                                        nextPatch++;

                        keys->set(j, (*versionKey)[nextPatch]);
                        (*lifetimes)[j] = (*expirations)[nextPatch];
                        signatures->set(j, npc((*manifests)[nextPatch])->signature);
                        nextPatch++;
                    }
                    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"AR Sending a patch with "_j)->append(patchesHere)
                            ->append(u" IDs, starting at "_j)
                            ->append(static_cast< ::java::lang::Object* >((*keys)[int32_t(0)]))
                            ->append(u", to "_j)
                            ->append(static_cast< ::java::lang::Object* >(npc(thisHolder)->getId()))->toString());

                    totalPatchesSent += patchesHere;
                    GlacierImpl_this->sendMessage(nullptr, new ::rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage(getMyUID(), keys, lifetimes, signatures, GlacierImpl_this->getLocalNodeHandle(), npc(thisHolder)->getId(), GlacierImpl_this->tagRefresh), thisHolder);
                }
            }
            if(totalPatchesSent == 0) {
                if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(GlacierImpl_this->logger)->log(u"AR No patches sent; refresh seems to be complete..."_j);

                retriesRemaining = 0;
                timeoutExpired();
            }
        } else {
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(GlacierImpl_this->logger)->log(u"AR Giving up"_j);

            terminate();
            auto result = new ::java::lang::ObjectArray(npc(ids)->length);
            for (auto i = int32_t(0); i < npc(ids)->length; i++) {
                result->set(i, ((*successes)[i] >= minAcceptable) ? java_cast< ::java::lang::Object* >((new ::java::lang::Boolean(true))) : java_cast< ::java::lang::Object* >((new ::rice::p2p::glacier::GlacierException(::java::lang::StringBuilder().append(u"Only "_j)->append((*successes)[i])
                    ->append(u" fragments of "_j)
                    ->append(static_cast< ::java::lang::Object* >((*versionKey)[i]))
                    ->append(u" refreshed successfully; need "_j)
                    ->append(minAcceptable)->toString()))));
                if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u" - AR Result for "_j)->append(static_cast< ::java::lang::Object* >((*versionKey)[i]))
                        ->append(u": "_j)
                        ->append(((dynamic_cast< ::java::lang::Boolean* >((*result)[i]) != nullptr) ? u"OK"_j : u"Failed"_j))
                        ->append(u" (with "_j)
                        ->append((*successes)[i])
                        ->append(u"/"_j)
                        ->append(GlacierImpl_this->numFragments)
                        ->append(u" fragments, "_j)
                        ->append(minAcceptable)
                        ->append(u" acceptable)"_j)->toString());

            }
            answered = true;
            npc(command)->receiveResult(result);
        }
    }
}

int64_t rice::p2p::glacier::v2::GlacierImpl_refresh_21::getTimeout()
{
    return nextTimeout;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_refresh_21::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_refresh_21::getClass0()
{
    return class_();
}

