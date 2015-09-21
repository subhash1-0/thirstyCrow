// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_insert_24_receiveResult_24_1.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_insert_24.hpp>
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
typedef ::SubArray< ::rice::p2p::glacier::Fragment, ::java::lang::ObjectArray, ::java::io::SerializableArray > FragmentArray;

            namespace v2
            {
typedef ::SubArray< ::rice::p2p::glacier::v2::Manifest, ::java::lang::ObjectArray, ::java::io::SerializableArray > ManifestArray;
            } // v2
        } // glacier
    } // p2p
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::GlacierImpl_insert_24_receiveResult_24_1::GlacierImpl_insert_24_receiveResult_24_1(GlacierImpl_insert_24 *GlacierImpl_insert_24_this, ::rice::p2p::glacier::VersionKey* vkey, ::rice::p2p::past::PastContent* obj, ::rice::p2p::glacier::FragmentArray* fragments, int64_t expiration)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_insert_24_this(GlacierImpl_insert_24_this)
    , vkey(vkey)
    , obj(obj)
    , fragments(fragments)
    , expiration(expiration)
{
    clinit();
    ctor();
}

java::lang::Object* rice::p2p::glacier::v2::GlacierImpl_insert_24_receiveResult_24_1::execute()
{
    return npc(GlacierImpl_insert_24_this->GlacierImpl_this->policy)->createManifests(vkey, obj, fragments, expiration);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_insert_24_receiveResult_24_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_insert_24_receiveResult_24_1::getClass0()
{
    return class_();
}

