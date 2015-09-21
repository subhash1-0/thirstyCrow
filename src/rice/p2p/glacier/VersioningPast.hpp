// Generated from /pastry-2.1/src/rice/p2p/glacier/VersioningPast.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/fwd-pastry-2.1.hpp>
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
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
        } // commonapi
    } // p2p
} // rice

struct rice::p2p::glacier::VersioningPast
    : public virtual ::java::lang::Object
{
    virtual void lookup(::rice::p2p::commonapi::Id* id, int64_t version, ::rice::Continuation* command) = 0;
    virtual void lookupHandles(::rice::p2p::commonapi::Id* id, int64_t version, int32_t num, ::rice::Continuation* command) = 0;
    virtual void refresh(::rice::p2p::commonapi::IdArray* ids, ::int64_tArray* versions, ::int64_tArray* expirations, ::rice::Continuation* command) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
