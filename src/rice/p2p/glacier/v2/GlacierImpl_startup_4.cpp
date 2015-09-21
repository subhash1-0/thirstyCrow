// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_startup_4.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/glacier/Fragment.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/v2/FragmentAndManifest.hpp>
#include <rice/p2p/glacier/v2/FragmentMetadata.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_4_receiveResult_4_1.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_4_receiveResult_4_2.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_4_receiveResult_4_3.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/GlacierPolicy.hpp>
#include <rice/p2p/glacier/v2/Manifest.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierDataMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierQueryMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierResponseMessage.hpp>
#include <rice/persistence/StorageManager.hpp>
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
typedef ::SubArray< ::rice::p2p::glacier::FragmentKey, ::java::lang::ObjectArray, ::rice::p2p::commonapi::IdArray > FragmentKeyArray;
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

rice::p2p::glacier::v2::GlacierImpl_startup_4::GlacierImpl_startup_4(GlacierImpl *GlacierImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
{
    clinit();
    ctor();
}

java::lang::String* rice::p2p::glacier::v2::GlacierImpl_startup_4::toString()
{
    return u"Handoff continuation"_j;
}

void rice::p2p::glacier::v2::GlacierImpl_startup_4::init_()
{
    nextTimeout = npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis() + GlacierImpl_this->handoffDelayAfterJoin;
}

void rice::p2p::glacier::v2::GlacierImpl_startup_4::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierResponseMessage* >(o) != nullptr) {
        auto const grm = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierResponseMessage* >(o);
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Received handoff response from "_j)->append(static_cast< ::java::lang::Object* >(npc(npc(grm)->getSource())->getId()))
                ->append(u" with "_j)
                ->append(npc(grm)->numKeys())
                ->append(u" keys"_j)->toString());

        for (auto i = int32_t(0); i < npc(grm)->numKeys(); i++) {
            auto const thisKey = npc(grm)->getKey(i);
            if(npc(grm)->getAuthoritative(i)) {
                if(npc(grm)->getHaveIt(i)) {
                    auto thisPos = GlacierImpl_this->getFragmentLocation(thisKey);
                    if(!npc(GlacierImpl_this->responsibleRange)->containsId(thisPos)) {
                        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Deleting fragment "_j)->append(static_cast< ::java::lang::Object* >(thisKey))->toString());

                        GlacierImpl_this->deleteFragment(thisKey, new GlacierImpl_startup_4_receiveResult_4_1(this, thisKey));
                    } else {
                        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Handoff response for "_j)->append(static_cast< ::java::lang::Object* >(thisKey))
                                ->append(u", for which I am still responsible (attack?) -- ignored"_j)->toString());

                    }
                } else {
                    npc(GlacierImpl_this->fragmentStorage)->getObject(thisKey, new GlacierImpl_startup_4_receiveResult_4_2(this, thisKey, grm));
                }
            } else {
                if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Ignoring fragment "_j)->append(static_cast< ::java::lang::Object* >(thisKey))
                        ->append(u" (haveIt="_j)
                        ->append(npc(grm)->getHaveIt(i))
                        ->append(u", authoritative="_j)
                        ->append(npc(grm)->getAuthoritative(i))
                        ->append(u")"_j)->toString());

            }
        }
    } else if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierDataMessage* >(o) != nullptr) {
        auto const gdm = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierDataMessage* >(o);
        for (auto i = int32_t(0); i < npc(gdm)->numKeys(); i++) {
            auto const thisKey = npc(gdm)->getKey(i);
            auto const thisFragment = npc(gdm)->getFragment(i);
            auto const thisManifest = npc(gdm)->getManifest(i);
            if((thisFragment != nullptr) && (thisManifest != nullptr)) {
                if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
                    npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Handoff: Received Fragment+Manifest for "_j)->append(static_cast< ::java::lang::Object* >(thisKey))->toString());

                if(!npc(GlacierImpl_this->responsibleRange)->containsId(GlacierImpl_this->getFragmentLocation(thisKey))) {
                    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Handoff: Not responsible for "_j)->append(static_cast< ::java::lang::Object* >(thisKey))
                            ->append(u" (at "_j)
                            ->append(static_cast< ::java::lang::Object* >(GlacierImpl_this->getFragmentLocation(thisKey)))
                            ->append(u") -- discarding"_j)->toString());

                    continue;
                }
                if(!npc(GlacierImpl_this->policy)->checkSignature(thisManifest, npc(thisKey)->getVersionKey())) {
                    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(GlacierImpl_this->logger)->log(u"Handoff: Manifest is not signed properly"_j);

                    continue;
                }
                if(!npc(thisManifest)->validatesFragment(thisFragment, npc(thisKey)->getFragmentID(), npc(npc(GlacierImpl_this->environment)->getLogManager())->getLogger(Manifest::class_(), GlacierImpl_this->instance))) {
                    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(GlacierImpl_this->logger)->log(u"Handoff: Manifest does not validate this fragment"_j);

                    continue;
                }
                if(!npc(GlacierImpl_this->fragmentStorage)->exists(thisKey)) {
                    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(GlacierImpl_this->logger)->log(u"Handoff: Verified ok. Storing locally."_j);

                    auto fam = new FragmentAndManifest(thisFragment, thisManifest);
                    npc(GlacierImpl_this->fragmentStorage)->store(thisKey, new FragmentMetadata(npc(thisManifest)->getExpiration(), int32_t(0), npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis()), fam, new GlacierImpl_startup_4_receiveResult_4_3(this, thisKey, gdm, thisManifest));
                } else {
                    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(GlacierImpl_this->logger)->log(u"Handoff: We already have a fragment with this key! -- sending response"_j);

                    GlacierImpl_this->sendMessage(nullptr, new ::rice::p2p::glacier::v2::messaging::GlacierResponseMessage(npc(gdm)->getUID(), thisKey, true, npc(thisManifest)->getExpiration(), true, GlacierImpl_this->getLocalNodeHandle(), npc(npc(gdm)->getSource())->getId(), true, GlacierImpl_this->tagHandoff), npc(gdm)->getSource());
                    continue;
                }
                continue;
            } else {
                if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(GlacierImpl_this->logger)->log(u"Handoff: Either fragment or manifest are missing!"_j);

                continue;
            }
        }
    } else {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Unexpected response in handoff continuation: "_j)->append(static_cast< ::java::lang::Object* >(o))
                ->append(u" -- ignored"_j)->toString());

    }
}

