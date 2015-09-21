// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_refresh_20_receiveResult_20_1.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/glacier/GlacierException.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_refresh_20.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/GlacierPolicy.hpp>
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
            namespace v2
            {
typedef ::SubArray< ::rice::p2p::glacier::v2::Manifest, ::java::lang::ObjectArray, ::java::io::SerializableArray > ManifestArray;
            } // v2
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

rice::p2p::glacier::v2::GlacierImpl_refresh_20_receiveResult_20_1::GlacierImpl_refresh_20_receiveResult_20_1(GlacierImpl_refresh_20 *GlacierImpl_refresh_20_this, ::rice::p2p::commonapi::Id* thisId, int64_t thisVersion, int64_t thisExpiration, ::rice::Continuation* thisContinuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_refresh_20_this(GlacierImpl_refresh_20_this)
    , thisId(thisId)
    , thisVersion(thisVersion)
    , thisExpiration(thisExpiration)
    , thisContinuation(thisContinuation)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_refresh_20_receiveResult_20_1::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< Manifest* >(o) != nullptr) {
        auto manifest = java_cast< Manifest* >(o);
        if(npc(GlacierImpl_refresh_20_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_refresh_20_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"refresh("_j)->append(npc(thisId)->toStringFull())
                ->append(u"v"_j)
                ->append(thisVersion)
                ->append(u"): Got manifest"_j)->toString());

        manifest = npc(GlacierImpl_refresh_20_this->GlacierImpl_this->policy)->updateManifest(new ::rice::p2p::glacier::VersionKey(thisId, thisVersion), manifest, thisExpiration);
        auto manifests = new ManifestArray(GlacierImpl_refresh_20_this->GlacierImpl_this->numFragments);
        for (auto i = int32_t(0); i < GlacierImpl_refresh_20_this->GlacierImpl_this->numFragments; i++) 
                        manifests->set(i, manifest);

        GlacierImpl_refresh_20_this->GlacierImpl_this->distribute(new ::rice::p2p::glacier::VersionKey(thisId, thisVersion), nullptr, manifests, thisExpiration, GlacierImpl_refresh_20_this->GlacierImpl_this->tagRefresh, thisContinuation);
    } else {
        if(npc(GlacierImpl_refresh_20_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GlacierImpl_refresh_20_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"refresh("_j)->append(static_cast< ::java::lang::Object* >(thisId))
                ->append(u"v"_j)
                ->append(thisVersion)
                ->append(u"): Cannot retrieve manifest"_j)->toString());

        npc(thisContinuation)->receiveResult(new ::rice::p2p::glacier::GlacierException(u"Cannot retrieve manifest -- retry later"_j));
    }
}

void rice::p2p::glacier::v2::GlacierImpl_refresh_20_receiveResult_20_1::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_refresh_20_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_refresh_20_this->GlacierImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"refresh("_j)->append(static_cast< ::java::lang::Object* >(thisId))
            ->append(u"v"_j)
            ->append(thisVersion)
            ->append(u"): Exception while retrieving manifest: "_j)->toString(), e);

    npc(thisContinuation)->receiveException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_refresh_20_receiveResult_20_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_refresh_20_receiveResult_20_1::getClass0()
{
    return class_();
}

