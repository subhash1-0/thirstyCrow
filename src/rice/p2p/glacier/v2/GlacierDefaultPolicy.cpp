// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierDefaultPolicy.java
#include <rice/p2p/glacier/v2/GlacierDefaultPolicy.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/security/MessageDigest.hpp>
#include <java/security/NoSuchAlgorithmException.hpp>
#include <java/util/Arrays.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/glacier/ErasureCodec.hpp>
#include <rice/p2p/glacier/Fragment.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/p2p/glacier/v2/Manifest.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/rawserialization/JavaSerializedPastContent.hpp>
#include <rice/p2p/past/rawserialization/RawPastContent.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
#include <Array.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
    } // lang
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

namespace 
{
typedef ::SubArray< ::int8_tArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > int8_tArrayArray;
} // 

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

rice::p2p::glacier::v2::GlacierDefaultPolicy::GlacierDefaultPolicy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::GlacierDefaultPolicy::GlacierDefaultPolicy(::rice::p2p::glacier::ErasureCodec* codec, ::java::lang::String* instance, ::rice::environment::Environment* env) 
    : GlacierDefaultPolicy(*static_cast< ::default_init_tag* >(0))
{
    ctor(codec,instance,env);
}

void rice::p2p::glacier::v2::GlacierDefaultPolicy::ctor(::rice::p2p::glacier::ErasureCodec* codec, ::java::lang::String* instance, ::rice::environment::Environment* env)
{
    super::ctor();
    this->codec = codec;
    this->instance = instance;
    this->environment = env;
    logger = npc(npc(environment)->getLogManager())->getLogger(GlacierDefaultPolicy::class_(), instance);
}

bool rice::p2p::glacier::v2::GlacierDefaultPolicy::checkSignature(Manifest* manifest, ::rice::p2p::glacier::VersionKey* key)
{
    if(npc(manifest)->getSignature() == nullptr)
        return false;

    return ::java::util::Arrays::equals(npc(manifest)->getSignature(), npc(key)->toByteArray_());
}

void rice::p2p::glacier::v2::GlacierDefaultPolicy::signManifest(Manifest* manifest, ::rice::p2p::glacier::VersionKey* key)
{
    npc(manifest)->setSignature(npc(key)->toByteArray_());
}

void rice::p2p::glacier::v2::GlacierDefaultPolicy::prefetchLocalObject(::rice::p2p::glacier::VersionKey* key, ::rice::Continuation* command)
{
    npc(command)->receiveResult(nullptr);
}

rice::p2p::past::PastContent* rice::p2p::glacier::v2::GlacierDefaultPolicy::decodeObject(::rice::p2p::glacier::FragmentArray* fragments, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd)
{
    return npc(codec)->decode(fragments, endpoint, pcd);
}

rice::p2p::glacier::v2::ManifestArray* rice::p2p::glacier::v2::GlacierDefaultPolicy::createManifests(::rice::p2p::glacier::VersionKey* key, ::rice::p2p::past::rawserialization::RawPastContent* obj, ::rice::p2p::glacier::FragmentArray* fragments, int64_t expiration)
{
    try {
        auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
        npc(sob)->writeShort(npc(obj)->getType());
        npc(obj)->serialize(sob);
        return createManifestsHelper(key, npc(sob)->getBytes(), npc(sob)->getWritten(), fragments, expiration);
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Cannot serialize object: "_j)->append(static_cast< ::java::lang::Object* >(ioe))->toString());

        return nullptr;
    }
}

rice::p2p::glacier::v2::ManifestArray* rice::p2p::glacier::v2::GlacierDefaultPolicy::createManifests(::rice::p2p::glacier::VersionKey* key, ::rice::p2p::past::PastContent* obj, ::rice::p2p::glacier::FragmentArray* fragments, int64_t expiration)
{
    return createManifests(key, dynamic_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(obj) != nullptr ? java_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(obj) : static_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(new ::rice::p2p::past::rawserialization::JavaSerializedPastContent(obj)), fragments, expiration);
}

rice::p2p::glacier::v2::ManifestArray* rice::p2p::glacier::v2::GlacierDefaultPolicy::createManifestsHelper(::rice::p2p::glacier::VersionKey* key, ::int8_tArray* bytes, int32_t length, ::rice::p2p::glacier::FragmentArray* fragments, int64_t expiration)
{
    ::java::security::MessageDigest* md = nullptr;
    try {
        md = ::java::security::MessageDigest::getInstance(u"SHA"_j);
    } catch (::java::security::NoSuchAlgorithmException* e) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(u"No SHA support!"_j);

        return nullptr;
    }
    auto fragmentHash = new ::int8_tArrayArray(npc(fragments)->length);
    for (auto i = int32_t(0); i < npc(fragments)->length; i++) {
        npc(md)->reset();
        npc(md)->update(npc((*fragments)[i])->getPayload());
        fragmentHash->set(i, npc(md)->digest());
    }
    ::int8_tArray* objectHash = nullptr;
    npc(md)->reset();
    npc(md)->update(bytes, 0, length);
    objectHash = npc(md)->digest();
    auto manifests = new ManifestArray(npc(fragments)->length);
    for (auto i = int32_t(0); i < npc(fragments)->length; i++) {
        manifests->set(i, new Manifest(objectHash, fragmentHash, expiration));
        signManifest((*manifests)[i], key);
    }
    return manifests;
}

rice::p2p::glacier::FragmentArray* rice::p2p::glacier::v2::GlacierDefaultPolicy::encodeObject(::rice::p2p::past::rawserialization::RawPastContent* obj, ::boolArray* generateFragment)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Serialize object: "_j)->append(static_cast< ::java::lang::Object* >(obj))->toString());

    try {
        auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
        npc(sob)->writeShort(npc(obj)->getType());
        npc(obj)->serialize(sob);
        return encodeObjectHelper(obj, npc(sob)->getBytes(), npc(sob)->getWritten(), generateFragment);
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Cannot serialize object: "_j)->append(static_cast< ::java::lang::Object* >(ioe))->toString());

        return nullptr;
    }
}

rice::p2p::glacier::FragmentArray* rice::p2p::glacier::v2::GlacierDefaultPolicy::encodeObject(::rice::p2p::past::PastContent* obj, ::boolArray* generateFragment)
{
    return encodeObject(dynamic_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(obj) != nullptr ? java_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(obj) : static_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(new ::rice::p2p::past::rawserialization::JavaSerializedPastContent(obj)), generateFragment);
}

rice::p2p::glacier::FragmentArray* rice::p2p::glacier::v2::GlacierDefaultPolicy::encodeObjectHelper(::rice::p2p::past::PastContent* obj, ::int8_tArray* bytes, int32_t length, ::boolArray* generateFragment)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Create fragments: "_j)->append(static_cast< ::java::lang::Object* >(obj))->toString());

    auto fragments = npc(codec)->encode(bytes, length, generateFragment);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Completed: "_j)->append(static_cast< ::java::lang::Object* >(obj))->toString());

    return fragments;
}

rice::p2p::glacier::v2::Manifest* rice::p2p::glacier::v2::GlacierDefaultPolicy::updateManifest(::rice::p2p::glacier::VersionKey* key, Manifest* manifest, int64_t newExpiration)
{
    if(!checkSignature(manifest, key))
        return nullptr;

    auto newManifest = new Manifest(npc(manifest)->getObjectHash(), npc(manifest)->getFragmentHashes(), newExpiration);
    signManifest(newManifest, key);
    return newManifest;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierDefaultPolicy::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.GlacierDefaultPolicy", 40);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierDefaultPolicy::getClass0()
{
    return class_();
}