void rice::p2p::glacier::v2::GlacierImpl_startup_4::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->logException(u"Exception in handoff continuation: "_j, e);

}

void rice::p2p::glacier::v2::GlacierImpl_startup_4::timeoutExpired()
{
    nextTimeout = npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis() + GlacierImpl_this->jitterTerm(GlacierImpl_this->handoffInterval);
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(GlacierImpl_this->logger)->log(u"Checking fragment storage for fragments to hand off..."_j);

    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Currently responsible for: "_j)->append(static_cast< ::java::lang::Object* >(GlacierImpl_this->responsibleRange))->toString());

    auto iter = npc(npc(GlacierImpl_this->fragmentStorage)->scan())->getIterator();
    auto handoffs = new ::java::util::Vector();
    ::rice::p2p::commonapi::Id* destination = nullptr;
    while (npc(iter)->hasNext()) {
        auto fkey = java_cast< ::rice::p2p::glacier::FragmentKey* >(java_cast< ::java::lang::Object* >(npc(iter)->next()));
        auto thisPos = GlacierImpl_this->getFragmentLocation(fkey);
        if(!npc(GlacierImpl_this->responsibleRange)->containsId(thisPos)) {
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Must hand off "_j)->append(static_cast< ::java::lang::Object* >(fkey))
                    ->append(u" @"_j)
                    ->append(static_cast< ::java::lang::Object* >(thisPos))->toString());

            npc(handoffs)->add(static_cast< ::java::lang::Object* >(fkey));
            if(npc(handoffs)->size() >= GlacierImpl_this->handoffMaxFragments) {
                if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Limit of "_j)->append(GlacierImpl_this->handoffMaxFragments)
                        ->append(u" reached for handoff"_j)->toString());

                break;
            }
            if(destination == nullptr)
                destination = thisPos;

        }
    }
    if(destination == nullptr) {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(u"Nothing to hand off -- returning"_j);

        return;
    }
    auto numHandoffs = ::java::lang::Math::min(npc(handoffs)->size(), GlacierImpl_this->handoffMaxFragments);
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Handing off "_j)->append(numHandoffs)
            ->append(u" fragments (out of "_j)
            ->append(npc(handoffs)->size())
            ->append(u")"_j)->toString());

    auto keys = new ::rice::p2p::glacier::FragmentKeyArray(numHandoffs);
    for (auto i = int32_t(0); i < numHandoffs; i++) 
                keys->set(i, java_cast< ::rice::p2p::glacier::FragmentKey* >(java_cast< ::java::lang::Object* >(npc(handoffs)->elementAt(i))));

    GlacierImpl_this->sendMessage(destination, new ::rice::p2p::glacier::v2::messaging::GlacierQueryMessage(getMyUID(), keys, GlacierImpl_this->getLocalNodeHandle(), destination, GlacierImpl_this->tagHandoff), nullptr);
}

int64_t rice::p2p::glacier::v2::GlacierImpl_startup_4::getTimeout()
{
    return nextTimeout;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_4::getClass0()
{
    return class_();
}

