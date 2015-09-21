// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_receiveResult_29_1_1_2.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
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
#include <rice/p2p/glacier/Fragment.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/GlacierException.hpp>
#include <rice/p2p/glacier/v2/GlacierContinuation.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveFragment_29.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveFragment_29_receiveResult_29_1.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/Manifest.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io
} // java

namespace rice
{
    namespace p2p
    {
        namespace glacier
        {
typedef ::SubArray< ::rice::p2p::glacier::Fragment, ::java::lang::ObjectArray, ::java::io::SerializableArray > FragmentArray;
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

rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_receiveResult_29_1_1_2::GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_receiveResult_29_1_1_2(GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1 *GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_this, Manifest* manifest, ::rice::p2p::glacier::FragmentKey* key, GlacierContinuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_this(GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_this)
    , manifest(manifest)
    , key(key)
    , c(c)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_receiveResult_29_1_1_2::receiveResult(::java::lang::Object* o)
{
    auto frag = java_cast< ::rice::p2p::glacier::FragmentArray* >(o);
    if(!npc(manifest)->validatesFragment((*frag)[npc(key)->getFragmentID()], npc(key)->getFragmentID(), npc(npc(GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_this->GlacierImpl_retrieveFragment_29_receiveResult_29_1_this->GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->environment)->getLogManager())->getLogger(Manifest::class_(), GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_this->GlacierImpl_retrieveFragment_29_receiveResult_29_1_this->GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->instance))) {
        if(npc(GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_this->GlacierImpl_retrieveFragment_29_receiveResult_29_1_this->GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_this->GlacierImpl_retrieveFragment_29_receiveResult_29_1_this->GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Reconstructed fragment #"_j)->append(npc(key)->getFragmentID())
                ->append(u" does not match manifest ??!?"_j)->toString());

        npc(c)->receiveException(new ::rice::p2p::glacier::GlacierException(u"Recovered object, but cannot re-encode it (strange!) -- try again later!"_j));
        return;
    }
    npc(c)->receiveResult((*frag)[npc(key)->getFragmentID()]);
}

void rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_receiveResult_29_1_1_2::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_this->GlacierImpl_retrieveFragment_29_receiveResult_29_1_this->GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::SEVERE)
        npc(GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_this->GlacierImpl_retrieveFragment_29_receiveResult_29_1_this->GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->logException(u"Recovered object, but re-encode failed: "_j, e);

    npc(c)->receiveException(new ::rice::p2p::glacier::GlacierException(::java::lang::StringBuilder().append(u"Recovered object, but re-encode failed: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString()));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_receiveResult_29_1_1_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_receiveResult_29_1_1_2::getClass0()
{
    return class_();
}

