// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/messaging/GlacierNeighborResponseMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
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
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::glacier::v2::messaging::GlacierNeighborResponseMessage
    : public GlacierMessage
{

public:
    typedef GlacierMessage super;
    static constexpr int16_t TYPE { int16_t(4) };

public: /* protected */
    ::rice::p2p::commonapi::IdArray* neighbors {  };
    ::int64_tArray* lastSeen {  };
protected:
    void ctor(int32_t uid, ::rice::p2p::commonapi::IdArray* neighbors, ::int64_tArray* lastSeen, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag);

public:
    virtual int32_t numNeighbors();
    virtual ::rice::p2p::commonapi::Id* getNeighbor(int32_t index);
    virtual int64_t getLastSeen(int32_t index);
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    static GlacierNeighborResponseMessage* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

    // Generated

public:
    GlacierNeighborResponseMessage(int32_t uid, ::rice::p2p::commonapi::IdArray* neighbors, ::int64_tArray* lastSeen, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag);

private:
    GlacierNeighborResponseMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    GlacierNeighborResponseMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
