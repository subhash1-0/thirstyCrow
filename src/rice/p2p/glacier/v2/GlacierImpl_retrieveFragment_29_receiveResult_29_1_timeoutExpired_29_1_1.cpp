// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/GlacierException.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/p2p/glacier/v2/GlacierContinuation.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveFragment_29.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveFragment_29_receiveResult_29_1.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_receiveResult_29_1_1_1.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_receiveResult_29_1_1_2.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/past/PastContent.hpp>

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

rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1::GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1(GlacierImpl_retrieveFragment_29_receiveResult_29_1 *GlacierImpl_retrieveFragment_29_receiveResult_29_1_this, ::rice::p2p::glacier::FragmentKey* key, GlacierContinuation* c, Manifest* manifest)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_retrieveFragment_29_receiveResult_29_1_this(GlacierImpl_retrieveFragment_29_receiveResult_29_1_this)
    , key(key)
    , c(c)
    , manifest(manifest)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1::receiveResult(::java::lang::Object* o)
{
    if(o == nullptr) {
        if(npc(GlacierImpl_retrieveFragment_29_receiveResult_29_1_this->GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GlacierImpl_retrieveFragment_29_receiveResult_29_1_this->GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveFragment: retrieveObject("_j)->append(static_cast< ::java::lang::Object* >(npc(key)->getVersionKey()))
                ->append(u") failed, returns null"_j)->toString());

        npc(c)->receiveException(new ::rice::p2p::glacier::GlacierException(u"Cannot restore either the object or the fragment -- try again later!"_j));
        return;
    }
    auto const retrievedObject = java_cast< ::rice::p2p::past::PastContent* >(o);
    npc(GlacierImpl_retrieveFragment_29_receiveResult_29_1_this->GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->endpoint)->process(new GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_receiveResult_29_1_1_1(this, key, retrievedObject), new GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_receiveResult_29_1_1_2(this, manifest, key, c));
}

void rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1::receiveException(::java::lang::Exception* e)
{
    npc(c)->receiveException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1::getClass0()
{
    return class_();
}

