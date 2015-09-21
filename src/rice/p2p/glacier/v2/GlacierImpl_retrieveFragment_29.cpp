// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveFragment_29.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/glacier/Fragment.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/v2/FragmentAndManifest.hpp>
#include <rice/p2p/glacier/v2/GlacierContinuation.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveFragment_29_receiveResult_29_1.hpp>
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

rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29::GlacierImpl_retrieveFragment_29(GlacierImpl *GlacierImpl_this, Manifest* manifest, ::rice::p2p::glacier::FragmentKey* key, GlacierContinuation* c, char16_t tag)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
    , manifest(manifest)
    , key(key)
    , c(c)
    , tag(tag)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29::receiveResult(::java::lang::Object* o)
{
    if(o != nullptr) {
        if(dynamic_cast< FragmentAndManifest* >(o) != nullptr) {
            auto thisFragment = npc((java_cast< FragmentAndManifest* >(o)))->fragment;
            if(npc(manifest)->validatesFragment(thisFragment, npc(key)->getFragmentID(), npc(npc(GlacierImpl_this->environment)->getLogManager())->getLogger(Manifest::class_(), GlacierImpl_this->instance))) {
                if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveFragment: Found in trash: "_j)->append(npc(key)->toStringFull())->toString());

                npc(c)->receiveResult(thisFragment);
                return;
            }
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(GlacierImpl_this->logger)->log(u"Fragment found in trash, but does not match manifest?!? -- fetching normally"_j);

        } else {
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Fragment "_j)->append(npc(key)->toStringFull())
                    ->append(u" found in trash, but object is not a FAM ("_j)
                    ->append(static_cast< ::java::lang::Object* >(o))
                    ->append(u")?!? -- ignoring"_j)->toString());

        }
    }
    GlacierImpl_this->addContinuation(new GlacierImpl_retrieveFragment_29_receiveResult_29_1(this, key, manifest, c, tag));
}

void rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Exception while checking for "_j)->append(npc(key)->toStringFull())
            ->append(u" in trash storage -- ignoring"_j)->toString());

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29::getClass0()
{
    return class_();
}

