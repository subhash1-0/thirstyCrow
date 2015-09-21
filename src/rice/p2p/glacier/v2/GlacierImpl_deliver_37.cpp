// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_deliver_37.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Arrays.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/v2/FragmentAndManifest.hpp>
#include <rice/p2p/glacier/v2/FragmentMetadata.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_deliver_37_receiveResult_37_1.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/GlacierPolicy.hpp>
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

rice::p2p::glacier::v2::GlacierImpl_deliver_37::GlacierImpl_deliver_37(GlacierImpl *GlacierImpl_this, ::rice::p2p::glacier::FragmentKey* thisKey, Manifest* thisManifest, FragmentMetadata* metadata, ::rice::p2p::glacier::v2::messaging::GlacierDataMessage* gdm)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
    , thisKey(thisKey)
    , thisManifest(thisManifest)
    , metadata(metadata)
    , gdm(gdm)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_deliver_37::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< FragmentAndManifest* >(o) != nullptr) {
        auto fam = java_cast< FragmentAndManifest* >(o);
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Got FAM for "_j)->append(static_cast< ::java::lang::Object* >(thisKey))
                ->append(u", now replacing old manifest with new one..."_j)->toString());

        ::java::lang::String* fault = nullptr;
        if(!npc(thisManifest)->validatesFragment(npc(fam)->fragment, npc(thisKey)->getFragmentID(), npc(npc(GlacierImpl_this->environment)->getLogManager())->getLogger(Manifest::class_(), GlacierImpl_this->instance)))
            fault = u"Update: Manifest does not validate this fragment"_j;

        if(!npc(GlacierImpl_this->policy)->checkSignature(thisManifest, npc(thisKey)->getVersionKey()))
            fault = u"Update: Manifest is not signed properly"_j;

        if(!::java::util::Arrays::equals(npc(thisManifest)->getObjectHash(), npc(npc(fam)->manifest)->getObjectHash()))
            fault = u"Update: Object hashes not equal"_j;

        for (auto i = int32_t(0); i < GlacierImpl_this->numFragments; i++) 
                        if(!::java::util::Arrays::equals(npc(thisManifest)->getFragmentHash(i), npc(npc(fam)->manifest)->getFragmentHash(i)))
                fault = ::java::lang::StringBuilder().append(u"Update: Fragment hash #"_j)->append(i)
                    ->append(u" does not match"_j)->toString();


        if(fault == nullptr) {
            npc(fam)->manifest = thisManifest;
            npc(GlacierImpl_this->fragmentStorage)->store(thisKey, new FragmentMetadata(npc(thisManifest)->getExpiration(), ((metadata == nullptr) ? static_cast< int64_t >(int32_t(0)) : npc(metadata)->getCurrentExpiration()), npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis()), fam, new GlacierImpl_deliver_37_receiveResult_37_1(this, thisKey, gdm, thisManifest));
        } else {
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(GlacierImpl_this->logger)->log(fault);

        }
    } else {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Fragment store returns something other than a FAM: "_j)->append(static_cast< ::java::lang::Object* >(o))->toString());

    }
}

void rice::p2p::glacier::v2::GlacierImpl_deliver_37::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Cannot retrieve FAM for "_j)->append(static_cast< ::java::lang::Object* >(thisKey))
            ->append(u": "_j)->toString(), e);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_deliver_37::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_deliver_37::getClass0()
{
    return class_();
}

