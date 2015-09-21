// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_insert_24.hpp>

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
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/glacier/Fragment.hpp>
#include <rice/p2p/glacier/GlacierException.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_insert_24_receiveResult_24_1.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_insert_24_receiveResult_24_2.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
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

rice::p2p::glacier::v2::GlacierImpl_insert_24::GlacierImpl_insert_24(GlacierImpl *GlacierImpl_this, ::rice::Continuation* command, ::rice::p2p::glacier::VersionKey* vkey, ::rice::p2p::past::PastContent* obj, int64_t expiration)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
    , command(command)
    , vkey(vkey)
    , obj(obj)
    , expiration(expiration)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_insert_24::receiveResult(::java::lang::Object* o)
{
    auto const fragments = java_cast< ::rice::p2p::glacier::FragmentArray* >(o);
    if(fragments == nullptr) {
        npc(command)->receiveException(new ::rice::p2p::glacier::GlacierException(u"Cannot encode object"_j));
        return;
    }
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"insert("_j)->append(npc(vkey)->toStringFull())
            ->append(u") encoded fragments OK, creating manifests..."_j)->toString());

    npc(GlacierImpl_this->endpoint)->process(new GlacierImpl_insert_24_receiveResult_24_1(this, vkey, obj, fragments, expiration), new GlacierImpl_insert_24_receiveResult_24_2(this, command, vkey, fragments, expiration));
}

void rice::p2p::glacier::v2::GlacierImpl_insert_24::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::SEVERE)
        npc(GlacierImpl_this->logger)->logException(u"EncodeObject failed: e="_j, e);

    npc(command)->receiveException(new ::rice::p2p::glacier::GlacierException(::java::lang::StringBuilder().append(u"EncodeObject failed: e="_j)->append(static_cast< ::java::lang::Object* >(e))->toString()));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_insert_24::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_insert_24::getClass0()
{
    return class_();
}

