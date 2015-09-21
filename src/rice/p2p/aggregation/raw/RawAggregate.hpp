// Generated from /pastry-2.1/src/rice/p2p/aggregation/raw/RawAggregate.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/aggregation/raw/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/aggregation/Aggregate.hpp>
#include <rice/p2p/past/gc/rawserialization/RawGCPastContent.hpp>

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

        namespace past
        {
typedef ::SubArray< ::rice::p2p::past::PastContent, ::java::lang::ObjectArray, ::java::io::SerializableArray > PastContentArray;

            namespace gc
            {
typedef ::SubArray< ::rice::p2p::past::gc::GCPastContent, ::java::lang::ObjectArray, ::rice::p2p::past::PastContentArray > GCPastContentArray;
            } // gc

            namespace rawserialization
            {
typedef ::SubArray< ::rice::p2p::past::rawserialization::RawPastContent, ::java::lang::ObjectArray, ::rice::p2p::past::PastContentArray > RawPastContentArray;
            } // rawserialization

            namespace gc
            {
                namespace rawserialization
                {
typedef ::SubArray< ::rice::p2p::past::gc::rawserialization::RawGCPastContent, ::java::lang::ObjectArray, ::rice::p2p::past::gc::GCPastContentArray, ::rice::p2p::past::rawserialization::RawPastContentArray > RawGCPastContentArray;
                } // rawserialization
            } // gc
        } // past
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::aggregation::raw::RawAggregate
    : public ::rice::p2p::aggregation::Aggregate
    , public virtual ::rice::p2p::past::gc::rawserialization::RawGCPastContent
{

public:
    typedef ::rice::p2p::aggregation::Aggregate super;

private:
    ::rice::p2p::past::gc::rawserialization::RawGCPastContentArray* rawComponents {  };
    static constexpr int64_t serialVersionUID { int64_t(-4891386773008082LL) };

public:
    static constexpr int16_t TYPE { int16_t(1) };
protected:
    void ctor(::rice::p2p::past::gc::GCPastContentArray* components, ::rice::p2p::commonapi::IdArray* pointers);
    void ctor(::rice::p2p::past::gc::rawserialization::RawGCPastContentArray* components, ::rice::p2p::commonapi::IdArray* pointers);

public:
    int32_t numComponents() override;
    ::int8_tArray* getContentHash() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

private:
    void serializeHelper(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* contentDeserializer) /* throws(IOException) */;

private:
    void readObject(::java::io::ObjectInputStream* in) /* throws(IOException, ClassNotFoundException) */;
    void buildRawComponents(::rice::p2p::past::gc::GCPastContentArray* components);

    // Generated

public:
    RawAggregate(::rice::p2p::past::gc::GCPastContentArray* components, ::rice::p2p::commonapi::IdArray* pointers);
    RawAggregate(::rice::p2p::past::gc::rawserialization::RawGCPastContentArray* components, ::rice::p2p::commonapi::IdArray* pointers);
    RawAggregate(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* contentDeserializer);
protected:
    RawAggregate(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual ::rice::p2p::past::PastContent* checkInsert(::rice::p2p::commonapi::Id* id, ::rice::p2p::past::PastContent* existingContent);
    virtual ::rice::p2p::past::PastContentHandle* getHandle(::rice::p2p::past::Past* local);
    virtual ::rice::p2p::commonapi::Id* getId();
    virtual bool isMutable();
    virtual ::rice::p2p::past::gc::GCPastContentHandle* getHandle(::rice::p2p::past::gc::GCPast* local, int64_t expiration);
    virtual ::rice::p2p::past::gc::GCPastMetadata* getMetadata(int64_t expiration);
    virtual int64_t getVersion();

private:
    virtual ::java::lang::Class* getClass0();
};
