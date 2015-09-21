// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveManifest_27.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Arrays.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/GlacierPolicy.hpp>
#include <rice/p2p/glacier/v2/Manifest.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierDataMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierFetchMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierResponseMessage.hpp>
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

rice::p2p::glacier::v2::GlacierImpl_retrieveManifest_27::GlacierImpl_retrieveManifest_27(GlacierImpl *GlacierImpl_this, ::rice::p2p::glacier::VersionKey* key, char16_t tag, ::rice::Continuation* command)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
    , key(key)
    , tag(tag)
    , command(command)
{
    clinit();
    ctor();
}

java::lang::String* rice::p2p::glacier::v2::GlacierImpl_retrieveManifest_27::toString()
{
    return ::java::lang::StringBuilder().append(u"retrieveManifest("_j)->append(static_cast< ::java::lang::Object* >(key))
        ->append(u")"_j)->toString();
}

void rice::p2p::glacier::v2::GlacierImpl_retrieveManifest_27::init_()
{
    checkedFragment = new ::boolArray(GlacierImpl_this->numFragments);
    ::java::util::Arrays::fill(checkedFragment, false);
    timeout = npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis() + GlacierImpl_this->manifestRequestTimeout;
    for (auto i = int32_t(0); i < GlacierImpl_this->manifestRequestInitialBurst; i++) 
                sendRandomRequest();

}

int32_t rice::p2p::glacier::v2::GlacierImpl_retrieveManifest_27::numCheckedFragments()
{
    auto result = int32_t(0);
    for (auto i = int32_t(0); i < npc(checkedFragment)->length; i++) 
                if((*checkedFragment)[i])
            result++;


    return result;
}

void rice::p2p::glacier::v2::GlacierImpl_retrieveManifest_27::sendRandomRequest()
{
    if(numCheckedFragments() >= GlacierImpl_this->numFragments)
        return;

    int32_t nextID;
    do {
        nextID = npc(npc(GlacierImpl_this->environment)->getRandomSource())->nextInt(GlacierImpl_this->numFragments);
    } while ((*checkedFragment)[nextID]);
    (*checkedFragment)[nextID] = true;
    auto nextKey = new ::rice::p2p::glacier::FragmentKey(key, nextID);
    auto nextLocation = GlacierImpl_this->getFragmentLocation(nextKey);
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveManifest: Asking "_j)->append(static_cast< ::java::lang::Object* >(nextLocation))
            ->append(u" for "_j)
            ->append(static_cast< ::java::lang::Object* >(nextKey))->toString());

    GlacierImpl_this->sendMessage(nextLocation, new ::rice::p2p::glacier::v2::messaging::GlacierFetchMessage(getMyUID(), nextKey, ::rice::p2p::glacier::v2::messaging::GlacierFetchMessage::FETCH_MANIFEST, GlacierImpl_this->getLocalNodeHandle(), nextLocation, tag), nullptr);
}

void rice::p2p::glacier::v2::GlacierImpl_retrieveManifest_27::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierDataMessage* >(o) != nullptr) {
        auto gdm = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierDataMessage* >(o);
        if((npc(gdm)->numKeys() > 0) && (npc(gdm)->getManifest(0) != nullptr)) {
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveManifest("_j)->append(static_cast< ::java::lang::Object* >(key))
                    ->append(u") received manifest"_j)->toString());

            if(npc(GlacierImpl_this->policy)->checkSignature(npc(gdm)->getManifest(0), key)) {
                npc(command)->receiveResult(npc(gdm)->getManifest(0));
                terminate();
            } else {
                if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveManifest("_j)->append(static_cast< ::java::lang::Object* >(key))
                        ->append(u"): invalid signature in "_j)
                        ->append(static_cast< ::java::lang::Object* >(npc(gdm)->getKey(0)))->toString());

            }
        } else if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveManifest("_j)->append(static_cast< ::java::lang::Object* >(key))
                ->append(u") retrieved GDM without a manifest?!?"_j)->toString());

    } else if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierResponseMessage* >(o) != nullptr) {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveManifest("_j)->append(static_cast< ::java::lang::Object* >(key))
                ->append(u"): Fragment not available:"_j)
                ->append(static_cast< ::java::lang::Object* >(npc((java_cast< ::rice::p2p::glacier::v2::messaging::GlacierResponseMessage* >(o)))->getKey(0)))->toString());

        if(numCheckedFragments() < GlacierImpl_this->numFragments) {
            sendRandomRequest();
        } else {
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveManifest("_j)->append(static_cast< ::java::lang::Object* >(key))
                    ->append(u"): giving up"_j)->toString());

            npc(command)->receiveResult(nullptr);
            terminate();
        }
    } else {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveManifest("_j)->append(static_cast< ::java::lang::Object* >(key))
                ->append(u") received unexpected object: "_j)
                ->append(static_cast< ::java::lang::Object* >(o))->toString());

    }
}

void rice::p2p::glacier::v2::GlacierImpl_retrieveManifest_27::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"retrieveManifest("_j)->append(static_cast< ::java::lang::Object* >(key))
            ->append(u") received exception: "_j)->toString(), e);

}

void rice::p2p::glacier::v2::GlacierImpl_retrieveManifest_27::timeoutExpired()
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveManifest("_j)->append(static_cast< ::java::lang::Object* >(key))
            ->append(u"): Timeout ("_j)
            ->append(numCheckedFragments())
            ->append(u" fragments checked)"_j)->toString());

    if(numCheckedFragments() < GlacierImpl_this->numFragments) {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(u"retrying..."_j);

        for (auto i = int32_t(0); i < GlacierImpl_this->manifestRequestRetryBurst; i++) 
                        sendRandomRequest();

        timeout += GlacierImpl_this->manifestRequestTimeout;
    } else {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveManifest("_j)->append(static_cast< ::java::lang::Object* >(key))
                ->append(u"): giving up"_j)->toString());

        terminate();
        npc(command)->receiveResult(nullptr);
    }
}

int64_t rice::p2p::glacier::v2::GlacierImpl_retrieveManifest_27::getTimeout()
{
    return timeout;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_retrieveManifest_27::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_retrieveManifest_27::getClass0()
{
    return class_();
}

