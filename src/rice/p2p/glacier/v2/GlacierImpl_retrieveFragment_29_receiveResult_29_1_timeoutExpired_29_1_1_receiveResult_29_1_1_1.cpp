// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_receiveResult_29_1_1_1.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Arrays.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/glacier/Fragment.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveFragment_29.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveFragment_29_receiveResult_29_1.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/GlacierPolicy.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>
#include <Array.hpp>

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

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_receiveResult_29_1_1_1::GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_receiveResult_29_1_1_1(GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1 *GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_this, ::rice::p2p::glacier::FragmentKey* key, ::rice::p2p::past::PastContent* retrievedObject)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_this(GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_this)
    , key(key)
    , retrievedObject(retrievedObject)
{
    clinit();
    ctor();
}

java::lang::Object* rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_receiveResult_29_1_1_1::execute()
{
    if(npc(GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_this->GlacierImpl_retrieveFragment_29_receiveResult_29_1_this->GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_this->GlacierImpl_retrieveFragment_29_receiveResult_29_1_this->GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Reencode object: "_j)->append(static_cast< ::java::lang::Object* >(npc(key)->getVersionKey()))->toString());

    auto generateFragment = new ::boolArray(GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_this->GlacierImpl_retrieveFragment_29_receiveResult_29_1_this->GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->numFragments);
    ::java::util::Arrays::fill(generateFragment, false);
    (*generateFragment)[npc(key)->getFragmentID()] = true;
    ::java::lang::Object* result = npc(GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_this->GlacierImpl_retrieveFragment_29_receiveResult_29_1_this->GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->policy)->encodeObject(retrievedObject, generateFragment);
    if(npc(GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_this->GlacierImpl_retrieveFragment_29_receiveResult_29_1_this->GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_this->GlacierImpl_retrieveFragment_29_receiveResult_29_1_this->GlacierImpl_retrieveFragment_29_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Reencode complete: "_j)->append(static_cast< ::java::lang::Object* >(npc(key)->getVersionKey()))->toString());

    return result;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_receiveResult_29_1_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_receiveResult_29_1_1_1::getClass0()
{
    return class_();
}

