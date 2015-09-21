// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_startup_6_timeoutExpired_6_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/p2p/glacier/v2/FragmentAndManifest.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_6.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/Manifest.hpp>

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

rice::p2p::glacier::v2::GlacierImpl_startup_6_timeoutExpired_6_1::GlacierImpl_startup_6_timeoutExpired_6_1(GlacierImpl_startup_6 *GlacierImpl_startup_6_this, ::rice::p2p::glacier::VersionKey* thisVKey, ::rice::p2p::commonapi::IdSet* fragments)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_startup_6_this(GlacierImpl_startup_6_this)
    , thisVKey(thisVKey)
    , fragments(fragments)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_startup_6_timeoutExpired_6_1::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< FragmentAndManifest* >(o) != nullptr) {
        auto const thisManifest = npc((java_cast< FragmentAndManifest* >(o)))->manifest;
        for (auto i = int32_t(0); i < GlacierImpl_startup_6_this->GlacierImpl_this->numFragments; i++) {
            auto const thisKey = new ::rice::p2p::glacier::FragmentKey(thisVKey, i);
            if(npc(GlacierImpl_startup_6_this->GlacierImpl_this->responsibleRange)->containsId(GlacierImpl_startup_6_this->GlacierImpl_this->getFragmentLocation(thisKey))) {
                if(!npc(fragments)->isMemberId(thisKey)) {
                    if(npc(GlacierImpl_startup_6_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(GlacierImpl_startup_6_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Local scan: Sending query for "_j)->append(static_cast< ::java::lang::Object* >(thisKey))->toString());

                    auto const tStart = npc(npc(GlacierImpl_startup_6_this->GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis();
                    GlacierImpl_startup_6_this->GlacierImpl_this->rateLimitedRetrieveFragment(thisKey, thisManifest, GlacierImpl_startup_6_this->GlacierImpl_this->tagLocalScan, new GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1(this, thisKey, thisManifest, tStart));
                }
            }
        }
    } else {
        if(npc(GlacierImpl_startup_6_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GlacierImpl_startup_6_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Local scan: Cannot retrieve "_j)->append(static_cast< ::java::lang::Object* >(thisVKey))
                ->append(u" from local store, received o="_j)
                ->append(static_cast< ::java::lang::Object* >(o))->toString());

    }
}

void rice::p2p::glacier::v2::GlacierImpl_startup_6_timeoutExpired_6_1::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_startup_6_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_startup_6_this->GlacierImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Local scan: Cannot retrieve "_j)->append(static_cast< ::java::lang::Object* >(thisVKey))
            ->append(u" from local store, exception e="_j)->toString(), e);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_6_timeoutExpired_6_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_6_timeoutExpired_6_1::getClass0()
{
    return class_();
}

