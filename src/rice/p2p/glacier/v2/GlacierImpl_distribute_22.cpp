// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_distribute_22.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Observable.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/glacier/Fragment.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/GlacierException.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/Manifest.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierDataMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierQueryMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierResponseMessage.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>
#include <Array.hpp>

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
typedef ::SubArray< ::rice::p2p::glacier::Fragment, ::java::lang::ObjectArray, ::java::io::SerializableArray > FragmentArray;
typedef ::SubArray< ::rice::p2p::glacier::FragmentKey, ::java::lang::ObjectArray, ::rice::p2p::commonapi::IdArray > FragmentKeyArray;

            namespace v2
            {
typedef ::SubArray< ::rice::p2p::glacier::v2::Manifest, ::java::lang::ObjectArray, ::java::io::SerializableArray > ManifestArray;
            } // v2
        } // glacier
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

rice::p2p::glacier::v2::GlacierImpl_distribute_22::GlacierImpl_distribute_22(GlacierImpl *GlacierImpl_this, ::rice::p2p::glacier::FragmentArray* fragments, ::rice::p2p::glacier::VersionKey* key, char16_t tag, ManifestArray* manifests, int64_t expiration, ::rice::Continuation* command, int64_t tStart)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
    , fragments(fragments)
    , key(key)
    , tag(tag)
    , manifests(manifests)
    , expiration(expiration)
    , command(command)
    , tStart(tStart)
{
    clinit();
    init();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_distribute_22::init()
{
    doInsert = (fragments != nullptr);
    doRefresh = !doInsert;
    answered = false;
    inhibitInsertions = true;
    minAcceptable = static_cast< int32_t >((GlacierImpl_this->numSurvivors * GlacierImpl_this->minFragmentsAfterInsert));
}

java::lang::String* rice::p2p::glacier::v2::GlacierImpl_distribute_22::toString()
{
    return ::java::lang::StringBuilder().append(whoAmI())->append(u" continuation for "_j)
        ->append(static_cast< ::java::lang::Object* >(key))->toString();
}

int32_t rice::p2p::glacier::v2::GlacierImpl_distribute_22::numReceiptsReceived()
{
    auto result = int32_t(0);
    for (auto i = int32_t(0); i < npc(receiptReceived)->length; i++) 
                if((*receiptReceived)[i])
            result++;


    return result;
}

int32_t rice::p2p::glacier::v2::GlacierImpl_distribute_22::numHoldersKnown()
{
    auto result = int32_t(0);
    for (auto i = int32_t(0); i < npc(holder)->length; i++) 
                if((*holder)[i] != nullptr)
            result++;


    return result;
}

java::lang::String* rice::p2p::glacier::v2::GlacierImpl_distribute_22::whoAmI()
{
    return (doRefresh) ? u"Refresh"_j : u"Insert"_j;
}

void rice::p2p::glacier::v2::GlacierImpl_distribute_22::init_()
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Initializing "_j)->append(whoAmI())
            ->append(u" continuation for "_j)
            ->append(static_cast< ::java::lang::Object* >(key))->toString());

    holder = new ::rice::p2p::commonapi::NodeHandleArray(GlacierImpl_this->numFragments);
    receiptReceived = new ::boolArray(GlacierImpl_this->numFragments);
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Sending queries for "_j)->append(static_cast< ::java::lang::Object* >(key))->toString());

    for (auto i = int32_t(0); i < GlacierImpl_this->numFragments; i++) {
        auto fragmentLoc = GlacierImpl_this->getFragmentLocation(npc(key)->getId(), i, npc(key)->getVersion());
        auto keys = new ::rice::p2p::glacier::FragmentKeyArray(int32_t(1));
        keys->set(int32_t(0), new ::rice::p2p::glacier::FragmentKey(key, i));
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Query #"_j)->append(i)
                ->append(u" to "_j)
                ->append(static_cast< ::java::lang::Object* >(fragmentLoc))->toString());

        GlacierImpl_this->sendMessage(fragmentLoc, new ::rice::p2p::glacier::v2::messaging::GlacierQueryMessage(getMyUID(), keys, GlacierImpl_this->getLocalNodeHandle(), fragmentLoc, tag), nullptr);
    }
}

