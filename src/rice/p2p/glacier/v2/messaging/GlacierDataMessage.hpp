// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/messaging/GlacierDataMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierMessage.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
        } // commonapi

        namespace glacier
        {
typedef ::SubArray< ::rice::p2p::glacier::Fragment, ::java::lang::ObjectArray, ::java::io::SerializableArray > FragmentArray;
typedef ::SubArray< ::rice::p2p::glacier::FragmentKey, ::java::lang::ObjectArray, ::rice::p2p::commonapi::IdArray > FragmentKeyArray;

            namespace v2
            {
typedef ::SubArray< ::rice::p2p::glacier::v2::Manifest, ::java::lang::ObjectArray, ::java::io::SerializableArray > ManifestArray;
            } // v2
        } // glacier
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::glacier::v2::messaging::GlacierDataMessage
    : public GlacierMessage
{

public:
    typedef GlacierMessage super;
    static constexpr int16_t TYPE { int16_t(1) };

public: /* protected */
    ::rice::p2p::glacier::FragmentKeyArray* keys {  };
    ::rice::p2p::glacier::FragmentArray* fragments {  };
    ::rice::p2p::glacier::v2::ManifestArray* manifests {  };
protected:
    void ctor(int32_t uid, ::rice::p2p::glacier::FragmentKey* key, ::rice::p2p::glacier::Fragment* fragment, ::rice::p2p::glacier::v2::Manifest* manifest, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, bool isResponse, char16_t tag);
    void ctor(int32_t uid, ::rice::p2p::glacier::FragmentKeyArray* keys, ::rice::p2p::glacier::FragmentArray* fragments, ::rice::p2p::glacier::v2::ManifestArray* manifests, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, bool isResponse, char16_t tag);

public:
    virtual int32_t numKeys();
    virtual ::rice::p2p::glacier::FragmentKey* getKey(int32_t index);
    virtual ::rice::p2p::glacier::Fragment* getFragment(int32_t index);
    virtual ::rice::p2p::glacier::v2::Manifest* getManifest(int32_t index);
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    static GlacierDataMessage* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

    // Generated

public:
    GlacierDataMessage(int32_t uid, ::rice::p2p::glacier::FragmentKey* key, ::rice::p2p::glacier::Fragment* fragment, ::rice::p2p::glacier::v2::Manifest* manifest, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, bool isResponse, char16_t tag);
    GlacierDataMessage(int32_t uid, ::rice::p2p::glacier::FragmentKeyArray* keys, ::rice::p2p::glacier::FragmentArray* fragments, ::rice::p2p::glacier::v2::ManifestArray* manifests, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, bool isResponse, char16_t tag);

private:
    GlacierDataMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    GlacierDataMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
