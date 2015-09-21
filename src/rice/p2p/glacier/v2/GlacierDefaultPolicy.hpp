// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierDefaultPolicy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/glacier/v2/GlacierPolicy.hpp>

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

struct default_init_tag;

class rice::p2p::glacier::v2::GlacierDefaultPolicy
    : public virtual ::java::lang::Object
    , public virtual GlacierPolicy
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::glacier::ErasureCodec* codec {  };
    ::java::lang::String* instance {  };
    ::rice::environment::Environment* environment {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::p2p::glacier::ErasureCodec* codec, ::java::lang::String* instance, ::rice::environment::Environment* env);

public:
    bool checkSignature(Manifest* manifest, ::rice::p2p::glacier::VersionKey* key) override;

public: /* protected */
    virtual void signManifest(Manifest* manifest, ::rice::p2p::glacier::VersionKey* key);

public:
    void prefetchLocalObject(::rice::p2p::glacier::VersionKey* key, ::rice::Continuation* command) override;
    ::rice::p2p::past::PastContent* decodeObject(::rice::p2p::glacier::FragmentArray* fragments, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd) override;
    virtual ManifestArray* createManifests(::rice::p2p::glacier::VersionKey* key, ::rice::p2p::past::rawserialization::RawPastContent* obj, ::rice::p2p::glacier::FragmentArray* fragments, int64_t expiration);
    ManifestArray* createManifests(::rice::p2p::glacier::VersionKey* key, ::rice::p2p::past::PastContent* obj, ::rice::p2p::glacier::FragmentArray* fragments, int64_t expiration) override;

private:
    ManifestArray* createManifestsHelper(::rice::p2p::glacier::VersionKey* key, ::int8_tArray* bytes, int32_t length, ::rice::p2p::glacier::FragmentArray* fragments, int64_t expiration);

public:
    virtual ::rice::p2p::glacier::FragmentArray* encodeObject(::rice::p2p::past::rawserialization::RawPastContent* obj, ::boolArray* generateFragment);
    ::rice::p2p::glacier::FragmentArray* encodeObject(::rice::p2p::past::PastContent* obj, ::boolArray* generateFragment) override;

private:
    ::rice::p2p::glacier::FragmentArray* encodeObjectHelper(::rice::p2p::past::PastContent* obj, ::int8_tArray* bytes, int32_t length, ::boolArray* generateFragment);

public:
    Manifest* updateManifest(::rice::p2p::glacier::VersionKey* key, Manifest* manifest, int64_t newExpiration) override;

    // Generated
    GlacierDefaultPolicy(::rice::p2p::glacier::ErasureCodec* codec, ::java::lang::String* instance, ::rice::environment::Environment* env);
protected:
    GlacierDefaultPolicy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
