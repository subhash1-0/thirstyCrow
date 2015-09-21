// Generated from /pastry-2.1/src/rice/p2p/commonapi/IdSet.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/io/Serializable.hpp>

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

struct rice::p2p::commonapi::IdSet
    : public virtual ::java::io::Serializable
{
    virtual int32_t numElements() = 0;
    virtual void addId(Id* id) = 0;
    virtual void removeId(Id* id) = 0;
    virtual bool isMemberId(Id* id) = 0;
    virtual IdSet* subSet(IdRange* range) = 0;
    virtual ::java::util::Iterator* getIterator() = 0;
    virtual IdArray* asArray_() = 0;
    virtual ::int8_tArray* hash() = 0;
    /*virtual ::java::lang::Object* clone(); (already declared) */
    virtual IdSet* build() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
