// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/glacier/Fragment.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/v2/FragmentAndManifest.hpp>
#include <rice/p2p/glacier/v2/FragmentMetadata.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_6.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_6_timeoutExpired_6_1.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1_receiveResult_6_1_1_1.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/Manifest.hpp>
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

rice::p2p::glacier::v2::GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1::GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1(GlacierImpl_startup_6_timeoutExpired_6_1 *GlacierImpl_startup_6_timeoutExpired_6_1_this, ::rice::p2p::glacier::FragmentKey* thisKey, Manifest* thisManifest, int64_t tStart)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_startup_6_timeoutExpired_6_1_this(GlacierImpl_startup_6_timeoutExpired_6_1_this)
    , thisKey(thisKey)
    , thisManifest(thisManifest)
    , tStart(tStart)
{
    clinit();
    ctor();
}

java::lang::String* rice::p2p::glacier::v2::GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1::toString()
{
    return ::java::lang::StringBuilder().append(u"Local scan: Fetch fragment: "_j)->append(static_cast< ::java::lang::Object* >(thisKey))->toString();
}

void rice::p2p::glacier::v2::GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< ::rice::p2p::glacier::Fragment* >(o) != nullptr) {
        if(npc(GlacierImpl_startup_6_timeoutExpired_6_1_this->GlacierImpl_startup_6_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(GlacierImpl_startup_6_timeoutExpired_6_1_this->GlacierImpl_startup_6_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Local scan: Received fragment "_j)->append(static_cast< ::java::lang::Object* >(thisKey))
                ->append(u" (from primary) matches existing manifest, storing..."_j)->toString());

        auto fam = new FragmentAndManifest(java_cast< ::rice::p2p::glacier::Fragment* >(o), thisManifest);
        npc(GlacierImpl_startup_6_timeoutExpired_6_1_this->GlacierImpl_startup_6_this->GlacierImpl_this->fragmentStorage)->store(thisKey, new FragmentMetadata(npc(thisManifest)->getExpiration(), int32_t(0), npc(npc(GlacierImpl_startup_6_timeoutExpired_6_1_this->GlacierImpl_startup_6_this->GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis()), fam, new GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1_receiveResult_6_1_1_1(this, thisKey));
    } else {
        if(npc(GlacierImpl_startup_6_timeoutExpired_6_1_this->GlacierImpl_startup_6_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GlacierImpl_startup_6_timeoutExpired_6_1_this->GlacierImpl_startup_6_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Local scan: FS received something other than a fragment: "_j)->append(static_cast< ::java::lang::Object* >(o))->toString());

    }
}

void rice::p2p::glacier::v2::GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_startup_6_timeoutExpired_6_1_this->GlacierImpl_startup_6_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_startup_6_timeoutExpired_6_1_this->GlacierImpl_startup_6_this->GlacierImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Local scan: Exception while recovering synced fragment "_j)->append(static_cast< ::java::lang::Object* >(thisKey))
            ->append(u": "_j)->toString(), e);

    terminate();
}

void rice::p2p::glacier::v2::GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1::timeoutExpired()
{
    if(npc(GlacierImpl_startup_6_timeoutExpired_6_1_this->GlacierImpl_startup_6_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_startup_6_timeoutExpired_6_1_this->GlacierImpl_startup_6_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Local scan: Timeout while fetching synced fragment "_j)->append(static_cast< ::java::lang::Object* >(thisKey))
            ->append(u" -- aborted"_j)->toString());

    terminate();
}

int64_t rice::p2p::glacier::v2::GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1::getTimeout()
{
    return tStart + GlacierImpl_startup_6_timeoutExpired_6_1_this->GlacierImpl_startup_6_this->GlacierImpl_this->overallRestoreTimeout;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1::getClass0()
{
    return class_();
}