void rice::p2p::glacier::v2::GlacierImpl_distribute_22::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierResponseMessage* >(o) != nullptr) {
        auto grm = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierResponseMessage* >(o);
        if(!npc(npc(npc(grm)->getKey(0))->getVersionKey())->equals(static_cast< ::java::lang::Object* >(key))) {
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(whoAmI())->append(u" response got routed to the wrong key: "_j)
                    ->append(static_cast< ::java::lang::Object* >(key))->toString());

            return;
        }
        auto fragmentID = npc(npc(grm)->getKey(0))->getFragmentID();
        if(fragmentID < GlacierImpl_this->numFragments) {
            if(npc(grm)->getAuthoritative(0)) {
                if(doInsert && !npc(grm)->getHaveIt(0)) {
                    if((*holder)[fragmentID] == nullptr) {
                        holder->set(fragmentID, npc(grm)->getSource());
                        if(!inhibitInsertions) {
                            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Got insert response, sending fragment "_j)->append(static_cast< ::java::lang::Object* >(npc(grm)->getKey(0)))->toString());

                            GlacierImpl_this->sendMessage(nullptr, new ::rice::p2p::glacier::v2::messaging::GlacierDataMessage(getMyUID(), npc(grm)->getKey(0), (*fragments)[fragmentID], (*manifests)[fragmentID], GlacierImpl_this->getLocalNodeHandle(), npc(npc(grm)->getSource())->getId(), false, tag), npc(grm)->getSource());
                        } else {
                            if(numHoldersKnown() >= minAcceptable) {
                                if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                                    npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Got "_j)->append(numHoldersKnown())
                                        ->append(u" insert responses, sending fragments..."_j)->toString());

                                inhibitInsertions = false;
                                for (auto i = int32_t(0); i < npc(holder)->length; i++) {
                                    if((*holder)[i] != nullptr) {
                                        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                                            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Sending fragment #"_j)->append(i)->toString());

                                        GlacierImpl_this->sendMessage(nullptr, new ::rice::p2p::glacier::v2::messaging::GlacierDataMessage(getMyUID(), new ::rice::p2p::glacier::FragmentKey(key, i), (*fragments)[i], (*manifests)[i], GlacierImpl_this->getLocalNodeHandle(), npc((*holder)[i])->getId(), false, tag), (*holder)[i]);
                                    }
                                }
                                if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                                    npc(GlacierImpl_this->logger)->log(u"Done sending fragments, now accepting further responses"_j);

                            } else {
                                if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                                    npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Got insert response #"_j)->append(numHoldersKnown())
                                        ->append(u" ("_j)
                                        ->append(minAcceptable)
                                        ->append(u" needed to start insertion)"_j)->toString());

                            }
                        }
                    } else {
                        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                            npc(GlacierImpl_this->logger)->log(u"Received two insert responses for the same fragment -- discarded"_j);

                    }
                } else if(npc(grm)->getHaveIt(0) && (npc(grm)->getExpiration(0) < expiration)) {
                    if((*holder)[fragmentID] == nullptr) {
                        holder->set(fragmentID, npc(grm)->getSource());
                        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Got refresh response (exp="_j)->append(npc(grm)->getExpiration(0))
                                ->append(u"<"_j)
                                ->append(expiration)
                                ->append(u"), sending manifest "_j)
                                ->append(static_cast< ::java::lang::Object* >(npc(grm)->getKey(0)))->toString());

                        GlacierImpl_this->sendMessage(nullptr, new ::rice::p2p::glacier::v2::messaging::GlacierDataMessage(getMyUID(), npc(grm)->getKey(0), static_cast< ::rice::p2p::glacier::Fragment* >(nullptr), (*manifests)[fragmentID], GlacierImpl_this->getLocalNodeHandle(), npc(npc(grm)->getSource())->getId(), false, tag), npc(grm)->getSource());
                        if(doRefresh) {
                            (*receiptReceived)[fragmentID] = true;
                            if((numReceiptsReceived() >= minAcceptable) && !answered) {
                                answered = true;
                                reportSuccess();
                            }
                        }
                    } else {
                        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                            npc(GlacierImpl_this->logger)->log(u"Received two refresh responses for the same fragment -- discarded"_j);

                    }
                } else if(npc(grm)->getHaveIt(0) && (npc(grm)->getExpiration(0) >= expiration)) {
                    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Receipt received after "_j)->append(whoAmI())
                            ->append(u": "_j)
                            ->append(static_cast< ::java::lang::Object* >(npc(grm)->getKey(0)))->toString());

                    (*receiptReceived)[fragmentID] = true;
                    if((numReceiptsReceived() >= minAcceptable) && !answered) {
                        answered = true;
                        reportSuccess();
                    }
                }
            } else {
                if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(whoAmI())->append(u" response, but not authoritative -- ignoring"_j)->toString());

            }
        } else {
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Fragment ID too large in "_j)->append(whoAmI())
                    ->append(u" response -- discarded"_j)->toString());

        }
        return;
    } else {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Unknown response to "_j)->append(whoAmI())
                ->append(u" continuation: "_j)
                ->append(static_cast< ::java::lang::Object* >(o))
                ->append(u" -- discarded"_j)->toString());

    }
}

