// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveFragment_29_receiveResult_29_1.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/glacier/Fragment.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/p2p/glacier/v2/GlacierContinuation.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveFragment_29.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/Manifest.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierDataMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierFetchMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierResponseMessage.hpp>

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

rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29_receiveResult_29_1::GlacierImpl_retrieveFragment_29_receiveResult_29_1(GlacierImpl_retrieveFragment_29 *GlacierImpl_retrieveFragment_29_this, ::rice::p2p::glacier::FragmentKey* key, Manifest* manifest, GlacierContinuation* c, char16_t tag)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_retrieveFragment_29_this(GlacierImpl_retrieveFragment_29_this)
    , key(key)
    , manifest(manifest)
    , c(c)
    , tag(tag)
{
    clinit();
    ctor();
}

java::lang::String* rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29_receiveResult_29_1::toString()
{
    return ::java::lang::StringBuilder().append(u"retrieveFragment("_j)->append(static_cast< ::java::lang::Object* >(key))
        ->append(u")"_j)->toString();
}

void rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29_receiveResult_29_1::init_()
{
    attemptsLeft = GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->fragmentRequestMaxAttempts;
    timeout = npc(npc(GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis();
    inPhaseTwo = false;
    timeoutExpired();
}

void rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29_receiveResult_29_1::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierResponseMessage* >(o) != nullptr) {
        auto grm = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierResponseMessage* >(o);
        if(!npc(npc(grm)->getKey(0))->equals(static_cast< ::java::lang::Object* >(key))) {
            if(npc(GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveFragment: Response does not match key "_j)->append(static_cast< ::java::lang::Object* >(key))
                    ->append(u" -- discarded"_j)->toString());

            return;
        }
        if((attemptsLeft > 0) && !npc(grm)->getHaveIt(0)) {
            attemptsLeft = 0;
            timeoutExpired();
        } else {
            if(npc(GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveFragment: Unexpected GlacierResponseMessage: "_j)->append(static_cast< ::java::lang::Object* >(grm))
                    ->append(u" (key="_j)
                    ->append(static_cast< ::java::lang::Object* >(key))
                    ->append(u")"_j)->toString());

        }
        return;
    }
    if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierDataMessage* >(o) != nullptr) {
        auto gdm = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierDataMessage* >(o);
        if(!npc(npc(gdm)->getKey(0))->equals(static_cast< ::java::lang::Object* >(key))) {
            if(npc(GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveFragment: Data does not match key "_j)->append(static_cast< ::java::lang::Object* >(key))
                    ->append(u" -- discarded"_j)->toString());

            return;
        }
        auto thisFragment = npc(gdm)->getFragment(0);
        if(thisFragment == nullptr) {
            if(npc(GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->log(u"retrieveFragment: DataMessage does not contain any fragments -- discarded"_j);

            return;
        }
        if(!npc(manifest)->validatesFragment(thisFragment, npc(npc(gdm)->getKey(0))->getFragmentID(), npc(npc(GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->environment)->getLogManager())->getLogger(Manifest::class_(), GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->instance))) {
            if(npc(GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Invalid fragment "_j)->append(static_cast< ::java::lang::Object* >(npc(gdm)->getKey(0)))
                    ->append(u" returned by primary -- ignored"_j)->toString());

            return;
        }
        npc(c)->receiveResult(thisFragment);
        terminate();
        return;
    }
    if(npc(GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveFragment: Unknown result "_j)->append(static_cast< ::java::lang::Object* >(o))
            ->append(u" (key="_j)
            ->append(static_cast< ::java::lang::Object* >(key))
            ->append(u")"_j)->toString());

}

void rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29_receiveResult_29_1::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->logException(u"retrieveFragment: Exception "_j, e);

    npc(c)->receiveException(e);
    terminate();
}

void rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29_receiveResult_29_1::timeoutExpired()
{
    if(attemptsLeft > 0) {
        if(npc(GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveFragment: Retrying ("_j)->append(attemptsLeft)
                ->append(u" attempts left)"_j)->toString());

        timeout = timeout + GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->currentFragmentRequestTimeout;
        attemptsLeft--;
        GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->sendMessage(npc(npc(key)->getVersionKey())->getId(), new ::rice::p2p::glacier::v2::messaging::GlacierFetchMessage(getMyUID(), key, ::rice::p2p::glacier::v2::messaging::GlacierFetchMessage::FETCH_FRAGMENT, GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->getLocalNodeHandle(), npc(npc(key)->getVersionKey())->getId(), tag), nullptr);
    } else {
        timeout = timeout + int32_t(3) * GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->restoreMaxBoosts * GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->currentFragmentRequestTimeout;
        if(inPhaseTwo) {
            if(npc(GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->log(u"retrieveFragment: Already in phase two"_j);

        }
        inPhaseTwo = true;
        GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->retrieveObject(npc(key)->getVersionKey(), manifest, false, tag, new GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1(this, key, c, manifest));
        terminate();
    }
}

int64_t rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29_receiveResult_29_1::getTimeout()
{
    return timeout;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29_receiveResult_29_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29_receiveResult_29_1::getClass0()
{
    return class_();
}

