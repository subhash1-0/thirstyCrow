// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregateDescriptor.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/aggregation/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

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
        namespace aggregation
        {
typedef ::SubArray< ::rice::p2p::aggregation::ObjectDescriptor, ::java::lang::ObjectArray, ::java::io::SerializableArray, ::java::lang::ComparableArray > ObjectDescriptorArray;
        } // aggregation

        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
        } // commonapi
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::aggregation::AggregateDescriptor
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    ::rice::p2p::commonapi::Id* key {  };
    int64_t currentLifetime {  };
    ObjectDescriptorArray* objects {  };
    ::rice::p2p::commonapi::IdArray* pointers {  };
    bool marker {  };
    int32_t referenceCount {  };
protected:
    void ctor(::rice::p2p::commonapi::Id* key, int64_t currentLifetime, ObjectDescriptorArray* objects, ::rice::p2p::commonapi::IdArray* pointers);

public:
    virtual int32_t lookupNewest(::rice::p2p::commonapi::Id* id);
    virtual int32_t lookupSpecific(::rice::p2p::commonapi::Id* id, int64_t version);
    virtual void addReference();
    virtual int32_t objectsAliveAt(int64_t pointInTime);
    virtual int32_t bytesAliveAt(int64_t pointInTime);

    // Generated
    AggregateDescriptor(::rice::p2p::commonapi::Id* key, int64_t currentLifetime, ObjectDescriptorArray* objects, ::rice::p2p::commonapi::IdArray* pointers);
protected:
    AggregateDescriptor(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
