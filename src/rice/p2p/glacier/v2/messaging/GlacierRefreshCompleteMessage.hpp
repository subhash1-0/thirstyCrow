// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/messaging/GlacierRefreshCompleteMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/fwd-pastry-2.1.hpp>
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
typedef ::SubArray< ::rice::p2p::glacier::VersionKey, ::java::lang::ObjectArray, ::rice::p2p::commonapi::IdArray, ::java::io::SerializableArray > VersionKeyArray;
        } // glacier
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::glacier::v2::messaging::GlacierRefreshCompleteMessage
    : public GlacierMessage
{

public:
    typedef GlacierMessage super;
    static constexpr int16_t TYPE { int16_t(9) };

public: /* protected */
    ::rice::p2p::glacier::VersionKeyArray* keys {  };
    ::int32_tArray* updates {  };
protected:
    void ctor(int32_t uid, ::rice::p2p::glacier::VersionKeyArray* keys, ::int32_tArray* updates, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag);

public:
    virtual int32_t numKeys();
    virtual ::rice::p2p::glacier::VersionKey* getKey(int32_t index);
    virtual int64_t getUpdates(int32_t index);
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    static GlacierRefreshCompleteMessage* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

    // Generated

public:
    GlacierRefreshCompleteMessage(int32_t uid, ::rice::p2p::glacier::VersionKeyArray* keys, ::int32_tArray* updates, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag);

private:
    GlacierRefreshCompleteMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    GlacierRefreshCompleteMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