void rice::p2p::glacier::v2::GlacierImpl_distribute_22::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Exception during "_j)->append(whoAmI())
            ->append(u"("_j)
            ->append(static_cast< ::java::lang::Object* >(key))
            ->append(u"): "_j)->toString(), e);

    if(!answered) {
        answered = true;
        npc(command)->receiveException(new ::rice::p2p::glacier::GlacierException(::java::lang::StringBuilder().append(u"Exception while inserting/refreshing: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString()));
    }
    terminate();
}

void rice::p2p::glacier::v2::GlacierImpl_distribute_22::reportSuccess()
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Reporting success for "_j)->append(static_cast< ::java::lang::Object* >(key))
            ->append(u", "_j)
            ->append(numReceiptsReceived())
            ->append(u"/"_j)
            ->append(GlacierImpl_this->numFragments)
            ->append(u" receipts received so far"_j)->toString());

    if(doInsert)
        npc(command)->receiveResult(new ::java::lang::BooleanArray({new ::java::lang::Boolean(true)}));
    else
        npc(command)->receiveResult(new ::java::lang::Boolean(true));
}

void rice::p2p::glacier::v2::GlacierImpl_distribute_22::timeoutExpired()
{
    if(numReceiptsReceived() >= minAcceptable) {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(whoAmI())->append(u" of "_j)
                ->append(static_cast< ::java::lang::Object* >(key))
                ->append(u" successful, "_j)
                ->append(numReceiptsReceived())
                ->append(u"/"_j)
                ->append(GlacierImpl_this->numFragments)
                ->append(u" receipts received"_j)->toString());

        if(!answered) {
            answered = true;
            reportSuccess();
        }
    } else {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(whoAmI())->append(u" "_j)
                ->append(static_cast< ::java::lang::Object* >(key))
                ->append(u" failed, only "_j)
                ->append(numReceiptsReceived())
                ->append(u"/"_j)
                ->append(GlacierImpl_this->numFragments)
                ->append(u" receipts received"_j)->toString());

        if(!answered) {
            answered = true;
            npc(command)->receiveException(new ::rice::p2p::glacier::GlacierException(::java::lang::StringBuilder().append(whoAmI())->append(u" failed, did not receive enough receipts"_j)->toString()));
        }
    }
    terminate();
}

int64_t rice::p2p::glacier::v2::GlacierImpl_distribute_22::getTimeout()
{
    return tStart + ((doRefresh) ? GlacierImpl_this->refreshTimeout : GlacierImpl_this->insertTimeout);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_distribute_22::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_distribute_22::getClass0()
{
    return class_();
}

