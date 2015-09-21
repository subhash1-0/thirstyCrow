// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_deliver_34.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/v2/FragmentAndManifest.hpp>
#include <rice/p2p/glacier/v2/FragmentMetadata.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/GlacierPolicy.hpp>
#include <rice/p2p/glacier/v2/Manifest.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierRefreshCompleteMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierRefreshPatchMessage.hpp>
#include <rice/persistence/StorageManager.hpp>
#include <Array.hpp>

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

rice::p2p::glacier::v2::GlacierImpl_deliver_34::GlacierImpl_deliver_34(GlacierImpl *GlacierImpl_this, ::rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage* grpm)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
    , grpm(grpm)
{
    clinit();
    init();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_deliver_34::init()
{
    successes = new ::int32_tArray(npc(grpm)->numKeys());
    currentPhase = GlacierImpl_deliver_34::phaseAdvance;
    currentKey = nullptr;
    currentIndex = int32_t(0);
    currentFID = -int32_t(1);
}

constexpr int32_t rice::p2p::glacier::v2::GlacierImpl_deliver_34::phaseFetch;

constexpr int32_t rice::p2p::glacier::v2::GlacierImpl_deliver_34::phaseStore;

constexpr int32_t rice::p2p::glacier::v2::GlacierImpl_deliver_34::phaseAdvance;

void rice::p2p::glacier::v2::GlacierImpl_deliver_34::receiveResult(::java::lang::Object* o)
{
    if(currentPhase == phaseFetch) {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"AR Patch: Got FAM for "_j)->append(static_cast< ::java::lang::Object* >(currentKey))->toString());

        auto fam = java_cast< FragmentAndManifest* >(o);
        npc(npc(fam)->manifest)->update(npc(grpm)->getLifetime(currentIndex), npc(grpm)->getSignature(currentIndex));
        if(npc(GlacierImpl_this->policy)->checkSignature(npc(fam)->manifest, npc(currentKey)->getVersionKey())) {
            auto metadata = java_cast< FragmentMetadata* >(npc(GlacierImpl_this->fragmentStorage)->getMetadata(currentKey));
            if(metadata != nullptr) {
                if(npc(metadata)->currentExpirationDate <= npc(grpm)->getLifetime(currentIndex)) {
                    currentPhase = phaseStore;
                    if(npc(metadata)->currentExpirationDate == npc(grpm)->getLifetime(currentIndex)) {
                        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"AR Duplicate refresh request (prev="_j)->append(npc(metadata)->previousExpirationDate)
                                ->append(u" cur="_j)
                                ->append(npc(metadata)->currentExpirationDate)
                                ->append(u" updated="_j)
                                ->append(npc(grpm)->getLifetime(currentIndex))
                                ->append(u") -- ignoring"_j)->toString());

                    } else {
                        auto newMetadata = new FragmentMetadata(npc(grpm)->getLifetime(currentIndex), npc(metadata)->currentExpirationDate, npc(metadata)->storedSince);
                        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"AR FAM "_j)->append(static_cast< ::java::lang::Object* >(currentKey))
                                ->append(u" updated ("_j)
                                ->append(npc(newMetadata)->previousExpirationDate)
                                ->append(u" -> "_j)
                                ->append(npc(newMetadata)->currentExpirationDate)
                                ->append(u"), writing to disk..."_j)->toString());

                        npc(GlacierImpl_this->fragmentStorage)->store(currentKey, newMetadata, fam, this);
                        return;
                    }
                } else {
                    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"RefreshPatch attempts to roll back lifetime from "_j)->append(npc(metadata)->currentExpirationDate)
                            ->append(u" to "_j)
                            ->append(npc(grpm)->getLifetime(currentIndex))->toString());

                    currentPhase = phaseStore;
                }
            } else {
                if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Cannot fetch metadata for key "_j)->append(static_cast< ::java::lang::Object* >(currentKey))
                        ->append(u", got 'null'"_j)->toString());

                currentPhase = phaseAdvance;
            }
        } else {
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"RefreshPatch with invalid signature: "_j)->append(static_cast< ::java::lang::Object* >(currentKey))->toString());

            currentPhase = phaseAdvance;
        }
    }
    if(currentPhase == phaseStore) {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"AR Patch: Update completed for "_j)->append(static_cast< ::java::lang::Object* >(currentKey))->toString());

        (*successes)[currentIndex]++;
        currentPhase = phaseAdvance;
    }
    if(currentPhase == phaseAdvance) {
        do {
            currentFID++;
            if(currentFID >= GlacierImpl_this->numFragments) {
                currentFID = 0;
                currentIndex++;
            }
            if(currentIndex >= npc(grpm)->numKeys()) {
                respond();
                return;
            }
            currentKey = new ::rice::p2p::glacier::FragmentKey(npc(grpm)->getKey(currentIndex), currentFID);
        } while (!npc(GlacierImpl_this->fragmentStorage)->exists(currentKey));
        currentPhase = phaseFetch;
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"AR Patch: Fetching FAM for "_j)->append(static_cast< ::java::lang::Object* >(currentKey))->toString());

        npc(GlacierImpl_this->fragmentStorage)->getObject(currentKey, this);
    }
}

void rice::p2p::glacier::v2::GlacierImpl_deliver_34::respond()
{
    auto totalSuccesses = int32_t(0);
    for (auto i = int32_t(0); i < npc(successes)->length; i++) 
                totalSuccesses += (*successes)[i];

    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"AR Patch: Sending response ("_j)->append(totalSuccesses)
            ->append(u" updates total)"_j)->toString());

    GlacierImpl_this->sendMessage(nullptr, new ::rice::p2p::glacier::v2::messaging::GlacierRefreshCompleteMessage(npc(grpm)->getUID(), npc(grpm)->getAllKeys(), successes, GlacierImpl_this->getLocalNodeHandle(), npc(npc(grpm)->getSource())->getId(), npc(grpm)->getTag()), npc(grpm)->getSource());
}

void rice::p2p::glacier::v2::GlacierImpl_deliver_34::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Exception while processing AR patch (key "_j)->append(static_cast< ::java::lang::Object* >(currentKey))
            ->append(u", phase "_j)
            ->append(currentPhase)
            ->append(u"): "_j)->toString(), e);

    currentPhase = phaseAdvance;
    receiveResult(static_cast< ::java::lang::Object* >(nullptr));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_deliver_34::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_deliver_34::getClass0()
{
    return class_();
}

