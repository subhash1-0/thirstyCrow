// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_startup_6.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/TreeSet.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/p2p/glacier/v2/FragmentMetadata.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_6_timeoutExpired_6_1.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/persistence/StorageManager.hpp>

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

rice::p2p::glacier::v2::GlacierImpl_startup_6::GlacierImpl_startup_6(GlacierImpl *GlacierImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
{
    clinit();
    ctor();
}

java::lang::String* rice::p2p::glacier::v2::GlacierImpl_startup_6::toString()
{
    return u"Local scan"_j;
}

void rice::p2p::glacier::v2::GlacierImpl_startup_6::init_()
{
    nextTimeout = npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis() + GlacierImpl_this->localScanInterval;
}

void rice::p2p::glacier::v2::GlacierImpl_startup_6::receiveResult(::java::lang::Object* o)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Local scan received object: "_j)->append(static_cast< ::java::lang::Object* >(o))->toString());

}

void rice::p2p::glacier::v2::GlacierImpl_startup_6::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->logException(u"Local scan received exception: "_j, e);

}

int64_t rice::p2p::glacier::v2::GlacierImpl_startup_6::getTimeout()
{
    return nextTimeout;
}

void rice::p2p::glacier::v2::GlacierImpl_startup_6::timeoutExpired()
{
    nextTimeout = npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis() + GlacierImpl_this->jitterTerm(GlacierImpl_this->localScanInterval);
    auto const fragments = npc(GlacierImpl_this->fragmentStorage)->scan();
    auto const now = npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis();
    auto queries = new ::java::util::TreeSet();
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Performing local scan over "_j)->append(npc(fragments)->numElements())
            ->append(u" fragment(s)..."_j)->toString());

    auto iter = npc(fragments)->getIterator();
    while (npc(iter)->hasNext()) {
        auto const thisKey = java_cast< ::rice::p2p::glacier::FragmentKey* >(java_cast< ::java::lang::Object* >(npc(iter)->next()));
        auto metadata = java_cast< FragmentMetadata* >(npc(GlacierImpl_this->fragmentStorage)->getMetadata(thisKey));
        if((metadata != nullptr) && (npc(metadata)->currentExpirationDate >= now)) {
            auto const thisObjectKey = npc(npc(thisKey)->getVersionKey())->getId();
            auto const thisVersion = npc(npc(thisKey)->getVersionKey())->getVersion();
            auto const thisFragmentID = npc(thisKey)->getFragmentID();
            auto const fidLeft = (thisFragmentID + GlacierImpl_this->numFragments - int32_t(1)) % GlacierImpl_this->numFragments;
            auto const fidRight = (thisFragmentID + int32_t(1)) % GlacierImpl_this->numFragments;
            if(npc(GlacierImpl_this->responsibleRange)->containsId(GlacierImpl_this->getFragmentLocation(thisObjectKey, fidLeft, thisVersion))) {
                if(!npc(fragments)->isMemberId(npc(thisKey)->getPeerKey(fidLeft))) {
                    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
                        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Missing: "_j)->append(static_cast< ::java::lang::Object* >(thisKey))
                            ->append(u" L="_j)
                            ->append(fidLeft)->toString());

                    npc(queries)->add(static_cast< ::java::lang::Object* >(npc(thisKey)->getVersionKey()));
                }
            }
            if(npc(GlacierImpl_this->responsibleRange)->containsId(GlacierImpl_this->getFragmentLocation(thisObjectKey, fidRight, thisVersion))) {
                if(!npc(fragments)->isMemberId(npc(thisKey)->getPeerKey(fidRight))) {
                    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
                        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Missing: "_j)->append(static_cast< ::java::lang::Object* >(thisKey))
                            ->append(u" R="_j)
                            ->append(fidRight)->toString());

                    npc(queries)->add(static_cast< ::java::lang::Object* >(npc(thisKey)->getVersionKey()));
                }
            }
        } else {
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Expired, ignoring in local scan: "_j)->append(static_cast< ::java::lang::Object* >(thisKey))->toString());

        }
    }
    if(!npc(queries)->isEmpty()) {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Local scan completed; "_j)->append(npc(queries)->size())
                ->append(u" objects incomplete in local store"_j)->toString());

        iter = npc(queries)->iterator();
        auto queriesSent = int32_t(0);
        while (npc(iter)->hasNext() && (queriesSent < GlacierImpl_this->localScanMaxFragmentsPerRun)) {
            auto const thisVKey = java_cast< ::rice::p2p::glacier::VersionKey* >(java_cast< ::java::lang::Object* >(npc(iter)->next()));
            auto localFragmentID = int32_t(0);
            auto queriesHere = int32_t(0);
            for (auto i = int32_t(0); i < GlacierImpl_this->numFragments; i++) {
                auto keyHere = new ::rice::p2p::glacier::FragmentKey(thisVKey, i);
                if(npc(fragments)->isMemberId(keyHere)) {
                    localFragmentID = i;
                    break;
                } else if(npc(GlacierImpl_this->responsibleRange)->containsId(GlacierImpl_this->getFragmentLocation(keyHere))) {
                    queriesHere++;
                }
            }
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Local scan: Fetching manifest for "_j)->append(static_cast< ::java::lang::Object* >(thisVKey))
                    ->append(u" ("_j)
                    ->append(queriesHere)
                    ->append(u" pending queries)"_j)->toString());

            queriesSent += queriesHere;
            npc(GlacierImpl_this->fragmentStorage)->getObject(new ::rice::p2p::glacier::FragmentKey(thisVKey, localFragmentID), new GlacierImpl_startup_6_timeoutExpired_6_1(this, thisVKey, fragments));
        }
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(queriesSent)->append(u" queries sent after local scan"_j)->toString());

    } else {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(GlacierImpl_this->logger)->log(u"Local scan completed; no missing fragments"_j);

    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_6::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_6::getClass0()
{
    return class_();
}

