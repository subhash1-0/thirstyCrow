// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierPolicy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

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

struct rice::p2p::glacier::v2::GlacierPolicy
    : public virtual ::java::lang::Object
{
    virtual bool checkSignature(Manifest* manifest, ::rice::p2p::glacier::VersionKey* key) = 0;
    virtual ::rice::p2p::glacier::FragmentArray* encodeObject(::rice::p2p::past::PastContent* obj, ::boolArray* generateFragment) = 0;
    virtual ManifestArray* createManifests(::rice::p2p::glacier::VersionKey* key, ::rice::p2p::past::PastContent* obj, ::rice::p2p::glacier::FragmentArray* fragments, int64_t expiration) = 0;
    virtual Manifest* updateManifest(::rice::p2p::glacier::VersionKey* key, Manifest* manifest, int64_t newExpiration) = 0;
    virtual ::rice::p2p::past::PastContent* decodeObject(::rice::p2p::glacier::FragmentArray* fragments, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd) = 0;
    virtual void prefetchLocalObject(::rice::p2p::glacier::VersionKey* key, ::rice::Continuation* command) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
