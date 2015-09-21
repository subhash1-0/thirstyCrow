// Generated from /pastry-2.1/src/rice/p2p/aggregation/Aggregate.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/aggregation/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/past/gc/GCPastContent.hpp>

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
        } // past
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::aggregation::Aggregate
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::past::gc::GCPastContent
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::past::gc::GCPastContentArray* components {  };
    ::rice::p2p::commonapi::IdArray* pointers {  };
    ::rice::p2p::commonapi::Id* myId {  };

private:
    static constexpr int64_t serialVersionUID { int64_t(-4891386773008082LL) };
protected:
    void ctor(::rice::p2p::past::gc::GCPastContentArray* components, ::rice::p2p::commonapi::IdArray* pointers);

public:
    virtual void setId(::rice::p2p::commonapi::Id* myId);
    ::rice::p2p::commonapi::Id* getId() override;
    virtual ::rice::p2p::commonapi::IdArray* getPointers();
    virtual int32_t numComponents();
    virtual ::rice::p2p::past::gc::GCPastContent* getComponent(int32_t index);
    int64_t getVersion() override;
    bool isMutable() override;
    ::rice::p2p::past::PastContent* checkInsert(::rice::p2p::commonapi::Id* id, ::rice::p2p::past::PastContent* existingContent) /* throws(PastException) */ override;
    virtual ::int8_tArray* getContentHash();
    ::rice::p2p::past::PastContentHandle* getHandle(::rice::p2p::past::Past* local) override;
    ::rice::p2p::past::gc::GCPastContentHandle* getHandle(::rice::p2p::past::gc::GCPast* local, int64_t expiration) override;
    ::rice::p2p::past::gc::GCPastMetadata* getMetadata(int64_t expiration) override;

    // Generated
    Aggregate(::rice::p2p::past::gc::GCPastContentArray* components, ::rice::p2p::commonapi::IdArray* pointers);
protected:
    Aggregate(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
