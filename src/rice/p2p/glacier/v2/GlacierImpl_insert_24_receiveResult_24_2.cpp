// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_insert_24_receiveResult_24_2.hpp>

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
#include <rice/p2p/glacier/GlacierException.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_insert_24.hpp>
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

rice::p2p::glacier::v2::GlacierImpl_insert_24_receiveResult_24_2::GlacierImpl_insert_24_receiveResult_24_2(GlacierImpl_insert_24 *GlacierImpl_insert_24_this, ::rice::Continuation* command, ::rice::p2p::glacier::VersionKey* vkey, ::rice::p2p::glacier::FragmentArray* fragments, int64_t expiration)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_insert_24_this(GlacierImpl_insert_24_this)
    , command(command)
    , vkey(vkey)
    , fragments(fragments)
    , expiration(expiration)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_insert_24_receiveResult_24_2::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< ManifestArray* >(o) != nullptr) {
        auto const manifests = java_cast< ManifestArray* >(o);
        if(manifests == nullptr) {
            npc(command)->receiveException(new ::rice::p2p::glacier::GlacierException(u"Cannot create manifests"_j));
            return;
        }
        GlacierImpl_insert_24_this->GlacierImpl_this->distribute(vkey, fragments, manifests, expiration, GlacierImpl_insert_24_this->GlacierImpl_this->tagInsert, command);
    } else {
        if(npc(GlacierImpl_insert_24_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GlacierImpl_insert_24_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"insert("_j)->append(npc(vkey)->toStringFull())
                ->append(u") cannot create manifests - returned o="_j)
                ->append(static_cast< ::java::lang::Object* >(o))->toString());

        npc(command)->receiveException(new ::rice::p2p::glacier::GlacierException(u"Cannot create manifests in insert()"_j));
    }
}

void rice::p2p::glacier::v2::GlacierImpl_insert_24_receiveResult_24_2::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_insert_24_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_insert_24_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"insert("_j)->append(npc(vkey)->toStringFull())
            ->append(u") cannot create manifests - exception e="_j)
            ->append(static_cast< ::java::lang::Object* >(e))->toString());

    npc(command)->receiveException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_insert_24_receiveResult_24_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_insert_24_receiveResult_24_2::getClass0()
{
    return class_();
}

